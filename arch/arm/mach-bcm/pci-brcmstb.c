/*
 * Copyright (C) 2009 - 2013 Broadcom Corporation
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */
#include <linux/init.h>
#include <linux/types.h>
#include <linux/slab.h>
#include <linux/pci.h>
#include <linux/kernel.h>
#include <linux/ioport.h>
#include <linux/compiler.h>
#include <linux/delay.h>
#include <linux/io.h>
#include <linux/clk.h>
#include <linux/interrupt.h>
#include <linux/list.h>
#include <linux/msi.h>
#include <linux/printk.h>
#include <linux/syscore_ops.h>
#include <linux/of_irq.h>
#include <linux/of_platform.h>
#include <linux/of_address.h>
#include <linux/of_pci.h>
#include <linux/module.h>
#include <linux/irqdomain.h>
#include <linux/regulator/consumer.h>
#include <linux/string.h>

/* Broadcom PCIE Offsets */
#define PCIE_RC_CFG_PCIE_LINK_CAPABILITY		0x00b8
#define PCIE_RC_CFG_PCIE_LINK_STATUS_CONTROL		0x00bc
#define PCIE_RC_CFG_PCIE_ROOT_CAP_CONTROL		0x00c8
#define PCIE_RC_CFG_PCIE_LINK_STATUS_CONTROL_2		0x00dc
#define PCIE_RC_CFG_VENDOR_VENDOR_SPECIFIC_REG1		0x0188
#define PCIE_RC_CFG_PRIV1_ID_VAL3			0x043c
#define PCIE_RC_DL_MDIO_ADDR				0x1100
#define PCIE_RC_DL_MDIO_WR_DATA				0x1104
#define PCIE_RC_DL_MDIO_RD_DATA				0x1108
#define PCIE_MISC_MISC_CTRL				0x4008
#define PCIE_MISC_CPU_2_PCIE_MEM_WIN0_LO		0x400c
#define PCIE_MISC_CPU_2_PCIE_MEM_WIN0_HI		0x4010
#define PCIE_MISC_RC_BAR1_CONFIG_LO			0x402c
#define PCIE_MISC_RC_BAR1_CONFIG_HI			0x4030
#define PCIE_MISC_RC_BAR2_CONFIG_LO			0x4034
#define PCIE_MISC_RC_BAR2_CONFIG_HI			0x4038
#define PCIE_MISC_RC_BAR3_CONFIG_LO			0x403c
#define PCIE_MISC_RC_BAR3_CONFIG_HI			0x4040
#define PCIE_MISC_MSI_BAR_CONFIG_LO			0x4044
#define PCIE_MISC_MSI_BAR_CONFIG_HI			0x4048
#define PCIE_MISC_MSI_DATA_CONFIG			0x404c
#define PCIE_MISC_PCIE_CTRL				0x4064
#define PCIE_MISC_PCIE_STATUS				0x4068
#define PCIE_MISC_REVISION				0x406c
#define PCIE_MISC_CPU_2_PCIE_MEM_WIN0_BASE_LIMIT	0x4070
#define PCIE_MISC_HARD_PCIE_HARD_DEBUG			0x4204
#define PCIE_INTR2_CPU_BASE				0x4300
#define PCIE_MSI_INTR2_BASE				0x4500
#define PCIE_EXT_CFG_PCIE_EXT_CFG_INDEX			0x9000
#define PCIE_EXT_CFG_PCIE_EXT_CFG_DATA			0x9004
#define PCIE_RGR1_SW_INIT_1				0x9210
#define BRCM_NUM_PCI_OUT_WINS		0x4
#define BRCM_MAX_SCB			0x4
#define BRCM_INT_PCI_MSI_NR		32
#define BRCM_PCIE_HW_REV_33		0x0303
#define BRCM_MSI_TARGET_ADDR_LO		0x0
#define BRCM_MSI_TARGET_ADDR_HI		0xffffffff

/* Offsets from PCIE_INTR2_CPU_BASE and PCIE_MSI_INTR2_BASE */
#define STATUS				0x0
#define SET				0x4
#define CLR				0x8
#define MASK_STATUS			0xc
#define MASK_SET			0x10
#define MASK_CLR			0x14

#define PCI_BUSNUM_SHIFT		20
#define PCI_SLOT_SHIFT			15
#define PCI_FUNC_SHIFT			12

#define IDX_ADDR(base)		((base) + PCIE_EXT_CFG_PCIE_EXT_CFG_INDEX)
#define DATA_ADDR(base)		((base) + PCIE_EXT_CFG_PCIE_EXT_CFG_DATA)

static int brcm_pci_read_config(struct pci_bus *bus, unsigned int devfn,
				int where, int size, u32 *data);
static int brcm_pci_write_config(struct pci_bus *bus, unsigned int devfn,
				 int where, int size, u32 data);

static struct pci_ops brcm_pci_ops = {
	.read = brcm_pci_read_config,
	.write = brcm_pci_write_config,
};

static int brcm_setup_pcie_bridge(int nr, struct pci_sys_data *sys);
static int __init brcm_map_irq(const struct pci_dev *dev, u8 slot, u8 pin);

static struct hw_pci brcm_pcie_hw __initdata = {
	.nr_controllers	= 0,
	.setup		= brcm_setup_pcie_bridge,
	.map_irq	= brcm_map_irq,
	.ops		= &brcm_pci_ops,
};

struct brcm_msi {
	struct irq_domain *domain;
	struct irq_chip irq_chip;
	struct msi_chip chip;
	struct mutex lock;
	int irq;
	/* intr_base is the base pointer for interrupt status/set/clr regs */
	void __iomem *intr_base;
	/* intr_legacy_mask indicates how many bits are MSI interrupts */
	u32 intr_legacy_mask;
	/* intr_legacy_offset indicates bit position of MSI_01 */
	u32 intr_legacy_offset;
	/* used indicates which MSI interrupts have been alloc'd */
	unsigned long used;
	/* working indicates that on boot we have brought up MSI */
	bool working;
};

struct brcm_window {
	u64 pci_addr;
	u64 size;
	u64 cpu_addr;
	u32 info;
	struct resource pcie_iomem_res;
};

struct brcm_dev_pwr_supply {
	struct list_head node;
	char name[32];
	struct regulator *regulator;
};

/* Internal Bus Controller Information.*/
struct brcm_pcie {
	struct list_head	list;
	void __iomem		*base;
	char			name[8];
	bool			suspended;
	struct clk		*clk;
	struct device_node	*dn;
	int			pcie_irq[4];
	int			irq;
	int			num_out_wins;
	bool			ssc;
	int			gen;
	int			scb_size_vals[BRCM_MAX_SCB];
	struct brcm_window	out_wins[BRCM_NUM_PCI_OUT_WINS];
	struct pci_sys_data	*sys;
	struct device		*dev;
	struct list_head	pwr_supplies;
	bool			broken_pcie_irq_map_dt;
	struct brcm_msi		msi;
	unsigned		rev;
};

static struct list_head brcm_pcie;
static int brcm_num_pci_controllers;
static int num_memc;
static void turn_off(void __iomem *base);
static void enter_l23(struct brcm_pcie *pcie);


/***********************************************************************
 * PCIe Bridge setup
 ***********************************************************************/
#if defined(__BIG_ENDIAN)
#define	DATA_ENDIAN		2	/* PCI->DDR inbound accesses */
#define MMIO_ENDIAN		2	/* CPU->PCI outbound accesses */
#else
#define	DATA_ENDIAN		0
#define MMIO_ENDIAN		0
#endif


static void remove_pcie(struct brcm_pcie *pcie)
{
	struct list_head *pos, *q;
	struct brcm_pcie *tmp;

	list_for_each_safe(pos, q, &brcm_pcie) {
		tmp = list_entry(pos, struct brcm_pcie, list);
		if (tmp == pcie) {
			list_del(pos);
			break;
		}
	}
}


/* negative return value indicates error */
static int mdio_read(void __iomem *base, u8 phyad, u8 regad)
{
	const int TRYS = 10;
	u32 data = ((phyad & 0xf) << 16)
		| (regad & 0x1f)
		| 0x100000;

	int i = 0;

	__raw_writel(data, base + PCIE_RC_DL_MDIO_ADDR);
	__raw_readl(base + PCIE_RC_DL_MDIO_ADDR);

	data = __raw_readl(base + PCIE_RC_DL_MDIO_RD_DATA);

	while (!(data & 0x80000000) && ++i < TRYS) {
		udelay(10);
		data = __raw_readl(base + PCIE_RC_DL_MDIO_RD_DATA);
	}

	return (data & 0x80000000) ? (data & 0xffff) : -EIO;
}


/* negative return value indicates error */
static int mdio_write(void __iomem *base, u8 phyad, u8 regad, u16 wrdata)
{
	u32 data = ((phyad & 0xf) << 16) | (regad & 0x1f);
	const int TRYS = 10;
	int i = 0;
	__raw_writel(data, base + PCIE_RC_DL_MDIO_ADDR);
	__raw_readl(base + PCIE_RC_DL_MDIO_ADDR);

	__raw_writel(0x80000000 | wrdata, base + PCIE_RC_DL_MDIO_WR_DATA);

	data = __raw_readl(base + PCIE_RC_DL_MDIO_WR_DATA);

	while ((data & 0x80000000) && ++i < TRYS) {
		udelay(10);
		data = __raw_readl(base + PCIE_RC_DL_MDIO_WR_DATA);
	}

	return (data & 0x80000000) ? -EIO : 0;
}


static void wr_fld(void __iomem *p, u32 mask, int shift, u32 val)
{
	u32 reg = __raw_readl(p);
	reg = (reg & ~mask) | (val << shift);
	__raw_writel(reg, p);
}


static void wr_fld_rb(void __iomem *p, u32 mask, int shift, u32 val)
{
	wr_fld(p, mask, shift, val);
	(void) __raw_readl(p);
}


/* configures device for ssc mode; negative return value indicates error */
static int set_ssc(void __iomem *base)
{
	int tmp;
	u16 wrdata;

	tmp = mdio_write(base, 0, 0x1f, 0x1100);
	if (tmp < 0)
		return tmp;

	tmp = mdio_read(base, 0, 2);
	if (tmp < 0)
		return tmp;

	wrdata = ((u16)tmp & 0x3fff) | 0xc000;
	tmp = mdio_write(base, 0, 2, wrdata);
	if (tmp < 0)
		return tmp;

	mdelay(1);
	tmp = mdio_read(base, 0, 1);
	if (tmp < 0)
		return tmp;

	return 0;
}


/* returns 0 if in ssc mode, 1 if not, <0 on error */
static int is_ssc(void __iomem *base)
{
	int tmp = mdio_write(base, 0, 0x1f, 0x1100);
	if (tmp < 0)
		return tmp;
	tmp = mdio_read(base, 0, 1);
	if (tmp < 0)
		return tmp;
	return (tmp & 0xc00) == 0xc00 ? 0 : 1;
}


/* limits operation to a specific generation (1, 2, or 3) */
static void set_gen(void __iomem *base, int gen)
{
	wr_fld(base + PCIE_RC_CFG_PCIE_LINK_CAPABILITY, 0xf, 0, gen);
	wr_fld(base + PCIE_RC_CFG_PCIE_LINK_STATUS_CONTROL_2, 0xf, 0, gen);
}


static void set_pcie_outbound_win(void __iomem *base, unsigned win, u64 start,
				  u64 len)
{
	u32 tmp;

	__raw_writel((u32)(start) + MMIO_ENDIAN,
		     base + PCIE_MISC_CPU_2_PCIE_MEM_WIN0_LO+(win*8));
	__raw_writel((u32)(start >> 32),
		     base + PCIE_MISC_CPU_2_PCIE_MEM_WIN0_HI+(win*8));
	tmp = ((((u32)start) >> 20) << 4)
		| (((((u32)start) + ((u32)len) - 1) >> 20) << 20);
	__raw_writel(tmp,
		     base + PCIE_MISC_CPU_2_PCIE_MEM_WIN0_BASE_LIMIT+(win*4));
}


static int is_pcie_link_up(struct brcm_pcie *pcie)
{
	void __iomem *base = pcie->base;
	u32 val = __raw_readl(base + PCIE_MISC_PCIE_STATUS);
	return  ((val & 0x30) == 0x30) ? 1 : 0;
}


static inline struct brcm_msi *to_brcm_msi(struct msi_chip *chip)
{
	return container_of(chip, struct brcm_msi, chip);
}


static int brcm_msi_alloc(struct brcm_msi *chip)
{
	int msi;

	mutex_lock(&chip->lock);
	msi = ~chip->used ? ffz(chip->used) : -1;

	if (msi >= 0 && msi < BRCM_INT_PCI_MSI_NR)
		chip->used |= (1 << msi);
	else
		msi = -ENOSPC;

	mutex_unlock(&chip->lock);
	return msi;
}


static void brcm_msi_free(struct brcm_msi *chip, unsigned long irq)
{
	mutex_lock(&chip->lock);
	chip->used &= ~(1 << irq);
	mutex_unlock(&chip->lock);
}


static irqreturn_t brcm_pcie_msi_irq(int irq, void *data)
{
	struct brcm_pcie *pcie = data;
	struct brcm_msi *msi = &pcie->msi;
	unsigned long status;

	status = __raw_readl(msi->intr_base + STATUS) & msi->intr_legacy_mask;

	if (!status)
		return IRQ_NONE;

	while (status) {
		unsigned int index = ffs(status) - 1;
		unsigned int irq;

		/* clear the interrupt */
		__raw_writel(1 << index, msi->intr_base + CLR);
		status &= ~(1 << index);

		/* Account for legacy interrupt offset */
		index -= msi->intr_legacy_offset;

		irq = irq_find_mapping(msi->domain, index);
		if (irq) {
			if (msi->used & (1 << index))
				generic_handle_irq(irq);
			else
				dev_info(pcie->dev, "unhandled MSI %d\n",
					 index);
		} else {
			/* Unknown MSI, just clear it */
			dev_dbg(pcie->dev, "unexpected MSI\n");
		}
	}
	return IRQ_HANDLED;
}


static int brcm_msi_setup_irq(struct msi_chip *chip, struct pci_dev *pdev,
			      struct msi_desc *desc)
{
	struct brcm_msi *msi = to_brcm_msi(chip);
	struct brcm_pcie *pcie = container_of(chip, struct brcm_pcie, msi.chip);
	struct msi_msg msg;
	unsigned int irq;
	int hwirq;
	u32 data;

	hwirq = brcm_msi_alloc(msi);
	if (hwirq < 0)
		return hwirq;

	irq = irq_create_mapping(msi->domain, hwirq);
	if (!irq) {
		brcm_msi_free(msi, hwirq);
		return -EINVAL;
	}

	irq_set_msi_desc(irq, desc);

	msg.address_lo = BRCM_MSI_TARGET_ADDR_LO;
	msg.address_hi = BRCM_MSI_TARGET_ADDR_HI;
	data = __raw_readl(pcie->base + PCIE_MISC_MSI_DATA_CONFIG);
	msg.data = ((data >> 16) & (data & 0xffff)) | hwirq;
	wmb(); /* just being cautious */
	write_msi_msg(irq, &msg);

	return 0;
}


static void brcm_msi_teardown_irq(struct msi_chip *chip, unsigned int irq)
{
	struct brcm_msi *msi = to_brcm_msi(chip);
	struct irq_data *d = irq_get_irq_data(irq);

	brcm_msi_free(msi, d->hwirq);
}


static int brcm_msi_map(struct irq_domain *domain, unsigned int irq,
			irq_hw_number_t hwirq)
{
	struct brcm_pcie *pcie = domain->host_data;

	irq_set_chip_and_handler(irq, &pcie->msi.irq_chip, handle_simple_irq);
	irq_set_chip_data(irq, domain->host_data);

	return 0;
}

static const struct irq_domain_ops msi_domain_ops = {
	.map = brcm_msi_map,
};


static int brcm_pcie_enable_msi(struct brcm_pcie *pcie, int nr)
{
	static const char brcm_msi_name[] = "brcmstb_pcieX_msi";
	struct brcm_msi *msi = &pcie->msi;
	u32 data_val;
	char *name;
	int err;

	if (!pcie->suspended) {
		/* We are only here on cold boot */
		mutex_init(&msi->lock);

		msi->chip.dev = pcie->dev;
		msi->chip.setup_irq = brcm_msi_setup_irq;
		msi->chip.teardown_irq = brcm_msi_teardown_irq;

		/* We have multiple RC controllers.  We may have as many
		 * MSI controllers for them.  We want each to have a
		 * unique name, so we go to the trouble of having an
		 * irq_chip per RC (instead of one for all of them). */
		name = devm_kzalloc(pcie->dev, sizeof(brcm_msi_name),
				    GFP_KERNEL);
		if (name) {
			char *p;
			strcpy(name, brcm_msi_name);
			p = strchr(name, 'X');
			if (p)
				*p = '0' + nr;
			msi->irq_chip.name = name;
		} else {
			msi->irq_chip.name = brcm_msi_name;
		}

		msi->irq_chip.irq_enable = unmask_msi_irq;
		msi->irq_chip.irq_disable = mask_msi_irq;
		msi->irq_chip.irq_mask = mask_msi_irq;
		msi->irq_chip.irq_unmask = unmask_msi_irq;

		msi->domain =
			irq_domain_add_linear(pcie->dn, BRCM_INT_PCI_MSI_NR,
					      &msi_domain_ops, pcie);
		if (!msi->domain) {
			dev_err(pcie->dev,
				"failed to create IRQ domain for MSI\n");
			return -ENOMEM;
		}

		err = devm_request_irq(pcie->dev, msi->irq, brcm_pcie_msi_irq,
				       IRQF_SHARED, msi->irq_chip.name,
				       pcie);

		if (err < 0) {
			dev_err(pcie->dev,
				"failed to request IRQ (%d) for MSI\n",	err);
			goto msi_en_err;
		}

		if (pcie->rev >= BRCM_PCIE_HW_REV_33) {
			msi->intr_base = pcie->base + PCIE_MSI_INTR2_BASE;
			/* This version of PCIe hw has only 32 intr bits
			 * starting at bit position 0. */
			msi->intr_legacy_mask = 0xffffffff;
			msi->intr_legacy_offset = 0x0;
			msi->used = 0x0;

		} else {
			msi->intr_base = pcie->base + PCIE_INTR2_CPU_BASE;
			/* This version of PCIe hw has only 8 intr bits starting
			 * at bit position 24. */
			msi->intr_legacy_mask = 0xff000000;
			msi->intr_legacy_offset = 24;
			msi->used = 0xffffff00;
		}
		msi->working = true;
	}

	/* If we are here, and msi->working is false, it means that we've
	 * already tried and failed to bring up MSI.  Just return 0
	 * since there is nothing to be done. */
	if (!msi->working)
		return 0;

	if (pcie->rev >= BRCM_PCIE_HW_REV_33) {
		/* ffe0 -- least sig 5 bits are 0 indicating 32 msgs
		 * 6540 -- this is our arbitrary unique data value */
		data_val = 0xffe06540;
	} else {
		/* fff8 -- least sig 3 bits are 0 indicating 8 msgs
		 * 6540 -- this is our arbitrary unique data value */
		data_val = 0xfff86540;
	}

	/* Make sure we are not masking MSIs.  Note that MSIs can be masked,
	 * but that occurs on the PCIe EP device */
	__raw_writel(0xffffffff & msi->intr_legacy_mask,
		     msi->intr_base + MASK_CLR);

	/* The 0 bit of BRCM_MSI_TARGET_ADDR_LO is repurposed to MSI enable,
	 * which we set to 1. */
	__raw_writel(BRCM_MSI_TARGET_ADDR_LO | 1, pcie->base
		     + PCIE_MISC_MSI_BAR_CONFIG_LO);
	__raw_writel(BRCM_MSI_TARGET_ADDR_HI, pcie->base
		     + PCIE_MISC_MSI_BAR_CONFIG_HI);
	__raw_writel(data_val, pcie->base + PCIE_MISC_MSI_DATA_CONFIG);

	return 0;

msi_en_err:
	irq_domain_remove(msi->domain);
	return err;
}


static void brcm_pcie_setup_early(struct brcm_pcie *pcie)
{
	void __iomem *base = pcie->base;
	unsigned int scb_size_val;
	int i;

	/* reset the bridge and the endpoint device */
	/* field: PCIE_BRIDGE_SW_INIT = 1 */
	wr_fld_rb(base + PCIE_RGR1_SW_INIT_1, 0x00000002, 1, 1);
	/* field: PCIE_SW_PERST = 1 */
	wr_fld_rb(base + PCIE_RGR1_SW_INIT_1, 0x00000001, 0, 1);

	/* delay 100us */
	udelay(100);

	/* take the bridge out of reset */
	/* field: PCIE_BRIDGE_SW_INIT = 0 */
	wr_fld_rb(base + PCIE_RGR1_SW_INIT_1, 0x00000002, 1, 0);

	/* Grab the PCIe hw revision number */
	pcie->rev = __raw_readl(base + PCIE_MISC_REVISION) & 0xffff;

	/* enable SCB_MAX_BURST_SIZE | CSR_READ_UR_MODE | SCB_ACCESS_EN */
	__raw_writel(0x81e03000, base + PCIE_MISC_MISC_CTRL);

	for (i = 0; i < pcie->num_out_wins; i++) {
		struct brcm_window *w = &pcie->out_wins[i];
		set_pcie_outbound_win(base, i, w->cpu_addr, w->size);
	}

	/* set up 4GB PCIE->SCB memory window on BAR2 */
	__raw_writel(0x00000011, base + PCIE_MISC_RC_BAR2_CONFIG_LO);
	__raw_writel(0x00000000, base + PCIE_MISC_RC_BAR2_CONFIG_HI);

	/* field: SCB0_SIZE, default = 0xf (1 GB) */
	scb_size_val = pcie->scb_size_vals[0] ? pcie->scb_size_vals[0] : 0xf;
	wr_fld(base + PCIE_MISC_MISC_CTRL, 0xf8000000, 27, scb_size_val);

	/* field: SCB1_SIZE, default = 0xf (1 GB) */
	if (num_memc > 1) {
		scb_size_val = pcie->scb_size_vals[1]
			? pcie->scb_size_vals[1] : 0xf;
		wr_fld(base + PCIE_MISC_MISC_CTRL, 0x07c00000,
		       22, scb_size_val);
	}

	/* field: SCB2_SIZE, default = 0xf (1 GB) */
	if (num_memc > 2) {
		scb_size_val = pcie->scb_size_vals[2]
			? pcie->scb_size_vals[2] : 0xf;
		wr_fld(base + PCIE_MISC_MISC_CTRL, 0x0000001f,
		       0, scb_size_val);
	}

	/* disable the PCIE->GISB memory window */
	__raw_writel(0x00000000, base + PCIE_MISC_RC_BAR1_CONFIG_LO);

	/* disable the PCIE->SCB memory window */
	__raw_writel(0x00000000, base + PCIE_MISC_RC_BAR3_CONFIG_LO);

	if (!pcie->suspended) {
		/* clear any interrupts we find on boot */
		__raw_writel(0xffffffff, base + PCIE_INTR2_CPU_BASE + CLR);
		(void) __raw_readl(base + PCIE_INTR2_CPU_BASE + CLR);
	}

	/* Mask all interrupts since we are not handling any yet */
	__raw_writel(0xffffffff, base + PCIE_INTR2_CPU_BASE + MASK_SET);
	(void) __raw_readl(base + PCIE_INTR2_CPU_BASE + MASK_SET);

	if (pcie->gen)
		set_gen(base, pcie->gen);

	/* take the EP device out of reset */
	/* field: PCIE_SW_PERST = 0 */
	wr_fld_rb(base + PCIE_RGR1_SW_INIT_1, 0x00000001, 0, 0);
}


static int brcm_setup_pcie_bridge(int nr, struct pci_sys_data *sys)
{
	struct brcm_pcie *pcie = sys->private_data;
	void __iomem *base = pcie->base;
	const int limit = pcie->suspended ? 1000 : 100;
	struct clk *clk;
	unsigned status;
	static const char *link_speed[4] = { "???", "2.5", "5.0", "8.0" };
	int i, j, ret;
	bool ssc_good = false;

	pcie->sys = sys;

	/* Give the RC/EP time to wake up, before trying to configure RC.
	 * Intermittently check status for link-up, up to a total of 100ms
	 * when we don't know if the device is there, and up to 1000ms if
	 * we do know the device is there. */
	for (i = 1, j = 0; j < limit && !is_pcie_link_up(pcie); j += i, i = i*2)
		mdelay(i + j > limit ? limit - j : i);

	if (!is_pcie_link_up(pcie)) {
		dev_info(pcie->dev, "link down\n");
		goto FAIL;
	}

	/* Attempt to enable MSI if we have an interrupt for it. */
	if (pcie->msi.irq > 0) {
		ret = brcm_pcie_enable_msi(pcie, nr);
		if (ret < 0) {
			dev_err(pcie->dev, "failed to enable MSI support: %d\n",
				ret);
		}
	}

	/* For config space accesses on the RC, show the right class for
	 * a PCI-PCI bridge */
	wr_fld_rb(base + PCIE_RC_CFG_PRIV1_ID_VAL3, 0x00ffffff, 0, 0x060400);

	if (!pcie->suspended)
		for (i = 0; i < pcie->num_out_wins; i++)
			pci_add_resource_offset(&sys->resources,
					&pcie->out_wins[i].pcie_iomem_res,
					sys->mem_offset);

	status = __raw_readl(base + PCIE_RC_CFG_PCIE_LINK_STATUS_CONTROL);

	if (pcie->ssc) {
		if (set_ssc(base))
			dev_err(pcie->dev,
				"mdio rd/wt fail during ssc config\n");
		ret = is_ssc(base);
		if (ret == 0) {
			ssc_good = true;
		} else {
			if (ret < 0)
				dev_err(pcie->dev,
					"mdio rd/wt fail during ssc query\n");
			dev_err(pcie->dev, "failed to enter SSC mode\n");
		}
	}

	dev_info(pcie->dev, "link up, %s Gbps x%u %s\n",
		 link_speed[((status & 0x000f0000) >> 16) & 0x3],
		 (status & 0x03f00000) >> 20, ssc_good ? "(SSC)" : "(!SSC)");

	/* Enable configuration request retry (see pci_scan_device()) */
	/* field RC_CRS_EN = 1 */
	wr_fld(base + PCIE_RC_CFG_PCIE_ROOT_CAP_CONTROL, 0x00000010, 4, 1);

	/* PCIE->SCB endian mode for BAR */
	/* field ENDIAN_MODE_BAR2 = DATA_ENDIAN */
	wr_fld_rb(base + PCIE_RC_CFG_VENDOR_VENDOR_SPECIFIC_REG1, 0x0000000c, 2,
		  DATA_ENDIAN);

	/* Refclk from RC should be gated with CLKREQ# input when ASPM L0s,L1
	 * is enabled =>  setting the CLKREQ_DEBUG_ENABLE field to 1. */
	wr_fld_rb(base + PCIE_MISC_HARD_PCIE_HARD_DEBUG, 0x00000002, 1, 1);

	return 1;
FAIL:
	if (IS_ENABLED(CONFIG_PM))
		turn_off(base);

	clk = pcie->clk;
	if (pcie->suspended)
		clk_disable(clk);
	else {
		clk_disable_unprepare(clk);
		clk_put(clk);
		remove_pcie(pcie);
	}
	return 0;

}


/*
 * syscore device to handle PCIe bus suspend and resume
 */

static void turn_off(void __iomem *base)
{
	/* Reset endpoint device */
	wr_fld_rb(base + PCIE_RGR1_SW_INIT_1, 0x00000001, 0, 1);
	/* deassert request for L23 in case it was asserted */
	wr_fld_rb(base + PCIE_MISC_PCIE_CTRL, 0x1, 0, 0);
	/* SERDES_IDDQ = 1 */
	wr_fld_rb(base + PCIE_MISC_HARD_PCIE_HARD_DEBUG, 0x08000000,
		  27, 1);
	/* Shutdown PCIe bridge */
	wr_fld_rb(base + PCIE_RGR1_SW_INIT_1, 0x00000002, 1, 1);
}


static void enter_l23(struct brcm_pcie *pcie)
{
	void __iomem *base = pcie->base;
	int timeout = 1000;
	int l23;

	/* assert request for L23 */
	wr_fld_rb(base + PCIE_MISC_PCIE_CTRL, 0x1, 0, 1);
	do {
		/* poll L23 status */
		l23 = __raw_readl(base + PCIE_MISC_PCIE_STATUS) & (1 << 6);
	} while (--timeout && !l23);

	if (!timeout)
		dev_err(pcie->dev, "failed to enter L23\n");
}


static int pcie_suspend(void)
{
	struct brcm_pcie *pcie;
	struct list_head *pos;
	struct brcm_dev_pwr_supply *supply;


	list_for_each_entry(pcie, &brcm_pcie, list) {
		enter_l23(pcie);
		turn_off(pcie->base);
		clk_disable(pcie->clk);
		list_for_each(pos, &pcie->pwr_supplies) {
			supply = list_entry(pos, struct brcm_dev_pwr_supply,
					    node);
			if (regulator_disable(supply->regulator))
				pr_debug("Unable to turn off %s supply.\n",
					 supply->name);

		}
		pcie->suspended = true;
	}
	return 0;
}


static void pcie_resume(void)
{
	int i = 0;
	struct brcm_pcie *pcie;
	struct list_head *pos;
	struct brcm_dev_pwr_supply *supply;

	list_for_each_entry(pcie, &brcm_pcie, list) {
		void __iomem *base;

		base = pcie->base;
		list_for_each(pos, &pcie->pwr_supplies) {
			supply = list_entry(pos, struct brcm_dev_pwr_supply,
					    node);
			if (regulator_enable(supply->regulator))
				pr_debug("Unable to turn on %s supply.\n",
					 supply->name);
		}
		clk_enable(pcie->clk);

		/* Take bridge out of reset so we can access the SERDES reg */
		wr_fld_rb(base + PCIE_RGR1_SW_INIT_1, 0x00000002, 1, 0);

		/* SERDES_IDDQ = 0 */
		wr_fld_rb(base + PCIE_MISC_HARD_PCIE_HARD_DEBUG, 0x08000000,
			  27, 0);
		/* wait for serdes to be stable */
		udelay(100);

		brcm_pcie_setup_early(pcie);
	}

	list_for_each_entry(pcie, &brcm_pcie, list) {
		brcm_setup_pcie_bridge(i++, pcie->sys);
		pcie->suspended = false;
	}
}

static struct syscore_ops pcie_pm_ops = {
	.suspend        = pcie_suspend,
	.resume         = pcie_resume,
};


/***********************************************************************
 * Read/write PCI configuration registers
 ***********************************************************************/
static int cfg_index(int busnr, int devfn, int reg)
{
	return ((PCI_SLOT(devfn) & 0x1f) << PCI_SLOT_SHIFT)
		| ((PCI_FUNC(devfn) & 0x07) << PCI_FUNC_SHIFT)
		| (busnr << PCI_BUSNUM_SHIFT)
		| (reg & ~3);
}

static u32 read_config(void __iomem *base, int cfg_idx)
{
	__raw_writel(cfg_idx, IDX_ADDR(base));
	__raw_readl(IDX_ADDR(base));
	return __raw_readl(DATA_ADDR(base));
}

static void write_config(void __iomem *base, int cfg_idx, u32 val)
{
	__raw_writel(cfg_idx, IDX_ADDR(base));
	__raw_readl(IDX_ADDR(base));
	__raw_writel(val, DATA_ADDR(base));
	__raw_readl(DATA_ADDR(base));
}


static int brcm_pci_write_config(struct pci_bus *bus, unsigned int devfn,
				 int where, int size, u32 data)
{
	u32 val = 0, mask, shift;
	struct pci_sys_data *sys = bus->sysdata;
	struct brcm_pcie *pcie = sys->private_data;
	void __iomem *base;
	bool rc_access;
	int idx;

	if (!is_pcie_link_up(pcie))
		return PCIBIOS_DEVICE_NOT_FOUND;

	base = pcie->base;
	rc_access = sys->busnr == bus->number;
	idx = cfg_index(bus->number, devfn, where);
	BUG_ON(((where & 3) + size) > 4);

	if (rc_access && PCI_SLOT(devfn))
		return PCIBIOS_DEVICE_NOT_FOUND;

	if (size < 4) {
		/* partial word - read, modify, write */
		if (rc_access)
			val = __raw_readl(base + (where & ~3));
		else
			val = read_config(base, idx);
	}

	shift = (where & 3) << 3;
	mask = (0xffffffff >> ((4 - size) << 3)) << shift;
	val = (val & ~mask) | ((data << shift) & mask);

	if (rc_access) {
		__raw_writel(val, base + (where & ~3));
		__raw_readl(base + (where & ~3));
	} else {
		write_config(base, idx, val);
	}
	return PCIBIOS_SUCCESSFUL;
}


static int brcm_pci_read_config(struct pci_bus *bus, unsigned int devfn,
				int where, int size, u32 *data)
{
	struct pci_sys_data *sys = bus->sysdata;
	struct brcm_pcie *pcie = sys->private_data;
	u32 val, mask, shift;
	void __iomem *base;
	bool rc_access;
	int idx;

	if (!is_pcie_link_up(pcie))
		return PCIBIOS_DEVICE_NOT_FOUND;

	base = pcie->base;
	rc_access = sys->busnr == bus->number;
	idx = cfg_index(bus->number, devfn, where);
	BUG_ON(((where & 3) + size) > 4);

	if (rc_access && PCI_SLOT(devfn)) {
		*data = 0xffffffff;
		return PCIBIOS_FUNC_NOT_SUPPORTED;
	}

	if (rc_access)
		val = __raw_readl(base + (where & ~3));
	else
		val = read_config(base, idx);

	shift = (where & 3) << 3;
	mask = (0xffffffff >> ((4 - size) << 3)) << shift;
	*data = (val & mask) >> shift;

	return PCIBIOS_SUCCESSFUL;
}




/***********************************************************************
 * PCI slot to IRQ mappings (aka "fixup")
 ***********************************************************************/
static int __init brcm_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
	struct pci_sys_data *sys = dev->bus->sysdata;
	struct brcm_pcie *pcie = sys->private_data;

	if (pcie) {
		if (!pcie->broken_pcie_irq_map_dt)
			return of_irq_parse_and_map_pci(dev, slot, pin);
		if ((pin - 1) > 3)
			return 0;
		return pcie->pcie_irq[pin - 1];
	}
	return 0;
}


/***********************************************************************
 * Per-device initialization
 ***********************************************************************/
static void __attribute__((__section__("pci_fixup_early")))
brcm_pcibios_fixup(struct pci_dev *dev)
{
	struct pci_sys_data *sys = dev->bus->sysdata;
	struct brcm_pcie *pcie = sys->private_data;
	int slot = PCI_SLOT(dev->devfn);

	if (pci_is_root_bus(dev->bus)) {
		/* Set the root pci_dev's device node */
		if (!dev->dev.of_node)
			dev->dev.of_node = pcie->dn;
		/* Set the root bus's msi value */
		if (IS_ENABLED(CONFIG_PCI_MSI))
			dev->bus->msi = &pcie->msi.chip;
	}
	dev_info(pcie->dev,
		 "found device %04x:%04x on bus %d (%s), slot %d (irq %d)\n",
		 dev->vendor, dev->device, dev->bus->number, pcie->name,
		 slot, brcm_map_irq(dev, slot, 1));
}
DECLARE_PCI_FIXUP_EARLY(PCI_ANY_ID, PCI_ANY_ID, brcm_pcibios_fixup);


/***********************************************************************
 * PCI Platform Driver
 ***********************************************************************/
static int __init brcm_pci_probe(struct platform_device *pdev)
{
	struct device_node *dn = pdev->dev.of_node, *mdn;
	const u32 *imap_prop;
	int len, i, irq_offset, rlen, pna, np, ret;
	struct brcm_pcie *pcie;
	struct resource *r;
	const u32 *ranges, *log2_scb_sizes, *dma_ranges;
	void __iomem *base;
	u32 tmp;
	int supplies;
	const char *name;
	struct brcm_dev_pwr_supply *supply;

	pcie = devm_kzalloc(&pdev->dev, sizeof(struct brcm_pcie), GFP_KERNEL);
	if (!pcie)
		return -ENOMEM;

	INIT_LIST_HEAD(&pcie->pwr_supplies);
	supplies = of_property_count_strings(dn, "supply-names");
	if (supplies <= 0)
		supplies = 0;

	for (i = 0; i < supplies; i++) {
		if (of_property_read_string_index(dn, "supply-names", i,
						  &name))
			continue;
		supply = devm_kzalloc(&pdev->dev, sizeof(*supply), GFP_KERNEL);
		if (!supply)
			return -ENOMEM;
		strncpy(supply->name, name, sizeof(supply->name));
		supply->name[sizeof(supply->name) - 1] = '\0';
		supply->regulator = devm_regulator_get(&pdev->dev, name);
		if (IS_ERR(supply->regulator)) {
			dev_err(&pdev->dev, "Unable to get %s supply, err=%d\n",
				name, (int)PTR_ERR(supply->regulator));
			continue;
		}
		if (regulator_enable(supply->regulator))
			dev_err(&pdev->dev, "Unable to enable %s supply.\n",
				name);
		list_add_tail(&supply->node, &pcie->pwr_supplies);
	}

	/* 'num_memc' will be set only by the first controller, and all
	 * other controllers will use the value set by the first. */
	if (num_memc == 0)
		for_each_compatible_node(mdn, NULL, "brcm,brcmstb-memc")
			if (of_device_is_available(mdn))
				num_memc++;

	r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!r)
		return -EINVAL;

	base = devm_request_and_ioremap(&pdev->dev, r);
	if (!base)
		return -ENOMEM;

	imap_prop = of_get_property(dn, "interrupt-map", &len);

	if (imap_prop == NULL) {
		dev_err(&pdev->dev, "missing interrupt-map\n");
		return -EINVAL;
	}

	if (len == sizeof(u32) * 4 * 7) {
		/* broken method for getting INT{ABCD} */
		dev_info(&pdev->dev, "adjusting to legacy (broken) pcie DT\n");
		pcie->broken_pcie_irq_map_dt = true;
		irq_offset = irq_of_parse_and_map(dn, 0);
		for (i = 0; i < 4 && i*4 < len; i++)
			pcie->pcie_irq[i] = irq_offset
				+ of_read_number(imap_prop + (i * 7 + 5), 1);
	}

	snprintf(pcie->name,
		 sizeof(pcie->name)-1, "PCIe%d", brcm_num_pci_controllers);
	pcie->suspended = false;
	pcie->clk = of_clk_get_by_name(dn, "sw_pcie");
	if (IS_ERR(pcie->clk)) {
		dev_err(&pdev->dev, "could not get clock\n");
		pcie->clk = NULL;
	}
	ret = clk_prepare_enable(pcie->clk);
	if (ret) {
		dev_err(&pdev->dev, "could not enable clock\n");
		return ret;
	}
	pcie->dn = dn;
	pcie->base = base;
	pcie->dev = &pdev->dev;
	pcie->dev->of_node = dn;
	pcie->gen = 0;

	ret = of_property_read_u32(dn, "brcm,gen", &tmp);
	if (ret == 0) {
		if (tmp > 0 && tmp < 3)
			pcie->gen = (int) tmp;
		else
			dev_warn(pcie->dev, "bad DT value for prop 'brcm,gen");
	} else if (ret != -EINVAL) {
		dev_warn(pcie->dev, "error reading DT prop 'brcm,gen");
	}

	pcie->ssc = of_property_read_bool(dn, "brcm,ssc");

	/* Get the value for the log2 of the scb sizes.  Subtract 15 from
	 * each because the target register field has 0==disabled and 1==64KB.
	 */
	log2_scb_sizes = of_get_property(dn, "brcm,log2-scb-sizes", &rlen);
	if (log2_scb_sizes != NULL)
		for (i = 0; i < rlen/4; i++)
			pcie->scb_size_vals[i]
				= (int) of_read_number(log2_scb_sizes + i, 1)
					- 15;

	/* Look for the dma-ranges property.  If it exists, issue a warning
	 * as PCIe drivers may not work.  This is because the identity
	 * mapping between system memory and PCIe space is not preserved,
	 * and we need Linux to massage the dma_addr_t values it gets
	 * from dma memory allocation.  This functionality will be added
	 * in the near future.
	 */
	dma_ranges = of_get_property(dn, "dma-ranges", &rlen);
	if (dma_ranges != NULL)
		dev_warn(pcie->dev, "no identity map; PCI drivers may fail");

	if (!pcie->broken_pcie_irq_map_dt) {
		ret = irq_of_parse_and_map(pdev->dev.of_node, 0);
		if (ret == 0) {
			dev_warn(pcie->dev, "cannot get pcie interrupt\n");
			/* keep going, as we don't use this yet */
		} else {
			pcie->irq = ret;
		}
	}

	ranges = of_get_property(dn, "ranges", &rlen);
	if (ranges == NULL) {
		dev_err(pcie->dev, "no ranges property in dev tree.\n");
		return -EINVAL;
	}
	/* set up CPU->PCIE memory windows (max of four) */
	pna = of_n_addr_cells(dn);
	np = pna + 5;

	pcie->num_out_wins = rlen / (np * 4);

	if (IS_ENABLED(CONFIG_PCI_MSI)) {
		ret = irq_of_parse_and_map(pdev->dev.of_node, 1);
		if (ret == 0)
			dev_warn(pcie->dev, "cannot get msi intr; MSI disabled\n");
		else
			pcie->msi.irq = ret;
	}

	for (i = 0; i < pcie->num_out_wins; i++) {
		struct brcm_window *w = &pcie->out_wins[i];
		w->info = (u32) of_read_ulong(ranges + 0, 1);
		w->pci_addr = of_read_number(ranges + 1, 2);
		w->cpu_addr = of_translate_address(dn, ranges + 3);
		w->size = of_read_number(ranges + pna + 3, 2);
		ranges += np;

		w->pcie_iomem_res.name	= "External PCIe MEM";
		w->pcie_iomem_res.flags	= IORESOURCE_MEM;
		w->pcie_iomem_res.start	= w->cpu_addr;
		w->pcie_iomem_res.end	= w->cpu_addr + w->size - 1;

		/* Request memory region resources. */
		if (request_resource(&iomem_resource, &w->pcie_iomem_res)) {
			dev_err(&pdev->dev,
				"request PCIe memory resource failed\n");
			return -EIO;
		}
	}

	/*
	 * Starts PCIe link negotiation immediately at kernel boot time.  The
	 * RC is supposed to give the endpoint device 100ms to settle down
	 * before attempting configuration accesses.  So we let the link
	 * negotiation happen in the background instead of busy-waiting.
	 */
	brcm_pcie_setup_early(pcie);
	list_add_tail(&pcie->list, &brcm_pcie);
	brcm_num_pci_controllers++;

	return 0;
}


static const struct of_device_id brcm_pci_match[] = {
	{ .compatible = "brcm,pci-plat-dev" },
	{},
};
MODULE_DEVICE_TABLE(of, brcm_pci_match);


static struct platform_driver __refdata brcm_pci_driver = {
	.probe = brcm_pci_probe,
	.driver = {
		.name = "brcm-pci",
		.owner = THIS_MODULE,
		.of_match_table = brcm_pci_match,
	},
};


int __init brcm_pcibios_init(void)
{
	int ret;

	INIT_LIST_HEAD(&brcm_pcie);
	ret = platform_driver_probe(&brcm_pci_driver, brcm_pci_probe);
	if (!ret && brcm_num_pci_controllers > 0) {
		void **private_data;
		struct brcm_pcie *pcie;
		int i = 0;

		brcm_pcie_hw.nr_controllers = brcm_num_pci_controllers;
		if (IS_ENABLED(CONFIG_PM))
			register_syscore_ops(&pcie_pm_ops);

		private_data = kzalloc(brcm_num_pci_controllers
				       * sizeof(void *), GFP_KERNEL);
		if (!private_data)
			return -ENOMEM;
		list_for_each_entry(pcie, &brcm_pcie, list)
			private_data[i++] = pcie;
		BUG_ON(i != brcm_num_pci_controllers);
		brcm_pcie_hw.private_data = private_data;
		pci_common_init(&brcm_pcie_hw);
		kfree(brcm_pcie_hw.private_data);
		brcm_pcie_hw.private_data = NULL;
	}
	return ret;
}


fs_initcall(brcm_pcibios_init);

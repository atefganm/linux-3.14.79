
#ifndef __RTL2832U_AUDIO_H__
#define __RTL2832U_AUDIO_H__


#if 0

#include "rtl2832u_fe.h"
#include "rtl2832u_io.h"
#include "dvbdev.h"
#include "dvb_demux.h"
#include "dvb-usb.h"

#define UCHAR  unsigned char



struct fm_cmd_struct
{
	int cmd_num;
	int cr;
	int tuner;	
	int tr;
};


#define FE_FM_CMD    _IOWR('o', 90,  struct fm_cmd_struct)

enum
{
	FE_ENABLE_FM=0,
	FE_DISABLE_FM,
	CR_D,
	CR_A,
	CR_S,
	READ_BYTE,
	WRITE_BYTE,
	FE_ENABLE_DAB,
	FE_DISABLE_DAB,
	TR_D,
	TR_A,
};

enum
{
	FM_MODE = 0,
	DAB_MODE,
};



int rtl2832_fe_ioctl_override(struct dvb_frontend *fe,unsigned int cmd, void *parg, unsigned int stage);
void fm_stream_ctrl(int f,  struct dvb_usb_adapter*  adapter);


#endif

#endif

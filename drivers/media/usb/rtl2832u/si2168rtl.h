#ifndef __Si2168RTL_H__
#define __Si2168RTL_H__

typedef enum   CUSTOM_Standard_Enum
{
	SILABS_ANALOG = 4,
	SILABS_DVB_T  = 0,
	SILABS_DVB_C  = 1,
	SILABS_DVB_S  = 2,
	SILABS_DVB_S2 = 3,
	SILABS_DVB_T2 = 5,
	SILABS_DSS    = 6
} CUSTOM_Standard_Enum;

typedef enum   CUSTOM_Constel_Enum
{
	SILABS_QAMAUTO = -1,
	SILABS_QAM16   = 0,
	SILABS_QAM32   = 1,
	SILABS_QAM64   = 2,
	SILABS_QAM128  = 3,
	SILABS_QAM256  = 4,
	SILABS_QPSK    = 5,
	SILABS_8PSK    = 6
} CUSTOM_Constel_Enum;

typedef enum   CUSTOM_Stream_Enum
{
	SILABS_HP = 0,
	SILABS_LP = 1
} CUSTOM_Stream_Enum;

typedef enum   CUSTOM_TS_Mode_Enum
{
	SILABS_TS_TRISTATE = 0,
	SILABS_TS_SERIAL   = 1,
	SILABS_TS_PARALLEL = 2,
	SILABS_TS_GPIF     = 3
} CUSTOM_TS_Mode_Enum;

typedef enum   CUSTOM_FFT_Mode_Enum
{
	SILABS_FFT_MODE_2K  = 0,
	SILABS_FFT_MODE_4K  = 1,
	SILABS_FFT_MODE_8K  = 2,
	SILABS_FFT_MODE_16K = 3,
	SILABS_FFT_MODE_32K = 4
} CUSTOM_FFT_Mode_Enum;

typedef enum   CUSTOM_GI_Enum
{
	SILABS_GUARD_INTERVAL_1_32    = 0,
	SILABS_GUARD_INTERVAL_1_16    = 1,
	SILABS_GUARD_INTERVAL_1_8     = 2,
	SILABS_GUARD_INTERVAL_1_4     = 3,
	SILABS_GUARD_INTERVAL_1_128   = 4,
	SILABS_GUARD_INTERVAL_19_128  = 5,
	SILABS_GUARD_INTERVAL_19_256  = 6
} CUSTOM_GI_Enum;

typedef enum   CUSTOM_Coderate_Enum
{
	SILABS_CODERATE_1_2  = 0,
	SILABS_CODERATE_2_3  = 1,
	SILABS_CODERATE_3_4  = 2,
	SILABS_CODERATE_4_5  = 3,
	SILABS_CODERATE_5_6  = 4,
	SILABS_CODERATE_7_8  = 5,
	SILABS_CODERATE_8_9  = 6,
	SILABS_CODERATE_9_10 = 7,
	SILABS_CODERATE_1_3  = 8,
	SILABS_CODERATE_1_4  = 9,
	SILABS_CODERATE_2_5  = 10,
	SILABS_CODERATE_3_5  = 11,
} CUSTOM_Coderate_Enum;

typedef enum   CUSTOM_Hierarchy_Enum
{
	SILABS_HIERARCHY_NONE  = 0,
	SILABS_HIERARCHY_ALFA1 = 1,
	SILABS_HIERARCHY_ALFA2 = 2,
	SILABS_HIERARCHY_ALFA4 = 3
} CUSTOM_Hierarchy_Enum;

typedef enum   CUSTOM_Video_Sys_Enum
{
	SILABS_VIDEO_SYS_B  = 0,
	SILABS_VIDEO_SYS_GH = 1,
	SILABS_VIDEO_SYS_M  = 2,
	SILABS_VIDEO_SYS_N  = 3,
	SILABS_VIDEO_SYS_I  = 4,
	SILABS_VIDEO_SYS_DK = 5,
	SILABS_VIDEO_SYS_L  = 6,
	SILABS_VIDEO_SYS_LP = 7
} CUSTOM_Video_Sys_Enum;

typedef enum   CUSTOM_Transmission_Mode_Enum
{
	SILABS_TRANSMISSION_MODE_TERRESTRIAL = 0,
	SILABS_TRANSMISSION_MODE_CABLE       = 1
} CUSTOM_Transmission_Mode_Enum;

typedef enum   CUSTOM_Pilot_Pattern_Enum
{
	SILABS_PILOT_PATTERN_PP1 = 1,
	SILABS_PILOT_PATTERN_PP2 = 2,
	SILABS_PILOT_PATTERN_PP3 = 3,
	SILABS_PILOT_PATTERN_PP4 = 4,
	SILABS_PILOT_PATTERN_PP5 = 5,
	SILABS_PILOT_PATTERN_PP6 = 6,
	SILABS_PILOT_PATTERN_PP7 = 7,
	SILABS_PILOT_PATTERN_PP8 = 8,
} CUSTOM_Pilot_Pattern_Enum;

typedef enum   CUSTOM_Color_Enum
{
	SILABS_COLOR_PAL_NTSC  = 0,
	SILABS_COLOR_SECAM     = 1
} CUSTOM_Color_Enum;

typedef enum   CUSTOM_Audio_Sys_Enum
{
	SILABS_AUDIO_SYS_DEFAULT         = 0,
	SILABS_AUDIO_SYS_MONO            = 1,
	SILABS_AUDIO_SYS_MONO_NICAM      = 2,
	SILABS_AUDIO_SYS_A2              = 3,
	SILABS_AUDIO_SYS_A2_DK2          = 4,
	SILABS_AUDIO_SYS_A2_DK3          = 5,
	SILABS_AUDIO_SYS_BTSC            = 6,
	SILABS_AUDIO_SYS_EIAJ            = 7,
	SILABS_AUDIO_SYS_SCAN            = 8,
	SILABS_AUDIO_SYS_A2_DK4          = 9,
	SILABS_AUDIO_SYS_WIDE_SCAN       = 10,
	SILABS_AUDIO_SYS_MONO_NICAM_6DB  = 11,
	SILABS_AUDIO_SYS_MONO_NICAM_10DB = 12
} CUSTOM_Audio_Sys_Enum;

typedef enum CONNECTION_TYPE
{
	SIMU = 0,
	USB,
	CUSTOMER,
	none
} CONNECTION_TYPE;

#define Si2168_TERRESTRIAL 1

typedef struct L0_Context
{
	unsigned char   address;
	int             indexSize;
	CONNECTION_TYPE connectionType;
	int             trackWrite;
	int             trackRead;
	int             mustReadWithoutStop;
} L0_Context;

typedef struct
{ // Si2168_COMMON_REPLY_struct
	unsigned char   ddint;
	unsigned char   scanint;
	unsigned char   err;
	unsigned char   cts;
} Si2168_COMMON_REPLY_struct;

#define Si2168_POWER_DOWN_CMD 0x13

#ifdef Si2168_POWER_DOWN_CMD
	#define Si2168_POWER_DOWN_CMD_CODE 0x010013
	typedef struct
	{ // Si2168_POWER_DOWN_CMD_struct
		unsigned char nothing;
	} Si2168_POWER_DOWN_CMD_struct;
	typedef struct
	{ // Si2168_POWER_DOWN_CMD_REPLY_struct
		Si2168_COMMON_REPLY_struct * STATUS;
	} Si2168_POWER_DOWN_CMD_REPLY_struct;
#endif // Si2168_POWER_DOWN_CMD

#define Si2168_DD_MODE_PROP 0x100a

#define Si2168_START_CLK_CMD 0xc0

#ifdef Si2168_START_CLK_CMD
	#define Si2168_START_CLK_CMD_CODE 0x0300c0
	typedef struct
	{ // Si2168_START_CLK_CMD_struct
		unsigned char   subcode;
		unsigned char   reserved1;
		unsigned char   tune_cap;
		unsigned char   reserved2;
		unsigned int    clk_mode;
		unsigned char   reserved3;
		unsigned char   reserved4;
		unsigned char   start_clk;
	} Si2168_START_CLK_CMD_struct;
	typedef struct
	{ // Si2168_START_CLK_CMD_REPLY_struct
		Si2168_COMMON_REPLY_struct * STATUS;
	} Si2168_START_CLK_CMD_REPLY_struct;
	// START_CLK command, SUBCODE field definition (address 1,size 8, lsb 0, unsigned)
	#define  Si2168_START_CLK_CMD_SUBCODE_LSB         0
	#define  Si2168_START_CLK_CMD_SUBCODE_MASK        0xff
	#define  Si2168_START_CLK_CMD_SUBCODE_MIN         18
	#define  Si2168_START_CLK_CMD_SUBCODE_MAX         18
	#define Si2168_START_CLK_CMD_SUBCODE_CODE  18
	// START_CLK command, RESERVED1 field definition (address 2,size 8, lsb 0, unsigned)
	#define  Si2168_START_CLK_CMD_RESERVED1_LSB         0
	#define  Si2168_START_CLK_CMD_RESERVED1_MASK        0xff
	#define  Si2168_START_CLK_CMD_RESERVED1_MIN         0
	#define  Si2168_START_CLK_CMD_RESERVED1_MAX         0
	#define Si2168_START_CLK_CMD_RESERVED1_RESERVED  0
	// START_CLK command, TUNE_CAP field definition (address 3,size 4, lsb 0, unsigned)
	#define  Si2168_START_CLK_CMD_TUNE_CAP_LSB         0
	#define  Si2168_START_CLK_CMD_TUNE_CAP_MASK        0x0f
	#define  Si2168_START_CLK_CMD_TUNE_CAP_MIN         0
	#define  Si2168_START_CLK_CMD_TUNE_CAP_MAX         15
	#define Si2168_START_CLK_CMD_TUNE_CAP_10P4     8
	#define Si2168_START_CLK_CMD_TUNE_CAP_11P7     9
	#define Si2168_START_CLK_CMD_TUNE_CAP_13P0     10
	#define Si2168_START_CLK_CMD_TUNE_CAP_14P3     11
	#define Si2168_START_CLK_CMD_TUNE_CAP_15P6     12
	#define Si2168_START_CLK_CMD_TUNE_CAP_16P9     13
	#define Si2168_START_CLK_CMD_TUNE_CAP_18P2     14
	#define Si2168_START_CLK_CMD_TUNE_CAP_19P5     15
	#define Si2168_START_CLK_CMD_TUNE_CAP_1P3      1
	#define Si2168_START_CLK_CMD_TUNE_CAP_2P6      2
	#define Si2168_START_CLK_CMD_TUNE_CAP_3P9      3
	#define Si2168_START_CLK_CMD_TUNE_CAP_5P2      4
	#define Si2168_START_CLK_CMD_TUNE_CAP_6P5      5
	#define Si2168_START_CLK_CMD_TUNE_CAP_7P8      6
	#define Si2168_START_CLK_CMD_TUNE_CAP_9P1      7
	#define Si2168_START_CLK_CMD_TUNE_CAP_EXT_CLK  0
	// START_CLK command, RESERVED2 field definition (address 3,size 4, lsb 4, unsigned)
	#define  Si2168_START_CLK_CMD_RESERVED2_LSB         4
	#define  Si2168_START_CLK_CMD_RESERVED2_MASK        0x0f
	#define  Si2168_START_CLK_CMD_RESERVED2_MIN         0
	#define  Si2168_START_CLK_CMD_RESERVED2_MAX         0
	#define Si2168_START_CLK_CMD_RESERVED2_RESERVED  0
	// START_CLK command, CLK_MODE field definition (address 4,size 12, lsb 0, unsigned)
	#define  Si2168_START_CLK_CMD_CLK_MODE_LSB         0
	#define  Si2168_START_CLK_CMD_CLK_MODE_MASK        0xfff
	#define  Si2168_START_CLK_CMD_CLK_MODE_MIN         575
	#define  Si2168_START_CLK_CMD_CLK_MODE_MAX         3328
	#define Si2168_START_CLK_CMD_CLK_MODE_CLK_CLKIO    3328
	#define Si2168_START_CLK_CMD_CLK_MODE_CLK_XTAL_IN  1536
	#define Si2168_START_CLK_CMD_CLK_MODE_XTAL         575
	// START_CLK command, RESERVED3 field definition (address 6,size 8, lsb 0, unsigned)
	#define  Si2168_START_CLK_CMD_RESERVED3_LSB         0
	#define  Si2168_START_CLK_CMD_RESERVED3_MASK        0xff
	#define  Si2168_START_CLK_CMD_RESERVED3_MIN         22
	#define  Si2168_START_CLK_CMD_RESERVED3_MAX         22
	#define Si2168_START_CLK_CMD_RESERVED3_RESERVED  22
	// START_CLK command, RESERVED4 field definition (address 7,size 1, lsb 0, unsigned)
	#define  Si2168_START_CLK_CMD_RESERVED4_LSB         0
	#define  Si2168_START_CLK_CMD_RESERVED4_MASK        0x01
	#define  Si2168_START_CLK_CMD_RESERVED4_MIN         0
	#define  Si2168_START_CLK_CMD_RESERVED4_MAX         0
	#define Si2168_START_CLK_CMD_RESERVED4_RESERVED  0
	// START_CLK command, START_CLK field definition (address 12,size 1, lsb 0, unsigned)
	#define  Si2168_START_CLK_CMD_START_CLK_LSB         0
	#define  Si2168_START_CLK_CMD_START_CLK_MASK        0x01
	#define  Si2168_START_CLK_CMD_START_CLK_MIN         0
	#define  Si2168_START_CLK_CMD_START_CLK_MAX         0
	#define Si2168_START_CLK_CMD_START_CLK_START_CLK    0//Yann
#endif // Si2168_START_CLK_CMD

#define Si2168_POWER_UP_CMD 0xc0

#ifdef Si2168_POWER_UP_CMD
	#define Si2168_POWER_UP_CMD_CODE 0x0200c0
	typedef struct
	{ // Si2168_POWER_UP_CMD_struct
		unsigned char   subcode;
		unsigned char   reset;
		unsigned char   reserved2;
		unsigned char   reserved4;
		unsigned char   reserved1;
		unsigned char   addr_mode;
		unsigned char   reserved5;
		unsigned char   func;
		unsigned char   clock_freq;
		unsigned char   ctsien;
		unsigned char   wake_up;
	} Si2168_POWER_UP_CMD_struct;
	typedef struct
	{ // Si2168_POWER_UP_CMD_REPLY_struct
		Si2168_COMMON_REPLY_struct * STATUS;
	} Si2168_POWER_UP_CMD_REPLY_struct;
	// POWER_UP command, SUBCODE field definition (address 1,size 8, lsb 0, unsigned)
	#define  Si2168_POWER_UP_CMD_SUBCODE_LSB         0
	#define  Si2168_POWER_UP_CMD_SUBCODE_MASK        0xff
	#define  Si2168_POWER_UP_CMD_SUBCODE_MIN         6
	#define  Si2168_POWER_UP_CMD_SUBCODE_MAX         6
	#define Si2168_POWER_UP_CMD_SUBCODE_CODE  6
	// POWER_UP command, RESET field definition (address 2,size 8, lsb 0, unsigned)
	#define  Si2168_POWER_UP_CMD_RESET_LSB         0
	#define  Si2168_POWER_UP_CMD_RESET_MASK        0xff
	#define  Si2168_POWER_UP_CMD_RESET_MIN         1
	#define  Si2168_POWER_UP_CMD_RESET_MAX         8
	#define Si2168_POWER_UP_CMD_RESET_RESET   1
	#define Si2168_POWER_UP_CMD_RESET_RESUME  8
	// POWER_UP command, RESERVED2 field definition (address 3,size 8, lsb 0, unsigned)
	#define  Si2168_POWER_UP_CMD_RESERVED2_LSB         0
	#define  Si2168_POWER_UP_CMD_RESERVED2_MASK        0xff
	#define  Si2168_POWER_UP_CMD_RESERVED2_MIN         15
	#define  Si2168_POWER_UP_CMD_RESERVED2_MAX         15
	#define Si2168_POWER_UP_CMD_RESERVED2_RESERVED  15
	// POWER_UP command, RESERVED4 field definition (address 4,size 8, lsb 0, unsigned)
	#define  Si2168_POWER_UP_CMD_RESERVED4_LSB         0
	#define  Si2168_POWER_UP_CMD_RESERVED4_MASK        0xff
	#define  Si2168_POWER_UP_CMD_RESERVED4_MIN         0
	#define  Si2168_POWER_UP_CMD_RESERVED4_MAX         0
	#define Si2168_POWER_UP_CMD_RESERVED4_RESERVED  0
	// POWER_UP command, RESERVED1 field definition (address 5,size 4, lsb 0, unsigned)
	#define  Si2168_POWER_UP_CMD_RESERVED1_LSB         0
	#define  Si2168_POWER_UP_CMD_RESERVED1_MASK        0x0f
	#define  Si2168_POWER_UP_CMD_RESERVED1_MIN         0
	#define  Si2168_POWER_UP_CMD_RESERVED1_MAX         0
	#define Si2168_POWER_UP_CMD_RESERVED1_RESERVED  0
	// POWER_UP command, ADDR_MODE field definition (address 5,size 1, lsb 4, unsigned)
	#define  Si2168_POWER_UP_CMD_ADDR_MODE_LSB         4
	#define  Si2168_POWER_UP_CMD_ADDR_MODE_MASK        0x01
	#define  Si2168_POWER_UP_CMD_ADDR_MODE_MIN         0
	#define  Si2168_POWER_UP_CMD_ADDR_MODE_MAX         1
	#define Si2168_POWER_UP_CMD_ADDR_MODE_CAPTURE  1
	#define Si2168_POWER_UP_CMD_ADDR_MODE_CURRENT  0//Yann
	// POWER_UP command, RESERVED5 field definition (address 5,size 1, lsb 5, unsigned)
	#define  Si2168_POWER_UP_CMD_RESERVED5_LSB         5
	#define  Si2168_POWER_UP_CMD_RESERVED5_MASK        0x01
	#define  Si2168_POWER_UP_CMD_RESERVED5_MIN         1
	#define  Si2168_POWER_UP_CMD_RESERVED5_MAX         1
	#define Si2168_POWER_UP_CMD_RESERVED5_RESERVED     1//Yann
	// POWER_UP command, FUNC field definition (address 6,size 4, lsb 0, unsigned)
	#define  Si2168_POWER_UP_CMD_FUNC_LSB         0
	#define  Si2168_POWER_UP_CMD_FUNC_MASK        0x0f
	#define  Si2168_POWER_UP_CMD_FUNC_MIN         0
	#define  Si2168_POWER_UP_CMD_FUNC_MAX         1
	#define Si2168_POWER_UP_CMD_FUNC_BOOTLOADER  0
	#define Si2168_POWER_UP_CMD_FUNC_NORMAL      1
	// POWER_UP command, CLOCK_FREQ field definition (address 6,size 3, lsb 4, unsigned)
	#define  Si2168_POWER_UP_CMD_CLOCK_FREQ_LSB         4
	#define  Si2168_POWER_UP_CMD_CLOCK_FREQ_MASK        0x07
	#define  Si2168_POWER_UP_CMD_CLOCK_FREQ_MIN         0
	#define  Si2168_POWER_UP_CMD_CLOCK_FREQ_MAX         4
	#define Si2168_POWER_UP_CMD_CLOCK_FREQ_CLK_16MHZ  0
	#define Si2168_POWER_UP_CMD_CLOCK_FREQ_CLK_24MHZ  2
	#define Si2168_POWER_UP_CMD_CLOCK_FREQ_CLK_27MHZ  3
	// POWER_UP command, CTSIEN field definition (address 6,size 1, lsb 7, unsigned)
	#define  Si2168_POWER_UP_CMD_CTSIEN_LSB         7
	#define  Si2168_POWER_UP_CMD_CTSIEN_MASK        0x01
	#define  Si2168_POWER_UP_CMD_CTSIEN_MIN         0
	#define  Si2168_POWER_UP_CMD_CTSIEN_MAX         1
	#define Si2168_POWER_UP_CMD_CTSIEN_DISABLE  0
	#define Si2168_POWER_UP_CMD_CTSIEN_ENABLE   1
	// POWER_UP command, WAKE_UP field definition (address 7,size 1, lsb 0, unsigned)
	#define  Si2168_POWER_UP_CMD_WAKE_UP_LSB         0
	#define  Si2168_POWER_UP_CMD_WAKE_UP_MASK        0x01
	#define  Si2168_POWER_UP_CMD_WAKE_UP_MIN         1
	#define  Si2168_POWER_UP_CMD_WAKE_UP_MAX         1
	#define Si2168_POWER_UP_CMD_WAKE_UP_WAKE_UP  1
#endif // Si2168_POWER_UP_CMD

#define Si2168_PART_INFO_CMD 0x02

#ifdef Si2168_PART_INFO_CMD
	#define Si2168_PART_INFO_CMD_CODE 0x010002
	typedef struct
	{ // Si2168_PART_INFO_CMD_struct
		unsigned char nothing;
	} Si2168_PART_INFO_CMD_struct;
	typedef struct
	{ // Si2168_PART_INFO_CMD_REPLY_struct
		Si2168_COMMON_REPLY_struct * STATUS;
		unsigned char   chiprev;
		unsigned char   romid;
		unsigned char   part;
		unsigned char   pmajor;
		unsigned char   pminor;
		unsigned char   pbuild;
		unsigned int    reserved;
		unsigned long   serial;
	} Si2168_PART_INFO_CMD_REPLY_struct;
	// PART_INFO command, CHIPREV field definition (address 1, size 4, lsb 0, unsigned)
	#define  Si2168_PART_INFO_RESPONSE_CHIPREV_LSB         0
	#define  Si2168_PART_INFO_RESPONSE_CHIPREV_MASK        0x0f
	#define Si2168_PART_INFO_RESPONSE_CHIPREV_A  1
	#define Si2168_PART_INFO_RESPONSE_CHIPREV_B  2
	// PART_INFO command, ROMID field definition (address 12, size 8, lsb 0, unsigned)
	#define  Si2168_PART_INFO_RESPONSE_ROMID_LSB         0
	#define  Si2168_PART_INFO_RESPONSE_ROMID_MASK        0xff
	// PART_INFO command, PART field definition (address 2, size 8, lsb 0, unsigned)
	#define  Si2168_PART_INFO_RESPONSE_PART_LSB         0
	#define  Si2168_PART_INFO_RESPONSE_PART_MASK        0xff
	// PART_INFO command, PMAJOR field definition (address 3, size 8, lsb 0, unsigned)
	#define  Si2168_PART_INFO_RESPONSE_PMAJOR_LSB         0
	#define  Si2168_PART_INFO_RESPONSE_PMAJOR_MASK        0xff
	// PART_INFO command, PMINOR field definition (address 4, size 8, lsb 0, unsigned)
	#define  Si2168_PART_INFO_RESPONSE_PMINOR_LSB         0
	#define  Si2168_PART_INFO_RESPONSE_PMINOR_MASK        0xff
	// PART_INFO command, PBUILD field definition (address 5, size 8, lsb 0, unsigned)
	#define  Si2168_PART_INFO_RESPONSE_PBUILD_LSB         0
	#define  Si2168_PART_INFO_RESPONSE_PBUILD_MASK        0xff
	// PART_INFO command, RESERVED field definition (address 6, size 16, lsb 0, unsigned)
	#define  Si2168_PART_INFO_RESPONSE_RESERVED_LSB         0
	#define  Si2168_PART_INFO_RESPONSE_RESERVED_MASK        0xffff
	// PART_INFO command, SERIAL field definition (address 8, size 32, lsb 0, unsigned)
	#define  Si2168_PART_INFO_RESPONSE_SERIAL_LSB         0
	#define  Si2168_PART_INFO_RESPONSE_SERIAL_MASK        0xffffffff
#endif // Si2168_PART_INFO_CMD

#define Si2168_EXIT_BOOTLOADER_CMD 0x01

#ifdef Si2168_EXIT_BOOTLOADER_CMD
	#define Si2168_EXIT_BOOTLOADER_CMD_CODE 0x010001
	typedef struct
	{ // Si2168_EXIT_BOOTLOADER_CMD_struct
		unsigned char   func;
		unsigned char   ctsien;
	} Si2168_EXIT_BOOTLOADER_CMD_struct;
	typedef struct
	{ // Si2168_EXIT_BOOTLOADER_CMD_REPLY_struct
		Si2168_COMMON_REPLY_struct * STATUS;
	} Si2168_EXIT_BOOTLOADER_CMD_REPLY_struct;
	// EXIT_BOOTLOADER command, FUNC field definition (address 1,size 4, lsb 0, unsigned)
	#define  Si2168_EXIT_BOOTLOADER_CMD_FUNC_LSB         0
	#define  Si2168_EXIT_BOOTLOADER_CMD_FUNC_MASK        0x0f
	#define  Si2168_EXIT_BOOTLOADER_CMD_FUNC_MIN         0
	#define  Si2168_EXIT_BOOTLOADER_CMD_FUNC_MAX         1
	#define Si2168_EXIT_BOOTLOADER_CMD_FUNC_BOOTLOADER  0
	#define Si2168_EXIT_BOOTLOADER_CMD_FUNC_NORMAL      1
	// EXIT_BOOTLOADER command, CTSIEN field definition (address 1,size 1, lsb 7, unsigned)
	#define  Si2168_EXIT_BOOTLOADER_CMD_CTSIEN_LSB         7
	#define  Si2168_EXIT_BOOTLOADER_CMD_CTSIEN_MASK        0x01
	#define  Si2168_EXIT_BOOTLOADER_CMD_CTSIEN_MIN         0
	#define  Si2168_EXIT_BOOTLOADER_CMD_CTSIEN_MAX         1
	#define Si2168_EXIT_BOOTLOADER_CMD_CTSIEN_OFF  0
	#define Si2168_EXIT_BOOTLOADER_CMD_CTSIEN_ON   1
#endif // Si2168_EXIT_BOOTLOADER_CMD

#define Si2168_DD_MP_DEFAULTS_CMD 0x88

#ifdef Si2168_DD_MP_DEFAULTS_CMD
	#define Si2168_DD_MP_DEFAULTS_CMD_CODE 0x010088
	typedef struct
	{ // Si2168_DD_MP_DEFAULTS_CMD_struct
		unsigned char   mp_a_mode;
		unsigned char   mp_b_mode;
		unsigned char   mp_c_mode;
		unsigned char   mp_d_mode;
	} Si2168_DD_MP_DEFAULTS_CMD_struct;
	typedef struct
	{ // Si2168_DD_MP_DEFAULTS_CMD_REPLY_struct
		Si2168_COMMON_REPLY_struct * STATUS;
		unsigned char   mp_a_mode;
		unsigned char   mp_b_mode;
		unsigned char   mp_c_mode;
		unsigned char   mp_d_mode;
	} Si2168_DD_MP_DEFAULTS_CMD_REPLY_struct;
	// DD_MP_DEFAULTS command, MP_A_MODE field definition (address 1,size 7, lsb 0, unsigned)
	#define  Si2168_DD_MP_DEFAULTS_CMD_MP_A_MODE_LSB         0
	#define  Si2168_DD_MP_DEFAULTS_CMD_MP_A_MODE_MASK        0x7f
	#define  Si2168_DD_MP_DEFAULTS_CMD_MP_A_MODE_MIN         0
	#define  Si2168_DD_MP_DEFAULTS_CMD_MP_A_MODE_MAX         3
	#define Si2168_DD_MP_DEFAULTS_CMD_MP_A_MODE_DISABLE    1
	#define Si2168_DD_MP_DEFAULTS_CMD_MP_A_MODE_DRIVE_0    2
	#define Si2168_DD_MP_DEFAULTS_CMD_MP_A_MODE_DRIVE_1    3
	#define Si2168_DD_MP_DEFAULTS_CMD_MP_A_MODE_NO_CHANGE  0
	// DD_MP_DEFAULTS command, MP_B_MODE field definition (address 2,size 7, lsb 0, unsigned)
	#define  Si2168_DD_MP_DEFAULTS_CMD_MP_B_MODE_LSB         0
	#define  Si2168_DD_MP_DEFAULTS_CMD_MP_B_MODE_MASK        0x7f
	#define  Si2168_DD_MP_DEFAULTS_CMD_MP_B_MODE_MIN         0
	#define  Si2168_DD_MP_DEFAULTS_CMD_MP_B_MODE_MAX         3
	#define Si2168_DD_MP_DEFAULTS_CMD_MP_B_MODE_DISABLE    1
	#define Si2168_DD_MP_DEFAULTS_CMD_MP_B_MODE_DRIVE_0    2
	#define Si2168_DD_MP_DEFAULTS_CMD_MP_B_MODE_DRIVE_1    3
	#define Si2168_DD_MP_DEFAULTS_CMD_MP_B_MODE_NO_CHANGE  0
	// DD_MP_DEFAULTS command, MP_C_MODE field definition (address 3,size 7, lsb 0, unsigned)
	#define  Si2168_DD_MP_DEFAULTS_CMD_MP_C_MODE_LSB         0
	#define  Si2168_DD_MP_DEFAULTS_CMD_MP_C_MODE_MASK        0x7f
	#define  Si2168_DD_MP_DEFAULTS_CMD_MP_C_MODE_MIN         0
	#define  Si2168_DD_MP_DEFAULTS_CMD_MP_C_MODE_MAX         3
	#define Si2168_DD_MP_DEFAULTS_CMD_MP_C_MODE_DISABLE    1
	#define Si2168_DD_MP_DEFAULTS_CMD_MP_C_MODE_DRIVE_0    2
	#define Si2168_DD_MP_DEFAULTS_CMD_MP_C_MODE_DRIVE_1    3
	#define Si2168_DD_MP_DEFAULTS_CMD_MP_C_MODE_NO_CHANGE  0
	// DD_MP_DEFAULTS command, MP_D_MODE field definition (address 4,size 7, lsb 0, unsigned)
	#define  Si2168_DD_MP_DEFAULTS_CMD_MP_D_MODE_LSB         0
	#define  Si2168_DD_MP_DEFAULTS_CMD_MP_D_MODE_MASK        0x7f
	#define  Si2168_DD_MP_DEFAULTS_CMD_MP_D_MODE_MIN         0
	#define  Si2168_DD_MP_DEFAULTS_CMD_MP_D_MODE_MAX         3
	#define Si2168_DD_MP_DEFAULTS_CMD_MP_D_MODE_DISABLE    1
	#define Si2168_DD_MP_DEFAULTS_CMD_MP_D_MODE_DRIVE_0    2
	#define Si2168_DD_MP_DEFAULTS_CMD_MP_D_MODE_DRIVE_1    3
	#define Si2168_DD_MP_DEFAULTS_CMD_MP_D_MODE_NO_CHANGE  0
	// DD_MP_DEFAULTS command, MP_A_MODE field definition (address 1, size 7, lsb 0, unsigned)
	#define  Si2168_DD_MP_DEFAULTS_RESPONSE_MP_A_MODE_LSB         0
	#define  Si2168_DD_MP_DEFAULTS_RESPONSE_MP_A_MODE_MASK        0x7f
	#define Si2168_DD_MP_DEFAULTS_RESPONSE_MP_A_MODE_AGC_1           3
	#define Si2168_DD_MP_DEFAULTS_RESPONSE_MP_A_MODE_AGC_1_INVERTED  4
	#define Si2168_DD_MP_DEFAULTS_RESPONSE_MP_A_MODE_AGC_2           5
	#define Si2168_DD_MP_DEFAULTS_RESPONSE_MP_A_MODE_AGC_2_INVERTED  6
	#define Si2168_DD_MP_DEFAULTS_RESPONSE_MP_A_MODE_DISABLE         0
	#define Si2168_DD_MP_DEFAULTS_RESPONSE_MP_A_MODE_DRIVE_0         1
	#define Si2168_DD_MP_DEFAULTS_RESPONSE_MP_A_MODE_DRIVE_1         2
	#define Si2168_DD_MP_DEFAULTS_RESPONSE_MP_A_MODE_FEF             7
	#define Si2168_DD_MP_DEFAULTS_RESPONSE_MP_A_MODE_FEF_INVERTED    8
	// DD_MP_DEFAULTS command, MP_B_MODE field definition (address 2, size 7, lsb 0, unsigned)
	#define  Si2168_DD_MP_DEFAULTS_RESPONSE_MP_B_MODE_LSB         0
	#define  Si2168_DD_MP_DEFAULTS_RESPONSE_MP_B_MODE_MASK        0x7f
	#define Si2168_DD_MP_DEFAULTS_RESPONSE_MP_B_MODE_AGC_1           3
	#define Si2168_DD_MP_DEFAULTS_RESPONSE_MP_B_MODE_AGC_1_INVERTED  4
	#define Si2168_DD_MP_DEFAULTS_RESPONSE_MP_B_MODE_AGC_2           5
	#define Si2168_DD_MP_DEFAULTS_RESPONSE_MP_B_MODE_AGC_2_INVERTED  6
	#define Si2168_DD_MP_DEFAULTS_RESPONSE_MP_B_MODE_DISABLE         0
	#define Si2168_DD_MP_DEFAULTS_RESPONSE_MP_B_MODE_DRIVE_0         1
	#define Si2168_DD_MP_DEFAULTS_RESPONSE_MP_B_MODE_DRIVE_1         2
	#define Si2168_DD_MP_DEFAULTS_RESPONSE_MP_B_MODE_FEF             7
	#define Si2168_DD_MP_DEFAULTS_RESPONSE_MP_B_MODE_FEF_INVERTED    8
	// DD_MP_DEFAULTS command, MP_C_MODE field definition (address 3, size 7, lsb 0, unsigned)
	#define  Si2168_DD_MP_DEFAULTS_RESPONSE_MP_C_MODE_LSB         0
	#define  Si2168_DD_MP_DEFAULTS_RESPONSE_MP_C_MODE_MASK        0x7f
	#define Si2168_DD_MP_DEFAULTS_RESPONSE_MP_C_MODE_AGC_1           3
	#define Si2168_DD_MP_DEFAULTS_RESPONSE_MP_C_MODE_AGC_1_INVERTED  4
	#define Si2168_DD_MP_DEFAULTS_RESPONSE_MP_C_MODE_AGC_2           5
	#define Si2168_DD_MP_DEFAULTS_RESPONSE_MP_C_MODE_AGC_2_INVERTED  6
	#define Si2168_DD_MP_DEFAULTS_RESPONSE_MP_C_MODE_DISABLE         0
	#define Si2168_DD_MP_DEFAULTS_RESPONSE_MP_C_MODE_DRIVE_0         1
	#define Si2168_DD_MP_DEFAULTS_RESPONSE_MP_C_MODE_DRIVE_1         2
	#define Si2168_DD_MP_DEFAULTS_RESPONSE_MP_C_MODE_FEF             7
	#define Si2168_DD_MP_DEFAULTS_RESPONSE_MP_C_MODE_FEF_INVERTED    8
	// DD_MP_DEFAULTS command, MP_D_MODE field definition (address 4, size 7, lsb 0, unsigned)
	#define  Si2168_DD_MP_DEFAULTS_RESPONSE_MP_D_MODE_LSB         0
	#define  Si2168_DD_MP_DEFAULTS_RESPONSE_MP_D_MODE_MASK        0x7f
	#define Si2168_DD_MP_DEFAULTS_RESPONSE_MP_D_MODE_AGC_1           3
	#define Si2168_DD_MP_DEFAULTS_RESPONSE_MP_D_MODE_AGC_1_INVERTED  4
	#define Si2168_DD_MP_DEFAULTS_RESPONSE_MP_D_MODE_AGC_2           5
	#define Si2168_DD_MP_DEFAULTS_RESPONSE_MP_D_MODE_AGC_2_INVERTED  6
	#define Si2168_DD_MP_DEFAULTS_RESPONSE_MP_D_MODE_DISABLE         0
	#define Si2168_DD_MP_DEFAULTS_RESPONSE_MP_D_MODE_DRIVE_0         1
	#define Si2168_DD_MP_DEFAULTS_RESPONSE_MP_D_MODE_DRIVE_1         2
	#define Si2168_DD_MP_DEFAULTS_RESPONSE_MP_D_MODE_FEF             7
	#define Si2168_DD_MP_DEFAULTS_RESPONSE_MP_D_MODE_FEF_INVERTED    8
#endif // Si2168_DD_MP_DEFAULTS_CMD

#define Si2168_CONFIG_PINS_CMD 0x12

#ifdef Si2168_CONFIG_PINS_CMD
	#define Si2168_CONFIG_PINS_CMD_CODE 0x010012
	typedef struct
	{ // Si2168_CONFIG_PINS_CMD_struct
		unsigned char   gpio0_mode;
		unsigned char   gpio0_read;
		unsigned char   gpio1_mode;
		unsigned char   gpio1_read;
	} Si2168_CONFIG_PINS_CMD_struct;
	typedef struct
	{ // Si2168_CONFIG_PINS_CMD_REPLY_struct
		Si2168_COMMON_REPLY_struct * STATUS;
		unsigned char   gpio0_mode;
		unsigned char   gpio0_state;
		unsigned char   gpio1_mode;
		unsigned char   gpio1_state;
	} Si2168_CONFIG_PINS_CMD_REPLY_struct;
	// CONFIG_PINS command, GPIO0_MODE field definition (address 1,size 7, lsb 0, unsigned)
	#define  Si2168_CONFIG_PINS_CMD_GPIO0_MODE_LSB         0
	#define  Si2168_CONFIG_PINS_CMD_GPIO0_MODE_MASK        0x7f
	#define  Si2168_CONFIG_PINS_CMD_GPIO0_MODE_MIN         0
	#define  Si2168_CONFIG_PINS_CMD_GPIO0_MODE_MAX         8
	#define Si2168_CONFIG_PINS_CMD_GPIO0_MODE_DISABLE    1
	#define Si2168_CONFIG_PINS_CMD_GPIO0_MODE_DRIVE_0    2
	#define Si2168_CONFIG_PINS_CMD_GPIO0_MODE_DRIVE_1    3
	#define Si2168_CONFIG_PINS_CMD_GPIO0_MODE_HW_LOCK    8
	#define Si2168_CONFIG_PINS_CMD_GPIO0_MODE_INT_FLAG   7
	#define Si2168_CONFIG_PINS_CMD_GPIO0_MODE_NO_CHANGE  0
	#define Si2168_CONFIG_PINS_CMD_GPIO0_MODE_TS_ERR     4
	// CONFIG_PINS command, GPIO0_READ field definition (address 1,size 1, lsb 7, unsigned)
	#define  Si2168_CONFIG_PINS_CMD_GPIO0_READ_LSB         7
	#define  Si2168_CONFIG_PINS_CMD_GPIO0_READ_MASK        0x01
	#define  Si2168_CONFIG_PINS_CMD_GPIO0_READ_MIN         0
	#define  Si2168_CONFIG_PINS_CMD_GPIO0_READ_MAX         1
	#define Si2168_CONFIG_PINS_CMD_GPIO0_READ_DO_NOT_READ  0
	#define Si2168_CONFIG_PINS_CMD_GPIO0_READ_READ         1
	// CONFIG_PINS command, GPIO1_MODE field definition (address 2,size 7, lsb 0, unsigned)
	#define  Si2168_CONFIG_PINS_CMD_GPIO1_MODE_LSB         0
	#define  Si2168_CONFIG_PINS_CMD_GPIO1_MODE_MASK        0x7f
	#define  Si2168_CONFIG_PINS_CMD_GPIO1_MODE_MIN         0
	#define  Si2168_CONFIG_PINS_CMD_GPIO1_MODE_MAX         8
	#define Si2168_CONFIG_PINS_CMD_GPIO1_MODE_DISABLE    1
	#define Si2168_CONFIG_PINS_CMD_GPIO1_MODE_DRIVE_0    2
	#define Si2168_CONFIG_PINS_CMD_GPIO1_MODE_DRIVE_1    3
	#define Si2168_CONFIG_PINS_CMD_GPIO1_MODE_HW_LOCK    8
	#define Si2168_CONFIG_PINS_CMD_GPIO1_MODE_INT_FLAG   7
	#define Si2168_CONFIG_PINS_CMD_GPIO1_MODE_NO_CHANGE  0
	#define Si2168_CONFIG_PINS_CMD_GPIO1_MODE_TS_ERR     4
	// CONFIG_PINS command, GPIO1_READ field definition (address 2,size 1, lsb 7, unsigned)
	#define  Si2168_CONFIG_PINS_CMD_GPIO1_READ_LSB         7
	#define  Si2168_CONFIG_PINS_CMD_GPIO1_READ_MASK        0x01
	#define  Si2168_CONFIG_PINS_CMD_GPIO1_READ_MIN         0
	#define  Si2168_CONFIG_PINS_CMD_GPIO1_READ_MAX         1
	#define Si2168_CONFIG_PINS_CMD_GPIO1_READ_DO_NOT_READ  0
	#define Si2168_CONFIG_PINS_CMD_GPIO1_READ_READ         1
	// CONFIG_PINS command, GPIO0_MODE field definition (address 1, size 7, lsb 0, unsigned)
	#define  Si2168_CONFIG_PINS_RESPONSE_GPIO0_MODE_LSB         0
	#define  Si2168_CONFIG_PINS_RESPONSE_GPIO0_MODE_MASK        0x7f
	#define Si2168_CONFIG_PINS_RESPONSE_GPIO0_MODE_DISABLE   1
	#define Si2168_CONFIG_PINS_RESPONSE_GPIO0_MODE_DRIVE_0   2
	#define Si2168_CONFIG_PINS_RESPONSE_GPIO0_MODE_DRIVE_1   3
	#define Si2168_CONFIG_PINS_RESPONSE_GPIO0_MODE_HW_LOCK   8
	#define Si2168_CONFIG_PINS_RESPONSE_GPIO0_MODE_INT_FLAG  7
	#define Si2168_CONFIG_PINS_RESPONSE_GPIO0_MODE_TS_ERR    4
	// CONFIG_PINS command, GPIO0_STATE field definition (address 1, size 1, lsb 7, unsigned)
	#define  Si2168_CONFIG_PINS_RESPONSE_GPIO0_STATE_LSB         7
	#define  Si2168_CONFIG_PINS_RESPONSE_GPIO0_STATE_MASK        0x01
	#define Si2168_CONFIG_PINS_RESPONSE_GPIO0_STATE_READ_0  0
	#define Si2168_CONFIG_PINS_RESPONSE_GPIO0_STATE_READ_1  1
	// CONFIG_PINS command, GPIO1_MODE field definition (address 2, size 7, lsb 0, unsigned)
	#define  Si2168_CONFIG_PINS_RESPONSE_GPIO1_MODE_LSB         0
	#define  Si2168_CONFIG_PINS_RESPONSE_GPIO1_MODE_MASK        0x7f
	#define Si2168_CONFIG_PINS_RESPONSE_GPIO1_MODE_DISABLE   1
	#define Si2168_CONFIG_PINS_RESPONSE_GPIO1_MODE_DRIVE_0   2
	#define Si2168_CONFIG_PINS_RESPONSE_GPIO1_MODE_DRIVE_1   3
	#define Si2168_CONFIG_PINS_RESPONSE_GPIO1_MODE_HW_LOCK   8
	#define Si2168_CONFIG_PINS_RESPONSE_GPIO1_MODE_INT_FLAG  7
	#define Si2168_CONFIG_PINS_RESPONSE_GPIO1_MODE_TS_ERR    4
	// CONFIG_PINS command, GPIO1_STATE field definition (address 2, size 1, lsb 7, unsigned)
	#define  Si2168_CONFIG_PINS_RESPONSE_GPIO1_STATE_LSB         7
	#define  Si2168_CONFIG_PINS_RESPONSE_GPIO1_STATE_MASK        0x01
	#define Si2168_CONFIG_PINS_RESPONSE_GPIO1_STATE_READ_0  0
	#define Si2168_CONFIG_PINS_RESPONSE_GPIO1_STATE_READ_1  1
#endif // Si2168_CONFIG_PINS_CMD

#define Si2168_DD_EXT_AGC_TER_CMD 0x89

#ifdef Si2168_DD_EXT_AGC_TER_CMD
	#define Si2168_DD_EXT_AGC_TER_CMD_CODE 0x010089
	typedef struct
	{ // Si2168_DD_EXT_AGC_TER_CMD_struct
		unsigned char   agc_1_mode;
		unsigned char   agc_1_inv;
		unsigned char   agc_2_mode;
		unsigned char   agc_2_inv;
		unsigned char   agc_1_kloop;
		unsigned char   agc_2_kloop;
		unsigned char   agc_1_min;
		unsigned char   agc_2_min;
	} Si2168_DD_EXT_AGC_TER_CMD_struct;
	typedef struct
	{ // Si2168_DD_EXT_AGC_TER_CMD_REPLY_struct
		Si2168_COMMON_REPLY_struct * STATUS;
		unsigned char   agc_1_level;
		unsigned char   agc_2_level;
	} Si2168_DD_EXT_AGC_TER_CMD_REPLY_struct;
	// DD_EXT_AGC_TER command, AGC_1_MODE field definition (address 1,size 3, lsb 0, unsigned)
	#define  Si2168_DD_EXT_AGC_TER_CMD_AGC_1_MODE_LSB         0
	#define  Si2168_DD_EXT_AGC_TER_CMD_AGC_1_MODE_MASK        0x07
	#define  Si2168_DD_EXT_AGC_TER_CMD_AGC_1_MODE_MIN         0
	#define  Si2168_DD_EXT_AGC_TER_CMD_AGC_1_MODE_MAX         5
	#define Si2168_DD_EXT_AGC_TER_CMD_AGC_1_MODE_MP_A       2
	#define Si2168_DD_EXT_AGC_TER_CMD_AGC_1_MODE_MP_B       3
	#define Si2168_DD_EXT_AGC_TER_CMD_AGC_1_MODE_MP_C       4
	#define Si2168_DD_EXT_AGC_TER_CMD_AGC_1_MODE_MP_D       5
	#define Si2168_DD_EXT_AGC_TER_CMD_AGC_1_MODE_NOT_USED   1
	#define Si2168_DD_EXT_AGC_TER_CMD_AGC_1_MODE_NO_CHANGE  0
	// DD_EXT_AGC_TER command, AGC_1_INV field definition (address 1,size 1, lsb 3, unsigned)
	#define  Si2168_DD_EXT_AGC_TER_CMD_AGC_1_INV_LSB         3
	#define  Si2168_DD_EXT_AGC_TER_CMD_AGC_1_INV_MASK        0x01
	#define  Si2168_DD_EXT_AGC_TER_CMD_AGC_1_INV_MIN         0
	#define  Si2168_DD_EXT_AGC_TER_CMD_AGC_1_INV_MAX         1
	#define Si2168_DD_EXT_AGC_TER_CMD_AGC_1_INV_INVERTED      1
	#define Si2168_DD_EXT_AGC_TER_CMD_AGC_1_INV_NOT_INVERTED  0
	// DD_EXT_AGC_TER command, AGC_2_MODE field definition (address 1,size 3, lsb 4, unsigned)
	#define  Si2168_DD_EXT_AGC_TER_CMD_AGC_2_MODE_LSB         4
	#define  Si2168_DD_EXT_AGC_TER_CMD_AGC_2_MODE_MASK        0x07
	#define  Si2168_DD_EXT_AGC_TER_CMD_AGC_2_MODE_MIN         0
	#define  Si2168_DD_EXT_AGC_TER_CMD_AGC_2_MODE_MAX         5
	#define Si2168_DD_EXT_AGC_TER_CMD_AGC_2_MODE_MP_A       2
	#define Si2168_DD_EXT_AGC_TER_CMD_AGC_2_MODE_MP_B       3
	#define Si2168_DD_EXT_AGC_TER_CMD_AGC_2_MODE_MP_C       4
	#define Si2168_DD_EXT_AGC_TER_CMD_AGC_2_MODE_MP_D       5
	#define Si2168_DD_EXT_AGC_TER_CMD_AGC_2_MODE_NOT_USED   1
	#define Si2168_DD_EXT_AGC_TER_CMD_AGC_2_MODE_NO_CHANGE  0
	// DD_EXT_AGC_TER command, AGC_2_INV field definition (address 1,size 1, lsb 7, unsigned)
	#define  Si2168_DD_EXT_AGC_TER_CMD_AGC_2_INV_LSB         7
	#define  Si2168_DD_EXT_AGC_TER_CMD_AGC_2_INV_MASK        0x01
	#define  Si2168_DD_EXT_AGC_TER_CMD_AGC_2_INV_MIN         0
	#define  Si2168_DD_EXT_AGC_TER_CMD_AGC_2_INV_MAX         1
	#define Si2168_DD_EXT_AGC_TER_CMD_AGC_2_INV_INVERTED      1
	#define Si2168_DD_EXT_AGC_TER_CMD_AGC_2_INV_NOT_INVERTED  0
	// DD_EXT_AGC_TER command, AGC_1_KLOOP field definition (address 2,size 5, lsb 0, unsigned)
	#define  Si2168_DD_EXT_AGC_TER_CMD_AGC_1_KLOOP_LSB         0
	#define  Si2168_DD_EXT_AGC_TER_CMD_AGC_1_KLOOP_MASK        0x1f
	#define  Si2168_DD_EXT_AGC_TER_CMD_AGC_1_KLOOP_MIN         6
	#define  Si2168_DD_EXT_AGC_TER_CMD_AGC_1_KLOOP_MAX         20
	#define Si2168_DD_EXT_AGC_TER_CMD_AGC_1_KLOOP_AGC_1_KLOOP_MIN  6
	#define Si2168_DD_EXT_AGC_TER_CMD_AGC_1_KLOOP_AGC_1_KLOOP_MAX  20
	// DD_EXT_AGC_TER command, AGC_2_KLOOP field definition (address 3,size 5, lsb 0, unsigned)
	#define  Si2168_DD_EXT_AGC_TER_CMD_AGC_2_KLOOP_LSB         0
	#define  Si2168_DD_EXT_AGC_TER_CMD_AGC_2_KLOOP_MASK        0x1f
	#define  Si2168_DD_EXT_AGC_TER_CMD_AGC_2_KLOOP_MIN         6
	#define  Si2168_DD_EXT_AGC_TER_CMD_AGC_2_KLOOP_MAX         20
	#define Si2168_DD_EXT_AGC_TER_CMD_AGC_2_KLOOP_AGC_2_KLOOP_MIN  6
	#define Si2168_DD_EXT_AGC_TER_CMD_AGC_2_KLOOP_AGC_2_KLOOP_MAX  20
	// DD_EXT_AGC_TER command, AGC_1_MIN field definition (address 4,size 8, lsb 0, unsigned)
	#define  Si2168_DD_EXT_AGC_TER_CMD_AGC_1_MIN_LSB         0
	#define  Si2168_DD_EXT_AGC_TER_CMD_AGC_1_MIN_MASK        0xff
	#define  Si2168_DD_EXT_AGC_TER_CMD_AGC_1_MIN_MIN         0
	#define  Si2168_DD_EXT_AGC_TER_CMD_AGC_1_MIN_MAX         255
	#define Si2168_DD_EXT_AGC_TER_CMD_AGC_1_MIN_AGC_1_MIN_MIN  0
	#define Si2168_DD_EXT_AGC_TER_CMD_AGC_1_MIN_AGC_1_MIN_MAX  255
	// DD_EXT_AGC_TER command, AGC_2_MIN field definition (address 5,size 8, lsb 0, unsigned)
	#define  Si2168_DD_EXT_AGC_TER_CMD_AGC_2_MIN_LSB         0
	#define  Si2168_DD_EXT_AGC_TER_CMD_AGC_2_MIN_MASK        0xff
	#define  Si2168_DD_EXT_AGC_TER_CMD_AGC_2_MIN_MIN         0
	#define  Si2168_DD_EXT_AGC_TER_CMD_AGC_2_MIN_MAX         255
	#define Si2168_DD_EXT_AGC_TER_CMD_AGC_2_MIN_AGC_2_MIN_MIN  0
	#define Si2168_DD_EXT_AGC_TER_CMD_AGC_2_MIN_AGC_2_MIN_MAX  255
	// DD_EXT_AGC_TER command, AGC_1_LEVEL field definition (address 1, size 8, lsb 0, unsigned)
	#define  Si2168_DD_EXT_AGC_TER_RESPONSE_AGC_1_LEVEL_LSB         0
	#define  Si2168_DD_EXT_AGC_TER_RESPONSE_AGC_1_LEVEL_MASK        0xff
	// DD_EXT_AGC_TER command, AGC_2_LEVEL field definition (address 2, size 8, lsb 0, unsigned)
	#define  Si2168_DD_EXT_AGC_TER_RESPONSE_AGC_2_LEVEL_LSB         0
	#define  Si2168_DD_EXT_AGC_TER_RESPONSE_AGC_2_LEVEL_MASK        0xff
#endif // Si2168_DD_EXT_AGC_TER_CMD

#define Si2168_DVBT2_FEF_CMD 0x51

#ifdef Si2168_DVBT2_FEF_CMD
	#define Si2168_DVBT2_FEF_CMD_CODE 0x010051
	typedef struct
	{ // Si2168_DVBT2_FEF_CMD_struct
		unsigned char   fef_tuner_flag;
		unsigned char   fef_tuner_flag_inv;
	} Si2168_DVBT2_FEF_CMD_struct;
	typedef struct
	{ // Si2168_DVBT2_FEF_CMD_REPLY_struct
		Si2168_COMMON_REPLY_struct * STATUS;
		unsigned char   fef_type;
		unsigned long   fef_length;
		unsigned long   fef_repetition;
	} Si2168_DVBT2_FEF_CMD_REPLY_struct;
	// DVBT2_FEF command, FEF_TUNER_FLAG field definition (address 1,size 3, lsb 0, unsigned)
	#define  Si2168_DVBT2_FEF_CMD_FEF_TUNER_FLAG_LSB         0
	#define  Si2168_DVBT2_FEF_CMD_FEF_TUNER_FLAG_MASK        0x07
	#define  Si2168_DVBT2_FEF_CMD_FEF_TUNER_FLAG_MIN         0
	#define  Si2168_DVBT2_FEF_CMD_FEF_TUNER_FLAG_MAX         5
	#define Si2168_DVBT2_FEF_CMD_FEF_TUNER_FLAG_MP_A       2
	#define Si2168_DVBT2_FEF_CMD_FEF_TUNER_FLAG_MP_B       3
	#define Si2168_DVBT2_FEF_CMD_FEF_TUNER_FLAG_MP_C       4
	#define Si2168_DVBT2_FEF_CMD_FEF_TUNER_FLAG_MP_D       5
	#define Si2168_DVBT2_FEF_CMD_FEF_TUNER_FLAG_NOT_USED   1
	#define Si2168_DVBT2_FEF_CMD_FEF_TUNER_FLAG_NO_CHANGE  0
	// DVBT2_FEF command, FEF_TUNER_FLAG_INV field definition (address 1,size 1, lsb 3, unsigned)
	#define  Si2168_DVBT2_FEF_CMD_FEF_TUNER_FLAG_INV_LSB         3
	#define  Si2168_DVBT2_FEF_CMD_FEF_TUNER_FLAG_INV_MASK        0x01
	#define  Si2168_DVBT2_FEF_CMD_FEF_TUNER_FLAG_INV_MIN         0
	#define  Si2168_DVBT2_FEF_CMD_FEF_TUNER_FLAG_INV_MAX         1
	#define Si2168_DVBT2_FEF_CMD_FEF_TUNER_FLAG_INV_FEF_HIGH  0
	#define Si2168_DVBT2_FEF_CMD_FEF_TUNER_FLAG_INV_FEF_LOW   1
	// DVBT2_FEF command, FEF_TYPE field definition (address 1, size 4, lsb 0, unsigned)
	#define  Si2168_DVBT2_FEF_RESPONSE_FEF_TYPE_LSB         0
	#define  Si2168_DVBT2_FEF_RESPONSE_FEF_TYPE_MASK        0x0f
	// DVBT2_FEF command, FEF_LENGTH field definition (address 4, size 32, lsb 0, unsigned)
	#define  Si2168_DVBT2_FEF_RESPONSE_FEF_LENGTH_LSB         0
	#define  Si2168_DVBT2_FEF_RESPONSE_FEF_LENGTH_MASK        0xffffffff
	// DVBT2_FEF command, FEF_REPETITION field definition (address 8, size 32, lsb 0, unsigned)
	#define  Si2168_DVBT2_FEF_RESPONSE_FEF_REPETITION_LSB         0
	#define  Si2168_DVBT2_FEF_RESPONSE_FEF_REPETITION_MASK        0xffffffff
#endif // Si2168_DVBT2_FEF_CMD

#define Si2168_SET_PROPERTY_CMD 0x14

#ifdef Si2168_SET_PROPERTY_CMD
	#define Si2168_SET_PROPERTY_CMD_CODE 0x010014
	typedef struct
	{ // Si2168_SET_PROPERTY_CMD_struct
		unsigned char   reserved;
		unsigned int    prop;
		unsigned int    data;
	} Si2168_SET_PROPERTY_CMD_struct;
	typedef struct
	{ // Si2168_SET_PROPERTY_CMD_REPLY_struct
		Si2168_COMMON_REPLY_struct * STATUS;
		unsigned char   reserved;
		unsigned int    data;
	} Si2168_SET_PROPERTY_CMD_REPLY_struct;
	// SET_PROPERTY command, RESERVED field definition (address 1,size 8, lsb 0, unsigned)
	#define  Si2168_SET_PROPERTY_CMD_RESERVED_LSB         0
	#define  Si2168_SET_PROPERTY_CMD_RESERVED_MASK        0xff
	#define  Si2168_SET_PROPERTY_CMD_RESERVED_MIN         0
	#define  Si2168_SET_PROPERTY_CMD_RESERVED_MAX         255.0
	// SET_PROPERTY command, PROP field definition (address 2,size 16, lsb 0, unsigned)
	#define  Si2168_SET_PROPERTY_CMD_PROP_LSB         0
	#define  Si2168_SET_PROPERTY_CMD_PROP_MASK        0xffff
	#define  Si2168_SET_PROPERTY_CMD_PROP_MIN         0
	#define  Si2168_SET_PROPERTY_CMD_PROP_MAX         65535
	#define Si2168_SET_PROPERTY_CMD_PROP_PROP_MIN  0
	#define Si2168_SET_PROPERTY_CMD_PROP_PROP_MAX  65535
	// SET_PROPERTY command, DATA field definition (address 4,size 16, lsb 0, unsigned)
	#define  Si2168_SET_PROPERTY_CMD_DATA_LSB         0
	#define  Si2168_SET_PROPERTY_CMD_DATA_MASK        0xffff
	#define  Si2168_SET_PROPERTY_CMD_DATA_MIN         0
	#define  Si2168_SET_PROPERTY_CMD_DATA_MAX         65535
	#define Si2168_SET_PROPERTY_CMD_DATA_DATA_MIN  0
	#define Si2168_SET_PROPERTY_CMD_DATA_DATA_MAX  65535
	// SET_PROPERTY command, RESERVED field definition (address 1, size 8, lsb 0, unsigned)
	#define  Si2168_SET_PROPERTY_RESPONSE_RESERVED_LSB         0
	#define  Si2168_SET_PROPERTY_RESPONSE_RESERVED_MASK        0xff
	#define Si2168_SET_PROPERTY_RESPONSE_RESERVED_RESERVED_MIN  0
	#define Si2168_SET_PROPERTY_RESPONSE_RESERVED_RESERVED_MAX  0
	// SET_PROPERTY command, DATA field definition (address 2, size 16, lsb 0, unsigned)
	#define  Si2168_SET_PROPERTY_RESPONSE_DATA_LSB         0
	#define  Si2168_SET_PROPERTY_RESPONSE_DATA_MASK        0xffff
#endif // Si2168_SET_PROPERTY_CMD

#define Si2168_DD_RESTART_CMD 0x85

#ifdef Si2168_DD_RESTART_CMD
	#define Si2168_DD_RESTART_CMD_CODE 0x010085
	typedef struct
	{ // Si2168_DD_RESTART_CMD_struct
		unsigned char   nothing;
	} Si2168_DD_RESTART_CMD_struct;
	typedef struct
	{ // Si2168_DD_RESTART_CMD_REPLY_struct
		Si2168_COMMON_REPLY_struct * STATUS;
	} Si2168_DD_RESTART_CMD_REPLY_struct;
#endif // Si2168_DD_RESTART_CMD

#define Si2168_DVBT_STATUS_CMD 0xa0

#ifdef Si2168_DVBT_STATUS_CMD
	#define Si2168_DVBT_STATUS_CMD_CODE 0x0100a0
	typedef struct
	{ // Si2168_DVBT_STATUS_CMD_struct
		unsigned char   intack;
	} Si2168_DVBT_STATUS_CMD_struct;
	typedef struct
	{ // Si2168_DVBT_STATUS_CMD_REPLY_struct
		Si2168_COMMON_REPLY_struct * STATUS;
		unsigned char   pclint;
		unsigned char   dlint;
		unsigned char   berint;
		unsigned char   uncorint;
		unsigned char   notdvbtint;
		unsigned char   fft_mode;
		unsigned char   guard_int;
		unsigned char   hierarchy;
		         char   tps_length;
		unsigned char   pcl;
		unsigned char   dl;
		unsigned char   ber;
		unsigned char   uncor;
		unsigned char   notdvbt;
		unsigned char   cnr;
		         int    afc_freq;
		         int    timing_offset;
		unsigned char   constellation;
		unsigned char   sp_inv;
		unsigned char   rate_hp;
		unsigned char   rate_lp;
	} Si2168_DVBT_STATUS_CMD_REPLY_struct;
	// DVBT_STATUS command, INTACK field definition (address 1,size 1, lsb 0, unsigned)
	#define  Si2168_DVBT_STATUS_CMD_INTACK_LSB         0
	#define  Si2168_DVBT_STATUS_CMD_INTACK_MASK        0x01
	#define  Si2168_DVBT_STATUS_CMD_INTACK_MIN         0
	#define  Si2168_DVBT_STATUS_CMD_INTACK_MAX         1
	#define Si2168_DVBT_STATUS_CMD_INTACK_CLEAR  1
	#define Si2168_DVBT_STATUS_CMD_INTACK_OK     0
	// DVBT_STATUS command, PCLINT field definition (address 1, size 1, lsb 1, unsigned)
	#define  Si2168_DVBT_STATUS_RESPONSE_PCLINT_LSB         1
	#define  Si2168_DVBT_STATUS_RESPONSE_PCLINT_MASK        0x01
	#define Si2168_DVBT_STATUS_RESPONSE_PCLINT_CHANGED    1
	#define Si2168_DVBT_STATUS_RESPONSE_PCLINT_NO_CHANGE  0
	// DVBT_STATUS command, DLINT field definition (address 1, size 1, lsb 2, unsigned)
	#define  Si2168_DVBT_STATUS_RESPONSE_DLINT_LSB         2
	#define  Si2168_DVBT_STATUS_RESPONSE_DLINT_MASK        0x01
	#define Si2168_DVBT_STATUS_RESPONSE_DLINT_CHANGED    1
	#define Si2168_DVBT_STATUS_RESPONSE_DLINT_NO_CHANGE  0
	// DVBT_STATUS command, BERINT field definition (address 1, size 1, lsb 3, unsigned)
	#define  Si2168_DVBT_STATUS_RESPONSE_BERINT_LSB         3
	#define  Si2168_DVBT_STATUS_RESPONSE_BERINT_MASK        0x01
	#define Si2168_DVBT_STATUS_RESPONSE_BERINT_CHANGED    1
	#define Si2168_DVBT_STATUS_RESPONSE_BERINT_NO_CHANGE  0
	// DVBT_STATUS command, UNCORINT field definition (address 1, size 1, lsb 4, unsigned)
	#define  Si2168_DVBT_STATUS_RESPONSE_UNCORINT_LSB         4
	#define  Si2168_DVBT_STATUS_RESPONSE_UNCORINT_MASK        0x01
	#define Si2168_DVBT_STATUS_RESPONSE_UNCORINT_CHANGED    1
	#define Si2168_DVBT_STATUS_RESPONSE_UNCORINT_NO_CHANGE  0
	// DVBT_STATUS command, NOTDVBTINT field definition (address 1, size 1, lsb 5, unsigned)
	#define  Si2168_DVBT_STATUS_RESPONSE_NOTDVBTINT_LSB         5
	#define  Si2168_DVBT_STATUS_RESPONSE_NOTDVBTINT_MASK        0x01
	#define Si2168_DVBT_STATUS_RESPONSE_NOTDVBTINT_CHANGED    1
	#define Si2168_DVBT_STATUS_RESPONSE_NOTDVBTINT_NO_CHANGE  0
	// DVBT_STATUS command, FFT_MODE field definition (address 10, size 4, lsb 0, unsigned)
	#define  Si2168_DVBT_STATUS_RESPONSE_FFT_MODE_LSB         0
	#define  Si2168_DVBT_STATUS_RESPONSE_FFT_MODE_MASK        0x0f
	#define Si2168_DVBT_STATUS_RESPONSE_FFT_MODE_2K  11
	#define Si2168_DVBT_STATUS_RESPONSE_FFT_MODE_4K  12
	#define Si2168_DVBT_STATUS_RESPONSE_FFT_MODE_8K  13
	// DVBT_STATUS command, GUARD_INT field definition (address 10, size 3, lsb 4, unsigned)
	#define  Si2168_DVBT_STATUS_RESPONSE_GUARD_INT_LSB         4
	#define  Si2168_DVBT_STATUS_RESPONSE_GUARD_INT_MASK        0x07
	#define Si2168_DVBT_STATUS_RESPONSE_GUARD_INT_1_16  2
	#define Si2168_DVBT_STATUS_RESPONSE_GUARD_INT_1_32  1
	#define Si2168_DVBT_STATUS_RESPONSE_GUARD_INT_1_4   4
	#define Si2168_DVBT_STATUS_RESPONSE_GUARD_INT_1_8   3
	// DVBT_STATUS command, HIERARCHY field definition (address 11, size 3, lsb 0, unsigned)
	#define  Si2168_DVBT_STATUS_RESPONSE_HIERARCHY_LSB         0
	#define  Si2168_DVBT_STATUS_RESPONSE_HIERARCHY_MASK        0x07
	#define Si2168_DVBT_STATUS_RESPONSE_HIERARCHY_ALFA1  2
	#define Si2168_DVBT_STATUS_RESPONSE_HIERARCHY_ALFA2  3
	#define Si2168_DVBT_STATUS_RESPONSE_HIERARCHY_ALFA4  5
	#define Si2168_DVBT_STATUS_RESPONSE_HIERARCHY_NONE   1
	// DVBT_STATUS command, TPS_LENGTH field definition (address 12, size 7, lsb 0, signed)
	#define  Si2168_DVBT_STATUS_RESPONSE_TPS_LENGTH_LSB         0
	#define  Si2168_DVBT_STATUS_RESPONSE_TPS_LENGTH_MASK        0x7f
	#define  Si2168_DVBT_STATUS_RESPONSE_TPS_LENGTH_SHIFT       25
	// DVBT_STATUS command, PCL field definition (address 2, size 1, lsb 1, unsigned)
	#define  Si2168_DVBT_STATUS_RESPONSE_PCL_LSB         1
	#define  Si2168_DVBT_STATUS_RESPONSE_PCL_MASK        0x01
	#define Si2168_DVBT_STATUS_RESPONSE_PCL_LOCKED   1
	#define Si2168_DVBT_STATUS_RESPONSE_PCL_NO_LOCK  0
	// DVBT_STATUS command, DL field definition (address 2, size 1, lsb 2, unsigned)
	#define  Si2168_DVBT_STATUS_RESPONSE_DL_LSB         2
	#define  Si2168_DVBT_STATUS_RESPONSE_DL_MASK        0x01
	#define Si2168_DVBT_STATUS_RESPONSE_DL_LOCKED   1
	#define Si2168_DVBT_STATUS_RESPONSE_DL_NO_LOCK  0
	// DVBT_STATUS command, BER field definition (address 2, size 1, lsb 3, unsigned)
	#define  Si2168_DVBT_STATUS_RESPONSE_BER_LSB         3
	#define  Si2168_DVBT_STATUS_RESPONSE_BER_MASK        0x01
	#define Si2168_DVBT_STATUS_RESPONSE_BER_BER_ABOVE  1
	#define Si2168_DVBT_STATUS_RESPONSE_BER_BER_BELOW  0
	// DVBT_STATUS command, UNCOR field definition (address 2, size 1, lsb 4, unsigned)
	#define  Si2168_DVBT_STATUS_RESPONSE_UNCOR_LSB         4
	#define  Si2168_DVBT_STATUS_RESPONSE_UNCOR_MASK        0x01
	#define Si2168_DVBT_STATUS_RESPONSE_UNCOR_NO_UNCOR_FOUND  0
	#define Si2168_DVBT_STATUS_RESPONSE_UNCOR_UNCOR_FOUND     1
	// DVBT_STATUS command, NOTDVBT field definition (address 2, size 1, lsb 5, unsigned)
	#define  Si2168_DVBT_STATUS_RESPONSE_NOTDVBT_LSB         5
	#define  Si2168_DVBT_STATUS_RESPONSE_NOTDVBT_MASK        0x01
	#define Si2168_DVBT_STATUS_RESPONSE_NOTDVBT_DVBT      0
	#define Si2168_DVBT_STATUS_RESPONSE_NOTDVBT_NOT_DVBT  1
	// DVBT_STATUS command, CNR field definition (address 3, size 8, lsb 0, unsigned)
	#define  Si2168_DVBT_STATUS_RESPONSE_CNR_LSB         0
	#define  Si2168_DVBT_STATUS_RESPONSE_CNR_MASK        0xff
	// DVBT_STATUS command, AFC_FREQ field definition (address 4, size 16, lsb 0, signed)
	#define  Si2168_DVBT_STATUS_RESPONSE_AFC_FREQ_LSB         0
	#define  Si2168_DVBT_STATUS_RESPONSE_AFC_FREQ_MASK        0xffff
	#define  Si2168_DVBT_STATUS_RESPONSE_AFC_FREQ_SHIFT       16
	// DVBT_STATUS command, TIMING_OFFSET field definition (address 6, size 16, lsb 0, signed)
	#define  Si2168_DVBT_STATUS_RESPONSE_TIMING_OFFSET_LSB         0
	#define  Si2168_DVBT_STATUS_RESPONSE_TIMING_OFFSET_MASK        0xffff
	#define  Si2168_DVBT_STATUS_RESPONSE_TIMING_OFFSET_SHIFT       16
	// DVBT_STATUS command, CONSTELLATION field definition (address 8, size 6, lsb 0, unsigned)
	#define  Si2168_DVBT_STATUS_RESPONSE_CONSTELLATION_LSB         0
	#define  Si2168_DVBT_STATUS_RESPONSE_CONSTELLATION_MASK        0x3f
	#define Si2168_DVBT_STATUS_RESPONSE_CONSTELLATION_QAM16  7
	#define Si2168_DVBT_STATUS_RESPONSE_CONSTELLATION_QAM64  9
	#define Si2168_DVBT_STATUS_RESPONSE_CONSTELLATION_QPSK   3
	// DVBT_STATUS command, SP_INV field definition (address 8, size 1, lsb 6, unsigned)
	#define  Si2168_DVBT_STATUS_RESPONSE_SP_INV_LSB         6
	#define  Si2168_DVBT_STATUS_RESPONSE_SP_INV_MASK        0x01
	#define Si2168_DVBT_STATUS_RESPONSE_SP_INV_INVERTED  1
	#define Si2168_DVBT_STATUS_RESPONSE_SP_INV_NORMAL    0
	// DVBT_STATUS command, RATE_HP field definition (address 9, size 4, lsb 0, unsigned)
	#define  Si2168_DVBT_STATUS_RESPONSE_RATE_HP_LSB         0
	#define  Si2168_DVBT_STATUS_RESPONSE_RATE_HP_MASK        0x0f
	#define Si2168_DVBT_STATUS_RESPONSE_RATE_HP_1_2  1
	#define Si2168_DVBT_STATUS_RESPONSE_RATE_HP_2_3  2
	#define Si2168_DVBT_STATUS_RESPONSE_RATE_HP_3_4  3
	#define Si2168_DVBT_STATUS_RESPONSE_RATE_HP_5_6  5
	#define Si2168_DVBT_STATUS_RESPONSE_RATE_HP_7_8  7
	// DVBT_STATUS command, RATE_LP field definition (address 9, size 4, lsb 4, unsigned)
	#define  Si2168_DVBT_STATUS_RESPONSE_RATE_LP_LSB         4
	#define  Si2168_DVBT_STATUS_RESPONSE_RATE_LP_MASK        0x0f
	#define Si2168_DVBT_STATUS_RESPONSE_RATE_LP_1_2  1
	#define Si2168_DVBT_STATUS_RESPONSE_RATE_LP_2_3  2
	#define Si2168_DVBT_STATUS_RESPONSE_RATE_LP_3_4  3
	#define Si2168_DVBT_STATUS_RESPONSE_RATE_LP_5_6  5
	#define Si2168_DVBT_STATUS_RESPONSE_RATE_LP_7_8  7

#endif // Si2168_DVBT_STATUS_CMD

// Si2168_DVBT2_PLP_SELECT command definition
#define   Si2168_DVBT2_PLP_SELECT_CMD 0x52

#ifdef    Si2168_DVBT2_PLP_SELECT_CMD
  #define Si2168_DVBT2_PLP_SELECT_CMD_CODE 0x010052

    typedef struct { // Si2168_DVBT2_PLP_SELECT_CMD_struct
     unsigned char   plp_id;
     unsigned char   plp_id_sel_mode;
   } Si2168_DVBT2_PLP_SELECT_CMD_struct;


    typedef struct { // Si2168_DVBT2_PLP_SELECT_CMD_REPLY_struct
       Si2168_COMMON_REPLY_struct * STATUS;
   }  Si2168_DVBT2_PLP_SELECT_CMD_REPLY_struct;

   // DVBT2_PLP_SELECT command, PLP_ID field definition (address 1,size 8, lsb 0, unsigned)
   #define  Si2168_DVBT2_PLP_SELECT_CMD_PLP_ID_LSB         0
   #define  Si2168_DVBT2_PLP_SELECT_CMD_PLP_ID_MASK        0xff
   #define  Si2168_DVBT2_PLP_SELECT_CMD_PLP_ID_MIN         0
   #define  Si2168_DVBT2_PLP_SELECT_CMD_PLP_ID_MAX         255.0
   // DVBT2_PLP_SELECT command, PLP_ID_SEL_MODE field definition (address 2,size 1, lsb 0, unsigned)
   #define  Si2168_DVBT2_PLP_SELECT_CMD_PLP_ID_SEL_MODE_LSB         0
   #define  Si2168_DVBT2_PLP_SELECT_CMD_PLP_ID_SEL_MODE_MASK        0x01
   #define  Si2168_DVBT2_PLP_SELECT_CMD_PLP_ID_SEL_MODE_MIN         0
   #define  Si2168_DVBT2_PLP_SELECT_CMD_PLP_ID_SEL_MODE_MAX         1
    #define Si2168_DVBT2_PLP_SELECT_CMD_PLP_ID_SEL_MODE_AUTO    0
    #define Si2168_DVBT2_PLP_SELECT_CMD_PLP_ID_SEL_MODE_MANUAL  1
#endif // Si2168_DVBT2_PLP_SELECT_CMD

#define Si2168_DVBT2_STATUS_CMD 0x50

#ifdef Si2168_DVBT2_STATUS_CMD
	#define Si2168_DVBT2_STATUS_CMD_CODE 0x010050
	typedef struct
	{ // Si2168_DVBT2_STATUS_CMD_struct
		unsigned char   intack;
	} Si2168_DVBT2_STATUS_CMD_struct;
	typedef struct
	{ // Si2168_DVBT2_STATUS_CMD_REPLY_struct
		Si2168_COMMON_REPLY_struct * STATUS;
		unsigned char   pclint;
		unsigned char   dlint;
		unsigned char   berint;
		unsigned char   uncorint;
		unsigned char   notdvbt2int;
		unsigned char   num_plp;
		unsigned char   pilot_pattern;
		unsigned char   tx_mode;
		unsigned char   rotated;
		unsigned char   short_frame;
		unsigned char   code_rate;
		unsigned char   plp_id;
		unsigned char   pcl;
		unsigned char   dl;
		unsigned char   ber;
		unsigned char   uncor;
		unsigned char   notdvbt2;
		unsigned char   cnr;
		         int    afc_freq;
		         int    timing_offset;
		unsigned char   constellation;
		unsigned char   sp_inv;
		unsigned char   fef;
		unsigned char   fft_mode;
		unsigned char   guard_int;
		unsigned char   bw_ext;
	} Si2168_DVBT2_STATUS_CMD_REPLY_struct;
	// DVBT2_STATUS command, INTACK field definition (address 1,size 1, lsb 0, unsigned)
	#define  Si2168_DVBT2_STATUS_CMD_INTACK_LSB         0
	#define  Si2168_DVBT2_STATUS_CMD_INTACK_MASK        0x01
	#define  Si2168_DVBT2_STATUS_CMD_INTACK_MIN         0
	#define  Si2168_DVBT2_STATUS_CMD_INTACK_MAX         1
	#define Si2168_DVBT2_STATUS_CMD_INTACK_CLEAR  1
	#define Si2168_DVBT2_STATUS_CMD_INTACK_OK     0
	// DVBT2_STATUS command, PCLINT field definition (address 1, size 1, lsb 1, unsigned)
	#define  Si2168_DVBT2_STATUS_RESPONSE_PCLINT_LSB         1
	#define  Si2168_DVBT2_STATUS_RESPONSE_PCLINT_MASK        0x01
	#define Si2168_DVBT2_STATUS_RESPONSE_PCLINT_CHANGED    1
	#define Si2168_DVBT2_STATUS_RESPONSE_PCLINT_NO_CHANGE  0
	// DVBT2_STATUS command, DLINT field definition (address 1, size 1, lsb 2, unsigned)
	#define  Si2168_DVBT2_STATUS_RESPONSE_DLINT_LSB         2
	#define  Si2168_DVBT2_STATUS_RESPONSE_DLINT_MASK        0x01
	#define Si2168_DVBT2_STATUS_RESPONSE_DLINT_CHANGED    1
	#define Si2168_DVBT2_STATUS_RESPONSE_DLINT_NO_CHANGE  0
	// DVBT2_STATUS command, BERINT field definition (address 1, size 1, lsb 3, unsigned)
	#define  Si2168_DVBT2_STATUS_RESPONSE_BERINT_LSB         3
	#define  Si2168_DVBT2_STATUS_RESPONSE_BERINT_MASK        0x01
	#define Si2168_DVBT2_STATUS_RESPONSE_BERINT_CHANGED    1
	#define Si2168_DVBT2_STATUS_RESPONSE_BERINT_NO_CHANGE  0
	// DVBT2_STATUS command, UNCORINT field definition (address 1, size 1, lsb 4, unsigned)
	#define  Si2168_DVBT2_STATUS_RESPONSE_UNCORINT_LSB         4
	#define  Si2168_DVBT2_STATUS_RESPONSE_UNCORINT_MASK        0x01
	#define Si2168_DVBT2_STATUS_RESPONSE_UNCORINT_CHANGED    1
	#define Si2168_DVBT2_STATUS_RESPONSE_UNCORINT_NO_CHANGE  0
	// DVBT2_STATUS command, NOTDVBT2INT field definition (address 1, size 1, lsb 5, unsigned)
	#define  Si2168_DVBT2_STATUS_RESPONSE_NOTDVBT2INT_LSB         5
	#define  Si2168_DVBT2_STATUS_RESPONSE_NOTDVBT2INT_MASK        0x01
	#define Si2168_DVBT2_STATUS_RESPONSE_NOTDVBT2INT_CHANGED    1
	#define Si2168_DVBT2_STATUS_RESPONSE_NOTDVBT2INT_NO_CHANGE  0
	// DVBT2_STATUS command, NUM_PLP field definition (address 10, size 8, lsb 0, unsigned)
	#define  Si2168_DVBT2_STATUS_RESPONSE_NUM_PLP_LSB         0
	#define  Si2168_DVBT2_STATUS_RESPONSE_NUM_PLP_MASK        0xff
	// DVBT2_STATUS command, PILOT_PATTERN field definition (address 11, size 4, lsb 0, unsigned)
	#define  Si2168_DVBT2_STATUS_RESPONSE_PILOT_PATTERN_LSB         0
	#define  Si2168_DVBT2_STATUS_RESPONSE_PILOT_PATTERN_MASK        0x0f
	#define Si2168_DVBT2_STATUS_RESPONSE_PILOT_PATTERN_PP1  0
	#define Si2168_DVBT2_STATUS_RESPONSE_PILOT_PATTERN_PP2  1
	#define Si2168_DVBT2_STATUS_RESPONSE_PILOT_PATTERN_PP3  2
	#define Si2168_DVBT2_STATUS_RESPONSE_PILOT_PATTERN_PP4  3
	#define Si2168_DVBT2_STATUS_RESPONSE_PILOT_PATTERN_PP5  4
	#define Si2168_DVBT2_STATUS_RESPONSE_PILOT_PATTERN_PP6  5
	#define Si2168_DVBT2_STATUS_RESPONSE_PILOT_PATTERN_PP7  6
	#define Si2168_DVBT2_STATUS_RESPONSE_PILOT_PATTERN_PP8  7
	// DVBT2_STATUS command, TX_MODE field definition (address 11, size 1, lsb 4, unsigned)
	#define  Si2168_DVBT2_STATUS_RESPONSE_TX_MODE_LSB         4
	#define  Si2168_DVBT2_STATUS_RESPONSE_TX_MODE_MASK        0x01
	#define Si2168_DVBT2_STATUS_RESPONSE_TX_MODE_MISO  1
	#define Si2168_DVBT2_STATUS_RESPONSE_TX_MODE_SISO  0
	// DVBT2_STATUS command, ROTATED field definition (address 11, size 1, lsb 5, unsigned)
	#define  Si2168_DVBT2_STATUS_RESPONSE_ROTATED_LSB         5
	#define  Si2168_DVBT2_STATUS_RESPONSE_ROTATED_MASK        0x01
	#define Si2168_DVBT2_STATUS_RESPONSE_ROTATED_NORMAL   0
	#define Si2168_DVBT2_STATUS_RESPONSE_ROTATED_ROTATED  1
	// DVBT2_STATUS command, SHORT_FRAME field definition (address 11, size 1, lsb 6, unsigned)
	#define  Si2168_DVBT2_STATUS_RESPONSE_SHORT_FRAME_LSB         6
	#define  Si2168_DVBT2_STATUS_RESPONSE_SHORT_FRAME_MASK        0x01
	#define Si2168_DVBT2_STATUS_RESPONSE_SHORT_FRAME_16K_LDPC  0
	#define Si2168_DVBT2_STATUS_RESPONSE_SHORT_FRAME_64K_LDPC  1
	// DVBT2_STATUS command, CODE_RATE field definition (address 12, size 4, lsb 0, unsigned)
	#define  Si2168_DVBT2_STATUS_RESPONSE_CODE_RATE_LSB         0
	#define  Si2168_DVBT2_STATUS_RESPONSE_CODE_RATE_MASK        0x0f
	#define Si2168_DVBT2_STATUS_RESPONSE_CODE_RATE_1_2  1
	#define Si2168_DVBT2_STATUS_RESPONSE_CODE_RATE_2_3  2
	#define Si2168_DVBT2_STATUS_RESPONSE_CODE_RATE_3_4  3
	#define Si2168_DVBT2_STATUS_RESPONSE_CODE_RATE_3_5  13
	#define Si2168_DVBT2_STATUS_RESPONSE_CODE_RATE_4_5  4
	#define Si2168_DVBT2_STATUS_RESPONSE_CODE_RATE_5_6  5
	// DVBT2_STATUS command, PLP_ID field definition (address 13, size 8, lsb 0, unsigned)
	#define  Si2168_DVBT2_STATUS_RESPONSE_PLP_ID_LSB         0
	#define  Si2168_DVBT2_STATUS_RESPONSE_PLP_ID_MASK        0xff
	// DVBT2_STATUS command, PCL field definition (address 2, size 1, lsb 1, unsigned)
	#define  Si2168_DVBT2_STATUS_RESPONSE_PCL_LSB         1
	#define  Si2168_DVBT2_STATUS_RESPONSE_PCL_MASK        0x01
	#define Si2168_DVBT2_STATUS_RESPONSE_PCL_LOCKED   1
	#define Si2168_DVBT2_STATUS_RESPONSE_PCL_NO_LOCK  0
	// DVBT2_STATUS command, DL field definition (address 2, size 1, lsb 2, unsigned)
	#define  Si2168_DVBT2_STATUS_RESPONSE_DL_LSB         2
	#define  Si2168_DVBT2_STATUS_RESPONSE_DL_MASK        0x01
	#define Si2168_DVBT2_STATUS_RESPONSE_DL_LOCKED   1
	#define Si2168_DVBT2_STATUS_RESPONSE_DL_NO_LOCK  0
	// DVBT2_STATUS command, BER field definition (address 2, size 1, lsb 3, unsigned)
	#define  Si2168_DVBT2_STATUS_RESPONSE_BER_LSB         3
	#define  Si2168_DVBT2_STATUS_RESPONSE_BER_MASK        0x01
	#define Si2168_DVBT2_STATUS_RESPONSE_BER_BER_ABOVE  1
	#define Si2168_DVBT2_STATUS_RESPONSE_BER_BER_BELOW  0
	// DVBT2_STATUS command, UNCOR field definition (address 2, size 1, lsb 4, unsigned)
	#define  Si2168_DVBT2_STATUS_RESPONSE_UNCOR_LSB         4
	#define  Si2168_DVBT2_STATUS_RESPONSE_UNCOR_MASK        0x01
	#define Si2168_DVBT2_STATUS_RESPONSE_UNCOR_NO_UNCOR_FOUND  0
	#define Si2168_DVBT2_STATUS_RESPONSE_UNCOR_UNCOR_FOUND     1
	// DVBT2_STATUS command, NOTDVBT2 field definition (address 2, size 1, lsb 5, unsigned)
	#define  Si2168_DVBT2_STATUS_RESPONSE_NOTDVBT2_LSB         5
	#define  Si2168_DVBT2_STATUS_RESPONSE_NOTDVBT2_MASK        0x01
	#define Si2168_DVBT2_STATUS_RESPONSE_NOTDVBT2_DVBT2      0
	#define Si2168_DVBT2_STATUS_RESPONSE_NOTDVBT2_NOT_DVBT2  1
	// DVBT2_STATUS command, CNR field definition (address 3, size 8, lsb 0, unsigned)
	#define  Si2168_DVBT2_STATUS_RESPONSE_CNR_LSB         0
	#define  Si2168_DVBT2_STATUS_RESPONSE_CNR_MASK        0xff
	// DVBT2_STATUS command, AFC_FREQ field definition (address 4, size 16, lsb 0, signed)
	#define  Si2168_DVBT2_STATUS_RESPONSE_AFC_FREQ_LSB         0
	#define  Si2168_DVBT2_STATUS_RESPONSE_AFC_FREQ_MASK        0xffff
	#define  Si2168_DVBT2_STATUS_RESPONSE_AFC_FREQ_SHIFT       16
	// DVBT2_STATUS command, TIMING_OFFSET field definition (address 6, size 16, lsb 0, signed)
	#define  Si2168_DVBT2_STATUS_RESPONSE_TIMING_OFFSET_LSB         0
	#define  Si2168_DVBT2_STATUS_RESPONSE_TIMING_OFFSET_MASK        0xffff
	#define  Si2168_DVBT2_STATUS_RESPONSE_TIMING_OFFSET_SHIFT       16
	// DVBT2_STATUS command, CONSTELLATION field definition (address 8, size 6, lsb 0, unsigned)
	#define  Si2168_DVBT2_STATUS_RESPONSE_CONSTELLATION_LSB         0
	#define  Si2168_DVBT2_STATUS_RESPONSE_CONSTELLATION_MASK        0x3f
	#define Si2168_DVBT2_STATUS_RESPONSE_CONSTELLATION_QAM128  10
	#define Si2168_DVBT2_STATUS_RESPONSE_CONSTELLATION_QAM16   7
	#define Si2168_DVBT2_STATUS_RESPONSE_CONSTELLATION_QAM256  11
	#define Si2168_DVBT2_STATUS_RESPONSE_CONSTELLATION_QAM32   8
	#define Si2168_DVBT2_STATUS_RESPONSE_CONSTELLATION_QAM64   9
	#define Si2168_DVBT2_STATUS_RESPONSE_CONSTELLATION_QPSK    3
	// DVBT2_STATUS command, SP_INV field definition (address 8, size 1, lsb 6, unsigned)
	#define  Si2168_DVBT2_STATUS_RESPONSE_SP_INV_LSB         6
	#define  Si2168_DVBT2_STATUS_RESPONSE_SP_INV_MASK        0x01
	#define Si2168_DVBT2_STATUS_RESPONSE_SP_INV_INVERTED  1
	#define Si2168_DVBT2_STATUS_RESPONSE_SP_INV_NORMAL    0
	// DVBT2_STATUS command, FEF field definition (address 8, size 1, lsb 7, unsigned)
	#define  Si2168_DVBT2_STATUS_RESPONSE_FEF_LSB         7
	#define  Si2168_DVBT2_STATUS_RESPONSE_FEF_MASK        0x01
	#define Si2168_DVBT2_STATUS_RESPONSE_FEF_FEF     1
	#define Si2168_DVBT2_STATUS_RESPONSE_FEF_NO_FEF  0
	// DVBT2_STATUS command, FFT_MODE field definition (address 9, size 4, lsb 0, unsigned)
	#define  Si2168_DVBT2_STATUS_RESPONSE_FFT_MODE_LSB         0
	#define  Si2168_DVBT2_STATUS_RESPONSE_FFT_MODE_MASK        0x0f
	#define Si2168_DVBT2_STATUS_RESPONSE_FFT_MODE_16K  14
	#define Si2168_DVBT2_STATUS_RESPONSE_FFT_MODE_1K   10
	#define Si2168_DVBT2_STATUS_RESPONSE_FFT_MODE_2K   11
	#define Si2168_DVBT2_STATUS_RESPONSE_FFT_MODE_32K  15
	#define Si2168_DVBT2_STATUS_RESPONSE_FFT_MODE_4K   12
	#define Si2168_DVBT2_STATUS_RESPONSE_FFT_MODE_8K   13
	// DVBT2_STATUS command, GUARD_INT field definition (address 9, size 3, lsb 4, unsigned)
	#define  Si2168_DVBT2_STATUS_RESPONSE_GUARD_INT_LSB         4
	#define  Si2168_DVBT2_STATUS_RESPONSE_GUARD_INT_MASK        0x07
	#define Si2168_DVBT2_STATUS_RESPONSE_GUARD_INT_19_128  6
	#define Si2168_DVBT2_STATUS_RESPONSE_GUARD_INT_19_256  7
	#define Si2168_DVBT2_STATUS_RESPONSE_GUARD_INT_1_128   5
	#define Si2168_DVBT2_STATUS_RESPONSE_GUARD_INT_1_16    2
	#define Si2168_DVBT2_STATUS_RESPONSE_GUARD_INT_1_32    1
	#define Si2168_DVBT2_STATUS_RESPONSE_GUARD_INT_1_4     4
	#define Si2168_DVBT2_STATUS_RESPONSE_GUARD_INT_1_8     3
	// DVBT2_STATUS command, BW_EXT field definition (address 9, size 1, lsb 7, unsigned)
	#define  Si2168_DVBT2_STATUS_RESPONSE_BW_EXT_LSB         7
	#define  Si2168_DVBT2_STATUS_RESPONSE_BW_EXT_MASK        0x01
	#define Si2168_DVBT2_STATUS_RESPONSE_BW_EXT_EXTENDED  1
	#define Si2168_DVBT2_STATUS_RESPONSE_BW_EXT_NORMAL    0
#endif // Si2168_DVBT2_STATUS_CMD

/* Si2168_DD_SET_REG command definition */
#define   Si2168_DD_SET_REG_CMD 0x8e

#ifdef    Si2168_DD_SET_REG_CMD
  #define Si2168_DD_SET_REG_CMD_CODE 0x01008e

    typedef struct { /* Si2168_DD_SET_REG_CMD_struct */
     unsigned char   reg_code_lsb;
     unsigned char   reg_code_mid;
     unsigned char   reg_code_msb;
     unsigned long   value;
   } Si2168_DD_SET_REG_CMD_struct;


    typedef struct { /* Si2168_DD_SET_REG_CMD_REPLY_struct */
       Si2168_COMMON_REPLY_struct * STATUS;
   }  Si2168_DD_SET_REG_CMD_REPLY_struct;

   /* DD_SET_REG command, REG_CODE_LSB field definition (address 1,size 8, lsb 0, unsigned) */
   #define  Si2168_DD_SET_REG_CMD_REG_CODE_LSB_LSB         0
   #define  Si2168_DD_SET_REG_CMD_REG_CODE_LSB_MASK        0xff
   #define  Si2168_DD_SET_REG_CMD_REG_CODE_LSB_MIN         0
   #define  Si2168_DD_SET_REG_CMD_REG_CODE_LSB_MAX         255
    #define Si2168_DD_SET_REG_CMD_REG_CODE_LSB_REG_CODE_LSB_MIN  0
    #define Si2168_DD_SET_REG_CMD_REG_CODE_LSB_REG_CODE_LSB_MAX  255
   /* DD_SET_REG command, REG_CODE_MID field definition (address 2,size 8, lsb 0, unsigned) */
   #define  Si2168_DD_SET_REG_CMD_REG_CODE_MID_LSB         0
   #define  Si2168_DD_SET_REG_CMD_REG_CODE_MID_MASK        0xff
   #define  Si2168_DD_SET_REG_CMD_REG_CODE_MID_MIN         0
   #define  Si2168_DD_SET_REG_CMD_REG_CODE_MID_MAX         255
    #define Si2168_DD_SET_REG_CMD_REG_CODE_MID_REG_CODE_MID_MIN  0
    #define Si2168_DD_SET_REG_CMD_REG_CODE_MID_REG_CODE_MID_MAX  255
   /* DD_SET_REG command, REG_CODE_MSB field definition (address 3,size 8, lsb 0, unsigned) */
   #define  Si2168_DD_SET_REG_CMD_REG_CODE_MSB_LSB         0
   #define  Si2168_DD_SET_REG_CMD_REG_CODE_MSB_MASK        0xff
   #define  Si2168_DD_SET_REG_CMD_REG_CODE_MSB_MIN         0
   #define  Si2168_DD_SET_REG_CMD_REG_CODE_MSB_MAX         255
    #define Si2168_DD_SET_REG_CMD_REG_CODE_MSB_REG_CODE_MSB_MIN  0
    #define Si2168_DD_SET_REG_CMD_REG_CODE_MSB_REG_CODE_MSB_MAX  255
   /* DD_SET_REG command, VALUE field definition (address 4,size 32, lsb 0, unsigned) */
   #define  Si2168_DD_SET_REG_CMD_VALUE_LSB         0
   #define  Si2168_DD_SET_REG_CMD_VALUE_MASK        0xffffffff
   #define  Si2168_DD_SET_REG_CMD_VALUE_MIN         0
   #define  Si2168_DD_SET_REG_CMD_VALUE_MAX         4294967295
    #define Si2168_DD_SET_REG_CMD_VALUE_VALUE_MIN  0
    #define Si2168_DD_SET_REG_CMD_VALUE_VALUE_MAX  4294967295
#endif /* Si2168_DD_SET_REG_CMD */

/* Si2168_DD_SSI_SQI command definition */
#define   Si2168_DD_SSI_SQI_CMD 0x8b

// Si2168_DD_SSI_SQI command definition
#define   Si2168_DD_SSI_SQI_CMD 0x8b

#ifdef Si2168_DD_SSI_SQI_CMD
	#define Si2168_DD_SSI_SQI_CMD_CODE 0x01008b
	typedef struct
	{ // Si2168_DD_SSI_SQI_CMD_struct
		char   tuner_rssi;
	} Si2168_DD_SSI_SQI_CMD_struct;
	typedef struct
	{ // Si2168_DD_SSI_SQI_CMD_REPLY_struct
		Si2168_COMMON_REPLY_struct * STATUS;
		unsigned char ssi;
		char   sqi;
	} Si2168_DD_SSI_SQI_CMD_REPLY_struct;
	// DD_SSI_SQI command, TUNER_RSSI field definition (address 1,size 8, lsb 0, unsigned signed)
	#define  Si2168_DD_SSI_SQI_CMD_TUNER_RSSI_LSB         0
	#define  Si2168_DD_SSI_SQI_CMD_TUNER_RSSI_MASK        0xff
	#define  Si2168_DD_SSI_SQI_CMD_TUNER_RSSI_SHIFT       24
	#define  Si2168_DD_SSI_SQI_CMD_TUNER_RSSI_MIN         -128.0
	#define  Si2168_DD_SSI_SQI_CMD_TUNER_RSSI_MAX         127.0
	// DD_SSI_SQI command, SSI field definition (address 1, size 8, lsb 0, signed)
	#define  Si2168_DD_SSI_SQI_RESPONSE_SSI_LSB         0
	#define  Si2168_DD_SSI_SQI_RESPONSE_SSI_MASK        0xff
	#define Si2168_DD_SSI_SQI_RESPONSE_SSI_SSI_MIN  0
	#define Si2168_DD_SSI_SQI_RESPONSE_SSI_SSI_MAX  100
	// DD_SSI_SQI command, SQI field definition (address 2, size 8, lsb 0, signed)
	#define  Si2168_DD_SSI_SQI_RESPONSE_SQI_LSB         0
	#define  Si2168_DD_SSI_SQI_RESPONSE_SQI_MASK        0xff
	#define  Si2168_DD_SSI_SQI_RESPONSE_SQI_SHIFT       24
	#define Si2168_DD_SSI_SQI_RESPONSE_SQI_SQI_MIN  -1
	#define Si2168_DD_SSI_SQI_RESPONSE_SQI_SQI_MAX  100

#endif // Si2168_DD_SSI_SQI_CMD

#define Si2168_DD_STATUS_CMD 0x87

#ifdef Si2168_DD_STATUS_CMD
	#define Si2168_DD_STATUS_CMD_CODE 0x010087
	typedef struct
	{ // Si2168_DD_STATUS_CMD_struct
		unsigned char   intack;
	} Si2168_DD_STATUS_CMD_struct;
	typedef struct
	{ // Si2168_DD_STATUS_CMD_REPLY_struct
		Si2168_COMMON_REPLY_struct * STATUS;
		unsigned char   pclint;
		unsigned char   dlint;
		unsigned char   berint;
		unsigned char   uncorint;
		unsigned char   rsqint_bit5;
		unsigned char   rsqint_bit6;
		unsigned char   rsqint_bit7;
		unsigned char   pcl;
		unsigned char   dl;
		unsigned char   ber;
		unsigned char   uncor;
		unsigned char   rsqstat_bit5;
		unsigned char   rsqstat_bit6;
		unsigned char   rsqstat_bit7;
		unsigned char   modulation;
		unsigned int    ts_bit_rate;
		unsigned int    ts_clk_freq;
	} Si2168_DD_STATUS_CMD_REPLY_struct;
	// DD_STATUS command, INTACK field definition (address 1,size 1, lsb 0, unsigned)
	#define  Si2168_DD_STATUS_CMD_INTACK_LSB         0
	#define  Si2168_DD_STATUS_CMD_INTACK_MASK        0x01
	#define  Si2168_DD_STATUS_CMD_INTACK_MIN         0
	#define  Si2168_DD_STATUS_CMD_INTACK_MAX         1
	#define Si2168_DD_STATUS_CMD_INTACK_CLEAR  1
	#define Si2168_DD_STATUS_CMD_INTACK_OK     0
	// DD_STATUS command, PCLINT field definition (address 1, size 1, lsb 1, unsigned)
	#define  Si2168_DD_STATUS_RESPONSE_PCLINT_LSB         1
	#define  Si2168_DD_STATUS_RESPONSE_PCLINT_MASK        0x01
	#define Si2168_DD_STATUS_RESPONSE_PCLINT_CHANGED    1
	#define Si2168_DD_STATUS_RESPONSE_PCLINT_NO_CHANGE  0
	// DD_STATUS command, DLINT field definition (address 1, size 1, lsb 2, unsigned)
	#define  Si2168_DD_STATUS_RESPONSE_DLINT_LSB         2
	#define  Si2168_DD_STATUS_RESPONSE_DLINT_MASK        0x01
	#define Si2168_DD_STATUS_RESPONSE_DLINT_CHANGED    1
	#define Si2168_DD_STATUS_RESPONSE_DLINT_NO_CHANGE  0
	// DD_STATUS command, BERINT field definition (address 1, size 1, lsb 3, unsigned)
	#define  Si2168_DD_STATUS_RESPONSE_BERINT_LSB         3
	#define  Si2168_DD_STATUS_RESPONSE_BERINT_MASK        0x01
	#define Si2168_DD_STATUS_RESPONSE_BERINT_CHANGED    1
	#define Si2168_DD_STATUS_RESPONSE_BERINT_NO_CHANGE  0
	// DD_STATUS command, UNCORINT field definition (address 1, size 1, lsb 4, unsigned)
	#define  Si2168_DD_STATUS_RESPONSE_UNCORINT_LSB         4
	#define  Si2168_DD_STATUS_RESPONSE_UNCORINT_MASK        0x01
	#define Si2168_DD_STATUS_RESPONSE_UNCORINT_CHANGED    1
	#define Si2168_DD_STATUS_RESPONSE_UNCORINT_NO_CHANGE  0
	// DD_STATUS command, RSQINT_BIT5 field definition (address 1, size 1, lsb 5, unsigned)
	#define  Si2168_DD_STATUS_RESPONSE_RSQINT_BIT5_LSB         5
	#define  Si2168_DD_STATUS_RESPONSE_RSQINT_BIT5_MASK        0x01
	#define Si2168_DD_STATUS_RESPONSE_RSQINT_BIT5_CHANGED    1
	#define Si2168_DD_STATUS_RESPONSE_RSQINT_BIT5_NO_CHANGE  0
	// DD_STATUS command, RSQINT_BIT6 field definition (address 1, size 1, lsb 6, unsigned)
	#define  Si2168_DD_STATUS_RESPONSE_RSQINT_BIT6_LSB         6
	#define  Si2168_DD_STATUS_RESPONSE_RSQINT_BIT6_MASK        0x01
	#define Si2168_DD_STATUS_RESPONSE_RSQINT_BIT6_CHANGED    1
	#define Si2168_DD_STATUS_RESPONSE_RSQINT_BIT6_NO_CHANGE  0
	// DD_STATUS command, RSQINT_BIT7 field definition (address 1, size 1, lsb 7, unsigned)
	#define  Si2168_DD_STATUS_RESPONSE_RSQINT_BIT7_LSB         7
	#define  Si2168_DD_STATUS_RESPONSE_RSQINT_BIT7_MASK        0x01
	#define Si2168_DD_STATUS_RESPONSE_RSQINT_BIT7_CHANGED    1
	#define Si2168_DD_STATUS_RESPONSE_RSQINT_BIT7_NO_CHANGE  0
	// DD_STATUS command, PCL field definition (address 2, size 1, lsb 1, unsigned)
	#define  Si2168_DD_STATUS_RESPONSE_PCL_LSB         1
	#define  Si2168_DD_STATUS_RESPONSE_PCL_MASK        0x01
	#define Si2168_DD_STATUS_RESPONSE_PCL_LOCKED   1
	#define Si2168_DD_STATUS_RESPONSE_PCL_NO_LOCK  0
	// DD_STATUS command, DL field definition (address 2, size 1, lsb 2, unsigned)
	#define  Si2168_DD_STATUS_RESPONSE_DL_LSB         2
	#define  Si2168_DD_STATUS_RESPONSE_DL_MASK        0x01
	#define Si2168_DD_STATUS_RESPONSE_DL_LOCKED   1
	#define Si2168_DD_STATUS_RESPONSE_DL_NO_LOCK  0
	// DD_STATUS command, BER field definition (address 2, size 1, lsb 3, unsigned)
	#define  Si2168_DD_STATUS_RESPONSE_BER_LSB         3
	#define  Si2168_DD_STATUS_RESPONSE_BER_MASK        0x01
	#define Si2168_DD_STATUS_RESPONSE_BER_BER_ABOVE  1
	#define Si2168_DD_STATUS_RESPONSE_BER_BER_BELOW  0
	// DD_STATUS command, UNCOR field definition (address 2, size 1, lsb 4, unsigned)
	#define  Si2168_DD_STATUS_RESPONSE_UNCOR_LSB         4
	#define  Si2168_DD_STATUS_RESPONSE_UNCOR_MASK        0x01
	#define Si2168_DD_STATUS_RESPONSE_UNCOR_NO_UNCOR_FOUND  0
	#define Si2168_DD_STATUS_RESPONSE_UNCOR_UNCOR_FOUND     1
	// DD_STATUS command, RSQSTAT_BIT5 field definition (address 2, size 1, lsb 5, unsigned)
	#define  Si2168_DD_STATUS_RESPONSE_RSQSTAT_BIT5_LSB         5
	#define  Si2168_DD_STATUS_RESPONSE_RSQSTAT_BIT5_MASK        0x01
	// DD_STATUS command, RSQSTAT_BIT6 field definition (address 2, size 1, lsb 6, unsigned)
	#define  Si2168_DD_STATUS_RESPONSE_RSQSTAT_BIT6_LSB         6
	#define  Si2168_DD_STATUS_RESPONSE_RSQSTAT_BIT6_MASK        0x01
	// DD_STATUS command, RSQSTAT_BIT7 field definition (address 2, size 1, lsb 7, unsigned)
	#define  Si2168_DD_STATUS_RESPONSE_RSQSTAT_BIT7_LSB         7
	#define  Si2168_DD_STATUS_RESPONSE_RSQSTAT_BIT7_MASK        0x01
	// DD_STATUS command, MODULATION field definition (address 3, size 4, lsb 0, unsigned)
	#define  Si2168_DD_STATUS_RESPONSE_MODULATION_LSB         0
	#define  Si2168_DD_STATUS_RESPONSE_MODULATION_MASK        0x0f
	#define Si2168_DD_STATUS_RESPONSE_MODULATION_DSS     10
    #define Si2168_DD_STATUS_RESPONSE_MODULATION_DVBC    3
    #define Si2168_DD_STATUS_RESPONSE_MODULATION_DVBS    8
    #define Si2168_DD_STATUS_RESPONSE_MODULATION_DVBS2   9
    #define Si2168_DD_STATUS_RESPONSE_MODULATION_DVBT    2
    #define Si2168_DD_STATUS_RESPONSE_MODULATION_DVBT2   7
	// DD_STATUS command, TS_BIT_RATE field definition (address 4, size 16, lsb 0, unsigned)
	#define  Si2168_DD_STATUS_RESPONSE_TS_BIT_RATE_LSB         0
	#define  Si2168_DD_STATUS_RESPONSE_TS_BIT_RATE_MASK        0xffff
	// DD_STATUS command, TS_CLK_FREQ field definition (address 6, size 16, lsb 0, unsigned)
	#define  Si2168_DD_STATUS_RESPONSE_TS_CLK_FREQ_LSB         0
	#define  Si2168_DD_STATUS_RESPONSE_TS_CLK_FREQ_MASK        0xffff
#endif // Si2168_DD_STATUS_CMD

/* Si2168_DVBT_TPS_EXTRA command definition */
#define   Si2168_DVBT_TPS_EXTRA_CMD 0xa1

#ifdef    Si2168_DVBT_TPS_EXTRA_CMD
  #define Si2168_DVBT_TPS_EXTRA_CMD_CODE 0x0100a1

    typedef struct { /* Si2168_DVBT_TPS_EXTRA_CMD_struct */
         unsigned char   nothing;   } Si2168_DVBT_TPS_EXTRA_CMD_struct;


    typedef struct { /* Si2168_DVBT_TPS_EXTRA_CMD_REPLY_struct */
       Si2168_COMMON_REPLY_struct * STATUS;
      unsigned char   lptimeslice;
      unsigned char   hptimeslice;
      unsigned char   lpmpefec;
      unsigned char   hpmpefec;
      unsigned char   dvbhinter;
               int    cell_id;
      unsigned char   tps_res1;
      unsigned char   tps_res2;
      unsigned char   tps_res3;
      unsigned char   tps_res4;
   }  Si2168_DVBT_TPS_EXTRA_CMD_REPLY_struct;

   /* DVBT_TPS_EXTRA command, LPTIMESLICE field definition (address 1, size 1, lsb 0, unsigned)*/
   #define  Si2168_DVBT_TPS_EXTRA_RESPONSE_LPTIMESLICE_LSB         0
   #define  Si2168_DVBT_TPS_EXTRA_RESPONSE_LPTIMESLICE_MASK        0x01
    #define Si2168_DVBT_TPS_EXTRA_RESPONSE_LPTIMESLICE_OFF  0
    #define Si2168_DVBT_TPS_EXTRA_RESPONSE_LPTIMESLICE_ON   1
   /* DVBT_TPS_EXTRA command, HPTIMESLICE field definition (address 1, size 1, lsb 1, unsigned)*/
   #define  Si2168_DVBT_TPS_EXTRA_RESPONSE_HPTIMESLICE_LSB         1
   #define  Si2168_DVBT_TPS_EXTRA_RESPONSE_HPTIMESLICE_MASK        0x01
    #define Si2168_DVBT_TPS_EXTRA_RESPONSE_HPTIMESLICE_OFF  0
    #define Si2168_DVBT_TPS_EXTRA_RESPONSE_HPTIMESLICE_ON   1
   /* DVBT_TPS_EXTRA command, LPMPEFEC field definition (address 1, size 1, lsb 2, unsigned)*/
   #define  Si2168_DVBT_TPS_EXTRA_RESPONSE_LPMPEFEC_LSB         2
   #define  Si2168_DVBT_TPS_EXTRA_RESPONSE_LPMPEFEC_MASK        0x01
    #define Si2168_DVBT_TPS_EXTRA_RESPONSE_LPMPEFEC_OFF  0
    #define Si2168_DVBT_TPS_EXTRA_RESPONSE_LPMPEFEC_ON   1
   /* DVBT_TPS_EXTRA command, HPMPEFEC field definition (address 1, size 1, lsb 3, unsigned)*/
   #define  Si2168_DVBT_TPS_EXTRA_RESPONSE_HPMPEFEC_LSB         3
   #define  Si2168_DVBT_TPS_EXTRA_RESPONSE_HPMPEFEC_MASK        0x01
    #define Si2168_DVBT_TPS_EXTRA_RESPONSE_HPMPEFEC_OFF  0
    #define Si2168_DVBT_TPS_EXTRA_RESPONSE_HPMPEFEC_ON   1
   /* DVBT_TPS_EXTRA command, DVBHINTER field definition (address 1, size 1, lsb 4, unsigned)*/
   #define  Si2168_DVBT_TPS_EXTRA_RESPONSE_DVBHINTER_LSB         4
   #define  Si2168_DVBT_TPS_EXTRA_RESPONSE_DVBHINTER_MASK        0x01
    #define Si2168_DVBT_TPS_EXTRA_RESPONSE_DVBHINTER_IN_DEPTH  1
    #define Si2168_DVBT_TPS_EXTRA_RESPONSE_DVBHINTER_NATIVE    0
   /* DVBT_TPS_EXTRA command, CELL_ID field definition (address 2, size 16, lsb 0, signed)*/
   #define  Si2168_DVBT_TPS_EXTRA_RESPONSE_CELL_ID_LSB         0
   #define  Si2168_DVBT_TPS_EXTRA_RESPONSE_CELL_ID_MASK        0xffff
   #define  Si2168_DVBT_TPS_EXTRA_RESPONSE_CELL_ID_SHIFT       16
   /* DVBT_TPS_EXTRA command, TPS_RES1 field definition (address 4, size 4, lsb 0, unsigned)*/
   #define  Si2168_DVBT_TPS_EXTRA_RESPONSE_TPS_RES1_LSB         0
   #define  Si2168_DVBT_TPS_EXTRA_RESPONSE_TPS_RES1_MASK        0x0f
   /* DVBT_TPS_EXTRA command, TPS_RES2 field definition (address 4, size 4, lsb 4, unsigned)*/
   #define  Si2168_DVBT_TPS_EXTRA_RESPONSE_TPS_RES2_LSB         4
   #define  Si2168_DVBT_TPS_EXTRA_RESPONSE_TPS_RES2_MASK        0x0f
   /* DVBT_TPS_EXTRA command, TPS_RES3 field definition (address 5, size 4, lsb 0, unsigned)*/
   #define  Si2168_DVBT_TPS_EXTRA_RESPONSE_TPS_RES3_LSB         0
   #define  Si2168_DVBT_TPS_EXTRA_RESPONSE_TPS_RES3_MASK        0x0f
   /* DVBT_TPS_EXTRA command, TPS_RES4 field definition (address 5, size 4, lsb 4, unsigned)*/
   #define  Si2168_DVBT_TPS_EXTRA_RESPONSE_TPS_RES4_LSB         4
   #define  Si2168_DVBT_TPS_EXTRA_RESPONSE_TPS_RES4_MASK        0x0f

#endif /* Si2168_DVBT_TPS_EXTRA_CMD */

#define Si2168_I2C_PASSTHROUGH_CMD 0xc0

#ifdef Si2168_I2C_PASSTHROUGH_CMD
	#define Si2168_I2C_PASSTHROUGH_CMD_CODE 0x0100c0
	typedef struct
	{ // Si2168_I2C_PASSTHROUGH_CMD_struct
		unsigned char   subcode;
		unsigned char   i2c_passthru;
		unsigned char   reserved;
	} Si2168_I2C_PASSTHROUGH_CMD_struct;
	typedef struct
	{ // Si2168_I2C_PASSTHROUGH_CMD_REPLY_struct
		Si2168_COMMON_REPLY_struct * STATUS;
	} Si2168_I2C_PASSTHROUGH_CMD_REPLY_struct;
	// I2C_PASSTHROUGH command, SUBCODE field definition (address 1,size 8, lsb 0, unsigned)
	#define  Si2168_I2C_PASSTHROUGH_CMD_SUBCODE_LSB         0
	#define  Si2168_I2C_PASSTHROUGH_CMD_SUBCODE_MASK        0xff
	#define  Si2168_I2C_PASSTHROUGH_CMD_SUBCODE_MIN         13
	#define  Si2168_I2C_PASSTHROUGH_CMD_SUBCODE_MAX         13
	#define Si2168_I2C_PASSTHROUGH_CMD_SUBCODE_CODE  13
	// I2C_PASSTHROUGH command, I2C_PASSTHRU field definition (address 2,size 1, lsb 0, unsigned)
	#define  Si2168_I2C_PASSTHROUGH_CMD_I2C_PASSTHRU_LSB         0
	#define  Si2168_I2C_PASSTHROUGH_CMD_I2C_PASSTHRU_MASK        0x01
	#define  Si2168_I2C_PASSTHROUGH_CMD_I2C_PASSTHRU_MIN         0
	#define  Si2168_I2C_PASSTHROUGH_CMD_I2C_PASSTHRU_MAX         1
	#define Si2168_I2C_PASSTHROUGH_CMD_I2C_PASSTHRU_CLOSE  1
	#define Si2168_I2C_PASSTHROUGH_CMD_I2C_PASSTHRU_OPEN   0
	// I2C_PASSTHROUGH command, RESERVED field definition (address 2,size 7, lsb 1, unsigned)
	#define  Si2168_I2C_PASSTHROUGH_CMD_RESERVED_LSB         1
	#define  Si2168_I2C_PASSTHROUGH_CMD_RESERVED_MASK        0x7f
	#define  Si2168_I2C_PASSTHROUGH_CMD_RESERVED_MIN         0
	#define  Si2168_I2C_PASSTHROUGH_CMD_RESERVED_MAX         0
	#define Si2168_I2C_PASSTHROUGH_CMD_RESERVED_RESERVED  0
#endif // Si2168_I2C_PASSTHROUGH_CMD

typedef struct
{ // Si2168_CmdObj struct
	#ifdef    Si2168_CONFIG_CLKIO_CMD
			  Si2168_CONFIG_CLKIO_CMD_struct               config_clkio;
	#endif /* Si2168_CONFIG_CLKIO_CMD */
	#ifdef    Si2168_CONFIG_PINS_CMD
			  Si2168_CONFIG_PINS_CMD_struct                config_pins;
	#endif /* Si2168_CONFIG_PINS_CMD */
	#ifdef    Si2168_DD_BER_CMD
			  Si2168_DD_BER_CMD_struct                     dd_ber;
	#endif /* Si2168_DD_BER_CMD */
	#ifdef    Si2168_DD_CBER_CMD
			  Si2168_DD_CBER_CMD_struct                    dd_cber;
	#endif /* Si2168_DD_CBER_CMD */

	#ifdef    Si2168_DD_EXT_AGC_TER_CMD
			  Si2168_DD_EXT_AGC_TER_CMD_struct             dd_ext_agc_ter;
	#endif /* Si2168_DD_EXT_AGC_TER_CMD */

	#ifdef    Si2168_DD_FER_CMD
			  Si2168_DD_FER_CMD_struct                     dd_fer;
	#endif /* Si2168_DD_FER_CMD */
	#ifdef    Si2168_DD_GET_REG_CMD
			  Si2168_DD_GET_REG_CMD_struct                 dd_get_reg;
	#endif /* Si2168_DD_GET_REG_CMD */
	#ifdef    Si2168_DD_MP_DEFAULTS_CMD
			  Si2168_DD_MP_DEFAULTS_CMD_struct             dd_mp_defaults;
	#endif /* Si2168_DD_MP_DEFAULTS_CMD */
	#ifdef    Si2168_DD_PER_CMD
			  Si2168_DD_PER_CMD_struct                     dd_per;
	#endif /* Si2168_DD_PER_CMD */
	#ifdef    Si2168_DD_RESTART_CMD
			  Si2168_DD_RESTART_CMD_struct                 dd_restart;
	#endif /* Si2168_DD_RESTART_CMD */
	#ifdef    Si2168_DD_SET_REG_CMD
			  Si2168_DD_SET_REG_CMD_struct                 dd_set_reg;
	#endif /* Si2168_DD_SET_REG_CMD */
	#ifdef    Si2168_DD_SSI_SQI_CMD
			  Si2168_DD_SSI_SQI_CMD_struct                 dd_ssi_sqi;
	#endif /* Si2168_DD_SSI_SQI_CMD */
	#ifdef    Si2168_DD_STATUS_CMD
			  Si2168_DD_STATUS_CMD_struct                  dd_status;
	#endif /* Si2168_DD_STATUS_CMD */
	#ifdef    Si2168_DD_UNCOR_CMD
			  Si2168_DD_UNCOR_CMD_struct                   dd_uncor;
	#endif /* Si2168_DD_UNCOR_CMD */
	#ifdef    Si2168_DOWNLOAD_DATASET_CONTINUE_CMD
			  Si2168_DOWNLOAD_DATASET_CONTINUE_CMD_struct  download_dataset_continue;
	#endif /* Si2168_DOWNLOAD_DATASET_CONTINUE_CMD */
	#ifdef    Si2168_DOWNLOAD_DATASET_START_CMD
			  Si2168_DOWNLOAD_DATASET_START_CMD_struct     download_dataset_start;
	#endif /* Si2168_DOWNLOAD_DATASET_START_CMD */
	#ifdef    Si2168_DVBC_STATUS_CMD
			  Si2168_DVBC_STATUS_CMD_struct                dvbc_status;
	#endif /* Si2168_DVBC_STATUS_CMD */

	#ifdef    Si2168_DVBT2_FEF_CMD
			  Si2168_DVBT2_FEF_CMD_struct                  dvbt2_fef;
	#endif /* Si2168_DVBT2_FEF_CMD */
	#ifdef    Si2168_DVBT2_PLP_INFO_CMD
			  Si2168_DVBT2_PLP_INFO_CMD_struct             dvbt2_plp_info;
	#endif /* Si2168_DVBT2_PLP_INFO_CMD */
	#ifdef    Si2168_DVBT2_PLP_SELECT_CMD
			  Si2168_DVBT2_PLP_SELECT_CMD_struct           dvbt2_plp_select;
	#endif /* Si2168_DVBT2_PLP_SELECT_CMD */
	#ifdef    Si2168_DVBT2_STATUS_CMD
			  Si2168_DVBT2_STATUS_CMD_struct               dvbt2_status;
	#endif /* Si2168_DVBT2_STATUS_CMD */
	#ifdef    Si2168_DVBT2_TX_ID_CMD
			  Si2168_DVBT2_TX_ID_CMD_struct                dvbt2_tx_id;
	#endif /* Si2168_DVBT2_TX_ID_CMD */

	#ifdef    Si2168_DVBT_STATUS_CMD
			  Si2168_DVBT_STATUS_CMD_struct                dvbt_status;
	#endif /* Si2168_DVBT_STATUS_CMD */
	#ifdef    Si2168_DVBT_TPS_EXTRA_CMD
			  Si2168_DVBT_TPS_EXTRA_CMD_struct             dvbt_tps_extra;
	#endif /* Si2168_DVBT_TPS_EXTRA_CMD */

	#ifdef    Si2168_EXIT_BOOTLOADER_CMD
			  Si2168_EXIT_BOOTLOADER_CMD_struct            exit_bootloader;
	#endif /* Si2168_EXIT_BOOTLOADER_CMD */
	#ifdef    Si2168_GET_PROPERTY_CMD
			  Si2168_GET_PROPERTY_CMD_struct               get_property;
	#endif /* Si2168_GET_PROPERTY_CMD */
	#ifdef    Si2168_GET_REV_CMD
			  Si2168_GET_REV_CMD_struct                    get_rev;
	#endif /* Si2168_GET_REV_CMD */
	#ifdef    Si2168_I2C_PASSTHROUGH_CMD
			  Si2168_I2C_PASSTHROUGH_CMD_struct            i2c_passthrough;
	#endif /* Si2168_I2C_PASSTHROUGH_CMD */
	#ifdef    Si2168_PART_INFO_CMD
			  Si2168_PART_INFO_CMD_struct                  part_info;
	#endif /* Si2168_PART_INFO_CMD */
	#ifdef    Si2168_POWER_DOWN_CMD
			  Si2168_POWER_DOWN_CMD_struct                 power_down;
	#endif /* Si2168_POWER_DOWN_CMD */
	#ifdef    Si2168_POWER_UP_CMD
			  Si2168_POWER_UP_CMD_struct                   power_up;
	#endif /* Si2168_POWER_UP_CMD */
	#ifdef    Si2168_RSSI_ADC_CMD
			  Si2168_RSSI_ADC_CMD_struct                   rssi_adc;
	#endif /* Si2168_RSSI_ADC_CMD */
	#ifdef    Si2168_SCAN_CTRL_CMD
			  Si2168_SCAN_CTRL_CMD_struct                  scan_ctrl;
	#endif /* Si2168_SCAN_CTRL_CMD */
	#ifdef    Si2168_SCAN_STATUS_CMD
			  Si2168_SCAN_STATUS_CMD_struct                scan_status;
	#endif /* Si2168_SCAN_STATUS_CMD */
	#ifdef    Si2168_SET_PROPERTY_CMD
			  Si2168_SET_PROPERTY_CMD_struct               set_property;
	#endif /* Si2168_SET_PROPERTY_CMD */
	#ifdef    Si2168_START_CLK_CMD
			  Si2168_START_CLK_CMD_struct                  start_clk;
	#endif /* Si2168_START_CLK_CMD */
} Si2168_CmdObj;

typedef struct
{ // Si2168_CmdReplyObj struct
	#ifdef    Si2168_CONFIG_CLKIO_CMD
			  Si2168_CONFIG_CLKIO_CMD_REPLY_struct               config_clkio;
	#endif /* Si2168_CONFIG_CLKIO_CMD */
	#ifdef    Si2168_CONFIG_PINS_CMD
			  Si2168_CONFIG_PINS_CMD_REPLY_struct                config_pins;
	#endif /* Si2168_CONFIG_PINS_CMD */
	#ifdef    Si2168_DD_BER_CMD
			  Si2168_DD_BER_CMD_REPLY_struct                     dd_ber;
	#endif /* Si2168_DD_BER_CMD */
	#ifdef    Si2168_DD_CBER_CMD
			  Si2168_DD_CBER_CMD_REPLY_struct                    dd_cber;
	#endif /* Si2168_DD_CBER_CMD */

	#ifdef    Si2168_DD_EXT_AGC_TER_CMD
			  Si2168_DD_EXT_AGC_TER_CMD_REPLY_struct             dd_ext_agc_ter;
	#endif /* Si2168_DD_EXT_AGC_TER_CMD */

	#ifdef    Si2168_DD_FER_CMD
			  Si2168_DD_FER_CMD_REPLY_struct                     dd_fer;
	#endif /* Si2168_DD_FER_CMD */
	#ifdef    Si2168_DD_GET_REG_CMD
			  Si2168_DD_GET_REG_CMD_REPLY_struct                 dd_get_reg;
	#endif /* Si2168_DD_GET_REG_CMD */
	#ifdef    Si2168_DD_MP_DEFAULTS_CMD
			  Si2168_DD_MP_DEFAULTS_CMD_REPLY_struct             dd_mp_defaults;
	#endif /* Si2168_DD_MP_DEFAULTS_CMD */
	#ifdef    Si2168_DD_PER_CMD
			  Si2168_DD_PER_CMD_REPLY_struct                     dd_per;
	#endif /* Si2168_DD_PER_CMD */
	#ifdef    Si2168_DD_RESTART_CMD
			  Si2168_DD_RESTART_CMD_REPLY_struct                 dd_restart;
	#endif /* Si2168_DD_RESTART_CMD */
	#ifdef    Si2168_DD_SET_REG_CMD
			  Si2168_DD_SET_REG_CMD_REPLY_struct                 dd_set_reg;
	#endif /* Si2168_DD_SET_REG_CMD */
	#ifdef    Si2168_DD_SSI_SQI_CMD
			  Si2168_DD_SSI_SQI_CMD_REPLY_struct                 dd_ssi_sqi;
	#endif /* Si2168_DD_SSI_SQI_CMD */
	#ifdef    Si2168_DD_STATUS_CMD
			  Si2168_DD_STATUS_CMD_REPLY_struct                  dd_status;
	#endif /* Si2168_DD_STATUS_CMD */
	#ifdef    Si2168_DD_UNCOR_CMD
			  Si2168_DD_UNCOR_CMD_REPLY_struct                   dd_uncor;
	#endif /* Si2168_DD_UNCOR_CMD */
	#ifdef    Si2168_DOWNLOAD_DATASET_CONTINUE_CMD
			  Si2168_DOWNLOAD_DATASET_CONTINUE_CMD_REPLY_struct  download_dataset_continue;
	#endif /* Si2168_DOWNLOAD_DATASET_CONTINUE_CMD */
	#ifdef    Si2168_DOWNLOAD_DATASET_START_CMD
			  Si2168_DOWNLOAD_DATASET_START_CMD_REPLY_struct     download_dataset_start;
	#endif /* Si2168_DOWNLOAD_DATASET_START_CMD */
	#ifdef    Si2168_DVBC_STATUS_CMD
			  Si2168_DVBC_STATUS_CMD_REPLY_struct                dvbc_status;
	#endif /* Si2168_DVBC_STATUS_CMD */

	#ifdef    Si2168_DVBT2_FEF_CMD
			  Si2168_DVBT2_FEF_CMD_REPLY_struct                  dvbt2_fef;
	#endif /* Si2168_DVBT2_FEF_CMD */
	#ifdef    Si2168_DVBT2_PLP_INFO_CMD
			  Si2168_DVBT2_PLP_INFO_CMD_REPLY_struct             dvbt2_plp_info;
	#endif /* Si2168_DVBT2_PLP_INFO_CMD */
	#ifdef    Si2168_DVBT2_PLP_SELECT_CMD
			  Si2168_DVBT2_PLP_SELECT_CMD_REPLY_struct           dvbt2_plp_select;
	#endif /* Si2168_DVBT2_PLP_SELECT_CMD */
	#ifdef    Si2168_DVBT2_STATUS_CMD
			  Si2168_DVBT2_STATUS_CMD_REPLY_struct               dvbt2_status;
	#endif /* Si2168_DVBT2_STATUS_CMD */
	#ifdef    Si2168_DVBT2_TX_ID_CMD
			  Si2168_DVBT2_TX_ID_CMD_REPLY_struct                dvbt2_tx_id;
	#endif /* Si2168_DVBT2_TX_ID_CMD */

	#ifdef    Si2168_DVBT_STATUS_CMD
			  Si2168_DVBT_STATUS_CMD_REPLY_struct                dvbt_status;
	#endif /* Si2168_DVBT_STATUS_CMD */
	#ifdef    Si2168_DVBT_TPS_EXTRA_CMD
			  Si2168_DVBT_TPS_EXTRA_CMD_REPLY_struct             dvbt_tps_extra;
	#endif /* Si2168_DVBT_TPS_EXTRA_CMD */

	#ifdef    Si2168_EXIT_BOOTLOADER_CMD
			  Si2168_EXIT_BOOTLOADER_CMD_REPLY_struct            exit_bootloader;
	#endif /* Si2168_EXIT_BOOTLOADER_CMD */
	#ifdef    Si2168_GET_PROPERTY_CMD
			  Si2168_GET_PROPERTY_CMD_REPLY_struct               get_property;
	#endif /* Si2168_GET_PROPERTY_CMD */
	#ifdef    Si2168_GET_REV_CMD
			  Si2168_GET_REV_CMD_REPLY_struct                    get_rev;
	#endif /* Si2168_GET_REV_CMD */
	#ifdef    Si2168_I2C_PASSTHROUGH_CMD
			  Si2168_I2C_PASSTHROUGH_CMD_REPLY_struct            i2c_passthrough;
	#endif /* Si2168_I2C_PASSTHROUGH_CMD */
	#ifdef    Si2168_PART_INFO_CMD
			  Si2168_PART_INFO_CMD_REPLY_struct                  part_info;
	#endif /* Si2168_PART_INFO_CMD */
	#ifdef    Si2168_POWER_DOWN_CMD
			  Si2168_POWER_DOWN_CMD_REPLY_struct                 power_down;
	#endif /* Si2168_POWER_DOWN_CMD */
	#ifdef    Si2168_POWER_UP_CMD
			  Si2168_POWER_UP_CMD_REPLY_struct                   power_up;
	#endif /* Si2168_POWER_UP_CMD */
	#ifdef    Si2168_RSSI_ADC_CMD
			  Si2168_RSSI_ADC_CMD_REPLY_struct                   rssi_adc;
	#endif /* Si2168_RSSI_ADC_CMD */
	#ifdef    Si2168_SCAN_CTRL_CMD
			  Si2168_SCAN_CTRL_CMD_REPLY_struct                  scan_ctrl;
	#endif /* Si2168_SCAN_CTRL_CMD */
	#ifdef    Si2168_SCAN_STATUS_CMD
			  Si2168_SCAN_STATUS_CMD_REPLY_struct                scan_status;
	#endif /* Si2168_SCAN_STATUS_CMD */
	#ifdef    Si2168_SET_PROPERTY_CMD
			  Si2168_SET_PROPERTY_CMD_REPLY_struct               set_property;
	#endif /* Si2168_SET_PROPERTY_CMD */
	#ifdef    Si2168_START_CLK_CMD
			  Si2168_START_CLK_CMD_REPLY_struct                  start_clk;
	#endif /* Si2168_START_CLK_CMD */
} Si2168_CmdReplyObj;

#define   Si2168_DD_BER_RESOL_PROP 0x1003

#ifdef Si2168_DD_BER_RESOL_PROP
	#define Si2168_DD_BER_RESOL_PROP_CODE 0x001003
	typedef struct
	{ // Si2168_DD_BER_RESOL_PROP_struct
		unsigned char   exp;
		unsigned char   mant;
	} Si2168_DD_BER_RESOL_PROP_struct;
	/* DD_BER_RESOL property, EXP field definition (NO TITLE)*/
	#define  Si2168_DD_BER_RESOL_PROP_EXP_LSB         0
	#define  Si2168_DD_BER_RESOL_PROP_EXP_MASK        0x0f
	#define  Si2168_DD_BER_RESOL_PROP_EXP_DEFAULT    7
	#define Si2168_DD_BER_RESOL_PROP_EXP_EXPLO_MIN  1
	#define Si2168_DD_BER_RESOL_PROP_EXP_EXPLO_MAX  8
	/* DD_BER_RESOL property, MANT field definition (NO TITLE)*/
	#define  Si2168_DD_BER_RESOL_PROP_MANT_LSB         4
	#define  Si2168_DD_BER_RESOL_PROP_MANT_MASK        0x0f
	#define  Si2168_DD_BER_RESOL_PROP_MANT_DEFAULT    1
	#define Si2168_DD_BER_RESOL_PROP_MANT_MANTLO_MIN  1
	#define Si2168_DD_BER_RESOL_PROP_MANT_MANTLO_MAX  9
#endif // Si2168_DD_BER_RESOL_PROP

#define Si2168_DD_CBER_RESOL_PROP 0x1002

#ifdef Si2168_DD_CBER_RESOL_PROP
	#define Si2168_DD_CBER_RESOL_PROP_CODE 0x001002
	typedef struct
	{ // Si2168_DD_CBER_RESOL_PROP_struct
		unsigned char   exp;
		unsigned char   mant;
	} Si2168_DD_CBER_RESOL_PROP_struct;
	/* DD_CBER_RESOL property, EXP field definition (NO TITLE)*/
	#define  Si2168_DD_CBER_RESOL_PROP_EXP_LSB         0
	#define  Si2168_DD_CBER_RESOL_PROP_EXP_MASK        0x0f
	#define  Si2168_DD_CBER_RESOL_PROP_EXP_DEFAULT    5
	#define Si2168_DD_CBER_RESOL_PROP_EXP_EXPLO_MIN  1
	#define Si2168_DD_CBER_RESOL_PROP_EXP_EXPLO_MAX  8
	/* DD_CBER_RESOL property, MANT field definition (NO TITLE)*/
	#define  Si2168_DD_CBER_RESOL_PROP_MANT_LSB         4
	#define  Si2168_DD_CBER_RESOL_PROP_MANT_MASK        0x0f
	#define  Si2168_DD_CBER_RESOL_PROP_MANT_DEFAULT    1
	#define Si2168_DD_CBER_RESOL_PROP_MANT_MANTLO_MIN  1
	#define Si2168_DD_CBER_RESOL_PROP_MANT_MANTLO_MAX  9
#endif // Si2168_DD_CBER_RESOL_PROP

/* Si2168 DD_FER_RESOL property definition */
#define Si2168_DD_FER_RESOL_PROP 0x100c

#ifdef Si2168_DD_FER_RESOL_PROP
	#define Si2168_DD_FER_RESOL_PROP_CODE 0x00100c


    typedef struct { /* Si2168_DD_FER_RESOL_PROP_struct */
      unsigned char   exp;
      unsigned char   mant;
   } Si2168_DD_FER_RESOL_PROP_struct;

   /* DD_FER_RESOL property, EXP field definition (NO TITLE)*/
   #define  Si2168_DD_FER_RESOL_PROP_EXP_LSB         0
   #define  Si2168_DD_FER_RESOL_PROP_EXP_MASK        0x0f
   #define  Si2168_DD_FER_RESOL_PROP_EXP_DEFAULT    3
    #define Si2168_DD_FER_RESOL_PROP_EXP_EXP_MIN  1
    #define Si2168_DD_FER_RESOL_PROP_EXP_EXP_MAX  4

   /* DD_FER_RESOL property, MANT field definition (NO TITLE)*/
   #define  Si2168_DD_FER_RESOL_PROP_MANT_LSB         4
   #define  Si2168_DD_FER_RESOL_PROP_MANT_MASK        0x0f
   #define  Si2168_DD_FER_RESOL_PROP_MANT_DEFAULT    1
    #define Si2168_DD_FER_RESOL_PROP_MANT_MANT_MIN  1
    #define Si2168_DD_FER_RESOL_PROP_MANT_MANT_MAX  9

#endif /* Si2168_DD_FER_RESOL_PROP */

/* Si2168 DD_IEN property definition */
#define   Si2168_DD_IEN_PROP 0x1006

#ifdef    Si2168_DD_IEN_PROP
  #define Si2168_DD_IEN_PROP_CODE 0x001006


    typedef struct { /* Si2168_DD_IEN_PROP_struct */
      unsigned char   ien_bit0;
      unsigned char   ien_bit1;
      unsigned char   ien_bit2;
      unsigned char   ien_bit3;
      unsigned char   ien_bit4;
      unsigned char   ien_bit5;
      unsigned char   ien_bit6;
      unsigned char   ien_bit7;
   } Si2168_DD_IEN_PROP_struct;

   /* DD_IEN property, IEN_BIT0 field definition (NO TITLE)*/
   #define  Si2168_DD_IEN_PROP_IEN_BIT0_LSB         0
   #define  Si2168_DD_IEN_PROP_IEN_BIT0_MASK        0x01
   #define  Si2168_DD_IEN_PROP_IEN_BIT0_DEFAULT    0
    #define Si2168_DD_IEN_PROP_IEN_BIT0_DISABLE  0
    #define Si2168_DD_IEN_PROP_IEN_BIT0_ENABLE   1

   /* DD_IEN property, IEN_BIT1 field definition (NO TITLE)*/
   #define  Si2168_DD_IEN_PROP_IEN_BIT1_LSB         1
   #define  Si2168_DD_IEN_PROP_IEN_BIT1_MASK        0x01
   #define  Si2168_DD_IEN_PROP_IEN_BIT1_DEFAULT    0
    #define Si2168_DD_IEN_PROP_IEN_BIT1_DISABLE  0
    #define Si2168_DD_IEN_PROP_IEN_BIT1_ENABLE   1

   /* DD_IEN property, IEN_BIT2 field definition (NO TITLE)*/
   #define  Si2168_DD_IEN_PROP_IEN_BIT2_LSB         2
   #define  Si2168_DD_IEN_PROP_IEN_BIT2_MASK        0x01
   #define  Si2168_DD_IEN_PROP_IEN_BIT2_DEFAULT    0
    #define Si2168_DD_IEN_PROP_IEN_BIT2_DISABLE  0
    #define Si2168_DD_IEN_PROP_IEN_BIT2_ENABLE   1

   /* DD_IEN property, IEN_BIT3 field definition (NO TITLE)*/
   #define  Si2168_DD_IEN_PROP_IEN_BIT3_LSB         3
   #define  Si2168_DD_IEN_PROP_IEN_BIT3_MASK        0x01
   #define  Si2168_DD_IEN_PROP_IEN_BIT3_DEFAULT    0
    #define Si2168_DD_IEN_PROP_IEN_BIT3_DISABLE  0
    #define Si2168_DD_IEN_PROP_IEN_BIT3_ENABLE   1

   /* DD_IEN property, IEN_BIT4 field definition (NO TITLE)*/
   #define  Si2168_DD_IEN_PROP_IEN_BIT4_LSB         4
   #define  Si2168_DD_IEN_PROP_IEN_BIT4_MASK        0x01
   #define  Si2168_DD_IEN_PROP_IEN_BIT4_DEFAULT    0
    #define Si2168_DD_IEN_PROP_IEN_BIT4_DISABLE  0
    #define Si2168_DD_IEN_PROP_IEN_BIT4_ENABLE   1

   /* DD_IEN property, IEN_BIT5 field definition (NO TITLE)*/
   #define  Si2168_DD_IEN_PROP_IEN_BIT5_LSB         5
   #define  Si2168_DD_IEN_PROP_IEN_BIT5_MASK        0x01
   #define  Si2168_DD_IEN_PROP_IEN_BIT5_DEFAULT    0
    #define Si2168_DD_IEN_PROP_IEN_BIT5_DISABLE  0
    #define Si2168_DD_IEN_PROP_IEN_BIT5_ENABLE   1

   /* DD_IEN property, IEN_BIT6 field definition (NO TITLE)*/
   #define  Si2168_DD_IEN_PROP_IEN_BIT6_LSB         6
   #define  Si2168_DD_IEN_PROP_IEN_BIT6_MASK        0x01
   #define  Si2168_DD_IEN_PROP_IEN_BIT6_DEFAULT    0
    #define Si2168_DD_IEN_PROP_IEN_BIT6_DISABLE  0
    #define Si2168_DD_IEN_PROP_IEN_BIT6_ENABLE   1

   /* DD_IEN property, IEN_BIT7 field definition (NO TITLE)*/
   #define  Si2168_DD_IEN_PROP_IEN_BIT7_LSB         7
   #define  Si2168_DD_IEN_PROP_IEN_BIT7_MASK        0x01
   #define  Si2168_DD_IEN_PROP_IEN_BIT7_DEFAULT    0
    #define Si2168_DD_IEN_PROP_IEN_BIT7_DISABLE  0
    #define Si2168_DD_IEN_PROP_IEN_BIT7_ENABLE   1

#endif /* Si2168_DD_IEN_PROP */

/* Si2168 DD_IF_INPUT_FREQ property definition */
#define   Si2168_DD_IF_INPUT_FREQ_PROP 0x100b

#ifdef    Si2168_DD_IF_INPUT_FREQ_PROP
  #define Si2168_DD_IF_INPUT_FREQ_PROP_CODE 0x00100b


    typedef struct { /* Si2168_DD_IF_INPUT_FREQ_PROP_struct */
      unsigned int    offset;
   } Si2168_DD_IF_INPUT_FREQ_PROP_struct;

   /* DD_IF_INPUT_FREQ property, OFFSET field definition (NO TITLE)*/
   #define  Si2168_DD_IF_INPUT_FREQ_PROP_OFFSET_LSB         0
   #define  Si2168_DD_IF_INPUT_FREQ_PROP_OFFSET_MASK        0xffff
   #define  Si2168_DD_IF_INPUT_FREQ_PROP_OFFSET_DEFAULT    5000
    #define Si2168_DD_IF_INPUT_FREQ_PROP_OFFSET_OFFSET_MIN  0
    #define Si2168_DD_IF_INPUT_FREQ_PROP_OFFSET_OFFSET_MAX  36000

#endif /* Si2168_DD_IF_INPUT_FREQ_PROP */

/* Si2168 DD_INT_SENSE property definition */
#define   Si2168_DD_INT_SENSE_PROP 0x1007

#ifdef    Si2168_DD_INT_SENSE_PROP
  #define Si2168_DD_INT_SENSE_PROP_CODE 0x001007


    typedef struct { /* Si2168_DD_INT_SENSE_PROP_struct */
      unsigned char   neg_bit0;
      unsigned char   neg_bit1;
      unsigned char   neg_bit2;
      unsigned char   neg_bit3;
      unsigned char   neg_bit4;
      unsigned char   neg_bit5;
      unsigned char   neg_bit6;
      unsigned char   neg_bit7;
      unsigned char   pos_bit0;
      unsigned char   pos_bit1;
      unsigned char   pos_bit2;
      unsigned char   pos_bit3;
      unsigned char   pos_bit4;
      unsigned char   pos_bit5;
      unsigned char   pos_bit6;
      unsigned char   pos_bit7;
   } Si2168_DD_INT_SENSE_PROP_struct;

   /* DD_INT_SENSE property, NEG_BIT0 field definition (NO TITLE)*/
   #define  Si2168_DD_INT_SENSE_PROP_NEG_BIT0_LSB         0
   #define  Si2168_DD_INT_SENSE_PROP_NEG_BIT0_MASK        0x01
   #define  Si2168_DD_INT_SENSE_PROP_NEG_BIT0_DEFAULT    0
    #define Si2168_DD_INT_SENSE_PROP_NEG_BIT0_DISABLE  0
    #define Si2168_DD_INT_SENSE_PROP_NEG_BIT0_ENABLE   1

   /* DD_INT_SENSE property, NEG_BIT1 field definition (NO TITLE)*/
   #define  Si2168_DD_INT_SENSE_PROP_NEG_BIT1_LSB         1
   #define  Si2168_DD_INT_SENSE_PROP_NEG_BIT1_MASK        0x01
   #define  Si2168_DD_INT_SENSE_PROP_NEG_BIT1_DEFAULT    0
    #define Si2168_DD_INT_SENSE_PROP_NEG_BIT1_DISABLE  0
    #define Si2168_DD_INT_SENSE_PROP_NEG_BIT1_ENABLE   1

   /* DD_INT_SENSE property, NEG_BIT2 field definition (NO TITLE)*/
   #define  Si2168_DD_INT_SENSE_PROP_NEG_BIT2_LSB         2
   #define  Si2168_DD_INT_SENSE_PROP_NEG_BIT2_MASK        0x01
   #define  Si2168_DD_INT_SENSE_PROP_NEG_BIT2_DEFAULT    0
    #define Si2168_DD_INT_SENSE_PROP_NEG_BIT2_DISABLE  0
    #define Si2168_DD_INT_SENSE_PROP_NEG_BIT2_ENABLE   1

   /* DD_INT_SENSE property, NEG_BIT3 field definition (NO TITLE)*/
   #define  Si2168_DD_INT_SENSE_PROP_NEG_BIT3_LSB         3
   #define  Si2168_DD_INT_SENSE_PROP_NEG_BIT3_MASK        0x01
   #define  Si2168_DD_INT_SENSE_PROP_NEG_BIT3_DEFAULT    0
    #define Si2168_DD_INT_SENSE_PROP_NEG_BIT3_DISABLE  0
    #define Si2168_DD_INT_SENSE_PROP_NEG_BIT3_ENABLE   1

   /* DD_INT_SENSE property, NEG_BIT4 field definition (NO TITLE)*/
   #define  Si2168_DD_INT_SENSE_PROP_NEG_BIT4_LSB         4
   #define  Si2168_DD_INT_SENSE_PROP_NEG_BIT4_MASK        0x01
   #define  Si2168_DD_INT_SENSE_PROP_NEG_BIT4_DEFAULT    0
    #define Si2168_DD_INT_SENSE_PROP_NEG_BIT4_DISABLE  0
    #define Si2168_DD_INT_SENSE_PROP_NEG_BIT4_ENABLE   1

   /* DD_INT_SENSE property, NEG_BIT5 field definition (NO TITLE)*/
   #define  Si2168_DD_INT_SENSE_PROP_NEG_BIT5_LSB         5
   #define  Si2168_DD_INT_SENSE_PROP_NEG_BIT5_MASK        0x01
   #define  Si2168_DD_INT_SENSE_PROP_NEG_BIT5_DEFAULT    0
    #define Si2168_DD_INT_SENSE_PROP_NEG_BIT5_DISABLE  0
    #define Si2168_DD_INT_SENSE_PROP_NEG_BIT5_ENABLE   1

   /* DD_INT_SENSE property, NEG_BIT6 field definition (NO TITLE)*/
   #define  Si2168_DD_INT_SENSE_PROP_NEG_BIT6_LSB         6
   #define  Si2168_DD_INT_SENSE_PROP_NEG_BIT6_MASK        0x01
   #define  Si2168_DD_INT_SENSE_PROP_NEG_BIT6_DEFAULT    0
    #define Si2168_DD_INT_SENSE_PROP_NEG_BIT6_DISABLE  0
    #define Si2168_DD_INT_SENSE_PROP_NEG_BIT6_ENABLE   1

   /* DD_INT_SENSE property, NEG_BIT7 field definition (NO TITLE)*/
   #define  Si2168_DD_INT_SENSE_PROP_NEG_BIT7_LSB         7
   #define  Si2168_DD_INT_SENSE_PROP_NEG_BIT7_MASK        0x01
   #define  Si2168_DD_INT_SENSE_PROP_NEG_BIT7_DEFAULT    0
    #define Si2168_DD_INT_SENSE_PROP_NEG_BIT7_DISABLE  0
    #define Si2168_DD_INT_SENSE_PROP_NEG_BIT7_ENABLE   1

   /* DD_INT_SENSE property, POS_BIT0 field definition (NO TITLE)*/
   #define  Si2168_DD_INT_SENSE_PROP_POS_BIT0_LSB         8
   #define  Si2168_DD_INT_SENSE_PROP_POS_BIT0_MASK        0x01
   #define  Si2168_DD_INT_SENSE_PROP_POS_BIT0_DEFAULT    0
    #define Si2168_DD_INT_SENSE_PROP_POS_BIT0_DISABLE  0
    #define Si2168_DD_INT_SENSE_PROP_POS_BIT0_ENABLE   1

   /* DD_INT_SENSE property, POS_BIT1 field definition (NO TITLE)*/
   #define  Si2168_DD_INT_SENSE_PROP_POS_BIT1_LSB         9
   #define  Si2168_DD_INT_SENSE_PROP_POS_BIT1_MASK        0x01
   #define  Si2168_DD_INT_SENSE_PROP_POS_BIT1_DEFAULT    0
    #define Si2168_DD_INT_SENSE_PROP_POS_BIT1_DISABLE  0
    #define Si2168_DD_INT_SENSE_PROP_POS_BIT1_ENABLE   1

   /* DD_INT_SENSE property, POS_BIT2 field definition (NO TITLE)*/
   #define  Si2168_DD_INT_SENSE_PROP_POS_BIT2_LSB         10
   #define  Si2168_DD_INT_SENSE_PROP_POS_BIT2_MASK        0x01
   #define  Si2168_DD_INT_SENSE_PROP_POS_BIT2_DEFAULT    0
    #define Si2168_DD_INT_SENSE_PROP_POS_BIT2_DISABLE  0
    #define Si2168_DD_INT_SENSE_PROP_POS_BIT2_ENABLE   1

   /* DD_INT_SENSE property, POS_BIT3 field definition (NO TITLE)*/
   #define  Si2168_DD_INT_SENSE_PROP_POS_BIT3_LSB         11
   #define  Si2168_DD_INT_SENSE_PROP_POS_BIT3_MASK        0x01
   #define  Si2168_DD_INT_SENSE_PROP_POS_BIT3_DEFAULT    0
    #define Si2168_DD_INT_SENSE_PROP_POS_BIT3_DISABLE  0
    #define Si2168_DD_INT_SENSE_PROP_POS_BIT3_ENABLE   1

   /* DD_INT_SENSE property, POS_BIT4 field definition (NO TITLE)*/
   #define  Si2168_DD_INT_SENSE_PROP_POS_BIT4_LSB         12
   #define  Si2168_DD_INT_SENSE_PROP_POS_BIT4_MASK        0x01
   #define  Si2168_DD_INT_SENSE_PROP_POS_BIT4_DEFAULT    0
    #define Si2168_DD_INT_SENSE_PROP_POS_BIT4_DISABLE  0
    #define Si2168_DD_INT_SENSE_PROP_POS_BIT4_ENABLE   1

   /* DD_INT_SENSE property, POS_BIT5 field definition (NO TITLE)*/
   #define  Si2168_DD_INT_SENSE_PROP_POS_BIT5_LSB         13
   #define  Si2168_DD_INT_SENSE_PROP_POS_BIT5_MASK        0x01
   #define  Si2168_DD_INT_SENSE_PROP_POS_BIT5_DEFAULT    0
    #define Si2168_DD_INT_SENSE_PROP_POS_BIT5_DISABLE  0
    #define Si2168_DD_INT_SENSE_PROP_POS_BIT5_ENABLE   1

   /* DD_INT_SENSE property, POS_BIT6 field definition (NO TITLE)*/
   #define  Si2168_DD_INT_SENSE_PROP_POS_BIT6_LSB         14
   #define  Si2168_DD_INT_SENSE_PROP_POS_BIT6_MASK        0x01
   #define  Si2168_DD_INT_SENSE_PROP_POS_BIT6_DEFAULT    0
    #define Si2168_DD_INT_SENSE_PROP_POS_BIT6_DISABLE  0
    #define Si2168_DD_INT_SENSE_PROP_POS_BIT6_ENABLE   1

   /* DD_INT_SENSE property, POS_BIT7 field definition (NO TITLE)*/
   #define  Si2168_DD_INT_SENSE_PROP_POS_BIT7_LSB         15
   #define  Si2168_DD_INT_SENSE_PROP_POS_BIT7_MASK        0x01
   #define  Si2168_DD_INT_SENSE_PROP_POS_BIT7_DEFAULT    0
    #define Si2168_DD_INT_SENSE_PROP_POS_BIT7_DISABLE  0
    #define Si2168_DD_INT_SENSE_PROP_POS_BIT7_ENABLE   1

#endif /* Si2168_DD_INT_SENSE_PROP */

/* Si2168 DD_MODE property definition */
#define   Si2168_DD_MODE_PROP 0x100a

#ifdef    Si2168_DD_MODE_PROP
  #define Si2168_DD_MODE_PROP_CODE 0x00100a


    typedef struct { /* Si2168_DD_MODE_PROP_struct */
      unsigned char   auto_detect;
      unsigned char   bw;
      unsigned char   invert_spectrum;
      unsigned char   modulation;
   } Si2168_DD_MODE_PROP_struct;

   /* DD_MODE property, AUTO_DETECT field definition (NO TITLE)*/
   #define  Si2168_DD_MODE_PROP_AUTO_DETECT_LSB         9
   #define  Si2168_DD_MODE_PROP_AUTO_DETECT_MASK        0x07
   #define  Si2168_DD_MODE_PROP_AUTO_DETECT_DEFAULT    0
    #define Si2168_DD_MODE_PROP_AUTO_DETECT_NONE               0
    #define Si2168_DD_MODE_PROP_AUTO_DETECT_AUTO_DVB_T_T2      1
    #define Si2168_DD_MODE_PROP_AUTO_DETECT_AUTO_DVB_S_S2      2
    #define Si2168_DD_MODE_PROP_AUTO_DETECT_AUTO_DVB_S_S2_DSS  3

   /* DD_MODE property, BW field definition (NO TITLE)*/
   #define  Si2168_DD_MODE_PROP_BW_LSB         0
   #define  Si2168_DD_MODE_PROP_BW_MASK        0x0f
   #define  Si2168_DD_MODE_PROP_BW_DEFAULT    8
    #define Si2168_DD_MODE_PROP_BW_BW_5MHZ    5
    #define Si2168_DD_MODE_PROP_BW_BW_6MHZ    6
    #define Si2168_DD_MODE_PROP_BW_BW_7MHZ    7
    #define Si2168_DD_MODE_PROP_BW_BW_8MHZ    8
    #define Si2168_DD_MODE_PROP_BW_BW_1D7MHZ  2

   /* DD_MODE property, INVERT_SPECTRUM field definition (NO TITLE)*/
   #define  Si2168_DD_MODE_PROP_INVERT_SPECTRUM_LSB         8
   #define  Si2168_DD_MODE_PROP_INVERT_SPECTRUM_MASK        0x01
   #define  Si2168_DD_MODE_PROP_INVERT_SPECTRUM_DEFAULT    0
    #define Si2168_DD_MODE_PROP_INVERT_SPECTRUM_NORMAL    0
    #define Si2168_DD_MODE_PROP_INVERT_SPECTRUM_INVERTED  1

   /* DD_MODE property, MODULATION field definition (NO TITLE)*/
   #define  Si2168_DD_MODE_PROP_MODULATION_LSB          4
   #define  Si2168_DD_MODE_PROP_MODULATION_MASK         0x0f
   #define  Si2168_DD_MODE_PROP_MODULATION_DEFAULT      2
    #define Si2168_DD_MODE_PROP_MODULATION_DVBT         2
    #define Si2168_DD_MODE_PROP_MODULATION_DVBC         3
    #define Si2168_DD_MODE_PROP_MODULATION_DVBT2        7
    #define Si2168_DD_MODE_PROP_MODULATION_DVBS         8
    #define Si2168_DD_MODE_PROP_MODULATION_DVBS2        9
    #define Si2168_DD_MODE_PROP_MODULATION_DSS          10
    #define Si2168_DD_MODE_PROP_MODULATION_AUTO_DETECT  15
    #define Si2168_DD_MODE_PROP_MODULATION_ANALOG     100

#endif /* Si2168_DD_MODE_PROP */

/* Si2168 DD_PER_RESOL property definition */
#define   Si2168_DD_PER_RESOL_PROP 0x1004

#ifdef    Si2168_DD_PER_RESOL_PROP
  #define Si2168_DD_PER_RESOL_PROP_CODE 0x001004


    typedef struct { /* Si2168_DD_PER_RESOL_PROP_struct */
      unsigned char   exp;
      unsigned char   mant;
   } Si2168_DD_PER_RESOL_PROP_struct;

   /* DD_PER_RESOL property, EXP field definition (NO TITLE)*/
   #define  Si2168_DD_PER_RESOL_PROP_EXP_LSB         0
   #define  Si2168_DD_PER_RESOL_PROP_EXP_MASK        0x0f
   #define  Si2168_DD_PER_RESOL_PROP_EXP_DEFAULT    5
    #define Si2168_DD_PER_RESOL_PROP_EXP_EXPLO_MIN  1
    #define Si2168_DD_PER_RESOL_PROP_EXP_EXPLO_MAX  9

   /* DD_PER_RESOL property, MANT field definition (NO TITLE)*/
   #define  Si2168_DD_PER_RESOL_PROP_MANT_LSB         4
   #define  Si2168_DD_PER_RESOL_PROP_MANT_MASK        0x0f
   #define  Si2168_DD_PER_RESOL_PROP_MANT_DEFAULT    1
    #define Si2168_DD_PER_RESOL_PROP_MANT_MANTLO_MIN  1
    #define Si2168_DD_PER_RESOL_PROP_MANT_MANTLO_MAX  9

#endif /* Si2168_DD_PER_RESOL_PROP */

/* Si2168 DD_RSQ_BER_THRESHOLD property definition */
#define   Si2168_DD_RSQ_BER_THRESHOLD_PROP 0x1005

#ifdef    Si2168_DD_RSQ_BER_THRESHOLD_PROP
  #define Si2168_DD_RSQ_BER_THRESHOLD_PROP_CODE 0x001005


    typedef struct { /* Si2168_DD_RSQ_BER_THRESHOLD_PROP_struct */
      unsigned char   exp;
      unsigned char   mant;
   } Si2168_DD_RSQ_BER_THRESHOLD_PROP_struct;

   /* DD_RSQ_BER_THRESHOLD property, EXP field definition (NO TITLE)*/
   #define  Si2168_DD_RSQ_BER_THRESHOLD_PROP_EXP_LSB         0
   #define  Si2168_DD_RSQ_BER_THRESHOLD_PROP_EXP_MASK        0x0f
   #define  Si2168_DD_RSQ_BER_THRESHOLD_PROP_EXP_DEFAULT    1
    #define Si2168_DD_RSQ_BER_THRESHOLD_PROP_EXP_EXP_MIN  1
    #define Si2168_DD_RSQ_BER_THRESHOLD_PROP_EXP_EXP_MAX  8

   /* DD_RSQ_BER_THRESHOLD property, MANT field definition (NO TITLE)*/
   #define  Si2168_DD_RSQ_BER_THRESHOLD_PROP_MANT_LSB         4
   #define  Si2168_DD_RSQ_BER_THRESHOLD_PROP_MANT_MASK        0x0f
   #define  Si2168_DD_RSQ_BER_THRESHOLD_PROP_MANT_DEFAULT    10
    #define Si2168_DD_RSQ_BER_THRESHOLD_PROP_MANT_MANT_MIN  0
    #define Si2168_DD_RSQ_BER_THRESHOLD_PROP_MANT_MANT_MAX  99

#endif /* Si2168_DD_RSQ_BER_THRESHOLD_PROP */

/* Si2168 DD_SSI_SQI_PARAM property definition */
#define   Si2168_DD_SSI_SQI_PARAM_PROP 0x100f

#ifdef    Si2168_DD_SSI_SQI_PARAM_PROP
  #define Si2168_DD_SSI_SQI_PARAM_PROP_CODE 0x00100f


    typedef struct { /* Si2168_DD_SSI_SQI_PARAM_PROP_struct */
      unsigned char   sqi_average;
   } Si2168_DD_SSI_SQI_PARAM_PROP_struct;

   /* DD_SSI_SQI_PARAM property, SQI_AVERAGE field definition (NO TITLE)*/
   #define  Si2168_DD_SSI_SQI_PARAM_PROP_SQI_AVERAGE_LSB         0
   #define  Si2168_DD_SSI_SQI_PARAM_PROP_SQI_AVERAGE_MASK        0x1f
   #define  Si2168_DD_SSI_SQI_PARAM_PROP_SQI_AVERAGE_DEFAULT    1
    #define Si2168_DD_SSI_SQI_PARAM_PROP_SQI_AVERAGE_SQI_AVERAGE_MIN  1
    #define Si2168_DD_SSI_SQI_PARAM_PROP_SQI_AVERAGE_SQI_AVERAGE_MAX  30

#endif /* Si2168_DD_SSI_SQI_PARAM_PROP */

/* Si2168 DD_TS_FREQ property definition */
#define   Si2168_DD_TS_FREQ_PROP 0x100d

#ifdef    Si2168_DD_TS_FREQ_PROP
  #define Si2168_DD_TS_FREQ_PROP_CODE 0x00100d


    typedef struct { /* Si2168_DD_TS_FREQ_PROP_struct */
      unsigned int    req_freq_10khz;
   } Si2168_DD_TS_FREQ_PROP_struct;

   /* DD_TS_FREQ property, REQ_FREQ_10KHZ field definition (NO TITLE)*/
   #define  Si2168_DD_TS_FREQ_PROP_REQ_FREQ_10KHZ_LSB         0
   #define  Si2168_DD_TS_FREQ_PROP_REQ_FREQ_10KHZ_MASK        0x3fff
   #define  Si2168_DD_TS_FREQ_PROP_REQ_FREQ_10KHZ_DEFAULT    720
    #define Si2168_DD_TS_FREQ_PROP_REQ_FREQ_10KHZ_REQ_FREQ_10KHZ_MIN  0
    #define Si2168_DD_TS_FREQ_PROP_REQ_FREQ_10KHZ_REQ_FREQ_10KHZ_MAX  14550

#endif /* Si2168_DD_TS_FREQ_PROP */

/* Si2168 DD_TS_MODE property definition */
#define   Si2168_DD_TS_MODE_PROP 0x1001

#ifdef    Si2168_DD_TS_MODE_PROP
  #define Si2168_DD_TS_MODE_PROP_CODE 0x001001


    typedef struct { /* Si2168_DD_TS_MODE_PROP_struct */
      unsigned char   clk_gapped_en;
      unsigned char   clock;
      unsigned char   mode;
   } Si2168_DD_TS_MODE_PROP_struct;

   /* DD_TS_MODE property, CLK_GAPPED_EN field definition (NO TITLE)*/
   #define  Si2168_DD_TS_MODE_PROP_CLK_GAPPED_EN_LSB         6
   #define  Si2168_DD_TS_MODE_PROP_CLK_GAPPED_EN_MASK        0x01
   #define  Si2168_DD_TS_MODE_PROP_CLK_GAPPED_EN_DEFAULT    0
    #define Si2168_DD_TS_MODE_PROP_CLK_GAPPED_EN_DISABLED  0
    #define Si2168_DD_TS_MODE_PROP_CLK_GAPPED_EN_ENABLED   1

   /* DD_TS_MODE property, CLOCK field definition (NO TITLE)*/
   #define  Si2168_DD_TS_MODE_PROP_CLOCK_LSB         4
   #define  Si2168_DD_TS_MODE_PROP_CLOCK_MASK        0x03
   #define  Si2168_DD_TS_MODE_PROP_CLOCK_DEFAULT    0
    #define Si2168_DD_TS_MODE_PROP_CLOCK_AUTO_FIXED  0
    #define Si2168_DD_TS_MODE_PROP_CLOCK_AUTO_ADAPT  1
    #define Si2168_DD_TS_MODE_PROP_CLOCK_MANUAL      2

   /* DD_TS_MODE property, MODE field definition (NO TITLE)*/
   #define  Si2168_DD_TS_MODE_PROP_MODE_LSB         0
   #define  Si2168_DD_TS_MODE_PROP_MODE_MASK        0x0f
   #define  Si2168_DD_TS_MODE_PROP_MODE_DEFAULT    0
    #define Si2168_DD_TS_MODE_PROP_MODE_TRISTATE  0
    #define Si2168_DD_TS_MODE_PROP_MODE_OFF       1
    #define Si2168_DD_TS_MODE_PROP_MODE_SERIAL    3
    #define Si2168_DD_TS_MODE_PROP_MODE_PARALLEL  6
    #define Si2168_DD_TS_MODE_PROP_MODE_GPIF      7

#endif /* Si2168_DD_TS_MODE_PROP */

/* Si2168 DD_TS_SETUP_PAR property definition */
#define   Si2168_DD_TS_SETUP_PAR_PROP 0x1009

#ifdef    Si2168_DD_TS_SETUP_PAR_PROP
  #define Si2168_DD_TS_SETUP_PAR_PROP_CODE 0x001009


    typedef struct { /* Si2168_DD_TS_SETUP_PAR_PROP_struct */
      unsigned char   ts_clk_invert;
      unsigned char   ts_clk_shape;
      unsigned char   ts_clk_shift;
      unsigned char   ts_clk_strength;
      unsigned char   ts_data_shape;
      unsigned char   ts_data_strength;
   } Si2168_DD_TS_SETUP_PAR_PROP_struct;

   /* DD_TS_SETUP_PAR property, TS_CLK_INVERT field definition (NO TITLE)*/
   #define  Si2168_DD_TS_SETUP_PAR_PROP_TS_CLK_INVERT_LSB         12
   #define  Si2168_DD_TS_SETUP_PAR_PROP_TS_CLK_INVERT_MASK        0x01
   #define  Si2168_DD_TS_SETUP_PAR_PROP_TS_CLK_INVERT_DEFAULT    1
    #define Si2168_DD_TS_SETUP_PAR_PROP_TS_CLK_INVERT_NOT_INVERTED  0
    #define Si2168_DD_TS_SETUP_PAR_PROP_TS_CLK_INVERT_INVERTED      1

   /* DD_TS_SETUP_PAR property, TS_CLK_SHAPE field definition (NO TITLE)*/
   #define  Si2168_DD_TS_SETUP_PAR_PROP_TS_CLK_SHAPE_LSB         10
   #define  Si2168_DD_TS_SETUP_PAR_PROP_TS_CLK_SHAPE_MASK        0x03
   #define  Si2168_DD_TS_SETUP_PAR_PROP_TS_CLK_SHAPE_DEFAULT    1
   /* DD_TS_SETUP_PAR property, TS_CLK_SHIFT field definition (NO TITLE)*/
   #define  Si2168_DD_TS_SETUP_PAR_PROP_TS_CLK_SHIFT_LSB         13
   #define  Si2168_DD_TS_SETUP_PAR_PROP_TS_CLK_SHIFT_MASK        0x07
   #define  Si2168_DD_TS_SETUP_PAR_PROP_TS_CLK_SHIFT_DEFAULT    0
   /* DD_TS_SETUP_PAR property, TS_CLK_STRENGTH field definition (NO TITLE)*/
   #define  Si2168_DD_TS_SETUP_PAR_PROP_TS_CLK_STRENGTH_LSB         6
   #define  Si2168_DD_TS_SETUP_PAR_PROP_TS_CLK_STRENGTH_MASK        0x0f
   #define  Si2168_DD_TS_SETUP_PAR_PROP_TS_CLK_STRENGTH_DEFAULT    3
   /* DD_TS_SETUP_PAR property, TS_DATA_SHAPE field definition (NO TITLE)*/
   #define  Si2168_DD_TS_SETUP_PAR_PROP_TS_DATA_SHAPE_LSB         4
   #define  Si2168_DD_TS_SETUP_PAR_PROP_TS_DATA_SHAPE_MASK        0x03
   #define  Si2168_DD_TS_SETUP_PAR_PROP_TS_DATA_SHAPE_DEFAULT    1
   /* DD_TS_SETUP_PAR property, TS_DATA_STRENGTH field definition (NO TITLE)*/
   #define  Si2168_DD_TS_SETUP_PAR_PROP_TS_DATA_STRENGTH_LSB         0
   #define  Si2168_DD_TS_SETUP_PAR_PROP_TS_DATA_STRENGTH_MASK        0x0f
   #define  Si2168_DD_TS_SETUP_PAR_PROP_TS_DATA_STRENGTH_DEFAULT    3
#endif /* Si2168_DD_TS_SETUP_PAR_PROP */

/* Si2168 DD_TS_SETUP_SER property definition */
#define   Si2168_DD_TS_SETUP_SER_PROP 0x1008

#ifdef    Si2168_DD_TS_SETUP_SER_PROP
  #define Si2168_DD_TS_SETUP_SER_PROP_CODE 0x001008


    typedef struct { /* Si2168_DD_TS_SETUP_SER_PROP_struct */
      unsigned char   ts_byte_order;
      unsigned char   ts_clk_invert;
      unsigned char   ts_clk_shape;
      unsigned char   ts_clk_strength;
      unsigned char   ts_data_shape;
      unsigned char   ts_data_strength;
      unsigned char   ts_sync_duration;
   } Si2168_DD_TS_SETUP_SER_PROP_struct;

   /* DD_TS_SETUP_SER property, TS_BYTE_ORDER field definition (NO TITLE)*/
   #define  Si2168_DD_TS_SETUP_SER_PROP_TS_BYTE_ORDER_LSB         14
   #define  Si2168_DD_TS_SETUP_SER_PROP_TS_BYTE_ORDER_MASK        0x01
   #define  Si2168_DD_TS_SETUP_SER_PROP_TS_BYTE_ORDER_DEFAULT    0
    #define Si2168_DD_TS_SETUP_SER_PROP_TS_BYTE_ORDER_MSB_FIRST  0
    #define Si2168_DD_TS_SETUP_SER_PROP_TS_BYTE_ORDER_LSB_FIRST  1

   /* DD_TS_SETUP_SER property, TS_CLK_INVERT field definition (NO TITLE)*/
   #define  Si2168_DD_TS_SETUP_SER_PROP_TS_CLK_INVERT_LSB         12
   #define  Si2168_DD_TS_SETUP_SER_PROP_TS_CLK_INVERT_MASK        0x01
   #define  Si2168_DD_TS_SETUP_SER_PROP_TS_CLK_INVERT_DEFAULT    1
    #define Si2168_DD_TS_SETUP_SER_PROP_TS_CLK_INVERT_NOT_INVERTED  0
    #define Si2168_DD_TS_SETUP_SER_PROP_TS_CLK_INVERT_INVERTED      1

   /* DD_TS_SETUP_SER property, TS_CLK_SHAPE field definition (NO TITLE)*/
   #define  Si2168_DD_TS_SETUP_SER_PROP_TS_CLK_SHAPE_LSB         10
   #define  Si2168_DD_TS_SETUP_SER_PROP_TS_CLK_SHAPE_MASK        0x03
   #define  Si2168_DD_TS_SETUP_SER_PROP_TS_CLK_SHAPE_DEFAULT    3
   /* DD_TS_SETUP_SER property, TS_CLK_STRENGTH field definition (NO TITLE)*/
   #define  Si2168_DD_TS_SETUP_SER_PROP_TS_CLK_STRENGTH_LSB         6
   #define  Si2168_DD_TS_SETUP_SER_PROP_TS_CLK_STRENGTH_MASK        0x0f
   #define  Si2168_DD_TS_SETUP_SER_PROP_TS_CLK_STRENGTH_DEFAULT    15
   /* DD_TS_SETUP_SER property, TS_DATA_SHAPE field definition (NO TITLE)*/
   #define  Si2168_DD_TS_SETUP_SER_PROP_TS_DATA_SHAPE_LSB         4
   #define  Si2168_DD_TS_SETUP_SER_PROP_TS_DATA_SHAPE_MASK        0x03
   #define  Si2168_DD_TS_SETUP_SER_PROP_TS_DATA_SHAPE_DEFAULT    3
   /* DD_TS_SETUP_SER property, TS_DATA_STRENGTH field definition (NO TITLE)*/
   #define  Si2168_DD_TS_SETUP_SER_PROP_TS_DATA_STRENGTH_LSB         0
   #define  Si2168_DD_TS_SETUP_SER_PROP_TS_DATA_STRENGTH_MASK        0x0f
   #define  Si2168_DD_TS_SETUP_SER_PROP_TS_DATA_STRENGTH_DEFAULT    15
   /* DD_TS_SETUP_SER property, TS_SYNC_DURATION field definition (NO TITLE)*/
   #define  Si2168_DD_TS_SETUP_SER_PROP_TS_SYNC_DURATION_LSB         13
   #define  Si2168_DD_TS_SETUP_SER_PROP_TS_SYNC_DURATION_MASK        0x01
   #define  Si2168_DD_TS_SETUP_SER_PROP_TS_SYNC_DURATION_DEFAULT    0
    #define Si2168_DD_TS_SETUP_SER_PROP_TS_SYNC_DURATION_FIRST_BYTE  0
    #define Si2168_DD_TS_SETUP_SER_PROP_TS_SYNC_DURATION_FIRST_BIT   1

#endif /* Si2168_DD_TS_SETUP_SER_PROP */

/* Si2168 DVBC_ADC_CREST_FACTOR property definition */
#define   Si2168_DVBC_ADC_CREST_FACTOR_PROP 0x1104

#ifdef    Si2168_DVBC_ADC_CREST_FACTOR_PROP
  #define Si2168_DVBC_ADC_CREST_FACTOR_PROP_CODE 0x001104


    typedef struct { /* Si2168_DVBC_ADC_CREST_FACTOR_PROP_struct */
      unsigned char   crest_factor;
   } Si2168_DVBC_ADC_CREST_FACTOR_PROP_struct;

   /* DVBC_ADC_CREST_FACTOR property, CREST_FACTOR field definition (NO TITLE)*/
   #define  Si2168_DVBC_ADC_CREST_FACTOR_PROP_CREST_FACTOR_LSB         0
   #define  Si2168_DVBC_ADC_CREST_FACTOR_PROP_CREST_FACTOR_MASK        0xff
   #define  Si2168_DVBC_ADC_CREST_FACTOR_PROP_CREST_FACTOR_DEFAULT    112
#endif /* Si2168_DVBC_ADC_CREST_FACTOR_PROP */

/* Si2168 DVBC_AFC_RANGE property definition */
#define   Si2168_DVBC_AFC_RANGE_PROP 0x1103

#ifdef    Si2168_DVBC_AFC_RANGE_PROP
  #define Si2168_DVBC_AFC_RANGE_PROP_CODE 0x001103


    typedef struct { /* Si2168_DVBC_AFC_RANGE_PROP_struct */
      unsigned int    range_khz;
   } Si2168_DVBC_AFC_RANGE_PROP_struct;

   /* DVBC_AFC_RANGE property, RANGE_KHZ field definition (NO TITLE)*/
   #define  Si2168_DVBC_AFC_RANGE_PROP_RANGE_KHZ_LSB         0
   #define  Si2168_DVBC_AFC_RANGE_PROP_RANGE_KHZ_MASK        0xffff
   #define  Si2168_DVBC_AFC_RANGE_PROP_RANGE_KHZ_DEFAULT    100
#endif /* Si2168_DVBC_AFC_RANGE_PROP */

/* Si2168 DVBC_CONSTELLATION property definition */
#define   Si2168_DVBC_CONSTELLATION_PROP 0x1101

#ifdef    Si2168_DVBC_CONSTELLATION_PROP
  #define Si2168_DVBC_CONSTELLATION_PROP_CODE 0x001101


    typedef struct { /* Si2168_DVBC_CONSTELLATION_PROP_struct */
      unsigned char   constellation;
   } Si2168_DVBC_CONSTELLATION_PROP_struct;

   /* DVBC_CONSTELLATION property, CONSTELLATION field definition (NO TITLE)*/
   #define  Si2168_DVBC_CONSTELLATION_PROP_CONSTELLATION_LSB         0
   #define  Si2168_DVBC_CONSTELLATION_PROP_CONSTELLATION_MASK        0x3f
   #define  Si2168_DVBC_CONSTELLATION_PROP_CONSTELLATION_DEFAULT    0
    #define Si2168_DVBC_CONSTELLATION_PROP_CONSTELLATION_AUTO    0
    #define Si2168_DVBC_CONSTELLATION_PROP_CONSTELLATION_QAM16   7
    #define Si2168_DVBC_CONSTELLATION_PROP_CONSTELLATION_QAM32   8
    #define Si2168_DVBC_CONSTELLATION_PROP_CONSTELLATION_QAM64   9
    #define Si2168_DVBC_CONSTELLATION_PROP_CONSTELLATION_QAM128  10
    #define Si2168_DVBC_CONSTELLATION_PROP_CONSTELLATION_QAM256  11

#endif /* Si2168_DVBC_CONSTELLATION_PROP */

/* Si2168 DVBC_SYMBOL_RATE property definition */
#define   Si2168_DVBC_SYMBOL_RATE_PROP 0x1102

#ifdef    Si2168_DVBC_SYMBOL_RATE_PROP
  #define Si2168_DVBC_SYMBOL_RATE_PROP_CODE 0x001102


    typedef struct { /* Si2168_DVBC_SYMBOL_RATE_PROP_struct */
      unsigned int    rate;
   } Si2168_DVBC_SYMBOL_RATE_PROP_struct;

   /* DVBC_SYMBOL_RATE property, RATE field definition (NO TITLE)*/
   #define  Si2168_DVBC_SYMBOL_RATE_PROP_RATE_LSB         0
   #define  Si2168_DVBC_SYMBOL_RATE_PROP_RATE_MASK        0xffff
   #define  Si2168_DVBC_SYMBOL_RATE_PROP_RATE_DEFAULT    6800
#endif /* Si2168_DVBC_SYMBOL_RATE_PROP */



/* Si2168 DVBT2_ADC_CREST_FACTOR property definition */
#define   Si2168_DVBT2_ADC_CREST_FACTOR_PROP 0x1303

#ifdef    Si2168_DVBT2_ADC_CREST_FACTOR_PROP
  #define Si2168_DVBT2_ADC_CREST_FACTOR_PROP_CODE 0x001303


    typedef struct { /* Si2168_DVBT2_ADC_CREST_FACTOR_PROP_struct */
      unsigned char   crest_factor;
   } Si2168_DVBT2_ADC_CREST_FACTOR_PROP_struct;

   /* DVBT2_ADC_CREST_FACTOR property, CREST_FACTOR field definition (NO TITLE)*/
   #define  Si2168_DVBT2_ADC_CREST_FACTOR_PROP_CREST_FACTOR_LSB         0
   #define  Si2168_DVBT2_ADC_CREST_FACTOR_PROP_CREST_FACTOR_MASK        0xff
   #define  Si2168_DVBT2_ADC_CREST_FACTOR_PROP_CREST_FACTOR_DEFAULT    130
#endif /* Si2168_DVBT2_ADC_CREST_FACTOR_PROP */

/* Si2168 DVBT2_AFC_RANGE property definition */
#define   Si2168_DVBT2_AFC_RANGE_PROP 0x1301

#ifdef    Si2168_DVBT2_AFC_RANGE_PROP
  #define Si2168_DVBT2_AFC_RANGE_PROP_CODE 0x001301


    typedef struct { /* Si2168_DVBT2_AFC_RANGE_PROP_struct */
      unsigned int    range_khz;
   } Si2168_DVBT2_AFC_RANGE_PROP_struct;

   /* DVBT2_AFC_RANGE property, RANGE_KHZ field definition (NO TITLE)*/
   #define  Si2168_DVBT2_AFC_RANGE_PROP_RANGE_KHZ_LSB         0
   #define  Si2168_DVBT2_AFC_RANGE_PROP_RANGE_KHZ_MASK        0xffff
   #define  Si2168_DVBT2_AFC_RANGE_PROP_RANGE_KHZ_DEFAULT    550
#endif /* Si2168_DVBT2_AFC_RANGE_PROP */

/* Si2168 DVBT2_FEF_TUNER property definition */
#define   Si2168_DVBT2_FEF_TUNER_PROP 0x1302

#ifdef    Si2168_DVBT2_FEF_TUNER_PROP
  #define Si2168_DVBT2_FEF_TUNER_PROP_CODE 0x001302


    typedef struct { /* Si2168_DVBT2_FEF_TUNER_PROP_struct */
      unsigned char   tuner_delay;
      unsigned char   tuner_freeze_time;
      unsigned char   tuner_unfreeze_time;
   } Si2168_DVBT2_FEF_TUNER_PROP_struct;

   /* DVBT2_FEF_TUNER property, TUNER_DELAY field definition (NO TITLE)*/
   #define  Si2168_DVBT2_FEF_TUNER_PROP_TUNER_DELAY_LSB         0
   #define  Si2168_DVBT2_FEF_TUNER_PROP_TUNER_DELAY_MASK        0xff
   #define  Si2168_DVBT2_FEF_TUNER_PROP_TUNER_DELAY_DEFAULT    0
   /* DVBT2_FEF_TUNER property, TUNER_FREEZE_TIME field definition (NO TITLE)*/
   #define  Si2168_DVBT2_FEF_TUNER_PROP_TUNER_FREEZE_TIME_LSB         8
   #define  Si2168_DVBT2_FEF_TUNER_PROP_TUNER_FREEZE_TIME_MASK        0x0f
   #define  Si2168_DVBT2_FEF_TUNER_PROP_TUNER_FREEZE_TIME_DEFAULT    0
   /* DVBT2_FEF_TUNER property, TUNER_UNFREEZE_TIME field definition (NO TITLE)*/
   #define  Si2168_DVBT2_FEF_TUNER_PROP_TUNER_UNFREEZE_TIME_LSB         12
   #define  Si2168_DVBT2_FEF_TUNER_PROP_TUNER_UNFREEZE_TIME_MASK        0x0f
   #define  Si2168_DVBT2_FEF_TUNER_PROP_TUNER_UNFREEZE_TIME_DEFAULT    0
#endif /* Si2168_DVBT2_FEF_TUNER_PROP */


/* Si2168 DVBT_ADC_CREST_FACTOR property definition */
#define   Si2168_DVBT_ADC_CREST_FACTOR_PROP 0x1203

#ifdef    Si2168_DVBT_ADC_CREST_FACTOR_PROP
  #define Si2168_DVBT_ADC_CREST_FACTOR_PROP_CODE 0x001203


    typedef struct { /* Si2168_DVBT_ADC_CREST_FACTOR_PROP_struct */
      unsigned char   crest_factor;
   } Si2168_DVBT_ADC_CREST_FACTOR_PROP_struct;

   /* DVBT_ADC_CREST_FACTOR property, CREST_FACTOR field definition (NO TITLE)*/
   #define  Si2168_DVBT_ADC_CREST_FACTOR_PROP_CREST_FACTOR_LSB         0
   #define  Si2168_DVBT_ADC_CREST_FACTOR_PROP_CREST_FACTOR_MASK        0xff
   #define  Si2168_DVBT_ADC_CREST_FACTOR_PROP_CREST_FACTOR_DEFAULT    130
#endif /* Si2168_DVBT_ADC_CREST_FACTOR_PROP */

/* Si2168 DVBT_AFC_RANGE property definition */
#define   Si2168_DVBT_AFC_RANGE_PROP 0x1202

#ifdef    Si2168_DVBT_AFC_RANGE_PROP
  #define Si2168_DVBT_AFC_RANGE_PROP_CODE 0x001202


    typedef struct { /* Si2168_DVBT_AFC_RANGE_PROP_struct */
      unsigned int    range_khz;
   } Si2168_DVBT_AFC_RANGE_PROP_struct;

   /* DVBT_AFC_RANGE property, RANGE_KHZ field definition (NO TITLE)*/
   #define  Si2168_DVBT_AFC_RANGE_PROP_RANGE_KHZ_LSB         0
   #define  Si2168_DVBT_AFC_RANGE_PROP_RANGE_KHZ_MASK        0xffff
   #define  Si2168_DVBT_AFC_RANGE_PROP_RANGE_KHZ_DEFAULT    550
#endif /* Si2168_DVBT_AFC_RANGE_PROP */

/* Si2168 DVBT_HIERARCHY property definition */
#define   Si2168_DVBT_HIERARCHY_PROP 0x1201

#ifdef    Si2168_DVBT_HIERARCHY_PROP
  #define Si2168_DVBT_HIERARCHY_PROP_CODE 0x001201


    typedef struct { /* Si2168_DVBT_HIERARCHY_PROP_struct */
      unsigned char   stream;
   } Si2168_DVBT_HIERARCHY_PROP_struct;

   /* DVBT_HIERARCHY property, STREAM field definition (NO TITLE)*/
   #define  Si2168_DVBT_HIERARCHY_PROP_STREAM_LSB         0
   #define  Si2168_DVBT_HIERARCHY_PROP_STREAM_MASK        0x01
   #define  Si2168_DVBT_HIERARCHY_PROP_STREAM_DEFAULT    0
    #define Si2168_DVBT_HIERARCHY_PROP_STREAM_HP  0
    #define Si2168_DVBT_HIERARCHY_PROP_STREAM_LP  1

#endif /* Si2168_DVBT_HIERARCHY_PROP */


/* Si2168 MASTER_IEN property definition */
#define   Si2168_MASTER_IEN_PROP 0x0401

#ifdef    Si2168_MASTER_IEN_PROP
  #define Si2168_MASTER_IEN_PROP_CODE 0x000401


    typedef struct { /* Si2168_MASTER_IEN_PROP_struct */
      unsigned char   ctsien;
      unsigned char   ddien;
      unsigned char   errien;
      unsigned char   scanien;
   } Si2168_MASTER_IEN_PROP_struct;

   /* MASTER_IEN property, CTSIEN field definition (NO TITLE)*/
   #define  Si2168_MASTER_IEN_PROP_CTSIEN_LSB         7
   #define  Si2168_MASTER_IEN_PROP_CTSIEN_MASK        0x01
   #define  Si2168_MASTER_IEN_PROP_CTSIEN_DEFAULT    0
    #define Si2168_MASTER_IEN_PROP_CTSIEN_OFF  0
    #define Si2168_MASTER_IEN_PROP_CTSIEN_ON   1

   /* MASTER_IEN property, DDIEN field definition (NO TITLE)*/
   #define  Si2168_MASTER_IEN_PROP_DDIEN_LSB         0
   #define  Si2168_MASTER_IEN_PROP_DDIEN_MASK        0x01
   #define  Si2168_MASTER_IEN_PROP_DDIEN_DEFAULT    0
    #define Si2168_MASTER_IEN_PROP_DDIEN_OFF  0
    #define Si2168_MASTER_IEN_PROP_DDIEN_ON   1

   /* MASTER_IEN property, ERRIEN field definition (NO TITLE)*/
   #define  Si2168_MASTER_IEN_PROP_ERRIEN_LSB         6
   #define  Si2168_MASTER_IEN_PROP_ERRIEN_MASK        0x01
   #define  Si2168_MASTER_IEN_PROP_ERRIEN_DEFAULT    0
    #define Si2168_MASTER_IEN_PROP_ERRIEN_OFF  0
    #define Si2168_MASTER_IEN_PROP_ERRIEN_ON   1

   /* MASTER_IEN property, SCANIEN field definition (NO TITLE)*/
   #define  Si2168_MASTER_IEN_PROP_SCANIEN_LSB         1
   #define  Si2168_MASTER_IEN_PROP_SCANIEN_MASK        0x01
   #define  Si2168_MASTER_IEN_PROP_SCANIEN_DEFAULT    0
    #define Si2168_MASTER_IEN_PROP_SCANIEN_OFF  0
    #define Si2168_MASTER_IEN_PROP_SCANIEN_ON   1

#endif /* Si2168_MASTER_IEN_PROP */

/* Si2168 SCAN_FMAX property definition */
#define   Si2168_SCAN_FMAX_PROP 0x0304

#ifdef    Si2168_SCAN_FMAX_PROP
  #define Si2168_SCAN_FMAX_PROP_CODE 0x000304


    typedef struct { /* Si2168_SCAN_FMAX_PROP_struct */
      unsigned int    scan_fmax;
   } Si2168_SCAN_FMAX_PROP_struct;

   /* SCAN_FMAX property, SCAN_FMAX field definition (NO TITLE)*/
   #define  Si2168_SCAN_FMAX_PROP_SCAN_FMAX_LSB         0
   #define  Si2168_SCAN_FMAX_PROP_SCAN_FMAX_MASK        0xffff
   #define  Si2168_SCAN_FMAX_PROP_SCAN_FMAX_DEFAULT    0
#endif /* Si2168_SCAN_FMAX_PROP */

/* Si2168 SCAN_FMIN property definition */
#define   Si2168_SCAN_FMIN_PROP 0x0303

#ifdef    Si2168_SCAN_FMIN_PROP
  #define Si2168_SCAN_FMIN_PROP_CODE 0x000303


    typedef struct { /* Si2168_SCAN_FMIN_PROP_struct */
      unsigned int    scan_fmin;
   } Si2168_SCAN_FMIN_PROP_struct;

   /* SCAN_FMIN property, SCAN_FMIN field definition (NO TITLE)*/
   #define  Si2168_SCAN_FMIN_PROP_SCAN_FMIN_LSB         0
   #define  Si2168_SCAN_FMIN_PROP_SCAN_FMIN_MASK        0xffff
   #define  Si2168_SCAN_FMIN_PROP_SCAN_FMIN_DEFAULT    0
#endif /* Si2168_SCAN_FMIN_PROP */

/* Si2168 SCAN_IEN property definition */
#define   Si2168_SCAN_IEN_PROP 0x0308

#ifdef    Si2168_SCAN_IEN_PROP
  #define Si2168_SCAN_IEN_PROP_CODE 0x000308


    typedef struct { /* Si2168_SCAN_IEN_PROP_struct */
      unsigned char   buzien;
      unsigned char   reqien;
   } Si2168_SCAN_IEN_PROP_struct;

   /* SCAN_IEN property, BUZIEN field definition (NO TITLE)*/
   #define  Si2168_SCAN_IEN_PROP_BUZIEN_LSB         0
   #define  Si2168_SCAN_IEN_PROP_BUZIEN_MASK        0x01
   #define  Si2168_SCAN_IEN_PROP_BUZIEN_DEFAULT    0
    #define Si2168_SCAN_IEN_PROP_BUZIEN_DISABLE  0
    #define Si2168_SCAN_IEN_PROP_BUZIEN_ENABLE   1

   /* SCAN_IEN property, REQIEN field definition (NO TITLE)*/
   #define  Si2168_SCAN_IEN_PROP_REQIEN_LSB         1
   #define  Si2168_SCAN_IEN_PROP_REQIEN_MASK        0x01
   #define  Si2168_SCAN_IEN_PROP_REQIEN_DEFAULT    0
    #define Si2168_SCAN_IEN_PROP_REQIEN_DISABLE  0
    #define Si2168_SCAN_IEN_PROP_REQIEN_ENABLE   1

#endif /* Si2168_SCAN_IEN_PROP */

/* Si2168 SCAN_INT_SENSE property definition */
#define   Si2168_SCAN_INT_SENSE_PROP 0x0307

#ifdef    Si2168_SCAN_INT_SENSE_PROP
  #define Si2168_SCAN_INT_SENSE_PROP_CODE 0x000307


    typedef struct { /* Si2168_SCAN_INT_SENSE_PROP_struct */
      unsigned char   buznegen;
      unsigned char   buzposen;
      unsigned char   reqnegen;
      unsigned char   reqposen;
   } Si2168_SCAN_INT_SENSE_PROP_struct;

   /* SCAN_INT_SENSE property, BUZNEGEN field definition (NO TITLE)*/
   #define  Si2168_SCAN_INT_SENSE_PROP_BUZNEGEN_LSB         0
   #define  Si2168_SCAN_INT_SENSE_PROP_BUZNEGEN_MASK        0x01
   #define  Si2168_SCAN_INT_SENSE_PROP_BUZNEGEN_DEFAULT    1
    #define Si2168_SCAN_INT_SENSE_PROP_BUZNEGEN_DISABLE  0
    #define Si2168_SCAN_INT_SENSE_PROP_BUZNEGEN_ENABLE   1

   /* SCAN_INT_SENSE property, BUZPOSEN field definition (NO TITLE)*/
   #define  Si2168_SCAN_INT_SENSE_PROP_BUZPOSEN_LSB         8
   #define  Si2168_SCAN_INT_SENSE_PROP_BUZPOSEN_MASK        0x01
   #define  Si2168_SCAN_INT_SENSE_PROP_BUZPOSEN_DEFAULT    0
    #define Si2168_SCAN_INT_SENSE_PROP_BUZPOSEN_DISABLE  0
    #define Si2168_SCAN_INT_SENSE_PROP_BUZPOSEN_ENABLE   1

   /* SCAN_INT_SENSE property, REQNEGEN field definition (NO TITLE)*/
   #define  Si2168_SCAN_INT_SENSE_PROP_REQNEGEN_LSB         1
   #define  Si2168_SCAN_INT_SENSE_PROP_REQNEGEN_MASK        0x01
   #define  Si2168_SCAN_INT_SENSE_PROP_REQNEGEN_DEFAULT    0
    #define Si2168_SCAN_INT_SENSE_PROP_REQNEGEN_DISABLE  0
    #define Si2168_SCAN_INT_SENSE_PROP_REQNEGEN_ENABLE   1

   /* SCAN_INT_SENSE property, REQPOSEN field definition (NO TITLE)*/
   #define  Si2168_SCAN_INT_SENSE_PROP_REQPOSEN_LSB         9
   #define  Si2168_SCAN_INT_SENSE_PROP_REQPOSEN_MASK        0x01
   #define  Si2168_SCAN_INT_SENSE_PROP_REQPOSEN_DEFAULT    1
    #define Si2168_SCAN_INT_SENSE_PROP_REQPOSEN_DISABLE  0
    #define Si2168_SCAN_INT_SENSE_PROP_REQPOSEN_ENABLE   1

#endif /* Si2168_SCAN_INT_SENSE_PROP */


/* Si2168 SCAN_SYMB_RATE_MAX property definition */
#define   Si2168_SCAN_SYMB_RATE_MAX_PROP 0x0306

#ifdef    Si2168_SCAN_SYMB_RATE_MAX_PROP
  #define Si2168_SCAN_SYMB_RATE_MAX_PROP_CODE 0x000306


    typedef struct { /* Si2168_SCAN_SYMB_RATE_MAX_PROP_struct */
      unsigned int    scan_symb_rate_max;
   } Si2168_SCAN_SYMB_RATE_MAX_PROP_struct;

   /* SCAN_SYMB_RATE_MAX property, SCAN_SYMB_RATE_MAX field definition (NO TITLE)*/
   #define  Si2168_SCAN_SYMB_RATE_MAX_PROP_SCAN_SYMB_RATE_MAX_LSB         0
   #define  Si2168_SCAN_SYMB_RATE_MAX_PROP_SCAN_SYMB_RATE_MAX_MASK        0xffff
   #define  Si2168_SCAN_SYMB_RATE_MAX_PROP_SCAN_SYMB_RATE_MAX_DEFAULT    0
#endif /* Si2168_SCAN_SYMB_RATE_MAX_PROP */

/* Si2168 SCAN_SYMB_RATE_MIN property definition */
#define   Si2168_SCAN_SYMB_RATE_MIN_PROP 0x0305

#ifdef    Si2168_SCAN_SYMB_RATE_MIN_PROP
  #define Si2168_SCAN_SYMB_RATE_MIN_PROP_CODE 0x000305


    typedef struct { /* Si2168_SCAN_SYMB_RATE_MIN_PROP_struct */
      unsigned int    scan_symb_rate_min;
   } Si2168_SCAN_SYMB_RATE_MIN_PROP_struct;

   /* SCAN_SYMB_RATE_MIN property, SCAN_SYMB_RATE_MIN field definition (NO TITLE)*/
   #define  Si2168_SCAN_SYMB_RATE_MIN_PROP_SCAN_SYMB_RATE_MIN_LSB         0
   #define  Si2168_SCAN_SYMB_RATE_MIN_PROP_SCAN_SYMB_RATE_MIN_MASK        0xffff
   #define  Si2168_SCAN_SYMB_RATE_MIN_PROP_SCAN_SYMB_RATE_MIN_DEFAULT    0
#endif /* Si2168_SCAN_SYMB_RATE_MIN_PROP */

/* Si2168 SCAN_TER_CONFIG property definition */
#define   Si2168_SCAN_TER_CONFIG_PROP 0x0301

#ifdef    Si2168_SCAN_TER_CONFIG_PROP
  #define Si2168_SCAN_TER_CONFIG_PROP_CODE 0x000301


    typedef struct { /* Si2168_SCAN_TER_CONFIG_PROP_struct */
      unsigned char   analog_bw;
      unsigned char   mode;
      unsigned char   search_analog;
   } Si2168_SCAN_TER_CONFIG_PROP_struct;

   /* SCAN_TER_CONFIG property, ANALOG_BW field definition (NO TITLE)*/
   #define  Si2168_SCAN_TER_CONFIG_PROP_ANALOG_BW_LSB         2
   #define  Si2168_SCAN_TER_CONFIG_PROP_ANALOG_BW_MASK        0x03
   #define  Si2168_SCAN_TER_CONFIG_PROP_ANALOG_BW_DEFAULT    3
    #define Si2168_SCAN_TER_CONFIG_PROP_ANALOG_BW_6MHZ  1
    #define Si2168_SCAN_TER_CONFIG_PROP_ANALOG_BW_7MHZ  2
    #define Si2168_SCAN_TER_CONFIG_PROP_ANALOG_BW_8MHZ  3

   /* SCAN_TER_CONFIG property, MODE field definition (NO TITLE)*/
   #define  Si2168_SCAN_TER_CONFIG_PROP_MODE_LSB         0
   #define  Si2168_SCAN_TER_CONFIG_PROP_MODE_MASK        0x03
   #define  Si2168_SCAN_TER_CONFIG_PROP_MODE_DEFAULT    0
    #define Si2168_SCAN_TER_CONFIG_PROP_MODE_BLIND_SCAN    0
    #define Si2168_SCAN_TER_CONFIG_PROP_MODE_MAPPING_SCAN  1
    #define Si2168_SCAN_TER_CONFIG_PROP_MODE_BLIND_LOCK    2

   /* SCAN_TER_CONFIG property, SEARCH_ANALOG field definition (NO TITLE)*/
   #define  Si2168_SCAN_TER_CONFIG_PROP_SEARCH_ANALOG_LSB         4
   #define  Si2168_SCAN_TER_CONFIG_PROP_SEARCH_ANALOG_MASK        0x01
   #define  Si2168_SCAN_TER_CONFIG_PROP_SEARCH_ANALOG_DEFAULT    0
    #define Si2168_SCAN_TER_CONFIG_PROP_SEARCH_ANALOG_DISABLE  0
    #define Si2168_SCAN_TER_CONFIG_PROP_SEARCH_ANALOG_ENABLE   1

#endif /* Si2168_SCAN_TER_CONFIG_PROP */

typedef struct
{
	#ifdef    Si2168_DD_BER_RESOL_PROP
			  Si2168_DD_BER_RESOL_PROP_struct            dd_ber_resol;
	#endif /* Si2168_DD_BER_RESOL_PROP */
	#ifdef    Si2168_DD_CBER_RESOL_PROP
			  Si2168_DD_CBER_RESOL_PROP_struct           dd_cber_resol;
	#endif /* Si2168_DD_CBER_RESOL_PROP */

	#ifdef    Si2168_DD_FER_RESOL_PROP
			  Si2168_DD_FER_RESOL_PROP_struct            dd_fer_resol;
	#endif /* Si2168_DD_FER_RESOL_PROP */
	#ifdef    Si2168_DD_IEN_PROP
			  Si2168_DD_IEN_PROP_struct                  dd_ien;
	#endif /* Si2168_DD_IEN_PROP */
	#ifdef    Si2168_DD_IF_INPUT_FREQ_PROP
			  Si2168_DD_IF_INPUT_FREQ_PROP_struct        dd_if_input_freq;
	#endif /* Si2168_DD_IF_INPUT_FREQ_PROP */
	#ifdef    Si2168_DD_INT_SENSE_PROP
			  Si2168_DD_INT_SENSE_PROP_struct            dd_int_sense;
	#endif /* Si2168_DD_INT_SENSE_PROP */
	#ifdef    Si2168_DD_MODE_PROP
			  Si2168_DD_MODE_PROP_struct                 dd_mode;
	#endif /* Si2168_DD_MODE_PROP */
	#ifdef    Si2168_DD_PER_RESOL_PROP
			  Si2168_DD_PER_RESOL_PROP_struct            dd_per_resol;
	#endif /* Si2168_DD_PER_RESOL_PROP */
	#ifdef    Si2168_DD_RSQ_BER_THRESHOLD_PROP
			  Si2168_DD_RSQ_BER_THRESHOLD_PROP_struct    dd_rsq_ber_threshold;
	#endif /* Si2168_DD_RSQ_BER_THRESHOLD_PROP */
	#ifdef    Si2168_DD_SSI_SQI_PARAM_PROP
			  Si2168_DD_SSI_SQI_PARAM_PROP_struct        dd_ssi_sqi_param;
	#endif /* Si2168_DD_SSI_SQI_PARAM_PROP */
	#ifdef    Si2168_DD_TS_FREQ_PROP
			  Si2168_DD_TS_FREQ_PROP_struct              dd_ts_freq;
	#endif /* Si2168_DD_TS_FREQ_PROP */
	#ifdef    Si2168_DD_TS_MODE_PROP
			  Si2168_DD_TS_MODE_PROP_struct              dd_ts_mode;
	#endif /* Si2168_DD_TS_MODE_PROP */
	#ifdef    Si2168_DD_TS_SETUP_PAR_PROP
			  Si2168_DD_TS_SETUP_PAR_PROP_struct         dd_ts_setup_par;
	#endif /* Si2168_DD_TS_SETUP_PAR_PROP */
	#ifdef    Si2168_DD_TS_SETUP_SER_PROP
			  Si2168_DD_TS_SETUP_SER_PROP_struct         dd_ts_setup_ser;
	#endif /* Si2168_DD_TS_SETUP_SER_PROP */
	#ifdef    Si2168_DVBC_ADC_CREST_FACTOR_PROP
			  Si2168_DVBC_ADC_CREST_FACTOR_PROP_struct   dvbc_adc_crest_factor;
	#endif /* Si2168_DVBC_ADC_CREST_FACTOR_PROP */
	#ifdef    Si2168_DVBC_AFC_RANGE_PROP
			  Si2168_DVBC_AFC_RANGE_PROP_struct          dvbc_afc_range;
	#endif /* Si2168_DVBC_AFC_RANGE_PROP */
	#ifdef    Si2168_DVBC_CONSTELLATION_PROP
			  Si2168_DVBC_CONSTELLATION_PROP_struct      dvbc_constellation;
	#endif /* Si2168_DVBC_CONSTELLATION_PROP */
	#ifdef    Si2168_DVBC_SYMBOL_RATE_PROP
			  Si2168_DVBC_SYMBOL_RATE_PROP_struct        dvbc_symbol_rate;
	#endif /* Si2168_DVBC_SYMBOL_RATE_PROP */


	#ifdef    Si2168_DVBT2_ADC_CREST_FACTOR_PROP
			  Si2168_DVBT2_ADC_CREST_FACTOR_PROP_struct  dvbt2_adc_crest_factor;
	#endif /* Si2168_DVBT2_ADC_CREST_FACTOR_PROP */
	#ifdef    Si2168_DVBT2_AFC_RANGE_PROP
			  Si2168_DVBT2_AFC_RANGE_PROP_struct         dvbt2_afc_range;
	#endif /* Si2168_DVBT2_AFC_RANGE_PROP */
	#ifdef    Si2168_DVBT2_FEF_TUNER_PROP
			  Si2168_DVBT2_FEF_TUNER_PROP_struct         dvbt2_fef_tuner;
	#endif /* Si2168_DVBT2_FEF_TUNER_PROP */

	#ifdef    Si2168_DVBT_ADC_CREST_FACTOR_PROP
			  Si2168_DVBT_ADC_CREST_FACTOR_PROP_struct   dvbt_adc_crest_factor;
	#endif /* Si2168_DVBT_ADC_CREST_FACTOR_PROP */
	#ifdef    Si2168_DVBT_AFC_RANGE_PROP
			  Si2168_DVBT_AFC_RANGE_PROP_struct          dvbt_afc_range;
	#endif /* Si2168_DVBT_AFC_RANGE_PROP */
	#ifdef    Si2168_DVBT_HIERARCHY_PROP
			  Si2168_DVBT_HIERARCHY_PROP_struct          dvbt_hierarchy;
	#endif /* Si2168_DVBT_HIERARCHY_PROP */

	#ifdef    Si2168_MASTER_IEN_PROP
			  Si2168_MASTER_IEN_PROP_struct              master_ien;
	#endif /* Si2168_MASTER_IEN_PROP */
	#ifdef    Si2168_SCAN_FMAX_PROP
			  Si2168_SCAN_FMAX_PROP_struct               scan_fmax;
	#endif /* Si2168_SCAN_FMAX_PROP */
	#ifdef    Si2168_SCAN_FMIN_PROP
			  Si2168_SCAN_FMIN_PROP_struct               scan_fmin;
	#endif /* Si2168_SCAN_FMIN_PROP */
	#ifdef    Si2168_SCAN_IEN_PROP
			  Si2168_SCAN_IEN_PROP_struct                scan_ien;
	#endif /* Si2168_SCAN_IEN_PROP */
	#ifdef    Si2168_SCAN_INT_SENSE_PROP
			  Si2168_SCAN_INT_SENSE_PROP_struct          scan_int_sense;
	#endif /* Si2168_SCAN_INT_SENSE_PROP */

	#ifdef    Si2168_SCAN_SYMB_RATE_MAX_PROP
			  Si2168_SCAN_SYMB_RATE_MAX_PROP_struct      scan_symb_rate_max;
	#endif /* Si2168_SCAN_SYMB_RATE_MAX_PROP */
	#ifdef    Si2168_SCAN_SYMB_RATE_MIN_PROP
			  Si2168_SCAN_SYMB_RATE_MIN_PROP_struct      scan_symb_rate_min;
	#endif /* Si2168_SCAN_SYMB_RATE_MIN_PROP */
	#ifdef    Si2168_SCAN_TER_CONFIG_PROP
			  Si2168_SCAN_TER_CONFIG_PROP_struct         scan_ter_config;
	#endif /* Si2168_SCAN_TER_CONFIG_PROP */
} Si2168_PropObj;

typedef struct L1_Si2168_Context
{
	L0_Context                 *i2c;
	L0_Context                  i2cObj;
	Si2168_CmdObj              *cmd;
	Si2168_CmdObj               cmdObj;
	Si2168_CmdReplyObj         *rsp;
	Si2168_CmdReplyObj          rspObj;
	Si2168_PropObj             *prop;
	Si2168_PropObj              propObj;
	Si2168_COMMON_REPLY_struct *status;
	Si2168_COMMON_REPLY_struct  statusObj;
	int                         standard;
	int                         media;
	unsigned int  tuner_rssi;
	unsigned char addr;
} L1_Si2168_Context;

typedef struct
{ // Si2146_COMMON_REPLY_struct
	unsigned char   tunint;
	unsigned char   atvint;
	unsigned char   dtvint;
	unsigned char   err;
	unsigned char   cts;
} Si2146_COMMON_REPLY_struct;

typedef struct
{ // Si2148_COMMON_REPLY_struct
	unsigned char   tunint;
	unsigned char   atvint;
	unsigned char   dtvint;
	unsigned char   err;
	unsigned char   cts;
} Si2148_COMMON_REPLY_struct;

#define   Si2146_SET_PROPERTY_CMD 0x14

#ifdef Si2146_SET_PROPERTY_CMD
	#define Si2146_SET_PROPERTY_CMD_CODE 0x010014
    typedef struct
	{ // Si2146_SET_PROPERTY_CMD_struct
		unsigned char   reserved;
		unsigned int    prop;
		unsigned int    data;
	} Si2146_SET_PROPERTY_CMD_struct;
	typedef struct
	{ // Si2146_SET_PROPERTY_CMD_REPLY_struct
		Si2146_COMMON_REPLY_struct * STATUS;
		unsigned char   reserved;
		unsigned int    data;
	} Si2146_SET_PROPERTY_CMD_REPLY_struct;
	// SET_PROPERTY command, RESERVED field definition (address 1,size 8, lsb 0, unsigned)
	#define  Si2146_SET_PROPERTY_CMD_RESERVED_LSB         0
	#define  Si2146_SET_PROPERTY_CMD_RESERVED_MASK        0xff
	#define  Si2146_SET_PROPERTY_CMD_RESERVED_MIN         0
	#define  Si2146_SET_PROPERTY_CMD_RESERVED_MAX         255.0
	// SET_PROPERTY command, PROP field definition (address 2,size 16, lsb 0, unsigned)
	#define  Si2146_SET_PROPERTY_CMD_PROP_LSB         0
	#define  Si2146_SET_PROPERTY_CMD_PROP_MASK        0xffff
	#define  Si2146_SET_PROPERTY_CMD_PROP_MIN         0
	#define  Si2146_SET_PROPERTY_CMD_PROP_MAX         65535
	#define Si2146_SET_PROPERTY_CMD_PROP_PROP_MIN  0
	#define Si2146_SET_PROPERTY_CMD_PROP_PROP_MAX  65535
	// SET_PROPERTY command, DATA field definition (address 4,size 16, lsb 0, unsigned)
	#define  Si2146_SET_PROPERTY_CMD_DATA_LSB         0
	#define  Si2146_SET_PROPERTY_CMD_DATA_MASK        0xffff
	#define  Si2146_SET_PROPERTY_CMD_DATA_MIN         0
	#define  Si2146_SET_PROPERTY_CMD_DATA_MAX         65535
	#define Si2146_SET_PROPERTY_CMD_DATA_DATA_MIN  0
	#define Si2146_SET_PROPERTY_CMD_DATA_DATA_MAX  65535
	// SET_PROPERTY command, RESERVED field definition (address 1, size 8, lsb 0, unsigned)
	#define  Si2146_SET_PROPERTY_RESPONSE_RESERVED_LSB         0
	#define  Si2146_SET_PROPERTY_RESPONSE_RESERVED_MASK        0xff
	#define Si2146_SET_PROPERTY_RESPONSE_RESERVED_RESERVED_MIN  0
	#define Si2146_SET_PROPERTY_RESPONSE_RESERVED_RESERVED_MAX  0
	// SET_PROPERTY command, DATA field definition (address 2, size 16, lsb 0, unsigned)
	#define  Si2146_SET_PROPERTY_RESPONSE_DATA_LSB         0
	#define  Si2146_SET_PROPERTY_RESPONSE_DATA_MASK        0xffff
#endif // Si2146_SET_PROPERTY_CMD

// Si2146_TUNER_STATUS command definition
#define   Si2146_TUNER_STATUS_CMD 0x42

#ifdef    Si2146_TUNER_STATUS_CMD
  #define Si2146_TUNER_STATUS_CMD_CODE 0x010042

    typedef struct { /* Si2146_TUNER_STATUS_CMD_struct */
     unsigned char   intack;
   } Si2146_TUNER_STATUS_CMD_struct;


    typedef struct { /* Si2146_TUNER_STATUS_CMD_REPLY_struct */
       Si2146_COMMON_REPLY_struct * STATUS;
      unsigned char   tcint;
      unsigned char   rssilint;
      unsigned char   rssihint;
               int    vco_code;
      unsigned char   tc;
      unsigned char   rssil;
      unsigned char   rssih;
               char   rssi;
      unsigned long   freq;
      unsigned char   mode;
   }  Si2146_TUNER_STATUS_CMD_REPLY_struct;

   /* TUNER_STATUS command, INTACK field definition (address 1,size 1, lsb 0, unsigned) */
   #define  Si2146_TUNER_STATUS_CMD_INTACK_LSB         0
   #define  Si2146_TUNER_STATUS_CMD_INTACK_MASK        0x01
   #define  Si2146_TUNER_STATUS_CMD_INTACK_MIN         0
   #define  Si2146_TUNER_STATUS_CMD_INTACK_MAX         1
    #define Si2146_TUNER_STATUS_CMD_INTACK_CLEAR  1
    #define Si2146_TUNER_STATUS_CMD_INTACK_OK     0
   /* TUNER_STATUS command, TCINT field definition (address 1, size 1, lsb 0, unsigned)*/
   #define  Si2146_TUNER_STATUS_RESPONSE_TCINT_LSB         0
   #define  Si2146_TUNER_STATUS_RESPONSE_TCINT_MASK        0x01
    #define Si2146_TUNER_STATUS_RESPONSE_TCINT_CHANGED    1
    #define Si2146_TUNER_STATUS_RESPONSE_TCINT_NO_CHANGE  0
   /* TUNER_STATUS command, RSSILINT field definition (address 1, size 1, lsb 1, unsigned)*/
   #define  Si2146_TUNER_STATUS_RESPONSE_RSSILINT_LSB         1
   #define  Si2146_TUNER_STATUS_RESPONSE_RSSILINT_MASK        0x01
    #define Si2146_TUNER_STATUS_RESPONSE_RSSILINT_CHANGED    1
    #define Si2146_TUNER_STATUS_RESPONSE_RSSILINT_NO_CHANGE  0
   /* TUNER_STATUS command, RSSIHINT field definition (address 1, size 1, lsb 2, unsigned)*/
   #define  Si2146_TUNER_STATUS_RESPONSE_RSSIHINT_LSB         2
   #define  Si2146_TUNER_STATUS_RESPONSE_RSSIHINT_MASK        0x01
    #define Si2146_TUNER_STATUS_RESPONSE_RSSIHINT_CHANGED    1
    #define Si2146_TUNER_STATUS_RESPONSE_RSSIHINT_NO_CHANGE  0
   /* TUNER_STATUS command, VCO_CODE field definition (address 10, size 16, lsb 0, signed)*/
   #define  Si2146_TUNER_STATUS_RESPONSE_VCO_CODE_LSB         0
   #define  Si2146_TUNER_STATUS_RESPONSE_VCO_CODE_MASK        0xffff
   #define  Si2146_TUNER_STATUS_RESPONSE_VCO_CODE_SHIFT       16
   /* TUNER_STATUS command, TC field definition (address 2, size 1, lsb 0, unsigned)*/
   #define  Si2146_TUNER_STATUS_RESPONSE_TC_LSB         0
   #define  Si2146_TUNER_STATUS_RESPONSE_TC_MASK        0x01
    #define Si2146_TUNER_STATUS_RESPONSE_TC_BUSY  0
    #define Si2146_TUNER_STATUS_RESPONSE_TC_DONE  1
   /* TUNER_STATUS command, RSSIL field definition (address 2, size 1, lsb 1, unsigned)*/
   #define  Si2146_TUNER_STATUS_RESPONSE_RSSIL_LSB         1
   #define  Si2146_TUNER_STATUS_RESPONSE_RSSIL_MASK        0x01
    #define Si2146_TUNER_STATUS_RESPONSE_RSSIL_LOW  1
    #define Si2146_TUNER_STATUS_RESPONSE_RSSIL_OK   0
   /* TUNER_STATUS command, RSSIH field definition (address 2, size 1, lsb 2, unsigned)*/
   #define  Si2146_TUNER_STATUS_RESPONSE_RSSIH_LSB         2
   #define  Si2146_TUNER_STATUS_RESPONSE_RSSIH_MASK        0x01
    #define Si2146_TUNER_STATUS_RESPONSE_RSSIH_HIGH  1
    #define Si2146_TUNER_STATUS_RESPONSE_RSSIH_OK    0
   /* TUNER_STATUS command, RSSI field definition (address 3, size 8, lsb 0, signed)*/
   #define  Si2146_TUNER_STATUS_RESPONSE_RSSI_LSB         0
   #define  Si2146_TUNER_STATUS_RESPONSE_RSSI_MASK        0xff
   #define  Si2146_TUNER_STATUS_RESPONSE_RSSI_SHIFT       24
   /* TUNER_STATUS command, FREQ field definition (address 4, size 32, lsb 0, unsigned)*/
   #define  Si2146_TUNER_STATUS_RESPONSE_FREQ_LSB         0
   #define  Si2146_TUNER_STATUS_RESPONSE_FREQ_MASK        0xffffffff
   /* TUNER_STATUS command, MODE field definition (address 8, size 1, lsb 0, unsigned)*/
   #define  Si2146_TUNER_STATUS_RESPONSE_MODE_LSB         0
   #define  Si2146_TUNER_STATUS_RESPONSE_MODE_MASK        0x01
    #define Si2146_TUNER_STATUS_RESPONSE_MODE_ATV  1
    #define Si2146_TUNER_STATUS_RESPONSE_MODE_DTV  0

#endif /* Si2146_TUNER_STATUS_CMD */

#define   Si2146_TUNER_TUNE_FREQ_CMD 0x41

#ifdef    Si2146_TUNER_TUNE_FREQ_CMD
  #define Si2146_TUNER_TUNE_FREQ_CMD_CODE 0x010041

    typedef struct { /* Si2146_TUNER_TUNE_FREQ_CMD_struct */
     unsigned char   mode;
     unsigned long   freq;
   } Si2146_TUNER_TUNE_FREQ_CMD_struct;


    typedef struct { /* Si2146_TUNER_TUNE_FREQ_CMD_REPLY_struct */
       Si2146_COMMON_REPLY_struct * STATUS;
   }  Si2146_TUNER_TUNE_FREQ_CMD_REPLY_struct;

   /* TUNER_TUNE_FREQ command, MODE field definition (address 1,size 1, lsb 0, unsigned) */
   #define  Si2146_TUNER_TUNE_FREQ_CMD_MODE_LSB         0
   #define  Si2146_TUNER_TUNE_FREQ_CMD_MODE_MASK        0x01
   #define  Si2146_TUNER_TUNE_FREQ_CMD_MODE_MIN         0
   #define  Si2146_TUNER_TUNE_FREQ_CMD_MODE_MAX         1
    #define Si2146_TUNER_TUNE_FREQ_CMD_MODE_ATV  1
    #define Si2146_TUNER_TUNE_FREQ_CMD_MODE_DTV  0
   /* TUNER_TUNE_FREQ command, FREQ field definition (address 4,size 32, lsb 0, unsigned) */
   #define  Si2146_TUNER_TUNE_FREQ_CMD_FREQ_LSB         0
   #define  Si2146_TUNER_TUNE_FREQ_CMD_FREQ_MASK        0xffffffff
   #define  Si2146_TUNER_TUNE_FREQ_CMD_FREQ_MIN         40000000
   #define  Si2146_TUNER_TUNE_FREQ_CMD_FREQ_MAX         1002000000
    #define Si2146_TUNER_TUNE_FREQ_CMD_FREQ_FREQ_MIN  40000000
    #define Si2146_TUNER_TUNE_FREQ_CMD_FREQ_FREQ_MAX  1002000000
#endif /* Si2146_TUNER_TUNE_FREQ_CMD */

#define   Si2146_POWER_UP_CMD 0xc0

#ifdef    Si2146_POWER_UP_CMD
  #define Si2146_POWER_UP_CMD_CODE 0x0100c0

    typedef struct { /* Si2146_POWER_UP_CMD_struct */
     unsigned char   subcode;
     unsigned char   reserved1;
     unsigned char   reserved2;
     unsigned char   reserved3;
     unsigned char   clock_mode;
     unsigned char   clock_freq;
     unsigned char   addr_mode;
     unsigned char   func;
     unsigned char   ctsien;
     unsigned char   wake_up;
   } Si2146_POWER_UP_CMD_struct;


    typedef struct { /* Si2146_POWER_UP_CMD_REPLY_struct */
       Si2146_COMMON_REPLY_struct * STATUS;
   }  Si2146_POWER_UP_CMD_REPLY_struct;

   /* POWER_UP command, SUBCODE field definition (address 1,size 8, lsb 0, unsigned) */
   #define  Si2146_POWER_UP_CMD_SUBCODE_LSB         0
   #define  Si2146_POWER_UP_CMD_SUBCODE_MASK        0xff
   #define  Si2146_POWER_UP_CMD_SUBCODE_MIN         5
   #define  Si2146_POWER_UP_CMD_SUBCODE_MAX         5
    #define Si2146_POWER_UP_CMD_SUBCODE_CODE  5
   /* POWER_UP command, RESERVED1 field definition (address 2,size 8, lsb 0, unsigned) */
   #define  Si2146_POWER_UP_CMD_RESERVED1_LSB         0
   #define  Si2146_POWER_UP_CMD_RESERVED1_MASK        0xff
   #define  Si2146_POWER_UP_CMD_RESERVED1_MIN         1
   #define  Si2146_POWER_UP_CMD_RESERVED1_MAX         1
    #define Si2146_POWER_UP_CMD_RESERVED1_RESERVED  1
   /* POWER_UP command, RESERVED2 field definition (address 3,size 8, lsb 0, unsigned) */
   #define  Si2146_POWER_UP_CMD_RESERVED2_LSB         0
   #define  Si2146_POWER_UP_CMD_RESERVED2_MASK        0xff
   #define  Si2146_POWER_UP_CMD_RESERVED2_MIN         0
   #define  Si2146_POWER_UP_CMD_RESERVED2_MAX         0
    #define Si2146_POWER_UP_CMD_RESERVED2_RESERVED  0
   /* POWER_UP command, RESERVED3 field definition (address 4,size 8, lsb 0, unsigned) */
   #define  Si2146_POWER_UP_CMD_RESERVED3_LSB         0
   #define  Si2146_POWER_UP_CMD_RESERVED3_MASK        0xff
   #define  Si2146_POWER_UP_CMD_RESERVED3_MIN         0
   #define  Si2146_POWER_UP_CMD_RESERVED3_MAX         0
    #define Si2146_POWER_UP_CMD_RESERVED3_RESERVED  0
   /* POWER_UP command, CLOCK_MODE field definition (address 5,size 2, lsb 0, unsigned) */
   #define  Si2146_POWER_UP_CMD_CLOCK_MODE_LSB         0
   #define  Si2146_POWER_UP_CMD_CLOCK_MODE_MASK        0x03
   #define  Si2146_POWER_UP_CMD_CLOCK_MODE_MIN         1
   #define  Si2146_POWER_UP_CMD_CLOCK_MODE_MAX         3
    #define Si2146_POWER_UP_CMD_CLOCK_MODE_EXTCLK  1
    #define Si2146_POWER_UP_CMD_CLOCK_MODE_XTAL    3
   /* POWER_UP command, CLOCK_FREQ field definition (address 5,size 2, lsb 2, unsigned) */
   #define  Si2146_POWER_UP_CMD_CLOCK_FREQ_LSB         2
   #define  Si2146_POWER_UP_CMD_CLOCK_FREQ_MASK        0x03
   #define  Si2146_POWER_UP_CMD_CLOCK_FREQ_MIN         0
   #define  Si2146_POWER_UP_CMD_CLOCK_FREQ_MAX         2
    #define Si2146_POWER_UP_CMD_CLOCK_FREQ_CLK_24MHZ  2
   /* POWER_UP command, ADDR_MODE field definition (address 6,size 1, lsb 4, unsigned) */
   #define  Si2146_POWER_UP_CMD_ADDR_MODE_LSB         4
   #define  Si2146_POWER_UP_CMD_ADDR_MODE_MASK        0x01
   #define  Si2146_POWER_UP_CMD_ADDR_MODE_MIN         0
   #define  Si2146_POWER_UP_CMD_ADDR_MODE_MAX         1
    #define Si2146_POWER_UP_CMD_ADDR_MODE_CAPTURE  1
    #define Si2146_POWER_UP_CMD_ADDR_MODE_CURRENT  0
   /* POWER_UP command, FUNC field definition (address 7,size 4, lsb 0, unsigned) */
   #define  Si2146_POWER_UP_CMD_FUNC_LSB         0
   #define  Si2146_POWER_UP_CMD_FUNC_MASK        0x0f
   #define  Si2146_POWER_UP_CMD_FUNC_MIN         0
   #define  Si2146_POWER_UP_CMD_FUNC_MAX         1
    #define Si2146_POWER_UP_CMD_FUNC_BOOTLOADER  0
    #define Si2146_POWER_UP_CMD_FUNC_NORMAL      1
   /* POWER_UP command, CTSIEN field definition (address 7,size 1, lsb 7, unsigned) */
   #define  Si2146_POWER_UP_CMD_CTSIEN_LSB         7
   #define  Si2146_POWER_UP_CMD_CTSIEN_MASK        0x01
   #define  Si2146_POWER_UP_CMD_CTSIEN_MIN         0
   #define  Si2146_POWER_UP_CMD_CTSIEN_MAX         1
    #define Si2146_POWER_UP_CMD_CTSIEN_DISABLE  0
    #define Si2146_POWER_UP_CMD_CTSIEN_ENABLE   1
   /* POWER_UP command, WAKE_UP field definition (address 8,size 1, lsb 0, unsigned) */
   #define  Si2146_POWER_UP_CMD_WAKE_UP_LSB         0
   #define  Si2146_POWER_UP_CMD_WAKE_UP_MASK        0x01
   #define  Si2146_POWER_UP_CMD_WAKE_UP_MIN         1
   #define  Si2146_POWER_UP_CMD_WAKE_UP_MAX         1
    #define Si2146_POWER_UP_CMD_WAKE_UP_WAKE_UP  1
#endif /* Si2146_POWER_UP_CMD */

#define   Si2146_PART_INFO_CMD 0x02

#ifdef    Si2146_PART_INFO_CMD
  #define Si2146_PART_INFO_CMD_CODE 0x010002

    typedef struct { /* Si2146_PART_INFO_CMD_struct */
         unsigned char   nothing;   } Si2146_PART_INFO_CMD_struct;


    typedef struct { /* Si2146_PART_INFO_CMD_REPLY_struct */
       Si2146_COMMON_REPLY_struct * STATUS;
      unsigned char   chiprev;
      unsigned char   romid;
      unsigned char   part;
      unsigned char   pmajor;
      unsigned char   pminor;
      unsigned char   pbuild;
      unsigned int    reserved;
      unsigned long   serial;
   }  Si2146_PART_INFO_CMD_REPLY_struct;

   /* PART_INFO command, CHIPREV field definition (address 1, size 4, lsb 0, unsigned)*/
   #define  Si2146_PART_INFO_RESPONSE_CHIPREV_LSB         0
   #define  Si2146_PART_INFO_RESPONSE_CHIPREV_MASK        0x0f
    #define Si2146_PART_INFO_RESPONSE_CHIPREV_A  1
    #define Si2146_PART_INFO_RESPONSE_CHIPREV_B  2
   /* PART_INFO command, ROMID field definition (address 12, size 8, lsb 0, unsigned)*/
   #define  Si2146_PART_INFO_RESPONSE_ROMID_LSB         0
   #define  Si2146_PART_INFO_RESPONSE_ROMID_MASK        0xff
   /* PART_INFO command, PART field definition (address 2, size 8, lsb 0, unsigned)*/
   #define  Si2146_PART_INFO_RESPONSE_PART_LSB         0
   #define  Si2146_PART_INFO_RESPONSE_PART_MASK        0xff
   /* PART_INFO command, PMAJOR field definition (address 3, size 8, lsb 0, unsigned)*/
   #define  Si2146_PART_INFO_RESPONSE_PMAJOR_LSB         0
   #define  Si2146_PART_INFO_RESPONSE_PMAJOR_MASK        0xff
   /* PART_INFO command, PMINOR field definition (address 4, size 8, lsb 0, unsigned)*/
   #define  Si2146_PART_INFO_RESPONSE_PMINOR_LSB         0
   #define  Si2146_PART_INFO_RESPONSE_PMINOR_MASK        0xff
   /* PART_INFO command, PBUILD field definition (address 5, size 8, lsb 0, unsigned)*/
   #define  Si2146_PART_INFO_RESPONSE_PBUILD_LSB         0
   #define  Si2146_PART_INFO_RESPONSE_PBUILD_MASK        0xff
   /* PART_INFO command, RESERVED field definition (address 6, size 16, lsb 0, unsigned)*/
   #define  Si2146_PART_INFO_RESPONSE_RESERVED_LSB         0
   #define  Si2146_PART_INFO_RESPONSE_RESERVED_MASK        0xffff
   /* PART_INFO command, SERIAL field definition (address 8, size 32, lsb 0, unsigned)*/
   #define  Si2146_PART_INFO_RESPONSE_SERIAL_LSB         0
   #define  Si2146_PART_INFO_RESPONSE_SERIAL_MASK        0xffffffff

#endif /* Si2146_PART_INFO_CMD */

/* Si2146_DTV_STATUS command definition */
#define   Si2146_DTV_STATUS_CMD 0x62

#ifdef    Si2146_DTV_STATUS_CMD
	#define Si2146_DTV_STATUS_CMD_CODE 0x010062

	typedef struct { /* Si2146_DTV_STATUS_CMD_struct */
	 unsigned char   intack;
	} Si2146_DTV_STATUS_CMD_struct;

	typedef struct { /* Si2146_DTV_STATUS_CMD_REPLY_struct */
	   Si2146_COMMON_REPLY_struct * STATUS;
	  unsigned char   chlint;
	  unsigned char   chl;
	  unsigned char   bw;
	  unsigned char   modulation;
	}  Si2146_DTV_STATUS_CMD_REPLY_struct;

	/* DTV_STATUS command, INTACK field definition (address 1,size 1, lsb 0, unsigned) */
	#define  Si2146_DTV_STATUS_CMD_INTACK_LSB         0
	#define  Si2146_DTV_STATUS_CMD_INTACK_MASK        0x01
	#define  Si2146_DTV_STATUS_CMD_INTACK_MIN         0
	#define  Si2146_DTV_STATUS_CMD_INTACK_MAX         1
	#define Si2146_DTV_STATUS_CMD_INTACK_CLEAR  1
	#define Si2146_DTV_STATUS_CMD_INTACK_OK     0
	/* DTV_STATUS command, CHLINT field definition (address 1, size 1, lsb 0, unsigned)*/
	#define  Si2146_DTV_STATUS_RESPONSE_CHLINT_LSB         0
	#define  Si2146_DTV_STATUS_RESPONSE_CHLINT_MASK        0x01
	#define Si2146_DTV_STATUS_RESPONSE_CHLINT_CHANGED    1
	#define Si2146_DTV_STATUS_RESPONSE_CHLINT_NO_CHANGE  0
	/* DTV_STATUS command, CHL field definition (address 2, size 1, lsb 0, unsigned)*/
	#define  Si2146_DTV_STATUS_RESPONSE_CHL_LSB         0
	#define  Si2146_DTV_STATUS_RESPONSE_CHL_MASK        0x01
	#define Si2146_DTV_STATUS_RESPONSE_CHL_CHANNEL     1
	#define Si2146_DTV_STATUS_RESPONSE_CHL_NO_CHANNEL  0
	/* DTV_STATUS command, BW field definition (address 3, size 4, lsb 0, unsigned)*/
	#define  Si2146_DTV_STATUS_RESPONSE_BW_LSB         0
	#define  Si2146_DTV_STATUS_RESPONSE_BW_MASK        0x0f
	#define Si2146_DTV_STATUS_RESPONSE_BW_BW_6MHZ  6
	#define Si2146_DTV_STATUS_RESPONSE_BW_BW_7MHZ  7
	#define Si2146_DTV_STATUS_RESPONSE_BW_BW_8MHZ  8
	/* DTV_STATUS command, MODULATION field definition (address 3, size 4, lsb 4, unsigned)*/
	#define  Si2146_DTV_STATUS_RESPONSE_MODULATION_LSB         4
	#define  Si2146_DTV_STATUS_RESPONSE_MODULATION_MASK        0x0f
	#define Si2146_DTV_STATUS_RESPONSE_MODULATION_ATSC    0
	#define Si2146_DTV_STATUS_RESPONSE_MODULATION_DTMB    6
	#define Si2146_DTV_STATUS_RESPONSE_MODULATION_DVBC    3
	#define Si2146_DTV_STATUS_RESPONSE_MODULATION_DVBT    2
	#define Si2146_DTV_STATUS_RESPONSE_MODULATION_ISDBC   5
	#define Si2146_DTV_STATUS_RESPONSE_MODULATION_ISDBT   4
	#define Si2146_DTV_STATUS_RESPONSE_MODULATION_QAM_US  1
#endif /* Si2146_DTV_STATUS_CMD */

#define   Si2146_EXIT_BOOTLOADER_CMD 0x01

#ifdef    Si2146_EXIT_BOOTLOADER_CMD
  #define Si2146_EXIT_BOOTLOADER_CMD_CODE 0x010001

    typedef struct { /* Si2146_EXIT_BOOTLOADER_CMD_struct */
     unsigned char   func;
     unsigned char   ctsien;
   } Si2146_EXIT_BOOTLOADER_CMD_struct;


    typedef struct { /* Si2146_EXIT_BOOTLOADER_CMD_REPLY_struct */
       Si2146_COMMON_REPLY_struct * STATUS;
   }  Si2146_EXIT_BOOTLOADER_CMD_REPLY_struct;

   /* EXIT_BOOTLOADER command, FUNC field definition (address 1,size 4, lsb 0, unsigned) */
   #define  Si2146_EXIT_BOOTLOADER_CMD_FUNC_LSB         0
   #define  Si2146_EXIT_BOOTLOADER_CMD_FUNC_MASK        0x0f
   #define  Si2146_EXIT_BOOTLOADER_CMD_FUNC_MIN         0
   #define  Si2146_EXIT_BOOTLOADER_CMD_FUNC_MAX         1
    #define Si2146_EXIT_BOOTLOADER_CMD_FUNC_BOOTLOADER  0
    #define Si2146_EXIT_BOOTLOADER_CMD_FUNC_TUNER       1
   /* EXIT_BOOTLOADER command, CTSIEN field definition (address 1,size 1, lsb 7, unsigned) */
   #define  Si2146_EXIT_BOOTLOADER_CMD_CTSIEN_LSB         7
   #define  Si2146_EXIT_BOOTLOADER_CMD_CTSIEN_MASK        0x01
   #define  Si2146_EXIT_BOOTLOADER_CMD_CTSIEN_MIN         0
   #define  Si2146_EXIT_BOOTLOADER_CMD_CTSIEN_MAX         1
    #define Si2146_EXIT_BOOTLOADER_CMD_CTSIEN_OFF  0
    #define Si2146_EXIT_BOOTLOADER_CMD_CTSIEN_ON   1
#endif /* Si2146_EXIT_BOOTLOADER_CMD */

#define   Si2146_CONFIG_PINS_CMD 0x12

#ifdef    Si2146_CONFIG_PINS_CMD
  #define Si2146_CONFIG_PINS_CMD_CODE 0x010012

    typedef struct { /* Si2146_CONFIG_PINS_CMD_struct */
     unsigned char   gpio1_mode;
     unsigned char   gpio1_read;
     unsigned char   gpio2_mode;
     unsigned char   gpio2_read;
     unsigned char   gpio3_mode;
     unsigned char   gpio3_read;
     unsigned char   bclk1_mode;
     unsigned char   bclk1_read;
     unsigned char   xout_mode;
   } Si2146_CONFIG_PINS_CMD_struct;


    typedef struct { /* Si2146_CONFIG_PINS_CMD_REPLY_struct */
       Si2146_COMMON_REPLY_struct * STATUS;
      unsigned char   gpio1_mode;
      unsigned char   gpio1_state;
      unsigned char   gpio2_mode;
      unsigned char   gpio2_state;
      unsigned char   gpio3_mode;
      unsigned char   gpio3_state;
      unsigned char   bclk1_mode;
      unsigned char   bclk1_state;
      unsigned char   xout_mode;
   }  Si2146_CONFIG_PINS_CMD_REPLY_struct;

   /* CONFIG_PINS command, GPIO1_MODE field definition (address 1,size 7, lsb 0, unsigned) */
   #define  Si2146_CONFIG_PINS_CMD_GPIO1_MODE_LSB         0
   #define  Si2146_CONFIG_PINS_CMD_GPIO1_MODE_MASK        0x7f
   #define  Si2146_CONFIG_PINS_CMD_GPIO1_MODE_MIN         0
   #define  Si2146_CONFIG_PINS_CMD_GPIO1_MODE_MAX         3
    #define Si2146_CONFIG_PINS_CMD_GPIO1_MODE_DISABLE    1
    #define Si2146_CONFIG_PINS_CMD_GPIO1_MODE_DRIVE_0    2
    #define Si2146_CONFIG_PINS_CMD_GPIO1_MODE_DRIVE_1    3
    #define Si2146_CONFIG_PINS_CMD_GPIO1_MODE_NO_CHANGE  0
   /* CONFIG_PINS command, GPIO1_READ field definition (address 1,size 1, lsb 7, unsigned) */
   #define  Si2146_CONFIG_PINS_CMD_GPIO1_READ_LSB         7
   #define  Si2146_CONFIG_PINS_CMD_GPIO1_READ_MASK        0x01
   #define  Si2146_CONFIG_PINS_CMD_GPIO1_READ_MIN         0
   #define  Si2146_CONFIG_PINS_CMD_GPIO1_READ_MAX         1
    #define Si2146_CONFIG_PINS_CMD_GPIO1_READ_DO_NOT_READ  0
    #define Si2146_CONFIG_PINS_CMD_GPIO1_READ_READ         1
   /* CONFIG_PINS command, GPIO2_MODE field definition (address 2,size 7, lsb 0, unsigned) */
   #define  Si2146_CONFIG_PINS_CMD_GPIO2_MODE_LSB         0
   #define  Si2146_CONFIG_PINS_CMD_GPIO2_MODE_MASK        0x7f
   #define  Si2146_CONFIG_PINS_CMD_GPIO2_MODE_MIN         0
   #define  Si2146_CONFIG_PINS_CMD_GPIO2_MODE_MAX         3
    #define Si2146_CONFIG_PINS_CMD_GPIO2_MODE_DISABLE    1
    #define Si2146_CONFIG_PINS_CMD_GPIO2_MODE_DRIVE_0    2
    #define Si2146_CONFIG_PINS_CMD_GPIO2_MODE_DRIVE_1    3
    #define Si2146_CONFIG_PINS_CMD_GPIO2_MODE_NO_CHANGE  0
   /* CONFIG_PINS command, GPIO2_READ field definition (address 2,size 1, lsb 7, unsigned) */
   #define  Si2146_CONFIG_PINS_CMD_GPIO2_READ_LSB         7
   #define  Si2146_CONFIG_PINS_CMD_GPIO2_READ_MASK        0x01
   #define  Si2146_CONFIG_PINS_CMD_GPIO2_READ_MIN         0
   #define  Si2146_CONFIG_PINS_CMD_GPIO2_READ_MAX         1
    #define Si2146_CONFIG_PINS_CMD_GPIO2_READ_DO_NOT_READ  0
    #define Si2146_CONFIG_PINS_CMD_GPIO2_READ_READ         1
   /* CONFIG_PINS command, GPIO3_MODE field definition (address 3,size 7, lsb 0, unsigned) */
   #define  Si2146_CONFIG_PINS_CMD_GPIO3_MODE_LSB         0
   #define  Si2146_CONFIG_PINS_CMD_GPIO3_MODE_MASK        0x7f
   #define  Si2146_CONFIG_PINS_CMD_GPIO3_MODE_MIN         0
   #define  Si2146_CONFIG_PINS_CMD_GPIO3_MODE_MAX         3
    #define Si2146_CONFIG_PINS_CMD_GPIO3_MODE_DISABLE    1
    #define Si2146_CONFIG_PINS_CMD_GPIO3_MODE_DRIVE_0    2
    #define Si2146_CONFIG_PINS_CMD_GPIO3_MODE_DRIVE_1    3
    #define Si2146_CONFIG_PINS_CMD_GPIO3_MODE_NO_CHANGE  0
   /* CONFIG_PINS command, GPIO3_READ field definition (address 3,size 1, lsb 7, unsigned) */
   #define  Si2146_CONFIG_PINS_CMD_GPIO3_READ_LSB         7
   #define  Si2146_CONFIG_PINS_CMD_GPIO3_READ_MASK        0x01
   #define  Si2146_CONFIG_PINS_CMD_GPIO3_READ_MIN         0
   #define  Si2146_CONFIG_PINS_CMD_GPIO3_READ_MAX         1
    #define Si2146_CONFIG_PINS_CMD_GPIO3_READ_DO_NOT_READ  0
    #define Si2146_CONFIG_PINS_CMD_GPIO3_READ_READ         1
   /* CONFIG_PINS command, BCLK1_MODE field definition (address 4,size 7, lsb 0, unsigned) */
   #define  Si2146_CONFIG_PINS_CMD_BCLK1_MODE_LSB         0
   #define  Si2146_CONFIG_PINS_CMD_BCLK1_MODE_MASK        0x7f
   #define  Si2146_CONFIG_PINS_CMD_BCLK1_MODE_MIN         0
   #define  Si2146_CONFIG_PINS_CMD_BCLK1_MODE_MAX         11
    #define Si2146_CONFIG_PINS_CMD_BCLK1_MODE_DISABLE    1
    #define Si2146_CONFIG_PINS_CMD_BCLK1_MODE_NO_CHANGE  0
    #define Si2146_CONFIG_PINS_CMD_BCLK1_MODE_XOUT       10
    #define Si2146_CONFIG_PINS_CMD_BCLK1_MODE_XOUT_HIGH  11
   /* CONFIG_PINS command, BCLK1_READ field definition (address 4,size 1, lsb 7, unsigned) */
   #define  Si2146_CONFIG_PINS_CMD_BCLK1_READ_LSB         7
   #define  Si2146_CONFIG_PINS_CMD_BCLK1_READ_MASK        0x01
   #define  Si2146_CONFIG_PINS_CMD_BCLK1_READ_MIN         0
   #define  Si2146_CONFIG_PINS_CMD_BCLK1_READ_MAX         1
    #define Si2146_CONFIG_PINS_CMD_BCLK1_READ_DO_NOT_READ  0
    #define Si2146_CONFIG_PINS_CMD_BCLK1_READ_READ         1
   /* CONFIG_PINS command, XOUT_MODE field definition (address 5,size 7, lsb 0, unsigned) */
   #define  Si2146_CONFIG_PINS_CMD_XOUT_MODE_LSB         0
   #define  Si2146_CONFIG_PINS_CMD_XOUT_MODE_MASK        0x7f
   #define  Si2146_CONFIG_PINS_CMD_XOUT_MODE_MIN         0
   #define  Si2146_CONFIG_PINS_CMD_XOUT_MODE_MAX         10
    #define Si2146_CONFIG_PINS_CMD_XOUT_MODE_DISABLE    1
    #define Si2146_CONFIG_PINS_CMD_XOUT_MODE_NO_CHANGE  0
    #define Si2146_CONFIG_PINS_CMD_XOUT_MODE_XOUT       10
   /* CONFIG_PINS command, GPIO1_MODE field definition (address 1, size 7, lsb 0, unsigned)*/
   #define  Si2146_CONFIG_PINS_RESPONSE_GPIO1_MODE_LSB         0
   #define  Si2146_CONFIG_PINS_RESPONSE_GPIO1_MODE_MASK        0x7f
    #define Si2146_CONFIG_PINS_RESPONSE_GPIO1_MODE_DISABLE  1
    #define Si2146_CONFIG_PINS_RESPONSE_GPIO1_MODE_DRIVE_0  2
    #define Si2146_CONFIG_PINS_RESPONSE_GPIO1_MODE_DRIVE_1  3
   /* CONFIG_PINS command, GPIO1_STATE field definition (address 1, size 1, lsb 7, unsigned)*/
   #define  Si2146_CONFIG_PINS_RESPONSE_GPIO1_STATE_LSB         7
   #define  Si2146_CONFIG_PINS_RESPONSE_GPIO1_STATE_MASK        0x01
    #define Si2146_CONFIG_PINS_RESPONSE_GPIO1_STATE_READ_0  0
    #define Si2146_CONFIG_PINS_RESPONSE_GPIO1_STATE_READ_1  1
   /* CONFIG_PINS command, GPIO2_MODE field definition (address 2, size 7, lsb 0, unsigned)*/
   #define  Si2146_CONFIG_PINS_RESPONSE_GPIO2_MODE_LSB         0
   #define  Si2146_CONFIG_PINS_RESPONSE_GPIO2_MODE_MASK        0x7f
    #define Si2146_CONFIG_PINS_RESPONSE_GPIO2_MODE_DISABLE  1
    #define Si2146_CONFIG_PINS_RESPONSE_GPIO2_MODE_DRIVE_0  2
    #define Si2146_CONFIG_PINS_RESPONSE_GPIO2_MODE_DRIVE_1  3
   /* CONFIG_PINS command, GPIO2_STATE field definition (address 2, size 1, lsb 7, unsigned)*/
   #define  Si2146_CONFIG_PINS_RESPONSE_GPIO2_STATE_LSB         7
   #define  Si2146_CONFIG_PINS_RESPONSE_GPIO2_STATE_MASK        0x01
    #define Si2146_CONFIG_PINS_RESPONSE_GPIO2_STATE_READ_0  0
    #define Si2146_CONFIG_PINS_RESPONSE_GPIO2_STATE_READ_1  1
   /* CONFIG_PINS command, GPIO3_MODE field definition (address 3, size 7, lsb 0, unsigned)*/
   #define  Si2146_CONFIG_PINS_RESPONSE_GPIO3_MODE_LSB         0
   #define  Si2146_CONFIG_PINS_RESPONSE_GPIO3_MODE_MASK        0x7f
    #define Si2146_CONFIG_PINS_RESPONSE_GPIO3_MODE_DISABLE  1
    #define Si2146_CONFIG_PINS_RESPONSE_GPIO3_MODE_DRIVE_0  2
    #define Si2146_CONFIG_PINS_RESPONSE_GPIO3_MODE_DRIVE_1  3
   /* CONFIG_PINS command, GPIO3_STATE field definition (address 3, size 1, lsb 7, unsigned)*/
   #define  Si2146_CONFIG_PINS_RESPONSE_GPIO3_STATE_LSB         7
   #define  Si2146_CONFIG_PINS_RESPONSE_GPIO3_STATE_MASK        0x01
    #define Si2146_CONFIG_PINS_RESPONSE_GPIO3_STATE_READ_0  0
    #define Si2146_CONFIG_PINS_RESPONSE_GPIO3_STATE_READ_1  1
   /* CONFIG_PINS command, BCLK1_MODE field definition (address 4, size 7, lsb 0, unsigned)*/
   #define  Si2146_CONFIG_PINS_RESPONSE_BCLK1_MODE_LSB         0
   #define  Si2146_CONFIG_PINS_RESPONSE_BCLK1_MODE_MASK        0x7f
    #define Si2146_CONFIG_PINS_RESPONSE_BCLK1_MODE_DISABLE    1
    #define Si2146_CONFIG_PINS_RESPONSE_BCLK1_MODE_XOUT       10
    #define Si2146_CONFIG_PINS_RESPONSE_BCLK1_MODE_XOUT_HIGH  11
   /* CONFIG_PINS command, BCLK1_STATE field definition (address 4, size 1, lsb 7, unsigned)*/
   #define  Si2146_CONFIG_PINS_RESPONSE_BCLK1_STATE_LSB         7
   #define  Si2146_CONFIG_PINS_RESPONSE_BCLK1_STATE_MASK        0x01
    #define Si2146_CONFIG_PINS_RESPONSE_BCLK1_STATE_READ_0  0
    #define Si2146_CONFIG_PINS_RESPONSE_BCLK1_STATE_READ_1  1
   /* CONFIG_PINS command, XOUT_MODE field definition (address 5, size 7, lsb 0, unsigned)*/
   #define  Si2146_CONFIG_PINS_RESPONSE_XOUT_MODE_LSB         0
   #define  Si2146_CONFIG_PINS_RESPONSE_XOUT_MODE_MASK        0x7f
    #define Si2146_CONFIG_PINS_RESPONSE_XOUT_MODE_DISABLE  1
    #define Si2146_CONFIG_PINS_RESPONSE_XOUT_MODE_XOUT     10

#endif /* Si2146_CONFIG_PINS_CMD */

#define   Si2146_STANDBY_CMD 0x16

#ifdef    Si2146_STANDBY_CMD
  #define Si2146_STANDBY_CMD_CODE 0x010016

    typedef struct { /* Si2146_STANDBY_CMD_struct */
         unsigned char   nothing;   } Si2146_STANDBY_CMD_struct;


    typedef struct { /* Si2146_STANDBY_CMD_REPLY_struct */
       Si2146_COMMON_REPLY_struct * STATUS;
   }  Si2146_STANDBY_CMD_REPLY_struct;

#endif /* Si2146_STANDBY_CMD */

typedef struct
{ // Si2146_CmdObj struct
	#ifdef    Si2146_AGC_OVERRIDE_CMD
			  Si2146_AGC_OVERRIDE_CMD_struct               agc_override;
	#endif /* Si2146_AGC_OVERRIDE_CMD */
	#ifdef    Si2146_ATV_RESTART_CMD
			  Si2146_ATV_RESTART_CMD_struct      atv_restart;
	#endif /* Si2146_ATV_RESTART_CMD */
	#ifdef    Si2146_ATV_STATUS_CMD
			  Si2146_ATV_STATUS_CMD_struct       atv_status;
	#endif /* Si2146_ATV_STATUS_CMD */
	#ifdef    Si2146_CONFIG_PINS_CMD
			  Si2146_CONFIG_PINS_CMD_struct                config_pins;
	#endif /* Si2146_CONFIG_PINS_CMD */
	#ifdef    Si2146_DTV_RESTART_CMD
			  Si2146_DTV_RESTART_CMD_struct                dtv_restart;
	#endif /* Si2146_DTV_RESTART_CMD */
	#ifdef    Si2146_DTV_STATUS_CMD
			  Si2146_DTV_STATUS_CMD_struct                 dtv_status;
	#endif /* Si2146_DTV_STATUS_CMD */
	#ifdef    Si2146_EXIT_BOOTLOADER_CMD
			  Si2146_EXIT_BOOTLOADER_CMD_struct            exit_bootloader;
	#endif /* Si2146_EXIT_BOOTLOADER_CMD */
	#ifdef    Si2146_FINE_TUNE_CMD
			  Si2146_FINE_TUNE_CMD_struct                  fine_tune;
	#endif /* Si2146_FINE_TUNE_CMD */
	#ifdef    Si2146_GET_PROPERTY_CMD
			  Si2146_GET_PROPERTY_CMD_struct               get_property;
	#endif /* Si2146_GET_PROPERTY_CMD */
	#ifdef    Si2146_GET_REV_CMD
			  Si2146_GET_REV_CMD_struct                    get_rev;
	#endif /* Si2146_GET_REV_CMD */
	#ifdef    Si2146_PART_INFO_CMD
			  Si2146_PART_INFO_CMD_struct                  part_info;
	#endif /* Si2146_PART_INFO_CMD */
	#ifdef    Si2146_POWER_DOWN_CMD
			  Si2146_POWER_DOWN_CMD_struct                 power_down;
	#endif /* Si2146_POWER_DOWN_CMD */
	#ifdef    Si2146_POWER_UP_CMD
			  Si2146_POWER_UP_CMD_struct                   power_up;
	#endif /* Si2146_POWER_UP_CMD */
	#ifdef    Si2146_SET_PROPERTY_CMD
			  Si2146_SET_PROPERTY_CMD_struct               set_property;
	#endif /* Si2146_SET_PROPERTY_CMD */
	#ifdef    Si2146_STANDBY_CMD
			  Si2146_STANDBY_CMD_struct                    standby;
	#endif /* Si2146_STANDBY_CMD */
	#ifdef    Si2146_TUNER_STATUS_CMD
			  Si2146_TUNER_STATUS_CMD_struct               tuner_status;
	#endif /* Si2146_TUNER_STATUS_CMD */
	#ifdef    Si2146_TUNER_TUNE_FREQ_CMD
			  Si2146_TUNER_TUNE_FREQ_CMD_struct            tuner_tune_freq;
	#endif /* Si2146_TUNER_TUNE_FREQ_CMD */
} Si2146_CmdObj;

// Si2148_CONFIG_CLOCKS command definition
#define   Si2148_CONFIG_CLOCKS_CMD 0xc0

#ifdef    Si2148_CONFIG_CLOCKS_CMD
	#define Si2148_CONFIG_CLOCKS_CMD_CODE 0x0100c0
	typedef struct
	{ // Si2148_CONFIG_CLOCKS_CMD_struct
		unsigned char   subcode;
		unsigned char   clock_mode;
		unsigned char   en_xout;
	} Si2148_CONFIG_CLOCKS_CMD_struct;
	typedef struct
	{ // Si2148_CONFIG_CLOCKS_CMD_REPLY_struct
		Si2148_COMMON_REPLY_struct * STATUS;
	}  Si2148_CONFIG_CLOCKS_CMD_REPLY_struct;
	// CONFIG_CLOCKS command, SUBCODE field definition (address 1,size 8, lsb 0, unsigned)
	#define  Si2148_CONFIG_CLOCKS_CMD_SUBCODE_LSB         0
	#define  Si2148_CONFIG_CLOCKS_CMD_SUBCODE_MASK        0xff
	#define  Si2148_CONFIG_CLOCKS_CMD_SUBCODE_MIN         0
	#define  Si2148_CONFIG_CLOCKS_CMD_SUBCODE_MAX         0
	#define Si2148_CONFIG_CLOCKS_CMD_SUBCODE_CODE  0
	// CONFIG_CLOCKS command, CLOCK_MODE field definition (address 2,size 2, lsb 0, unsigned)
	#define  Si2148_CONFIG_CLOCKS_CMD_CLOCK_MODE_LSB         0
	#define  Si2148_CONFIG_CLOCKS_CMD_CLOCK_MODE_MASK        0x03
	#define  Si2148_CONFIG_CLOCKS_CMD_CLOCK_MODE_MIN         0
	#define  Si2148_CONFIG_CLOCKS_CMD_CLOCK_MODE_MAX         2
	#define Si2148_CONFIG_CLOCKS_CMD_CLOCK_MODE_EXTCLK  2
	#define Si2148_CONFIG_CLOCKS_CMD_CLOCK_MODE_XTAL    0
	// CONFIG_CLOCKS command, EN_XOUT field definition (address 2,size 3, lsb 2, unsigned)
	#define  Si2148_CONFIG_CLOCKS_CMD_EN_XOUT_LSB         2
	#define  Si2148_CONFIG_CLOCKS_CMD_EN_XOUT_MASK        0x07
	#define  Si2148_CONFIG_CLOCKS_CMD_EN_XOUT_MIN         0
	#define  Si2148_CONFIG_CLOCKS_CMD_EN_XOUT_MAX         3
	#define Si2148_CONFIG_CLOCKS_CMD_EN_XOUT_DIS_XOUT  0
	#define Si2148_CONFIG_CLOCKS_CMD_EN_XOUT_EN_XOUT   3
#endif // Si2148_CONFIG_CLOCKS_CMD

// Si2148_STANDBY command definition
#define   Si2148_STANDBY_CMD 0x16

#ifdef    Si2148_STANDBY_CMD
	#define Si2148_STANDBY_CMD_CODE 0x010016
	typedef struct
	{ // Si2148_STANDBY_CMD_struct
		unsigned char   type;
	} Si2148_STANDBY_CMD_struct;
	typedef struct
	{ // Si2148_STANDBY_CMD_REPLY_struct
		Si2148_COMMON_REPLY_struct * STATUS;
	} Si2148_STANDBY_CMD_REPLY_struct;
	// STANDBY command, TYPE field definition (address 1,size 1, lsb 0, unsigned)
	#define  Si2148_STANDBY_CMD_TYPE_LSB         0
	#define  Si2148_STANDBY_CMD_TYPE_MASK        0x01
	#define  Si2148_STANDBY_CMD_TYPE_MIN         0
	#define  Si2148_STANDBY_CMD_TYPE_MAX         1
	#define Si2148_STANDBY_CMD_TYPE_LNA_OFF  1
	#define Si2148_STANDBY_CMD_TYPE_LNA_ON   0
#endif // Si2148_STANDBY_CMD

// Si2148_POWER_UP command definition
#define   Si2148_POWER_UP_CMD 0xc0
#ifdef    Si2148_POWER_UP_CMD
	#define Si2148_POWER_UP_CMD_CODE 0x0300c0
	typedef struct { /* Si2148_POWER_UP_CMD_struct */
	 unsigned char   subcode;
	 unsigned char   clock_mode;
	 unsigned char   en_xout;
	 unsigned char   pd_ldo;
	 unsigned char   reserved2;
	 unsigned char   reserved3;
	 unsigned char   reserved4;
	 unsigned char   reserved5;
	 unsigned char   reserved6;
	 unsigned char   reserved7;
	 unsigned char   reset;
	 unsigned char   clock_freq;
	 unsigned char   reserved8;
	 unsigned char   func;
	 unsigned char   ctsien;
	 unsigned char   wake_up;
	} Si2148_POWER_UP_CMD_struct;
	typedef struct { /* Si2148_POWER_UP_CMD_REPLY_struct */
	   Si2148_COMMON_REPLY_struct * STATUS;
	}  Si2148_POWER_UP_CMD_REPLY_struct;

	/* POWER_UP command, SUBCODE field definition (address 1,size 8, lsb 0, unsigned) */
	#define  Si2148_POWER_UP_CMD_SUBCODE_LSB         0
	#define  Si2148_POWER_UP_CMD_SUBCODE_MASK        0xff
	#define  Si2148_POWER_UP_CMD_SUBCODE_MIN         0
	#define  Si2148_POWER_UP_CMD_SUBCODE_MAX         0
	#define Si2148_POWER_UP_CMD_SUBCODE_CODE  0
	/* POWER_UP command, CLOCK_MODE field definition (address 2,size 2, lsb 0, unsigned) */
	#define  Si2148_POWER_UP_CMD_CLOCK_MODE_LSB         0
	#define  Si2148_POWER_UP_CMD_CLOCK_MODE_MASK        0x03
	#define  Si2148_POWER_UP_CMD_CLOCK_MODE_MIN         0
	#define  Si2148_POWER_UP_CMD_CLOCK_MODE_MAX         2
	#define Si2148_POWER_UP_CMD_CLOCK_MODE_EXTCLK  2
	#define Si2148_POWER_UP_CMD_CLOCK_MODE_XTAL    0
	/* POWER_UP command, EN_XOUT field definition (address 2,size 3, lsb 2, unsigned) */
	#define  Si2148_POWER_UP_CMD_EN_XOUT_LSB         2
	#define  Si2148_POWER_UP_CMD_EN_XOUT_MASK        0x07
	#define  Si2148_POWER_UP_CMD_EN_XOUT_MIN         0
	#define  Si2148_POWER_UP_CMD_EN_XOUT_MAX         3
	#define Si2148_POWER_UP_CMD_EN_XOUT_DIS_XOUT  0
	#define Si2148_POWER_UP_CMD_EN_XOUT_EN_XOUT   3
	/* POWER_UP command, PD_LDO field definition (address 3,size 1, lsb 0, unsigned) */
	#define  Si2148_POWER_UP_CMD_PD_LDO_LSB         0
	#define  Si2148_POWER_UP_CMD_PD_LDO_MASK        0x01
	#define  Si2148_POWER_UP_CMD_PD_LDO_MIN         0
	#define  Si2148_POWER_UP_CMD_PD_LDO_MAX         1
	#define Si2148_POWER_UP_CMD_PD_LDO_LDO_POWER_DOWN  1
	#define Si2148_POWER_UP_CMD_PD_LDO_LDO_POWER_UP    0
	/* POWER_UP command, RESERVED2 field definition (address 4,size 8, lsb 0, unsigned) */
	#define  Si2148_POWER_UP_CMD_RESERVED2_LSB         0
	#define  Si2148_POWER_UP_CMD_RESERVED2_MASK        0xff
	#define  Si2148_POWER_UP_CMD_RESERVED2_MIN         0
	#define  Si2148_POWER_UP_CMD_RESERVED2_MAX         0
	#define Si2148_POWER_UP_CMD_RESERVED2_RESERVED  0
	/* POWER_UP command, RESERVED3 field definition (address 5,size 8, lsb 0, unsigned) */
	#define  Si2148_POWER_UP_CMD_RESERVED3_LSB         0
	#define  Si2148_POWER_UP_CMD_RESERVED3_MASK        0xff
	#define  Si2148_POWER_UP_CMD_RESERVED3_MIN         1
	#define  Si2148_POWER_UP_CMD_RESERVED3_MAX         1
	#define Si2148_POWER_UP_CMD_RESERVED3_RESERVED  1
	/* POWER_UP command, RESERVED4 field definition (address 6,size 8, lsb 0, unsigned) */
	#define  Si2148_POWER_UP_CMD_RESERVED4_LSB         0
	#define  Si2148_POWER_UP_CMD_RESERVED4_MASK        0xff
	#define  Si2148_POWER_UP_CMD_RESERVED4_MIN         1
	#define  Si2148_POWER_UP_CMD_RESERVED4_MAX         1
	#define Si2148_POWER_UP_CMD_RESERVED4_RESERVED  1
	/* POWER_UP command, RESERVED5 field definition (address 7,size 8, lsb 0, unsigned) */
	#define  Si2148_POWER_UP_CMD_RESERVED5_LSB         0
	#define  Si2148_POWER_UP_CMD_RESERVED5_MASK        0xff
	#define  Si2148_POWER_UP_CMD_RESERVED5_MIN         1
	#define  Si2148_POWER_UP_CMD_RESERVED5_MAX         1
	#define Si2148_POWER_UP_CMD_RESERVED5_RESERVED  1
	/* POWER_UP command, RESERVED6 field definition (address 8,size 8, lsb 0, unsigned) */
	#define  Si2148_POWER_UP_CMD_RESERVED6_LSB         0
	#define  Si2148_POWER_UP_CMD_RESERVED6_MASK        0xff
	#define  Si2148_POWER_UP_CMD_RESERVED6_MIN         1
	#define  Si2148_POWER_UP_CMD_RESERVED6_MAX         1
	#define Si2148_POWER_UP_CMD_RESERVED6_RESERVED  1
	/* POWER_UP command, RESERVED7 field definition (address 9,size 8, lsb 0, unsigned) */
	#define  Si2148_POWER_UP_CMD_RESERVED7_LSB         0
	#define  Si2148_POWER_UP_CMD_RESERVED7_MASK        0xff
	#define  Si2148_POWER_UP_CMD_RESERVED7_MIN         1
	#define  Si2148_POWER_UP_CMD_RESERVED7_MAX         1
	#define Si2148_POWER_UP_CMD_RESERVED7_RESERVED  1
	/* POWER_UP command, RESET field definition (address 10,size 8, lsb 0, unsigned) */
	#define  Si2148_POWER_UP_CMD_RESET_LSB         0
	#define  Si2148_POWER_UP_CMD_RESET_MASK        0xff
	#define  Si2148_POWER_UP_CMD_RESET_MIN         1
	#define  Si2148_POWER_UP_CMD_RESET_MAX         1
	#define Si2148_POWER_UP_CMD_RESET_RESET  1
	/* POWER_UP command, CLOCK_FREQ field definition (address 11,size 2, lsb 0, unsigned) */
	#define  Si2148_POWER_UP_CMD_CLOCK_FREQ_LSB         0
	#define  Si2148_POWER_UP_CMD_CLOCK_FREQ_MASK        0x03
	#define  Si2148_POWER_UP_CMD_CLOCK_FREQ_MIN         0
	#define  Si2148_POWER_UP_CMD_CLOCK_FREQ_MAX         3
	#define Si2148_POWER_UP_CMD_CLOCK_FREQ_CLK_24MHZ  2
	/* POWER_UP command, RESERVED8 field definition (address 12,size 8, lsb 0, unsigned) */
	#define  Si2148_POWER_UP_CMD_RESERVED8_LSB         0
	#define  Si2148_POWER_UP_CMD_RESERVED8_MASK        0xff
	#define  Si2148_POWER_UP_CMD_RESERVED8_MIN         0
	#define  Si2148_POWER_UP_CMD_RESERVED8_MAX         0
	#define Si2148_POWER_UP_CMD_RESERVED8_RESERVED  0
	/* POWER_UP command, FUNC field definition (address 13,size 4, lsb 0, unsigned) */
	#define  Si2148_POWER_UP_CMD_FUNC_LSB         0
	#define  Si2148_POWER_UP_CMD_FUNC_MASK        0x0f
	#define  Si2148_POWER_UP_CMD_FUNC_MIN         0
	#define  Si2148_POWER_UP_CMD_FUNC_MAX         1
	#define Si2148_POWER_UP_CMD_FUNC_BOOTLOADER  0
	#define Si2148_POWER_UP_CMD_FUNC_NORMAL      1
	/* POWER_UP command, CTSIEN field definition (address 13,size 1, lsb 7, unsigned) */
	#define  Si2148_POWER_UP_CMD_CTSIEN_LSB         7
	#define  Si2148_POWER_UP_CMD_CTSIEN_MASK        0x01
	#define  Si2148_POWER_UP_CMD_CTSIEN_MIN         0
	#define  Si2148_POWER_UP_CMD_CTSIEN_MAX         1
	#define Si2148_POWER_UP_CMD_CTSIEN_DISABLE  0
	#define Si2148_POWER_UP_CMD_CTSIEN_ENABLE   1
	/* POWER_UP command, WAKE_UP field definition (address 14,size 1, lsb 0, unsigned) */
	#define  Si2148_POWER_UP_CMD_WAKE_UP_LSB         0
	#define  Si2148_POWER_UP_CMD_WAKE_UP_MASK        0x01
	#define  Si2148_POWER_UP_CMD_WAKE_UP_MIN         1
	#define  Si2148_POWER_UP_CMD_WAKE_UP_MAX         1
	#define Si2148_POWER_UP_CMD_WAKE_UP_WAKE_UP  1
#endif /* Si2148_POWER_UP_CMD */

/* Si2148_PART_INFO command definition */
#define   Si2148_PART_INFO_CMD 0x02

#ifdef    Si2148_PART_INFO_CMD
	#define Si2148_PART_INFO_CMD_CODE 0x010002

	typedef struct { /* Si2148_PART_INFO_CMD_struct */
		 unsigned char   nothing;   } Si2148_PART_INFO_CMD_struct;

	typedef struct { /* Si2148_PART_INFO_CMD_REPLY_struct */
	   Si2148_COMMON_REPLY_struct * STATUS;
	  unsigned char   chiprev;
	  unsigned char   romid;
	  unsigned char   part;
	  unsigned char   pmajor;
	  unsigned char   pminor;
	  unsigned char   pbuild;
	  unsigned int    reserved;
	  unsigned long   serial;
	}  Si2148_PART_INFO_CMD_REPLY_struct;

	/* PART_INFO command, CHIPREV field definition (address 1, size 4, lsb 0, unsigned)*/
	#define  Si2148_PART_INFO_RESPONSE_CHIPREV_LSB         0
	#define  Si2148_PART_INFO_RESPONSE_CHIPREV_MASK        0x0f
	#define Si2148_PART_INFO_RESPONSE_CHIPREV_A  1
	#define Si2148_PART_INFO_RESPONSE_CHIPREV_B  2
	/* PART_INFO command, ROMID field definition (address 12, size 8, lsb 0, unsigned)*/
	#define  Si2148_PART_INFO_RESPONSE_ROMID_LSB         0
	#define  Si2148_PART_INFO_RESPONSE_ROMID_MASK        0xff
	/* PART_INFO command, PART field definition (address 2, size 8, lsb 0, unsigned)*/
	#define  Si2148_PART_INFO_RESPONSE_PART_LSB         0
	#define  Si2148_PART_INFO_RESPONSE_PART_MASK        0xff
	/* PART_INFO command, PMAJOR field definition (address 3, size 8, lsb 0, unsigned)*/
	#define  Si2148_PART_INFO_RESPONSE_PMAJOR_LSB         0
	#define  Si2148_PART_INFO_RESPONSE_PMAJOR_MASK        0xff
	/* PART_INFO command, PMINOR field definition (address 4, size 8, lsb 0, unsigned)*/
	#define  Si2148_PART_INFO_RESPONSE_PMINOR_LSB         0
	#define  Si2148_PART_INFO_RESPONSE_PMINOR_MASK        0xff
	/* PART_INFO command, PBUILD field definition (address 5, size 8, lsb 0, unsigned)*/
	#define  Si2148_PART_INFO_RESPONSE_PBUILD_LSB         0
	#define  Si2148_PART_INFO_RESPONSE_PBUILD_MASK        0xff
	/* PART_INFO command, RESERVED field definition (address 6, size 16, lsb 0, unsigned)*/
	#define  Si2148_PART_INFO_RESPONSE_RESERVED_LSB         0
	#define  Si2148_PART_INFO_RESPONSE_RESERVED_MASK        0xffff
	/* PART_INFO command, SERIAL field definition (address 8, size 32, lsb 0, unsigned)*/
	#define  Si2148_PART_INFO_RESPONSE_SERIAL_LSB         0
	#define  Si2148_PART_INFO_RESPONSE_SERIAL_MASK        0xffffffff
#endif /* Si2148_PART_INFO_CMD */

/* Si2148_EXIT_BOOTLOADER command definition */
#define   Si2148_EXIT_BOOTLOADER_CMD 0x01

#ifdef    Si2148_EXIT_BOOTLOADER_CMD
  #define Si2148_EXIT_BOOTLOADER_CMD_CODE 0x010001

    typedef struct { /* Si2148_EXIT_BOOTLOADER_CMD_struct */
     unsigned char   func;
     unsigned char   ctsien;
   } Si2148_EXIT_BOOTLOADER_CMD_struct;


    typedef struct { /* Si2148_EXIT_BOOTLOADER_CMD_REPLY_struct */
       Si2148_COMMON_REPLY_struct * STATUS;
   }  Si2148_EXIT_BOOTLOADER_CMD_REPLY_struct;

   /* EXIT_BOOTLOADER command, FUNC field definition (address 1,size 4, lsb 0, unsigned) */
   #define  Si2148_EXIT_BOOTLOADER_CMD_FUNC_LSB         0
   #define  Si2148_EXIT_BOOTLOADER_CMD_FUNC_MASK        0x0f
   #define  Si2148_EXIT_BOOTLOADER_CMD_FUNC_MIN         0
   #define  Si2148_EXIT_BOOTLOADER_CMD_FUNC_MAX         1
    #define Si2148_EXIT_BOOTLOADER_CMD_FUNC_BOOTLOADER  0
    #define Si2148_EXIT_BOOTLOADER_CMD_FUNC_TUNER       1
   /* EXIT_BOOTLOADER command, CTSIEN field definition (address 1,size 1, lsb 7, unsigned) */
   #define  Si2148_EXIT_BOOTLOADER_CMD_CTSIEN_LSB         7
   #define  Si2148_EXIT_BOOTLOADER_CMD_CTSIEN_MASK        0x01
   #define  Si2148_EXIT_BOOTLOADER_CMD_CTSIEN_MIN         0
   #define  Si2148_EXIT_BOOTLOADER_CMD_CTSIEN_MAX         1
    #define Si2148_EXIT_BOOTLOADER_CMD_CTSIEN_OFF  0
    #define Si2148_EXIT_BOOTLOADER_CMD_CTSIEN_ON   1
#endif /* Si2148_EXIT_BOOTLOADER_CMD */
/* Si2148_SET_PROPERTY command definition */
#define   Si2148_SET_PROPERTY_CMD 0x14

#ifdef    Si2148_SET_PROPERTY_CMD
  #define Si2148_SET_PROPERTY_CMD_CODE 0x010014

    typedef struct { /* Si2148_SET_PROPERTY_CMD_struct */
     unsigned char   reserved;
     unsigned int    prop;
     unsigned int    data;
   } Si2148_SET_PROPERTY_CMD_struct;


    typedef struct { /* Si2148_SET_PROPERTY_CMD_REPLY_struct */
       Si2148_COMMON_REPLY_struct * STATUS;
      unsigned char   reserved;
      unsigned int    data;
   }  Si2148_SET_PROPERTY_CMD_REPLY_struct;

   /* SET_PROPERTY command, RESERVED field definition (address 1,size 8, lsb 0, unsigned) */
   #define  Si2148_SET_PROPERTY_CMD_RESERVED_LSB         0
   #define  Si2148_SET_PROPERTY_CMD_RESERVED_MASK        0xff
   #define  Si2148_SET_PROPERTY_CMD_RESERVED_MIN         0
   #define  Si2148_SET_PROPERTY_CMD_RESERVED_MAX         255.0
   /* SET_PROPERTY command, PROP field definition (address 2,size 16, lsb 0, unsigned) */
   #define  Si2148_SET_PROPERTY_CMD_PROP_LSB         0
   #define  Si2148_SET_PROPERTY_CMD_PROP_MASK        0xffff
   #define  Si2148_SET_PROPERTY_CMD_PROP_MIN         0
   #define  Si2148_SET_PROPERTY_CMD_PROP_MAX         65535
    #define Si2148_SET_PROPERTY_CMD_PROP_PROP_MIN  0
    #define Si2148_SET_PROPERTY_CMD_PROP_PROP_MAX  65535
   /* SET_PROPERTY command, DATA field definition (address 4,size 16, lsb 0, unsigned) */
   #define  Si2148_SET_PROPERTY_CMD_DATA_LSB         0
   #define  Si2148_SET_PROPERTY_CMD_DATA_MASK        0xffff
   #define  Si2148_SET_PROPERTY_CMD_DATA_MIN         0
   #define  Si2148_SET_PROPERTY_CMD_DATA_MAX         65535
    #define Si2148_SET_PROPERTY_CMD_DATA_DATA_MIN  0
    #define Si2148_SET_PROPERTY_CMD_DATA_DATA_MAX  65535
   /* SET_PROPERTY command, RESERVED field definition (address 1, size 8, lsb 0, unsigned)*/
   #define  Si2148_SET_PROPERTY_RESPONSE_RESERVED_LSB         0
   #define  Si2148_SET_PROPERTY_RESPONSE_RESERVED_MASK        0xff
    #define Si2148_SET_PROPERTY_RESPONSE_RESERVED_RESERVED_MIN  0
    #define Si2148_SET_PROPERTY_RESPONSE_RESERVED_RESERVED_MAX  0
   /* SET_PROPERTY command, DATA field definition (address 2, size 16, lsb 0, unsigned)*/
   #define  Si2148_SET_PROPERTY_RESPONSE_DATA_LSB         0
   #define  Si2148_SET_PROPERTY_RESPONSE_DATA_MASK        0xffff

#endif /* Si2148_SET_PROPERTY_CMD */

/* Si2148_TUNER_TUNE_FREQ command definition */
#define   Si2148_TUNER_TUNE_FREQ_CMD 0x41

#ifdef    Si2148_TUNER_TUNE_FREQ_CMD
  #define Si2148_TUNER_TUNE_FREQ_CMD_CODE 0x010041

    typedef struct { /* Si2148_TUNER_TUNE_FREQ_CMD_struct */
     unsigned char   mode;
     unsigned long   freq;
   } Si2148_TUNER_TUNE_FREQ_CMD_struct;


    typedef struct { /* Si2148_TUNER_TUNE_FREQ_CMD_REPLY_struct */
       Si2148_COMMON_REPLY_struct * STATUS;
   }  Si2148_TUNER_TUNE_FREQ_CMD_REPLY_struct;

   /* TUNER_TUNE_FREQ command, MODE field definition (address 1,size 1, lsb 0, unsigned) */
   #define  Si2148_TUNER_TUNE_FREQ_CMD_MODE_LSB         0
   #define  Si2148_TUNER_TUNE_FREQ_CMD_MODE_MASK        0x01
   #define  Si2148_TUNER_TUNE_FREQ_CMD_MODE_MIN         0
   #define  Si2148_TUNER_TUNE_FREQ_CMD_MODE_MAX         1
    #define Si2148_TUNER_TUNE_FREQ_CMD_MODE_ATV  1
    #define Si2148_TUNER_TUNE_FREQ_CMD_MODE_DTV  0
   /* TUNER_TUNE_FREQ command, FREQ field definition (address 4,size 32, lsb 0, unsigned) */
   #define  Si2148_TUNER_TUNE_FREQ_CMD_FREQ_LSB         0
   #define  Si2148_TUNER_TUNE_FREQ_CMD_FREQ_MASK        0xffffffff
   #define  Si2148_TUNER_TUNE_FREQ_CMD_FREQ_MIN         40000000
   #define  Si2148_TUNER_TUNE_FREQ_CMD_FREQ_MAX         1002000000
    #define Si2148_TUNER_TUNE_FREQ_CMD_FREQ_FREQ_MIN  40000000
    #define Si2148_TUNER_TUNE_FREQ_CMD_FREQ_FREQ_MAX  1002000000
#endif /* Si2148_TUNER_TUNE_FREQ_CMD */

/* Si2148_TUNER_STATUS command definition */
#define   Si2148_TUNER_STATUS_CMD 0x42

#ifdef    Si2148_TUNER_STATUS_CMD
  #define Si2148_TUNER_STATUS_CMD_CODE 0x010042

    typedef struct { /* Si2148_TUNER_STATUS_CMD_struct */
     unsigned char   intack;
   } Si2148_TUNER_STATUS_CMD_struct;


    typedef struct { /* Si2148_TUNER_STATUS_CMD_REPLY_struct */
       Si2148_COMMON_REPLY_struct * STATUS;
      unsigned char   tcint;
      unsigned char   rssilint;
      unsigned char   rssihint;
               int    vco_code;
      unsigned char   tc;
      unsigned char   rssil;
      unsigned char   rssih;
               char   rssi;
      unsigned long   freq;
      unsigned char   mode;
   }  Si2148_TUNER_STATUS_CMD_REPLY_struct;

   /* TUNER_STATUS command, INTACK field definition (address 1,size 1, lsb 0, unsigned) */
   #define  Si2148_TUNER_STATUS_CMD_INTACK_LSB         0
   #define  Si2148_TUNER_STATUS_CMD_INTACK_MASK        0x01
   #define  Si2148_TUNER_STATUS_CMD_INTACK_MIN         0
   #define  Si2148_TUNER_STATUS_CMD_INTACK_MAX         1
    #define Si2148_TUNER_STATUS_CMD_INTACK_CLEAR  1
    #define Si2148_TUNER_STATUS_CMD_INTACK_OK     0
   /* TUNER_STATUS command, TCINT field definition (address 1, size 1, lsb 0, unsigned)*/
   #define  Si2148_TUNER_STATUS_RESPONSE_TCINT_LSB         0
   #define  Si2148_TUNER_STATUS_RESPONSE_TCINT_MASK        0x01
    #define Si2148_TUNER_STATUS_RESPONSE_TCINT_CHANGED    1
    #define Si2148_TUNER_STATUS_RESPONSE_TCINT_NO_CHANGE  0
   /* TUNER_STATUS command, RSSILINT field definition (address 1, size 1, lsb 1, unsigned)*/
   #define  Si2148_TUNER_STATUS_RESPONSE_RSSILINT_LSB         1
   #define  Si2148_TUNER_STATUS_RESPONSE_RSSILINT_MASK        0x01
    #define Si2148_TUNER_STATUS_RESPONSE_RSSILINT_CHANGED    1
    #define Si2148_TUNER_STATUS_RESPONSE_RSSILINT_NO_CHANGE  0
   /* TUNER_STATUS command, RSSIHINT field definition (address 1, size 1, lsb 2, unsigned)*/
   #define  Si2148_TUNER_STATUS_RESPONSE_RSSIHINT_LSB         2
   #define  Si2148_TUNER_STATUS_RESPONSE_RSSIHINT_MASK        0x01
    #define Si2148_TUNER_STATUS_RESPONSE_RSSIHINT_CHANGED    1
    #define Si2148_TUNER_STATUS_RESPONSE_RSSIHINT_NO_CHANGE  0
   /* TUNER_STATUS command, VCO_CODE field definition (address 10, size 16, lsb 0, signed)*/
   #define  Si2148_TUNER_STATUS_RESPONSE_VCO_CODE_LSB         0
   #define  Si2148_TUNER_STATUS_RESPONSE_VCO_CODE_MASK        0xffff
   #define  Si2148_TUNER_STATUS_RESPONSE_VCO_CODE_SHIFT       16
   /* TUNER_STATUS command, TC field definition (address 2, size 1, lsb 0, unsigned)*/
   #define  Si2148_TUNER_STATUS_RESPONSE_TC_LSB         0
   #define  Si2148_TUNER_STATUS_RESPONSE_TC_MASK        0x01
    #define Si2148_TUNER_STATUS_RESPONSE_TC_BUSY  0
    #define Si2148_TUNER_STATUS_RESPONSE_TC_DONE  1
   /* TUNER_STATUS command, RSSIL field definition (address 2, size 1, lsb 1, unsigned)*/
   #define  Si2148_TUNER_STATUS_RESPONSE_RSSIL_LSB         1
   #define  Si2148_TUNER_STATUS_RESPONSE_RSSIL_MASK        0x01
    #define Si2148_TUNER_STATUS_RESPONSE_RSSIL_LOW  1
    #define Si2148_TUNER_STATUS_RESPONSE_RSSIL_OK   0
   /* TUNER_STATUS command, RSSIH field definition (address 2, size 1, lsb 2, unsigned)*/
   #define  Si2148_TUNER_STATUS_RESPONSE_RSSIH_LSB         2
   #define  Si2148_TUNER_STATUS_RESPONSE_RSSIH_MASK        0x01
    #define Si2148_TUNER_STATUS_RESPONSE_RSSIH_HIGH  1
    #define Si2148_TUNER_STATUS_RESPONSE_RSSIH_OK    0
   /* TUNER_STATUS command, RSSI field definition (address 3, size 8, lsb 0, signed)*/
   #define  Si2148_TUNER_STATUS_RESPONSE_RSSI_LSB         0
   #define  Si2148_TUNER_STATUS_RESPONSE_RSSI_MASK        0xff
   #define  Si2148_TUNER_STATUS_RESPONSE_RSSI_SHIFT       24
   /* TUNER_STATUS command, FREQ field definition (address 4, size 32, lsb 0, unsigned)*/
   #define  Si2148_TUNER_STATUS_RESPONSE_FREQ_LSB         0
   #define  Si2148_TUNER_STATUS_RESPONSE_FREQ_MASK        0xffffffff
   /* TUNER_STATUS command, MODE field definition (address 8, size 1, lsb 0, unsigned)*/
   #define  Si2148_TUNER_STATUS_RESPONSE_MODE_LSB         0
   #define  Si2148_TUNER_STATUS_RESPONSE_MODE_MASK        0x01
    #define Si2148_TUNER_STATUS_RESPONSE_MODE_ATV  1
    #define Si2148_TUNER_STATUS_RESPONSE_MODE_DTV  0

#endif /* Si2148_TUNER_STATUS_CMD */

typedef struct { /* Si2148_CmdObj struct */
	#ifdef    Si2148_AGC_OVERRIDE_CMD
			  Si2148_AGC_OVERRIDE_CMD_struct     agc_override;
	#endif /* Si2148_AGC_OVERRIDE_CMD */
	#ifdef    Si2148_ATV_CW_TEST_CMD
			  Si2148_ATV_CW_TEST_CMD_struct      atv_cw_test;
	#endif /* Si2148_ATV_CW_TEST_CMD */
	#ifdef    Si2148_CONFIG_CLOCKS_CMD
			  Si2148_CONFIG_CLOCKS_CMD_struct    config_clocks;
	#endif /* Si2148_CONFIG_CLOCKS_CMD */
	#ifdef    Si2148_CONFIG_PINS_CMD
			  Si2148_CONFIG_PINS_CMD_struct      config_pins;
	#endif /* Si2148_CONFIG_PINS_CMD */
	#ifdef    Si2148_DTV_RESTART_CMD
			  Si2148_DTV_RESTART_CMD_struct      dtv_restart;
	#endif /* Si2148_DTV_RESTART_CMD */
	#ifdef    Si2148_DTV_STATUS_CMD
			  Si2148_DTV_STATUS_CMD_struct       dtv_status;
	#endif /* Si2148_DTV_STATUS_CMD */
	#ifdef    Si2148_EXIT_BOOTLOADER_CMD
			  Si2148_EXIT_BOOTLOADER_CMD_struct  exit_bootloader;
	#endif /* Si2148_EXIT_BOOTLOADER_CMD */
	#ifdef    Si2148_FINE_TUNE_CMD
			  Si2148_FINE_TUNE_CMD_struct        fine_tune;
	#endif /* Si2148_FINE_TUNE_CMD */
	#ifdef    Si2148_GET_PROPERTY_CMD
			  Si2148_GET_PROPERTY_CMD_struct     get_property;
	#endif /* Si2148_GET_PROPERTY_CMD */
	#ifdef    Si2148_GET_REV_CMD
			  Si2148_GET_REV_CMD_struct          get_rev;
	#endif /* Si2148_GET_REV_CMD */
	#ifdef    Si2148_PART_INFO_CMD
			  Si2148_PART_INFO_CMD_struct        part_info;
	#endif /* Si2148_PART_INFO_CMD */
	#ifdef    Si2148_POWER_DOWN_CMD
			  Si2148_POWER_DOWN_CMD_struct       power_down;
	#endif /* Si2148_POWER_DOWN_CMD */
	#ifdef    Si2148_POWER_DOWN_HW_CMD
			  Si2148_POWER_DOWN_HW_CMD_struct    power_down_hw;
	#endif /* Si2148_POWER_DOWN_HW_CMD */
	#ifdef    Si2148_POWER_UP_CMD
			  Si2148_POWER_UP_CMD_struct         power_up;
	#endif /* Si2148_POWER_UP_CMD */
	#ifdef    Si2148_RAM_CRC_CMD
			  Si2148_RAM_CRC_CMD_struct          ram_crc;
	#endif /* Si2148_RAM_CRC_CMD */
	#ifdef    Si2148_SET_PROPERTY_CMD
			  Si2148_SET_PROPERTY_CMD_struct     set_property;
	#endif /* Si2148_SET_PROPERTY_CMD */
	#ifdef    Si2148_STANDBY_CMD
			  Si2148_STANDBY_CMD_struct          standby;
	#endif /* Si2148_STANDBY_CMD */
	#ifdef    Si2148_TUNER_STATUS_CMD
			  Si2148_TUNER_STATUS_CMD_struct     tuner_status;
	#endif /* Si2148_TUNER_STATUS_CMD */
	#ifdef    Si2148_TUNER_TUNE_FREQ_CMD
			  Si2148_TUNER_TUNE_FREQ_CMD_struct  tuner_tune_freq;
	#endif /* Si2148_TUNER_TUNE_FREQ_CMD */
} Si2148_CmdObj;

typedef struct
{ // Si2146_CmdReplyObj struct
	#ifdef    Si2146_AGC_OVERRIDE_CMD
			  Si2146_AGC_OVERRIDE_CMD_REPLY_struct               agc_override;
	#endif /* Si2146_AGC_OVERRIDE_CMD */
	#ifdef    Si2146_ATV_RESTART_CMD
			  Si2146_ATV_RESTART_CMD_REPLY_struct      atv_restart;
	#endif /* Si2146_ATV_RESTART_CMD */
	#ifdef    Si2146_ATV_STATUS_CMD
			  Si2146_ATV_STATUS_CMD_REPLY_struct       atv_status;
	#endif /* Si2146_ATV_STATUS_CMD */
	#ifdef    Si2146_CONFIG_PINS_CMD
			  Si2146_CONFIG_PINS_CMD_REPLY_struct                config_pins;
	#endif /* Si2146_CONFIG_PINS_CMD */
	#ifdef    Si2146_DTV_RESTART_CMD
			  Si2146_DTV_RESTART_CMD_REPLY_struct                dtv_restart;
	#endif /* Si2146_DTV_RESTART_CMD */
	#ifdef    Si2146_DTV_STATUS_CMD
			  Si2146_DTV_STATUS_CMD_REPLY_struct                 dtv_status;
	#endif /* Si2146_DTV_STATUS_CMD */
	#ifdef    Si2146_EXIT_BOOTLOADER_CMD
			  Si2146_EXIT_BOOTLOADER_CMD_REPLY_struct            exit_bootloader;
	#endif /* Si2146_EXIT_BOOTLOADER_CMD */
	#ifdef    Si2146_FINE_TUNE_CMD
			  Si2146_FINE_TUNE_CMD_REPLY_struct                  fine_tune;
	#endif /* Si2146_FINE_TUNE_CMD */
	#ifdef    Si2146_GET_PROPERTY_CMD
			  Si2146_GET_PROPERTY_CMD_REPLY_struct               get_property;
	#endif /* Si2146_GET_PROPERTY_CMD */
	#ifdef    Si2146_GET_REV_CMD
			  Si2146_GET_REV_CMD_REPLY_struct                    get_rev;
	#endif /* Si2146_GET_REV_CMD */
	#ifdef    Si2146_PART_INFO_CMD
			  Si2146_PART_INFO_CMD_REPLY_struct                  part_info;
	#endif /* Si2146_PART_INFO_CMD */
	#ifdef    Si2146_POWER_DOWN_CMD
			  Si2146_POWER_DOWN_CMD_REPLY_struct                 power_down;
	#endif /* Si2146_POWER_DOWN_CMD */
	#ifdef    Si2146_POWER_UP_CMD
			  Si2146_POWER_UP_CMD_REPLY_struct                   power_up;
	#endif /* Si2146_POWER_UP_CMD */
	#ifdef    Si2146_SET_PROPERTY_CMD
			  Si2146_SET_PROPERTY_CMD_REPLY_struct               set_property;
	#endif /* Si2146_SET_PROPERTY_CMD */
	#ifdef    Si2146_STANDBY_CMD
			  Si2146_STANDBY_CMD_REPLY_struct                    standby;
	#endif /* Si2146_STANDBY_CMD */
	#ifdef    Si2146_TUNER_STATUS_CMD
			  Si2146_TUNER_STATUS_CMD_REPLY_struct               tuner_status;
	#endif /* Si2146_TUNER_STATUS_CMD */
	#ifdef    Si2146_TUNER_TUNE_FREQ_CMD
			  Si2146_TUNER_TUNE_FREQ_CMD_REPLY_struct            tuner_tune_freq;
	#endif /* Si2146_TUNER_TUNE_FREQ_CMD */
} Si2146_CmdReplyObj;

typedef struct
{ // Si2148_CmdReplyObj struct
	#ifdef    Si2148_AGC_OVERRIDE_CMD
			  Si2148_AGC_OVERRIDE_CMD_REPLY_struct     agc_override;
	#endif /* Si2148_AGC_OVERRIDE_CMD */
	#ifdef    Si2148_ATV_CW_TEST_CMD
			  Si2148_ATV_CW_TEST_CMD_REPLY_struct      atv_cw_test;
	#endif /* Si2148_ATV_CW_TEST_CMD */
	#ifdef    Si2148_CONFIG_CLOCKS_CMD
			  Si2148_CONFIG_CLOCKS_CMD_REPLY_struct    config_clocks;
	#endif /* Si2148_CONFIG_CLOCKS_CMD */
	#ifdef    Si2148_CONFIG_PINS_CMD
			  Si2148_CONFIG_PINS_CMD_REPLY_struct      config_pins;
	#endif /* Si2148_CONFIG_PINS_CMD */
	#ifdef    Si2148_DTV_RESTART_CMD
			  Si2148_DTV_RESTART_CMD_REPLY_struct      dtv_restart;
	#endif /* Si2148_DTV_RESTART_CMD */
	#ifdef    Si2148_DTV_STATUS_CMD
			  Si2148_DTV_STATUS_CMD_REPLY_struct       dtv_status;
	#endif /* Si2148_DTV_STATUS_CMD */
	#ifdef    Si2148_EXIT_BOOTLOADER_CMD
			  Si2148_EXIT_BOOTLOADER_CMD_REPLY_struct  exit_bootloader;
	#endif /* Si2148_EXIT_BOOTLOADER_CMD */
	#ifdef    Si2148_FINE_TUNE_CMD
			  Si2148_FINE_TUNE_CMD_REPLY_struct        fine_tune;
	#endif /* Si2148_FINE_TUNE_CMD */
	#ifdef    Si2148_GET_PROPERTY_CMD
			  Si2148_GET_PROPERTY_CMD_REPLY_struct     get_property;
	#endif /* Si2148_GET_PROPERTY_CMD */
	#ifdef    Si2148_GET_REV_CMD
			  Si2148_GET_REV_CMD_REPLY_struct          get_rev;
	#endif /* Si2148_GET_REV_CMD */
	#ifdef    Si2148_PART_INFO_CMD
			  Si2148_PART_INFO_CMD_REPLY_struct        part_info;
	#endif /* Si2148_PART_INFO_CMD */
	#ifdef    Si2148_POWER_DOWN_CMD
			  Si2148_POWER_DOWN_CMD_REPLY_struct       power_down;
	#endif /* Si2148_POWER_DOWN_CMD */
	#ifdef    Si2148_POWER_DOWN_HW_CMD
			  Si2148_POWER_DOWN_HW_CMD_REPLY_struct    power_down_hw;
	#endif /* Si2148_POWER_DOWN_HW_CMD */
	#ifdef    Si2148_POWER_UP_CMD
			  Si2148_POWER_UP_CMD_REPLY_struct         power_up;
	#endif /* Si2148_POWER_UP_CMD */
	#ifdef    Si2148_RAM_CRC_CMD
			  Si2148_RAM_CRC_CMD_REPLY_struct          ram_crc;
	#endif /* Si2148_RAM_CRC_CMD */
	#ifdef    Si2148_SET_PROPERTY_CMD
			  Si2148_SET_PROPERTY_CMD_REPLY_struct     set_property;
	#endif /* Si2148_SET_PROPERTY_CMD */
	#ifdef    Si2148_STANDBY_CMD
			  Si2148_STANDBY_CMD_REPLY_struct          standby;
	#endif /* Si2148_STANDBY_CMD */
	#ifdef    Si2148_TUNER_STATUS_CMD
			  Si2148_TUNER_STATUS_CMD_REPLY_struct     tuner_status;
	#endif /* Si2148_TUNER_STATUS_CMD */
	#ifdef    Si2148_TUNER_TUNE_FREQ_CMD
			  Si2148_TUNER_TUNE_FREQ_CMD_REPLY_struct  tuner_tune_freq;
	#endif /* Si2148_TUNER_TUNE_FREQ_CMD */
} Si2148_CmdReplyObj;

#define   Si2146_DTV_AGC_FREEZE_INPUT_PROP 0x0711
#ifdef    Si2146_DTV_AGC_FREEZE_INPUT_PROP
  #define Si2146_DTV_AGC_FREEZE_INPUT_PROP_CODE 0x000711


    typedef struct { /* Si2146_DTV_AGC_FREEZE_INPUT_PROP_struct */
      unsigned char   level;
      unsigned char   pin;
   } Si2146_DTV_AGC_FREEZE_INPUT_PROP_struct;

   /* DTV_AGC_FREEZE_INPUT property, LEVEL field definition (NO TITLE)*/
   #define  Si2146_DTV_AGC_FREEZE_INPUT_PROP_LEVEL_LSB         0
   #define  Si2146_DTV_AGC_FREEZE_INPUT_PROP_LEVEL_MASK        0x01
   #define  Si2146_DTV_AGC_FREEZE_INPUT_PROP_LEVEL_DEFAULT    0
    #define Si2146_DTV_AGC_FREEZE_INPUT_PROP_LEVEL_LOW   0
    #define Si2146_DTV_AGC_FREEZE_INPUT_PROP_LEVEL_HIGH  1

   /* DTV_AGC_FREEZE_INPUT property, PIN field definition (NO TITLE)*/
   #define  Si2146_DTV_AGC_FREEZE_INPUT_PROP_PIN_LSB         1
   #define  Si2146_DTV_AGC_FREEZE_INPUT_PROP_PIN_MASK        0x03
   #define  Si2146_DTV_AGC_FREEZE_INPUT_PROP_PIN_DEFAULT    0
    #define Si2146_DTV_AGC_FREEZE_INPUT_PROP_PIN_NONE   0
    #define Si2146_DTV_AGC_FREEZE_INPUT_PROP_PIN_GPIO1  1
    #define Si2146_DTV_AGC_FREEZE_INPUT_PROP_PIN_GPIO2  2
    #define Si2146_DTV_AGC_FREEZE_INPUT_PROP_PIN_GPIO3  3

#endif /* Si2146_DTV_AGC_FREEZE_INPUT_PROP */

#define   Si2146_DTV_MODE_PROP 0x0703

#ifdef    Si2146_DTV_MODE_PROP
  #define Si2146_DTV_MODE_PROP_CODE 0x000703


    typedef struct { /* Si2146_DTV_MODE_PROP_struct */
      unsigned char   bw;
      unsigned char   invert_spectrum;
      unsigned char   modulation;
   } Si2146_DTV_MODE_PROP_struct;

   /* DTV_MODE property, BW field definition (NO TITLE)*/
   #define  Si2146_DTV_MODE_PROP_BW_LSB         0
   #define  Si2146_DTV_MODE_PROP_BW_MASK        0x0f
   #define  Si2146_DTV_MODE_PROP_BW_DEFAULT    8
    #define Si2146_DTV_MODE_PROP_BW_BW_6MHZ  6
    #define Si2146_DTV_MODE_PROP_BW_BW_7MHZ  7
    #define Si2146_DTV_MODE_PROP_BW_BW_8MHZ  8

   /* DTV_MODE property, INVERT_SPECTRUM field definition (NO TITLE)*/
   #define  Si2146_DTV_MODE_PROP_INVERT_SPECTRUM_LSB         8
   #define  Si2146_DTV_MODE_PROP_INVERT_SPECTRUM_MASK        0x01
   #define  Si2146_DTV_MODE_PROP_INVERT_SPECTRUM_DEFAULT    0
    #define Si2146_DTV_MODE_PROP_INVERT_SPECTRUM_NORMAL    0
    #define Si2146_DTV_MODE_PROP_INVERT_SPECTRUM_INVERTED  1

   /* DTV_MODE property, MODULATION field definition (NO TITLE)*/
   #define  Si2146_DTV_MODE_PROP_MODULATION_LSB         4
   #define  Si2146_DTV_MODE_PROP_MODULATION_MASK        0x0f
   #define  Si2146_DTV_MODE_PROP_MODULATION_DEFAULT    2
    #define Si2146_DTV_MODE_PROP_MODULATION_ATSC    0
    #define Si2146_DTV_MODE_PROP_MODULATION_QAM_US  1
    #define Si2146_DTV_MODE_PROP_MODULATION_DVBT    2
    #define Si2146_DTV_MODE_PROP_MODULATION_DVBC    3
    #define Si2146_DTV_MODE_PROP_MODULATION_ISDBT   4
    #define Si2146_DTV_MODE_PROP_MODULATION_ISDBC   5
    #define Si2146_DTV_MODE_PROP_MODULATION_DTMB    6

#endif /* Si2146_DTV_MODE_PROP */

#define   Si2146_CRYSTAL_TRIM_PROP 0x0402

#ifdef    Si2146_CRYSTAL_TRIM_PROP
  #define Si2146_CRYSTAL_TRIM_PROP_CODE 0x000402


    typedef struct { /* Si2146_CRYSTAL_TRIM_PROP_struct */
      unsigned char   xo_cap;
   } Si2146_CRYSTAL_TRIM_PROP_struct;

   /* CRYSTAL_TRIM property, XO_CAP field definition (NO TITLE)*/
   #define  Si2146_CRYSTAL_TRIM_PROP_XO_CAP_LSB         0
   #define  Si2146_CRYSTAL_TRIM_PROP_XO_CAP_MASK        0x0f
   #define  Si2146_CRYSTAL_TRIM_PROP_XO_CAP_DEFAULT    8
    #define Si2146_CRYSTAL_TRIM_PROP_XO_CAP_XO_CAP_MIN  0
    #define Si2146_CRYSTAL_TRIM_PROP_XO_CAP_XO_CAP_MAX  15

#endif /* Si2146_CRYSTAL_TRIM_PROP */

#define   Si2146_MASTER_IEN_PROP 0x0401

#ifdef    Si2146_MASTER_IEN_PROP
  #define Si2146_MASTER_IEN_PROP_CODE 0x000401


    typedef struct { /* Si2146_MASTER_IEN_PROP_struct */
      unsigned char   atvien;
      unsigned char   ctsien;
      unsigned char   dtvien;
      unsigned char   errien;
      unsigned char   tunien;
   } Si2146_MASTER_IEN_PROP_struct;

   /* MASTER_IEN property, ATVIEN field definition (NO TITLE)*/
   #define  Si2146_MASTER_IEN_PROP_ATVIEN_LSB         1
   #define  Si2146_MASTER_IEN_PROP_ATVIEN_MASK        0x01
   #define  Si2146_MASTER_IEN_PROP_ATVIEN_DEFAULT    0
    #define Si2146_MASTER_IEN_PROP_ATVIEN_OFF  0
    #define Si2146_MASTER_IEN_PROP_ATVIEN_ON   1

   /* MASTER_IEN property, CTSIEN field definition (NO TITLE)*/
   #define  Si2146_MASTER_IEN_PROP_CTSIEN_LSB         7
   #define  Si2146_MASTER_IEN_PROP_CTSIEN_MASK        0x01
   #define  Si2146_MASTER_IEN_PROP_CTSIEN_DEFAULT    0
    #define Si2146_MASTER_IEN_PROP_CTSIEN_OFF  0
    #define Si2146_MASTER_IEN_PROP_CTSIEN_ON   1

   /* MASTER_IEN property, DTVIEN field definition (NO TITLE)*/
   #define  Si2146_MASTER_IEN_PROP_DTVIEN_LSB         2
   #define  Si2146_MASTER_IEN_PROP_DTVIEN_MASK        0x01
   #define  Si2146_MASTER_IEN_PROP_DTVIEN_DEFAULT    0
    #define Si2146_MASTER_IEN_PROP_DTVIEN_OFF  0
    #define Si2146_MASTER_IEN_PROP_DTVIEN_ON   1

   /* MASTER_IEN property, ERRIEN field definition (NO TITLE)*/
   #define  Si2146_MASTER_IEN_PROP_ERRIEN_LSB         6
   #define  Si2146_MASTER_IEN_PROP_ERRIEN_MASK        0x01
   #define  Si2146_MASTER_IEN_PROP_ERRIEN_DEFAULT    0
    #define Si2146_MASTER_IEN_PROP_ERRIEN_OFF  0
    #define Si2146_MASTER_IEN_PROP_ERRIEN_ON   1

   /* MASTER_IEN property, TUNIEN field definition (NO TITLE)*/
   #define  Si2146_MASTER_IEN_PROP_TUNIEN_LSB         0
   #define  Si2146_MASTER_IEN_PROP_TUNIEN_MASK        0x01
   #define  Si2146_MASTER_IEN_PROP_TUNIEN_DEFAULT    0
    #define Si2146_MASTER_IEN_PROP_TUNIEN_OFF  0
    #define Si2146_MASTER_IEN_PROP_TUNIEN_ON   1

#endif // Si2146_MASTER_IEN_PROP

#define Si2146_DTV_AGC_SPEED_PROP 0x0708

#ifdef Si2146_DTV_AGC_SPEED_PROP
	#define Si2146_DTV_AGC_SPEED_PROP_CODE 0x000708
	typedef struct
	{ // Si2146_DTV_AGC_SPEED_PROP_struct
		unsigned char   agc_decim;
		unsigned char   if_agc_speed;
	} Si2146_DTV_AGC_SPEED_PROP_struct;
	// DTV_AGC_SPEED property, AGC_DECIM field definition (NO TITLE)
	#define  Si2146_DTV_AGC_SPEED_PROP_AGC_DECIM_LSB         8
	#define  Si2146_DTV_AGC_SPEED_PROP_AGC_DECIM_MASK        0x03
	#define  Si2146_DTV_AGC_SPEED_PROP_AGC_DECIM_DEFAULT    0
	#define Si2146_DTV_AGC_SPEED_PROP_AGC_DECIM_OFF  0
	#define Si2146_DTV_AGC_SPEED_PROP_AGC_DECIM_2    1
	#define Si2146_DTV_AGC_SPEED_PROP_AGC_DECIM_4    2
	#define Si2146_DTV_AGC_SPEED_PROP_AGC_DECIM_8    3
	// DTV_AGC_SPEED property, IF_AGC_SPEED field definition (NO TITLE)
	#define  Si2146_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_LSB         0
	#define  Si2146_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_MASK        0xff
	#define  Si2146_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_DEFAULT    0
	#define Si2146_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_AUTO  0
	#define Si2146_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_39    39
	#define Si2146_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_54    54
	#define Si2146_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_63    63
	#define Si2146_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_89    89
	#define Si2146_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_105   105
	#define Si2146_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_121   121
	#define Si2146_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_137   137
	#define Si2146_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_158   158
	#define Si2146_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_172   172
	#define Si2146_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_185   185
	#define Si2146_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_196   196
	#define Si2146_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_206   206
	#define Si2146_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_216   216
	#define Si2146_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_219   219
	#define Si2146_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_222   222
#endif // Si2146_DTV_AGC_SPEED_PROP

#define Si2146_DTV_CONFIG_IF_PORT_PROP 0x0702

#ifdef Si2146_DTV_CONFIG_IF_PORT_PROP
	#define Si2146_DTV_CONFIG_IF_PORT_PROP_CODE 0x000702
	typedef struct
	{ // Si2146_DTV_CONFIG_IF_PORT_PROP_struct
		unsigned char   dtv_agc_source;
		unsigned char   dtv_out_type;
	} Si2146_DTV_CONFIG_IF_PORT_PROP_struct;
	// DTV_CONFIG_IF_PORT property, DTV_AGC_SOURCE field definition (NO TITLE)
	#define  Si2146_DTV_CONFIG_IF_PORT_PROP_DTV_AGC_SOURCE_LSB         8
	#define  Si2146_DTV_CONFIG_IF_PORT_PROP_DTV_AGC_SOURCE_MASK        0x07
	#define  Si2146_DTV_CONFIG_IF_PORT_PROP_DTV_AGC_SOURCE_DEFAULT    0
	#define Si2146_DTV_CONFIG_IF_PORT_PROP_DTV_AGC_SOURCE_INTERNAL       0
	#define Si2146_DTV_CONFIG_IF_PORT_PROP_DTV_AGC_SOURCE_DLIF_AGC_3DB   1
	// DTV_CONFIG_IF_PORT property, DTV_OUT_TYPE field definition (NO TITLE)
	#define  Si2146_DTV_CONFIG_IF_PORT_PROP_DTV_OUT_TYPE_LSB         0
	#define  Si2146_DTV_CONFIG_IF_PORT_PROP_DTV_OUT_TYPE_MASK        0x0f
	#define  Si2146_DTV_CONFIG_IF_PORT_PROP_DTV_OUT_TYPE_DEFAULT    0
	#define Si2146_DTV_CONFIG_IF_PORT_PROP_DTV_OUT_TYPE_LIF_IF1      0
	#define Si2146_DTV_CONFIG_IF_PORT_PROP_DTV_OUT_TYPE_LIF_SE_IF1A  4
#endif // Si2146_DTV_CONFIG_IF_PORT_PROP

#define Si2146_DTV_EXT_AGC_PROP 0x0705

#ifdef Si2146_DTV_EXT_AGC_PROP
	#define Si2146_DTV_EXT_AGC_PROP_CODE 0x000705
	typedef struct
	{ // Si2146_DTV_EXT_AGC_PROP_struct
		unsigned char   max_10mv;
		unsigned char   min_10mv;
	} Si2146_DTV_EXT_AGC_PROP_struct;
	// DTV_EXT_AGC property, MAX_10MV field definition (NO TITLE)
	#define  Si2146_DTV_EXT_AGC_PROP_MAX_10MV_LSB         8
	#define  Si2146_DTV_EXT_AGC_PROP_MAX_10MV_MASK        0xff
	#define  Si2146_DTV_EXT_AGC_PROP_MAX_10MV_DEFAULT    200
	#define Si2146_DTV_EXT_AGC_PROP_MAX_10MV_MAX_10MV_MIN  0
	#define Si2146_DTV_EXT_AGC_PROP_MAX_10MV_MAX_10MV_MAX  215
	// DTV_EXT_AGC property, MIN_10MV field definition (NO TITLE)
	#define  Si2146_DTV_EXT_AGC_PROP_MIN_10MV_LSB         0
	#define  Si2146_DTV_EXT_AGC_PROP_MIN_10MV_MASK        0xff
	#define  Si2146_DTV_EXT_AGC_PROP_MIN_10MV_DEFAULT    50
	#define Si2146_DTV_EXT_AGC_PROP_MIN_10MV_MIN_10MV_MIN  0
	#define Si2146_DTV_EXT_AGC_PROP_MIN_10MV_MIN_10MV_MAX  215
#endif // Si2146_DTV_EXT_AGC_PROP

#define Si2146_DTV_IEN_PROP 0x0701

#ifdef Si2146_DTV_IEN_PROP
	#define Si2146_DTV_IEN_PROP_CODE 0x000701
	typedef struct
	{ // Si2146_DTV_IEN_PROP_struct
		unsigned char   chlien;
	} Si2146_DTV_IEN_PROP_struct;
	// DTV_IEN property, CHLIEN field definition (NO TITLE)
	#define  Si2146_DTV_IEN_PROP_CHLIEN_LSB         0
	#define  Si2146_DTV_IEN_PROP_CHLIEN_MASK        0x01
	#define  Si2146_DTV_IEN_PROP_CHLIEN_DEFAULT    0
	#define Si2146_DTV_IEN_PROP_CHLIEN_DISABLE  0
	#define Si2146_DTV_IEN_PROP_CHLIEN_ENABLE   1
#endif // Si2146_DTV_IEN_PROP

#define Si2146_DTV_INITIAL_AGC_SPEED_PROP 0x070d

#ifdef Si2146_DTV_INITIAL_AGC_SPEED_PROP
	#define Si2146_DTV_INITIAL_AGC_SPEED_PROP_CODE 0x00070d
	typedef struct
	{ // Si2146_DTV_INITIAL_AGC_SPEED_PROP_struct
		unsigned char   agc_decim;
		unsigned char   if_agc_speed;
	} Si2146_DTV_INITIAL_AGC_SPEED_PROP_struct;
	// DTV_INITIAL_AGC_SPEED property, AGC_DECIM field definition (NO TITLE)
	#define  Si2146_DTV_INITIAL_AGC_SPEED_PROP_AGC_DECIM_LSB         8
	#define  Si2146_DTV_INITIAL_AGC_SPEED_PROP_AGC_DECIM_MASK        0x03
	#define  Si2146_DTV_INITIAL_AGC_SPEED_PROP_AGC_DECIM_DEFAULT    0
	#define Si2146_DTV_INITIAL_AGC_SPEED_PROP_AGC_DECIM_OFF  0
	#define Si2146_DTV_INITIAL_AGC_SPEED_PROP_AGC_DECIM_2    1
	#define Si2146_DTV_INITIAL_AGC_SPEED_PROP_AGC_DECIM_4    2
	#define Si2146_DTV_INITIAL_AGC_SPEED_PROP_AGC_DECIM_8    3
	// DTV_INITIAL_AGC_SPEED property, IF_AGC_SPEED field definition (NO TITLE)
	#define  Si2146_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_LSB         0
	#define  Si2146_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_MASK        0xff
	#define  Si2146_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_DEFAULT    0
	#define Si2146_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_AUTO  0
	#define Si2146_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_39    39
	#define Si2146_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_54    54
	#define Si2146_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_63    63
	#define Si2146_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_89    89
	#define Si2146_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_105   105
	#define Si2146_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_121   121
	#define Si2146_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_137   137
	#define Si2146_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_158   158
	#define Si2146_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_172   172
	#define Si2146_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_185   185
	#define Si2146_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_196   196
	#define Si2146_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_206   206
	#define Si2146_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_216   216
	#define Si2146_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_219   219
	#define Si2146_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_222   222
#endif // Si2146_DTV_INITIAL_AGC_SPEED_PROP

#define Si2146_DTV_INITIAL_AGC_SPEED_PERIOD_PROP 0x070e

#ifdef Si2146_DTV_INITIAL_AGC_SPEED_PERIOD_PROP
	#define Si2146_DTV_INITIAL_AGC_SPEED_PERIOD_PROP_CODE 0x00070e
	typedef struct
	{ // Si2146_DTV_INITIAL_AGC_SPEED_PERIOD_PROP_struct
		unsigned int    period;
	} Si2146_DTV_INITIAL_AGC_SPEED_PERIOD_PROP_struct;
	// DTV_INITIAL_AGC_SPEED_PERIOD property, PERIOD field definition (NO TITLE)
	#define  Si2146_DTV_INITIAL_AGC_SPEED_PERIOD_PROP_PERIOD_LSB         0
	#define  Si2146_DTV_INITIAL_AGC_SPEED_PERIOD_PROP_PERIOD_MASK        0xffff
	#define  Si2146_DTV_INITIAL_AGC_SPEED_PERIOD_PROP_PERIOD_DEFAULT    0
	#define Si2146_DTV_INITIAL_AGC_SPEED_PERIOD_PROP_PERIOD_PERIOD_MIN  0
	#define Si2146_DTV_INITIAL_AGC_SPEED_PERIOD_PROP_PERIOD_PERIOD_MAX  65535
#endif // Si2146_DTV_INITIAL_AGC_SPEED_PERIOD_PROP

#define Si2146_DTV_INT_SENSE_PROP 0x070a

#ifdef Si2146_DTV_INT_SENSE_PROP
	#define Si2146_DTV_INT_SENSE_PROP_CODE 0x00070a
	typedef struct
	{ // Si2146_DTV_INT_SENSE_PROP_struct
		unsigned char   chlnegen;
		unsigned char   chlposen;
	} Si2146_DTV_INT_SENSE_PROP_struct;
	// DTV_INT_SENSE property, CHLNEGEN field definition (NO TITLE)
	#define  Si2146_DTV_INT_SENSE_PROP_CHLNEGEN_LSB         0
	#define  Si2146_DTV_INT_SENSE_PROP_CHLNEGEN_MASK        0x01
	#define  Si2146_DTV_INT_SENSE_PROP_CHLNEGEN_DEFAULT    0
	#define Si2146_DTV_INT_SENSE_PROP_CHLNEGEN_DISABLE  0
	#define Si2146_DTV_INT_SENSE_PROP_CHLNEGEN_ENABLE   1
	// DTV_INT_SENSE property, CHLPOSEN field definition (NO TITLE)
	#define  Si2146_DTV_INT_SENSE_PROP_CHLPOSEN_LSB         8
	#define  Si2146_DTV_INT_SENSE_PROP_CHLPOSEN_MASK        0x01
	#define  Si2146_DTV_INT_SENSE_PROP_CHLPOSEN_DEFAULT    1
	#define Si2146_DTV_INT_SENSE_PROP_CHLPOSEN_DISABLE  0
	#define Si2146_DTV_INT_SENSE_PROP_CHLPOSEN_ENABLE   1
#endif // Si2146_DTV_INT_SENSE_PROP

#define Si2146_DTV_LIF_FREQ_PROP 0x0706

#ifdef Si2146_DTV_LIF_FREQ_PROP
	#define Si2146_DTV_LIF_FREQ_PROP_CODE 0x000706
	typedef struct
	{ // Si2146_DTV_LIF_FREQ_PROP_struct
		unsigned int    offset;
	} Si2146_DTV_LIF_FREQ_PROP_struct;
	// DTV_LIF_FREQ property, OFFSET field definition (NO TITLE)
	#define  Si2146_DTV_LIF_FREQ_PROP_OFFSET_LSB         0
	#define  Si2146_DTV_LIF_FREQ_PROP_OFFSET_MASK        0xffff
	#define  Si2146_DTV_LIF_FREQ_PROP_OFFSET_DEFAULT    5000
	#define Si2146_DTV_LIF_FREQ_PROP_OFFSET_OFFSET_MIN  0
	#define Si2146_DTV_LIF_FREQ_PROP_OFFSET_OFFSET_MAX  7000
#endif // Si2146_DTV_LIF_FREQ_PROP

#define Si2146_DTV_LIF_OUT_PROP 0x0707

#ifdef Si2146_DTV_LIF_OUT_PROP
	#define Si2146_DTV_LIF_OUT_PROP_CODE 0x000707
	typedef struct
	{ // Si2146_DTV_LIF_OUT_PROP_struct
		unsigned char   amp;
		unsigned char   offset;
	} Si2146_DTV_LIF_OUT_PROP_struct;
	// DTV_LIF_OUT property, AMP field definition (NO TITLE)
	#define  Si2146_DTV_LIF_OUT_PROP_AMP_LSB         8
	#define  Si2146_DTV_LIF_OUT_PROP_AMP_MASK        0xff
	#define  Si2146_DTV_LIF_OUT_PROP_AMP_DEFAULT    27
	#define Si2146_DTV_LIF_OUT_PROP_AMP_AMP_MIN  0
	#define Si2146_DTV_LIF_OUT_PROP_AMP_AMP_MAX  255
	// DTV_LIF_OUT property, OFFSET field definition (NO TITLE)
	#define  Si2146_DTV_LIF_OUT_PROP_OFFSET_LSB         0
	#define  Si2146_DTV_LIF_OUT_PROP_OFFSET_MASK        0xff
	#define  Si2146_DTV_LIF_OUT_PROP_OFFSET_DEFAULT    148
	#define Si2146_DTV_LIF_OUT_PROP_OFFSET_OFFSET_MIN  0
	#define Si2146_DTV_LIF_OUT_PROP_OFFSET_OFFSET_MAX  255
#endif // Si2146_DTV_LIF_OUT_PROP

#define Si2146_DTV_RF_TOP_PROP 0x0709

#ifdef    Si2146_DTV_RF_TOP_PROP
	#define Si2146_DTV_RF_TOP_PROP_CODE 0x000709
	typedef struct
	{ // Si2146_DTV_RF_TOP_PROP_struct
		unsigned char   dtv_rf_top;
	} Si2146_DTV_RF_TOP_PROP_struct;
	// DTV_RF_TOP property, DTV_RF_TOP field definition (NO TITLE)
	#define  Si2146_DTV_RF_TOP_PROP_DTV_RF_TOP_LSB         0
	#define  Si2146_DTV_RF_TOP_PROP_DTV_RF_TOP_MASK        0xff
	#define  Si2146_DTV_RF_TOP_PROP_DTV_RF_TOP_DEFAULT    0
	#define Si2146_DTV_RF_TOP_PROP_DTV_RF_TOP_AUTO   0
	#define Si2146_DTV_RF_TOP_PROP_DTV_RF_TOP_0DB    6
	#define Si2146_DTV_RF_TOP_PROP_DTV_RF_TOP_M1DB   7
	#define Si2146_DTV_RF_TOP_PROP_DTV_RF_TOP_M2DB   8
	#define Si2146_DTV_RF_TOP_PROP_DTV_RF_TOP_M4DB   10
	#define Si2146_DTV_RF_TOP_PROP_DTV_RF_TOP_M5DB   11
	#define Si2146_DTV_RF_TOP_PROP_DTV_RF_TOP_M6DB   12
	#define Si2146_DTV_RF_TOP_PROP_DTV_RF_TOP_M7DB   13
	#define Si2146_DTV_RF_TOP_PROP_DTV_RF_TOP_M8DB   14
	#define Si2146_DTV_RF_TOP_PROP_DTV_RF_TOP_M9DB   15
#endif // Si2146_DTV_RF_TOP_PROP

#define Si2146_DTV_RSQ_RSSI_THRESHOLD_PROP 0x0704

#ifdef Si2146_DTV_RSQ_RSSI_THRESHOLD_PROP
	#define Si2146_DTV_RSQ_RSSI_THRESHOLD_PROP_CODE 0x000704
	typedef struct
	{ // Si2146_DTV_RSQ_RSSI_THRESHOLD_PROP_struct
		char   hi;
		char   lo;
	} Si2146_DTV_RSQ_RSSI_THRESHOLD_PROP_struct;
	// DTV_RSQ_RSSI_THRESHOLD property, HI field definition (NO TITLE)
	#define  Si2146_DTV_RSQ_RSSI_THRESHOLD_PROP_HI_LSB         8
	#define  Si2146_DTV_RSQ_RSSI_THRESHOLD_PROP_HI_MASK        0xff
	#define  Si2146_DTV_RSQ_RSSI_THRESHOLD_PROP_HI_DEFAULT    0
	#define Si2146_DTV_RSQ_RSSI_THRESHOLD_PROP_HI_HI_MIN  -128
	#define Si2146_DTV_RSQ_RSSI_THRESHOLD_PROP_HI_HI_MAX  127
	// DTV_RSQ_RSSI_THRESHOLD property, LO field definition (NO TITLE)
	#define  Si2146_DTV_RSQ_RSSI_THRESHOLD_PROP_LO_LSB         0
	#define  Si2146_DTV_RSQ_RSSI_THRESHOLD_PROP_LO_MASK        0xff
	#define  Si2146_DTV_RSQ_RSSI_THRESHOLD_PROP_LO_DEFAULT    -80
	#define Si2146_DTV_RSQ_RSSI_THRESHOLD_PROP_LO_LO_MIN  -128
	#define Si2146_DTV_RSQ_RSSI_THRESHOLD_PROP_LO_LO_MAX  127
#endif // Si2146_DTV_RSQ_RSSI_THRESHOLD_PROP

#define Si2146_TUNER_BLOCKED_VCO_PROP 0x0504

#ifdef Si2146_TUNER_BLOCKED_VCO_PROP
	#define Si2146_TUNER_BLOCKED_VCO_PROP_CODE 0x000504
	typedef struct
	{ // Si2146_TUNER_BLOCKED_VCO_PROP_struct
		int    vco_code;
	} Si2146_TUNER_BLOCKED_VCO_PROP_struct;
	// TUNER_BLOCKED_VCO property, VCO_CODE field definition (NO TITLE)
	#define  Si2146_TUNER_BLOCKED_VCO_PROP_VCO_CODE_LSB         0
	#define  Si2146_TUNER_BLOCKED_VCO_PROP_VCO_CODE_MASK        0xffff
	#define  Si2146_TUNER_BLOCKED_VCO_PROP_VCO_CODE_DEFAULT    0x8000
	#define Si2146_TUNER_BLOCKED_VCO_PROP_VCO_CODE_VCO_CODE_MIN  -32768
	#define Si2146_TUNER_BLOCKED_VCO_PROP_VCO_CODE_VCO_CODE_MAX  32767
#endif // Si2146_TUNER_BLOCKED_VCO_PROP

#define Si2146_TUNER_IEN_PROP 0x0501

#ifdef Si2146_TUNER_IEN_PROP
	#define Si2146_TUNER_IEN_PROP_CODE 0x000501
	typedef struct
	{ // Si2146_TUNER_IEN_PROP_struct
		unsigned char   rssihien;
		unsigned char   rssilien;
		unsigned char   tcien;
	} Si2146_TUNER_IEN_PROP_struct;
	// TUNER_IEN property, RSSIHIEN field definition (NO TITLE)
	#define  Si2146_TUNER_IEN_PROP_RSSIHIEN_LSB         2
	#define  Si2146_TUNER_IEN_PROP_RSSIHIEN_MASK        0x01
	#define  Si2146_TUNER_IEN_PROP_RSSIHIEN_DEFAULT    0
	#define Si2146_TUNER_IEN_PROP_RSSIHIEN_DISABLE  0
	#define Si2146_TUNER_IEN_PROP_RSSIHIEN_ENABLE   1
	// TUNER_IEN property, RSSILIEN field definition (NO TITLE)
	#define  Si2146_TUNER_IEN_PROP_RSSILIEN_LSB         1
	#define  Si2146_TUNER_IEN_PROP_RSSILIEN_MASK        0x01
	#define  Si2146_TUNER_IEN_PROP_RSSILIEN_DEFAULT    0
	#define Si2146_TUNER_IEN_PROP_RSSILIEN_DISABLE  0
	#define Si2146_TUNER_IEN_PROP_RSSILIEN_ENABLE   1
	// TUNER_IEN property, TCIEN field definition (NO TITLE)
	#define  Si2146_TUNER_IEN_PROP_TCIEN_LSB         0
	#define  Si2146_TUNER_IEN_PROP_TCIEN_MASK        0x01
	#define  Si2146_TUNER_IEN_PROP_TCIEN_DEFAULT    0
	#define Si2146_TUNER_IEN_PROP_TCIEN_DISABLE  0
	#define Si2146_TUNER_IEN_PROP_TCIEN_ENABLE   1
#endif // Si2146_TUNER_IEN_PROP

#define Si2146_TUNER_INT_SENSE_PROP 0x0505

#ifdef Si2146_TUNER_INT_SENSE_PROP
	#define Si2146_TUNER_INT_SENSE_PROP_CODE 0x000505
	typedef struct
	{ // Si2146_TUNER_INT_SENSE_PROP_struct
		unsigned char   rssihnegen;
		unsigned char   rssihposen;
		unsigned char   rssilnegen;
		unsigned char   rssilposen;
		unsigned char   tcnegen;
		unsigned char   tcposen;
	} Si2146_TUNER_INT_SENSE_PROP_struct;
	// TUNER_INT_SENSE property, RSSIHNEGEN field definition (NO TITLE)
	#define  Si2146_TUNER_INT_SENSE_PROP_RSSIHNEGEN_LSB         2
	#define  Si2146_TUNER_INT_SENSE_PROP_RSSIHNEGEN_MASK        0x01
	#define  Si2146_TUNER_INT_SENSE_PROP_RSSIHNEGEN_DEFAULT    0
	#define Si2146_TUNER_INT_SENSE_PROP_RSSIHNEGEN_DISABLE  0
	#define Si2146_TUNER_INT_SENSE_PROP_RSSIHNEGEN_ENABLE   1
	// TUNER_INT_SENSE property, RSSIHPOSEN field definition (NO TITLE)
	#define  Si2146_TUNER_INT_SENSE_PROP_RSSIHPOSEN_LSB         10
	#define  Si2146_TUNER_INT_SENSE_PROP_RSSIHPOSEN_MASK        0x01
	#define  Si2146_TUNER_INT_SENSE_PROP_RSSIHPOSEN_DEFAULT    1
	#define Si2146_TUNER_INT_SENSE_PROP_RSSIHPOSEN_DISABLE  0
	#define Si2146_TUNER_INT_SENSE_PROP_RSSIHPOSEN_ENABLE   1
	// TUNER_INT_SENSE property, RSSILNEGEN field definition (NO TITLE)
	#define  Si2146_TUNER_INT_SENSE_PROP_RSSILNEGEN_LSB         1
	#define  Si2146_TUNER_INT_SENSE_PROP_RSSILNEGEN_MASK        0x01
	#define  Si2146_TUNER_INT_SENSE_PROP_RSSILNEGEN_DEFAULT    0
	#define Si2146_TUNER_INT_SENSE_PROP_RSSILNEGEN_DISABLE  0
	#define Si2146_TUNER_INT_SENSE_PROP_RSSILNEGEN_ENABLE   1
	// TUNER_INT_SENSE property, RSSILPOSEN field definition (NO TITLE)
	#define  Si2146_TUNER_INT_SENSE_PROP_RSSILPOSEN_LSB         9
	#define  Si2146_TUNER_INT_SENSE_PROP_RSSILPOSEN_MASK        0x01
	#define  Si2146_TUNER_INT_SENSE_PROP_RSSILPOSEN_DEFAULT    1
	#define Si2146_TUNER_INT_SENSE_PROP_RSSILPOSEN_DISABLE  0
	#define Si2146_TUNER_INT_SENSE_PROP_RSSILPOSEN_ENABLE   1
	// TUNER_INT_SENSE property, TCNEGEN field definition (NO TITLE)
	#define  Si2146_TUNER_INT_SENSE_PROP_TCNEGEN_LSB         0
	#define  Si2146_TUNER_INT_SENSE_PROP_TCNEGEN_MASK        0x01
	#define  Si2146_TUNER_INT_SENSE_PROP_TCNEGEN_DEFAULT    0
	#define Si2146_TUNER_INT_SENSE_PROP_TCNEGEN_DISABLE  0
	#define Si2146_TUNER_INT_SENSE_PROP_TCNEGEN_ENABLE   1
	// TUNER_INT_SENSE property, TCPOSEN field definition (NO TITLE)
	#define  Si2146_TUNER_INT_SENSE_PROP_TCPOSEN_LSB         8
	#define  Si2146_TUNER_INT_SENSE_PROP_TCPOSEN_MASK        0x01
	#define  Si2146_TUNER_INT_SENSE_PROP_TCPOSEN_DEFAULT    1
	#define Si2146_TUNER_INT_SENSE_PROP_TCPOSEN_DISABLE  0
	#define Si2146_TUNER_INT_SENSE_PROP_TCPOSEN_ENABLE   1
#endif // Si2146_TUNER_INT_SENSE_PROP

#define Si2146_TUNER_LO_INJECTION_PROP 0x0506

#ifdef Si2146_TUNER_LO_INJECTION_PROP
	#define Si2146_TUNER_LO_INJECTION_PROP_CODE 0x000506
	typedef struct
	{ // Si2146_TUNER_LO_INJECTION_PROP_struct
		unsigned char   band_1;
		unsigned char   band_2;
		unsigned char   band_3;
		unsigned char   band_4;
		unsigned char   band_5;
	} Si2146_TUNER_LO_INJECTION_PROP_struct;
	// TUNER_LO_INJECTION property, BAND_1 field definition (NO TITLE)
	#define  Si2146_TUNER_LO_INJECTION_PROP_BAND_1_LSB         0
	#define  Si2146_TUNER_LO_INJECTION_PROP_BAND_1_MASK        0x01
	#define  Si2146_TUNER_LO_INJECTION_PROP_BAND_1_DEFAULT    1
	#define Si2146_TUNER_LO_INJECTION_PROP_BAND_1_LOW_SIDE   0
	#define Si2146_TUNER_LO_INJECTION_PROP_BAND_1_HIGH_SIDE  1
	// TUNER_LO_INJECTION property, BAND_2 field definition (NO TITLE)
	#define  Si2146_TUNER_LO_INJECTION_PROP_BAND_2_LSB         1
	#define  Si2146_TUNER_LO_INJECTION_PROP_BAND_2_MASK        0x01
	#define  Si2146_TUNER_LO_INJECTION_PROP_BAND_2_DEFAULT    0
	#define Si2146_TUNER_LO_INJECTION_PROP_BAND_2_LOW_SIDE   0
	#define Si2146_TUNER_LO_INJECTION_PROP_BAND_2_HIGH_SIDE  1
	// TUNER_LO_INJECTION property, BAND_3 field definition (NO TITLE)
	#define  Si2146_TUNER_LO_INJECTION_PROP_BAND_3_LSB         2
	#define  Si2146_TUNER_LO_INJECTION_PROP_BAND_3_MASK        0x01
	#define  Si2146_TUNER_LO_INJECTION_PROP_BAND_3_DEFAULT    0
	#define Si2146_TUNER_LO_INJECTION_PROP_BAND_3_LOW_SIDE   0
	#define Si2146_TUNER_LO_INJECTION_PROP_BAND_3_HIGH_SIDE  1
	// TUNER_LO_INJECTION property, BAND_4 field definition (NO TITLE)
	#define  Si2146_TUNER_LO_INJECTION_PROP_BAND_4_LSB         3
	#define  Si2146_TUNER_LO_INJECTION_PROP_BAND_4_MASK        0x01
	#define  Si2146_TUNER_LO_INJECTION_PROP_BAND_4_DEFAULT    0
	#define Si2146_TUNER_LO_INJECTION_PROP_BAND_4_LOW_SIDE   0
	#define Si2146_TUNER_LO_INJECTION_PROP_BAND_4_HIGH_SIDE  1
	// TUNER_LO_INJECTION property, BAND_5 field definition (NO TITLE)
	#define  Si2146_TUNER_LO_INJECTION_PROP_BAND_5_LSB         4
	#define  Si2146_TUNER_LO_INJECTION_PROP_BAND_5_MASK        0x01
	#define  Si2146_TUNER_LO_INJECTION_PROP_BAND_5_DEFAULT    0
	#define Si2146_TUNER_LO_INJECTION_PROP_BAND_5_LOW_SIDE   0
	#define Si2146_TUNER_LO_INJECTION_PROP_BAND_5_HIGH_SIDE  1
#endif // Si2146_TUNER_LO_INJECTION_PROP

typedef struct
{
	#ifdef    Si2146_ATV_AFC_RANGE_PROP
			  Si2146_ATV_AFC_RANGE_PROP_struct                 atv_afc_range;
	#endif // Si2146_ATV_AFC_RANGE_PROP
	#ifdef    Si2146_ATV_AF_OUT_PROP
			  Si2146_ATV_AF_OUT_PROP_struct                    atv_af_out;
	#endif // Si2146_ATV_AF_OUT_PROP
	#ifdef    Si2146_ATV_AGC_SPEED_PROP
			  Si2146_ATV_AGC_SPEED_PROP_struct                 atv_agc_speed;
	#endif // Si2146_ATV_AGC_SPEED_PROP
	#ifdef    Si2146_ATV_AUDIO_MODE_PROP
			  Si2146_ATV_AUDIO_MODE_PROP_struct                atv_audio_mode;
	#endif // Si2146_ATV_AUDIO_MODE_PROP
	#ifdef    Si2146_ATV_CVBS_OUT_PROP
			  Si2146_ATV_CVBS_OUT_PROP_struct                  atv_cvbs_out;
	#endif // Si2146_ATV_CVBS_OUT_PROP
	#ifdef    Si2146_ATV_CVBS_OUT_FINE_PROP
			  Si2146_ATV_CVBS_OUT_FINE_PROP_struct             atv_cvbs_out_fine;
	#endif // Si2146_ATV_CVBS_OUT_FINE_PROP
	#ifdef    Si2146_ATV_IEN_PROP
			  Si2146_ATV_IEN_PROP_struct                       atv_ien;
	#endif // Si2146_ATV_IEN_PROP
	#ifdef    Si2146_ATV_INT_SENSE_PROP
			  Si2146_ATV_INT_SENSE_PROP_struct                 atv_int_sense;
	#endif // Si2146_ATV_INT_SENSE_PROP
	#ifdef    Si2146_ATV_RF_TOP_PROP
			  Si2146_ATV_RF_TOP_PROP_struct                    atv_rf_top;
	#endif // Si2146_ATV_RF_TOP_PROP
	#ifdef    Si2146_ATV_RSQ_RSSI_THRESHOLD_PROP
			  Si2146_ATV_RSQ_RSSI_THRESHOLD_PROP_struct        atv_rsq_rssi_threshold;
	#endif // Si2146_ATV_RSQ_RSSI_THRESHOLD_PROP
	#ifdef    Si2146_ATV_RSQ_SNR_THRESHOLD_PROP
			  Si2146_ATV_RSQ_SNR_THRESHOLD_PROP_struct         atv_rsq_snr_threshold;
	#endif // Si2146_ATV_RSQ_SNR_THRESHOLD_PROP
	#ifdef    Si2146_ATV_SIF_OUT_PROP
			  Si2146_ATV_SIF_OUT_PROP_struct                   atv_sif_out;
	#endif // Si2146_ATV_SIF_OUT_PROP
	#ifdef    Si2146_ATV_SOUND_AGC_LIMIT_PROP
			  Si2146_ATV_SOUND_AGC_LIMIT_PROP_struct           atv_sound_agc_limit;
	#endif // Si2146_ATV_SOUND_AGC_LIMIT_PROP
	#ifdef    Si2146_ATV_SOUND_AGC_SPEED_PROP
			  Si2146_ATV_SOUND_AGC_SPEED_PROP_struct           atv_sound_agc_speed;
	#endif // Si2146_ATV_SOUND_AGC_SPEED_PROP
	#ifdef    Si2146_ATV_VIDEO_EQUALIZER_PROP
			  Si2146_ATV_VIDEO_EQUALIZER_PROP_struct           atv_video_equalizer;
	#endif // Si2146_ATV_VIDEO_EQUALIZER_PROP
	#ifdef    Si2146_ATV_VIDEO_MODE_PROP
			  Si2146_ATV_VIDEO_MODE_PROP_struct                atv_video_mode;
	#endif // Si2146_ATV_VIDEO_MODE_PROP
	#ifdef    Si2146_ATV_VSNR_CAP_PROP
			  Si2146_ATV_VSNR_CAP_PROP_struct                  atv_vsnr_cap;
	#endif // Si2146_ATV_VSNR_CAP_PROP
	#ifdef    Si2146_ATV_VSYNC_TRACKING_PROP
			  Si2146_ATV_VSYNC_TRACKING_PROP_struct            atv_vsync_tracking;
	#endif // Si2146_ATV_VSYNC_TRACKING_PROP
	#ifdef    Si2146_CRYSTAL_TRIM_PROP
			  Si2146_CRYSTAL_TRIM_PROP_struct            crystal_trim;
	#endif // Si2146_CRYSTAL_TRIM_PROP
	#ifdef    Si2146_DTV_AGC_FREEZE_INPUT_PROP
			  Si2146_DTV_AGC_FREEZE_INPUT_PROP_struct          dtv_agc_freeze_input;
	#endif // Si2146_DTV_AGC_FREEZE_INPUT_PROP
	#ifdef    Si2146_DTV_AGC_SPEED_PROP
			  Si2146_DTV_AGC_SPEED_PROP_struct           dtv_agc_speed;
	#endif // Si2146_DTV_AGC_SPEED_PROP
	#ifdef    Si2146_DTV_CONFIG_IF_PORT_PROP
			  Si2146_DTV_CONFIG_IF_PORT_PROP_struct      dtv_config_if_port;
	#endif // Si2146_DTV_CONFIG_IF_PORT_PROP
	#ifdef    Si2146_DTV_EXT_AGC_PROP
			  Si2146_DTV_EXT_AGC_PROP_struct             dtv_ext_agc;
	#endif // Si2146_DTV_EXT_AGC_PROP
	#ifdef    Si2146_DTV_IEN_PROP
			  Si2146_DTV_IEN_PROP_struct                 dtv_ien;
	#endif // Si2146_DTV_IEN_PROP
	#ifdef    Si2146_DTV_INITIAL_AGC_SPEED_PROP
			  Si2146_DTV_INITIAL_AGC_SPEED_PROP_struct         dtv_initial_agc_speed;
	#endif // Si2146_DTV_INITIAL_AGC_SPEED_PROP
	#ifdef    Si2146_DTV_INITIAL_AGC_SPEED_PERIOD_PROP
			  Si2146_DTV_INITIAL_AGC_SPEED_PERIOD_PROP_struct  dtv_initial_agc_speed_period;
	#endif // Si2146_DTV_INITIAL_AGC_SPEED_PERIOD_PROP
	#ifdef    Si2146_DTV_INT_SENSE_PROP
			  Si2146_DTV_INT_SENSE_PROP_struct           dtv_int_sense;
	#endif // Si2146_DTV_INT_SENSE_PROP
	#ifdef    Si2146_DTV_LIF_FREQ_PROP
			  Si2146_DTV_LIF_FREQ_PROP_struct            dtv_lif_freq;
	#endif // Si2146_DTV_LIF_FREQ_PROP
	#ifdef    Si2146_DTV_LIF_OUT_PROP
			  Si2146_DTV_LIF_OUT_PROP_struct             dtv_lif_out;
	#endif // Si2146_DTV_LIF_OUT_PROP
	#ifdef    Si2146_DTV_MODE_PROP
			  Si2146_DTV_MODE_PROP_struct                dtv_mode;
	#endif // Si2146_DTV_MODE_PROP
	#ifdef    Si2146_DTV_RF_TOP_PROP
			  Si2146_DTV_RF_TOP_PROP_struct              dtv_rf_top;
	#endif // Si2146_DTV_RF_TOP_PROP
	#ifdef    Si2146_DTV_RSQ_RSSI_THRESHOLD_PROP
			  Si2146_DTV_RSQ_RSSI_THRESHOLD_PROP_struct  dtv_rsq_rssi_threshold;
	#endif // Si2146_DTV_RSQ_RSSI_THRESHOLD_PROP
	#ifdef    Si2146_MASTER_IEN_PROP
			  Si2146_MASTER_IEN_PROP_struct              master_ien;
	#endif // Si2146_MASTER_IEN_PROP
	#ifdef    Si2146_TUNER_BLOCKED_VCO_PROP
			  Si2146_TUNER_BLOCKED_VCO_PROP_struct       tuner_blocked_vco;
	#endif // Si2146_TUNER_BLOCKED_VCO_PROP
	#ifdef    Si2146_TUNER_IEN_PROP
			  Si2146_TUNER_IEN_PROP_struct               tuner_ien;
	#endif // Si2146_TUNER_IEN_PROP
	#ifdef    Si2146_TUNER_INT_SENSE_PROP
			  Si2146_TUNER_INT_SENSE_PROP_struct         tuner_int_sense;
	#endif // Si2146_TUNER_INT_SENSE_PROP
	#ifdef    Si2146_TUNER_LO_INJECTION_PROP
			  Si2146_TUNER_LO_INJECTION_PROP_struct      tuner_lo_injection;
	#endif // Si2146_TUNER_LO_INJECTION_PROP
} Si2146_PropObj;

/* Si2148 ATV_ARTIFICIAL_SNOW property definition */
#define   Si2148_ATV_ARTIFICIAL_SNOW_PROP 0x0624

#ifdef    Si2148_ATV_ARTIFICIAL_SNOW_PROP
  #define Si2148_ATV_ARTIFICIAL_SNOW_PROP_CODE 0x000624


    typedef struct { /* Si2148_ATV_ARTIFICIAL_SNOW_PROP_struct */
      unsigned char   gain;
               char   offset;
   } Si2148_ATV_ARTIFICIAL_SNOW_PROP_struct;

   /* ATV_ARTIFICIAL_SNOW property, GAIN field definition (NO TITLE)*/
   #define  Si2148_ATV_ARTIFICIAL_SNOW_PROP_GAIN_LSB         0
   #define  Si2148_ATV_ARTIFICIAL_SNOW_PROP_GAIN_MASK        0xff
   #define  Si2148_ATV_ARTIFICIAL_SNOW_PROP_GAIN_DEFAULT    0
    #define Si2148_ATV_ARTIFICIAL_SNOW_PROP_GAIN_AUTO  0
    #define Si2148_ATV_ARTIFICIAL_SNOW_PROP_GAIN_0DB   1
    #define Si2148_ATV_ARTIFICIAL_SNOW_PROP_GAIN_6DB   2
    #define Si2148_ATV_ARTIFICIAL_SNOW_PROP_GAIN_12DB  3
    #define Si2148_ATV_ARTIFICIAL_SNOW_PROP_GAIN_18DB  4
    #define Si2148_ATV_ARTIFICIAL_SNOW_PROP_GAIN_24DB  5
    #define Si2148_ATV_ARTIFICIAL_SNOW_PROP_GAIN_30DB  6
    #define Si2148_ATV_ARTIFICIAL_SNOW_PROP_GAIN_36DB  7
    #define Si2148_ATV_ARTIFICIAL_SNOW_PROP_GAIN_42DB  8
    #define Si2148_ATV_ARTIFICIAL_SNOW_PROP_GAIN_OFF   9

   /* ATV_ARTIFICIAL_SNOW property, OFFSET field definition (NO TITLE)*/
   #define  Si2148_ATV_ARTIFICIAL_SNOW_PROP_OFFSET_LSB         8
   #define  Si2148_ATV_ARTIFICIAL_SNOW_PROP_OFFSET_MASK        0xff
   #define  Si2148_ATV_ARTIFICIAL_SNOW_PROP_OFFSET_DEFAULT    0
    #define Si2148_ATV_ARTIFICIAL_SNOW_PROP_OFFSET_OFFSET_MIN  -128
    #define Si2148_ATV_ARTIFICIAL_SNOW_PROP_OFFSET_OFFSET_MAX  127

#endif /* Si2148_ATV_ARTIFICIAL_SNOW_PROP */

/* Si2148 ATV_EXT_AGC property definition */
#define   Si2148_ATV_EXT_AGC_PROP 0x0607

#ifdef    Si2148_ATV_EXT_AGC_PROP
  #define Si2148_ATV_EXT_AGC_PROP_CODE 0x000607


    typedef struct { /* Si2148_ATV_EXT_AGC_PROP_struct */
      unsigned char   max_10mv;
      unsigned char   min_10mv;
   } Si2148_ATV_EXT_AGC_PROP_struct;

   /* ATV_EXT_AGC property, MAX_10MV field definition (NO TITLE)*/
   #define  Si2148_ATV_EXT_AGC_PROP_MAX_10MV_LSB         8
   #define  Si2148_ATV_EXT_AGC_PROP_MAX_10MV_MASK        0xff
   #define  Si2148_ATV_EXT_AGC_PROP_MAX_10MV_DEFAULT    200
    #define Si2148_ATV_EXT_AGC_PROP_MAX_10MV_MAX_10MV_MIN  0
    #define Si2148_ATV_EXT_AGC_PROP_MAX_10MV_MAX_10MV_MAX  255

   /* ATV_EXT_AGC property, MIN_10MV field definition (NO TITLE)*/
   #define  Si2148_ATV_EXT_AGC_PROP_MIN_10MV_LSB         0
   #define  Si2148_ATV_EXT_AGC_PROP_MIN_10MV_MASK        0xff
   #define  Si2148_ATV_EXT_AGC_PROP_MIN_10MV_DEFAULT    50
    #define Si2148_ATV_EXT_AGC_PROP_MIN_10MV_MIN_10MV_MIN  0
    #define Si2148_ATV_EXT_AGC_PROP_MIN_10MV_MIN_10MV_MAX  255

#endif /* Si2148_ATV_EXT_AGC_PROP */

/* Si2148 ATV_LIF_FREQ property definition */
#define   Si2148_ATV_LIF_FREQ_PROP 0x060c

#ifdef    Si2148_ATV_LIF_FREQ_PROP
  #define Si2148_ATV_LIF_FREQ_PROP_CODE 0x00060c


    typedef struct { /* Si2148_ATV_LIF_FREQ_PROP_struct */
      unsigned int    offset;
   } Si2148_ATV_LIF_FREQ_PROP_struct;

   /* ATV_LIF_FREQ property, OFFSET field definition (NO TITLE)*/
   #define  Si2148_ATV_LIF_FREQ_PROP_OFFSET_LSB         0
   #define  Si2148_ATV_LIF_FREQ_PROP_OFFSET_MASK        0xffff
   #define  Si2148_ATV_LIF_FREQ_PROP_OFFSET_DEFAULT    5000
    #define Si2148_ATV_LIF_FREQ_PROP_OFFSET_OFFSET_MIN  0
    #define Si2148_ATV_LIF_FREQ_PROP_OFFSET_OFFSET_MAX  7000

#endif /* Si2148_ATV_LIF_FREQ_PROP */

/* Si2148 ATV_LIF_OUT property definition */
#define   Si2148_ATV_LIF_OUT_PROP 0x060d

#ifdef    Si2148_ATV_LIF_OUT_PROP
  #define Si2148_ATV_LIF_OUT_PROP_CODE 0x00060d


    typedef struct { /* Si2148_ATV_LIF_OUT_PROP_struct */
      unsigned char   amp;
      unsigned char   offset;
   } Si2148_ATV_LIF_OUT_PROP_struct;

   /* ATV_LIF_OUT property, AMP field definition (NO TITLE)*/
   #define  Si2148_ATV_LIF_OUT_PROP_AMP_LSB         8
   #define  Si2148_ATV_LIF_OUT_PROP_AMP_MASK        0xff
   #define  Si2148_ATV_LIF_OUT_PROP_AMP_DEFAULT    100
    #define Si2148_ATV_LIF_OUT_PROP_AMP_AMP_MIN  0
    #define Si2148_ATV_LIF_OUT_PROP_AMP_AMP_MAX  255

   /* ATV_LIF_OUT property, OFFSET field definition (NO TITLE)*/
   #define  Si2148_ATV_LIF_OUT_PROP_OFFSET_LSB         0
   #define  Si2148_ATV_LIF_OUT_PROP_OFFSET_MASK        0xff
   #define  Si2148_ATV_LIF_OUT_PROP_OFFSET_DEFAULT    148
    #define Si2148_ATV_LIF_OUT_PROP_OFFSET_OFFSET_MIN  0
    #define Si2148_ATV_LIF_OUT_PROP_OFFSET_OFFSET_MAX  255

#endif /* Si2148_ATV_LIF_OUT_PROP */

/* Si2148 ATV_PGA_TARGET property definition */
#define   Si2148_ATV_PGA_TARGET_PROP 0x0617

#ifdef    Si2148_ATV_PGA_TARGET_PROP
  #define Si2148_ATV_PGA_TARGET_PROP_CODE 0x000617


    typedef struct { /* Si2148_ATV_PGA_TARGET_PROP_struct */
      unsigned char   override_enable;
               char   pga_target;
   } Si2148_ATV_PGA_TARGET_PROP_struct;

   /* ATV_PGA_TARGET property, OVERRIDE_ENABLE field definition (NO TITLE)*/
   #define  Si2148_ATV_PGA_TARGET_PROP_OVERRIDE_ENABLE_LSB         8
   #define  Si2148_ATV_PGA_TARGET_PROP_OVERRIDE_ENABLE_MASK        0x01
   #define  Si2148_ATV_PGA_TARGET_PROP_OVERRIDE_ENABLE_DEFAULT    0
    #define Si2148_ATV_PGA_TARGET_PROP_OVERRIDE_ENABLE_DISABLE  0
    #define Si2148_ATV_PGA_TARGET_PROP_OVERRIDE_ENABLE_ENABLE   1

   /* ATV_PGA_TARGET property, PGA_TARGET field definition (NO TITLE)*/
   #define  Si2148_ATV_PGA_TARGET_PROP_PGA_TARGET_LSB         0
   #define  Si2148_ATV_PGA_TARGET_PROP_PGA_TARGET_MASK        0xff
   #define  Si2148_ATV_PGA_TARGET_PROP_PGA_TARGET_DEFAULT    0
    #define Si2148_ATV_PGA_TARGET_PROP_PGA_TARGET_PGA_TARGET_MIN  -13
    #define Si2148_ATV_PGA_TARGET_PROP_PGA_TARGET_PGA_TARGET_MAX  7

#endif /* Si2148_ATV_PGA_TARGET_PROP */

/* Si2148 CRYSTAL_TRIM property definition */
#define   Si2148_CRYSTAL_TRIM_PROP 0x0402

#ifdef    Si2148_CRYSTAL_TRIM_PROP
  #define Si2148_CRYSTAL_TRIM_PROP_CODE 0x000402


    typedef struct { /* Si2148_CRYSTAL_TRIM_PROP_struct */
      unsigned char   xo_cap;
   } Si2148_CRYSTAL_TRIM_PROP_struct;

   /* CRYSTAL_TRIM property, XO_CAP field definition (NO TITLE)*/
   #define  Si2148_CRYSTAL_TRIM_PROP_XO_CAP_LSB         0
   #define  Si2148_CRYSTAL_TRIM_PROP_XO_CAP_MASK        0x0f
   #define  Si2148_CRYSTAL_TRIM_PROP_XO_CAP_DEFAULT    8
    #define Si2148_CRYSTAL_TRIM_PROP_XO_CAP_0   0
    #define Si2148_CRYSTAL_TRIM_PROP_XO_CAP_2   2
    #define Si2148_CRYSTAL_TRIM_PROP_XO_CAP_4   4
    #define Si2148_CRYSTAL_TRIM_PROP_XO_CAP_6   6
    #define Si2148_CRYSTAL_TRIM_PROP_XO_CAP_8   8
    #define Si2148_CRYSTAL_TRIM_PROP_XO_CAP_10  10
    #define Si2148_CRYSTAL_TRIM_PROP_XO_CAP_12  12
    #define Si2148_CRYSTAL_TRIM_PROP_XO_CAP_14  14

#endif /* Si2148_CRYSTAL_TRIM_PROP */

/* Si2148 DTV_AGC_FREEZE_INPUT property definition */
#define   Si2148_DTV_AGC_FREEZE_INPUT_PROP 0x0711

#ifdef    Si2148_DTV_AGC_FREEZE_INPUT_PROP
  #define Si2148_DTV_AGC_FREEZE_INPUT_PROP_CODE 0x000711


    typedef struct { /* Si2148_DTV_AGC_FREEZE_INPUT_PROP_struct */
      unsigned char   level;
      unsigned char   pin;
   } Si2148_DTV_AGC_FREEZE_INPUT_PROP_struct;

   /* DTV_AGC_FREEZE_INPUT property, LEVEL field definition (NO TITLE)*/
   #define  Si2148_DTV_AGC_FREEZE_INPUT_PROP_LEVEL_LSB         0
   #define  Si2148_DTV_AGC_FREEZE_INPUT_PROP_LEVEL_MASK        0x01
   #define  Si2148_DTV_AGC_FREEZE_INPUT_PROP_LEVEL_DEFAULT    0
    #define Si2148_DTV_AGC_FREEZE_INPUT_PROP_LEVEL_LOW   0
    #define Si2148_DTV_AGC_FREEZE_INPUT_PROP_LEVEL_HIGH  1

   /* DTV_AGC_FREEZE_INPUT property, PIN field definition (NO TITLE)*/
   #define  Si2148_DTV_AGC_FREEZE_INPUT_PROP_PIN_LSB         1
   #define  Si2148_DTV_AGC_FREEZE_INPUT_PROP_PIN_MASK        0x07
   #define  Si2148_DTV_AGC_FREEZE_INPUT_PROP_PIN_DEFAULT    0
    #define Si2148_DTV_AGC_FREEZE_INPUT_PROP_PIN_NONE      0
    #define Si2148_DTV_AGC_FREEZE_INPUT_PROP_PIN_GPIO1     1
    #define Si2148_DTV_AGC_FREEZE_INPUT_PROP_PIN_GPIO2     2
    #define Si2148_DTV_AGC_FREEZE_INPUT_PROP_PIN_RESERVED  3
    #define Si2148_DTV_AGC_FREEZE_INPUT_PROP_PIN_AGC1      4
    #define Si2148_DTV_AGC_FREEZE_INPUT_PROP_PIN_AGC2      5
    #define Si2148_DTV_AGC_FREEZE_INPUT_PROP_PIN_LIF1A     6
    #define Si2148_DTV_AGC_FREEZE_INPUT_PROP_PIN_LIF1B     7

#endif /* Si2148_DTV_AGC_FREEZE_INPUT_PROP */

/* Si2148 DTV_AGC_SPEED property definition */
#define   Si2148_DTV_AGC_SPEED_PROP 0x0708

#ifdef    Si2148_DTV_AGC_SPEED_PROP
  #define Si2148_DTV_AGC_SPEED_PROP_CODE 0x000708


    typedef struct { /* Si2148_DTV_AGC_SPEED_PROP_struct */
      unsigned char   agc_decim;
      unsigned char   if_agc_speed;
   } Si2148_DTV_AGC_SPEED_PROP_struct;

   /* DTV_AGC_SPEED property, AGC_DECIM field definition (NO TITLE)*/
   #define  Si2148_DTV_AGC_SPEED_PROP_AGC_DECIM_LSB         8
   #define  Si2148_DTV_AGC_SPEED_PROP_AGC_DECIM_MASK        0x03
   #define  Si2148_DTV_AGC_SPEED_PROP_AGC_DECIM_DEFAULT    0
    #define Si2148_DTV_AGC_SPEED_PROP_AGC_DECIM_OFF  0
    #define Si2148_DTV_AGC_SPEED_PROP_AGC_DECIM_2    1
    #define Si2148_DTV_AGC_SPEED_PROP_AGC_DECIM_4    2
    #define Si2148_DTV_AGC_SPEED_PROP_AGC_DECIM_8    3

   /* DTV_AGC_SPEED property, IF_AGC_SPEED field definition (NO TITLE)*/
   #define  Si2148_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_LSB         0
   #define  Si2148_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_MASK        0xff
   #define  Si2148_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_DEFAULT    0
    #define Si2148_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_AUTO  0
    #define Si2148_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_39    39
    #define Si2148_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_54    54
    #define Si2148_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_63    63
    #define Si2148_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_89    89
    #define Si2148_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_105   105
    #define Si2148_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_121   121
    #define Si2148_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_137   137
    #define Si2148_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_158   158
    #define Si2148_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_172   172
    #define Si2148_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_185   185
    #define Si2148_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_196   196
    #define Si2148_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_206   206
    #define Si2148_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_216   216
    #define Si2148_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_219   219
    #define Si2148_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_222   222

#endif /* Si2148_DTV_AGC_SPEED_PROP */

/* Si2148 DTV_CONFIG_IF_PORT property definition */
#define   Si2148_DTV_CONFIG_IF_PORT_PROP 0x0702

#ifdef    Si2148_DTV_CONFIG_IF_PORT_PROP
  #define Si2148_DTV_CONFIG_IF_PORT_PROP_CODE 0x000702


    typedef struct { /* Si2148_DTV_CONFIG_IF_PORT_PROP_struct */
      unsigned char   dtv_agc_source;
      unsigned char   dtv_out_type;
   } Si2148_DTV_CONFIG_IF_PORT_PROP_struct;

   /* DTV_CONFIG_IF_PORT property, DTV_AGC_SOURCE field definition (NO TITLE)*/
   #define  Si2148_DTV_CONFIG_IF_PORT_PROP_DTV_AGC_SOURCE_LSB         8
   #define  Si2148_DTV_CONFIG_IF_PORT_PROP_DTV_AGC_SOURCE_MASK        0x07
   #define  Si2148_DTV_CONFIG_IF_PORT_PROP_DTV_AGC_SOURCE_DEFAULT    0
    #define Si2148_DTV_CONFIG_IF_PORT_PROP_DTV_AGC_SOURCE_INTERNAL   0
    #define Si2148_DTV_CONFIG_IF_PORT_PROP_DTV_AGC_SOURCE_AGC1_3DB   1
    #define Si2148_DTV_CONFIG_IF_PORT_PROP_DTV_AGC_SOURCE_AGC2_3DB   2

   /* DTV_CONFIG_IF_PORT property, DTV_OUT_TYPE field definition (NO TITLE)*/
   #define  Si2148_DTV_CONFIG_IF_PORT_PROP_DTV_OUT_TYPE_LSB         0
   #define  Si2148_DTV_CONFIG_IF_PORT_PROP_DTV_OUT_TYPE_MASK        0x0f
   #define  Si2148_DTV_CONFIG_IF_PORT_PROP_DTV_OUT_TYPE_DEFAULT    0
    #define Si2148_DTV_CONFIG_IF_PORT_PROP_DTV_OUT_TYPE_LIF_IF1      0
    #define Si2148_DTV_CONFIG_IF_PORT_PROP_DTV_OUT_TYPE_LIF_IF2      1
    #define Si2148_DTV_CONFIG_IF_PORT_PROP_DTV_OUT_TYPE_LIF_SE_IF1A  4
    #define Si2148_DTV_CONFIG_IF_PORT_PROP_DTV_OUT_TYPE_LIF_SE_IF2A  5

#endif /* Si2148_DTV_CONFIG_IF_PORT_PROP */

/* Si2148 DTV_EXT_AGC property definition */
#define   Si2148_DTV_EXT_AGC_PROP 0x0705

#ifdef    Si2148_DTV_EXT_AGC_PROP
  #define Si2148_DTV_EXT_AGC_PROP_CODE 0x000705


    typedef struct { /* Si2148_DTV_EXT_AGC_PROP_struct */
      unsigned char   max_10mv;
      unsigned char   min_10mv;
   } Si2148_DTV_EXT_AGC_PROP_struct;

   /* DTV_EXT_AGC property, MAX_10MV field definition (NO TITLE)*/
   #define  Si2148_DTV_EXT_AGC_PROP_MAX_10MV_LSB         8
   #define  Si2148_DTV_EXT_AGC_PROP_MAX_10MV_MASK        0xff
   #define  Si2148_DTV_EXT_AGC_PROP_MAX_10MV_DEFAULT    200
    #define Si2148_DTV_EXT_AGC_PROP_MAX_10MV_MAX_10MV_MIN  0
    #define Si2148_DTV_EXT_AGC_PROP_MAX_10MV_MAX_10MV_MAX  255

   /* DTV_EXT_AGC property, MIN_10MV field definition (NO TITLE)*/
   #define  Si2148_DTV_EXT_AGC_PROP_MIN_10MV_LSB         0
   #define  Si2148_DTV_EXT_AGC_PROP_MIN_10MV_MASK        0xff
   #define  Si2148_DTV_EXT_AGC_PROP_MIN_10MV_DEFAULT    50
    #define Si2148_DTV_EXT_AGC_PROP_MIN_10MV_MIN_10MV_MIN  0
    #define Si2148_DTV_EXT_AGC_PROP_MIN_10MV_MIN_10MV_MAX  255

#endif /* Si2148_DTV_EXT_AGC_PROP */

/* Si2148 DTV_FILTER_SELECT property definition */
#define   Si2148_DTV_FILTER_SELECT_PROP 0x070c

#ifdef    Si2148_DTV_FILTER_SELECT_PROP
  #define Si2148_DTV_FILTER_SELECT_PROP_CODE 0x00070c


    typedef struct { /* Si2148_DTV_FILTER_SELECT_PROP_struct */
      unsigned char   filter;
   } Si2148_DTV_FILTER_SELECT_PROP_struct;

   /* DTV_FILTER_SELECT property, FILTER field definition (NO TITLE)*/
   #define  Si2148_DTV_FILTER_SELECT_PROP_FILTER_LSB         0
   #define  Si2148_DTV_FILTER_SELECT_PROP_FILTER_MASK        0x03
   #define  Si2148_DTV_FILTER_SELECT_PROP_FILTER_DEFAULT    1
    #define Si2148_DTV_FILTER_SELECT_PROP_FILTER_LEGACY   0
    #define Si2148_DTV_FILTER_SELECT_PROP_FILTER_CUSTOM1  1
    #define Si2148_DTV_FILTER_SELECT_PROP_FILTER_CUSTOM2  2

#endif /* Si2148_DTV_FILTER_SELECT_PROP */

/* Si2148 DTV_IEN property definition */
#define   Si2148_DTV_IEN_PROP 0x0701

#ifdef    Si2148_DTV_IEN_PROP
  #define Si2148_DTV_IEN_PROP_CODE 0x000701


    typedef struct { /* Si2148_DTV_IEN_PROP_struct */
      unsigned char   chlien;
   } Si2148_DTV_IEN_PROP_struct;

   /* DTV_IEN property, CHLIEN field definition (NO TITLE)*/
   #define  Si2148_DTV_IEN_PROP_CHLIEN_LSB         0
   #define  Si2148_DTV_IEN_PROP_CHLIEN_MASK        0x01
   #define  Si2148_DTV_IEN_PROP_CHLIEN_DEFAULT    1
    #define Si2148_DTV_IEN_PROP_CHLIEN_DISABLE  0
    #define Si2148_DTV_IEN_PROP_CHLIEN_ENABLE   1

#endif /* Si2148_DTV_IEN_PROP */

/* Si2148 DTV_INITIAL_AGC_SPEED property definition */
#define   Si2148_DTV_INITIAL_AGC_SPEED_PROP 0x070d

#ifdef    Si2148_DTV_INITIAL_AGC_SPEED_PROP
  #define Si2148_DTV_INITIAL_AGC_SPEED_PROP_CODE 0x00070d


    typedef struct { /* Si2148_DTV_INITIAL_AGC_SPEED_PROP_struct */
      unsigned char   agc_decim;
      unsigned char   if_agc_speed;
   } Si2148_DTV_INITIAL_AGC_SPEED_PROP_struct;

   /* DTV_INITIAL_AGC_SPEED property, AGC_DECIM field definition (NO TITLE)*/
   #define  Si2148_DTV_INITIAL_AGC_SPEED_PROP_AGC_DECIM_LSB         8
   #define  Si2148_DTV_INITIAL_AGC_SPEED_PROP_AGC_DECIM_MASK        0x03
   #define  Si2148_DTV_INITIAL_AGC_SPEED_PROP_AGC_DECIM_DEFAULT    0
    #define Si2148_DTV_INITIAL_AGC_SPEED_PROP_AGC_DECIM_OFF  0
    #define Si2148_DTV_INITIAL_AGC_SPEED_PROP_AGC_DECIM_2    1
    #define Si2148_DTV_INITIAL_AGC_SPEED_PROP_AGC_DECIM_4    2
    #define Si2148_DTV_INITIAL_AGC_SPEED_PROP_AGC_DECIM_8    3

   /* DTV_INITIAL_AGC_SPEED property, IF_AGC_SPEED field definition (NO TITLE)*/
   #define  Si2148_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_LSB         0
   #define  Si2148_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_MASK        0xff
   #define  Si2148_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_DEFAULT    0
    #define Si2148_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_AUTO  0
    #define Si2148_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_39    39
    #define Si2148_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_54    54
    #define Si2148_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_63    63
    #define Si2148_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_89    89
    #define Si2148_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_105   105
    #define Si2148_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_121   121
    #define Si2148_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_137   137
    #define Si2148_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_158   158
    #define Si2148_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_172   172
    #define Si2148_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_185   185
    #define Si2148_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_196   196
    #define Si2148_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_206   206
    #define Si2148_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_216   216
    #define Si2148_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_219   219
    #define Si2148_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_222   222

#endif /* Si2148_DTV_INITIAL_AGC_SPEED_PROP */

/* Si2148 DTV_INITIAL_AGC_SPEED_PERIOD property definition */
#define   Si2148_DTV_INITIAL_AGC_SPEED_PERIOD_PROP 0x070e

#ifdef    Si2148_DTV_INITIAL_AGC_SPEED_PERIOD_PROP
  #define Si2148_DTV_INITIAL_AGC_SPEED_PERIOD_PROP_CODE 0x00070e


    typedef struct { /* Si2148_DTV_INITIAL_AGC_SPEED_PERIOD_PROP_struct */
      unsigned int    period;
   } Si2148_DTV_INITIAL_AGC_SPEED_PERIOD_PROP_struct;

   /* DTV_INITIAL_AGC_SPEED_PERIOD property, PERIOD field definition (NO TITLE)*/
   #define  Si2148_DTV_INITIAL_AGC_SPEED_PERIOD_PROP_PERIOD_LSB         0
   #define  Si2148_DTV_INITIAL_AGC_SPEED_PERIOD_PROP_PERIOD_MASK        0xffff
   #define  Si2148_DTV_INITIAL_AGC_SPEED_PERIOD_PROP_PERIOD_DEFAULT    0
    #define Si2148_DTV_INITIAL_AGC_SPEED_PERIOD_PROP_PERIOD_PERIOD_MIN  0
    #define Si2148_DTV_INITIAL_AGC_SPEED_PERIOD_PROP_PERIOD_PERIOD_MAX  65535

#endif /* Si2148_DTV_INITIAL_AGC_SPEED_PERIOD_PROP */

/* Si2148 DTV_INTERNAL_ZIF property definition */
#define   Si2148_DTV_INTERNAL_ZIF_PROP 0x0710

#ifdef    Si2148_DTV_INTERNAL_ZIF_PROP
  #define Si2148_DTV_INTERNAL_ZIF_PROP_CODE 0x000710


    typedef struct { /* Si2148_DTV_INTERNAL_ZIF_PROP_struct */
      unsigned char   atsc;
      unsigned char   dtmb;
      unsigned char   dvbc;
      unsigned char   dvbt;
      unsigned char   isdbc;
      unsigned char   isdbt;
      unsigned char   qam_us;
   } Si2148_DTV_INTERNAL_ZIF_PROP_struct;

   /* DTV_INTERNAL_ZIF property, ATSC field definition (NO TITLE)*/
   #define  Si2148_DTV_INTERNAL_ZIF_PROP_ATSC_LSB         0
   #define  Si2148_DTV_INTERNAL_ZIF_PROP_ATSC_MASK        0x01
   #define  Si2148_DTV_INTERNAL_ZIF_PROP_ATSC_DEFAULT    0
    #define Si2148_DTV_INTERNAL_ZIF_PROP_ATSC_LIF  0
    #define Si2148_DTV_INTERNAL_ZIF_PROP_ATSC_ZIF  1

   /* DTV_INTERNAL_ZIF property, DTMB field definition (NO TITLE)*/
   #define  Si2148_DTV_INTERNAL_ZIF_PROP_DTMB_LSB         6
   #define  Si2148_DTV_INTERNAL_ZIF_PROP_DTMB_MASK        0x01
   #define  Si2148_DTV_INTERNAL_ZIF_PROP_DTMB_DEFAULT    0
    #define Si2148_DTV_INTERNAL_ZIF_PROP_DTMB_LIF  0
    #define Si2148_DTV_INTERNAL_ZIF_PROP_DTMB_ZIF  1

   /* DTV_INTERNAL_ZIF property, DVBC field definition (NO TITLE)*/
   #define  Si2148_DTV_INTERNAL_ZIF_PROP_DVBC_LSB         3
   #define  Si2148_DTV_INTERNAL_ZIF_PROP_DVBC_MASK        0x01
   #define  Si2148_DTV_INTERNAL_ZIF_PROP_DVBC_DEFAULT    0
    #define Si2148_DTV_INTERNAL_ZIF_PROP_DVBC_LIF  0
    #define Si2148_DTV_INTERNAL_ZIF_PROP_DVBC_ZIF  1

   /* DTV_INTERNAL_ZIF property, DVBT field definition (NO TITLE)*/
   #define  Si2148_DTV_INTERNAL_ZIF_PROP_DVBT_LSB         2
   #define  Si2148_DTV_INTERNAL_ZIF_PROP_DVBT_MASK        0x01
   #define  Si2148_DTV_INTERNAL_ZIF_PROP_DVBT_DEFAULT    0
    #define Si2148_DTV_INTERNAL_ZIF_PROP_DVBT_LIF  0
    #define Si2148_DTV_INTERNAL_ZIF_PROP_DVBT_ZIF  1

   /* DTV_INTERNAL_ZIF property, ISDBC field definition (NO TITLE)*/
   #define  Si2148_DTV_INTERNAL_ZIF_PROP_ISDBC_LSB         5
   #define  Si2148_DTV_INTERNAL_ZIF_PROP_ISDBC_MASK        0x01
   #define  Si2148_DTV_INTERNAL_ZIF_PROP_ISDBC_DEFAULT    0
    #define Si2148_DTV_INTERNAL_ZIF_PROP_ISDBC_LIF  0
    #define Si2148_DTV_INTERNAL_ZIF_PROP_ISDBC_ZIF  1

   /* DTV_INTERNAL_ZIF property, ISDBT field definition (NO TITLE)*/
   #define  Si2148_DTV_INTERNAL_ZIF_PROP_ISDBT_LSB         4
   #define  Si2148_DTV_INTERNAL_ZIF_PROP_ISDBT_MASK        0x01
   #define  Si2148_DTV_INTERNAL_ZIF_PROP_ISDBT_DEFAULT    0
    #define Si2148_DTV_INTERNAL_ZIF_PROP_ISDBT_LIF  0
    #define Si2148_DTV_INTERNAL_ZIF_PROP_ISDBT_ZIF  1

   /* DTV_INTERNAL_ZIF property, QAM_US field definition (NO TITLE)*/
   #define  Si2148_DTV_INTERNAL_ZIF_PROP_QAM_US_LSB         1
   #define  Si2148_DTV_INTERNAL_ZIF_PROP_QAM_US_MASK        0x01
   #define  Si2148_DTV_INTERNAL_ZIF_PROP_QAM_US_DEFAULT    0
    #define Si2148_DTV_INTERNAL_ZIF_PROP_QAM_US_LIF  0
    #define Si2148_DTV_INTERNAL_ZIF_PROP_QAM_US_ZIF  1

#endif /* Si2148_DTV_INTERNAL_ZIF_PROP */

/* Si2148 DTV_INT_SENSE property definition */
#define   Si2148_DTV_INT_SENSE_PROP 0x070a

#ifdef    Si2148_DTV_INT_SENSE_PROP
  #define Si2148_DTV_INT_SENSE_PROP_CODE 0x00070a


    typedef struct { /* Si2148_DTV_INT_SENSE_PROP_struct */
      unsigned char   chlnegen;
      unsigned char   chlposen;
   } Si2148_DTV_INT_SENSE_PROP_struct;

   /* DTV_INT_SENSE property, CHLNEGEN field definition (NO TITLE)*/
   #define  Si2148_DTV_INT_SENSE_PROP_CHLNEGEN_LSB         0
   #define  Si2148_DTV_INT_SENSE_PROP_CHLNEGEN_MASK        0x01
   #define  Si2148_DTV_INT_SENSE_PROP_CHLNEGEN_DEFAULT    0
    #define Si2148_DTV_INT_SENSE_PROP_CHLNEGEN_DISABLE  0
    #define Si2148_DTV_INT_SENSE_PROP_CHLNEGEN_ENABLE   1

   /* DTV_INT_SENSE property, CHLPOSEN field definition (NO TITLE)*/
   #define  Si2148_DTV_INT_SENSE_PROP_CHLPOSEN_LSB         8
   #define  Si2148_DTV_INT_SENSE_PROP_CHLPOSEN_MASK        0x01
   #define  Si2148_DTV_INT_SENSE_PROP_CHLPOSEN_DEFAULT    1
    #define Si2148_DTV_INT_SENSE_PROP_CHLPOSEN_DISABLE  0
    #define Si2148_DTV_INT_SENSE_PROP_CHLPOSEN_ENABLE   1

#endif /* Si2148_DTV_INT_SENSE_PROP */

/* Si2148 DTV_LIF_FREQ property definition */
#define   Si2148_DTV_LIF_FREQ_PROP 0x0706

#ifdef    Si2148_DTV_LIF_FREQ_PROP
  #define Si2148_DTV_LIF_FREQ_PROP_CODE 0x000706


    typedef struct { /* Si2148_DTV_LIF_FREQ_PROP_struct */
      unsigned int    offset;
   } Si2148_DTV_LIF_FREQ_PROP_struct;

   /* DTV_LIF_FREQ property, OFFSET field definition (NO TITLE)*/
   #define  Si2148_DTV_LIF_FREQ_PROP_OFFSET_LSB         0
   #define  Si2148_DTV_LIF_FREQ_PROP_OFFSET_MASK        0xffff
   #define  Si2148_DTV_LIF_FREQ_PROP_OFFSET_DEFAULT    5000
    #define Si2148_DTV_LIF_FREQ_PROP_OFFSET_OFFSET_MIN  0
    #define Si2148_DTV_LIF_FREQ_PROP_OFFSET_OFFSET_MAX  7000

#endif /* Si2148_DTV_LIF_FREQ_PROP */

/* Si2148 DTV_LIF_OUT property definition */
#define   Si2148_DTV_LIF_OUT_PROP 0x0707

#ifdef    Si2148_DTV_LIF_OUT_PROP
  #define Si2148_DTV_LIF_OUT_PROP_CODE 0x000707


    typedef struct { /* Si2148_DTV_LIF_OUT_PROP_struct */
      unsigned char   amp;
      unsigned char   offset;
   } Si2148_DTV_LIF_OUT_PROP_struct;

   /* DTV_LIF_OUT property, AMP field definition (NO TITLE)*/
   #define  Si2148_DTV_LIF_OUT_PROP_AMP_LSB         8
   #define  Si2148_DTV_LIF_OUT_PROP_AMP_MASK        0xff
   #define  Si2148_DTV_LIF_OUT_PROP_AMP_DEFAULT    27
    #define Si2148_DTV_LIF_OUT_PROP_AMP_AMP_MIN  0
    #define Si2148_DTV_LIF_OUT_PROP_AMP_AMP_MAX  255

   /* DTV_LIF_OUT property, OFFSET field definition (NO TITLE)*/
   #define  Si2148_DTV_LIF_OUT_PROP_OFFSET_LSB         0
   #define  Si2148_DTV_LIF_OUT_PROP_OFFSET_MASK        0xff
   #define  Si2148_DTV_LIF_OUT_PROP_OFFSET_DEFAULT    148
    #define Si2148_DTV_LIF_OUT_PROP_OFFSET_OFFSET_MIN  0
    #define Si2148_DTV_LIF_OUT_PROP_OFFSET_OFFSET_MAX  255

#endif /* Si2148_DTV_LIF_OUT_PROP */

/* Si2148 DTV_MODE property definition */
#define   Si2148_DTV_MODE_PROP 0x0703

#ifdef    Si2148_DTV_MODE_PROP
  #define Si2148_DTV_MODE_PROP_CODE 0x000703


    typedef struct { /* Si2148_DTV_MODE_PROP_struct */
      unsigned char   bw;
      unsigned char   invert_spectrum;
      unsigned char   modulation;
   } Si2148_DTV_MODE_PROP_struct;

   /* DTV_MODE property, BW field definition (NO TITLE)*/
   #define  Si2148_DTV_MODE_PROP_BW_LSB         0
   #define  Si2148_DTV_MODE_PROP_BW_MASK        0x0f
   #define  Si2148_DTV_MODE_PROP_BW_DEFAULT    8
    #define Si2148_DTV_MODE_PROP_BW_BW_6MHZ  6
    #define Si2148_DTV_MODE_PROP_BW_BW_7MHZ  7
    #define Si2148_DTV_MODE_PROP_BW_BW_8MHZ  8

   /* DTV_MODE property, INVERT_SPECTRUM field definition (NO TITLE)*/
   #define  Si2148_DTV_MODE_PROP_INVERT_SPECTRUM_LSB         8
   #define  Si2148_DTV_MODE_PROP_INVERT_SPECTRUM_MASK        0x01
   #define  Si2148_DTV_MODE_PROP_INVERT_SPECTRUM_DEFAULT    0
    #define Si2148_DTV_MODE_PROP_INVERT_SPECTRUM_NORMAL    0
    #define Si2148_DTV_MODE_PROP_INVERT_SPECTRUM_INVERTED  1

   /* DTV_MODE property, MODULATION field definition (NO TITLE)*/
   #define  Si2148_DTV_MODE_PROP_MODULATION_LSB         4
   #define  Si2148_DTV_MODE_PROP_MODULATION_MASK        0x0f
   #define  Si2148_DTV_MODE_PROP_MODULATION_DEFAULT    2
    #define Si2148_DTV_MODE_PROP_MODULATION_ATSC    0
    #define Si2148_DTV_MODE_PROP_MODULATION_QAM_US  1
    #define Si2148_DTV_MODE_PROP_MODULATION_DVBT    2
    #define Si2148_DTV_MODE_PROP_MODULATION_DVBC    3
    #define Si2148_DTV_MODE_PROP_MODULATION_ISDBT   4
    #define Si2148_DTV_MODE_PROP_MODULATION_ISDBC   5
    #define Si2148_DTV_MODE_PROP_MODULATION_DTMB    6

#endif /* Si2148_DTV_MODE_PROP */

/* Si2148 DTV_PGA_LIMITS property definition */
#define   Si2148_DTV_PGA_LIMITS_PROP 0x0713

#ifdef    Si2148_DTV_PGA_LIMITS_PROP
  #define Si2148_DTV_PGA_LIMITS_PROP_CODE 0x000713


    typedef struct { /* Si2148_DTV_PGA_LIMITS_PROP_struct */
               char   max;
               char   min;
   } Si2148_DTV_PGA_LIMITS_PROP_struct;

   /* DTV_PGA_LIMITS property, MAX field definition (NO TITLE)*/
   #define  Si2148_DTV_PGA_LIMITS_PROP_MAX_LSB         8
   #define  Si2148_DTV_PGA_LIMITS_PROP_MAX_MASK        0xff
   #define  Si2148_DTV_PGA_LIMITS_PROP_MAX_DEFAULT    -1
    #define Si2148_DTV_PGA_LIMITS_PROP_MAX_MAX_MIN  -1
    #define Si2148_DTV_PGA_LIMITS_PROP_MAX_MAX_MAX  56

   /* DTV_PGA_LIMITS property, MIN field definition (NO TITLE)*/
   #define  Si2148_DTV_PGA_LIMITS_PROP_MIN_LSB         0
   #define  Si2148_DTV_PGA_LIMITS_PROP_MIN_MASK        0xff
   #define  Si2148_DTV_PGA_LIMITS_PROP_MIN_DEFAULT    -1
    #define Si2148_DTV_PGA_LIMITS_PROP_MIN_MIN_MIN  -1
    #define Si2148_DTV_PGA_LIMITS_PROP_MIN_MIN_MAX  56

#endif /* Si2148_DTV_PGA_LIMITS_PROP */

/* Si2148 DTV_PGA_TARGET property definition */
#define   Si2148_DTV_PGA_TARGET_PROP 0x070f

#ifdef    Si2148_DTV_PGA_TARGET_PROP
  #define Si2148_DTV_PGA_TARGET_PROP_CODE 0x00070f


    typedef struct { /* Si2148_DTV_PGA_TARGET_PROP_struct */
      unsigned char   override_enable;
               char   pga_target;
   } Si2148_DTV_PGA_TARGET_PROP_struct;

   /* DTV_PGA_TARGET property, OVERRIDE_ENABLE field definition (NO TITLE)*/
   #define  Si2148_DTV_PGA_TARGET_PROP_OVERRIDE_ENABLE_LSB         8
   #define  Si2148_DTV_PGA_TARGET_PROP_OVERRIDE_ENABLE_MASK        0x01
   #define  Si2148_DTV_PGA_TARGET_PROP_OVERRIDE_ENABLE_DEFAULT    0
    #define Si2148_DTV_PGA_TARGET_PROP_OVERRIDE_ENABLE_DISABLE  0
    #define Si2148_DTV_PGA_TARGET_PROP_OVERRIDE_ENABLE_ENABLE   1

   /* DTV_PGA_TARGET property, PGA_TARGET field definition (NO TITLE)*/
   #define  Si2148_DTV_PGA_TARGET_PROP_PGA_TARGET_LSB         0
   #define  Si2148_DTV_PGA_TARGET_PROP_PGA_TARGET_MASK        0xff
   #define  Si2148_DTV_PGA_TARGET_PROP_PGA_TARGET_DEFAULT    0
    #define Si2148_DTV_PGA_TARGET_PROP_PGA_TARGET_PGA_TARGET_MIN  -13
    #define Si2148_DTV_PGA_TARGET_PROP_PGA_TARGET_PGA_TARGET_MAX  7

#endif /* Si2148_DTV_PGA_TARGET_PROP */

/* Si2148 DTV_RF_TOP property definition */
#define   Si2148_DTV_RF_TOP_PROP 0x0709

#ifdef    Si2148_DTV_RF_TOP_PROP
  #define Si2148_DTV_RF_TOP_PROP_CODE 0x000709


    typedef struct { /* Si2148_DTV_RF_TOP_PROP_struct */
      unsigned char   dtv_rf_top;
   } Si2148_DTV_RF_TOP_PROP_struct;

   /* DTV_RF_TOP property, DTV_RF_TOP field definition (NO TITLE)*/
   #define  Si2148_DTV_RF_TOP_PROP_DTV_RF_TOP_LSB         0
   #define  Si2148_DTV_RF_TOP_PROP_DTV_RF_TOP_MASK        0xff
   #define  Si2148_DTV_RF_TOP_PROP_DTV_RF_TOP_DEFAULT    0
    #define Si2148_DTV_RF_TOP_PROP_DTV_RF_TOP_AUTO     0
    #define Si2148_DTV_RF_TOP_PROP_DTV_RF_TOP_P6DB     9
    #define Si2148_DTV_RF_TOP_PROP_DTV_RF_TOP_P5P5DB   10
    #define Si2148_DTV_RF_TOP_PROP_DTV_RF_TOP_P5DB     11
    #define Si2148_DTV_RF_TOP_PROP_DTV_RF_TOP_P4P5DB   12
    #define Si2148_DTV_RF_TOP_PROP_DTV_RF_TOP_P4DB     13
    #define Si2148_DTV_RF_TOP_PROP_DTV_RF_TOP_P3P5DB   14
    #define Si2148_DTV_RF_TOP_PROP_DTV_RF_TOP_P3DB     15
    #define Si2148_DTV_RF_TOP_PROP_DTV_RF_TOP_P2P5DB   16
    #define Si2148_DTV_RF_TOP_PROP_DTV_RF_TOP_P2DB     17
    #define Si2148_DTV_RF_TOP_PROP_DTV_RF_TOP_P1P5DB   18
    #define Si2148_DTV_RF_TOP_PROP_DTV_RF_TOP_P1DB     19
    #define Si2148_DTV_RF_TOP_PROP_DTV_RF_TOP_P0P5DB   20
    #define Si2148_DTV_RF_TOP_PROP_DTV_RF_TOP_0DB      21
    #define Si2148_DTV_RF_TOP_PROP_DTV_RF_TOP_M0P5DB   22
    #define Si2148_DTV_RF_TOP_PROP_DTV_RF_TOP_M1DB     23
    #define Si2148_DTV_RF_TOP_PROP_DTV_RF_TOP_M1P5DB   24
    #define Si2148_DTV_RF_TOP_PROP_DTV_RF_TOP_M2DB     25
    #define Si2148_DTV_RF_TOP_PROP_DTV_RF_TOP_M2P5DB   26
    #define Si2148_DTV_RF_TOP_PROP_DTV_RF_TOP_M3DB     27
    #define Si2148_DTV_RF_TOP_PROP_DTV_RF_TOP_M3P5DB   28
    #define Si2148_DTV_RF_TOP_PROP_DTV_RF_TOP_M4DB     29
    #define Si2148_DTV_RF_TOP_PROP_DTV_RF_TOP_M4P5DB   30
    #define Si2148_DTV_RF_TOP_PROP_DTV_RF_TOP_M5DB     31
    #define Si2148_DTV_RF_TOP_PROP_DTV_RF_TOP_M5P5DB   32
    #define Si2148_DTV_RF_TOP_PROP_DTV_RF_TOP_M6DB     33
    #define Si2148_DTV_RF_TOP_PROP_DTV_RF_TOP_M6P5DB   34
    #define Si2148_DTV_RF_TOP_PROP_DTV_RF_TOP_M7DB     35
    #define Si2148_DTV_RF_TOP_PROP_DTV_RF_TOP_M7P5DB   36
    #define Si2148_DTV_RF_TOP_PROP_DTV_RF_TOP_M8DB     37
    #define Si2148_DTV_RF_TOP_PROP_DTV_RF_TOP_M8P5DB   38
    #define Si2148_DTV_RF_TOP_PROP_DTV_RF_TOP_M9DB     39
    #define Si2148_DTV_RF_TOP_PROP_DTV_RF_TOP_M9P5DB   40
    #define Si2148_DTV_RF_TOP_PROP_DTV_RF_TOP_M10DB    41
    #define Si2148_DTV_RF_TOP_PROP_DTV_RF_TOP_M10P5DB  42
    #define Si2148_DTV_RF_TOP_PROP_DTV_RF_TOP_M11DB    43

#endif /* Si2148_DTV_RF_TOP_PROP */

/* Si2148 DTV_RSQ_RSSI_THRESHOLD property definition */
#define   Si2148_DTV_RSQ_RSSI_THRESHOLD_PROP 0x0704

#ifdef    Si2148_DTV_RSQ_RSSI_THRESHOLD_PROP
  #define Si2148_DTV_RSQ_RSSI_THRESHOLD_PROP_CODE 0x000704


    typedef struct { /* Si2148_DTV_RSQ_RSSI_THRESHOLD_PROP_struct */
               char   hi;
               char   lo;
   } Si2148_DTV_RSQ_RSSI_THRESHOLD_PROP_struct;

   /* DTV_RSQ_RSSI_THRESHOLD property, HI field definition (NO TITLE)*/
   #define  Si2148_DTV_RSQ_RSSI_THRESHOLD_PROP_HI_LSB         8
   #define  Si2148_DTV_RSQ_RSSI_THRESHOLD_PROP_HI_MASK        0xff
   #define  Si2148_DTV_RSQ_RSSI_THRESHOLD_PROP_HI_DEFAULT    0
    #define Si2148_DTV_RSQ_RSSI_THRESHOLD_PROP_HI_HI_MIN  -128
    #define Si2148_DTV_RSQ_RSSI_THRESHOLD_PROP_HI_HI_MAX  127

   /* DTV_RSQ_RSSI_THRESHOLD property, LO field definition (NO TITLE)*/
   #define  Si2148_DTV_RSQ_RSSI_THRESHOLD_PROP_LO_LSB         0
   #define  Si2148_DTV_RSQ_RSSI_THRESHOLD_PROP_LO_MASK        0xff
   #define  Si2148_DTV_RSQ_RSSI_THRESHOLD_PROP_LO_DEFAULT    -80
    #define Si2148_DTV_RSQ_RSSI_THRESHOLD_PROP_LO_LO_MIN  -128
    #define Si2148_DTV_RSQ_RSSI_THRESHOLD_PROP_LO_LO_MAX  127

#endif /* Si2148_DTV_RSQ_RSSI_THRESHOLD_PROP */

/* Si2148 DTV_ZIF_DC_CANCELLER_BW property definition */
#define   Si2148_DTV_ZIF_DC_CANCELLER_BW_PROP 0x0712

#ifdef    Si2148_DTV_ZIF_DC_CANCELLER_BW_PROP
  #define Si2148_DTV_ZIF_DC_CANCELLER_BW_PROP_CODE 0x000712


    typedef struct { /* Si2148_DTV_ZIF_DC_CANCELLER_BW_PROP_struct */
      unsigned char   bandwidth;
   } Si2148_DTV_ZIF_DC_CANCELLER_BW_PROP_struct;

   /* DTV_ZIF_DC_CANCELLER_BW property, BANDWIDTH field definition (NO TITLE)*/
   #define  Si2148_DTV_ZIF_DC_CANCELLER_BW_PROP_BANDWIDTH_LSB         0
   #define  Si2148_DTV_ZIF_DC_CANCELLER_BW_PROP_BANDWIDTH_MASK        0xff
   #define  Si2148_DTV_ZIF_DC_CANCELLER_BW_PROP_BANDWIDTH_DEFAULT    16
    #define Si2148_DTV_ZIF_DC_CANCELLER_BW_PROP_BANDWIDTH_4_HZ       0
    #define Si2148_DTV_ZIF_DC_CANCELLER_BW_PROP_BANDWIDTH_8_HZ       1
    #define Si2148_DTV_ZIF_DC_CANCELLER_BW_PROP_BANDWIDTH_15_HZ      2
    #define Si2148_DTV_ZIF_DC_CANCELLER_BW_PROP_BANDWIDTH_30_HZ      3
    #define Si2148_DTV_ZIF_DC_CANCELLER_BW_PROP_BANDWIDTH_61_HZ      4
    #define Si2148_DTV_ZIF_DC_CANCELLER_BW_PROP_BANDWIDTH_121_HZ     5
    #define Si2148_DTV_ZIF_DC_CANCELLER_BW_PROP_BANDWIDTH_243_HZ     6
    #define Si2148_DTV_ZIF_DC_CANCELLER_BW_PROP_BANDWIDTH_486_HZ     7
    #define Si2148_DTV_ZIF_DC_CANCELLER_BW_PROP_BANDWIDTH_972_HZ     8
    #define Si2148_DTV_ZIF_DC_CANCELLER_BW_PROP_BANDWIDTH_1943_HZ    9
    #define Si2148_DTV_ZIF_DC_CANCELLER_BW_PROP_BANDWIDTH_3888_HZ    10
    #define Si2148_DTV_ZIF_DC_CANCELLER_BW_PROP_BANDWIDTH_7779_HZ    11
    #define Si2148_DTV_ZIF_DC_CANCELLER_BW_PROP_BANDWIDTH_15573_HZ   12
    #define Si2148_DTV_ZIF_DC_CANCELLER_BW_PROP_BANDWIDTH_31207_HZ   13
    #define Si2148_DTV_ZIF_DC_CANCELLER_BW_PROP_BANDWIDTH_62658_HZ   14
    #define Si2148_DTV_ZIF_DC_CANCELLER_BW_PROP_BANDWIDTH_126303_HZ  15
    #define Si2148_DTV_ZIF_DC_CANCELLER_BW_PROP_BANDWIDTH_DEFAULT    16

#endif /* Si2148_DTV_ZIF_DC_CANCELLER_BW_PROP */

/* Si2148 MASTER_IEN property definition */
#define   Si2148_MASTER_IEN_PROP 0x0401

#ifdef    Si2148_MASTER_IEN_PROP
  #define Si2148_MASTER_IEN_PROP_CODE 0x000401


    typedef struct { /* Si2148_MASTER_IEN_PROP_struct */
      unsigned char   atvien;
      unsigned char   ctsien;
      unsigned char   dtvien;
      unsigned char   errien;
      unsigned char   tunien;
   } Si2148_MASTER_IEN_PROP_struct;

   /* MASTER_IEN property, ATVIEN field definition (NO TITLE)*/
   #define  Si2148_MASTER_IEN_PROP_ATVIEN_LSB         1
   #define  Si2148_MASTER_IEN_PROP_ATVIEN_MASK        0x01
   #define  Si2148_MASTER_IEN_PROP_ATVIEN_DEFAULT    0
    #define Si2148_MASTER_IEN_PROP_ATVIEN_OFF  0
    #define Si2148_MASTER_IEN_PROP_ATVIEN_ON   1

   /* MASTER_IEN property, CTSIEN field definition (NO TITLE)*/
   #define  Si2148_MASTER_IEN_PROP_CTSIEN_LSB         7
   #define  Si2148_MASTER_IEN_PROP_CTSIEN_MASK        0x01
   #define  Si2148_MASTER_IEN_PROP_CTSIEN_DEFAULT    0
    #define Si2148_MASTER_IEN_PROP_CTSIEN_OFF  0
    #define Si2148_MASTER_IEN_PROP_CTSIEN_ON   1

   /* MASTER_IEN property, DTVIEN field definition (NO TITLE)*/
   #define  Si2148_MASTER_IEN_PROP_DTVIEN_LSB         2
   #define  Si2148_MASTER_IEN_PROP_DTVIEN_MASK        0x01
   #define  Si2148_MASTER_IEN_PROP_DTVIEN_DEFAULT    0
    #define Si2148_MASTER_IEN_PROP_DTVIEN_OFF  0
    #define Si2148_MASTER_IEN_PROP_DTVIEN_ON   1

   /* MASTER_IEN property, ERRIEN field definition (NO TITLE)*/
   #define  Si2148_MASTER_IEN_PROP_ERRIEN_LSB         6
   #define  Si2148_MASTER_IEN_PROP_ERRIEN_MASK        0x01
   #define  Si2148_MASTER_IEN_PROP_ERRIEN_DEFAULT    0
    #define Si2148_MASTER_IEN_PROP_ERRIEN_OFF  0
    #define Si2148_MASTER_IEN_PROP_ERRIEN_ON   1

   /* MASTER_IEN property, TUNIEN field definition (NO TITLE)*/
   #define  Si2148_MASTER_IEN_PROP_TUNIEN_LSB         0
   #define  Si2148_MASTER_IEN_PROP_TUNIEN_MASK        0x01
   #define  Si2148_MASTER_IEN_PROP_TUNIEN_DEFAULT    0
    #define Si2148_MASTER_IEN_PROP_TUNIEN_OFF  0
    #define Si2148_MASTER_IEN_PROP_TUNIEN_ON   1

#endif /* Si2148_MASTER_IEN_PROP */

/* Si2148 TUNER_BLOCKED_VCO property definition */
#define   Si2148_TUNER_BLOCKED_VCO_PROP 0x0504

#ifdef    Si2148_TUNER_BLOCKED_VCO_PROP
  #define Si2148_TUNER_BLOCKED_VCO_PROP_CODE 0x000504


    typedef struct { /* Si2148_TUNER_BLOCKED_VCO_PROP_struct */
               int    vco_code;
   } Si2148_TUNER_BLOCKED_VCO_PROP_struct;

   /* TUNER_BLOCKED_VCO property, VCO_CODE field definition (NO TITLE)*/
   #define  Si2148_TUNER_BLOCKED_VCO_PROP_VCO_CODE_LSB         0
   #define  Si2148_TUNER_BLOCKED_VCO_PROP_VCO_CODE_MASK        0xffff
   #define  Si2148_TUNER_BLOCKED_VCO_PROP_VCO_CODE_DEFAULT    0x8000
    #define Si2148_TUNER_BLOCKED_VCO_PROP_VCO_CODE_VCO_CODE_MIN  -32768
    #define Si2148_TUNER_BLOCKED_VCO_PROP_VCO_CODE_VCO_CODE_MAX  32767

#endif /* Si2148_TUNER_BLOCKED_VCO_PROP */

/* Si2148 TUNER_IEN property definition */
#define   Si2148_TUNER_IEN_PROP 0x0501

#ifdef    Si2148_TUNER_IEN_PROP
  #define Si2148_TUNER_IEN_PROP_CODE 0x000501


    typedef struct { /* Si2148_TUNER_IEN_PROP_struct */
      unsigned char   rssihien;
      unsigned char   rssilien;
      unsigned char   tcien;
   } Si2148_TUNER_IEN_PROP_struct;

   /* TUNER_IEN property, RSSIHIEN field definition (NO TITLE)*/
   #define  Si2148_TUNER_IEN_PROP_RSSIHIEN_LSB         2
   #define  Si2148_TUNER_IEN_PROP_RSSIHIEN_MASK        0x01
   #define  Si2148_TUNER_IEN_PROP_RSSIHIEN_DEFAULT    0
    #define Si2148_TUNER_IEN_PROP_RSSIHIEN_DISABLE  0
    #define Si2148_TUNER_IEN_PROP_RSSIHIEN_ENABLE   1

   /* TUNER_IEN property, RSSILIEN field definition (NO TITLE)*/
   #define  Si2148_TUNER_IEN_PROP_RSSILIEN_LSB         1
   #define  Si2148_TUNER_IEN_PROP_RSSILIEN_MASK        0x01
   #define  Si2148_TUNER_IEN_PROP_RSSILIEN_DEFAULT    0
    #define Si2148_TUNER_IEN_PROP_RSSILIEN_DISABLE  0
    #define Si2148_TUNER_IEN_PROP_RSSILIEN_ENABLE   1

   /* TUNER_IEN property, TCIEN field definition (NO TITLE)*/
   #define  Si2148_TUNER_IEN_PROP_TCIEN_LSB         0
   #define  Si2148_TUNER_IEN_PROP_TCIEN_MASK        0x01
   #define  Si2148_TUNER_IEN_PROP_TCIEN_DEFAULT    1
    #define Si2148_TUNER_IEN_PROP_TCIEN_DISABLE  0
    #define Si2148_TUNER_IEN_PROP_TCIEN_ENABLE   1

#endif /* Si2148_TUNER_IEN_PROP */

/* Si2148 TUNER_INT_SENSE property definition */
#define   Si2148_TUNER_INT_SENSE_PROP 0x0505

#ifdef    Si2148_TUNER_INT_SENSE_PROP
  #define Si2148_TUNER_INT_SENSE_PROP_CODE 0x000505


    typedef struct { /* Si2148_TUNER_INT_SENSE_PROP_struct */
      unsigned char   rssihnegen;
      unsigned char   rssihposen;
      unsigned char   rssilnegen;
      unsigned char   rssilposen;
      unsigned char   tcnegen;
      unsigned char   tcposen;
   } Si2148_TUNER_INT_SENSE_PROP_struct;

   /* TUNER_INT_SENSE property, RSSIHNEGEN field definition (NO TITLE)*/
   #define  Si2148_TUNER_INT_SENSE_PROP_RSSIHNEGEN_LSB         2
   #define  Si2148_TUNER_INT_SENSE_PROP_RSSIHNEGEN_MASK        0x01
   #define  Si2148_TUNER_INT_SENSE_PROP_RSSIHNEGEN_DEFAULT    0
    #define Si2148_TUNER_INT_SENSE_PROP_RSSIHNEGEN_DISABLE  0
    #define Si2148_TUNER_INT_SENSE_PROP_RSSIHNEGEN_ENABLE   1

   /* TUNER_INT_SENSE property, RSSIHPOSEN field definition (NO TITLE)*/
   #define  Si2148_TUNER_INT_SENSE_PROP_RSSIHPOSEN_LSB         10
   #define  Si2148_TUNER_INT_SENSE_PROP_RSSIHPOSEN_MASK        0x01
   #define  Si2148_TUNER_INT_SENSE_PROP_RSSIHPOSEN_DEFAULT    1
    #define Si2148_TUNER_INT_SENSE_PROP_RSSIHPOSEN_DISABLE  0
    #define Si2148_TUNER_INT_SENSE_PROP_RSSIHPOSEN_ENABLE   1

   /* TUNER_INT_SENSE property, RSSILNEGEN field definition (NO TITLE)*/
   #define  Si2148_TUNER_INT_SENSE_PROP_RSSILNEGEN_LSB         1
   #define  Si2148_TUNER_INT_SENSE_PROP_RSSILNEGEN_MASK        0x01
   #define  Si2148_TUNER_INT_SENSE_PROP_RSSILNEGEN_DEFAULT    0
    #define Si2148_TUNER_INT_SENSE_PROP_RSSILNEGEN_DISABLE  0
    #define Si2148_TUNER_INT_SENSE_PROP_RSSILNEGEN_ENABLE   1

   /* TUNER_INT_SENSE property, RSSILPOSEN field definition (NO TITLE)*/
   #define  Si2148_TUNER_INT_SENSE_PROP_RSSILPOSEN_LSB         9
   #define  Si2148_TUNER_INT_SENSE_PROP_RSSILPOSEN_MASK        0x01
   #define  Si2148_TUNER_INT_SENSE_PROP_RSSILPOSEN_DEFAULT    1
    #define Si2148_TUNER_INT_SENSE_PROP_RSSILPOSEN_DISABLE  0
    #define Si2148_TUNER_INT_SENSE_PROP_RSSILPOSEN_ENABLE   1

   /* TUNER_INT_SENSE property, TCNEGEN field definition (NO TITLE)*/
   #define  Si2148_TUNER_INT_SENSE_PROP_TCNEGEN_LSB         0
   #define  Si2148_TUNER_INT_SENSE_PROP_TCNEGEN_MASK        0x01
   #define  Si2148_TUNER_INT_SENSE_PROP_TCNEGEN_DEFAULT    0
    #define Si2148_TUNER_INT_SENSE_PROP_TCNEGEN_DISABLE  0
    #define Si2148_TUNER_INT_SENSE_PROP_TCNEGEN_ENABLE   1

   /* TUNER_INT_SENSE property, TCPOSEN field definition (NO TITLE)*/
   #define  Si2148_TUNER_INT_SENSE_PROP_TCPOSEN_LSB         8
   #define  Si2148_TUNER_INT_SENSE_PROP_TCPOSEN_MASK        0x01
   #define  Si2148_TUNER_INT_SENSE_PROP_TCPOSEN_DEFAULT    1
    #define Si2148_TUNER_INT_SENSE_PROP_TCPOSEN_DISABLE  0
    #define Si2148_TUNER_INT_SENSE_PROP_TCPOSEN_ENABLE   1

#endif /* Si2148_TUNER_INT_SENSE_PROP */

/* Si2148 TUNER_LO_INJECTION property definition */
#define   Si2148_TUNER_LO_INJECTION_PROP 0x0506

#ifdef    Si2148_TUNER_LO_INJECTION_PROP
  #define Si2148_TUNER_LO_INJECTION_PROP_CODE 0x000506


    typedef struct { /* Si2148_TUNER_LO_INJECTION_PROP_struct */
      unsigned char   band_1;
      unsigned char   band_2;
      unsigned char   band_3;
   } Si2148_TUNER_LO_INJECTION_PROP_struct;

   /* TUNER_LO_INJECTION property, BAND_1 field definition (NO TITLE)*/
   #define  Si2148_TUNER_LO_INJECTION_PROP_BAND_1_LSB         0
   #define  Si2148_TUNER_LO_INJECTION_PROP_BAND_1_MASK        0x01
   #define  Si2148_TUNER_LO_INJECTION_PROP_BAND_1_DEFAULT    1
    #define Si2148_TUNER_LO_INJECTION_PROP_BAND_1_LOW_SIDE   0
    #define Si2148_TUNER_LO_INJECTION_PROP_BAND_1_HIGH_SIDE  1

   /* TUNER_LO_INJECTION property, BAND_2 field definition (NO TITLE)*/
   #define  Si2148_TUNER_LO_INJECTION_PROP_BAND_2_LSB         1
   #define  Si2148_TUNER_LO_INJECTION_PROP_BAND_2_MASK        0x01
   #define  Si2148_TUNER_LO_INJECTION_PROP_BAND_2_DEFAULT    0
    #define Si2148_TUNER_LO_INJECTION_PROP_BAND_2_LOW_SIDE   0
    #define Si2148_TUNER_LO_INJECTION_PROP_BAND_2_HIGH_SIDE  1

   /* TUNER_LO_INJECTION property, BAND_3 field definition (NO TITLE)*/
   #define  Si2148_TUNER_LO_INJECTION_PROP_BAND_3_LSB         2
   #define  Si2148_TUNER_LO_INJECTION_PROP_BAND_3_MASK        0x01
   #define  Si2148_TUNER_LO_INJECTION_PROP_BAND_3_DEFAULT    0
    #define Si2148_TUNER_LO_INJECTION_PROP_BAND_3_LOW_SIDE   0
    #define Si2148_TUNER_LO_INJECTION_PROP_BAND_3_HIGH_SIDE  1

#endif /* Si2148_TUNER_LO_INJECTION_PROP */

/* Si2148 TUNER_RETURN_LOSS property definition */
#define   Si2148_TUNER_RETURN_LOSS_PROP 0x0507

#ifdef    Si2148_TUNER_RETURN_LOSS_PROP
  #define Si2148_TUNER_RETURN_LOSS_PROP_CODE 0x000507


    typedef struct { /* Si2148_TUNER_RETURN_LOSS_PROP_struct */
      unsigned char   config;
      unsigned char   mode;
   } Si2148_TUNER_RETURN_LOSS_PROP_struct;

   /* TUNER_RETURN_LOSS property, CONFIG field definition (NO TITLE)*/
   #define  Si2148_TUNER_RETURN_LOSS_PROP_CONFIG_LSB         0
   #define  Si2148_TUNER_RETURN_LOSS_PROP_CONFIG_MASK        0xff
   #define  Si2148_TUNER_RETURN_LOSS_PROP_CONFIG_DEFAULT    127
    #define Si2148_TUNER_RETURN_LOSS_PROP_CONFIG_27   27
    #define Si2148_TUNER_RETURN_LOSS_PROP_CONFIG_31   31
    #define Si2148_TUNER_RETURN_LOSS_PROP_CONFIG_35   35
    #define Si2148_TUNER_RETURN_LOSS_PROP_CONFIG_39   39
    #define Si2148_TUNER_RETURN_LOSS_PROP_CONFIG_43   43
    #define Si2148_TUNER_RETURN_LOSS_PROP_CONFIG_47   47
    #define Si2148_TUNER_RETURN_LOSS_PROP_CONFIG_51   51
    #define Si2148_TUNER_RETURN_LOSS_PROP_CONFIG_59   59
    #define Si2148_TUNER_RETURN_LOSS_PROP_CONFIG_67   67
    #define Si2148_TUNER_RETURN_LOSS_PROP_CONFIG_75   75
    #define Si2148_TUNER_RETURN_LOSS_PROP_CONFIG_127  127

   /* TUNER_RETURN_LOSS property, MODE field definition (NO TITLE)*/
   #define  Si2148_TUNER_RETURN_LOSS_PROP_MODE_LSB         8
   #define  Si2148_TUNER_RETURN_LOSS_PROP_MODE_MASK        0xff
   #define  Si2148_TUNER_RETURN_LOSS_PROP_MODE_DEFAULT    0
    #define Si2148_TUNER_RETURN_LOSS_PROP_MODE_TERRESTRIAL  0
    #define Si2148_TUNER_RETURN_LOSS_PROP_MODE_CABLE        1

#endif /* Si2148_TUNER_RETURN_LOSS_PROP */

typedef struct
{
	#ifdef    Si2148_ATV_ARTIFICIAL_SNOW_PROP
			  Si2148_ATV_ARTIFICIAL_SNOW_PROP_struct           atv_artificial_snow;
	#endif /* Si2148_ATV_ARTIFICIAL_SNOW_PROP */
	#ifdef    Si2148_ATV_EXT_AGC_PROP
			  Si2148_ATV_EXT_AGC_PROP_struct                   atv_ext_agc;
	#endif /* Si2148_ATV_EXT_AGC_PROP */
	#ifdef    Si2148_ATV_LIF_FREQ_PROP
			  Si2148_ATV_LIF_FREQ_PROP_struct                  atv_lif_freq;
	#endif /* Si2148_ATV_LIF_FREQ_PROP */
	#ifdef    Si2148_ATV_LIF_OUT_PROP
			  Si2148_ATV_LIF_OUT_PROP_struct                   atv_lif_out;
	#endif /* Si2148_ATV_LIF_OUT_PROP */
	#ifdef    Si2148_ATV_PGA_TARGET_PROP
			  Si2148_ATV_PGA_TARGET_PROP_struct                atv_pga_target;
	#endif /* Si2148_ATV_PGA_TARGET_PROP */
	#ifdef    Si2148_CRYSTAL_TRIM_PROP
			  Si2148_CRYSTAL_TRIM_PROP_struct                  crystal_trim;
	#endif /* Si2148_CRYSTAL_TRIM_PROP */
	#ifdef    Si2148_DTV_AGC_FREEZE_INPUT_PROP
			  Si2148_DTV_AGC_FREEZE_INPUT_PROP_struct          dtv_agc_freeze_input;
	#endif /* Si2148_DTV_AGC_FREEZE_INPUT_PROP */
	#ifdef    Si2148_DTV_AGC_SPEED_PROP
			  Si2148_DTV_AGC_SPEED_PROP_struct                 dtv_agc_speed;
	#endif /* Si2148_DTV_AGC_SPEED_PROP */
	#ifdef    Si2148_DTV_CONFIG_IF_PORT_PROP
			  Si2148_DTV_CONFIG_IF_PORT_PROP_struct            dtv_config_if_port;
	#endif /* Si2148_DTV_CONFIG_IF_PORT_PROP */
	#ifdef    Si2148_DTV_EXT_AGC_PROP
			  Si2148_DTV_EXT_AGC_PROP_struct                   dtv_ext_agc;
	#endif /* Si2148_DTV_EXT_AGC_PROP */
	#ifdef    Si2148_DTV_FILTER_SELECT_PROP
			  Si2148_DTV_FILTER_SELECT_PROP_struct             dtv_filter_select;
	#endif /* Si2148_DTV_FILTER_SELECT_PROP */
	#ifdef    Si2148_DTV_IEN_PROP
			  Si2148_DTV_IEN_PROP_struct                       dtv_ien;
	#endif /* Si2148_DTV_IEN_PROP */
	#ifdef    Si2148_DTV_INITIAL_AGC_SPEED_PROP
			  Si2148_DTV_INITIAL_AGC_SPEED_PROP_struct         dtv_initial_agc_speed;
	#endif /* Si2148_DTV_INITIAL_AGC_SPEED_PROP */
	#ifdef    Si2148_DTV_INITIAL_AGC_SPEED_PERIOD_PROP
			  Si2148_DTV_INITIAL_AGC_SPEED_PERIOD_PROP_struct  dtv_initial_agc_speed_period;
	#endif /* Si2148_DTV_INITIAL_AGC_SPEED_PERIOD_PROP */
	#ifdef    Si2148_DTV_INTERNAL_ZIF_PROP
			  Si2148_DTV_INTERNAL_ZIF_PROP_struct              dtv_internal_zif;
	#endif /* Si2148_DTV_INTERNAL_ZIF_PROP */
	#ifdef    Si2148_DTV_INT_SENSE_PROP
			  Si2148_DTV_INT_SENSE_PROP_struct                 dtv_int_sense;
	#endif /* Si2148_DTV_INT_SENSE_PROP */
	#ifdef    Si2148_DTV_LIF_FREQ_PROP
			  Si2148_DTV_LIF_FREQ_PROP_struct                  dtv_lif_freq;
	#endif /* Si2148_DTV_LIF_FREQ_PROP */
	#ifdef    Si2148_DTV_LIF_OUT_PROP
			  Si2148_DTV_LIF_OUT_PROP_struct                   dtv_lif_out;
	#endif /* Si2148_DTV_LIF_OUT_PROP */
	#ifdef    Si2148_DTV_MODE_PROP
			  Si2148_DTV_MODE_PROP_struct                      dtv_mode;
	#endif /* Si2148_DTV_MODE_PROP */
	#ifdef    Si2148_DTV_PGA_LIMITS_PROP
			  Si2148_DTV_PGA_LIMITS_PROP_struct                dtv_pga_limits;
	#endif /* Si2148_DTV_PGA_LIMITS_PROP */
	#ifdef    Si2148_DTV_PGA_TARGET_PROP
			  Si2148_DTV_PGA_TARGET_PROP_struct                dtv_pga_target;
	#endif /* Si2148_DTV_PGA_TARGET_PROP */
	#ifdef    Si2148_DTV_RF_TOP_PROP
			  Si2148_DTV_RF_TOP_PROP_struct                    dtv_rf_top;
	#endif /* Si2148_DTV_RF_TOP_PROP */
	#ifdef    Si2148_DTV_RSQ_RSSI_THRESHOLD_PROP
			  Si2148_DTV_RSQ_RSSI_THRESHOLD_PROP_struct        dtv_rsq_rssi_threshold;
	#endif /* Si2148_DTV_RSQ_RSSI_THRESHOLD_PROP */
	#ifdef    Si2148_DTV_ZIF_DC_CANCELLER_BW_PROP
			  Si2148_DTV_ZIF_DC_CANCELLER_BW_PROP_struct       dtv_zif_dc_canceller_bw;
	#endif /* Si2148_DTV_ZIF_DC_CANCELLER_BW_PROP */
	#ifdef    Si2148_MASTER_IEN_PROP
			  Si2148_MASTER_IEN_PROP_struct                    master_ien;
	#endif /* Si2148_MASTER_IEN_PROP */
	#ifdef    Si2148_TUNER_BLOCKED_VCO_PROP
			  Si2148_TUNER_BLOCKED_VCO_PROP_struct             tuner_blocked_vco;
	#endif /* Si2148_TUNER_BLOCKED_VCO_PROP */
	#ifdef    Si2148_TUNER_IEN_PROP
			  Si2148_TUNER_IEN_PROP_struct                     tuner_ien;
	#endif /* Si2148_TUNER_IEN_PROP */
	#ifdef    Si2148_TUNER_INT_SENSE_PROP
			  Si2148_TUNER_INT_SENSE_PROP_struct               tuner_int_sense;
	#endif /* Si2148_TUNER_INT_SENSE_PROP */
	#ifdef    Si2148_TUNER_LO_INJECTION_PROP
			  Si2148_TUNER_LO_INJECTION_PROP_struct            tuner_lo_injection;
	#endif /* Si2148_TUNER_LO_INJECTION_PROP */
	#ifdef    Si2148_TUNER_RETURN_LOSS_PROP
			  Si2148_TUNER_RETURN_LOSS_PROP_struct             tuner_return_loss;
	#endif /* Si2148_TUNER_RETURN_LOSS_PROP */
} Si2148_PropObj;

typedef struct L1_Si2146_Context
{
	L0_Context                 *i2c;
	L0_Context                  i2cObj;
	Si2146_CmdObj              *cmd;
	Si2146_CmdObj               cmdObj;
	Si2146_CmdReplyObj         *rsp;
	Si2146_CmdReplyObj          rspObj;
	Si2146_PropObj             *prop;
	Si2146_PropObj              propObj;
	Si2146_COMMON_REPLY_struct *status;
	Si2146_COMMON_REPLY_struct  statusObj;
	//chip rev constants for integrity checking
	unsigned char chiprev;
	unsigned char part;
	// Last 2 digits of part number
	unsigned char partMajorVersion;
	unsigned char partMinorVersion;
	unsigned char partRomid;
	unsigned long newFrequency;
	// Channel Scan Globals
	// Global array to store the list of found channels
	unsigned long ChannelList[160];
	// ChannelScanPal needs to store the PAL type also so allocate 4 chars each for that
	char ChannelType[160][4];
	// Number of found channels from a channel scan
	int ChannelListSize;
	unsigned char addr;
} L1_Si2146_Context;

typedef struct L1_Si2148_Context
{
	L0_Context                 *i2c;
	L0_Context                  i2cObj;
	Si2148_CmdObj              *cmd;
	Si2148_CmdObj               cmdObj;
	Si2148_CmdReplyObj         *rsp;
	Si2148_CmdReplyObj          rspObj;
	Si2148_PropObj             *prop;
	Si2148_PropObj              propObj;
	Si2148_COMMON_REPLY_struct *status;
	Si2148_COMMON_REPLY_struct  statusObj;
	//chip rev constants for integrity checking
	unsigned char chiprev;
	unsigned char part;
	// Last 2 digits of part number
	unsigned char partMajorVersion;
	unsigned char partMinorVersion;
	unsigned char partRomid;
	// Channel Scan Globals
	// Global array to store the list of found channels
	unsigned long ChannelList[160];
	// ChannelScanPal needs to store the PAL type also so allocate 4 chars each for that
	char ChannelType[160][4];
	// Number of found channels from a channel scan
	int ChannelListSize;
	unsigned char addr;
} L1_Si2148_Context;

//Yann 2146/2148
#define SiTuner 2148
#if SiTuner==2146
#define TER_TUNER_CONTEXT L1_Si2146_Context
#else
#define TER_TUNER_CONTEXT L1_Si2148_Context
#endif

typedef struct Si2168_L2_Context
{
	L1_Si2168_Context *demod;
	TER_TUNER_CONTEXT *tuner_ter;
	L1_Si2168_Context  demodObj;
	TER_TUNER_CONTEXT  tuner_terObj;
	int                first_init_done;
	int                Si2168_init_done;
	int                TER_init_done;
	int                TER_tuner_init_done;
	int                standard;
	int                detected_rf;
	int                previous_standard;
	int                tuneUnitHz;
	int                rangeMin;
	int                rangeMax;
	int                seekBWHz;
	int                seekStepHz;
	int                minSRbps;
	int                maxSRbps;
	int                minRSSIdBm;
	int                maxRSSIdBm;
	int                minSNRHalfdB;
	int                maxSNRHalfdB;
	int                seekAbort;
	unsigned char      seekRunning;
	int                center_rf;
} Si2168_L2_Context;

typedef struct SILABS_TER_TUNER_Config
{
	unsigned char nSel_dtv_out_type;
	unsigned char nSel_dtv_agc_source;
	int           nSel_dtv_lif_freq_offset;
	unsigned char nSel_dtv_mode_bw;
	unsigned char nSel_dtv_mode_invert_spectrum;
	unsigned char nSel_dtv_mode_modulation;
	unsigned char nSel_atv_video_mode_video_sys;
	unsigned char nSel_atv_audio_mode_audio_sys;
	unsigned char nSel_atv_atv_video_mode_tran;
	unsigned char nSel_atv_video_mod_color;
	unsigned char nSel_atv_mode_invert_spectrum;
	unsigned char nSel_atv_mode_invert_signal;
	char          nSel_atv_cvbs_out_fine_amp;
	char          nSel_atv_cvbs_out_fine_offset;
	unsigned char nSel_atv_sif_out_amp;
	unsigned char nSel_atv_sif_out_offset;
	unsigned char if_agc_speed;
	char          nSel_dtv_rf_top;
	char          nSel_atv_rf_top;
	unsigned long nLocked_Freq;
	unsigned long nCenter_Freq;
	int           nCriteriaStep;
	int           nLeftMax;
	int           nRightMax;
	int           nReal_Step;
	int           nBeforeStep;
} SILABS_TER_TUNER_Config;

/*typedef struct SILABS_SAT_TUNER_Config
{
	int    RF;
	int    IF;
	int    minRF;
	int    maxRF;
	double xtal;
	double LPF;
	int    tunerBytesCount;
	int    I2CMuxChannel;
	double RefDiv_value;
	int    Mash_Per;
	CONNECTION_TYPE connType;
	unsigned char tuner_log[40];
	unsigned char tuner_read[7];
	char          nSel_att_top;
} SILABS_SAT_TUNER_Config;*/

typedef struct SILABS_CARRIER_Config
{
	int                freq;
	int                bandwidth;
	int                stream;
	int                symbol_rate;
	int                constellation;
} SILABS_CARRIER_Config;

typedef struct SILABS_ANALOG_CARRIER_Config
{
	unsigned char      video_sys;
	unsigned char      trans;
	unsigned char      color;
	unsigned char      invert_signal;
	unsigned char      invert_spectrum;
} SILABS_ANALOG_CARRIER_Config;

typedef struct SILABS_ANALOG_SIF_Config
{
	unsigned char      stereo_sys;
} SILABS_ANALOG_SIF_Config;

typedef struct SILABS_FE_Context
{
	unsigned int       chip;
	unsigned int       tuner_ter;
	unsigned int       tuner_sat;
	Si2168_L2_Context *Si2168_FE;
	Si2168_L2_Context  Si2168_FE_Obj;
	int                standard;
	int                init_ok;
	SILABS_TER_TUNER_Config      TER_Tuner_Cfg;
	//SILABS_SAT_TUNER_Config      SAT_Tuner_Cfg;
	SILABS_CARRIER_Config        Carrier_Cfg;
	SILABS_ANALOG_CARRIER_Config Analog_Cfg;
	SILABS_ANALOG_SIF_Config     Analog_Sif_Cfg;
} SILABS_FE_Context;

typedef struct CUSTOM_Status_Struct
{
	int       standard;
	int      clock_mode;
	int      demod_lock;
	int      fec_lock;
	int      fec_lock_in_range;
	//double   c_n;
	//double   ber;
	//double   per;
	//double   fer;
	int      uncorrs;
	int      RFagc;
	int      IFagc;
	int      RFlevel;
	long     freq_offset;
	long     timing_offset;
	int      bandwidth_Hz;
	int      stream;
	int      fft_mode;
	int      guard_interval;
	int      constellation;
	int      symbol_rate;
	int      code_rate_hp;
	int      code_rate_lp;
	int      hierarchy;
	int      spectral_inversion;
	int      code_rate;
	int      pilots;
	int      cell_id;
	//float    RSSI;
	int      SSI;
	int      SQI;
	int      tuner_lock;
	int      rotated;
	int      pilot_pattern;
	int      bw_ext;
	int      num_plp;
	int      tx_mode;
	int      short_frame;
	unsigned char attctrl;
	// TUNER_STATUS
	unsigned char   tcint;
	unsigned char   rssilint;
	unsigned char   rssihint;
		   int    vco_code;
	unsigned char   tc;
	unsigned char   rssil;
	unsigned char   rssih;
		   char   rssi;
	unsigned long   freq;
	unsigned char   mode;
	// ATV_STATUS & DTV_STATUS
	unsigned char   chl;
	// ATV_STATUS
	int      ATV_Sync_Lock;
	int      ATV_Master_Lock;
	unsigned char   audio_chan_filt_bw;
	unsigned char   snrl;
	unsigned char   snrh;
	unsigned char   video_snr;
		   int    afc_freq;
		   int    video_sc_spacing;
	unsigned char   video_sys;
	unsigned char   color;
	unsigned char   trans;
	unsigned char   audio_sys;
	unsigned char   audio_demod_mode;
	// DTV_STATUS
	unsigned char   chlint;
	unsigned char   bw;
	unsigned char   modulation;
	unsigned char   fef;
} CUSTOM_Status_Struct;

#ifndef __FIRMWARE_STRUCT__
#define __FIRMWARE_STRUCT__
typedef struct firmware_struct {
	unsigned char firmware_len;
	unsigned char firmware_table[16];
} firmware_struct;
#endif /* __FIRMWARE_STRUCT__ */

#define Si2146_DTV_MODE_PROP_MODULATION_ATSC    0
#define Si2146_DTV_MODE_PROP_MODULATION_QAM_US  1
#define Si2146_DTV_MODE_PROP_MODULATION_DVBT    2
#define Si2146_DTV_MODE_PROP_MODULATION_DVBC    3
#define Si2146_DTV_MODE_PROP_MODULATION_ISDBT   4
#define Si2146_DTV_MODE_PROP_MODULATION_ISDBC   5
#define Si2146_DTV_MODE_PROP_MODULATION_DTMB    6

#define L1_RF_TER_TUNER_MODULATION_DVBC  Si2146_DTV_MODE_PROP_MODULATION_DVBC
#define L1_RF_TER_TUNER_MODULATION_DVBT  Si2146_DTV_MODE_PROP_MODULATION_DVBT
#define L1_RF_TER_TUNER_MODULATION_DVBT2 Si2146_DTV_MODE_PROP_MODULATION_DVBT

void MyDelay(int nTime);
void Si2168_Initial(void);
int Si2168_Data_Update(struct rtl2832_state* p_state,int nStandard,unsigned int nFreq,unsigned int nBandwidth,unsigned int nSymbolrate, int plp_id);
int Si2168_Check_Lock(void);
int Si2168_Check_CNR(void);
int Si2168_Check_Status(void);

#endif //__Si2168RTL_H__

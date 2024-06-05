#ifndef SI2168_H
#define SI2168_H

#include <linux/dvb/frontend.h>
/*
 * I2C address
 * 0x64
 */
struct si2168_config {
	/*
	 * frontend
	 * returned by driver
	 */
	struct dvb_frontend **fe;

	/*
	 * tuner I2C adapter
	 * returned by driver
	 */
	struct i2c_adapter **i2c_adapter;

	/* TS mode */
	u8 ts_mode;

	/* TS clock inverted */
	bool ts_clock_inv;

};

#define SI2168_TS_PARALLEL	0x06
#define SI2168_TS_SERIAL	0x03

#endif

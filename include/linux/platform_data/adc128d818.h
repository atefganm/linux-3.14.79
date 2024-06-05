/*
 * Driver for TI ADC128D818 System Monitor with Temperature Sensor
 *
 * Copyright (C) 2014 Andreas Oberritter
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef __ADC128D818_H__
#define __ADC128D818_H__

/**
 * struct adc128_platform_data - adc128d818 info
 * @mode		input mode [0..3]
 */
struct adc128_platform_data {
	unsigned int mode;
};

#endif /* __ADC128D818_H__ */

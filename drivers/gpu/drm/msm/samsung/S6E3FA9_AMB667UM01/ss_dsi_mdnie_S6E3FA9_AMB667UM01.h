/*
 * =================================================================
 *
 *
 *	Description:  samsung display common file
 *
 *	Author: jb09.kim
 *	Company:  Samsung Electronics
 *
 * ================================================================
 */
/*
<one line to give the program's name and a brief idea of what it does.>
Copyright (C) 2012, Samsung Electronics. All rights reserved.

*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
*/
#ifndef _SAMSUNG_DSI_MDNIE_S6E3FA9_AMB667UM01_
#define _SAMSUNG_DSI_MDNIE_S6E3FA9_AMB667UM01_

#include "ss_dsi_mdnie_lite_common.h"

#define MDNIE_COLOR_BLINDE_CMD_OFFSET 32

#define ADDRESS_SCR_WHITE_RED   0x32
#define ADDRESS_SCR_WHITE_GREEN 0x34
#define ADDRESS_SCR_WHITE_BLUE  0x36

#define MDNIE_STEP1_INDEX 1
#define MDNIE_STEP2_INDEX 2
#define MDNIE_STEP3_INDEX 3

#define MDNIE_TRANS_DIMMING_DATA_INDEX	17

static char level_1_key_on[] = {
	0xF0,
	0x5A, 0x5A
};

static char level_1_key_off[] = {
	0xF0,
	0xA5, 0xA5
};

static char adjust_ldu_data_1[] = {
	0xff, 0xff, 0xff,
	0xfd, 0xfd, 0xff,
	0xfb, 0xfb, 0xff,
	0xf9, 0xf8, 0xff,
	0xf6, 0xf6, 0xff,
	0xf4, 0xf4, 0xff,
};

static char adjust_ldu_data_2[] = {
	0xff, 0xfc, 0xf6,
	0xfd, 0xfa, 0xf6,
	0xfb, 0xf7, 0xf6,
	0xf9, 0xf5, 0xf6,
	0xf4, 0xf0, 0xf6,
	0xf2, 0xee, 0xf6,
};

static char *adjust_ldu_data[MAX_MODE] = {
	adjust_ldu_data_2,
	adjust_ldu_data_2,
	adjust_ldu_data_2,
	adjust_ldu_data_1,
	adjust_ldu_data_1,
};

static char night_mode_data[] = {
	0x00, 0xff, 0xfc, 0x00, 0xf6, 0x00, 0xff, 0x00, 0x00, 0xfc, 0xf6, 0x00, 0xff, 0x00, 0xfc, 0x00, 0x00, 0xf6, 0xff, 0x00, 0xfc, 0x00, 0xf6, 0x00, /* 6750K */
	0x00, 0xff, 0xfb, 0x00, 0xf3, 0x00, 0xff, 0x00, 0x00, 0xfb, 0xf3, 0x00, 0xff, 0x00, 0xfb, 0x00, 0x00, 0xf3, 0xff, 0x00, 0xfb, 0x00, 0xf3, 0x00, /* 6500K */
	0x00, 0xff, 0xfa, 0x00, 0xef, 0x00, 0xff, 0x00, 0x00, 0xfa, 0xef, 0x00, 0xff, 0x00, 0xfa, 0x00, 0x00, 0xef, 0xff, 0x00, 0xfa, 0x00, 0xef, 0x00, /* 6250K */
	0x00, 0xff, 0xf8, 0x00, 0xeb, 0x00, 0xff, 0x00, 0x00, 0xf8, 0xeb, 0x00, 0xff, 0x00, 0xf8, 0x00, 0x00, 0xeb, 0xff, 0x00, 0xf8, 0x00, 0xeb, 0x00, /* 6000K */
	0x00, 0xff, 0xf7, 0x00, 0xe7, 0x00, 0xff, 0x00, 0x00, 0xf7, 0xe7, 0x00, 0xff, 0x00, 0xf7, 0x00, 0x00, 0xe7, 0xff, 0x00, 0xf7, 0x00, 0xe7, 0x00, /* 5750K */
	0x00, 0xff, 0xf5, 0x00, 0xe2, 0x00, 0xff, 0x00, 0x00, 0xf5, 0xe2, 0x00, 0xff, 0x00, 0xf5, 0x00, 0x00, 0xe2, 0xff, 0x00, 0xf5, 0x00, 0xe2, 0x00, /* 5500K */
	0x00, 0xff, 0xf0, 0x00, 0xd3, 0x00, 0xff, 0x00, 0x00, 0xf0, 0xd3, 0x00, 0xff, 0x00, 0xf0, 0x00, 0x00, 0xd3, 0xff, 0x00, 0xf0, 0x00, 0xd3, 0x00, /* 4900K */
	0x00, 0xff, 0xe9, 0x00, 0xbe, 0x00, 0xff, 0x00, 0x00, 0xe9, 0xbe, 0x00, 0xff, 0x00, 0xe9, 0x00, 0x00, 0xbe, 0xff, 0x00, 0xe9, 0x00, 0xbe, 0x00, /* 4300K */
	0x00, 0xff, 0xe0, 0x00, 0xa4, 0x00, 0xff, 0x00, 0x00, 0xe0, 0xa4, 0x00, 0xff, 0x00, 0xe0, 0x00, 0x00, 0xa4, 0xff, 0x00, 0xe0, 0x00, 0xa4, 0x00, /* 3700K */
	0x00, 0xff, 0xd3, 0x00, 0x86, 0x00, 0xff, 0x00, 0x00, 0xd3, 0x86, 0x00, 0xff, 0x00, 0xd3, 0x00, 0x00, 0x86, 0xff, 0x00, 0xd3, 0x00, 0x86, 0x00, /* 3100K */
	0x00, 0xff, 0xb8, 0x00, 0x58, 0x00, 0xff, 0x00, 0x00, 0xb8, 0x58, 0x00, 0xff, 0x00, 0xb8, 0x00, 0x00, 0x58, 0xff, 0x00, 0xb8, 0x00, 0x58, 0x00, /* 2300K */
};

static char color_lens_data[] = {
	//Blue
	0x00, 0xcc, 0xcc, 0x00, 0xff, 0x33, 0xcc, 0x00, 0x00, 0xcc, 0xff, 0x33, 0xcc, 0x00, 0xcc, 0x00, 0x33, 0xff, 0xcc, 0x00, 0xcc, 0x00, 0xff, 0x33, /* 20% */
	0x00, 0xbf, 0xbf, 0x00, 0xff, 0x40, 0xbf, 0x00, 0x00, 0xbf, 0xff, 0x40, 0xbf, 0x00, 0xbf, 0x00, 0x40, 0xff, 0xbf, 0x00, 0xbf, 0x00, 0xff, 0x40, /* 25% */
	0x00, 0xb2, 0xb2, 0x00, 0xff, 0x4d, 0xb2, 0x00, 0x00, 0xb2, 0xff, 0x4d, 0xb2, 0x00, 0xb2, 0x00, 0x4d, 0xff, 0xb2, 0x00, 0xb2, 0x00, 0xff, 0x4d, /* 30% */
	0x00, 0xa6, 0xa6, 0x00, 0xff, 0x59, 0xa6, 0x00, 0x00, 0xa6, 0xff, 0x59, 0xa6, 0x00, 0xa6, 0x00, 0x59, 0xff, 0xa6, 0x00, 0xa6, 0x00, 0xff, 0x59, /* 35% */
	0x00, 0x99, 0x99, 0x00, 0xff, 0x66, 0x99, 0x00, 0x00, 0x99, 0xff, 0x66, 0x99, 0x00, 0x99, 0x00, 0x66, 0xff, 0x99, 0x00, 0x99, 0x00, 0xff, 0x66, /* 40% */
	0x00, 0x8c, 0x8c, 0x00, 0xff, 0x73, 0x8c, 0x00, 0x00, 0x8c, 0xff, 0x73, 0x8c, 0x00, 0x8c, 0x00, 0x73, 0xff, 0x8c, 0x00, 0x8c, 0x00, 0xff, 0x73, /* 45% */
	0x00, 0x7f, 0x7f, 0x00, 0xff, 0x80, 0x7f, 0x00, 0x00, 0x7f, 0xff, 0x80, 0x7f, 0x00, 0x7f, 0x00, 0x80, 0xff, 0x7f, 0x00, 0x7f, 0x00, 0xff, 0x80, /* 50% */
	0x00, 0x73, 0x73, 0x00, 0xff, 0x8c, 0x73, 0x00, 0x00, 0x73, 0xff, 0x8c, 0x73, 0x00, 0x73, 0x00, 0x8c, 0xff, 0x73, 0x00, 0x73, 0x00, 0xff, 0x8c, /* 55% */
	0x00, 0x66, 0x66, 0x00, 0xff, 0x99, 0x66, 0x00, 0x00, 0x66, 0xff, 0x99, 0x66, 0x00, 0x66, 0x00, 0x99, 0xff, 0x66, 0x00, 0x66, 0x00, 0xff, 0x99, /* 60% */

	//Azure
	0x00, 0xcc, 0xe5, 0x19, 0xff, 0x33, 0xcc, 0x00, 0x19, 0xe5, 0xff, 0x33, 0xcc, 0x00, 0xe5, 0x19, 0x33, 0xff, 0xcc, 0x00, 0xe5, 0x19, 0xff, 0x33, /* 20% */
	0x00, 0xbf, 0xdf, 0x20, 0xff, 0x40, 0xbf, 0x00, 0x20, 0xdf, 0xff, 0x40, 0xbf, 0x00, 0xdf, 0x20, 0x40, 0xff, 0xbf, 0x00, 0xdf, 0x20, 0xff, 0x40, /* 25% */
	0x00, 0xb2, 0xd8, 0x26, 0xff, 0x4d, 0xb2, 0x00, 0x26, 0xd8, 0xff, 0x4d, 0xb2, 0x00, 0xd8, 0x26, 0x4d, 0xff, 0xb2, 0x00, 0xd8, 0x26, 0xff, 0x4d, /* 30% */
	0x00, 0xa6, 0xd2, 0x2c, 0xff, 0x59, 0xa6, 0x00, 0x2c, 0xd2, 0xff, 0x59, 0xa6, 0x00, 0xd2, 0x2c, 0x59, 0xff, 0xa6, 0x00, 0xd2, 0x2c, 0xff, 0x59, /* 35% */
	0x00, 0x99, 0xcc, 0x33, 0xff, 0x66, 0x99, 0x00, 0x33, 0xcc, 0xff, 0x66, 0x99, 0x00, 0xcc, 0x33, 0x66, 0xff, 0x99, 0x00, 0xcc, 0x33, 0xff, 0x66, /* 40% */
	0x00, 0x8c, 0xc5, 0x39, 0xff, 0x73, 0x8c, 0x00, 0x39, 0xc5, 0xff, 0x73, 0x8c, 0x00, 0xc5, 0x39, 0x73, 0xff, 0x8c, 0x00, 0xc5, 0x39, 0xff, 0x73, /* 45% */
	0x00, 0x7f, 0xbf, 0x40, 0xff, 0x80, 0x7f, 0x00, 0x40, 0xbf, 0xff, 0x80, 0x7f, 0x00, 0xbf, 0x40, 0x80, 0xff, 0x7f, 0x00, 0xbf, 0x40, 0xff, 0x80, /* 50% */
	0x00, 0x73, 0xb9, 0x46, 0xff, 0x8c, 0x73, 0x00, 0x46, 0xb9, 0xff, 0x8c, 0x73, 0x00, 0xb9, 0x46, 0x8c, 0xff, 0x73, 0x00, 0xb9, 0x46, 0xff, 0x8c, /* 55% */
	0x00, 0x66, 0xb2, 0x4c, 0xff, 0x99, 0x66, 0x00, 0x4c, 0xb2, 0xff, 0x99, 0x66, 0x00, 0xb2, 0x4c, 0x99, 0xff, 0x66, 0x00, 0xb2, 0x4c, 0xff, 0x99, /* 60% */

	//Cyan
	0x00, 0xcc, 0xff, 0x33, 0xff, 0x33, 0xcc, 0x00, 0x33, 0xff, 0xff, 0x33, 0xcc, 0x00, 0xff, 0x33, 0x33, 0xff, 0xcc, 0x00, 0xff, 0x33, 0xff, 0x33, /* 20% */
	0x00, 0xbf, 0xff, 0x40, 0xff, 0x40, 0xbf, 0x00, 0x40, 0xff, 0xff, 0x40, 0xbf, 0x00, 0xff, 0x40, 0x40, 0xff, 0xbf, 0x00, 0xff, 0x40, 0xff, 0x40, /* 25% */
	0x00, 0xb2, 0xff, 0x4d, 0xff, 0x4d, 0xb2, 0x00, 0x4d, 0xff, 0xff, 0x4d, 0xb2, 0x00, 0xff, 0x4d, 0x4d, 0xff, 0xb2, 0x00, 0xff, 0x4d, 0xff, 0x4d, /* 30% */
	0x00, 0xa6, 0xff, 0x59, 0xff, 0x59, 0xa6, 0x00, 0x59, 0xff, 0xff, 0x59, 0xa6, 0x00, 0xff, 0x59, 0x59, 0xff, 0xa6, 0x00, 0xff, 0x59, 0xff, 0x59, /* 35% */
	0x00, 0x99, 0xff, 0x66, 0xff, 0x66, 0x99, 0x00, 0x66, 0xff, 0xff, 0x66, 0x99, 0x00, 0xff, 0x66, 0x66, 0xff, 0x99, 0x00, 0xff, 0x66, 0xff, 0x66, /* 40% */
	0x00, 0x8c, 0xff, 0x73, 0xff, 0x73, 0x8c, 0x00, 0x73, 0xff, 0xff, 0x73, 0x8c, 0x00, 0xff, 0x73, 0x73, 0xff, 0x8c, 0x00, 0xff, 0x73, 0xff, 0x73, /* 45% */
	0x00, 0x7f, 0xff, 0x80, 0xff, 0x80, 0x7f, 0x00, 0x80, 0xff, 0xff, 0x80, 0x7f, 0x00, 0xff, 0x80, 0x80, 0xff, 0x7f, 0x00, 0xff, 0x80, 0xff, 0x80, /* 50% */
	0x00, 0x73, 0xff, 0x8c, 0xff, 0x8c, 0x73, 0x00, 0x8c, 0xff, 0xff, 0x8c, 0x73, 0x00, 0xff, 0x8c, 0x8c, 0xff, 0x73, 0x00, 0xff, 0x8c, 0xff, 0x8c, /* 55% */
	0x00, 0x66, 0xff, 0x99, 0xff, 0x99, 0x66, 0x00, 0x99, 0xff, 0xff, 0x99, 0x66, 0x00, 0xff, 0x99, 0x99, 0xff, 0x66, 0x00, 0xff, 0x99, 0xff, 0x99, /* 60% */

	//Spring green
	0x00, 0xcc, 0xff, 0x33, 0xe5, 0x19, 0xcc, 0x00, 0x33, 0xff, 0xe5, 0x19, 0xcc, 0x00, 0xff, 0x33, 0x19, 0xe5, 0xcc, 0x00, 0xff, 0x33, 0xe5, 0x19, /* 20% */
	0x00, 0xbf, 0xff, 0x40, 0xdf, 0x20, 0xbf, 0x00, 0x40, 0xff, 0xdf, 0x20, 0xbf, 0x00, 0xff, 0x40, 0x20, 0xdf, 0xbf, 0x00, 0xff, 0x40, 0xdf, 0x20, /* 25% */
	0x00, 0xb2, 0xff, 0x4d, 0xd8, 0x26, 0xb2, 0x00, 0x4d, 0xff, 0xd8, 0x26, 0xb2, 0x00, 0xff, 0x4d, 0x26, 0xd8, 0xb2, 0x00, 0xff, 0x4d, 0xd8, 0x26, /* 30% */
	0x00, 0xa6, 0xff, 0x59, 0xd2, 0x2c, 0xa6, 0x00, 0x59, 0xff, 0xd2, 0x2c, 0xa6, 0x00, 0xff, 0x59, 0x2c, 0xd2, 0xa6, 0x00, 0xff, 0x59, 0xd2, 0x2c, /* 35% */
	0x00, 0x99, 0xff, 0x66, 0xcc, 0x33, 0x99, 0x00, 0x66, 0xff, 0xcc, 0x33, 0x99, 0x00, 0xff, 0x66, 0x33, 0xcc, 0x99, 0x00, 0xff, 0x66, 0xcc, 0x33, /* 40% */
	0x00, 0x8c, 0xff, 0x73, 0xc5, 0x39, 0x8c, 0x00, 0x73, 0xff, 0xc5, 0x39, 0x8c, 0x00, 0xff, 0x73, 0x39, 0xc5, 0x8c, 0x00, 0xff, 0x73, 0xc5, 0x39, /* 45% */
	0x00, 0x7f, 0xff, 0x80, 0xbf, 0x40, 0x7f, 0x00, 0x80, 0xff, 0xbf, 0x40, 0x7f, 0x00, 0xff, 0x80, 0x40, 0xbf, 0x7f, 0x00, 0xff, 0x80, 0xbf, 0x40, /* 50% */
	0x00, 0x73, 0xff, 0x8c, 0xb9, 0x46, 0x73, 0x00, 0x8c, 0xff, 0xb9, 0x46, 0x73, 0x00, 0xff, 0x8c, 0x46, 0xb9, 0x73, 0x00, 0xff, 0x8c, 0xb9, 0x46, /* 55% */
	0x00, 0x66, 0xff, 0x99, 0xb2, 0x4c, 0x66, 0x00, 0x99, 0xff, 0xb2, 0x4c, 0x66, 0x00, 0xff, 0x99, 0x4c, 0xb2, 0x66, 0x00, 0xff, 0x99, 0xb2, 0x4c, /* 60% */

	//Green
	0x00, 0xcc, 0xff, 0x33, 0xcc, 0x00, 0xcc, 0x00, 0x33, 0xff, 0xcc, 0x00, 0xcc, 0x00, 0xff, 0x33, 0x00, 0xcc, 0xcc, 0x00, 0xff, 0x33, 0xcc, 0x00, /* 20% */
	0x00, 0xbf, 0xff, 0x40, 0xbf, 0x00, 0xbf, 0x00, 0x40, 0xff, 0xbf, 0x00, 0xbf, 0x00, 0xff, 0x40, 0x00, 0xbf, 0xbf, 0x00, 0xff, 0x40, 0xbf, 0x00, /* 25% */
	0x00, 0xb2, 0xff, 0x4d, 0xb2, 0x00, 0xb2, 0x00, 0x4d, 0xff, 0xb2, 0x00, 0xb2, 0x00, 0xff, 0x4d, 0x00, 0xb2, 0xb2, 0x00, 0xff, 0x4d, 0xb2, 0x00, /* 30% */
	0x00, 0xa6, 0xff, 0x59, 0xa6, 0x00, 0xa6, 0x00, 0x59, 0xff, 0xa6, 0x00, 0xa6, 0x00, 0xff, 0x59, 0x00, 0xa6, 0xa6, 0x00, 0xff, 0x59, 0xa6, 0x00, /* 35% */
	0x00, 0x99, 0xff, 0x66, 0x99, 0x00, 0x99, 0x00, 0x66, 0xff, 0x99, 0x00, 0x99, 0x00, 0xff, 0x66, 0x00, 0x99, 0x99, 0x00, 0xff, 0x66, 0x99, 0x00, /* 40% */
	0x00, 0x8c, 0xff, 0x73, 0x8c, 0x00, 0x8c, 0x00, 0x73, 0xff, 0x8c, 0x00, 0x8c, 0x00, 0xff, 0x73, 0x00, 0x8c, 0x8c, 0x00, 0xff, 0x73, 0x8c, 0x00, /* 45% */
	0x00, 0x7f, 0xff, 0x80, 0x7f, 0x00, 0x7f, 0x00, 0x80, 0xff, 0x7f, 0x00, 0x7f, 0x00, 0xff, 0x80, 0x00, 0x7f, 0x7f, 0x00, 0xff, 0x80, 0x7f, 0x00, /* 50% */
	0x00, 0x73, 0xff, 0x8c, 0x73, 0x00, 0x73, 0x00, 0x8c, 0xff, 0x73, 0x00, 0x73, 0x00, 0xff, 0x8c, 0x00, 0x73, 0x73, 0x00, 0xff, 0x8c, 0x73, 0x00, /* 55% */
	0x00, 0x66, 0xff, 0x99, 0x66, 0x00, 0x66, 0x00, 0x99, 0xff, 0x66, 0x00, 0x66, 0x00, 0xff, 0x99, 0x00, 0x66, 0x66, 0x00, 0xff, 0x99, 0x66, 0x00, /* 60% */

	//Chartreuse Green
	0x19, 0xe5, 0xff, 0x33, 0xcc, 0x00, 0xe5, 0x19, 0x33, 0xff, 0xcc, 0x00, 0xe5, 0x19, 0xff, 0x33, 0x00, 0xcc, 0xe5, 0x19, 0xff, 0x33, 0xcc, 0x00, /* 20% */
	0x20, 0xdf, 0xff, 0x40, 0xbf, 0x00, 0xdf, 0x20, 0x40, 0xff, 0xbf, 0x00, 0xdf, 0x20, 0xff, 0x40, 0x00, 0xbf, 0xdf, 0x20, 0xff, 0x40, 0xbf, 0x00, /* 25% */
	0x26, 0xd8, 0xff, 0x4d, 0xb2, 0x00, 0xd8, 0x26, 0x4d, 0xff, 0xb2, 0x00, 0xd8, 0x26, 0xff, 0x4d, 0x00, 0xb2, 0xd8, 0x26, 0xff, 0x4d, 0xb2, 0x00, /* 30% */
	0x2c, 0xd2, 0xff, 0x59, 0xa6, 0x00, 0xd2, 0x2c, 0x59, 0xff, 0xa6, 0x00, 0xd2, 0x2c, 0xff, 0x59, 0x00, 0xa6, 0xd2, 0x2c, 0xff, 0x59, 0xa6, 0x00, /* 35% */
	0x33, 0xcc, 0xff, 0x66, 0x99, 0x00, 0xcc, 0x33, 0x66, 0xff, 0x99, 0x00, 0xcc, 0x33, 0xff, 0x66, 0x00, 0x99, 0xcc, 0x33, 0xff, 0x66, 0x99, 0x00, /* 40% */
	0x39, 0xc5, 0xff, 0x73, 0x8c, 0x00, 0xc5, 0x39, 0x73, 0xff, 0x8c, 0x00, 0xc5, 0x39, 0xff, 0x73, 0x00, 0x8c, 0xc5, 0x39, 0xff, 0x73, 0x8c, 0x00, /* 45% */
	0x40, 0xbf, 0xff, 0x80, 0x7f, 0x00, 0xbf, 0x40, 0x80, 0xff, 0x7f, 0x00, 0xbf, 0x40, 0xff, 0x80, 0x00, 0x7f, 0xbf, 0x40, 0xff, 0x80, 0x7f, 0x00, /* 50% */
	0x46, 0xb9, 0xff, 0x8c, 0x73, 0x00, 0xb9, 0x46, 0x8c, 0xff, 0x73, 0x00, 0xb9, 0x46, 0xff, 0x8c, 0x00, 0x73, 0xb9, 0x46, 0xff, 0x8c, 0x73, 0x00, /* 55% */
	0x4c, 0xb2, 0xff, 0x99, 0x66, 0x00, 0xb2, 0x4c, 0x99, 0xff, 0x66, 0x00, 0xb2, 0x4c, 0xff, 0x99, 0x00, 0x66, 0xb2, 0x4c, 0xff, 0x99, 0x66, 0x00, /* 60% */

	//Yellow
	0x33, 0xff, 0xff, 0x33, 0xcc, 0x00, 0xff, 0x33, 0x33, 0xff, 0xcc, 0x00, 0xff, 0x33, 0xff, 0x33, 0x00, 0xcc, 0xff, 0x33, 0xff, 0x33, 0xcc, 0x00, /* 20% */
	0x40, 0xff, 0xff, 0x40, 0xbf, 0x00, 0xff, 0x40, 0x40, 0xff, 0xbf, 0x00, 0xff, 0x40, 0xff, 0x40, 0x00, 0xbf, 0xff, 0x40, 0xff, 0x40, 0xbf, 0x00, /* 25% */
	0x4d, 0xff, 0xff, 0x4d, 0xb2, 0x00, 0xff, 0x4d, 0x4d, 0xff, 0xb2, 0x00, 0xff, 0x4d, 0xff, 0x4d, 0x00, 0xb2, 0xff, 0x4d, 0xff, 0x4d, 0xb2, 0x00, /* 30% */
	0x59, 0xff, 0xff, 0x59, 0xa6, 0x00, 0xff, 0x59, 0x59, 0xff, 0xa6, 0x00, 0xff, 0x59, 0xff, 0x59, 0x00, 0xa6, 0xff, 0x59, 0xff, 0x59, 0xa6, 0x00, /* 35% */
	0x66, 0xff, 0xff, 0x66, 0x99, 0x00, 0xff, 0x66, 0x66, 0xff, 0x99, 0x00, 0xff, 0x66, 0xff, 0x66, 0x00, 0x99, 0xff, 0x66, 0xff, 0x66, 0x99, 0x00, /* 40% */
	0x73, 0xff, 0xff, 0x73, 0x8c, 0x00, 0xff, 0x73, 0x73, 0xff, 0x8c, 0x00, 0xff, 0x73, 0xff, 0x73, 0x00, 0x8c, 0xff, 0x73, 0xff, 0x73, 0x8c, 0x00, /* 45% */
	0x80, 0xff, 0xff, 0x80, 0x7f, 0x00, 0xff, 0x80, 0x80, 0xff, 0x7f, 0x00, 0xff, 0x80, 0xff, 0x80, 0x00, 0x7f, 0xff, 0x80, 0xff, 0x80, 0x7f, 0x00, /* 50% */
	0x8c, 0xff, 0xff, 0x8c, 0x73, 0x00, 0xff, 0x8c, 0x8c, 0xff, 0x73, 0x00, 0xff, 0x8c, 0xff, 0x8c, 0x00, 0x73, 0xff, 0x8c, 0xff, 0x8c, 0x73, 0x00, /* 55% */
	0x99, 0xff, 0xff, 0x99, 0x66, 0x00, 0xff, 0x99, 0x99, 0xff, 0x66, 0x00, 0xff, 0x99, 0xff, 0x99, 0x00, 0x66, 0xff, 0x99, 0xff, 0x99, 0x66, 0x00, /* 60% */

	//Orange
	0x33, 0xff, 0xe5, 0x19, 0xcc, 0x00, 0xff, 0x33, 0x19, 0xe5, 0xcc, 0x00, 0xff, 0x33, 0xe5, 0x19, 0x00, 0xcc, 0xff, 0x33, 0xe5, 0x19, 0xcc, 0x00, /* 20% */
	0x40, 0xff, 0xdf, 0x20, 0xbf, 0x00, 0xff, 0x40, 0x20, 0xdf, 0xbf, 0x00, 0xff, 0x40, 0xdf, 0x20, 0x00, 0xbf, 0xff, 0x40, 0xdf, 0x20, 0xbf, 0x00, /* 25% */
	0x4d, 0xff, 0xd8, 0x26, 0xb2, 0x00, 0xff, 0x4d, 0x26, 0xd8, 0xb2, 0x00, 0xff, 0x4d, 0xd8, 0x26, 0x00, 0xb2, 0xff, 0x4d, 0xd8, 0x26, 0xb2, 0x00, /* 30% */
	0x59, 0xff, 0xd2, 0x2c, 0xa6, 0x00, 0xff, 0x59, 0x2c, 0xd2, 0xa6, 0x00, 0xff, 0x59, 0xd2, 0x2c, 0x00, 0xa6, 0xff, 0x59, 0xd2, 0x2c, 0xa6, 0x00, /* 35% */
	0x66, 0xff, 0xcc, 0x33, 0x99, 0x00, 0xff, 0x66, 0x33, 0xcc, 0x99, 0x00, 0xff, 0x66, 0xcc, 0x33, 0x00, 0x99, 0xff, 0x66, 0xcc, 0x33, 0x99, 0x00, /* 40% */
	0x73, 0xff, 0xc5, 0x39, 0x8c, 0x00, 0xff, 0x73, 0x39, 0xc5, 0x8c, 0x00, 0xff, 0x73, 0xc5, 0x39, 0x00, 0x8c, 0xff, 0x73, 0xc5, 0x39, 0x8c, 0x00, /* 45% */
	0x80, 0xff, 0xbf, 0x40, 0x7f, 0x00, 0xff, 0x80, 0x40, 0xbf, 0x7f, 0x00, 0xff, 0x80, 0xbf, 0x40, 0x00, 0x7f, 0xff, 0x80, 0xbf, 0x40, 0x7f, 0x00, /* 50% */
	0x8c, 0xff, 0xb9, 0x46, 0x73, 0x00, 0xff, 0x8c, 0x46, 0xb9, 0x73, 0x00, 0xff, 0x8c, 0xb9, 0x46, 0x00, 0x73, 0xff, 0x8c, 0xb9, 0x46, 0x73, 0x00, /* 55% */
	0x99, 0xff, 0xb2, 0x4c, 0x66, 0x00, 0xff, 0x99, 0x4c, 0xb2, 0x66, 0x00, 0xff, 0x99, 0xb2, 0x4c, 0x00, 0x66, 0xff, 0x99, 0xb2, 0x4c, 0x66, 0x00, /* 60% */

	//Red
	0x33, 0xff, 0xcc, 0x00, 0xcc, 0x00, 0xff, 0x33, 0x00, 0xcc, 0xcc, 0x00, 0xff, 0x33, 0xcc, 0x00, 0x00, 0xcc, 0xff, 0x33, 0xcc, 0x00, 0xcc, 0x00, /* 20% */
	0x40, 0xff, 0xbf, 0x00, 0xbf, 0x00, 0xff, 0x40, 0x00, 0xbf, 0xbf, 0x00, 0xff, 0x40, 0xbf, 0x00, 0x00, 0xbf, 0xff, 0x40, 0xbf, 0x00, 0xbf, 0x00, /* 25% */
	0x4d, 0xff, 0xb2, 0x00, 0xb2, 0x00, 0xff, 0x4d, 0x00, 0xb2, 0xb2, 0x00, 0xff, 0x4d, 0xb2, 0x00, 0x00, 0xb2, 0xff, 0x4d, 0xb2, 0x00, 0xb2, 0x00, /* 30% */
	0x59, 0xff, 0xa6, 0x00, 0xa6, 0x00, 0xff, 0x59, 0x00, 0xa6, 0xa6, 0x00, 0xff, 0x59, 0xa6, 0x00, 0x00, 0xa6, 0xff, 0x59, 0xa6, 0x00, 0xa6, 0x00, /* 35% */
	0x66, 0xff, 0x99, 0x00, 0x99, 0x00, 0xff, 0x66, 0x00, 0x99, 0x99, 0x00, 0xff, 0x66, 0x99, 0x00, 0x00, 0x99, 0xff, 0x66, 0x99, 0x00, 0x99, 0x00, /* 40% */
	0x73, 0xff, 0x8c, 0x00, 0x8c, 0x00, 0xff, 0x73, 0x00, 0x8c, 0x8c, 0x00, 0xff, 0x73, 0x8c, 0x00, 0x00, 0x8c, 0xff, 0x73, 0x8c, 0x00, 0x8c, 0x00, /* 45% */
	0x80, 0xff, 0x7f, 0x00, 0x7f, 0x00, 0xff, 0x80, 0x00, 0x7f, 0x7f, 0x00, 0xff, 0x80, 0x7f, 0x00, 0x00, 0x7f, 0xff, 0x80, 0x7f, 0x00, 0x7f, 0x00, /* 50% */
	0x8c, 0xff, 0x73, 0x00, 0x73, 0x00, 0xff, 0x8c, 0x00, 0x73, 0x73, 0x00, 0xff, 0x8c, 0x73, 0x00, 0x00, 0x73, 0xff, 0x8c, 0x73, 0x00, 0x73, 0x00, /* 55% */
	0x99, 0xff, 0x66, 0x00, 0x66, 0x00, 0xff, 0x99, 0x00, 0x66, 0x66, 0x00, 0xff, 0x99, 0x66, 0x00, 0x00, 0x66, 0xff, 0x99, 0x66, 0x00, 0x66, 0x00, /* 60% */

	//Rose
	0x33, 0xff, 0xcc, 0x00, 0xe5, 0x19, 0xff, 0x33, 0x00, 0xcc, 0xe5, 0x19, 0xff, 0x33, 0xcc, 0x00, 0x19, 0xe5, 0xff, 0x33, 0xcc, 0x00, 0xe5, 0x19, /* 20% */
	0x40, 0xff, 0xbf, 0x00, 0xdf, 0x20, 0xff, 0x40, 0x00, 0xbf, 0xdf, 0x20, 0xff, 0x40, 0xbf, 0x00, 0x20, 0xdf, 0xff, 0x40, 0xbf, 0x00, 0xdf, 0x20, /* 25% */
	0x4d, 0xff, 0xb2, 0x00, 0xd8, 0x26, 0xff, 0x4d, 0x00, 0xb2, 0xd8, 0x26, 0xff, 0x4d, 0xb2, 0x00, 0x26, 0xd8, 0xff, 0x4d, 0xb2, 0x00, 0xd8, 0x26, /* 30% */
	0x59, 0xff, 0xa6, 0x00, 0xd2, 0x2c, 0xff, 0x59, 0x00, 0xa6, 0xd2, 0x2c, 0xff, 0x59, 0xa6, 0x00, 0x2c, 0xd2, 0xff, 0x59, 0xa6, 0x00, 0xd2, 0x2c, /* 35% */
	0x66, 0xff, 0x99, 0x00, 0xcc, 0x33, 0xff, 0x66, 0x00, 0x99, 0xcc, 0x33, 0xff, 0x66, 0x99, 0x00, 0x33, 0xcc, 0xff, 0x66, 0x99, 0x00, 0xcc, 0x33, /* 40% */
	0x73, 0xff, 0x8c, 0x00, 0xc5, 0x39, 0xff, 0x73, 0x00, 0x8c, 0xc5, 0x39, 0xff, 0x73, 0x8c, 0x00, 0x39, 0xc5, 0xff, 0x73, 0x8c, 0x00, 0xc5, 0x39, /* 45% */
	0x80, 0xff, 0x7f, 0x00, 0xbf, 0x40, 0xff, 0x80, 0x00, 0x7f, 0xbf, 0x40, 0xff, 0x80, 0x7f, 0x00, 0x40, 0xbf, 0xff, 0x80, 0x7f, 0x00, 0xbf, 0x40, /* 50% */
	0x8c, 0xff, 0x73, 0x00, 0xb9, 0x46, 0xff, 0x8c, 0x00, 0x73, 0xb9, 0x46, 0xff, 0x8c, 0x73, 0x00, 0x46, 0xb9, 0xff, 0x8c, 0x73, 0x00, 0xb9, 0x46, /* 55% */
	0x99, 0xff, 0x66, 0x00, 0xb2, 0x4c, 0xff, 0x99, 0x00, 0x66, 0xb2, 0x4c, 0xff, 0x99, 0x66, 0x00, 0x4c, 0xb2, 0xff, 0x99, 0x66, 0x00, 0xb2, 0x4c, /* 60% */

	//Magenta
	0x33, 0xff, 0xcc, 0x00, 0xff, 0x33, 0xff, 0x33, 0x00, 0xcc, 0xff, 0x33, 0xff, 0x33, 0xcc, 0x00, 0x33, 0xff, 0xff, 0x33, 0xcc, 0x00, 0xff, 0x33, /* 20% */
	0x40, 0xff, 0xbf, 0x00, 0xff, 0x40, 0xff, 0x40, 0x00, 0xbf, 0xff, 0x40, 0xff, 0x40, 0xbf, 0x00, 0x40, 0xff, 0xff, 0x40, 0xbf, 0x00, 0xff, 0x40, /* 25% */
	0x4d, 0xff, 0xb2, 0x00, 0xff, 0x4d, 0xff, 0x4d, 0x00, 0xb2, 0xff, 0x4d, 0xff, 0x4d, 0xb2, 0x00, 0x4d, 0xff, 0xff, 0x4d, 0xb2, 0x00, 0xff, 0x4d, /* 30% */
	0x59, 0xff, 0xa6, 0x00, 0xff, 0x59, 0xff, 0x59, 0x00, 0xa6, 0xff, 0x59, 0xff, 0x59, 0xa6, 0x00, 0x59, 0xff, 0xff, 0x59, 0xa6, 0x00, 0xff, 0x59, /* 35% */
	0x66, 0xff, 0x99, 0x00, 0xff, 0x66, 0xff, 0x66, 0x00, 0x99, 0xff, 0x66, 0xff, 0x66, 0x99, 0x00, 0x66, 0xff, 0xff, 0x66, 0x99, 0x00, 0xff, 0x66, /* 40% */
	0x73, 0xff, 0x8c, 0x00, 0xff, 0x73, 0xff, 0x73, 0x00, 0x8c, 0xff, 0x73, 0xff, 0x73, 0x8c, 0x00, 0x73, 0xff, 0xff, 0x73, 0x8c, 0x00, 0xff, 0x73, /* 45% */
	0x80, 0xff, 0x7f, 0x00, 0xff, 0x80, 0xff, 0x80, 0x00, 0x7f, 0xff, 0x80, 0xff, 0x80, 0x7f, 0x00, 0x80, 0xff, 0xff, 0x80, 0x7f, 0x00, 0xff, 0x80, /* 50% */
	0x8c, 0xff, 0x73, 0x00, 0xff, 0x8c, 0xff, 0x8c, 0x00, 0x73, 0xff, 0x8c, 0xff, 0x8c, 0x73, 0x00, 0x8c, 0xff, 0xff, 0x8c, 0x73, 0x00, 0xff, 0x8c, /* 55% */
	0x99, 0xff, 0x66, 0x00, 0xff, 0x99, 0xff, 0x99, 0x00, 0x66, 0xff, 0x99, 0xff, 0x99, 0x66, 0x00, 0x99, 0xff, 0xff, 0x99, 0x66, 0x00, 0xff, 0x99, /* 60% */

	//Violet
	0x19, 0xe5, 0xcc, 0x00, 0xff, 0x33, 0xe5, 0x19, 0x00, 0xcc, 0xff, 0x33, 0xe5, 0x19, 0xcc, 0x00, 0x33, 0xff, 0xe5, 0x19, 0xcc, 0x00, 0xff, 0x33, /* 20% */
	0x20, 0xdf, 0xbf, 0x00, 0xff, 0x40, 0xdf, 0x20, 0x00, 0xbf, 0xff, 0x40, 0xdf, 0x20, 0xbf, 0x00, 0x40, 0xff, 0xdf, 0x20, 0xbf, 0x00, 0xff, 0x40, /* 25% */
	0x26, 0xd8, 0xb2, 0x00, 0xff, 0x4d, 0xd8, 0x26, 0x00, 0xb2, 0xff, 0x4d, 0xd8, 0x26, 0xb2, 0x00, 0x4d, 0xff, 0xd8, 0x26, 0xb2, 0x00, 0xff, 0x4d, /* 30% */
	0x2c, 0xd2, 0xa6, 0x00, 0xff, 0x59, 0xd2, 0x2c, 0x00, 0xa6, 0xff, 0x59, 0xd2, 0x2c, 0xa6, 0x00, 0x59, 0xff, 0xd2, 0x2c, 0xa6, 0x00, 0xff, 0x59, /* 35% */
	0x33, 0xcc, 0x99, 0x00, 0xff, 0x66, 0xcc, 0x33, 0x00, 0x99, 0xff, 0x66, 0xcc, 0x33, 0x99, 0x00, 0x66, 0xff, 0xcc, 0x33, 0x99, 0x00, 0xff, 0x66, /* 40% */
	0x39, 0xc5, 0x8c, 0x00, 0xff, 0x73, 0xc5, 0x39, 0x00, 0x8c, 0xff, 0x73, 0xc5, 0x39, 0x8c, 0x00, 0x73, 0xff, 0xc5, 0x39, 0x8c, 0x00, 0xff, 0x73, /* 45% */
	0x40, 0xbf, 0x7f, 0x00, 0xff, 0x80, 0xbf, 0x40, 0x00, 0x7f, 0xff, 0x80, 0xbf, 0x40, 0x7f, 0x00, 0x80, 0xff, 0xbf, 0x40, 0x7f, 0x00, 0xff, 0x80, /* 50% */
	0x46, 0xb9, 0x73, 0x00, 0xff, 0x8c, 0xb9, 0x46, 0x00, 0x73, 0xff, 0x8c, 0xb9, 0x46, 0x73, 0x00, 0x8c, 0xff, 0xb9, 0x46, 0x73, 0x00, 0xff, 0x8c, /* 55% */
	0x4c, 0xb2, 0x66, 0x00, 0xff, 0x99, 0xb2, 0x4c, 0x00, 0x66, 0xff, 0x99, 0xb2, 0x4c, 0x66, 0x00, 0x99, 0xff, 0xb2, 0x4c, 0x66, 0x00, 0xff, 0x99, /* 60% */
};

static char DSI0_BYPASS_MDNIE_1[] = {
	//start
	0xDF,
	0x00, //linear_on ascr_skin_on 0000 0000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xff, //ascr_skin_Rr
	0x00, //ascr_skin_Rg
	0x00, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xff, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xff, //ascr_Wg
	0x00, //ascr_Kg
	0xff, //ascr_Wb
	0x00, //ascr_Kb
};

static char DSI0_BYPASS_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x00, //slce_on cadrx_en 0000 0000
	0x00, //lce_gain 000 0000
	0x30, //lce_color_gain 00 0000
	0x01, //lce_min_ref_offset
	0x00,
	0x70, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x34,
	0x01, //lce_ref_gain 9
	0x40,
	0x66, //lce_block_size h v 0000 0000
	0x03, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x11, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x20,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x00, //lce_lg_flicker Avg pixel_cnt 000
	0x0a, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x00, //lce_lg_mix_weight 7
	0x10, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0x40,
	0x00, //cadrx_ui_illum_offset2
	0x50,
	0x00, //cadrx_ui_illum_offset3
	0x60,
	0x00, //cadrx_ui_illum_offset4
	0x70,
	0x00, //cadrx_ui_illum_slope1
	0x80,
	0x00, //cadrx_ui_illum_slope2
	0x80,
	0x00, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x40,
	0x01, //cadrx_ui_ref_offset2
	0x80,
	0x01, //cadrx_ui_ref_offset3
	0x80,
	0x01, //cadrx_ui_ref_offset4
	0x80,
	0x02, //cadrx_ui_ref_slope1
	0x00,
	0x00, //cadrx_ui_ref_slope2
	0x00,
	0x00, //cadrx_ui_ref_slope3
	0x00,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x00, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0xe6, //pos_bi_min
	0xff, //pos_bi_max
	0x00, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x02, //de_maxplus 11
	0x00,
	0x02, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x10,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x08, //curve_y_1
	0x10, //curve_y_2
	0x18, //curve_y_3
	0x20, //curve_y_4
	0x28, //curve_y_5
	0x30, //curve_y_6
	0x38, //curve_y_7
	0x40, //curve_y_8
	0x48, //curve_y_9
	0x50, //curve_y_10
	0x58, //curve_y_11
	0x60, //curve_y_12
	0x68, //curve_y_13
	0x70, //curve_y_14
	0x78, //curve_y_15
	0x80, //curve_y_16
	0x88, //curve_y_17
	0x90, //curve_y_18
	0x98, //curve_y_19
	0xa0, //curve_y_20
	0xa8, //curve_y_21
	0xb0, //curve_y_22
	0xb8, //curve_y_23
	0xc0, //curve_y_24
	0xc8, //curve_y_25
	0xd0, //curve_y_26
	0xd8, //curve_y_27
	0xe0, //curve_y_28
	0xe8, //curve_y_29
	0xf0, //curve_y_30
	0xf8, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static char DSI0_BYPASS_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0x00, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0x00, //trans_on trans_block 0 000 0000
	0x00, //trans_slope
	0x00, //trans_interval
	//end
};

static char DSI0_NEGATIVE_MDNIE_1[] = {
	//start
	0xDF,
	0x01, //linear_on ascr_skin_on 0000 0000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xff, //ascr_skin_Rr
	0x00, //ascr_skin_Rg
	0x00, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0x00, //ascr_skin_Wr
	0x00, //ascr_skin_Wg
	0x00, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xff, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0x00, //ascr_Wr
	0xff, //ascr_Kr
	0x00, //ascr_Wg
	0xff, //ascr_Kg
	0x00, //ascr_Wb
	0xff, //ascr_Kb
};

static char DSI0_NEGATIVE_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x00, //slce_on cadrx_en 0000 0000
	0x00, //lce_gain 000 0000
	0x30, //lce_color_gain 00 0000
	0x01, //lce_min_ref_offset
	0x00,
	0x70, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x34,
	0x01, //lce_ref_gain 9
	0x40,
	0x66, //lce_block_size h v 0000 0000
	0x03, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x11, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x20,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x00, //lce_lg_flicker Avg pixel_cnt 000
	0x0a, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x00, //lce_lg_mix_weight 7
	0x10, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0x40,
	0x00, //cadrx_ui_illum_offset2
	0x50,
	0x00, //cadrx_ui_illum_offset3
	0x60,
	0x00, //cadrx_ui_illum_offset4
	0x70,
	0x00, //cadrx_ui_illum_slope1
	0x80,
	0x00, //cadrx_ui_illum_slope2
	0x80,
	0x00, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x40,
	0x01, //cadrx_ui_ref_offset2
	0x80,
	0x01, //cadrx_ui_ref_offset3
	0x80,
	0x01, //cadrx_ui_ref_offset4
	0x80,
	0x02, //cadrx_ui_ref_slope1
	0x00,
	0x00, //cadrx_ui_ref_slope2
	0x00,
	0x00, //cadrx_ui_ref_slope3
	0x00,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x00, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0xe6, //pos_bi_min
	0xff, //pos_bi_max
	0x00, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x02, //de_maxplus 11
	0x00,
	0x02, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x10,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x08, //curve_y_1
	0x10, //curve_y_2
	0x18, //curve_y_3
	0x20, //curve_y_4
	0x28, //curve_y_5
	0x30, //curve_y_6
	0x38, //curve_y_7
	0x40, //curve_y_8
	0x48, //curve_y_9
	0x50, //curve_y_10
	0x58, //curve_y_11
	0x60, //curve_y_12
	0x68, //curve_y_13
	0x70, //curve_y_14
	0x78, //curve_y_15
	0x80, //curve_y_16
	0x88, //curve_y_17
	0x90, //curve_y_18
	0x98, //curve_y_19
	0xa0, //curve_y_20
	0xa8, //curve_y_21
	0xb0, //curve_y_22
	0xb8, //curve_y_23
	0xc0, //curve_y_24
	0xc8, //curve_y_25
	0xd0, //curve_y_26
	0xd8, //curve_y_27
	0xe0, //curve_y_28
	0xe8, //curve_y_29
	0xf0, //curve_y_30
	0xf8, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static char DSI0_NEGATIVE_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0xf0, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0xff, //trans_on trans_block 0 000 0000
	0x04, //trans_slope
	0x01, //trans_interval
	//end
};

static char DSI0_GRAYSCALE_MDNIE_1[] = {
	//start
	0xDF,
	0x01, //linear_on ascr_skin_on 0000 0000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0x4c, //ascr_skin_Rr
	0x4c, //ascr_skin_Rg
	0x4c, //ascr_skin_Rb
	0xe2, //ascr_skin_Yr
	0xe2, //ascr_skin_Yg
	0xe2, //ascr_skin_Yb
	0x69, //ascr_skin_Mr
	0x69, //ascr_skin_Mg
	0x69, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0xb3, //ascr_Cr
	0x4c, //ascr_Rr
	0xb3, //ascr_Cg
	0x4c, //ascr_Rg
	0xb3, //ascr_Cb
	0x4c, //ascr_Rb
	0x69, //ascr_Mr
	0x96, //ascr_Gr
	0x69, //ascr_Mg
	0x96, //ascr_Gg
	0x69, //ascr_Mb
	0x96, //ascr_Gb
	0xe2, //ascr_Yr
	0x1d, //ascr_Br
	0xe2, //ascr_Yg
	0x1d, //ascr_Bg
	0xe2, //ascr_Yb
	0x1d, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xff, //ascr_Wg
	0x00, //ascr_Kg
	0xff, //ascr_Wb
	0x00, //ascr_Kb
};

static char DSI0_GRAYSCALE_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x00, //slce_on cadrx_en 0000 0000
	0x00, //lce_gain 000 0000
	0x30, //lce_color_gain 00 0000
	0x01, //lce_min_ref_offset
	0x00,
	0x70, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x34,
	0x01, //lce_ref_gain 9
	0x40,
	0x66, //lce_block_size h v 0000 0000
	0x03, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x11, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x20,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x00, //lce_lg_flicker Avg pixel_cnt 000
	0x0a, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x00, //lce_lg_mix_weight 7
	0x10, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0x40,
	0x00, //cadrx_ui_illum_offset2
	0x50,
	0x00, //cadrx_ui_illum_offset3
	0x60,
	0x00, //cadrx_ui_illum_offset4
	0x70,
	0x00, //cadrx_ui_illum_slope1
	0x80,
	0x00, //cadrx_ui_illum_slope2
	0x80,
	0x00, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x40,
	0x01, //cadrx_ui_ref_offset2
	0x80,
	0x01, //cadrx_ui_ref_offset3
	0x80,
	0x01, //cadrx_ui_ref_offset4
	0x80,
	0x02, //cadrx_ui_ref_slope1
	0x00,
	0x00, //cadrx_ui_ref_slope2
	0x00,
	0x00, //cadrx_ui_ref_slope3
	0x00,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x00, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0xe6, //pos_bi_min
	0xff, //pos_bi_max
	0x00, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x02, //de_maxplus 11
	0x00,
	0x02, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x10,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x08, //curve_y_1
	0x10, //curve_y_2
	0x18, //curve_y_3
	0x20, //curve_y_4
	0x28, //curve_y_5
	0x30, //curve_y_6
	0x38, //curve_y_7
	0x40, //curve_y_8
	0x48, //curve_y_9
	0x50, //curve_y_10
	0x58, //curve_y_11
	0x60, //curve_y_12
	0x68, //curve_y_13
	0x70, //curve_y_14
	0x78, //curve_y_15
	0x80, //curve_y_16
	0x88, //curve_y_17
	0x90, //curve_y_18
	0x98, //curve_y_19
	0xa0, //curve_y_20
	0xa8, //curve_y_21
	0xb0, //curve_y_22
	0xb8, //curve_y_23
	0xc0, //curve_y_24
	0xc8, //curve_y_25
	0xd0, //curve_y_26
	0xd8, //curve_y_27
	0xe0, //curve_y_28
	0xe8, //curve_y_29
	0xf0, //curve_y_30
	0xf8, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static char DSI0_GRAYSCALE_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0xf0, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0xff, //trans_on trans_block 0 000 0000
	0x04, //trans_slope
	0x01, //trans_interval
	//end
};

static char DSI0_GRAYSCALE_NEGATIVE_MDNIE_1[] = {
	//start
	0xDF,
	0x01, //linear_on ascr_skin_on 0000 0000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0x4c, //ascr_skin_Rr
	0x4c, //ascr_skin_Rg
	0x4c, //ascr_skin_Rb
	0xe2, //ascr_skin_Yr
	0xe2, //ascr_skin_Yg
	0xe2, //ascr_skin_Yb
	0x69, //ascr_skin_Mr
	0x69, //ascr_skin_Mg
	0x69, //ascr_skin_Mb
	0x00, //ascr_skin_Wr
	0x00, //ascr_skin_Wg
	0x00, //ascr_skin_Wb
	0xb3, //ascr_Cr
	0x4c, //ascr_Rr
	0xb3, //ascr_Cg
	0x4c, //ascr_Rg
	0xb3, //ascr_Cb
	0x4c, //ascr_Rb
	0x69, //ascr_Mr
	0x96, //ascr_Gr
	0x69, //ascr_Mg
	0x96, //ascr_Gg
	0x69, //ascr_Mb
	0x96, //ascr_Gb
	0xe2, //ascr_Yr
	0x1d, //ascr_Br
	0xe2, //ascr_Yg
	0x1d, //ascr_Bg
	0xe2, //ascr_Yb
	0x1d, //ascr_Bb
	0x00, //ascr_Wr
	0xff, //ascr_Kr
	0x00, //ascr_Wg
	0xff, //ascr_Kg
	0x00, //ascr_Wb
	0xff, //ascr_Kb
};

static char DSI0_GRAYSCALE_NEGATIVE_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x00, //slce_on cadrx_en 0000 0000
	0x00, //lce_gain 000 0000
	0x30, //lce_color_gain 00 0000
	0x01, //lce_min_ref_offset
	0x00,
	0x70, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x34,
	0x01, //lce_ref_gain 9
	0x40,
	0x66, //lce_block_size h v 0000 0000
	0x03, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x11, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x20,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x00, //lce_lg_flicker Avg pixel_cnt 000
	0x0a, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x00, //lce_lg_mix_weight 7
	0x10, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0x40,
	0x00, //cadrx_ui_illum_offset2
	0x50,
	0x00, //cadrx_ui_illum_offset3
	0x60,
	0x00, //cadrx_ui_illum_offset4
	0x70,
	0x00, //cadrx_ui_illum_slope1
	0x80,
	0x00, //cadrx_ui_illum_slope2
	0x80,
	0x00, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x40,
	0x01, //cadrx_ui_ref_offset2
	0x80,
	0x01, //cadrx_ui_ref_offset3
	0x80,
	0x01, //cadrx_ui_ref_offset4
	0x80,
	0x02, //cadrx_ui_ref_slope1
	0x00,
	0x00, //cadrx_ui_ref_slope2
	0x00,
	0x00, //cadrx_ui_ref_slope3
	0x00,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x00, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0xe6, //pos_bi_min
	0xff, //pos_bi_max
	0x00, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x02, //de_maxplus 11
	0x00,
	0x02, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x10,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x08, //curve_y_1
	0x10, //curve_y_2
	0x18, //curve_y_3
	0x20, //curve_y_4
	0x28, //curve_y_5
	0x30, //curve_y_6
	0x38, //curve_y_7
	0x40, //curve_y_8
	0x48, //curve_y_9
	0x50, //curve_y_10
	0x58, //curve_y_11
	0x60, //curve_y_12
	0x68, //curve_y_13
	0x70, //curve_y_14
	0x78, //curve_y_15
	0x80, //curve_y_16
	0x88, //curve_y_17
	0x90, //curve_y_18
	0x98, //curve_y_19
	0xa0, //curve_y_20
	0xa8, //curve_y_21
	0xb0, //curve_y_22
	0xb8, //curve_y_23
	0xc0, //curve_y_24
	0xc8, //curve_y_25
	0xd0, //curve_y_26
	0xd8, //curve_y_27
	0xe0, //curve_y_28
	0xe8, //curve_y_29
	0xf0, //curve_y_30
	0xf8, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static char DSI0_GRAYSCALE_NEGATIVE_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0xf0, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0xff, //trans_on trans_block 0 000 0000
	0x04, //trans_slope
	0x01, //trans_interval
	//end
};

static char DSI0_COLOR_BLIND_MDNIE_1[] = {
	//start
	0xDF,
	0x00, //linear_on ascr_skin_on 0000 0000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xff, //ascr_skin_Rr
	0x00, //ascr_skin_Rg
	0x00, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xff, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xff, //ascr_Wg
	0x00, //ascr_Kg
	0xff, //ascr_Wb
	0x00, //ascr_Kb
};

static char DSI0_COLOR_BLIND_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x00, //slce_on cadrx_en 0000 0000
	0x00, //lce_gain 000 0000
	0x30, //lce_color_gain 00 0000
	0x01, //lce_min_ref_offset
	0x00,
	0x70, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x34,
	0x01, //lce_ref_gain 9
	0x40,
	0x66, //lce_block_size h v 0000 0000
	0x03, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x11, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x20,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x00, //lce_lg_flicker Avg pixel_cnt 000
	0x0a, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x00, //lce_lg_mix_weight 7
	0x10, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0x40,
	0x00, //cadrx_ui_illum_offset2
	0x50,
	0x00, //cadrx_ui_illum_offset3
	0x60,
	0x00, //cadrx_ui_illum_offset4
	0x70,
	0x00, //cadrx_ui_illum_slope1
	0x80,
	0x00, //cadrx_ui_illum_slope2
	0x80,
	0x00, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x40,
	0x01, //cadrx_ui_ref_offset2
	0x80,
	0x01, //cadrx_ui_ref_offset3
	0x80,
	0x01, //cadrx_ui_ref_offset4
	0x80,
	0x02, //cadrx_ui_ref_slope1
	0x00,
	0x00, //cadrx_ui_ref_slope2
	0x00,
	0x00, //cadrx_ui_ref_slope3
	0x00,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x00, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0xe6, //pos_bi_min
	0xff, //pos_bi_max
	0x00, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x02, //de_maxplus 11
	0x00,
	0x02, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x10,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x08, //curve_y_1
	0x10, //curve_y_2
	0x18, //curve_y_3
	0x20, //curve_y_4
	0x28, //curve_y_5
	0x30, //curve_y_6
	0x38, //curve_y_7
	0x40, //curve_y_8
	0x48, //curve_y_9
	0x50, //curve_y_10
	0x58, //curve_y_11
	0x60, //curve_y_12
	0x68, //curve_y_13
	0x70, //curve_y_14
	0x78, //curve_y_15
	0x80, //curve_y_16
	0x88, //curve_y_17
	0x90, //curve_y_18
	0x98, //curve_y_19
	0xa0, //curve_y_20
	0xa8, //curve_y_21
	0xb0, //curve_y_22
	0xb8, //curve_y_23
	0xc0, //curve_y_24
	0xc8, //curve_y_25
	0xd0, //curve_y_26
	0xd8, //curve_y_27
	0xe0, //curve_y_28
	0xe8, //curve_y_29
	0xf0, //curve_y_30
	0xf8, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static char DSI0_COLOR_BLIND_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0xf0, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0xff, //trans_on trans_block 0 000 0000
	0x04, //trans_slope
	0x01, //trans_interval
	//end
};

static char DSI0_NIGHT_MODE_MDNIE_1[] = {
	//start
	0xDF,
	0x00, //linear_on ascr_skin_on 0000 0000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xff, //ascr_skin_Rr
	0x00, //ascr_skin_Rg
	0x00, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xff, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xff, //ascr_Wg
	0x00, //ascr_Kg
	0xff, //ascr_Wb
	0x00, //ascr_Kb
};

static char DSI0_NIGHT_MODE_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x00, //slce_on cadrx_en 0000 0000
	0x00, //lce_gain 000 0000
	0x30, //lce_color_gain 00 0000
	0x01, //lce_min_ref_offset
	0x00,
	0x70, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x34,
	0x01, //lce_ref_gain 9
	0x40,
	0x66, //lce_block_size h v 0000 0000
	0x03, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x11, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x20,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x00, //lce_lg_flicker Avg pixel_cnt 000
	0x0a, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x00, //lce_lg_mix_weight 7
	0x10, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0x40,
	0x00, //cadrx_ui_illum_offset2
	0x50,
	0x00, //cadrx_ui_illum_offset3
	0x60,
	0x00, //cadrx_ui_illum_offset4
	0x70,
	0x00, //cadrx_ui_illum_slope1
	0x80,
	0x00, //cadrx_ui_illum_slope2
	0x80,
	0x00, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x40,
	0x01, //cadrx_ui_ref_offset2
	0x80,
	0x01, //cadrx_ui_ref_offset3
	0x80,
	0x01, //cadrx_ui_ref_offset4
	0x80,
	0x02, //cadrx_ui_ref_slope1
	0x00,
	0x00, //cadrx_ui_ref_slope2
	0x00,
	0x00, //cadrx_ui_ref_slope3
	0x00,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x00, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0xe6, //pos_bi_min
	0xff, //pos_bi_max
	0x00, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x02, //de_maxplus 11
	0x00,
	0x02, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x10,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x08, //curve_y_1
	0x10, //curve_y_2
	0x18, //curve_y_3
	0x20, //curve_y_4
	0x28, //curve_y_5
	0x30, //curve_y_6
	0x38, //curve_y_7
	0x40, //curve_y_8
	0x48, //curve_y_9
	0x50, //curve_y_10
	0x58, //curve_y_11
	0x60, //curve_y_12
	0x68, //curve_y_13
	0x70, //curve_y_14
	0x78, //curve_y_15
	0x80, //curve_y_16
	0x88, //curve_y_17
	0x90, //curve_y_18
	0x98, //curve_y_19
	0xa0, //curve_y_20
	0xa8, //curve_y_21
	0xb0, //curve_y_22
	0xb8, //curve_y_23
	0xc0, //curve_y_24
	0xc8, //curve_y_25
	0xd0, //curve_y_26
	0xd8, //curve_y_27
	0xe0, //curve_y_28
	0xe8, //curve_y_29
	0xf0, //curve_y_30
	0xf8, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static char DSI0_NIGHT_MODE_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0xf0, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0xff, //trans_on trans_block 0 000 0000
	0x04, //trans_slope
	0x01, //trans_interval
	//end
};

static char DSI0_COLOR_LENS_MDNIE_1[] = {
	//start
	0xDF,
	0x00, //linear_on ascr_skin_on 0000 0000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xff, //ascr_skin_Rr
	0x00, //ascr_skin_Rg
	0x00, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xff, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xff, //ascr_Wg
	0x00, //ascr_Kg
	0xff, //ascr_Wb
	0x00, //ascr_Kb
};

static char DSI0_COLOR_LENS_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x00, //slce_on cadrx_en 0000 0000
	0x00, //lce_gain 000 0000
	0x30, //lce_color_gain 00 0000
	0x01, //lce_min_ref_offset
	0x00,
	0x70, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x34,
	0x01, //lce_ref_gain 9
	0x40,
	0x66, //lce_block_size h v 0000 0000
	0x03, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x11, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x20,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x00, //lce_lg_flicker Avg pixel_cnt 000
	0x0a, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x00, //lce_lg_mix_weight 7
	0x10, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0x40,
	0x00, //cadrx_ui_illum_offset2
	0x50,
	0x00, //cadrx_ui_illum_offset3
	0x60,
	0x00, //cadrx_ui_illum_offset4
	0x70,
	0x00, //cadrx_ui_illum_slope1
	0x80,
	0x00, //cadrx_ui_illum_slope2
	0x80,
	0x00, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x40,
	0x01, //cadrx_ui_ref_offset2
	0x80,
	0x01, //cadrx_ui_ref_offset3
	0x80,
	0x01, //cadrx_ui_ref_offset4
	0x80,
	0x02, //cadrx_ui_ref_slope1
	0x00,
	0x00, //cadrx_ui_ref_slope2
	0x00,
	0x00, //cadrx_ui_ref_slope3
	0x00,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x00, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0xe6, //pos_bi_min
	0xff, //pos_bi_max
	0x00, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x02, //de_maxplus 11
	0x00,
	0x02, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x10,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x08, //curve_y_1
	0x10, //curve_y_2
	0x18, //curve_y_3
	0x20, //curve_y_4
	0x28, //curve_y_5
	0x30, //curve_y_6
	0x38, //curve_y_7
	0x40, //curve_y_8
	0x48, //curve_y_9
	0x50, //curve_y_10
	0x58, //curve_y_11
	0x60, //curve_y_12
	0x68, //curve_y_13
	0x70, //curve_y_14
	0x78, //curve_y_15
	0x80, //curve_y_16
	0x88, //curve_y_17
	0x90, //curve_y_18
	0x98, //curve_y_19
	0xa0, //curve_y_20
	0xa8, //curve_y_21
	0xb0, //curve_y_22
	0xb8, //curve_y_23
	0xc0, //curve_y_24
	0xc8, //curve_y_25
	0xd0, //curve_y_26
	0xd8, //curve_y_27
	0xe0, //curve_y_28
	0xe8, //curve_y_29
	0xf0, //curve_y_30
	0xf8, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static char DSI0_COLOR_LENS_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0xf0, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0xff, //trans_on trans_block 0 000 0000
	0x04, //trans_slope
	0x01, //trans_interval
	//end
};

static char DSI0_HBM_CE_MDNIE_1[] = {
	//start
	0xDF,
	0x01, //linear_on ascr_skin_on 0000 0000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xff, //ascr_skin_Rr
	0x30, //ascr_skin_Rg
	0x30, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xf0, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xff, //ascr_Wg
	0x00, //ascr_Kg
	0xff, //ascr_Wb
	0x00, //ascr_Kb
};

static char DSI0_HBM_CE_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x11, //slce_on cadrx_en 0000 0000
	0x2c, //lce_gain 000 0000
	0x20, //lce_color_gain 00 0000
	0x01, //lce_min_ref_offset
	0x00,
	0x70, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x34,
	0x01, //lce_ref_gain 9
	0x40,
	0x66, //lce_block_size h v 0000 0000
	0x03, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x11, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x26,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x06, //lce_lg_flicker Avg pixel_cnt 000
	0x00, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x20, //lce_lg_mix_weight 7
	0x10, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0x40,
	0x00, //cadrx_ui_illum_offset2
	0x50,
	0x00, //cadrx_ui_illum_offset3
	0x60,
	0x00, //cadrx_ui_illum_offset4
	0x70,
	0x00, //cadrx_ui_illum_slope1
	0x80,
	0x00, //cadrx_ui_illum_slope2
	0x80,
	0x00, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x40,
	0x01, //cadrx_ui_ref_offset2
	0x80,
	0x01, //cadrx_ui_ref_offset3
	0x80,
	0x01, //cadrx_ui_ref_offset4
	0x80,
	0x02, //cadrx_ui_ref_slope1
	0x00,
	0x00, //cadrx_ui_ref_slope2
	0x00,
	0x00, //cadrx_ui_ref_slope3
	0x00,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x40, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0x00, //pos_bi_min
	0xff, //pos_bi_max
	0x02, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x02, //de_maxplus 11
	0x00,
	0x02, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x10,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x30,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x08, //curve_y_1
	0x10, //curve_y_2
	0x18, //curve_y_3
	0x20, //curve_y_4
	0x28, //curve_y_5
	0x30, //curve_y_6
	0x38, //curve_y_7
	0x40, //curve_y_8
	0x48, //curve_y_9
	0x50, //curve_y_10
	0x58, //curve_y_11
	0x60, //curve_y_12
	0x68, //curve_y_13
	0x70, //curve_y_14
	0x78, //curve_y_15
	0x80, //curve_y_16
	0x88, //curve_y_17
	0x90, //curve_y_18
	0x98, //curve_y_19
	0xa0, //curve_y_20
	0xa8, //curve_y_21
	0xb0, //curve_y_22
	0xb8, //curve_y_23
	0xc0, //curve_y_24
	0xc8, //curve_y_25
	0xd0, //curve_y_26
	0xd8, //curve_y_27
	0xe0, //curve_y_28
	0xe8, //curve_y_29
	0xf0, //curve_y_30
	0xf8, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static char DSI0_HBM_CE_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0xfc, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0xff, //trans_on trans_block 0 000 0000
	0x08, //trans_slope
	0x01, //trans_interval
	//end
};

static char DSI0_HBM_CE_D65_MDNIE_1[] = {
	//start
	0xDF,
	0x01, //linear_on ascr_skin_on 0000 0000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xff, //ascr_skin_Rr
	0x30, //ascr_skin_Rg
	0x30, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xfc, //ascr_skin_Wg
	0xf6, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xf0, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xfc, //ascr_Wg
	0x00, //ascr_Kg
	0xf6, //ascr_Wb
	0x00, //ascr_Kb
};

static char DSI0_HBM_CE_D65_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x11, //slce_on cadrx_en 0000 0000
	0x2c, //lce_gain 000 0000
	0x20, //lce_color_gain 00 0000
	0x01, //lce_min_ref_offset
	0x00,
	0x70, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x34,
	0x01, //lce_ref_gain 9
	0x40,
	0x66, //lce_block_size h v 0000 0000
	0x03, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x11, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x26,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x06, //lce_lg_flicker Avg pixel_cnt 000
	0x00, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x20, //lce_lg_mix_weight 7
	0x10, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0x40,
	0x00, //cadrx_ui_illum_offset2
	0x50,
	0x00, //cadrx_ui_illum_offset3
	0x60,
	0x00, //cadrx_ui_illum_offset4
	0x70,
	0x00, //cadrx_ui_illum_slope1
	0x80,
	0x00, //cadrx_ui_illum_slope2
	0x80,
	0x00, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x40,
	0x01, //cadrx_ui_ref_offset2
	0x80,
	0x01, //cadrx_ui_ref_offset3
	0x80,
	0x01, //cadrx_ui_ref_offset4
	0x80,
	0x02, //cadrx_ui_ref_slope1
	0x00,
	0x00, //cadrx_ui_ref_slope2
	0x00,
	0x00, //cadrx_ui_ref_slope3
	0x00,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x40, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0x00, //pos_bi_min
	0xff, //pos_bi_max
	0x02, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x02, //de_maxplus 11
	0x00,
	0x02, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x10,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x30,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x08, //curve_y_1
	0x10, //curve_y_2
	0x18, //curve_y_3
	0x20, //curve_y_4
	0x28, //curve_y_5
	0x30, //curve_y_6
	0x38, //curve_y_7
	0x40, //curve_y_8
	0x48, //curve_y_9
	0x50, //curve_y_10
	0x58, //curve_y_11
	0x60, //curve_y_12
	0x68, //curve_y_13
	0x70, //curve_y_14
	0x78, //curve_y_15
	0x80, //curve_y_16
	0x88, //curve_y_17
	0x90, //curve_y_18
	0x98, //curve_y_19
	0xa0, //curve_y_20
	0xa8, //curve_y_21
	0xb0, //curve_y_22
	0xb8, //curve_y_23
	0xc0, //curve_y_24
	0xc8, //curve_y_25
	0xd0, //curve_y_26
	0xd8, //curve_y_27
	0xe0, //curve_y_28
	0xe8, //curve_y_29
	0xf0, //curve_y_30
	0xf8, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static char DSI0_HBM_CE_D65_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0xfc, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0xff, //trans_on trans_block 0 000 0000
	0x08, //trans_slope
	0x01, //trans_interval
	//end
};

static char DSI0_RGB_SENSOR_MDNIE_1[] = {
	//start
	0xDF,
	0x00, //linear_on ascr_skin_on 0000 0000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xff, //ascr_skin_Rr
	0x00, //ascr_skin_Rg
	0x00, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xff, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xff, //ascr_Wg
	0x00, //ascr_Kg
	0xff, //ascr_Wb
	0x00, //ascr_Kb
};

static char DSI0_RGB_SENSOR_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x00, //slce_on cadrx_en 0000 0000
	0x00, //lce_gain 000 0000
	0x30, //lce_color_gain 00 0000
	0x01, //lce_min_ref_offset
	0x00,
	0x70, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x34,
	0x01, //lce_ref_gain 9
	0x40,
	0x66, //lce_block_size h v 0000 0000
	0x03, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x11, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x20,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x00, //lce_lg_flicker Avg pixel_cnt 000
	0x0a, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x00, //lce_lg_mix_weight 7
	0x10, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0x40,
	0x00, //cadrx_ui_illum_offset2
	0x50,
	0x00, //cadrx_ui_illum_offset3
	0x60,
	0x00, //cadrx_ui_illum_offset4
	0x70,
	0x00, //cadrx_ui_illum_slope1
	0x80,
	0x00, //cadrx_ui_illum_slope2
	0x80,
	0x00, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x40,
	0x01, //cadrx_ui_ref_offset2
	0x80,
	0x01, //cadrx_ui_ref_offset3
	0x80,
	0x01, //cadrx_ui_ref_offset4
	0x80,
	0x02, //cadrx_ui_ref_slope1
	0x00,
	0x00, //cadrx_ui_ref_slope2
	0x00,
	0x00, //cadrx_ui_ref_slope3
	0x00,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x00, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0xe6, //pos_bi_min
	0xff, //pos_bi_max
	0x00, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x02, //de_maxplus 11
	0x00,
	0x02, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x10,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x08, //curve_y_1
	0x10, //curve_y_2
	0x18, //curve_y_3
	0x20, //curve_y_4
	0x28, //curve_y_5
	0x30, //curve_y_6
	0x38, //curve_y_7
	0x40, //curve_y_8
	0x48, //curve_y_9
	0x50, //curve_y_10
	0x58, //curve_y_11
	0x60, //curve_y_12
	0x68, //curve_y_13
	0x70, //curve_y_14
	0x78, //curve_y_15
	0x80, //curve_y_16
	0x88, //curve_y_17
	0x90, //curve_y_18
	0x98, //curve_y_19
	0xa0, //curve_y_20
	0xa8, //curve_y_21
	0xb0, //curve_y_22
	0xb8, //curve_y_23
	0xc0, //curve_y_24
	0xc8, //curve_y_25
	0xd0, //curve_y_26
	0xd8, //curve_y_27
	0xe0, //curve_y_28
	0xe8, //curve_y_29
	0xf0, //curve_y_30
	0xf8, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static char DSI0_RGB_SENSOR_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0xf0, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0xff, //trans_on trans_block 0 000 0000
	0x04, //trans_slope
	0x01, //trans_interval
	//end
};

static char DSI0_SCREEN_CURTAIN_MDNIE_1[] = {
	//start
	0xDF,
	0x01, //linear_on ascr_skin_on 0000 0000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0x00, //ascr_skin_Rr
	0x00, //ascr_skin_Rg
	0x00, //ascr_skin_Rb
	0x00, //ascr_skin_Yr
	0x00, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0x00, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0x00, //ascr_skin_Mb
	0x00, //ascr_skin_Wr
	0x00, //ascr_skin_Wg
	0x00, //ascr_skin_Wb
	0x00, //ascr_Cr
	0x00, //ascr_Rr
	0x00, //ascr_Cg
	0x00, //ascr_Rg
	0x00, //ascr_Cb
	0x00, //ascr_Rb
	0x00, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0x00, //ascr_Gg
	0x00, //ascr_Mb
	0x00, //ascr_Gb
	0x00, //ascr_Yr
	0x00, //ascr_Br
	0x00, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0x00, //ascr_Bb
	0x00, //ascr_Wr
	0x00, //ascr_Kr
	0x00, //ascr_Wg
	0x00, //ascr_Kg
	0x00, //ascr_Wb
	0x00, //ascr_Kb
};

static char DSI0_SCREEN_CURTAIN_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x00, //slce_on cadrx_en 0000 0000
	0x00, //lce_gain 000 0000
	0x30, //lce_color_gain 00 0000
	0x01, //lce_min_ref_offset
	0x00,
	0x70, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x34,
	0x01, //lce_ref_gain 9
	0x40,
	0x66, //lce_block_size h v 0000 0000
	0x03, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x11, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x20,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x00, //lce_lg_flicker Avg pixel_cnt 000
	0x0a, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x00, //lce_lg_mix_weight 7
	0x10, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0x40,
	0x00, //cadrx_ui_illum_offset2
	0x50,
	0x00, //cadrx_ui_illum_offset3
	0x60,
	0x00, //cadrx_ui_illum_offset4
	0x70,
	0x00, //cadrx_ui_illum_slope1
	0x80,
	0x00, //cadrx_ui_illum_slope2
	0x80,
	0x00, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x40,
	0x01, //cadrx_ui_ref_offset2
	0x80,
	0x01, //cadrx_ui_ref_offset3
	0x80,
	0x01, //cadrx_ui_ref_offset4
	0x80,
	0x02, //cadrx_ui_ref_slope1
	0x00,
	0x00, //cadrx_ui_ref_slope2
	0x00,
	0x00, //cadrx_ui_ref_slope3
	0x00,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x00, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0xe6, //pos_bi_min
	0xff, //pos_bi_max
	0x00, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x02, //de_maxplus 11
	0x00,
	0x02, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x10,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x08, //curve_y_1
	0x10, //curve_y_2
	0x18, //curve_y_3
	0x20, //curve_y_4
	0x28, //curve_y_5
	0x30, //curve_y_6
	0x38, //curve_y_7
	0x40, //curve_y_8
	0x48, //curve_y_9
	0x50, //curve_y_10
	0x58, //curve_y_11
	0x60, //curve_y_12
	0x68, //curve_y_13
	0x70, //curve_y_14
	0x78, //curve_y_15
	0x80, //curve_y_16
	0x88, //curve_y_17
	0x90, //curve_y_18
	0x98, //curve_y_19
	0xa0, //curve_y_20
	0xa8, //curve_y_21
	0xb0, //curve_y_22
	0xb8, //curve_y_23
	0xc0, //curve_y_24
	0xc8, //curve_y_25
	0xd0, //curve_y_26
	0xd8, //curve_y_27
	0xe0, //curve_y_28
	0xe8, //curve_y_29
	0xf0, //curve_y_30
	0xf8, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static char DSI0_SCREEN_CURTAIN_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0xf0, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0xff, //trans_on trans_block 0 000 0000
	0x04, //trans_slope
	0x01, //trans_interval
	//end
};

static char DSI0_LIGHT_NOTIFICATION_MDNIE_1[] = {
	//start
	0xDF,
	0x01, //linear_on ascr_skin_on 0000 0000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xff, //ascr_skin_Rr
	0x60, //ascr_skin_Rg
	0x13, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xf9, //ascr_skin_Yg
	0x13, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x60, //ascr_skin_Mg
	0xac, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xf9, //ascr_skin_Wg
	0xac, //ascr_skin_Wb
	0x66, //ascr_Cr
	0xff, //ascr_Rr
	0xf9, //ascr_Cg
	0x60, //ascr_Rg
	0xac, //ascr_Cb
	0x13, //ascr_Rb
	0xff, //ascr_Mr
	0x66, //ascr_Gr
	0x60, //ascr_Mg
	0xf9, //ascr_Gg
	0xac, //ascr_Mb
	0x13, //ascr_Gb
	0xff, //ascr_Yr
	0x66, //ascr_Br
	0xf9, //ascr_Yg
	0x60, //ascr_Bg
	0x13, //ascr_Yb
	0xac, //ascr_Bb
	0xff, //ascr_Wr
	0x66, //ascr_Kr
	0xf9, //ascr_Wg
	0x60, //ascr_Kg
	0xac, //ascr_Wb
	0x13, //ascr_Kb
};

static char DSI0_LIGHT_NOTIFICATION_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x00, //slce_on cadrx_en 0000 0000
	0x00, //lce_gain 000 0000
	0x30, //lce_color_gain 00 0000
	0x01, //lce_min_ref_offset
	0x00,
	0x70, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x34,
	0x01, //lce_ref_gain 9
	0x40,
	0x66, //lce_block_size h v 0000 0000
	0x03, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x11, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x20,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x00, //lce_lg_flicker Avg pixel_cnt 000
	0x0a, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x00, //lce_lg_mix_weight 7
	0x10, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0x40,
	0x00, //cadrx_ui_illum_offset2
	0x50,
	0x00, //cadrx_ui_illum_offset3
	0x60,
	0x00, //cadrx_ui_illum_offset4
	0x70,
	0x00, //cadrx_ui_illum_slope1
	0x80,
	0x00, //cadrx_ui_illum_slope2
	0x80,
	0x00, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x40,
	0x01, //cadrx_ui_ref_offset2
	0x80,
	0x01, //cadrx_ui_ref_offset3
	0x80,
	0x01, //cadrx_ui_ref_offset4
	0x80,
	0x02, //cadrx_ui_ref_slope1
	0x00,
	0x00, //cadrx_ui_ref_slope2
	0x00,
	0x00, //cadrx_ui_ref_slope3
	0x00,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x00, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0xe6, //pos_bi_min
	0xff, //pos_bi_max
	0x00, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x02, //de_maxplus 11
	0x00,
	0x02, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x10,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x08, //curve_y_1
	0x10, //curve_y_2
	0x18, //curve_y_3
	0x20, //curve_y_4
	0x28, //curve_y_5
	0x30, //curve_y_6
	0x38, //curve_y_7
	0x40, //curve_y_8
	0x48, //curve_y_9
	0x50, //curve_y_10
	0x58, //curve_y_11
	0x60, //curve_y_12
	0x68, //curve_y_13
	0x70, //curve_y_14
	0x78, //curve_y_15
	0x80, //curve_y_16
	0x88, //curve_y_17
	0x90, //curve_y_18
	0x98, //curve_y_19
	0xa0, //curve_y_20
	0xa8, //curve_y_21
	0xb0, //curve_y_22
	0xb8, //curve_y_23
	0xc0, //curve_y_24
	0xc8, //curve_y_25
	0xd0, //curve_y_26
	0xd8, //curve_y_27
	0xe0, //curve_y_28
	0xe8, //curve_y_29
	0xf0, //curve_y_30
	0xf8, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static char DSI0_LIGHT_NOTIFICATION_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0xf0, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0xff, //trans_on trans_block 0 000 0000
	0x04, //trans_slope
	0x01, //trans_interval
	//end
};

static unsigned char DSI0_HDR_VIDEO_1_MDNIE_1[] = {
	//start
	0xDF,
	0x01, //linear_on ascr_skin_on 0000 0000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xff, //ascr_skin_Rr
	0x30, //ascr_skin_Rg
	0x30, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xf7, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xfc, //ascr_skin_Wg
	0xf5, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xff, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xfc, //ascr_Wg
	0x00, //ascr_Kg
	0xf5, //ascr_Wb
	0x00, //ascr_Kb
};

static unsigned char DSI0_HDR_VIDEO_1_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x00, //slce_on cadrx_en 0000 0000
	0x00, //lce_gain 000 0000
	0x30, //lce_color_gain 00 0000
	0x01, //lce_min_ref_offset
	0x00,
	0x70, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x34,
	0x01, //lce_ref_gain 9
	0x40,
	0x66, //lce_block_size h v 0000 0000
	0x03, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x11, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x20,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x00, //lce_lg_flicker Avg pixel_cnt 000
	0x0a, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x00, //lce_lg_mix_weight 7
	0x10, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0x40,
	0x00, //cadrx_ui_illum_offset2
	0x50,
	0x00, //cadrx_ui_illum_offset3
	0x60,
	0x00, //cadrx_ui_illum_offset4
	0x70,
	0x00, //cadrx_ui_illum_slope1
	0x80,
	0x00, //cadrx_ui_illum_slope2
	0x80,
	0x00, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x40,
	0x01, //cadrx_ui_ref_offset2
	0x80,
	0x01, //cadrx_ui_ref_offset3
	0x80,
	0x01, //cadrx_ui_ref_offset4
	0x80,
	0x02, //cadrx_ui_ref_slope1
	0x00,
	0x00, //cadrx_ui_ref_slope2
	0x00,
	0x00, //cadrx_ui_ref_slope3
	0x00,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x00, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0xe6, //pos_bi_min
	0xff, //pos_bi_max
	0x01, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x02, //de_maxplus 11
	0x00,
	0x02, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x00,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x08, //curve_y_1
	0x10, //curve_y_2
	0x18, //curve_y_3
	0x20, //curve_y_4
	0x27, //curve_y_5
	0x2e, //curve_y_6
	0x35, //curve_y_7
	0x3d, //curve_y_8
	0x44, //curve_y_9
	0x4c, //curve_y_10
	0x55, //curve_y_11
	0x5e, //curve_y_12
	0x66, //curve_y_13
	0x6e, //curve_y_14
	0x76, //curve_y_15
	0x7e, //curve_y_16
	0x86, //curve_y_17
	0x8e, //curve_y_18
	0x95, //curve_y_19
	0x9c, //curve_y_20
	0xa3, //curve_y_21
	0xab, //curve_y_22
	0xb3, //curve_y_23
	0xbb, //curve_y_24
	0xc3, //curve_y_25
	0xcb, //curve_y_26
	0xd3, //curve_y_27
	0xdb, //curve_y_28
	0xe4, //curve_y_29
	0xed, //curve_y_30
	0xf6, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static unsigned char DSI0_HDR_VIDEO_1_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0xf0, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0xff, //trans_on trans_block 0 000 0000
	0x04, //trans_slope
	0x01, //trans_interval
	//end
};

static unsigned char DSI0_HDR_VIDEO_2_MDNIE_1[] = {
	//start
	0xDF,
	0x01, //linear_on ascr_skin_on 0000 0000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xff, //ascr_skin_Rr
	0x30, //ascr_skin_Rg
	0x30, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xf7, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xfc, //ascr_skin_Wg
	0xf5, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xff, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xfc, //ascr_Wg
	0x00, //ascr_Kg
	0xf5, //ascr_Wb
	0x00, //ascr_Kb
};

static unsigned char DSI0_HDR_VIDEO_2_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x00, //slce_on cadrx_en 0000 0000
	0x00, //lce_gain 000 0000
	0x30, //lce_color_gain 00 0000
	0x01, //lce_min_ref_offset
	0x00,
	0x70, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x34,
	0x01, //lce_ref_gain 9
	0x40,
	0x66, //lce_block_size h v 0000 0000
	0x03, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x11, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x20,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x00, //lce_lg_flicker Avg pixel_cnt 000
	0x0a, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x00, //lce_lg_mix_weight 7
	0x10, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0x40,
	0x00, //cadrx_ui_illum_offset2
	0x50,
	0x00, //cadrx_ui_illum_offset3
	0x60,
	0x00, //cadrx_ui_illum_offset4
	0x70,
	0x00, //cadrx_ui_illum_slope1
	0x80,
	0x00, //cadrx_ui_illum_slope2
	0x80,
	0x00, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x40,
	0x01, //cadrx_ui_ref_offset2
	0x80,
	0x01, //cadrx_ui_ref_offset3
	0x80,
	0x01, //cadrx_ui_ref_offset4
	0x80,
	0x02, //cadrx_ui_ref_slope1
	0x00,
	0x00, //cadrx_ui_ref_slope2
	0x00,
	0x00, //cadrx_ui_ref_slope3
	0x00,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x00, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0xe6, //pos_bi_min
	0xff, //pos_bi_max
	0x01, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x02, //de_maxplus 11
	0x00,
	0x02, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x00,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x08, //curve_y_1
	0x10, //curve_y_2
	0x18, //curve_y_3
	0x20, //curve_y_4
	0x27, //curve_y_5
	0x2e, //curve_y_6
	0x35, //curve_y_7
	0x3d, //curve_y_8
	0x44, //curve_y_9
	0x4c, //curve_y_10
	0x55, //curve_y_11
	0x5e, //curve_y_12
	0x66, //curve_y_13
	0x6e, //curve_y_14
	0x76, //curve_y_15
	0x7e, //curve_y_16
	0x86, //curve_y_17
	0x8e, //curve_y_18
	0x95, //curve_y_19
	0x9c, //curve_y_20
	0xa3, //curve_y_21
	0xab, //curve_y_22
	0xb3, //curve_y_23
	0xbb, //curve_y_24
	0xc3, //curve_y_25
	0xcb, //curve_y_26
	0xd3, //curve_y_27
	0xdb, //curve_y_28
	0xe4, //curve_y_29
	0xed, //curve_y_30
	0xf6, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static unsigned char DSI0_HDR_VIDEO_2_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0xf0, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0xff, //trans_on trans_block 0 000 0000
	0x04, //trans_slope
	0x01, //trans_interval
	//end
};

static unsigned char DSI0_HDR_VIDEO_3_MDNIE_1[] = {
	//start
	0xDF,
	0x00, //linear_on ascr_skin_on 0000 0000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xff, //ascr_skin_Rr
	0x00, //ascr_skin_Rg
	0x00, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xff, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xff, //ascr_Wg
	0x00, //ascr_Kg
	0xff, //ascr_Wb
	0x00, //ascr_Kb
};

static unsigned char DSI0_HDR_VIDEO_3_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x00, //slce_on cadrx_en 0000 0000
	0x00, //lce_gain 000 0000
	0x30, //lce_color_gain 00 0000
	0x01, //lce_min_ref_offset
	0x00,
	0x70, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x34,
	0x01, //lce_ref_gain 9
	0x40,
	0x66, //lce_block_size h v 0000 0000
	0x03, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x11, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x20,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x00, //lce_lg_flicker Avg pixel_cnt 000
	0x0a, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x00, //lce_lg_mix_weight 7
	0x10, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0x40,
	0x00, //cadrx_ui_illum_offset2
	0x50,
	0x00, //cadrx_ui_illum_offset3
	0x60,
	0x00, //cadrx_ui_illum_offset4
	0x70,
	0x00, //cadrx_ui_illum_slope1
	0x80,
	0x00, //cadrx_ui_illum_slope2
	0x80,
	0x00, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x40,
	0x01, //cadrx_ui_ref_offset2
	0x80,
	0x01, //cadrx_ui_ref_offset3
	0x80,
	0x01, //cadrx_ui_ref_offset4
	0x80,
	0x02, //cadrx_ui_ref_slope1
	0x00,
	0x00, //cadrx_ui_ref_slope2
	0x00,
	0x00, //cadrx_ui_ref_slope3
	0x00,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x00, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0xe6, //pos_bi_min
	0xff, //pos_bi_max
	0x00, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x02, //de_maxplus 11
	0x00,
	0x02, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x10,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x08, //curve_y_1
	0x10, //curve_y_2
	0x18, //curve_y_3
	0x20, //curve_y_4
	0x28, //curve_y_5
	0x30, //curve_y_6
	0x38, //curve_y_7
	0x40, //curve_y_8
	0x48, //curve_y_9
	0x50, //curve_y_10
	0x58, //curve_y_11
	0x60, //curve_y_12
	0x68, //curve_y_13
	0x70, //curve_y_14
	0x78, //curve_y_15
	0x80, //curve_y_16
	0x88, //curve_y_17
	0x90, //curve_y_18
	0x98, //curve_y_19
	0xa0, //curve_y_20
	0xa8, //curve_y_21
	0xb0, //curve_y_22
	0xb8, //curve_y_23
	0xc0, //curve_y_24
	0xc8, //curve_y_25
	0xd0, //curve_y_26
	0xd8, //curve_y_27
	0xe0, //curve_y_28
	0xe8, //curve_y_29
	0xf0, //curve_y_30
	0xf8, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static unsigned char DSI0_HDR_VIDEO_3_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0x00, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0xff, //trans_on trans_block 0 000 0000
	0x04, //trans_slope
	0x01, //trans_interval
	//end
};

static unsigned char DSI0_HDR_VIDEO_4_MDNIE_1[] = {
	//start
	0xDF,
	0x01, //linear_on ascr_skin_on 0000 0000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x37, //ascr_dist_up
	0x29, //ascr_dist_down
	0x19, //ascr_dist_right
	0x47, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x25,
	0x3d,
	0x00, //ascr_div_down
	0x31,
	0xf4,
	0x00, //ascr_div_right
	0x51,
	0xec,
	0x00, //ascr_div_left
	0x1c,
	0xd8,
	0xd0, //ascr_skin_Rr
	0x48, //ascr_skin_Rg
	0x50, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xd0, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xa0, //ascr_Yr
	0x00, //ascr_Br
	0xff, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xf7, //ascr_Wg
	0x00, //ascr_Kg
	0xf0, //ascr_Wb
	0x00, //ascr_Kb
};

static unsigned char DSI0_HDR_VIDEO_4_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x00, //slce_on cadrx_en 0000 0000
	0x00, //lce_gain 000 0000
	0x30, //lce_color_gain 00 0000
	0x01, //lce_min_ref_offset
	0x00,
	0x70, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x34,
	0x01, //lce_ref_gain 9
	0x40,
	0x66, //lce_block_size h v 0000 0000
	0x03, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x11, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x20,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x00, //lce_lg_flicker Avg pixel_cnt 000
	0x0a, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x00, //lce_lg_mix_weight 7
	0x10, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0x40,
	0x00, //cadrx_ui_illum_offset2
	0x50,
	0x00, //cadrx_ui_illum_offset3
	0x60,
	0x00, //cadrx_ui_illum_offset4
	0x70,
	0x00, //cadrx_ui_illum_slope1
	0x80,
	0x00, //cadrx_ui_illum_slope2
	0x80,
	0x00, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x40,
	0x01, //cadrx_ui_ref_offset2
	0x80,
	0x01, //cadrx_ui_ref_offset3
	0x80,
	0x01, //cadrx_ui_ref_offset4
	0x80,
	0x02, //cadrx_ui_ref_slope1
	0x00,
	0x00, //cadrx_ui_ref_slope2
	0x00,
	0x00, //cadrx_ui_ref_slope3
	0x00,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x00, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0xe6, //pos_bi_min
	0xff, //pos_bi_max
	0x07, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x10,
	0x00, //de_maxplus 11
	0x40,
	0x00, //de_maxminus 11
	0x40,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x10,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x80,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x06, //curve_y_1
	0x0c, //curve_y_2
	0x12, //curve_y_3
	0x18, //curve_y_4
	0x1e, //curve_y_5
	0x24, //curve_y_6
	0x2c, //curve_y_7
	0x34, //curve_y_8
	0x3e, //curve_y_9
	0x47, //curve_y_10
	0x52, //curve_y_11
	0x5c, //curve_y_12
	0x67, //curve_y_13
	0x72, //curve_y_14
	0x80, //curve_y_15
	0x8e, //curve_y_16
	0x9c, //curve_y_17
	0xaa, //curve_y_18
	0xb8, //curve_y_19
	0xc6, //curve_y_20
	0xcf, //curve_y_21
	0xd7, //curve_y_22
	0xdf, //curve_y_23
	0xe6, //curve_y_24
	0xeb, //curve_y_25
	0xf0, //curve_y_26
	0xf5, //curve_y_27
	0xfa, //curve_y_28
	0xfd, //curve_y_29
	0xff, //curve_y_30
	0xff, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static unsigned char DSI0_HDR_VIDEO_4_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0xf3, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0xff, //trans_on trans_block 0 000 0000
	0x04, //trans_slope
	0x01, //trans_interval
	//end
};

static unsigned char DSI0_HDR_VIDEO_5_MDNIE_1[] = {
	//start
	0xDF,
	0x01, //linear_on ascr_skin_on 0000 0000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x37, //ascr_dist_up
	0x29, //ascr_dist_down
	0x19, //ascr_dist_right
	0x47, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x25,
	0x3d,
	0x00, //ascr_div_down
	0x31,
	0xf4,
	0x00, //ascr_div_right
	0x51,
	0xec,
	0x00, //ascr_div_left
	0x1c,
	0xd8,
	0xd0, //ascr_skin_Rr
	0x48, //ascr_skin_Rg
	0x50, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xd0, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xa0, //ascr_Yr
	0x00, //ascr_Br
	0xff, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xf7, //ascr_Wg
	0x00, //ascr_Kg
	0xf0, //ascr_Wb
	0x00, //ascr_Kb
};

static unsigned char DSI0_HDR_VIDEO_5_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x00, //slce_on cadrx_en 0000 0000
	0x00, //lce_gain 000 0000
	0x30, //lce_color_gain 00 0000
	0x01, //lce_min_ref_offset
	0x00,
	0x70, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x34,
	0x01, //lce_ref_gain 9
	0x40,
	0x66, //lce_block_size h v 0000 0000
	0x03, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x11, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x20,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x00, //lce_lg_flicker Avg pixel_cnt 000
	0x0a, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x00, //lce_lg_mix_weight 7
	0x10, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0x40,
	0x00, //cadrx_ui_illum_offset2
	0x50,
	0x00, //cadrx_ui_illum_offset3
	0x60,
	0x00, //cadrx_ui_illum_offset4
	0x70,
	0x00, //cadrx_ui_illum_slope1
	0x80,
	0x00, //cadrx_ui_illum_slope2
	0x80,
	0x00, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x40,
	0x01, //cadrx_ui_ref_offset2
	0x80,
	0x01, //cadrx_ui_ref_offset3
	0x80,
	0x01, //cadrx_ui_ref_offset4
	0x80,
	0x02, //cadrx_ui_ref_slope1
	0x00,
	0x00, //cadrx_ui_ref_slope2
	0x00,
	0x00, //cadrx_ui_ref_slope3
	0x00,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x00, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0xe6, //pos_bi_min
	0xff, //pos_bi_max
	0x07, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x10,
	0x00, //de_maxplus 11
	0x40,
	0x00, //de_maxminus 11
	0x40,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x10,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x80,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x06, //curve_y_1
	0x0c, //curve_y_2
	0x12, //curve_y_3
	0x18, //curve_y_4
	0x1e, //curve_y_5
	0x24, //curve_y_6
	0x2c, //curve_y_7
	0x34, //curve_y_8
	0x3e, //curve_y_9
	0x47, //curve_y_10
	0x52, //curve_y_11
	0x5c, //curve_y_12
	0x67, //curve_y_13
	0x72, //curve_y_14
	0x80, //curve_y_15
	0x8e, //curve_y_16
	0x9c, //curve_y_17
	0xaa, //curve_y_18
	0xb8, //curve_y_19
	0xc6, //curve_y_20
	0xcf, //curve_y_21
	0xd7, //curve_y_22
	0xdf, //curve_y_23
	0xe6, //curve_y_24
	0xeb, //curve_y_25
	0xf0, //curve_y_26
	0xf5, //curve_y_27
	0xfa, //curve_y_28
	0xfd, //curve_y_29
	0xff, //curve_y_30
	0xff, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static unsigned char DSI0_HDR_VIDEO_5_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0xf3, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0xff, //trans_on trans_block 0 000 0000
	0x04, //trans_slope
	0x01, //trans_interval
	//end
};

static unsigned char DSI0_VIDEO_ENHANCER_D65_MDNIE_1[] = {
	//start
	0xDF,
	0x01, //linear_on ascr_skin_on 0000 0000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xff, //ascr_skin_Rr
	0x60, //ascr_skin_Rg
	0x70, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xf7, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xfc, //ascr_skin_Wg
	0xf6, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xf0, //ascr_Rr
	0xee, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xf7, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xfc, //ascr_Wg
	0x00, //ascr_Kg
	0xf6, //ascr_Wb
	0x00, //ascr_Kb
};

static unsigned char DSI0_VIDEO_ENHANCER_D65_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x11, //slce_on cadrx_en 0000 0000
	0x08, //lce_gain 000 0000
	0x18, //lce_color_gain 00 0000
	0x00, //lce_min_ref_offset
	0xff,
	0xa0, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x40,
	0x01, //lce_ref_gain 9
	0x00,
	0x66, //lce_block_size h v 0000 0000
	0x05, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x10, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x40,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x04, //lce_lg_flicker Avg pixel_cnt 000
	0x00, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x00, //lce_lg_mix_weight 7
	0x1b, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0xd0,
	0x00, //cadrx_ui_illum_offset2
	0xc0,
	0x00, //cadrx_ui_illum_offset3
	0xb0,
	0x00, //cadrx_ui_illum_offset4
	0xa0,
	0x07, //cadrx_ui_illum_slope1
	0x80,
	0x07, //cadrx_ui_illum_slope2
	0x80,
	0x07, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x60,
	0x01, //cadrx_ui_ref_offset2
	0x50,
	0x01, //cadrx_ui_ref_offset3
	0x40,
	0x01, //cadrx_ui_ref_offset4
	0x30,
	0x07, //cadrx_ui_ref_slope1
	0x80,
	0x07, //cadrx_ui_ref_slope2
	0x80,
	0x07, //cadrx_ui_ref_slope3
	0x80,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x00, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0xe6, //pos_bi_min
	0xff, //pos_bi_max
	0x07, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x10,
	0x00, //de_maxplus 11
	0x40,
	0x00, //de_maxminus 11
	0x40,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x10,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x20,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x08, //curve_y_1
	0x10, //curve_y_2
	0x18, //curve_y_3
	0x20, //curve_y_4
	0x28, //curve_y_5
	0x30, //curve_y_6
	0x38, //curve_y_7
	0x40, //curve_y_8
	0x48, //curve_y_9
	0x50, //curve_y_10
	0x58, //curve_y_11
	0x60, //curve_y_12
	0x68, //curve_y_13
	0x70, //curve_y_14
	0x78, //curve_y_15
	0x80, //curve_y_16
	0x88, //curve_y_17
	0x90, //curve_y_18
	0x98, //curve_y_19
	0xa0, //curve_y_20
	0xa8, //curve_y_21
	0xb0, //curve_y_22
	0xb8, //curve_y_23
	0xc0, //curve_y_24
	0xc8, //curve_y_25
	0xd0, //curve_y_26
	0xd8, //curve_y_27
	0xe0, //curve_y_28
	0xe8, //curve_y_29
	0xf0, //curve_y_30
	0xf8, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static unsigned char DSI0_VIDEO_ENHANCER_D65_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0xfc, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0xff, //trans_on trans_block 0 000 0000
	0x04, //trans_slope
	0x01, //trans_interval
	//end
};

static unsigned char DSI0_VIDEO_ENHANCER_AUTO_MDNIE_1[] = {
	//start
	0xDF,
	0x01, //linear_on ascr_skin_on 0000 0000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xff, //ascr_skin_Rr
	0x60, //ascr_skin_Rg
	0x70, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xf7, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xf0, //ascr_Rr
	0xee, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xf7, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xff, //ascr_Wg
	0x00, //ascr_Kg
	0xff, //ascr_Wb
	0x00, //ascr_Kb
};

static unsigned char DSI0_VIDEO_ENHANCER_AUTO_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x11, //slce_on cadrx_en 0000 0000
	0x08, //lce_gain 000 0000
	0x18, //lce_color_gain 00 0000
	0x00, //lce_min_ref_offset
	0xff,
	0xa0, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x40,
	0x01, //lce_ref_gain 9
	0x00,
	0x66, //lce_block_size h v 0000 0000
	0x05, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x10, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x40,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x04, //lce_lg_flicker Avg pixel_cnt 000
	0x00, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x00, //lce_lg_mix_weight 7
	0x1b, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0xd0,
	0x00, //cadrx_ui_illum_offset2
	0xc0,
	0x00, //cadrx_ui_illum_offset3
	0xb0,
	0x00, //cadrx_ui_illum_offset4
	0xa0,
	0x07, //cadrx_ui_illum_slope1
	0x80,
	0x07, //cadrx_ui_illum_slope2
	0x80,
	0x07, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x60,
	0x01, //cadrx_ui_ref_offset2
	0x50,
	0x01, //cadrx_ui_ref_offset3
	0x40,
	0x01, //cadrx_ui_ref_offset4
	0x30,
	0x07, //cadrx_ui_ref_slope1
	0x80,
	0x07, //cadrx_ui_ref_slope2
	0x80,
	0x07, //cadrx_ui_ref_slope3
	0x80,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x00, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0xe6, //pos_bi_min
	0xff, //pos_bi_max
	0x07, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x10,
	0x00, //de_maxplus 11
	0x40,
	0x00, //de_maxminus 11
	0x40,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x10,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x20,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x08, //curve_y_1
	0x10, //curve_y_2
	0x18, //curve_y_3
	0x20, //curve_y_4
	0x28, //curve_y_5
	0x30, //curve_y_6
	0x38, //curve_y_7
	0x40, //curve_y_8
	0x48, //curve_y_9
	0x50, //curve_y_10
	0x58, //curve_y_11
	0x60, //curve_y_12
	0x68, //curve_y_13
	0x70, //curve_y_14
	0x78, //curve_y_15
	0x80, //curve_y_16
	0x88, //curve_y_17
	0x90, //curve_y_18
	0x98, //curve_y_19
	0xa0, //curve_y_20
	0xa8, //curve_y_21
	0xb0, //curve_y_22
	0xb8, //curve_y_23
	0xc0, //curve_y_24
	0xc8, //curve_y_25
	0xd0, //curve_y_26
	0xd8, //curve_y_27
	0xe0, //curve_y_28
	0xe8, //curve_y_29
	0xf0, //curve_y_30
	0xf8, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static unsigned char DSI0_VIDEO_ENHANCER_AUTO_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0xfc, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0xff, //trans_on trans_block 0 000 0000
	0x04, //trans_slope
	0x01, //trans_interval
	//end
};


static unsigned char DSI0_VIDEO_ENHANCER_THIRD_D65_MDNIE_1[] = {
	//start
	0xDF,
	0x01, //linear_on ascr_skin_on 0000 0000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xff, //ascr_skin_Rr
	0x60, //ascr_skin_Rg
	0x70, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xf7, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xfc, //ascr_skin_Wg
	0xf6, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xf0, //ascr_Rr
	0xee, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xf7, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xfc, //ascr_Wg
	0x00, //ascr_Kg
	0xf6, //ascr_Wb
	0x00, //ascr_Kb
};

static unsigned char DSI0_VIDEO_ENHANCER_THIRD_D65_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x11, //slce_on cadrx_en 0000 0000
	0x01, //lce_gain 000 0000
	0x18, //lce_color_gain 00 0000
	0x00, //lce_min_ref_offset
	0xff,
	0xa0, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x40,
	0x01, //lce_ref_gain 9
	0x00,
	0x66, //lce_block_size h v 0000 0000
	0x05, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x10, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x40,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x04, //lce_lg_flicker Avg pixel_cnt 000
	0x00, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x00, //lce_lg_mix_weight 7
	0x1b, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0xd0,
	0x00, //cadrx_ui_illum_offset2
	0xc0,
	0x00, //cadrx_ui_illum_offset3
	0xb0,
	0x00, //cadrx_ui_illum_offset4
	0xa0,
	0x07, //cadrx_ui_illum_slope1
	0x80,
	0x07, //cadrx_ui_illum_slope2
	0x80,
	0x07, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x60,
	0x01, //cadrx_ui_ref_offset2
	0x50,
	0x01, //cadrx_ui_ref_offset3
	0x40,
	0x01, //cadrx_ui_ref_offset4
	0x30,
	0x07, //cadrx_ui_ref_slope1
	0x80,
	0x07, //cadrx_ui_ref_slope2
	0x80,
	0x07, //cadrx_ui_ref_slope3
	0x80,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x00, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0xe6, //pos_bi_min
	0xff, //pos_bi_max
	0x07, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x10,
	0x00, //de_maxplus 11
	0x40,
	0x00, //de_maxminus 11
	0x40,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x10,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x20,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x0b, //curve_y_1
	0x15, //curve_y_2
	0x1e, //curve_y_3
	0x27, //curve_y_4
	0x2f, //curve_y_5
	0x38, //curve_y_6
	0x40, //curve_y_7
	0x49, //curve_y_8
	0x51, //curve_y_9
	0x59, //curve_y_10
	0x61, //curve_y_11
	0x69, //curve_y_12
	0x71, //curve_y_13
	0x79, //curve_y_14
	0x81, //curve_y_15
	0x88, //curve_y_16
	0x8e, //curve_y_17
	0x95, //curve_y_18
	0x9c, //curve_y_19
	0xa3, //curve_y_20
	0xaa, //curve_y_21
	0xb1, //curve_y_22
	0xb8, //curve_y_23
	0xc0, //curve_y_24
	0xc8, //curve_y_25
	0xd0, //curve_y_26
	0xd8, //curve_y_27
	0xe0, //curve_y_28
	0xe8, //curve_y_29
	0xf0, //curve_y_30
	0xf8, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static unsigned char DSI0_VIDEO_ENHANCER_THIRD_D65_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0xfc, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0xff, //trans_on trans_block 0 000 0000
	0x04, //trans_slope
	0x01, //trans_interval
	//end
};

static unsigned char DSI0_VIDEO_ENHANCER_THIRD_AUTO_MDNIE_1[] = {
	//start
	0xDF,
	0x01, //linear_on ascr_skin_on 0000 0000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xff, //ascr_skin_Rr
	0x60, //ascr_skin_Rg
	0x70, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xf7, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xf0, //ascr_Rr
	0xee, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xf7, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xff, //ascr_Wg
	0x00, //ascr_Kg
	0xff, //ascr_Wb
	0x00, //ascr_Kb
};

static unsigned char DSI0_VIDEO_ENHANCER_THIRD_AUTO_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x11, //slce_on cadrx_en 0000 0000
	0x01, //lce_gain 000 0000
	0x18, //lce_color_gain 00 0000
	0x00, //lce_min_ref_offset
	0xff,
	0xa0, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x40,
	0x01, //lce_ref_gain 9
	0x00,
	0x66, //lce_block_size h v 0000 0000
	0x05, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x10, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x40,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x04, //lce_lg_flicker Avg pixel_cnt 000
	0x00, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x00, //lce_lg_mix_weight 7
	0x1b, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0xd0,
	0x00, //cadrx_ui_illum_offset2
	0xc0,
	0x00, //cadrx_ui_illum_offset3
	0xb0,
	0x00, //cadrx_ui_illum_offset4
	0xa0,
	0x07, //cadrx_ui_illum_slope1
	0x80,
	0x07, //cadrx_ui_illum_slope2
	0x80,
	0x07, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x60,
	0x01, //cadrx_ui_ref_offset2
	0x50,
	0x01, //cadrx_ui_ref_offset3
	0x40,
	0x01, //cadrx_ui_ref_offset4
	0x30,
	0x07, //cadrx_ui_ref_slope1
	0x80,
	0x07, //cadrx_ui_ref_slope2
	0x80,
	0x07, //cadrx_ui_ref_slope3
	0x80,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x00, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0xe6, //pos_bi_min
	0xff, //pos_bi_max
	0x07, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x10,
	0x00, //de_maxplus 11
	0x40,
	0x00, //de_maxminus 11
	0x40,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x10,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x20,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x0b, //curve_y_1
	0x15, //curve_y_2
	0x1e, //curve_y_3
	0x27, //curve_y_4
	0x2f, //curve_y_5
	0x38, //curve_y_6
	0x40, //curve_y_7
	0x49, //curve_y_8
	0x51, //curve_y_9
	0x59, //curve_y_10
	0x61, //curve_y_11
	0x69, //curve_y_12
	0x71, //curve_y_13
	0x79, //curve_y_14
	0x81, //curve_y_15
	0x88, //curve_y_16
	0x8e, //curve_y_17
	0x95, //curve_y_18
	0x9c, //curve_y_19
	0xa3, //curve_y_20
	0xaa, //curve_y_21
	0xb1, //curve_y_22
	0xb8, //curve_y_23
	0xc0, //curve_y_24
	0xc8, //curve_y_25
	0xd0, //curve_y_26
	0xd8, //curve_y_27
	0xe0, //curve_y_28
	0xe8, //curve_y_29
	0xf0, //curve_y_30
	0xf8, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static unsigned char DSI0_VIDEO_ENHANCER_THIRD_AUTO_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0xfc, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0xff, //trans_on trans_block 0 000 0000
	0x04, //trans_slope
	0x01, //trans_interval
	//end
};

static char DSI0_UI_DYNAMIC_MDNIE_1[] = {
	//start
	0xDF,
	0x11, //linear_on ascr_skin_on 0000 0000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xe8, //ascr_skin_Rr
	0x1c, //ascr_skin_Rg
	0x00, //ascr_skin_Rb
	0xf0, //ascr_skin_Yr
	0xf2, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xf2, //ascr_skin_Mr
	0x18, //ascr_skin_Mg
	0xef, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xfc, //ascr_skin_Wg
	0xf6, //ascr_skin_Wb
	0x58, //ascr_Cr
	0xe8, //ascr_Rr
	0xf5, //ascr_Cg
	0x1c, //ascr_Rg
	0xf1, //ascr_Cb
	0x00, //ascr_Rb
	0xf2, //ascr_Mr
	0x38, //ascr_Gr
	0x18, //ascr_Mg
	0xff, //ascr_Gg
	0xef, //ascr_Mb
	0x00, //ascr_Gb
	0xf0, //ascr_Yr
	0x35, //ascr_Br
	0xf2, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xe8, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xfc, //ascr_Wg
	0x00, //ascr_Kg
	0xf6, //ascr_Wb
	0x00, //ascr_Kb
};

static char DSI0_UI_DYNAMIC_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x00, //slce_on cadrx_en 0000 0000
	0x00, //lce_gain 000 0000
	0x30, //lce_color_gain 00 0000
	0x01, //lce_min_ref_offset
	0x00,
	0x70, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x34,
	0x01, //lce_ref_gain 9
	0x40,
	0x66, //lce_block_size h v 0000 0000
	0x03, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x11, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x20,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x00, //lce_lg_flicker Avg pixel_cnt 000
	0x0a, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x00, //lce_lg_mix_weight 7
	0x10, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0x40,
	0x00, //cadrx_ui_illum_offset2
	0x50,
	0x00, //cadrx_ui_illum_offset3
	0x60,
	0x00, //cadrx_ui_illum_offset4
	0x70,
	0x00, //cadrx_ui_illum_slope1
	0x80,
	0x00, //cadrx_ui_illum_slope2
	0x80,
	0x00, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x40,
	0x01, //cadrx_ui_ref_offset2
	0x80,
	0x01, //cadrx_ui_ref_offset3
	0x80,
	0x01, //cadrx_ui_ref_offset4
	0x80,
	0x02, //cadrx_ui_ref_slope1
	0x00,
	0x00, //cadrx_ui_ref_slope2
	0x00,
	0x00, //cadrx_ui_ref_slope3
	0x00,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x00, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0xe6, //pos_bi_min
	0xff, //pos_bi_max
	0x00, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x02, //de_maxplus 11
	0x00,
	0x02, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x10,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x08, //curve_y_1
	0x10, //curve_y_2
	0x18, //curve_y_3
	0x20, //curve_y_4
	0x28, //curve_y_5
	0x30, //curve_y_6
	0x38, //curve_y_7
	0x40, //curve_y_8
	0x48, //curve_y_9
	0x50, //curve_y_10
	0x58, //curve_y_11
	0x60, //curve_y_12
	0x68, //curve_y_13
	0x70, //curve_y_14
	0x78, //curve_y_15
	0x80, //curve_y_16
	0x88, //curve_y_17
	0x90, //curve_y_18
	0x98, //curve_y_19
	0xa0, //curve_y_20
	0xa8, //curve_y_21
	0xb0, //curve_y_22
	0xb8, //curve_y_23
	0xc0, //curve_y_24
	0xc8, //curve_y_25
	0xd0, //curve_y_26
	0xd8, //curve_y_27
	0xe0, //curve_y_28
	0xe8, //curve_y_29
	0xf0, //curve_y_30
	0xf8, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static char DSI0_UI_DYNAMIC_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0xf0, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0xff, //trans_on trans_block 0 000 0000
	0x04, //trans_slope
	0x01, //trans_interval
	//end
};

static char DSI0_UI_STANDARD_MDNIE_1[] = {
	//start
	0xDF,
	0x11, //linear_on ascr_skin_on 0000 0000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xff, //ascr_skin_Rr
	0x4e, //ascr_skin_Rg
	0x2e, //ascr_skin_Rb
	0xfa, //ascr_skin_Yr
	0xfa, //ascr_skin_Yg
	0x45, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x5d, //ascr_skin_Mg
	0xf5, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xfc, //ascr_skin_Wg
	0xf6, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xf5, //ascr_Cg
	0x4e, //ascr_Rg
	0xf5, //ascr_Cb
	0x2e, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x5d, //ascr_Mg
	0xf1, //ascr_Gg
	0xf5, //ascr_Mb
	0x33, //ascr_Gb
	0xfa, //ascr_Yr
	0x38, //ascr_Br
	0xfa, //ascr_Yg
	0x1e, //ascr_Bg
	0x45, //ascr_Yb
	0xf2, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xfc, //ascr_Wg
	0x00, //ascr_Kg
	0xf6, //ascr_Wb
	0x00, //ascr_Kb
};

static char DSI0_UI_STANDARD_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x00, //slce_on cadrx_en 0000 0000
	0x00, //lce_gain 000 0000
	0x30, //lce_color_gain 00 0000
	0x01, //lce_min_ref_offset
	0x00,
	0x70, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x34,
	0x01, //lce_ref_gain 9
	0x40,
	0x66, //lce_block_size h v 0000 0000
	0x03, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x11, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x20,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x00, //lce_lg_flicker Avg pixel_cnt 000
	0x0a, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x00, //lce_lg_mix_weight 7
	0x10, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0x40,
	0x00, //cadrx_ui_illum_offset2
	0x50,
	0x00, //cadrx_ui_illum_offset3
	0x60,
	0x00, //cadrx_ui_illum_offset4
	0x70,
	0x00, //cadrx_ui_illum_slope1
	0x80,
	0x00, //cadrx_ui_illum_slope2
	0x80,
	0x00, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x40,
	0x01, //cadrx_ui_ref_offset2
	0x80,
	0x01, //cadrx_ui_ref_offset3
	0x80,
	0x01, //cadrx_ui_ref_offset4
	0x80,
	0x02, //cadrx_ui_ref_slope1
	0x00,
	0x00, //cadrx_ui_ref_slope2
	0x00,
	0x00, //cadrx_ui_ref_slope3
	0x00,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x00, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0xe6, //pos_bi_min
	0xff, //pos_bi_max
	0x02, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x02, //de_maxplus 11
	0x00,
	0x02, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x10,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x18,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x08, //curve_y_1
	0x10, //curve_y_2
	0x18, //curve_y_3
	0x20, //curve_y_4
	0x28, //curve_y_5
	0x30, //curve_y_6
	0x38, //curve_y_7
	0x40, //curve_y_8
	0x48, //curve_y_9
	0x50, //curve_y_10
	0x58, //curve_y_11
	0x60, //curve_y_12
	0x68, //curve_y_13
	0x70, //curve_y_14
	0x78, //curve_y_15
	0x80, //curve_y_16
	0x88, //curve_y_17
	0x90, //curve_y_18
	0x98, //curve_y_19
	0xa0, //curve_y_20
	0xa8, //curve_y_21
	0xb0, //curve_y_22
	0xb8, //curve_y_23
	0xc0, //curve_y_24
	0xc8, //curve_y_25
	0xd0, //curve_y_26
	0xd8, //curve_y_27
	0xe0, //curve_y_28
	0xe8, //curve_y_29
	0xf0, //curve_y_30
	0xf8, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static char DSI0_UI_STANDARD_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0xf0, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0xff, //trans_on trans_block 0 000 0000
	0x04, //trans_slope
	0x01, //trans_interval
	//end
};

static char DSI0_UI_NATURAL_MDNIE_1[] = {
	//start
	0xDF,
	0x11, //linear_on ascr_skin_on 0000 0000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xe1, //ascr_skin_Rr
	0x3d, //ascr_skin_Rg
	0x27, //ascr_skin_Rb
	0xfa, //ascr_skin_Yr
	0xfb, //ascr_skin_Yg
	0x57, //ascr_skin_Yb
	0xe6, //ascr_skin_Mr
	0x46, //ascr_skin_Mg
	0xf0, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xfc, //ascr_skin_Wg
	0xf6, //ascr_skin_Wb
	0x8f, //ascr_Cr
	0xe1, //ascr_Rr
	0xf8, //ascr_Cg
	0x3d, //ascr_Rg
	0xf5, //ascr_Cb
	0x27, //ascr_Rb
	0xe6, //ascr_Mr
	0x86, //ascr_Gr
	0x46, //ascr_Mg
	0xf5, //ascr_Gg
	0xf0, //ascr_Mb
	0x4f, //ascr_Gb
	0xfa, //ascr_Yr
	0x37, //ascr_Br
	0xfb, //ascr_Yg
	0x1f, //ascr_Bg
	0x57, //ascr_Yb
	0xed, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xfc, //ascr_Wg
	0x00, //ascr_Kg
	0xf6, //ascr_Wb
	0x00, //ascr_Kb
};

static char DSI0_UI_NATURAL_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x00, //slce_on cadrx_en 0000 0000
	0x00, //lce_gain 000 0000
	0x30, //lce_color_gain 00 0000
	0x01, //lce_min_ref_offset
	0x00,
	0x70, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x34,
	0x01, //lce_ref_gain 9
	0x40,
	0x66, //lce_block_size h v 0000 0000
	0x03, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x11, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x20,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x00, //lce_lg_flicker Avg pixel_cnt 000
	0x0a, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x00, //lce_lg_mix_weight 7
	0x10, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0x40,
	0x00, //cadrx_ui_illum_offset2
	0x50,
	0x00, //cadrx_ui_illum_offset3
	0x60,
	0x00, //cadrx_ui_illum_offset4
	0x70,
	0x00, //cadrx_ui_illum_slope1
	0x80,
	0x00, //cadrx_ui_illum_slope2
	0x80,
	0x00, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x40,
	0x01, //cadrx_ui_ref_offset2
	0x80,
	0x01, //cadrx_ui_ref_offset3
	0x80,
	0x01, //cadrx_ui_ref_offset4
	0x80,
	0x02, //cadrx_ui_ref_slope1
	0x00,
	0x00, //cadrx_ui_ref_slope2
	0x00,
	0x00, //cadrx_ui_ref_slope3
	0x00,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x00, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0xe6, //pos_bi_min
	0xff, //pos_bi_max
	0x00, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x02, //de_maxplus 11
	0x00,
	0x02, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x10,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x08, //curve_y_1
	0x10, //curve_y_2
	0x18, //curve_y_3
	0x20, //curve_y_4
	0x28, //curve_y_5
	0x30, //curve_y_6
	0x38, //curve_y_7
	0x40, //curve_y_8
	0x48, //curve_y_9
	0x50, //curve_y_10
	0x58, //curve_y_11
	0x60, //curve_y_12
	0x68, //curve_y_13
	0x70, //curve_y_14
	0x78, //curve_y_15
	0x80, //curve_y_16
	0x88, //curve_y_17
	0x90, //curve_y_18
	0x98, //curve_y_19
	0xa0, //curve_y_20
	0xa8, //curve_y_21
	0xb0, //curve_y_22
	0xb8, //curve_y_23
	0xc0, //curve_y_24
	0xc8, //curve_y_25
	0xd0, //curve_y_26
	0xd8, //curve_y_27
	0xe0, //curve_y_28
	0xe8, //curve_y_29
	0xf0, //curve_y_30
	0xf8, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static char DSI0_UI_NATURAL_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0xf0, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0xff, //trans_on trans_block 0 000 0000
	0x04, //trans_slope
	0x01, //trans_interval
	//end
};

static char DSI0_UI_AUTO_MDNIE_1[] = {
	//start
	0xDF,
	0x01, //linear_on ascr_skin_on 0000 0000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xff, //ascr_skin_Rr
	0x30, //ascr_skin_Rg
	0x38, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xff, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xff, //ascr_Wg
	0x00, //ascr_Kg
	0xff, //ascr_Wb
	0x00, //ascr_Kb
};

static char DSI0_UI_AUTO_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x00, //slce_on cadrx_en 0000 0000
	0x00, //lce_gain 000 0000
	0x30, //lce_color_gain 00 0000
	0x01, //lce_min_ref_offset
	0x00,
	0x70, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x34,
	0x01, //lce_ref_gain 9
	0x40,
	0x66, //lce_block_size h v 0000 0000
	0x03, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x11, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x20,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x00, //lce_lg_flicker Avg pixel_cnt 000
	0x0a, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x00, //lce_lg_mix_weight 7
	0x10, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0x40,
	0x00, //cadrx_ui_illum_offset2
	0x50,
	0x00, //cadrx_ui_illum_offset3
	0x60,
	0x00, //cadrx_ui_illum_offset4
	0x70,
	0x00, //cadrx_ui_illum_slope1
	0x80,
	0x00, //cadrx_ui_illum_slope2
	0x80,
	0x00, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x40,
	0x01, //cadrx_ui_ref_offset2
	0x80,
	0x01, //cadrx_ui_ref_offset3
	0x80,
	0x01, //cadrx_ui_ref_offset4
	0x80,
	0x02, //cadrx_ui_ref_slope1
	0x00,
	0x00, //cadrx_ui_ref_slope2
	0x00,
	0x00, //cadrx_ui_ref_slope3
	0x00,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x00, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0xe6, //pos_bi_min
	0xff, //pos_bi_max
	0x00, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x02, //de_maxplus 11
	0x00,
	0x02, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x10,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x08, //curve_y_1
	0x10, //curve_y_2
	0x18, //curve_y_3
	0x20, //curve_y_4
	0x28, //curve_y_5
	0x30, //curve_y_6
	0x38, //curve_y_7
	0x40, //curve_y_8
	0x48, //curve_y_9
	0x50, //curve_y_10
	0x58, //curve_y_11
	0x60, //curve_y_12
	0x68, //curve_y_13
	0x70, //curve_y_14
	0x78, //curve_y_15
	0x80, //curve_y_16
	0x88, //curve_y_17
	0x90, //curve_y_18
	0x98, //curve_y_19
	0xa0, //curve_y_20
	0xa8, //curve_y_21
	0xb0, //curve_y_22
	0xb8, //curve_y_23
	0xc0, //curve_y_24
	0xc8, //curve_y_25
	0xd0, //curve_y_26
	0xd8, //curve_y_27
	0xe0, //curve_y_28
	0xe8, //curve_y_29
	0xf0, //curve_y_30
	0xf8, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static char DSI0_UI_AUTO_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0xf0, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0xff, //trans_on trans_block 0 000 0000
	0x04, //trans_slope
	0x01, //trans_interval
	//end
};

static char DSI0_VIDEO_DYNAMIC_MDNIE_1[] = {
	//start
	0xDF,
	0x11, //linear_on ascr_skin_on 0000 0000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xe8, //ascr_skin_Rr
	0x1c, //ascr_skin_Rg
	0x00, //ascr_skin_Rb
	0xf0, //ascr_skin_Yr
	0xf2, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xf2, //ascr_skin_Mr
	0x18, //ascr_skin_Mg
	0xef, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xfc, //ascr_skin_Wg
	0xf6, //ascr_skin_Wb
	0x58, //ascr_Cr
	0xe8, //ascr_Rr
	0xf5, //ascr_Cg
	0x1c, //ascr_Rg
	0xf1, //ascr_Cb
	0x00, //ascr_Rb
	0xf2, //ascr_Mr
	0x38, //ascr_Gr
	0x18, //ascr_Mg
	0xff, //ascr_Gg
	0xef, //ascr_Mb
	0x00, //ascr_Gb
	0xf0, //ascr_Yr
	0x35, //ascr_Br
	0xf2, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xe8, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xfc, //ascr_Wg
	0x00, //ascr_Kg
	0xf6, //ascr_Wb
	0x00, //ascr_Kb
};

static char DSI0_VIDEO_DYNAMIC_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x00, //slce_on cadrx_en 0000 0000
	0x00, //lce_gain 000 0000
	0x30, //lce_color_gain 00 0000
	0x01, //lce_min_ref_offset
	0x00,
	0x70, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x34,
	0x01, //lce_ref_gain 9
	0x40,
	0x66, //lce_block_size h v 0000 0000
	0x03, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x11, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x20,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x00, //lce_lg_flicker Avg pixel_cnt 000
	0x0a, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x00, //lce_lg_mix_weight 7
	0x10, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0x40,
	0x00, //cadrx_ui_illum_offset2
	0x50,
	0x00, //cadrx_ui_illum_offset3
	0x60,
	0x00, //cadrx_ui_illum_offset4
	0x70,
	0x00, //cadrx_ui_illum_slope1
	0x80,
	0x00, //cadrx_ui_illum_slope2
	0x80,
	0x00, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x40,
	0x01, //cadrx_ui_ref_offset2
	0x80,
	0x01, //cadrx_ui_ref_offset3
	0x80,
	0x01, //cadrx_ui_ref_offset4
	0x80,
	0x02, //cadrx_ui_ref_slope1
	0x00,
	0x00, //cadrx_ui_ref_slope2
	0x00,
	0x00, //cadrx_ui_ref_slope3
	0x00,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x00, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0xe6, //pos_bi_min
	0xff, //pos_bi_max
	0x04, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x10,
	0x00, //de_maxplus 11
	0x40,
	0x00, //de_maxminus 11
	0x40,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x10,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x08, //curve_y_1
	0x10, //curve_y_2
	0x18, //curve_y_3
	0x20, //curve_y_4
	0x28, //curve_y_5
	0x30, //curve_y_6
	0x38, //curve_y_7
	0x40, //curve_y_8
	0x48, //curve_y_9
	0x50, //curve_y_10
	0x58, //curve_y_11
	0x60, //curve_y_12
	0x68, //curve_y_13
	0x70, //curve_y_14
	0x78, //curve_y_15
	0x80, //curve_y_16
	0x88, //curve_y_17
	0x90, //curve_y_18
	0x98, //curve_y_19
	0xa0, //curve_y_20
	0xa8, //curve_y_21
	0xb0, //curve_y_22
	0xb8, //curve_y_23
	0xc0, //curve_y_24
	0xc8, //curve_y_25
	0xd0, //curve_y_26
	0xd8, //curve_y_27
	0xe0, //curve_y_28
	0xe8, //curve_y_29
	0xf0, //curve_y_30
	0xf8, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static char DSI0_VIDEO_DYNAMIC_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0xf0, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0xff, //trans_on trans_block 0 000 0000
	0x04, //trans_slope
	0x01, //trans_interval
	//end
};

static char DSI0_VIDEO_STANDARD_MDNIE_1[] = {
	//start
	0xDF,
	0x11, //linear_on ascr_skin_on 0000 0000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xff, //ascr_skin_Rr
	0x4e, //ascr_skin_Rg
	0x2e, //ascr_skin_Rb
	0xfa, //ascr_skin_Yr
	0xfa, //ascr_skin_Yg
	0x45, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x5d, //ascr_skin_Mg
	0xf5, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xfc, //ascr_skin_Wg
	0xf6, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xf5, //ascr_Cg
	0x4e, //ascr_Rg
	0xf5, //ascr_Cb
	0x2e, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x5d, //ascr_Mg
	0xf1, //ascr_Gg
	0xf5, //ascr_Mb
	0x33, //ascr_Gb
	0xfa, //ascr_Yr
	0x38, //ascr_Br
	0xfa, //ascr_Yg
	0x1e, //ascr_Bg
	0x45, //ascr_Yb
	0xf2, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xfc, //ascr_Wg
	0x00, //ascr_Kg
	0xf6, //ascr_Wb
	0x00, //ascr_Kb
};

static char DSI0_VIDEO_STANDARD_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x00, //slce_on cadrx_en 0000 0000
	0x00, //lce_gain 000 0000
	0x30, //lce_color_gain 00 0000
	0x01, //lce_min_ref_offset
	0x00,
	0x70, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x34,
	0x01, //lce_ref_gain 9
	0x40,
	0x66, //lce_block_size h v 0000 0000
	0x03, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x11, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x20,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x00, //lce_lg_flicker Avg pixel_cnt 000
	0x0a, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x00, //lce_lg_mix_weight 7
	0x10, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0x40,
	0x00, //cadrx_ui_illum_offset2
	0x50,
	0x00, //cadrx_ui_illum_offset3
	0x60,
	0x00, //cadrx_ui_illum_offset4
	0x70,
	0x00, //cadrx_ui_illum_slope1
	0x80,
	0x00, //cadrx_ui_illum_slope2
	0x80,
	0x00, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x40,
	0x01, //cadrx_ui_ref_offset2
	0x80,
	0x01, //cadrx_ui_ref_offset3
	0x80,
	0x01, //cadrx_ui_ref_offset4
	0x80,
	0x02, //cadrx_ui_ref_slope1
	0x00,
	0x00, //cadrx_ui_ref_slope2
	0x00,
	0x00, //cadrx_ui_ref_slope3
	0x00,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x00, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0xe6, //pos_bi_min
	0xff, //pos_bi_max
	0x06, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x10,
	0x00, //de_maxplus 11
	0x40,
	0x00, //de_maxminus 11
	0x40,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x10,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x18,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x08, //curve_y_1
	0x10, //curve_y_2
	0x18, //curve_y_3
	0x20, //curve_y_4
	0x28, //curve_y_5
	0x30, //curve_y_6
	0x38, //curve_y_7
	0x40, //curve_y_8
	0x48, //curve_y_9
	0x50, //curve_y_10
	0x58, //curve_y_11
	0x60, //curve_y_12
	0x68, //curve_y_13
	0x70, //curve_y_14
	0x78, //curve_y_15
	0x80, //curve_y_16
	0x88, //curve_y_17
	0x90, //curve_y_18
	0x98, //curve_y_19
	0xa0, //curve_y_20
	0xa8, //curve_y_21
	0xb0, //curve_y_22
	0xb8, //curve_y_23
	0xc0, //curve_y_24
	0xc8, //curve_y_25
	0xd0, //curve_y_26
	0xd8, //curve_y_27
	0xe0, //curve_y_28
	0xe8, //curve_y_29
	0xf0, //curve_y_30
	0xf8, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static char DSI0_VIDEO_STANDARD_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0xf0, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0xff, //trans_on trans_block 0 000 0000
	0x04, //trans_slope
	0x01, //trans_interval
	//end
};

static char DSI0_VIDEO_NATURAL_MDNIE_1[] = {
	//start
	0xDF,
	0x11, //linear_on ascr_skin_on 0000 0000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xe1, //ascr_skin_Rr
	0x3d, //ascr_skin_Rg
	0x27, //ascr_skin_Rb
	0xfa, //ascr_skin_Yr
	0xfb, //ascr_skin_Yg
	0x57, //ascr_skin_Yb
	0xe6, //ascr_skin_Mr
	0x46, //ascr_skin_Mg
	0xf0, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xfc, //ascr_skin_Wg
	0xf6, //ascr_skin_Wb
	0x8f, //ascr_Cr
	0xe1, //ascr_Rr
	0xf8, //ascr_Cg
	0x3d, //ascr_Rg
	0xf5, //ascr_Cb
	0x27, //ascr_Rb
	0xe6, //ascr_Mr
	0x86, //ascr_Gr
	0x46, //ascr_Mg
	0xf5, //ascr_Gg
	0xf0, //ascr_Mb
	0x4f, //ascr_Gb
	0xfa, //ascr_Yr
	0x37, //ascr_Br
	0xfb, //ascr_Yg
	0x1f, //ascr_Bg
	0x57, //ascr_Yb
	0xed, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xfc, //ascr_Wg
	0x00, //ascr_Kg
	0xf6, //ascr_Wb
	0x00, //ascr_Kb
};

static char DSI0_VIDEO_NATURAL_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x00, //slce_on cadrx_en 0000 0000
	0x00, //lce_gain 000 0000
	0x30, //lce_color_gain 00 0000
	0x01, //lce_min_ref_offset
	0x00,
	0x70, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x34,
	0x01, //lce_ref_gain 9
	0x40,
	0x66, //lce_block_size h v 0000 0000
	0x03, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x11, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x20,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x00, //lce_lg_flicker Avg pixel_cnt 000
	0x0a, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x00, //lce_lg_mix_weight 7
	0x10, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0x40,
	0x00, //cadrx_ui_illum_offset2
	0x50,
	0x00, //cadrx_ui_illum_offset3
	0x60,
	0x00, //cadrx_ui_illum_offset4
	0x70,
	0x00, //cadrx_ui_illum_slope1
	0x80,
	0x00, //cadrx_ui_illum_slope2
	0x80,
	0x00, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x40,
	0x01, //cadrx_ui_ref_offset2
	0x80,
	0x01, //cadrx_ui_ref_offset3
	0x80,
	0x01, //cadrx_ui_ref_offset4
	0x80,
	0x02, //cadrx_ui_ref_slope1
	0x00,
	0x00, //cadrx_ui_ref_slope2
	0x00,
	0x00, //cadrx_ui_ref_slope3
	0x00,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x00, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0xe6, //pos_bi_min
	0xff, //pos_bi_max
	0x04, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x10,
	0x00, //de_maxplus 11
	0x40,
	0x00, //de_maxminus 11
	0x40,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x10,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x08, //curve_y_1
	0x10, //curve_y_2
	0x18, //curve_y_3
	0x20, //curve_y_4
	0x28, //curve_y_5
	0x30, //curve_y_6
	0x38, //curve_y_7
	0x40, //curve_y_8
	0x48, //curve_y_9
	0x50, //curve_y_10
	0x58, //curve_y_11
	0x60, //curve_y_12
	0x68, //curve_y_13
	0x70, //curve_y_14
	0x78, //curve_y_15
	0x80, //curve_y_16
	0x88, //curve_y_17
	0x90, //curve_y_18
	0x98, //curve_y_19
	0xa0, //curve_y_20
	0xa8, //curve_y_21
	0xb0, //curve_y_22
	0xb8, //curve_y_23
	0xc0, //curve_y_24
	0xc8, //curve_y_25
	0xd0, //curve_y_26
	0xd8, //curve_y_27
	0xe0, //curve_y_28
	0xe8, //curve_y_29
	0xf0, //curve_y_30
	0xf8, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static char DSI0_VIDEO_NATURAL_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0xf0, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0xff, //trans_on trans_block 0 000 0000
	0x04, //trans_slope
	0x01, //trans_interval
	//end
};

static char DSI0_VIDEO_AUTO_MDNIE_1[] = {
	//start
	0xDF,
	0x01, //linear_on ascr_skin_on 0000 0000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xff, //ascr_skin_Rr
	0x60, //ascr_skin_Rg
	0x70, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xf7, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xf0, //ascr_Rr
	0xee, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xf7, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xff, //ascr_Wg
	0x00, //ascr_Kg
	0xff, //ascr_Wb
	0x00, //ascr_Kb
};

static char DSI0_VIDEO_AUTO_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x00, //slce_on cadrx_en 0000 0000
	0x00, //lce_gain 000 0000
	0x30, //lce_color_gain 00 0000
	0x01, //lce_min_ref_offset
	0x00,
	0x70, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x34,
	0x01, //lce_ref_gain 9
	0x40,
	0x66, //lce_block_size h v 0000 0000
	0x03, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x11, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x20,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x00, //lce_lg_flicker Avg pixel_cnt 000
	0x0a, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x00, //lce_lg_mix_weight 7
	0x10, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0x40,
	0x00, //cadrx_ui_illum_offset2
	0x50,
	0x00, //cadrx_ui_illum_offset3
	0x60,
	0x00, //cadrx_ui_illum_offset4
	0x70,
	0x00, //cadrx_ui_illum_slope1
	0x80,
	0x00, //cadrx_ui_illum_slope2
	0x80,
	0x00, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x40,
	0x01, //cadrx_ui_ref_offset2
	0x80,
	0x01, //cadrx_ui_ref_offset3
	0x80,
	0x01, //cadrx_ui_ref_offset4
	0x80,
	0x02, //cadrx_ui_ref_slope1
	0x00,
	0x00, //cadrx_ui_ref_slope2
	0x00,
	0x00, //cadrx_ui_ref_slope3
	0x00,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x00, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0xe6, //pos_bi_min
	0xff, //pos_bi_max
	0x0e, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x10,
	0x00, //de_maxplus 11
	0x40,
	0x00, //de_maxminus 11
	0x40,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x10,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x20,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x08, //curve_y_1
	0x10, //curve_y_2
	0x18, //curve_y_3
	0x20, //curve_y_4
	0x28, //curve_y_5
	0x30, //curve_y_6
	0x38, //curve_y_7
	0x40, //curve_y_8
	0x48, //curve_y_9
	0x50, //curve_y_10
	0x58, //curve_y_11
	0x60, //curve_y_12
	0x68, //curve_y_13
	0x70, //curve_y_14
	0x78, //curve_y_15
	0x80, //curve_y_16
	0x88, //curve_y_17
	0x90, //curve_y_18
	0x98, //curve_y_19
	0xa0, //curve_y_20
	0xa8, //curve_y_21
	0xb0, //curve_y_22
	0xb8, //curve_y_23
	0xc0, //curve_y_24
	0xc8, //curve_y_25
	0xd0, //curve_y_26
	0xd8, //curve_y_27
	0xe0, //curve_y_28
	0xe8, //curve_y_29
	0xf0, //curve_y_30
	0xf8, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static char DSI0_VIDEO_AUTO_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0xf0, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0xff, //trans_on trans_block 0 000 0000
	0x04, //trans_slope
	0x01, //trans_interval
	//end
};

static char DSI0_CAMERA_DYNAMIC_MDNIE_1[] = {
	//start
	0xDF,
	0x11, //linear_on ascr_skin_on 0000 0000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xe8, //ascr_skin_Rr
	0x1c, //ascr_skin_Rg
	0x00, //ascr_skin_Rb
	0xf0, //ascr_skin_Yr
	0xf2, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xf2, //ascr_skin_Mr
	0x18, //ascr_skin_Mg
	0xef, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xfc, //ascr_skin_Wg
	0xf6, //ascr_skin_Wb
	0x58, //ascr_Cr
	0xe8, //ascr_Rr
	0xf5, //ascr_Cg
	0x1c, //ascr_Rg
	0xf1, //ascr_Cb
	0x00, //ascr_Rb
	0xf2, //ascr_Mr
	0x38, //ascr_Gr
	0x18, //ascr_Mg
	0xff, //ascr_Gg
	0xef, //ascr_Mb
	0x00, //ascr_Gb
	0xf0, //ascr_Yr
	0x35, //ascr_Br
	0xf2, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xe8, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xfc, //ascr_Wg
	0x00, //ascr_Kg
	0xf6, //ascr_Wb
	0x00, //ascr_Kb
};

static char DSI0_CAMERA_DYNAMIC_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x00, //slce_on cadrx_en 0000 0000
	0x00, //lce_gain 000 0000
	0x30, //lce_color_gain 00 0000
	0x01, //lce_min_ref_offset
	0x00,
	0x70, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x34,
	0x01, //lce_ref_gain 9
	0x40,
	0x66, //lce_block_size h v 0000 0000
	0x03, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x11, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x20,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x00, //lce_lg_flicker Avg pixel_cnt 000
	0x0a, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x00, //lce_lg_mix_weight 7
	0x10, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0x40,
	0x00, //cadrx_ui_illum_offset2
	0x50,
	0x00, //cadrx_ui_illum_offset3
	0x60,
	0x00, //cadrx_ui_illum_offset4
	0x70,
	0x00, //cadrx_ui_illum_slope1
	0x80,
	0x00, //cadrx_ui_illum_slope2
	0x80,
	0x00, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x40,
	0x01, //cadrx_ui_ref_offset2
	0x80,
	0x01, //cadrx_ui_ref_offset3
	0x80,
	0x01, //cadrx_ui_ref_offset4
	0x80,
	0x02, //cadrx_ui_ref_slope1
	0x00,
	0x00, //cadrx_ui_ref_slope2
	0x00,
	0x00, //cadrx_ui_ref_slope3
	0x00,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x00, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0xe6, //pos_bi_min
	0xff, //pos_bi_max
	0x00, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x02, //de_maxplus 11
	0x00,
	0x02, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x10,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x08, //curve_y_1
	0x10, //curve_y_2
	0x18, //curve_y_3
	0x20, //curve_y_4
	0x28, //curve_y_5
	0x30, //curve_y_6
	0x38, //curve_y_7
	0x40, //curve_y_8
	0x48, //curve_y_9
	0x50, //curve_y_10
	0x58, //curve_y_11
	0x60, //curve_y_12
	0x68, //curve_y_13
	0x70, //curve_y_14
	0x78, //curve_y_15
	0x80, //curve_y_16
	0x88, //curve_y_17
	0x90, //curve_y_18
	0x98, //curve_y_19
	0xa0, //curve_y_20
	0xa8, //curve_y_21
	0xb0, //curve_y_22
	0xb8, //curve_y_23
	0xc0, //curve_y_24
	0xc8, //curve_y_25
	0xd0, //curve_y_26
	0xd8, //curve_y_27
	0xe0, //curve_y_28
	0xe8, //curve_y_29
	0xf0, //curve_y_30
	0xf8, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static char DSI0_CAMERA_DYNAMIC_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0xf0, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0xff, //trans_on trans_block 0 000 0000
	0x04, //trans_slope
	0x01, //trans_interval
	//end
};

static char DSI0_CAMERA_STANDARD_MDNIE_1[] = {
	//start
	0xDF,
	0x11, //linear_on ascr_skin_on 0000 0000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xff, //ascr_skin_Rr
	0x4e, //ascr_skin_Rg
	0x2e, //ascr_skin_Rb
	0xfa, //ascr_skin_Yr
	0xfa, //ascr_skin_Yg
	0x45, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x5d, //ascr_skin_Mg
	0xf5, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xfc, //ascr_skin_Wg
	0xf6, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xf5, //ascr_Cg
	0x4e, //ascr_Rg
	0xf5, //ascr_Cb
	0x2e, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x5d, //ascr_Mg
	0xf1, //ascr_Gg
	0xf5, //ascr_Mb
	0x33, //ascr_Gb
	0xfa, //ascr_Yr
	0x38, //ascr_Br
	0xfa, //ascr_Yg
	0x1e, //ascr_Bg
	0x45, //ascr_Yb
	0xf2, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xfc, //ascr_Wg
	0x00, //ascr_Kg
	0xf6, //ascr_Wb
	0x00, //ascr_Kb
};

static char DSI0_CAMERA_STANDARD_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x00, //slce_on cadrx_en 0000 0000
	0x00, //lce_gain 000 0000
	0x30, //lce_color_gain 00 0000
	0x01, //lce_min_ref_offset
	0x00,
	0x70, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x34,
	0x01, //lce_ref_gain 9
	0x40,
	0x66, //lce_block_size h v 0000 0000
	0x03, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x11, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x20,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x00, //lce_lg_flicker Avg pixel_cnt 000
	0x0a, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x00, //lce_lg_mix_weight 7
	0x10, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0x40,
	0x00, //cadrx_ui_illum_offset2
	0x50,
	0x00, //cadrx_ui_illum_offset3
	0x60,
	0x00, //cadrx_ui_illum_offset4
	0x70,
	0x00, //cadrx_ui_illum_slope1
	0x80,
	0x00, //cadrx_ui_illum_slope2
	0x80,
	0x00, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x40,
	0x01, //cadrx_ui_ref_offset2
	0x80,
	0x01, //cadrx_ui_ref_offset3
	0x80,
	0x01, //cadrx_ui_ref_offset4
	0x80,
	0x02, //cadrx_ui_ref_slope1
	0x00,
	0x00, //cadrx_ui_ref_slope2
	0x00,
	0x00, //cadrx_ui_ref_slope3
	0x00,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x00, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0xe6, //pos_bi_min
	0xff, //pos_bi_max
	0x02, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x02, //de_maxplus 11
	0x00,
	0x02, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x10,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x18,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x08, //curve_y_1
	0x10, //curve_y_2
	0x18, //curve_y_3
	0x20, //curve_y_4
	0x28, //curve_y_5
	0x30, //curve_y_6
	0x38, //curve_y_7
	0x40, //curve_y_8
	0x48, //curve_y_9
	0x50, //curve_y_10
	0x58, //curve_y_11
	0x60, //curve_y_12
	0x68, //curve_y_13
	0x70, //curve_y_14
	0x78, //curve_y_15
	0x80, //curve_y_16
	0x88, //curve_y_17
	0x90, //curve_y_18
	0x98, //curve_y_19
	0xa0, //curve_y_20
	0xa8, //curve_y_21
	0xb0, //curve_y_22
	0xb8, //curve_y_23
	0xc0, //curve_y_24
	0xc8, //curve_y_25
	0xd0, //curve_y_26
	0xd8, //curve_y_27
	0xe0, //curve_y_28
	0xe8, //curve_y_29
	0xf0, //curve_y_30
	0xf8, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static char DSI0_CAMERA_STANDARD_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0xf0, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0xff, //trans_on trans_block 0 000 0000
	0x04, //trans_slope
	0x01, //trans_interval
	//end
};

static char DSI0_CAMERA_NATURAL_MDNIE_1[] = {
	//start
	0xDF,
	0x11, //linear_on ascr_skin_on 0000 0000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xe1, //ascr_skin_Rr
	0x3d, //ascr_skin_Rg
	0x27, //ascr_skin_Rb
	0xfa, //ascr_skin_Yr
	0xfb, //ascr_skin_Yg
	0x57, //ascr_skin_Yb
	0xe6, //ascr_skin_Mr
	0x46, //ascr_skin_Mg
	0xf0, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xfc, //ascr_skin_Wg
	0xf6, //ascr_skin_Wb
	0x8f, //ascr_Cr
	0xe1, //ascr_Rr
	0xf8, //ascr_Cg
	0x3d, //ascr_Rg
	0xf5, //ascr_Cb
	0x27, //ascr_Rb
	0xe6, //ascr_Mr
	0x86, //ascr_Gr
	0x46, //ascr_Mg
	0xf5, //ascr_Gg
	0xf0, //ascr_Mb
	0x4f, //ascr_Gb
	0xfa, //ascr_Yr
	0x37, //ascr_Br
	0xfb, //ascr_Yg
	0x1f, //ascr_Bg
	0x57, //ascr_Yb
	0xed, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xfc, //ascr_Wg
	0x00, //ascr_Kg
	0xf6, //ascr_Wb
	0x00, //ascr_Kb
};

static char DSI0_CAMERA_NATURAL_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x00, //slce_on cadrx_en 0000 0000
	0x00, //lce_gain 000 0000
	0x30, //lce_color_gain 00 0000
	0x01, //lce_min_ref_offset
	0x00,
	0x70, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x34,
	0x01, //lce_ref_gain 9
	0x40,
	0x66, //lce_block_size h v 0000 0000
	0x03, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x11, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x20,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x00, //lce_lg_flicker Avg pixel_cnt 000
	0x0a, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x00, //lce_lg_mix_weight 7
	0x10, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0x40,
	0x00, //cadrx_ui_illum_offset2
	0x50,
	0x00, //cadrx_ui_illum_offset3
	0x60,
	0x00, //cadrx_ui_illum_offset4
	0x70,
	0x00, //cadrx_ui_illum_slope1
	0x80,
	0x00, //cadrx_ui_illum_slope2
	0x80,
	0x00, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x40,
	0x01, //cadrx_ui_ref_offset2
	0x80,
	0x01, //cadrx_ui_ref_offset3
	0x80,
	0x01, //cadrx_ui_ref_offset4
	0x80,
	0x02, //cadrx_ui_ref_slope1
	0x00,
	0x00, //cadrx_ui_ref_slope2
	0x00,
	0x00, //cadrx_ui_ref_slope3
	0x00,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x00, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0xe6, //pos_bi_min
	0xff, //pos_bi_max
	0x00, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x02, //de_maxplus 11
	0x00,
	0x02, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x10,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x08, //curve_y_1
	0x10, //curve_y_2
	0x18, //curve_y_3
	0x20, //curve_y_4
	0x28, //curve_y_5
	0x30, //curve_y_6
	0x38, //curve_y_7
	0x40, //curve_y_8
	0x48, //curve_y_9
	0x50, //curve_y_10
	0x58, //curve_y_11
	0x60, //curve_y_12
	0x68, //curve_y_13
	0x70, //curve_y_14
	0x78, //curve_y_15
	0x80, //curve_y_16
	0x88, //curve_y_17
	0x90, //curve_y_18
	0x98, //curve_y_19
	0xa0, //curve_y_20
	0xa8, //curve_y_21
	0xb0, //curve_y_22
	0xb8, //curve_y_23
	0xc0, //curve_y_24
	0xc8, //curve_y_25
	0xd0, //curve_y_26
	0xd8, //curve_y_27
	0xe0, //curve_y_28
	0xe8, //curve_y_29
	0xf0, //curve_y_30
	0xf8, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static char DSI0_CAMERA_NATURAL_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0xf0, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0xff, //trans_on trans_block 0 000 0000
	0x04, //trans_slope
	0x01, //trans_interval
	//end
};

static char DSI0_CAMERA_AUTO_MDNIE_1[] = {
	//start
	0xDF,
	0x01, //linear_on ascr_skin_on 0000 0000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xff, //ascr_skin_Rr
	0x60, //ascr_skin_Rg
	0x70, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xf7, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xf0, //ascr_Rr
	0xee, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xf7, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xff, //ascr_Wg
	0x00, //ascr_Kg
	0xff, //ascr_Wb
	0x00, //ascr_Kb
};

static char DSI0_CAMERA_AUTO_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x00, //slce_on cadrx_en 0000 0000
	0x00, //lce_gain 000 0000
	0x30, //lce_color_gain 00 0000
	0x01, //lce_min_ref_offset
	0x00,
	0x70, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x34,
	0x01, //lce_ref_gain 9
	0x40,
	0x66, //lce_block_size h v 0000 0000
	0x03, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x11, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x20,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x00, //lce_lg_flicker Avg pixel_cnt 000
	0x0a, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x00, //lce_lg_mix_weight 7
	0x10, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0x40,
	0x00, //cadrx_ui_illum_offset2
	0x50,
	0x00, //cadrx_ui_illum_offset3
	0x60,
	0x00, //cadrx_ui_illum_offset4
	0x70,
	0x00, //cadrx_ui_illum_slope1
	0x80,
	0x00, //cadrx_ui_illum_slope2
	0x80,
	0x00, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x40,
	0x01, //cadrx_ui_ref_offset2
	0x80,
	0x01, //cadrx_ui_ref_offset3
	0x80,
	0x01, //cadrx_ui_ref_offset4
	0x80,
	0x02, //cadrx_ui_ref_slope1
	0x00,
	0x00, //cadrx_ui_ref_slope2
	0x00,
	0x00, //cadrx_ui_ref_slope3
	0x00,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x00, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0xe6, //pos_bi_min
	0xff, //pos_bi_max
	0x00, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x02, //de_maxplus 11
	0x00,
	0x02, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x10,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x08, //curve_y_1
	0x10, //curve_y_2
	0x18, //curve_y_3
	0x20, //curve_y_4
	0x28, //curve_y_5
	0x30, //curve_y_6
	0x38, //curve_y_7
	0x40, //curve_y_8
	0x48, //curve_y_9
	0x50, //curve_y_10
	0x58, //curve_y_11
	0x60, //curve_y_12
	0x68, //curve_y_13
	0x70, //curve_y_14
	0x78, //curve_y_15
	0x80, //curve_y_16
	0x88, //curve_y_17
	0x90, //curve_y_18
	0x98, //curve_y_19
	0xa0, //curve_y_20
	0xa8, //curve_y_21
	0xb0, //curve_y_22
	0xb8, //curve_y_23
	0xc0, //curve_y_24
	0xc8, //curve_y_25
	0xd0, //curve_y_26
	0xd8, //curve_y_27
	0xe0, //curve_y_28
	0xe8, //curve_y_29
	0xf0, //curve_y_30
	0xf8, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static char DSI0_CAMERA_AUTO_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0xf0, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0xff, //trans_on trans_block 0 000 0000
	0x04, //trans_slope
	0x01, //trans_interval
	//end
};

static char DSI0_GALLERY_DYNAMIC_MDNIE_1[] = {
	//start
	0xDF,
	0x11, //linear_on ascr_skin_on 0000 0000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xe8, //ascr_skin_Rr
	0x1c, //ascr_skin_Rg
	0x00, //ascr_skin_Rb
	0xf0, //ascr_skin_Yr
	0xf2, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xf2, //ascr_skin_Mr
	0x18, //ascr_skin_Mg
	0xef, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xfc, //ascr_skin_Wg
	0xf6, //ascr_skin_Wb
	0x58, //ascr_Cr
	0xe8, //ascr_Rr
	0xf5, //ascr_Cg
	0x1c, //ascr_Rg
	0xf1, //ascr_Cb
	0x00, //ascr_Rb
	0xf2, //ascr_Mr
	0x38, //ascr_Gr
	0x18, //ascr_Mg
	0xff, //ascr_Gg
	0xef, //ascr_Mb
	0x00, //ascr_Gb
	0xf0, //ascr_Yr
	0x35, //ascr_Br
	0xf2, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xe8, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xfc, //ascr_Wg
	0x00, //ascr_Kg
	0xf6, //ascr_Wb
	0x00, //ascr_Kb
};

static char DSI0_GALLERY_DYNAMIC_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x00, //slce_on cadrx_en 0000 0000
	0x00, //lce_gain 000 0000
	0x30, //lce_color_gain 00 0000
	0x01, //lce_min_ref_offset
	0x00,
	0x70, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x34,
	0x01, //lce_ref_gain 9
	0x40,
	0x66, //lce_block_size h v 0000 0000
	0x03, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x11, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x20,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x00, //lce_lg_flicker Avg pixel_cnt 000
	0x0a, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x00, //lce_lg_mix_weight 7
	0x10, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0x40,
	0x00, //cadrx_ui_illum_offset2
	0x50,
	0x00, //cadrx_ui_illum_offset3
	0x60,
	0x00, //cadrx_ui_illum_offset4
	0x70,
	0x00, //cadrx_ui_illum_slope1
	0x80,
	0x00, //cadrx_ui_illum_slope2
	0x80,
	0x00, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x40,
	0x01, //cadrx_ui_ref_offset2
	0x80,
	0x01, //cadrx_ui_ref_offset3
	0x80,
	0x01, //cadrx_ui_ref_offset4
	0x80,
	0x02, //cadrx_ui_ref_slope1
	0x00,
	0x00, //cadrx_ui_ref_slope2
	0x00,
	0x00, //cadrx_ui_ref_slope3
	0x00,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x00, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0xe6, //pos_bi_min
	0xff, //pos_bi_max
	0x04, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x10,
	0x02, //de_maxplus 11
	0x00,
	0x02, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x10,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x08, //curve_y_1
	0x10, //curve_y_2
	0x18, //curve_y_3
	0x20, //curve_y_4
	0x28, //curve_y_5
	0x30, //curve_y_6
	0x38, //curve_y_7
	0x40, //curve_y_8
	0x48, //curve_y_9
	0x50, //curve_y_10
	0x58, //curve_y_11
	0x60, //curve_y_12
	0x68, //curve_y_13
	0x70, //curve_y_14
	0x78, //curve_y_15
	0x80, //curve_y_16
	0x88, //curve_y_17
	0x90, //curve_y_18
	0x98, //curve_y_19
	0xa0, //curve_y_20
	0xa8, //curve_y_21
	0xb0, //curve_y_22
	0xb8, //curve_y_23
	0xc0, //curve_y_24
	0xc8, //curve_y_25
	0xd0, //curve_y_26
	0xd8, //curve_y_27
	0xe0, //curve_y_28
	0xe8, //curve_y_29
	0xf0, //curve_y_30
	0xf8, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static char DSI0_GALLERY_DYNAMIC_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0xf0, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0xff, //trans_on trans_block 0 000 0000
	0x04, //trans_slope
	0x01, //trans_interval
	//end
};

static char DSI0_GALLERY_STANDARD_MDNIE_1[] = {
	//start
	0xDF,
	0x11, //linear_on ascr_skin_on 0000 0000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xff, //ascr_skin_Rr
	0x4e, //ascr_skin_Rg
	0x2e, //ascr_skin_Rb
	0xfa, //ascr_skin_Yr
	0xfa, //ascr_skin_Yg
	0x45, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x5d, //ascr_skin_Mg
	0xf5, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xfc, //ascr_skin_Wg
	0xf6, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xf5, //ascr_Cg
	0x4e, //ascr_Rg
	0xf5, //ascr_Cb
	0x2e, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x5d, //ascr_Mg
	0xf1, //ascr_Gg
	0xf5, //ascr_Mb
	0x33, //ascr_Gb
	0xfa, //ascr_Yr
	0x38, //ascr_Br
	0xfa, //ascr_Yg
	0x1e, //ascr_Bg
	0x45, //ascr_Yb
	0xf2, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xfc, //ascr_Wg
	0x00, //ascr_Kg
	0xf6, //ascr_Wb
	0x00, //ascr_Kb
};

static char DSI0_GALLERY_STANDARD_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x00, //slce_on cadrx_en 0000 0000
	0x00, //lce_gain 000 0000
	0x30, //lce_color_gain 00 0000
	0x01, //lce_min_ref_offset
	0x00,
	0x70, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x34,
	0x01, //lce_ref_gain 9
	0x40,
	0x66, //lce_block_size h v 0000 0000
	0x03, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x11, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x20,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x00, //lce_lg_flicker Avg pixel_cnt 000
	0x0a, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x00, //lce_lg_mix_weight 7
	0x10, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0x40,
	0x00, //cadrx_ui_illum_offset2
	0x50,
	0x00, //cadrx_ui_illum_offset3
	0x60,
	0x00, //cadrx_ui_illum_offset4
	0x70,
	0x00, //cadrx_ui_illum_slope1
	0x80,
	0x00, //cadrx_ui_illum_slope2
	0x80,
	0x00, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x40,
	0x01, //cadrx_ui_ref_offset2
	0x80,
	0x01, //cadrx_ui_ref_offset3
	0x80,
	0x01, //cadrx_ui_ref_offset4
	0x80,
	0x02, //cadrx_ui_ref_slope1
	0x00,
	0x00, //cadrx_ui_ref_slope2
	0x00,
	0x00, //cadrx_ui_ref_slope3
	0x00,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x00, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0xe6, //pos_bi_min
	0xff, //pos_bi_max
	0x06, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x10,
	0x02, //de_maxplus 11
	0x00,
	0x02, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x10,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x18,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x08, //curve_y_1
	0x10, //curve_y_2
	0x18, //curve_y_3
	0x20, //curve_y_4
	0x28, //curve_y_5
	0x30, //curve_y_6
	0x38, //curve_y_7
	0x40, //curve_y_8
	0x48, //curve_y_9
	0x50, //curve_y_10
	0x58, //curve_y_11
	0x60, //curve_y_12
	0x68, //curve_y_13
	0x70, //curve_y_14
	0x78, //curve_y_15
	0x80, //curve_y_16
	0x88, //curve_y_17
	0x90, //curve_y_18
	0x98, //curve_y_19
	0xa0, //curve_y_20
	0xa8, //curve_y_21
	0xb0, //curve_y_22
	0xb8, //curve_y_23
	0xc0, //curve_y_24
	0xc8, //curve_y_25
	0xd0, //curve_y_26
	0xd8, //curve_y_27
	0xe0, //curve_y_28
	0xe8, //curve_y_29
	0xf0, //curve_y_30
	0xf8, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static char DSI0_GALLERY_STANDARD_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0xf0, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0xff, //trans_on trans_block 0 000 0000
	0x04, //trans_slope
	0x01, //trans_interval
	//end
};

static char DSI0_GALLERY_NATURAL_MDNIE_1[] = {
	//start
	0xDF,
	0x11, //linear_on ascr_skin_on 0000 0000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xe1, //ascr_skin_Rr
	0x3d, //ascr_skin_Rg
	0x27, //ascr_skin_Rb
	0xfa, //ascr_skin_Yr
	0xfb, //ascr_skin_Yg
	0x57, //ascr_skin_Yb
	0xe6, //ascr_skin_Mr
	0x46, //ascr_skin_Mg
	0xf0, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xfc, //ascr_skin_Wg
	0xf6, //ascr_skin_Wb
	0x8f, //ascr_Cr
	0xe1, //ascr_Rr
	0xf8, //ascr_Cg
	0x3d, //ascr_Rg
	0xf5, //ascr_Cb
	0x27, //ascr_Rb
	0xe6, //ascr_Mr
	0x86, //ascr_Gr
	0x46, //ascr_Mg
	0xf5, //ascr_Gg
	0xf0, //ascr_Mb
	0x4f, //ascr_Gb
	0xfa, //ascr_Yr
	0x37, //ascr_Br
	0xfb, //ascr_Yg
	0x1f, //ascr_Bg
	0x57, //ascr_Yb
	0xed, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xfc, //ascr_Wg
	0x00, //ascr_Kg
	0xf6, //ascr_Wb
	0x00, //ascr_Kb
};

static char DSI0_GALLERY_NATURAL_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x00, //slce_on cadrx_en 0000 0000
	0x00, //lce_gain 000 0000
	0x30, //lce_color_gain 00 0000
	0x01, //lce_min_ref_offset
	0x00,
	0x70, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x34,
	0x01, //lce_ref_gain 9
	0x40,
	0x66, //lce_block_size h v 0000 0000
	0x03, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x11, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x20,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x00, //lce_lg_flicker Avg pixel_cnt 000
	0x0a, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x00, //lce_lg_mix_weight 7
	0x10, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0x40,
	0x00, //cadrx_ui_illum_offset2
	0x50,
	0x00, //cadrx_ui_illum_offset3
	0x60,
	0x00, //cadrx_ui_illum_offset4
	0x70,
	0x00, //cadrx_ui_illum_slope1
	0x80,
	0x00, //cadrx_ui_illum_slope2
	0x80,
	0x00, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x40,
	0x01, //cadrx_ui_ref_offset2
	0x80,
	0x01, //cadrx_ui_ref_offset3
	0x80,
	0x01, //cadrx_ui_ref_offset4
	0x80,
	0x02, //cadrx_ui_ref_slope1
	0x00,
	0x00, //cadrx_ui_ref_slope2
	0x00,
	0x00, //cadrx_ui_ref_slope3
	0x00,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x00, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0xe6, //pos_bi_min
	0xff, //pos_bi_max
	0x04, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x10,
	0x02, //de_maxplus 11
	0x00,
	0x02, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x10,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x08, //curve_y_1
	0x10, //curve_y_2
	0x18, //curve_y_3
	0x20, //curve_y_4
	0x28, //curve_y_5
	0x30, //curve_y_6
	0x38, //curve_y_7
	0x40, //curve_y_8
	0x48, //curve_y_9
	0x50, //curve_y_10
	0x58, //curve_y_11
	0x60, //curve_y_12
	0x68, //curve_y_13
	0x70, //curve_y_14
	0x78, //curve_y_15
	0x80, //curve_y_16
	0x88, //curve_y_17
	0x90, //curve_y_18
	0x98, //curve_y_19
	0xa0, //curve_y_20
	0xa8, //curve_y_21
	0xb0, //curve_y_22
	0xb8, //curve_y_23
	0xc0, //curve_y_24
	0xc8, //curve_y_25
	0xd0, //curve_y_26
	0xd8, //curve_y_27
	0xe0, //curve_y_28
	0xe8, //curve_y_29
	0xf0, //curve_y_30
	0xf8, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static char DSI0_GALLERY_NATURAL_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0xf0, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0xff, //trans_on trans_block 0 000 0000
	0x04, //trans_slope
	0x01, //trans_interval
	//end
};

static char DSI0_GALLERY_AUTO_MDNIE_1[] = {
	//start
	0xDF,
	0x01, //linear_on ascr_skin_on 0000 0000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xff, //ascr_skin_Rr
	0x60, //ascr_skin_Rg
	0x70, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xf7, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xf0, //ascr_Rr
	0xee, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xf7, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xff, //ascr_Wg
	0x00, //ascr_Kg
	0xff, //ascr_Wb
	0x00, //ascr_Kb
};

static char DSI0_GALLERY_AUTO_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x00, //slce_on cadrx_en 0000 0000
	0x00, //lce_gain 000 0000
	0x30, //lce_color_gain 00 0000
	0x01, //lce_min_ref_offset
	0x00,
	0x70, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x34,
	0x01, //lce_ref_gain 9
	0x40,
	0x66, //lce_block_size h v 0000 0000
	0x03, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x11, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x20,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x00, //lce_lg_flicker Avg pixel_cnt 000
	0x0a, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x00, //lce_lg_mix_weight 7
	0x10, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0x40,
	0x00, //cadrx_ui_illum_offset2
	0x50,
	0x00, //cadrx_ui_illum_offset3
	0x60,
	0x00, //cadrx_ui_illum_offset4
	0x70,
	0x00, //cadrx_ui_illum_slope1
	0x80,
	0x00, //cadrx_ui_illum_slope2
	0x80,
	0x00, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x40,
	0x01, //cadrx_ui_ref_offset2
	0x80,
	0x01, //cadrx_ui_ref_offset3
	0x80,
	0x01, //cadrx_ui_ref_offset4
	0x80,
	0x02, //cadrx_ui_ref_slope1
	0x00,
	0x00, //cadrx_ui_ref_slope2
	0x00,
	0x00, //cadrx_ui_ref_slope3
	0x00,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x00, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0xe6, //pos_bi_min
	0xff, //pos_bi_max
	0x0c, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x10,
	0x02, //de_maxplus 11
	0x00,
	0x02, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x10,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x08, //curve_y_1
	0x10, //curve_y_2
	0x18, //curve_y_3
	0x20, //curve_y_4
	0x28, //curve_y_5
	0x30, //curve_y_6
	0x38, //curve_y_7
	0x40, //curve_y_8
	0x48, //curve_y_9
	0x50, //curve_y_10
	0x58, //curve_y_11
	0x60, //curve_y_12
	0x68, //curve_y_13
	0x70, //curve_y_14
	0x78, //curve_y_15
	0x80, //curve_y_16
	0x88, //curve_y_17
	0x90, //curve_y_18
	0x98, //curve_y_19
	0xa0, //curve_y_20
	0xa8, //curve_y_21
	0xb0, //curve_y_22
	0xb8, //curve_y_23
	0xc0, //curve_y_24
	0xc8, //curve_y_25
	0xd0, //curve_y_26
	0xd8, //curve_y_27
	0xe0, //curve_y_28
	0xe8, //curve_y_29
	0xf0, //curve_y_30
	0xf8, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static char DSI0_GALLERY_AUTO_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0xf0, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0xff, //trans_on trans_block 0 000 0000
	0x04, //trans_slope
	0x01, //trans_interval
	//end
};

static char DSI0_BROWSER_DYNAMIC_MDNIE_1[] = {
	//start
	0xDF,
	0x11, //linear_on ascr_skin_on 0000 0000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xe8, //ascr_skin_Rr
	0x1c, //ascr_skin_Rg
	0x00, //ascr_skin_Rb
	0xf0, //ascr_skin_Yr
	0xf2, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xf2, //ascr_skin_Mr
	0x18, //ascr_skin_Mg
	0xef, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xfc, //ascr_skin_Wg
	0xf6, //ascr_skin_Wb
	0x58, //ascr_Cr
	0xe8, //ascr_Rr
	0xf5, //ascr_Cg
	0x1c, //ascr_Rg
	0xf1, //ascr_Cb
	0x00, //ascr_Rb
	0xf2, //ascr_Mr
	0x38, //ascr_Gr
	0x18, //ascr_Mg
	0xff, //ascr_Gg
	0xef, //ascr_Mb
	0x00, //ascr_Gb
	0xf0, //ascr_Yr
	0x35, //ascr_Br
	0xf2, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xe8, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xfc, //ascr_Wg
	0x00, //ascr_Kg
	0xf6, //ascr_Wb
	0x00, //ascr_Kb
};

static char DSI0_BROWSER_DYNAMIC_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x00, //slce_on cadrx_en 0000 0000
	0x00, //lce_gain 000 0000
	0x30, //lce_color_gain 00 0000
	0x01, //lce_min_ref_offset
	0x00,
	0x70, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x34,
	0x01, //lce_ref_gain 9
	0x40,
	0x66, //lce_block_size h v 0000 0000
	0x03, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x11, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x20,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x00, //lce_lg_flicker Avg pixel_cnt 000
	0x0a, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x00, //lce_lg_mix_weight 7
	0x10, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0x40,
	0x00, //cadrx_ui_illum_offset2
	0x50,
	0x00, //cadrx_ui_illum_offset3
	0x60,
	0x00, //cadrx_ui_illum_offset4
	0x70,
	0x00, //cadrx_ui_illum_slope1
	0x80,
	0x00, //cadrx_ui_illum_slope2
	0x80,
	0x00, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x40,
	0x01, //cadrx_ui_ref_offset2
	0x80,
	0x01, //cadrx_ui_ref_offset3
	0x80,
	0x01, //cadrx_ui_ref_offset4
	0x80,
	0x02, //cadrx_ui_ref_slope1
	0x00,
	0x00, //cadrx_ui_ref_slope2
	0x00,
	0x00, //cadrx_ui_ref_slope3
	0x00,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x00, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0xe6, //pos_bi_min
	0xff, //pos_bi_max
	0x00, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x02, //de_maxplus 11
	0x00,
	0x02, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x10,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x08, //curve_y_1
	0x10, //curve_y_2
	0x18, //curve_y_3
	0x20, //curve_y_4
	0x28, //curve_y_5
	0x30, //curve_y_6
	0x38, //curve_y_7
	0x40, //curve_y_8
	0x48, //curve_y_9
	0x50, //curve_y_10
	0x58, //curve_y_11
	0x60, //curve_y_12
	0x68, //curve_y_13
	0x70, //curve_y_14
	0x78, //curve_y_15
	0x80, //curve_y_16
	0x88, //curve_y_17
	0x90, //curve_y_18
	0x98, //curve_y_19
	0xa0, //curve_y_20
	0xa8, //curve_y_21
	0xb0, //curve_y_22
	0xb8, //curve_y_23
	0xc0, //curve_y_24
	0xc8, //curve_y_25
	0xd0, //curve_y_26
	0xd8, //curve_y_27
	0xe0, //curve_y_28
	0xe8, //curve_y_29
	0xf0, //curve_y_30
	0xf8, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static char DSI0_BROWSER_DYNAMIC_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0xf0, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0xff, //trans_on trans_block 0 000 0000
	0x04, //trans_slope
	0x01, //trans_interval
	//end
};

static char DSI0_BROWSER_STANDARD_MDNIE_1[] = {
	//start
	0xDF,
	0x11, //linear_on ascr_skin_on 0000 0000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xff, //ascr_skin_Rr
	0x4e, //ascr_skin_Rg
	0x2e, //ascr_skin_Rb
	0xfa, //ascr_skin_Yr
	0xfa, //ascr_skin_Yg
	0x45, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x5d, //ascr_skin_Mg
	0xf5, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xfc, //ascr_skin_Wg
	0xf6, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xf5, //ascr_Cg
	0x4e, //ascr_Rg
	0xf5, //ascr_Cb
	0x2e, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x5d, //ascr_Mg
	0xf1, //ascr_Gg
	0xf5, //ascr_Mb
	0x33, //ascr_Gb
	0xfa, //ascr_Yr
	0x38, //ascr_Br
	0xfa, //ascr_Yg
	0x1e, //ascr_Bg
	0x45, //ascr_Yb
	0xf2, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xfc, //ascr_Wg
	0x00, //ascr_Kg
	0xf6, //ascr_Wb
	0x00, //ascr_Kb
};

static char DSI0_BROWSER_STANDARD_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x00, //slce_on cadrx_en 0000 0000
	0x00, //lce_gain 000 0000
	0x30, //lce_color_gain 00 0000
	0x01, //lce_min_ref_offset
	0x00,
	0x70, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x34,
	0x01, //lce_ref_gain 9
	0x40,
	0x66, //lce_block_size h v 0000 0000
	0x03, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x11, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x20,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x00, //lce_lg_flicker Avg pixel_cnt 000
	0x0a, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x00, //lce_lg_mix_weight 7
	0x10, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0x40,
	0x00, //cadrx_ui_illum_offset2
	0x50,
	0x00, //cadrx_ui_illum_offset3
	0x60,
	0x00, //cadrx_ui_illum_offset4
	0x70,
	0x00, //cadrx_ui_illum_slope1
	0x80,
	0x00, //cadrx_ui_illum_slope2
	0x80,
	0x00, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x40,
	0x01, //cadrx_ui_ref_offset2
	0x80,
	0x01, //cadrx_ui_ref_offset3
	0x80,
	0x01, //cadrx_ui_ref_offset4
	0x80,
	0x02, //cadrx_ui_ref_slope1
	0x00,
	0x00, //cadrx_ui_ref_slope2
	0x00,
	0x00, //cadrx_ui_ref_slope3
	0x00,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x00, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0xe6, //pos_bi_min
	0xff, //pos_bi_max
	0x02, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x02, //de_maxplus 11
	0x00,
	0x02, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x10,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x18,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x08, //curve_y_1
	0x10, //curve_y_2
	0x18, //curve_y_3
	0x20, //curve_y_4
	0x28, //curve_y_5
	0x30, //curve_y_6
	0x38, //curve_y_7
	0x40, //curve_y_8
	0x48, //curve_y_9
	0x50, //curve_y_10
	0x58, //curve_y_11
	0x60, //curve_y_12
	0x68, //curve_y_13
	0x70, //curve_y_14
	0x78, //curve_y_15
	0x80, //curve_y_16
	0x88, //curve_y_17
	0x90, //curve_y_18
	0x98, //curve_y_19
	0xa0, //curve_y_20
	0xa8, //curve_y_21
	0xb0, //curve_y_22
	0xb8, //curve_y_23
	0xc0, //curve_y_24
	0xc8, //curve_y_25
	0xd0, //curve_y_26
	0xd8, //curve_y_27
	0xe0, //curve_y_28
	0xe8, //curve_y_29
	0xf0, //curve_y_30
	0xf8, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static char DSI0_BROWSER_STANDARD_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0xf0, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0xff, //trans_on trans_block 0 000 0000
	0x04, //trans_slope
	0x01, //trans_interval
	//end
};

static char DSI0_BROWSER_NATURAL_MDNIE_1[] = {
	//start
	0xDF,
	0x11, //linear_on ascr_skin_on 0000 0000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xe1, //ascr_skin_Rr
	0x3d, //ascr_skin_Rg
	0x27, //ascr_skin_Rb
	0xfa, //ascr_skin_Yr
	0xfb, //ascr_skin_Yg
	0x57, //ascr_skin_Yb
	0xe6, //ascr_skin_Mr
	0x46, //ascr_skin_Mg
	0xf0, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xfc, //ascr_skin_Wg
	0xf6, //ascr_skin_Wb
	0x8f, //ascr_Cr
	0xe1, //ascr_Rr
	0xf8, //ascr_Cg
	0x3d, //ascr_Rg
	0xf5, //ascr_Cb
	0x27, //ascr_Rb
	0xe6, //ascr_Mr
	0x86, //ascr_Gr
	0x46, //ascr_Mg
	0xf5, //ascr_Gg
	0xf0, //ascr_Mb
	0x4f, //ascr_Gb
	0xfa, //ascr_Yr
	0x37, //ascr_Br
	0xfb, //ascr_Yg
	0x1f, //ascr_Bg
	0x57, //ascr_Yb
	0xed, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xfc, //ascr_Wg
	0x00, //ascr_Kg
	0xf6, //ascr_Wb
	0x00, //ascr_Kb
};

static char DSI0_BROWSER_NATURAL_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x00, //slce_on cadrx_en 0000 0000
	0x00, //lce_gain 000 0000
	0x30, //lce_color_gain 00 0000
	0x01, //lce_min_ref_offset
	0x00,
	0x70, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x34,
	0x01, //lce_ref_gain 9
	0x40,
	0x66, //lce_block_size h v 0000 0000
	0x03, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x11, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x20,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x00, //lce_lg_flicker Avg pixel_cnt 000
	0x0a, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x00, //lce_lg_mix_weight 7
	0x10, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0x40,
	0x00, //cadrx_ui_illum_offset2
	0x50,
	0x00, //cadrx_ui_illum_offset3
	0x60,
	0x00, //cadrx_ui_illum_offset4
	0x70,
	0x00, //cadrx_ui_illum_slope1
	0x80,
	0x00, //cadrx_ui_illum_slope2
	0x80,
	0x00, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x40,
	0x01, //cadrx_ui_ref_offset2
	0x80,
	0x01, //cadrx_ui_ref_offset3
	0x80,
	0x01, //cadrx_ui_ref_offset4
	0x80,
	0x02, //cadrx_ui_ref_slope1
	0x00,
	0x00, //cadrx_ui_ref_slope2
	0x00,
	0x00, //cadrx_ui_ref_slope3
	0x00,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x00, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0xe6, //pos_bi_min
	0xff, //pos_bi_max
	0x00, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x02, //de_maxplus 11
	0x00,
	0x02, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x10,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x08, //curve_y_1
	0x10, //curve_y_2
	0x18, //curve_y_3
	0x20, //curve_y_4
	0x28, //curve_y_5
	0x30, //curve_y_6
	0x38, //curve_y_7
	0x40, //curve_y_8
	0x48, //curve_y_9
	0x50, //curve_y_10
	0x58, //curve_y_11
	0x60, //curve_y_12
	0x68, //curve_y_13
	0x70, //curve_y_14
	0x78, //curve_y_15
	0x80, //curve_y_16
	0x88, //curve_y_17
	0x90, //curve_y_18
	0x98, //curve_y_19
	0xa0, //curve_y_20
	0xa8, //curve_y_21
	0xb0, //curve_y_22
	0xb8, //curve_y_23
	0xc0, //curve_y_24
	0xc8, //curve_y_25
	0xd0, //curve_y_26
	0xd8, //curve_y_27
	0xe0, //curve_y_28
	0xe8, //curve_y_29
	0xf0, //curve_y_30
	0xf8, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static char DSI0_BROWSER_NATURAL_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0xf0, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0xff, //trans_on trans_block 0 000 0000
	0x04, //trans_slope
	0x01, //trans_interval
	//end
};

static char DSI0_BROWSER_AUTO_MDNIE_1[] = {
	//start
	0xDF,
	0x01, //linear_on ascr_skin_on 0000 0000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xff, //ascr_skin_Rr
	0x60, //ascr_skin_Rg
	0x70, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xf7, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xf0, //ascr_Rr
	0xee, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xf7, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xff, //ascr_Wg
	0x00, //ascr_Kg
	0xff, //ascr_Wb
	0x00, //ascr_Kb
};

static char DSI0_BROWSER_AUTO_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x00, //slce_on cadrx_en 0000 0000
	0x00, //lce_gain 000 0000
	0x30, //lce_color_gain 00 0000
	0x01, //lce_min_ref_offset
	0x00,
	0x70, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x34,
	0x01, //lce_ref_gain 9
	0x40,
	0x66, //lce_block_size h v 0000 0000
	0x03, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x11, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x20,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x00, //lce_lg_flicker Avg pixel_cnt 000
	0x0a, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x00, //lce_lg_mix_weight 7
	0x10, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0x40,
	0x00, //cadrx_ui_illum_offset2
	0x50,
	0x00, //cadrx_ui_illum_offset3
	0x60,
	0x00, //cadrx_ui_illum_offset4
	0x70,
	0x00, //cadrx_ui_illum_slope1
	0x80,
	0x00, //cadrx_ui_illum_slope2
	0x80,
	0x00, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x40,
	0x01, //cadrx_ui_ref_offset2
	0x80,
	0x01, //cadrx_ui_ref_offset3
	0x80,
	0x01, //cadrx_ui_ref_offset4
	0x80,
	0x02, //cadrx_ui_ref_slope1
	0x00,
	0x00, //cadrx_ui_ref_slope2
	0x00,
	0x00, //cadrx_ui_ref_slope3
	0x00,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x00, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0xe6, //pos_bi_min
	0xff, //pos_bi_max
	0x00, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x02, //de_maxplus 11
	0x00,
	0x02, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x10,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x08, //curve_y_1
	0x10, //curve_y_2
	0x18, //curve_y_3
	0x20, //curve_y_4
	0x28, //curve_y_5
	0x30, //curve_y_6
	0x38, //curve_y_7
	0x40, //curve_y_8
	0x48, //curve_y_9
	0x50, //curve_y_10
	0x58, //curve_y_11
	0x60, //curve_y_12
	0x68, //curve_y_13
	0x70, //curve_y_14
	0x78, //curve_y_15
	0x80, //curve_y_16
	0x88, //curve_y_17
	0x90, //curve_y_18
	0x98, //curve_y_19
	0xa0, //curve_y_20
	0xa8, //curve_y_21
	0xb0, //curve_y_22
	0xb8, //curve_y_23
	0xc0, //curve_y_24
	0xc8, //curve_y_25
	0xd0, //curve_y_26
	0xd8, //curve_y_27
	0xe0, //curve_y_28
	0xe8, //curve_y_29
	0xf0, //curve_y_30
	0xf8, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static char DSI0_BROWSER_AUTO_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0xf0, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0xff, //trans_on trans_block 0 000 0000
	0x04, //trans_slope
	0x01, //trans_interval
	//end
};

static char DSI0_EBOOK_DYNAMIC_MDNIE_1[] = {
	//start
	0xDF,
	0x11, //linear_on ascr_skin_on 0000 0000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xe8, //ascr_skin_Rr
	0x1c, //ascr_skin_Rg
	0x00, //ascr_skin_Rb
	0xf0, //ascr_skin_Yr
	0xf2, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xf2, //ascr_skin_Mr
	0x18, //ascr_skin_Mg
	0xef, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xfc, //ascr_skin_Wg
	0xf6, //ascr_skin_Wb
	0x58, //ascr_Cr
	0xe8, //ascr_Rr
	0xf5, //ascr_Cg
	0x1c, //ascr_Rg
	0xf1, //ascr_Cb
	0x00, //ascr_Rb
	0xf2, //ascr_Mr
	0x38, //ascr_Gr
	0x18, //ascr_Mg
	0xff, //ascr_Gg
	0xef, //ascr_Mb
	0x00, //ascr_Gb
	0xf0, //ascr_Yr
	0x35, //ascr_Br
	0xf2, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xe8, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xfc, //ascr_Wg
	0x00, //ascr_Kg
	0xf6, //ascr_Wb
	0x00, //ascr_Kb
};

static char DSI0_EBOOK_DYNAMIC_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x00, //slce_on cadrx_en 0000 0000
	0x00, //lce_gain 000 0000
	0x30, //lce_color_gain 00 0000
	0x01, //lce_min_ref_offset
	0x00,
	0x70, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x34,
	0x01, //lce_ref_gain 9
	0x40,
	0x66, //lce_block_size h v 0000 0000
	0x03, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x11, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x20,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x00, //lce_lg_flicker Avg pixel_cnt 000
	0x0a, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x00, //lce_lg_mix_weight 7
	0x10, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0x40,
	0x00, //cadrx_ui_illum_offset2
	0x50,
	0x00, //cadrx_ui_illum_offset3
	0x60,
	0x00, //cadrx_ui_illum_offset4
	0x70,
	0x00, //cadrx_ui_illum_slope1
	0x80,
	0x00, //cadrx_ui_illum_slope2
	0x80,
	0x00, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x40,
	0x01, //cadrx_ui_ref_offset2
	0x80,
	0x01, //cadrx_ui_ref_offset3
	0x80,
	0x01, //cadrx_ui_ref_offset4
	0x80,
	0x02, //cadrx_ui_ref_slope1
	0x00,
	0x00, //cadrx_ui_ref_slope2
	0x00,
	0x00, //cadrx_ui_ref_slope3
	0x00,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x00, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0xe6, //pos_bi_min
	0xff, //pos_bi_max
	0x00, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x02, //de_maxplus 11
	0x00,
	0x02, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x10,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x08, //curve_y_1
	0x10, //curve_y_2
	0x18, //curve_y_3
	0x20, //curve_y_4
	0x28, //curve_y_5
	0x30, //curve_y_6
	0x38, //curve_y_7
	0x40, //curve_y_8
	0x48, //curve_y_9
	0x50, //curve_y_10
	0x58, //curve_y_11
	0x60, //curve_y_12
	0x68, //curve_y_13
	0x70, //curve_y_14
	0x78, //curve_y_15
	0x80, //curve_y_16
	0x88, //curve_y_17
	0x90, //curve_y_18
	0x98, //curve_y_19
	0xa0, //curve_y_20
	0xa8, //curve_y_21
	0xb0, //curve_y_22
	0xb8, //curve_y_23
	0xc0, //curve_y_24
	0xc8, //curve_y_25
	0xd0, //curve_y_26
	0xd8, //curve_y_27
	0xe0, //curve_y_28
	0xe8, //curve_y_29
	0xf0, //curve_y_30
	0xf8, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static char DSI0_EBOOK_DYNAMIC_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0xf0, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0xff, //trans_on trans_block 0 000 0000
	0x04, //trans_slope
	0x01, //trans_interval
	//end
};

static char DSI0_EBOOK_STANDARD_MDNIE_1[] = {
	//start
	0xDF,
	0x11, //linear_on ascr_skin_on 0000 0000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xff, //ascr_skin_Rr
	0x4e, //ascr_skin_Rg
	0x2e, //ascr_skin_Rb
	0xfa, //ascr_skin_Yr
	0xfa, //ascr_skin_Yg
	0x45, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x5d, //ascr_skin_Mg
	0xf5, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xfc, //ascr_skin_Wg
	0xf6, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xf5, //ascr_Cg
	0x4e, //ascr_Rg
	0xf5, //ascr_Cb
	0x2e, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x5d, //ascr_Mg
	0xf1, //ascr_Gg
	0xf5, //ascr_Mb
	0x33, //ascr_Gb
	0xfa, //ascr_Yr
	0x38, //ascr_Br
	0xfa, //ascr_Yg
	0x1e, //ascr_Bg
	0x45, //ascr_Yb
	0xf2, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xfc, //ascr_Wg
	0x00, //ascr_Kg
	0xf6, //ascr_Wb
	0x00, //ascr_Kb
};

static char DSI0_EBOOK_STANDARD_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x00, //slce_on cadrx_en 0000 0000
	0x00, //lce_gain 000 0000
	0x30, //lce_color_gain 00 0000
	0x01, //lce_min_ref_offset
	0x00,
	0x70, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x34,
	0x01, //lce_ref_gain 9
	0x40,
	0x66, //lce_block_size h v 0000 0000
	0x03, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x11, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x20,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x00, //lce_lg_flicker Avg pixel_cnt 000
	0x0a, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x00, //lce_lg_mix_weight 7
	0x10, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0x40,
	0x00, //cadrx_ui_illum_offset2
	0x50,
	0x00, //cadrx_ui_illum_offset3
	0x60,
	0x00, //cadrx_ui_illum_offset4
	0x70,
	0x00, //cadrx_ui_illum_slope1
	0x80,
	0x00, //cadrx_ui_illum_slope2
	0x80,
	0x00, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x40,
	0x01, //cadrx_ui_ref_offset2
	0x80,
	0x01, //cadrx_ui_ref_offset3
	0x80,
	0x01, //cadrx_ui_ref_offset4
	0x80,
	0x02, //cadrx_ui_ref_slope1
	0x00,
	0x00, //cadrx_ui_ref_slope2
	0x00,
	0x00, //cadrx_ui_ref_slope3
	0x00,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x00, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0xe6, //pos_bi_min
	0xff, //pos_bi_max
	0x02, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x02, //de_maxplus 11
	0x00,
	0x02, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x10,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x18,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x08, //curve_y_1
	0x10, //curve_y_2
	0x18, //curve_y_3
	0x20, //curve_y_4
	0x28, //curve_y_5
	0x30, //curve_y_6
	0x38, //curve_y_7
	0x40, //curve_y_8
	0x48, //curve_y_9
	0x50, //curve_y_10
	0x58, //curve_y_11
	0x60, //curve_y_12
	0x68, //curve_y_13
	0x70, //curve_y_14
	0x78, //curve_y_15
	0x80, //curve_y_16
	0x88, //curve_y_17
	0x90, //curve_y_18
	0x98, //curve_y_19
	0xa0, //curve_y_20
	0xa8, //curve_y_21
	0xb0, //curve_y_22
	0xb8, //curve_y_23
	0xc0, //curve_y_24
	0xc8, //curve_y_25
	0xd0, //curve_y_26
	0xd8, //curve_y_27
	0xe0, //curve_y_28
	0xe8, //curve_y_29
	0xf0, //curve_y_30
	0xf8, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static char DSI0_EBOOK_STANDARD_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0xf0, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0xff, //trans_on trans_block 0 000 0000
	0x04, //trans_slope
	0x01, //trans_interval
	//end
};

static char DSI0_EBOOK_NATURAL_MDNIE_1[] = {
	//start
	0xDF,
	0x11, //linear_on ascr_skin_on 0000 0000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xe1, //ascr_skin_Rr
	0x3d, //ascr_skin_Rg
	0x27, //ascr_skin_Rb
	0xfa, //ascr_skin_Yr
	0xfb, //ascr_skin_Yg
	0x57, //ascr_skin_Yb
	0xe6, //ascr_skin_Mr
	0x46, //ascr_skin_Mg
	0xf0, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xfc, //ascr_skin_Wg
	0xf6, //ascr_skin_Wb
	0x8f, //ascr_Cr
	0xe1, //ascr_Rr
	0xf8, //ascr_Cg
	0x3d, //ascr_Rg
	0xf5, //ascr_Cb
	0x27, //ascr_Rb
	0xe6, //ascr_Mr
	0x86, //ascr_Gr
	0x46, //ascr_Mg
	0xf5, //ascr_Gg
	0xf0, //ascr_Mb
	0x4f, //ascr_Gb
	0xfa, //ascr_Yr
	0x37, //ascr_Br
	0xfb, //ascr_Yg
	0x1f, //ascr_Bg
	0x57, //ascr_Yb
	0xed, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xfc, //ascr_Wg
	0x00, //ascr_Kg
	0xf6, //ascr_Wb
	0x00, //ascr_Kb
};

static char DSI0_EBOOK_NATURAL_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x00, //slce_on cadrx_en 0000 0000
	0x00, //lce_gain 000 0000
	0x30, //lce_color_gain 00 0000
	0x01, //lce_min_ref_offset
	0x00,
	0x70, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x34,
	0x01, //lce_ref_gain 9
	0x40,
	0x66, //lce_block_size h v 0000 0000
	0x03, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x11, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x20,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x00, //lce_lg_flicker Avg pixel_cnt 000
	0x0a, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x00, //lce_lg_mix_weight 7
	0x10, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0x40,
	0x00, //cadrx_ui_illum_offset2
	0x50,
	0x00, //cadrx_ui_illum_offset3
	0x60,
	0x00, //cadrx_ui_illum_offset4
	0x70,
	0x00, //cadrx_ui_illum_slope1
	0x80,
	0x00, //cadrx_ui_illum_slope2
	0x80,
	0x00, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x40,
	0x01, //cadrx_ui_ref_offset2
	0x80,
	0x01, //cadrx_ui_ref_offset3
	0x80,
	0x01, //cadrx_ui_ref_offset4
	0x80,
	0x02, //cadrx_ui_ref_slope1
	0x00,
	0x00, //cadrx_ui_ref_slope2
	0x00,
	0x00, //cadrx_ui_ref_slope3
	0x00,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x00, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0xe6, //pos_bi_min
	0xff, //pos_bi_max
	0x00, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x02, //de_maxplus 11
	0x00,
	0x02, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x10,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x08, //curve_y_1
	0x10, //curve_y_2
	0x18, //curve_y_3
	0x20, //curve_y_4
	0x28, //curve_y_5
	0x30, //curve_y_6
	0x38, //curve_y_7
	0x40, //curve_y_8
	0x48, //curve_y_9
	0x50, //curve_y_10
	0x58, //curve_y_11
	0x60, //curve_y_12
	0x68, //curve_y_13
	0x70, //curve_y_14
	0x78, //curve_y_15
	0x80, //curve_y_16
	0x88, //curve_y_17
	0x90, //curve_y_18
	0x98, //curve_y_19
	0xa0, //curve_y_20
	0xa8, //curve_y_21
	0xb0, //curve_y_22
	0xb8, //curve_y_23
	0xc0, //curve_y_24
	0xc8, //curve_y_25
	0xd0, //curve_y_26
	0xd8, //curve_y_27
	0xe0, //curve_y_28
	0xe8, //curve_y_29
	0xf0, //curve_y_30
	0xf8, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static char DSI0_EBOOK_NATURAL_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0xf0, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0xff, //trans_on trans_block 0 000 0000
	0x04, //trans_slope
	0x01, //trans_interval
	//end
};

static char DSI0_EBOOK_AUTO_MDNIE_1[] = {
	//start
	0xDF,
	0x01, //linear_on ascr_skin_on 0000 0000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xff, //ascr_skin_Rr
	0x00, //ascr_skin_Rg
	0x00, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xf7, //ascr_skin_Wg
	0xe5, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xff, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xf7, //ascr_Wg
	0x00, //ascr_Kg
	0xe5, //ascr_Wb
	0x00, //ascr_Kb
};

static char DSI0_EBOOK_AUTO_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x00, //slce_on cadrx_en 0000 0000
	0x00, //lce_gain 000 0000
	0x30, //lce_color_gain 00 0000
	0x01, //lce_min_ref_offset
	0x00,
	0x70, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x34,
	0x01, //lce_ref_gain 9
	0x40,
	0x66, //lce_block_size h v 0000 0000
	0x03, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x11, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x20,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x00, //lce_lg_flicker Avg pixel_cnt 000
	0x0a, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x00, //lce_lg_mix_weight 7
	0x10, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0x40,
	0x00, //cadrx_ui_illum_offset2
	0x50,
	0x00, //cadrx_ui_illum_offset3
	0x60,
	0x00, //cadrx_ui_illum_offset4
	0x70,
	0x00, //cadrx_ui_illum_slope1
	0x80,
	0x00, //cadrx_ui_illum_slope2
	0x80,
	0x00, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x40,
	0x01, //cadrx_ui_ref_offset2
	0x80,
	0x01, //cadrx_ui_ref_offset3
	0x80,
	0x01, //cadrx_ui_ref_offset4
	0x80,
	0x02, //cadrx_ui_ref_slope1
	0x00,
	0x00, //cadrx_ui_ref_slope2
	0x00,
	0x00, //cadrx_ui_ref_slope3
	0x00,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x00, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0xe6, //pos_bi_min
	0xff, //pos_bi_max
	0x00, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x02, //de_maxplus 11
	0x00,
	0x02, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x10,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x08, //curve_y_1
	0x10, //curve_y_2
	0x18, //curve_y_3
	0x20, //curve_y_4
	0x28, //curve_y_5
	0x30, //curve_y_6
	0x38, //curve_y_7
	0x40, //curve_y_8
	0x48, //curve_y_9
	0x50, //curve_y_10
	0x58, //curve_y_11
	0x60, //curve_y_12
	0x68, //curve_y_13
	0x70, //curve_y_14
	0x78, //curve_y_15
	0x80, //curve_y_16
	0x88, //curve_y_17
	0x90, //curve_y_18
	0x98, //curve_y_19
	0xa0, //curve_y_20
	0xa8, //curve_y_21
	0xb0, //curve_y_22
	0xb8, //curve_y_23
	0xc0, //curve_y_24
	0xc8, //curve_y_25
	0xd0, //curve_y_26
	0xd8, //curve_y_27
	0xe0, //curve_y_28
	0xe8, //curve_y_29
	0xf0, //curve_y_30
	0xf8, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static char DSI0_EBOOK_AUTO_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0xf0, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0xff, //trans_on trans_block 0 000 0000
	0x04, //trans_slope
	0x01, //trans_interval
	//end
};

static char DSI0_EMAIL_AUTO_MDNIE_1[] = {
	//start
	0xDF,
	0x01, //linear_on ascr_skin_on 0000 0000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xff, //ascr_skin_Rr
	0x00, //ascr_skin_Rg
	0x00, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xfb, //ascr_skin_Wg
	0xee, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xff, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xfb, //ascr_Wg
	0x00, //ascr_Kg
	0xee, //ascr_Wb
	0x00, //ascr_Kb
};

static char DSI0_EMAIL_AUTO_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x00, //slce_on cadrx_en 0000 0000
	0x00, //lce_gain 000 0000
	0x30, //lce_color_gain 00 0000
	0x01, //lce_min_ref_offset
	0x00,
	0x70, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x34,
	0x01, //lce_ref_gain 9
	0x40,
	0x66, //lce_block_size h v 0000 0000
	0x03, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x11, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x20,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x00, //lce_lg_flicker Avg pixel_cnt 000
	0x0a, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x00, //lce_lg_mix_weight 7
	0x10, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0x40,
	0x00, //cadrx_ui_illum_offset2
	0x50,
	0x00, //cadrx_ui_illum_offset3
	0x60,
	0x00, //cadrx_ui_illum_offset4
	0x70,
	0x00, //cadrx_ui_illum_slope1
	0x80,
	0x00, //cadrx_ui_illum_slope2
	0x80,
	0x00, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x40,
	0x01, //cadrx_ui_ref_offset2
	0x80,
	0x01, //cadrx_ui_ref_offset3
	0x80,
	0x01, //cadrx_ui_ref_offset4
	0x80,
	0x02, //cadrx_ui_ref_slope1
	0x00,
	0x00, //cadrx_ui_ref_slope2
	0x00,
	0x00, //cadrx_ui_ref_slope3
	0x00,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x00, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0xe6, //pos_bi_min
	0xff, //pos_bi_max
	0x00, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x02, //de_maxplus 11
	0x00,
	0x02, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x10,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x08, //curve_y_1
	0x10, //curve_y_2
	0x18, //curve_y_3
	0x20, //curve_y_4
	0x28, //curve_y_5
	0x30, //curve_y_6
	0x38, //curve_y_7
	0x40, //curve_y_8
	0x48, //curve_y_9
	0x50, //curve_y_10
	0x58, //curve_y_11
	0x60, //curve_y_12
	0x68, //curve_y_13
	0x70, //curve_y_14
	0x78, //curve_y_15
	0x80, //curve_y_16
	0x88, //curve_y_17
	0x90, //curve_y_18
	0x98, //curve_y_19
	0xa0, //curve_y_20
	0xa8, //curve_y_21
	0xb0, //curve_y_22
	0xb8, //curve_y_23
	0xc0, //curve_y_24
	0xc8, //curve_y_25
	0xd0, //curve_y_26
	0xd8, //curve_y_27
	0xe0, //curve_y_28
	0xe8, //curve_y_29
	0xf0, //curve_y_30
	0xf8, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static char DSI0_EMAIL_AUTO_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0xf0, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0xff, //trans_on trans_block 0 000 0000
	0x04, //trans_slope
	0x01, //trans_interval
	//end
};

static char DSI0_TDMB_STANDARD_MDNIE_1[] = {
	//start
	0xDF,
	0x11, //linear_on ascr_skin_on 0000 0000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xff, //ascr_skin_Rr
	0x4e, //ascr_skin_Rg
	0x2e, //ascr_skin_Rb
	0xfa, //ascr_skin_Yr
	0xfa, //ascr_skin_Yg
	0x45, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x5d, //ascr_skin_Mg
	0xf5, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xfc, //ascr_skin_Wg
	0xf6, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xf5, //ascr_Cg
	0x4e, //ascr_Rg
	0xf5, //ascr_Cb
	0x2e, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x5d, //ascr_Mg
	0xf1, //ascr_Gg
	0xf5, //ascr_Mb
	0x33, //ascr_Gb
	0xfa, //ascr_Yr
	0x38, //ascr_Br
	0xfa, //ascr_Yg
	0x1e, //ascr_Bg
	0x45, //ascr_Yb
	0xf2, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xfc, //ascr_Wg
	0x00, //ascr_Kg
	0xf6, //ascr_Wb
	0x00, //ascr_Kb
};

static char DSI0_TDMB_STANDARD_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x00, //slce_on cadrx_en 0000 0000
	0x00, //lce_gain 000 0000
	0x30, //lce_color_gain 00 0000
	0x01, //lce_min_ref_offset
	0x00,
	0x70, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x34,
	0x01, //lce_ref_gain 9
	0x40,
	0x66, //lce_block_size h v 0000 0000
	0x03, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x11, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x20,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x00, //lce_lg_flicker Avg pixel_cnt 000
	0x0a, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x00, //lce_lg_mix_weight 7
	0x10, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0x40,
	0x00, //cadrx_ui_illum_offset2
	0x50,
	0x00, //cadrx_ui_illum_offset3
	0x60,
	0x00, //cadrx_ui_illum_offset4
	0x70,
	0x00, //cadrx_ui_illum_slope1
	0x80,
	0x00, //cadrx_ui_illum_slope2
	0x80,
	0x00, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x40,
	0x01, //cadrx_ui_ref_offset2
	0x80,
	0x01, //cadrx_ui_ref_offset3
	0x80,
	0x01, //cadrx_ui_ref_offset4
	0x80,
	0x02, //cadrx_ui_ref_slope1
	0x00,
	0x00, //cadrx_ui_ref_slope2
	0x00,
	0x00, //cadrx_ui_ref_slope3
	0x00,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x00, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0xe6, //pos_bi_min
	0xff, //pos_bi_max
	0x06, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x10,
	0x02, //de_maxplus 11
	0x00,
	0x02, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x10,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x18,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x08, //curve_y_1
	0x10, //curve_y_2
	0x18, //curve_y_3
	0x20, //curve_y_4
	0x28, //curve_y_5
	0x30, //curve_y_6
	0x38, //curve_y_7
	0x40, //curve_y_8
	0x48, //curve_y_9
	0x50, //curve_y_10
	0x58, //curve_y_11
	0x60, //curve_y_12
	0x68, //curve_y_13
	0x70, //curve_y_14
	0x78, //curve_y_15
	0x80, //curve_y_16
	0x88, //curve_y_17
	0x90, //curve_y_18
	0x98, //curve_y_19
	0xa0, //curve_y_20
	0xa8, //curve_y_21
	0xb0, //curve_y_22
	0xb8, //curve_y_23
	0xc0, //curve_y_24
	0xc8, //curve_y_25
	0xd0, //curve_y_26
	0xd8, //curve_y_27
	0xe0, //curve_y_28
	0xe8, //curve_y_29
	0xf0, //curve_y_30
	0xf8, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static char DSI0_TDMB_STANDARD_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0xf0, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0xff, //trans_on trans_block 0 000 0000
	0x04, //trans_slope
	0x01, //trans_interval
	//end
};

static char DSI0_TDMB_NATURAL_MDNIE_1[] = {
	//start
	0xDF,
	0x11, //linear_on ascr_skin_on 0000 0000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xe1, //ascr_skin_Rr
	0x3d, //ascr_skin_Rg
	0x27, //ascr_skin_Rb
	0xfa, //ascr_skin_Yr
	0xfb, //ascr_skin_Yg
	0x57, //ascr_skin_Yb
	0xe6, //ascr_skin_Mr
	0x46, //ascr_skin_Mg
	0xf0, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xfc, //ascr_skin_Wg
	0xf6, //ascr_skin_Wb
	0x8f, //ascr_Cr
	0xe1, //ascr_Rr
	0xf8, //ascr_Cg
	0x3d, //ascr_Rg
	0xf5, //ascr_Cb
	0x27, //ascr_Rb
	0xe6, //ascr_Mr
	0x86, //ascr_Gr
	0x46, //ascr_Mg
	0xf5, //ascr_Gg
	0xf0, //ascr_Mb
	0x4f, //ascr_Gb
	0xfa, //ascr_Yr
	0x37, //ascr_Br
	0xfb, //ascr_Yg
	0x1f, //ascr_Bg
	0x57, //ascr_Yb
	0xed, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xfc, //ascr_Wg
	0x00, //ascr_Kg
	0xf6, //ascr_Wb
	0x00, //ascr_Kb
};

static char DSI0_TDMB_NATURAL_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x00, //slce_on cadrx_en 0000 0000
	0x00, //lce_gain 000 0000
	0x30, //lce_color_gain 00 0000
	0x01, //lce_min_ref_offset
	0x00,
	0x70, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x34,
	0x01, //lce_ref_gain 9
	0x40,
	0x66, //lce_block_size h v 0000 0000
	0x03, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x11, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x20,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x00, //lce_lg_flicker Avg pixel_cnt 000
	0x0a, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x00, //lce_lg_mix_weight 7
	0x10, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0x40,
	0x00, //cadrx_ui_illum_offset2
	0x50,
	0x00, //cadrx_ui_illum_offset3
	0x60,
	0x00, //cadrx_ui_illum_offset4
	0x70,
	0x00, //cadrx_ui_illum_slope1
	0x80,
	0x00, //cadrx_ui_illum_slope2
	0x80,
	0x00, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x40,
	0x01, //cadrx_ui_ref_offset2
	0x80,
	0x01, //cadrx_ui_ref_offset3
	0x80,
	0x01, //cadrx_ui_ref_offset4
	0x80,
	0x02, //cadrx_ui_ref_slope1
	0x00,
	0x00, //cadrx_ui_ref_slope2
	0x00,
	0x00, //cadrx_ui_ref_slope3
	0x00,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x00, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0xe6, //pos_bi_min
	0xff, //pos_bi_max
	0x04, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x10,
	0x02, //de_maxplus 11
	0x00,
	0x02, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x10,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x08, //curve_y_1
	0x10, //curve_y_2
	0x18, //curve_y_3
	0x20, //curve_y_4
	0x28, //curve_y_5
	0x30, //curve_y_6
	0x38, //curve_y_7
	0x40, //curve_y_8
	0x48, //curve_y_9
	0x50, //curve_y_10
	0x58, //curve_y_11
	0x60, //curve_y_12
	0x68, //curve_y_13
	0x70, //curve_y_14
	0x78, //curve_y_15
	0x80, //curve_y_16
	0x88, //curve_y_17
	0x90, //curve_y_18
	0x98, //curve_y_19
	0xa0, //curve_y_20
	0xa8, //curve_y_21
	0xb0, //curve_y_22
	0xb8, //curve_y_23
	0xc0, //curve_y_24
	0xc8, //curve_y_25
	0xd0, //curve_y_26
	0xd8, //curve_y_27
	0xe0, //curve_y_28
	0xe8, //curve_y_29
	0xf0, //curve_y_30
	0xf8, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static char DSI0_TDMB_NATURAL_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0xf0, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0xff, //trans_on trans_block 0 000 0000
	0x04, //trans_slope
	0x01, //trans_interval
	//end
};

static char DSI0_TDMB_DYNAMIC_MDNIE_1[] = {
	//start
	0xDF,
	0x11, //linear_on ascr_skin_on 0000 0000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xe8, //ascr_skin_Rr
	0x1c, //ascr_skin_Rg
	0x00, //ascr_skin_Rb
	0xf0, //ascr_skin_Yr
	0xf2, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xf2, //ascr_skin_Mr
	0x18, //ascr_skin_Mg
	0xef, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xfc, //ascr_skin_Wg
	0xf6, //ascr_skin_Wb
	0x58, //ascr_Cr
	0xe8, //ascr_Rr
	0xf5, //ascr_Cg
	0x1c, //ascr_Rg
	0xf1, //ascr_Cb
	0x00, //ascr_Rb
	0xf2, //ascr_Mr
	0x38, //ascr_Gr
	0x18, //ascr_Mg
	0xff, //ascr_Gg
	0xef, //ascr_Mb
	0x00, //ascr_Gb
	0xf0, //ascr_Yr
	0x35, //ascr_Br
	0xf2, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xe8, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xfc, //ascr_Wg
	0x00, //ascr_Kg
	0xf6, //ascr_Wb
	0x00, //ascr_Kb
};

static char DSI0_TDMB_DYNAMIC_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x00, //slce_on cadrx_en 0000 0000
	0x00, //lce_gain 000 0000
	0x30, //lce_color_gain 00 0000
	0x01, //lce_min_ref_offset
	0x00,
	0x70, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x34,
	0x01, //lce_ref_gain 9
	0x40,
	0x66, //lce_block_size h v 0000 0000
	0x03, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x11, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x20,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x00, //lce_lg_flicker Avg pixel_cnt 000
	0x0a, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x00, //lce_lg_mix_weight 7
	0x10, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0x40,
	0x00, //cadrx_ui_illum_offset2
	0x50,
	0x00, //cadrx_ui_illum_offset3
	0x60,
	0x00, //cadrx_ui_illum_offset4
	0x70,
	0x00, //cadrx_ui_illum_slope1
	0x80,
	0x00, //cadrx_ui_illum_slope2
	0x80,
	0x00, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x40,
	0x01, //cadrx_ui_ref_offset2
	0x80,
	0x01, //cadrx_ui_ref_offset3
	0x80,
	0x01, //cadrx_ui_ref_offset4
	0x80,
	0x02, //cadrx_ui_ref_slope1
	0x00,
	0x00, //cadrx_ui_ref_slope2
	0x00,
	0x00, //cadrx_ui_ref_slope3
	0x00,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x00, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0xe6, //pos_bi_min
	0xff, //pos_bi_max
	0x04, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x10,
	0x02, //de_maxplus 11
	0x00,
	0x02, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x10,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x08, //curve_y_1
	0x10, //curve_y_2
	0x18, //curve_y_3
	0x20, //curve_y_4
	0x28, //curve_y_5
	0x30, //curve_y_6
	0x38, //curve_y_7
	0x40, //curve_y_8
	0x48, //curve_y_9
	0x50, //curve_y_10
	0x58, //curve_y_11
	0x60, //curve_y_12
	0x68, //curve_y_13
	0x70, //curve_y_14
	0x78, //curve_y_15
	0x80, //curve_y_16
	0x88, //curve_y_17
	0x90, //curve_y_18
	0x98, //curve_y_19
	0xa0, //curve_y_20
	0xa8, //curve_y_21
	0xb0, //curve_y_22
	0xb8, //curve_y_23
	0xc0, //curve_y_24
	0xc8, //curve_y_25
	0xd0, //curve_y_26
	0xd8, //curve_y_27
	0xe0, //curve_y_28
	0xe8, //curve_y_29
	0xf0, //curve_y_30
	0xf8, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static char DSI0_TDMB_DYNAMIC_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0xf0, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0xff, //trans_on trans_block 0 000 0000
	0x04, //trans_slope
	0x01, //trans_interval
	//end
};

static char DSI0_TDMB_AUTO_MDNIE_1[] = {
	//start
	0xDF,
	0x01, //linear_on ascr_skin_on 0000 0000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xff, //ascr_skin_Rr
	0x60, //ascr_skin_Rg
	0x70, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xf7, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xf0, //ascr_Rr
	0xee, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xf7, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xff, //ascr_Wg
	0x00, //ascr_Kg
	0xff, //ascr_Wb
	0x00, //ascr_Kb
};

static char DSI0_TDMB_AUTO_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x00, //slce_on cadrx_en 0000 0000
	0x00, //lce_gain 000 0000
	0x30, //lce_color_gain 00 0000
	0x01, //lce_min_ref_offset
	0x00,
	0x70, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x34,
	0x01, //lce_ref_gain 9
	0x40,
	0x66, //lce_block_size h v 0000 0000
	0x03, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x11, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x20,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x00, //lce_lg_flicker Avg pixel_cnt 000
	0x0a, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x00, //lce_lg_mix_weight 7
	0x10, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0x40,
	0x00, //cadrx_ui_illum_offset2
	0x50,
	0x00, //cadrx_ui_illum_offset3
	0x60,
	0x00, //cadrx_ui_illum_offset4
	0x70,
	0x00, //cadrx_ui_illum_slope1
	0x80,
	0x00, //cadrx_ui_illum_slope2
	0x80,
	0x00, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x40,
	0x01, //cadrx_ui_ref_offset2
	0x80,
	0x01, //cadrx_ui_ref_offset3
	0x80,
	0x01, //cadrx_ui_ref_offset4
	0x80,
	0x02, //cadrx_ui_ref_slope1
	0x00,
	0x00, //cadrx_ui_ref_slope2
	0x00,
	0x00, //cadrx_ui_ref_slope3
	0x00,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x00, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0xe6, //pos_bi_min
	0xff, //pos_bi_max
	0x0c, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x10,
	0x02, //de_maxplus 11
	0x00,
	0x02, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x10,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x08, //curve_y_1
	0x10, //curve_y_2
	0x18, //curve_y_3
	0x20, //curve_y_4
	0x28, //curve_y_5
	0x30, //curve_y_6
	0x38, //curve_y_7
	0x40, //curve_y_8
	0x48, //curve_y_9
	0x50, //curve_y_10
	0x58, //curve_y_11
	0x60, //curve_y_12
	0x68, //curve_y_13
	0x70, //curve_y_14
	0x78, //curve_y_15
	0x80, //curve_y_16
	0x88, //curve_y_17
	0x90, //curve_y_18
	0x98, //curve_y_19
	0xa0, //curve_y_20
	0xa8, //curve_y_21
	0xb0, //curve_y_22
	0xb8, //curve_y_23
	0xc0, //curve_y_24
	0xc8, //curve_y_25
	0xd0, //curve_y_26
	0xd8, //curve_y_27
	0xe0, //curve_y_28
	0xe8, //curve_y_29
	0xf0, //curve_y_30
	0xf8, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static char DSI0_TDMB_AUTO_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0xf0, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0xff, //trans_on trans_block 0 000 0000
	0x04, //trans_slope
	0x01, //trans_interval
	//end
};

static char DSI0_HMT_COLOR_TEMP_3000K_MDNIE_1[] = {
	//start
	0xDF,
	0x01, //linear_on ascr_skin_on 0000 0000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xff, //ascr_skin_Rr
	0x00, //ascr_skin_Rg
	0x00, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xfc, //ascr_skin_Wg
	0xf6, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xff, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xfc, //ascr_Wg
	0x00, //ascr_Kg
	0xf6, //ascr_Wb
	0x00, //ascr_Kb
};

static char DSI0_HMT_COLOR_TEMP_3000K_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x00, //slce_on cadrx_en 0000 0000
	0x00, //lce_gain 000 0000
	0x30, //lce_color_gain 00 0000
	0x01, //lce_min_ref_offset
	0x00,
	0x70, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x34,
	0x01, //lce_ref_gain 9
	0x40,
	0x66, //lce_block_size h v 0000 0000
	0x03, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x11, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x20,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x00, //lce_lg_flicker Avg pixel_cnt 000
	0x0a, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x00, //lce_lg_mix_weight 7
	0x10, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0x40,
	0x00, //cadrx_ui_illum_offset2
	0x50,
	0x00, //cadrx_ui_illum_offset3
	0x60,
	0x00, //cadrx_ui_illum_offset4
	0x70,
	0x00, //cadrx_ui_illum_slope1
	0x80,
	0x00, //cadrx_ui_illum_slope2
	0x80,
	0x00, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x40,
	0x01, //cadrx_ui_ref_offset2
	0x80,
	0x01, //cadrx_ui_ref_offset3
	0x80,
	0x01, //cadrx_ui_ref_offset4
	0x80,
	0x02, //cadrx_ui_ref_slope1
	0x00,
	0x00, //cadrx_ui_ref_slope2
	0x00,
	0x00, //cadrx_ui_ref_slope3
	0x00,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x00, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0xe6, //pos_bi_min
	0xff, //pos_bi_max
	0x00, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x02, //de_maxplus 11
	0x00,
	0x02, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x10,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x08, //curve_y_1
	0x10, //curve_y_2
	0x18, //curve_y_3
	0x20, //curve_y_4
	0x28, //curve_y_5
	0x30, //curve_y_6
	0x38, //curve_y_7
	0x40, //curve_y_8
	0x48, //curve_y_9
	0x50, //curve_y_10
	0x58, //curve_y_11
	0x60, //curve_y_12
	0x68, //curve_y_13
	0x70, //curve_y_14
	0x78, //curve_y_15
	0x80, //curve_y_16
	0x88, //curve_y_17
	0x90, //curve_y_18
	0x98, //curve_y_19
	0xa0, //curve_y_20
	0xa8, //curve_y_21
	0xb0, //curve_y_22
	0xb8, //curve_y_23
	0xc0, //curve_y_24
	0xc8, //curve_y_25
	0xd0, //curve_y_26
	0xd8, //curve_y_27
	0xe0, //curve_y_28
	0xe8, //curve_y_29
	0xf0, //curve_y_30
	0xf8, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static char DSI0_HMT_COLOR_TEMP_3000K_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0xf0, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0xff, //trans_on trans_block 0 000 0000
	0x04, //trans_slope
	0x01, //trans_interval
	//end
};

static char DSI0_HMT_COLOR_TEMP_4000K_MDNIE_1[] = {
	//start
	0xDF,
	0x01, //linear_on ascr_skin_on 0000 0000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xff, //ascr_skin_Rr
	0x00, //ascr_skin_Rg
	0x00, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xfc, //ascr_skin_Wg
	0xf6, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xff, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xfc, //ascr_Wg
	0x00, //ascr_Kg
	0xf6, //ascr_Wb
	0x00, //ascr_Kb
};

static char DSI0_HMT_COLOR_TEMP_4000K_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x00, //slce_on cadrx_en 0000 0000
	0x00, //lce_gain 000 0000
	0x30, //lce_color_gain 00 0000
	0x01, //lce_min_ref_offset
	0x00,
	0x70, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x34,
	0x01, //lce_ref_gain 9
	0x40,
	0x66, //lce_block_size h v 0000 0000
	0x03, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x11, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x20,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x00, //lce_lg_flicker Avg pixel_cnt 000
	0x0a, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x00, //lce_lg_mix_weight 7
	0x10, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0x40,
	0x00, //cadrx_ui_illum_offset2
	0x50,
	0x00, //cadrx_ui_illum_offset3
	0x60,
	0x00, //cadrx_ui_illum_offset4
	0x70,
	0x00, //cadrx_ui_illum_slope1
	0x80,
	0x00, //cadrx_ui_illum_slope2
	0x80,
	0x00, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x40,
	0x01, //cadrx_ui_ref_offset2
	0x80,
	0x01, //cadrx_ui_ref_offset3
	0x80,
	0x01, //cadrx_ui_ref_offset4
	0x80,
	0x02, //cadrx_ui_ref_slope1
	0x00,
	0x00, //cadrx_ui_ref_slope2
	0x00,
	0x00, //cadrx_ui_ref_slope3
	0x00,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x00, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0xe6, //pos_bi_min
	0xff, //pos_bi_max
	0x00, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x02, //de_maxplus 11
	0x00,
	0x02, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x10,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x08, //curve_y_1
	0x10, //curve_y_2
	0x18, //curve_y_3
	0x20, //curve_y_4
	0x28, //curve_y_5
	0x30, //curve_y_6
	0x38, //curve_y_7
	0x40, //curve_y_8
	0x48, //curve_y_9
	0x50, //curve_y_10
	0x58, //curve_y_11
	0x60, //curve_y_12
	0x68, //curve_y_13
	0x70, //curve_y_14
	0x78, //curve_y_15
	0x80, //curve_y_16
	0x88, //curve_y_17
	0x90, //curve_y_18
	0x98, //curve_y_19
	0xa0, //curve_y_20
	0xa8, //curve_y_21
	0xb0, //curve_y_22
	0xb8, //curve_y_23
	0xc0, //curve_y_24
	0xc8, //curve_y_25
	0xd0, //curve_y_26
	0xd8, //curve_y_27
	0xe0, //curve_y_28
	0xe8, //curve_y_29
	0xf0, //curve_y_30
	0xf8, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static char DSI0_HMT_COLOR_TEMP_4000K_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0xf0, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0xff, //trans_on trans_block 0 000 0000
	0x04, //trans_slope
	0x01, //trans_interval
	//end
};

static char DSI0_HMT_COLOR_TEMP_5000K_MDNIE_1[] = {
	//start
	0xDF,
	0x01, //linear_on ascr_skin_on 0000 0000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xff, //ascr_skin_Rr
	0x00, //ascr_skin_Rg
	0x00, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xfc, //ascr_skin_Wg
	0xf6, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xff, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xfc, //ascr_Wg
	0x00, //ascr_Kg
	0xf6, //ascr_Wb
	0x00, //ascr_Kb
};

static char DSI0_HMT_COLOR_TEMP_5000K_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x00, //slce_on cadrx_en 0000 0000
	0x00, //lce_gain 000 0000
	0x30, //lce_color_gain 00 0000
	0x01, //lce_min_ref_offset
	0x00,
	0x70, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x34,
	0x01, //lce_ref_gain 9
	0x40,
	0x66, //lce_block_size h v 0000 0000
	0x03, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x11, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x20,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x00, //lce_lg_flicker Avg pixel_cnt 000
	0x0a, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x00, //lce_lg_mix_weight 7
	0x10, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0x40,
	0x00, //cadrx_ui_illum_offset2
	0x50,
	0x00, //cadrx_ui_illum_offset3
	0x60,
	0x00, //cadrx_ui_illum_offset4
	0x70,
	0x00, //cadrx_ui_illum_slope1
	0x80,
	0x00, //cadrx_ui_illum_slope2
	0x80,
	0x00, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x40,
	0x01, //cadrx_ui_ref_offset2
	0x80,
	0x01, //cadrx_ui_ref_offset3
	0x80,
	0x01, //cadrx_ui_ref_offset4
	0x80,
	0x02, //cadrx_ui_ref_slope1
	0x00,
	0x00, //cadrx_ui_ref_slope2
	0x00,
	0x00, //cadrx_ui_ref_slope3
	0x00,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x00, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0xe6, //pos_bi_min
	0xff, //pos_bi_max
	0x00, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x02, //de_maxplus 11
	0x00,
	0x02, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x10,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x08, //curve_y_1
	0x10, //curve_y_2
	0x18, //curve_y_3
	0x20, //curve_y_4
	0x28, //curve_y_5
	0x30, //curve_y_6
	0x38, //curve_y_7
	0x40, //curve_y_8
	0x48, //curve_y_9
	0x50, //curve_y_10
	0x58, //curve_y_11
	0x60, //curve_y_12
	0x68, //curve_y_13
	0x70, //curve_y_14
	0x78, //curve_y_15
	0x80, //curve_y_16
	0x88, //curve_y_17
	0x90, //curve_y_18
	0x98, //curve_y_19
	0xa0, //curve_y_20
	0xa8, //curve_y_21
	0xb0, //curve_y_22
	0xb8, //curve_y_23
	0xc0, //curve_y_24
	0xc8, //curve_y_25
	0xd0, //curve_y_26
	0xd8, //curve_y_27
	0xe0, //curve_y_28
	0xe8, //curve_y_29
	0xf0, //curve_y_30
	0xf8, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static char DSI0_HMT_COLOR_TEMP_5000K_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0xf0, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0xff, //trans_on trans_block 0 000 0000
	0x04, //trans_slope
	0x01, //trans_interval
	//end
};

static char DSI0_HMT_COLOR_TEMP_6500K_MDNIE_1[] = {
	//start
	0xDF,
	0x01, //linear_on ascr_skin_on 0000 0000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xff, //ascr_skin_Rr
	0x00, //ascr_skin_Rg
	0x00, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xfc, //ascr_skin_Wg
	0xf6, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xff, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xfc, //ascr_Wg
	0x00, //ascr_Kg
	0xf6, //ascr_Wb
	0x00, //ascr_Kb
};

static char DSI0_HMT_COLOR_TEMP_6500K_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x00, //slce_on cadrx_en 0000 0000
	0x00, //lce_gain 000 0000
	0x30, //lce_color_gain 00 0000
	0x01, //lce_min_ref_offset
	0x00,
	0x70, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x34,
	0x01, //lce_ref_gain 9
	0x40,
	0x66, //lce_block_size h v 0000 0000
	0x03, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x11, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x20,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x00, //lce_lg_flicker Avg pixel_cnt 000
	0x0a, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x00, //lce_lg_mix_weight 7
	0x10, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0x40,
	0x00, //cadrx_ui_illum_offset2
	0x50,
	0x00, //cadrx_ui_illum_offset3
	0x60,
	0x00, //cadrx_ui_illum_offset4
	0x70,
	0x00, //cadrx_ui_illum_slope1
	0x80,
	0x00, //cadrx_ui_illum_slope2
	0x80,
	0x00, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x40,
	0x01, //cadrx_ui_ref_offset2
	0x80,
	0x01, //cadrx_ui_ref_offset3
	0x80,
	0x01, //cadrx_ui_ref_offset4
	0x80,
	0x02, //cadrx_ui_ref_slope1
	0x00,
	0x00, //cadrx_ui_ref_slope2
	0x00,
	0x00, //cadrx_ui_ref_slope3
	0x00,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x00, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0xe6, //pos_bi_min
	0xff, //pos_bi_max
	0x02, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x02, //de_maxplus 11
	0x00,
	0x02, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x10,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x40,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x08, //curve_y_1
	0x10, //curve_y_2
	0x18, //curve_y_3
	0x20, //curve_y_4
	0x28, //curve_y_5
	0x30, //curve_y_6
	0x38, //curve_y_7
	0x40, //curve_y_8
	0x48, //curve_y_9
	0x50, //curve_y_10
	0x58, //curve_y_11
	0x60, //curve_y_12
	0x68, //curve_y_13
	0x70, //curve_y_14
	0x78, //curve_y_15
	0x80, //curve_y_16
	0x88, //curve_y_17
	0x90, //curve_y_18
	0x98, //curve_y_19
	0xa0, //curve_y_20
	0xa8, //curve_y_21
	0xb0, //curve_y_22
	0xb8, //curve_y_23
	0xc0, //curve_y_24
	0xc8, //curve_y_25
	0xd0, //curve_y_26
	0xd8, //curve_y_27
	0xe0, //curve_y_28
	0xe8, //curve_y_29
	0xf0, //curve_y_30
	0xf8, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static char DSI0_HMT_COLOR_TEMP_6500K_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0xf0, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0xff, //trans_on trans_block 0 000 0000
	0x04, //trans_slope
	0x01, //trans_interval
	//end
};

static char DSI0_HMT_COLOR_TEMP_7500K_MDNIE_1[] = {
	//start
	0xDF,
	0x01, //linear_on ascr_skin_on 0000 0000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xff, //ascr_skin_Rr
	0x00, //ascr_skin_Rg
	0x00, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xfc, //ascr_skin_Wg
	0xf6, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xff, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xfc, //ascr_Wg
	0x00, //ascr_Kg
	0xf6, //ascr_Wb
	0x00, //ascr_Kb
};

static char DSI0_HMT_COLOR_TEMP_7500K_MDNIE_2[] = {
	0xDE,
	0x00, //gamut_gamma_on gamut_blk_shift 0000 0000
	0x40, //gamut_scale
	0x04, //gamut_r1
	0x00,
	0x00, //gamut_r2
	0x00,
	0x00, //gamut_r3
	0x00,
	0x00, //gamut_g1
	0x00,
	0x04, //gamut_g2
	0x00,
	0x00, //gamut_g3
	0x00,
	0x00, //gamut_b1
	0x00,
	0x00, //gamut_b2
	0x00,
	0x04, //gamut_b3
	0x00,
	0x00, //slce_on cadrx_en 0000 0000
	0x00, //lce_gain 000 0000
	0x30, //lce_color_gain 00 0000
	0x01, //lce_min_ref_offset
	0x00,
	0x70, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x34,
	0x01, //lce_ref_gain 9
	0x40,
	0x66, //lce_block_size h v 0000 0000
	0x03, //lce_dark_th 000
	0x01, //lce_reduct_slope 0000
	0x11, //lce_black cc1 0000 0000
	0x00, //lce_color_th 12
	0x20,
	0x08, //lce_med_w
	0x08, //lce_small_w
	0x00, //lce_lg_flicker Avg pixel_cnt 000
	0x0a, //lce_lg_avg_th
	0x0a, //lce_lg_pixel_th
	0x06, //lce_lg_pixel_cnt_th 23
	0xae,
	0x00,
	0x00, //lce_lg_mix_weight 7
	0x10, //cadrx_gain
	0x20, //cadrx_ui_illum_a1
	0x40, //cadrx_ui_illum_a2
	0x60, //cadrx_ui_illum_a3
	0x00, //cadrx_ui_illum_offset1
	0x40,
	0x00, //cadrx_ui_illum_offset2
	0x50,
	0x00, //cadrx_ui_illum_offset3
	0x60,
	0x00, //cadrx_ui_illum_offset4
	0x70,
	0x00, //cadrx_ui_illum_slope1
	0x80,
	0x00, //cadrx_ui_illum_slope2
	0x80,
	0x00, //cadrx_ui_illum_slope3
	0x80,
	0x00, //cadrx_ui_illum_slope4
	0x00,
	0x20, //cadrx_ui_ref_a1
	0x40, //cadrx_ui_ref_a2
	0x60, //cadrx_ui_ref_a3
	0x01, //cadrx_ui_ref_offset1
	0x40,
	0x01, //cadrx_ui_ref_offset2
	0x80,
	0x01, //cadrx_ui_ref_offset3
	0x80,
	0x01, //cadrx_ui_ref_offset4
	0x80,
	0x02, //cadrx_ui_ref_slope1
	0x00,
	0x00, //cadrx_ui_ref_slope2
	0x00,
	0x00, //cadrx_ui_ref_slope3
	0x00,
	0x00, //cadrx_ui_ref_slope4
	0x00,
	0x07, //bi_filter_en bi_en bcr_en 000
	0x40, //reduce_halo_neg
	0x00, //reduce_halo_pos
	0x6e, //neg_bi_min
	0x82, //neg_bi_max
	0xe6, //pos_bi_min
	0xff, //pos_bi_max
	0x00, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x02, //de_maxplus 11
	0x00,
	0x02, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 10
	0x01,
	0x00, //fa_step_n 10
	0x01,
	0x00, //fa_max_de_gain 10
	0x10,
	0x00, //fa_pcl_ppi 14
	0x00,
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x04, //fa_edge_cnt_weight
	0x0f, //fa_avg_y_weight
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_x_0
	0x08, //curve_x_1
	0x10, //curve_x_2
	0x18, //curve_x_3
	0x20, //curve_x_4
	0x28, //curve_x_5
	0x30, //curve_x_6
	0x38, //curve_x_7
	0x40, //curve_x_8
	0x48, //curve_x_9
	0x50, //curve_x_10
	0x58, //curve_x_11
	0x60, //curve_x_12
	0x68, //curve_x_13
	0x70, //curve_x_14
	0x78, //curve_x_15
	0x80, //curve_x_16
	0x88, //curve_x_17
	0x90, //curve_x_18
	0x98, //curve_x_19
	0xa0, //curve_x_20
	0xa8, //curve_x_21
	0xb0, //curve_x_22
	0xb8, //curve_x_23
	0xc0, //curve_x_24
	0xc8, //curve_x_25
	0xd0, //curve_x_26
	0xd8, //curve_x_27
	0xe0, //curve_x_28
	0xe8, //curve_x_29
	0xf0, //curve_x_30
	0xf8, //curve_x_31
	0x01, //curve_x_32
	0x00,
	0x00, //curve_y_0
	0x08, //curve_y_1
	0x10, //curve_y_2
	0x18, //curve_y_3
	0x20, //curve_y_4
	0x28, //curve_y_5
	0x30, //curve_y_6
	0x38, //curve_y_7
	0x40, //curve_y_8
	0x48, //curve_y_9
	0x50, //curve_y_10
	0x58, //curve_y_11
	0x60, //curve_y_12
	0x68, //curve_y_13
	0x70, //curve_y_14
	0x78, //curve_y_15
	0x80, //curve_y_16
	0x88, //curve_y_17
	0x90, //curve_y_18
	0x98, //curve_y_19
	0xa0, //curve_y_20
	0xa8, //curve_y_21
	0xb0, //curve_y_22
	0xb8, //curve_y_23
	0xc0, //curve_y_24
	0xc8, //curve_y_25
	0xd0, //curve_y_26
	0xd8, //curve_y_27
	0xe0, //curve_y_28
	0xe8, //curve_y_29
	0xf0, //curve_y_30
	0xf8, //curve_y_31
	0x01, //curve_y_32
	0x00,
};

static char DSI0_HMT_COLOR_TEMP_7500K_MDNIE_3[] = {
	0xDD,
	0x01, //mdnie_en
	0x00, //mask 0 0000
	0xf0, //ascr algo aolce gamut 00 00 00 00
	0x07, //v_partial_on
	0x7f, //partial_en1
	0x7f, //partial_en2
	0x00, //roi_en
	0x00, //roi_block
	0x00, //roi_sx
	0x00, //roi_sx
	0x00, //roi_sy
	0x00, //roi_sy
	0x00, //roi_ex
	0x00, //roi_ex
	0x00, //roi_ey
	0x00, //roi_ey
	0xff, //trans_on trans_block 0 000 0000
	0x04, //trans_slope
	0x01, //trans_interval
	//end
};

static char DSI_AFC[] = {
	0xE2,
	0x00,
	0x00,
	0x03,
	0x0F,
	0x00,
	0x00,
	0x00,
	0x00,
	0x05,
	0x9F,
	0x00,
	0x53,
	0x00,
	0x00,
	0x00,
	0x54,
	0x05,
	0x9F,
	0x01,
	0x2C,
	0x00,
	0x00,
	0x01,
	0x2D,
	0x05,
	0x9F,
	0x0A,
	0xE7,
	0x00,
	0x00,
	0x0A,
	0xE8,
	0x05,
	0x9F,
	0x0B,
	0xDF,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x40,
	0x00,
	0x80,
	0x00,
	0x80,
	0x01,
	0x00,
	0xFF,
	0xFF,
	0xFF,
	0xFF,
	0xFF,
	0xFF,
	0xFF,
	0xFF,
	0xFF,
	0xFF,
	0xFF,
	0xFF,
	0xFF,
	0xFF,
	0xFF,
	0xFF,
	0xFF,
	0xFF,
	0xFF,
	0xFF
	//end
};

static char DSI_AFC_ON[] = {
	0xE2,
	0x01,
	0x00,
	0x03,
	0x0F,
	0x00,
	0x00,
	0x00,
	0x00,
	0x05,
	0x9F,
	0x00,
	0x53,
	0x00,
	0x00,
	0x00,
	0x54,
	0x05,
	0x9F,
	0x01,
	0x2C,
	0x00,
	0x00,
	0x01,
	0x2D,
	0x05,
	0x9F,
	0x0A,
	0xE7,
	0x00,
	0x00,
	0x0A,
	0xE8,
	0x05,
	0x9F,
	0x0B,
	0xDF,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x40,
	0x00,
	0x80,
	0x00,
	0x80,
	0x01,
	0x00,
	0xFF,
	0xFF,
	0xFF,
	0xFF,
	0xFF,
	0xFF,
	0xFF,
	0xFF,
	0xFF,
	0xFF,
	0xFF,
	0xFF,
	0xFF,
	0xFF,
	0xFF,
	0xFF,
	0xFF,
	0xFF,
	0xFF,
	0xFF
	//end
};

static char DSI_AFC_OFF[] = {
	0xE2,
	0x00,
	0x00,
	0x03,
	0x0F,
	0x00,
	0x00,
	0x00,
	0x00,
	0x05,
	0x9F,
	0x00,
	0x53,
	0x00,
	0x00,
	0x00,
	0x54,
	0x05,
	0x9F,
	0x01,
	0x2C,
	0x00,
	0x00,
	0x01,
	0x2D,
	0x05,
	0x9F,
	0x0A,
	0xE7,
	0x00,
	0x00,
	0x0A,
	0xE8,
	0x05,
	0x9F,
	0x0B,
	0xDF,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x40,
	0x00,
	0x80,
	0x00,
	0x80,
	0x01,
	0x00,
	0xFF,
	0xFF,
	0xFF,
	0xFF,
	0xFF,
	0xFF,
	0xFF,
	0xFF,
	0xFF,
	0xFF,
	0xFF,
	0xFF,
	0xFF,
	0xFF,
	0xFF,
	0xFF,
	0xFF,
	0xFF,
	0xFF,
	0xFF
	//end
};

static struct dsi_cmd_desc DSI0_BYPASS_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_BYPASS_MDNIE_1), DSI0_BYPASS_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_BYPASS_MDNIE_2), DSI0_BYPASS_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_BYPASS_MDNIE_3), DSI0_BYPASS_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI_AFC), DSI_AFC, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_NEGATIVE_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_NEGATIVE_MDNIE_1), DSI0_NEGATIVE_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_NEGATIVE_MDNIE_2), DSI0_NEGATIVE_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_NEGATIVE_MDNIE_3), DSI0_NEGATIVE_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI_AFC), DSI_AFC, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_GRAYSCALE_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_GRAYSCALE_MDNIE_1), DSI0_GRAYSCALE_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_GRAYSCALE_MDNIE_2), DSI0_GRAYSCALE_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_GRAYSCALE_MDNIE_3), DSI0_GRAYSCALE_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI_AFC), DSI_AFC, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_GRAYSCALE_NEGATIVE_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_GRAYSCALE_NEGATIVE_MDNIE_1), DSI0_GRAYSCALE_NEGATIVE_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_GRAYSCALE_NEGATIVE_MDNIE_2), DSI0_GRAYSCALE_NEGATIVE_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_GRAYSCALE_NEGATIVE_MDNIE_3), DSI0_GRAYSCALE_NEGATIVE_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI_AFC), DSI_AFC, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_COLOR_BLIND_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_COLOR_BLIND_MDNIE_1), DSI0_COLOR_BLIND_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_COLOR_BLIND_MDNIE_2), DSI0_COLOR_BLIND_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_COLOR_BLIND_MDNIE_3), DSI0_COLOR_BLIND_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI_AFC), DSI_AFC, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_NIGHT_MODE_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_NIGHT_MODE_MDNIE_1), DSI0_NIGHT_MODE_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_NIGHT_MODE_MDNIE_2), DSI0_NIGHT_MODE_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_NIGHT_MODE_MDNIE_3), DSI0_NIGHT_MODE_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI_AFC), DSI_AFC, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_COLOR_LENS_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_COLOR_LENS_MDNIE_1), DSI0_COLOR_LENS_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_COLOR_LENS_MDNIE_2), DSI0_COLOR_LENS_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_COLOR_LENS_MDNIE_3), DSI0_COLOR_LENS_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI_AFC), DSI_AFC, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_HBM_CE_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HBM_CE_MDNIE_1), DSI0_HBM_CE_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HBM_CE_MDNIE_2), DSI0_HBM_CE_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HBM_CE_MDNIE_3), DSI0_HBM_CE_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI_AFC), DSI_AFC, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_HBM_CE_D65_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HBM_CE_D65_MDNIE_1), DSI0_HBM_CE_D65_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HBM_CE_D65_MDNIE_2), DSI0_HBM_CE_D65_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HBM_CE_D65_MDNIE_3), DSI0_HBM_CE_D65_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI_AFC), DSI_AFC, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_RGB_SENSOR_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_RGB_SENSOR_MDNIE_1), DSI0_RGB_SENSOR_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_RGB_SENSOR_MDNIE_2), DSI0_RGB_SENSOR_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_RGB_SENSOR_MDNIE_3), DSI0_RGB_SENSOR_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI_AFC), DSI_AFC, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_SCREEN_CURTAIN_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_SCREEN_CURTAIN_MDNIE_1), DSI0_SCREEN_CURTAIN_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_SCREEN_CURTAIN_MDNIE_2), DSI0_SCREEN_CURTAIN_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_SCREEN_CURTAIN_MDNIE_3), DSI0_SCREEN_CURTAIN_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI_AFC), DSI_AFC, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_LIGHT_NOTIFICATION_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_LIGHT_NOTIFICATION_MDNIE_1), DSI0_LIGHT_NOTIFICATION_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_LIGHT_NOTIFICATION_MDNIE_2), DSI0_LIGHT_NOTIFICATION_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_LIGHT_NOTIFICATION_MDNIE_3), DSI0_LIGHT_NOTIFICATION_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI_AFC), DSI_AFC, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_HDR_VIDEO_1_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_1_MDNIE_1), DSI0_HDR_VIDEO_1_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_1_MDNIE_2), DSI0_HDR_VIDEO_1_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_1_MDNIE_3), DSI0_HDR_VIDEO_1_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI_AFC), DSI_AFC, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_HDR_VIDEO_2_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_2_MDNIE_1), DSI0_HDR_VIDEO_2_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_2_MDNIE_2), DSI0_HDR_VIDEO_2_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_2_MDNIE_3), DSI0_HDR_VIDEO_2_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI_AFC), DSI_AFC, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_HDR_VIDEO_3_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_3_MDNIE_1), DSI0_HDR_VIDEO_3_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_3_MDNIE_2), DSI0_HDR_VIDEO_3_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_3_MDNIE_3), DSI0_HDR_VIDEO_3_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI_AFC), DSI_AFC, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_HDR_VIDEO_4_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_4_MDNIE_1), DSI0_HDR_VIDEO_4_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_4_MDNIE_2), DSI0_HDR_VIDEO_4_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_4_MDNIE_3), DSI0_HDR_VIDEO_4_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI_AFC), DSI_AFC, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_HDR_VIDEO_5_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_5_MDNIE_1), DSI0_HDR_VIDEO_5_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_5_MDNIE_2), DSI0_HDR_VIDEO_5_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_5_MDNIE_3), DSI0_HDR_VIDEO_5_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI_AFC), DSI_AFC, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_VIDEO_ENHANCER_D65_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_VIDEO_ENHANCER_D65_MDNIE_1), DSI0_VIDEO_ENHANCER_D65_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_VIDEO_ENHANCER_D65_MDNIE_2), DSI0_VIDEO_ENHANCER_D65_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_VIDEO_ENHANCER_D65_MDNIE_3), DSI0_VIDEO_ENHANCER_D65_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI_AFC), DSI_AFC, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_VIDEO_ENHANCER_AUTO_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_VIDEO_ENHANCER_AUTO_MDNIE_1), DSI0_VIDEO_ENHANCER_AUTO_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_VIDEO_ENHANCER_AUTO_MDNIE_2), DSI0_VIDEO_ENHANCER_AUTO_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_VIDEO_ENHANCER_AUTO_MDNIE_3), DSI0_VIDEO_ENHANCER_AUTO_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI_AFC), DSI_AFC, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_VIDEO_ENHANCER_THIRD_D65_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_VIDEO_ENHANCER_THIRD_D65_MDNIE_1), DSI0_VIDEO_ENHANCER_THIRD_D65_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_VIDEO_ENHANCER_THIRD_D65_MDNIE_2), DSI0_VIDEO_ENHANCER_THIRD_D65_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_VIDEO_ENHANCER_THIRD_D65_MDNIE_3), DSI0_VIDEO_ENHANCER_THIRD_D65_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI_AFC), DSI_AFC, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_VIDEO_ENHANCER_THIRD_AUTO_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_VIDEO_ENHANCER_THIRD_AUTO_MDNIE_1), DSI0_VIDEO_ENHANCER_THIRD_AUTO_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_VIDEO_ENHANCER_THIRD_AUTO_MDNIE_2), DSI0_VIDEO_ENHANCER_THIRD_AUTO_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_VIDEO_ENHANCER_THIRD_AUTO_MDNIE_3), DSI0_VIDEO_ENHANCER_THIRD_AUTO_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI_AFC), DSI_AFC, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

///////////////////////////////////////////////////////////////////////////////////

static struct dsi_cmd_desc DSI0_UI_DYNAMIC_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_UI_DYNAMIC_MDNIE_1), DSI0_UI_DYNAMIC_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_UI_DYNAMIC_MDNIE_2), DSI0_UI_DYNAMIC_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_UI_DYNAMIC_MDNIE_3), DSI0_UI_DYNAMIC_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI_AFC), DSI_AFC, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_UI_STANDARD_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_UI_STANDARD_MDNIE_1), DSI0_UI_STANDARD_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_UI_STANDARD_MDNIE_2), DSI0_UI_STANDARD_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_UI_STANDARD_MDNIE_3), DSI0_UI_STANDARD_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI_AFC), DSI_AFC, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_UI_NATURAL_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_UI_NATURAL_MDNIE_1), DSI0_UI_NATURAL_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_UI_NATURAL_MDNIE_2), DSI0_UI_NATURAL_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_UI_NATURAL_MDNIE_3), DSI0_UI_NATURAL_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI_AFC), DSI_AFC, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_UI_AUTO_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_UI_AUTO_MDNIE_1), DSI0_UI_AUTO_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_UI_AUTO_MDNIE_2), DSI0_UI_AUTO_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_UI_AUTO_MDNIE_3), DSI0_UI_AUTO_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI_AFC), DSI_AFC, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_VIDEO_DYNAMIC_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_VIDEO_DYNAMIC_MDNIE_1), DSI0_VIDEO_DYNAMIC_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_VIDEO_DYNAMIC_MDNIE_2), DSI0_VIDEO_DYNAMIC_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_VIDEO_DYNAMIC_MDNIE_3), DSI0_VIDEO_DYNAMIC_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI_AFC), DSI_AFC, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_VIDEO_STANDARD_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_VIDEO_STANDARD_MDNIE_1), DSI0_VIDEO_STANDARD_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_VIDEO_STANDARD_MDNIE_2), DSI0_VIDEO_STANDARD_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_VIDEO_STANDARD_MDNIE_3), DSI0_VIDEO_STANDARD_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI_AFC), DSI_AFC, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_VIDEO_NATURAL_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_VIDEO_NATURAL_MDNIE_1), DSI0_VIDEO_NATURAL_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_VIDEO_NATURAL_MDNIE_2), DSI0_VIDEO_NATURAL_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_VIDEO_NATURAL_MDNIE_3), DSI0_VIDEO_NATURAL_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI_AFC), DSI_AFC, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_VIDEO_AUTO_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_VIDEO_AUTO_MDNIE_1), DSI0_VIDEO_AUTO_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_VIDEO_AUTO_MDNIE_2), DSI0_VIDEO_AUTO_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_VIDEO_AUTO_MDNIE_3), DSI0_VIDEO_AUTO_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI_AFC), DSI_AFC, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_CAMERA_DYNAMIC_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_CAMERA_DYNAMIC_MDNIE_1), DSI0_CAMERA_DYNAMIC_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_CAMERA_DYNAMIC_MDNIE_2), DSI0_CAMERA_DYNAMIC_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_CAMERA_DYNAMIC_MDNIE_3), DSI0_CAMERA_DYNAMIC_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI_AFC), DSI_AFC, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_CAMERA_STANDARD_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_CAMERA_STANDARD_MDNIE_1), DSI0_CAMERA_STANDARD_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_CAMERA_STANDARD_MDNIE_2), DSI0_CAMERA_STANDARD_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_CAMERA_STANDARD_MDNIE_3), DSI0_CAMERA_STANDARD_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI_AFC), DSI_AFC, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_CAMERA_NATURAL_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_CAMERA_NATURAL_MDNIE_1), DSI0_CAMERA_NATURAL_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_CAMERA_NATURAL_MDNIE_2), DSI0_CAMERA_NATURAL_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_CAMERA_NATURAL_MDNIE_3), DSI0_CAMERA_NATURAL_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI_AFC), DSI_AFC, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_CAMERA_AUTO_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_CAMERA_AUTO_MDNIE_1), DSI0_CAMERA_AUTO_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_CAMERA_AUTO_MDNIE_2), DSI0_CAMERA_AUTO_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_CAMERA_AUTO_MDNIE_3), DSI0_CAMERA_AUTO_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI_AFC), DSI_AFC, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_GALLERY_DYNAMIC_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_GALLERY_DYNAMIC_MDNIE_1), DSI0_GALLERY_DYNAMIC_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_GALLERY_DYNAMIC_MDNIE_2), DSI0_GALLERY_DYNAMIC_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_GALLERY_DYNAMIC_MDNIE_3), DSI0_GALLERY_DYNAMIC_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI_AFC), DSI_AFC, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_GALLERY_STANDARD_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_GALLERY_STANDARD_MDNIE_1), DSI0_GALLERY_STANDARD_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_GALLERY_STANDARD_MDNIE_2), DSI0_GALLERY_STANDARD_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_GALLERY_STANDARD_MDNIE_3), DSI0_GALLERY_STANDARD_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI_AFC), DSI_AFC, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_GALLERY_NATURAL_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_GALLERY_NATURAL_MDNIE_1), DSI0_GALLERY_NATURAL_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_GALLERY_NATURAL_MDNIE_2), DSI0_GALLERY_NATURAL_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_GALLERY_NATURAL_MDNIE_3), DSI0_GALLERY_NATURAL_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI_AFC), DSI_AFC, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_GALLERY_AUTO_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_GALLERY_AUTO_MDNIE_1), DSI0_GALLERY_AUTO_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_GALLERY_AUTO_MDNIE_2), DSI0_GALLERY_AUTO_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_GALLERY_AUTO_MDNIE_3), DSI0_GALLERY_AUTO_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI_AFC), DSI_AFC, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_BROWSER_DYNAMIC_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_BROWSER_DYNAMIC_MDNIE_1), DSI0_BROWSER_DYNAMIC_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_BROWSER_DYNAMIC_MDNIE_2), DSI0_BROWSER_DYNAMIC_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_BROWSER_DYNAMIC_MDNIE_3), DSI0_BROWSER_DYNAMIC_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI_AFC), DSI_AFC, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_BROWSER_STANDARD_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_BROWSER_STANDARD_MDNIE_1), DSI0_BROWSER_STANDARD_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_BROWSER_STANDARD_MDNIE_2), DSI0_BROWSER_STANDARD_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_BROWSER_STANDARD_MDNIE_3), DSI0_BROWSER_STANDARD_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI_AFC), DSI_AFC, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_BROWSER_NATURAL_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_BROWSER_NATURAL_MDNIE_1), DSI0_BROWSER_NATURAL_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_BROWSER_NATURAL_MDNIE_2), DSI0_BROWSER_NATURAL_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_BROWSER_NATURAL_MDNIE_3), DSI0_BROWSER_NATURAL_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI_AFC), DSI_AFC, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_BROWSER_AUTO_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_BROWSER_AUTO_MDNIE_1), DSI0_BROWSER_AUTO_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_BROWSER_AUTO_MDNIE_2), DSI0_BROWSER_AUTO_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_BROWSER_AUTO_MDNIE_3), DSI0_BROWSER_AUTO_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI_AFC), DSI_AFC, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_EBOOK_DYNAMIC_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_EBOOK_DYNAMIC_MDNIE_1), DSI0_EBOOK_DYNAMIC_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_EBOOK_DYNAMIC_MDNIE_2), DSI0_EBOOK_DYNAMIC_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_EBOOK_DYNAMIC_MDNIE_3), DSI0_EBOOK_DYNAMIC_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI_AFC), DSI_AFC, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_EBOOK_STANDARD_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_EBOOK_STANDARD_MDNIE_1), DSI0_EBOOK_STANDARD_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_EBOOK_STANDARD_MDNIE_2), DSI0_EBOOK_STANDARD_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_EBOOK_STANDARD_MDNIE_3), DSI0_EBOOK_STANDARD_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI_AFC), DSI_AFC, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_EBOOK_NATURAL_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_EBOOK_NATURAL_MDNIE_1), DSI0_EBOOK_NATURAL_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_EBOOK_NATURAL_MDNIE_2), DSI0_EBOOK_NATURAL_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_EBOOK_NATURAL_MDNIE_3), DSI0_EBOOK_NATURAL_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI_AFC), DSI_AFC, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_EBOOK_AUTO_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_EBOOK_AUTO_MDNIE_1), DSI0_EBOOK_AUTO_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_EBOOK_AUTO_MDNIE_2), DSI0_EBOOK_AUTO_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_EBOOK_AUTO_MDNIE_3), DSI0_EBOOK_AUTO_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI_AFC), DSI_AFC, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_EMAIL_AUTO_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_EMAIL_AUTO_MDNIE_1), DSI0_EMAIL_AUTO_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_EMAIL_AUTO_MDNIE_2), DSI0_EMAIL_AUTO_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_EMAIL_AUTO_MDNIE_3), DSI0_EMAIL_AUTO_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI_AFC), DSI_AFC, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_GAME_LOW_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_BYPASS_MDNIE_1), DSI0_BYPASS_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_BYPASS_MDNIE_2), DSI0_BYPASS_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_BYPASS_MDNIE_3), DSI0_BYPASS_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI_AFC), DSI_AFC, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_GAME_MID_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_BYPASS_MDNIE_1), DSI0_BYPASS_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_BYPASS_MDNIE_2), DSI0_BYPASS_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_BYPASS_MDNIE_3), DSI0_BYPASS_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI_AFC), DSI_AFC, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_GAME_HIGH_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_BYPASS_MDNIE_1), DSI0_BYPASS_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_BYPASS_MDNIE_2), DSI0_BYPASS_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_BYPASS_MDNIE_3), DSI0_BYPASS_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI_AFC), DSI_AFC, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_TDMB_DYNAMIC_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_TDMB_DYNAMIC_MDNIE_1), DSI0_TDMB_DYNAMIC_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_TDMB_DYNAMIC_MDNIE_2), DSI0_TDMB_DYNAMIC_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_TDMB_DYNAMIC_MDNIE_3), DSI0_TDMB_DYNAMIC_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI_AFC), DSI_AFC, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_TDMB_STANDARD_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_TDMB_STANDARD_MDNIE_1), DSI0_TDMB_STANDARD_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_TDMB_STANDARD_MDNIE_2), DSI0_TDMB_STANDARD_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_TDMB_STANDARD_MDNIE_3), DSI0_TDMB_STANDARD_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI_AFC), DSI_AFC, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_TDMB_NATURAL_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_TDMB_NATURAL_MDNIE_1), DSI0_TDMB_NATURAL_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_TDMB_NATURAL_MDNIE_2), DSI0_TDMB_NATURAL_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_TDMB_NATURAL_MDNIE_3), DSI0_TDMB_NATURAL_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI_AFC), DSI_AFC, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_TDMB_AUTO_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_TDMB_AUTO_MDNIE_1), DSI0_TDMB_AUTO_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_TDMB_AUTO_MDNIE_2), DSI0_TDMB_AUTO_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_TDMB_AUTO_MDNIE_3), DSI0_TDMB_AUTO_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI_AFC), DSI_AFC, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc *mdnie_tune_value_dsi0[MAX_APP_MODE][MAX_MODE][MAX_OUTDOOR_MODE] = {
	/*
		DYNAMIC_MODE
		STANDARD_MODE
		NATURAL_MODE
		MOVIE_MODE
		AUTO_MODE
		READING_MODE
	*/
	// UI_APP
	{
		{DSI0_UI_DYNAMIC_MDNIE,	NULL},
		{DSI0_UI_STANDARD_MDNIE,	NULL},
		{DSI0_UI_NATURAL_MDNIE,	NULL},
		{NULL,	NULL},
		{DSI0_UI_AUTO_MDNIE,	NULL},
		{DSI0_EBOOK_AUTO_MDNIE,	NULL},
	},
	// VIDEO_APP
	{
		{DSI0_VIDEO_DYNAMIC_MDNIE,	NULL},
		{DSI0_VIDEO_STANDARD_MDNIE,	NULL},
		{DSI0_VIDEO_NATURAL_MDNIE,	NULL},
		{NULL,	NULL},
		{DSI0_VIDEO_AUTO_MDNIE,	NULL},
		{DSI0_EBOOK_AUTO_MDNIE,	NULL},
	},
	// VIDEO_WARM_APP
	{
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
	},
	// VIDEO_COLD_APP
	{
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
	},
	// CAMERA_APP
	{
		{DSI0_CAMERA_DYNAMIC_MDNIE,	NULL},
		{DSI0_CAMERA_STANDARD_MDNIE,	NULL},
		{DSI0_CAMERA_NATURAL_MDNIE,	NULL},
		{NULL,	NULL},
		{DSI0_CAMERA_AUTO_MDNIE,	NULL},
		{DSI0_EBOOK_AUTO_MDNIE,	NULL},
	},
	// NAVI_APP
	{
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
	},
	// GALLERY_APP
	{
		{DSI0_GALLERY_DYNAMIC_MDNIE,	NULL},
		{DSI0_GALLERY_STANDARD_MDNIE,	NULL},
		{DSI0_GALLERY_NATURAL_MDNIE,	NULL},
		{NULL,	NULL},
		{DSI0_GALLERY_AUTO_MDNIE,	NULL},
		{DSI0_EBOOK_AUTO_MDNIE,	NULL},
	},
	// VT_APP
	{
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
	},
	// BROWSER_APP
	{
		{DSI0_BROWSER_DYNAMIC_MDNIE,	NULL},
		{DSI0_BROWSER_STANDARD_MDNIE,	NULL},
		{DSI0_BROWSER_NATURAL_MDNIE,	NULL},
		{NULL,	NULL},
		{DSI0_BROWSER_AUTO_MDNIE,	NULL},
		{DSI0_EBOOK_AUTO_MDNIE,	NULL},
	},
	// eBOOK_APP
	{
		{DSI0_EBOOK_DYNAMIC_MDNIE,	NULL},
		{DSI0_EBOOK_STANDARD_MDNIE,	NULL},
		{DSI0_EBOOK_NATURAL_MDNIE,	NULL},
		{NULL,	NULL},
		{DSI0_EBOOK_AUTO_MDNIE,	NULL},
		{DSI0_EBOOK_AUTO_MDNIE,	NULL},
	},
	// EMAIL_APP
	{
		{DSI0_EMAIL_AUTO_MDNIE,	NULL},
		{DSI0_EMAIL_AUTO_MDNIE,	NULL},
		{DSI0_EMAIL_AUTO_MDNIE,	NULL},
		{NULL,	NULL},
		{DSI0_EMAIL_AUTO_MDNIE,	NULL},
		{DSI0_EBOOK_AUTO_MDNIE,	NULL},
	},
	// GAME_LOW_APP
	{
		{DSI0_GAME_LOW_MDNIE,	NULL},
		{DSI0_GAME_LOW_MDNIE,	NULL},
		{DSI0_GAME_LOW_MDNIE,	NULL},
		{NULL,	NULL},
		{DSI0_GAME_LOW_MDNIE,	NULL},
		{DSI0_GAME_LOW_MDNIE,	NULL},
	},
	// GAME_MID_APP
	{
		{DSI0_GAME_MID_MDNIE,	NULL},
		{DSI0_GAME_MID_MDNIE,	NULL},
		{DSI0_GAME_MID_MDNIE,	NULL},
		{NULL,	NULL},
		{DSI0_GAME_MID_MDNIE,	NULL},
		{DSI0_GAME_MID_MDNIE,	NULL},
	},
	// GAME_HIGH_APP
	{
		{DSI0_GAME_HIGH_MDNIE,	NULL},
		{DSI0_GAME_HIGH_MDNIE,	NULL},
		{DSI0_GAME_HIGH_MDNIE,	NULL},
		{NULL,	NULL},
		{DSI0_GAME_HIGH_MDNIE,	NULL},
		{DSI0_GAME_HIGH_MDNIE,	NULL},
	},
	// VIDEO_ENHANCER_APP
	{
		{DSI0_VIDEO_ENHANCER_D65_MDNIE,	NULL},
		{DSI0_VIDEO_ENHANCER_D65_MDNIE,	NULL},
		{DSI0_VIDEO_ENHANCER_D65_MDNIE,	NULL},
		{NULL,	NULL},
		{DSI0_VIDEO_ENHANCER_AUTO_MDNIE,	NULL},
		{DSI0_EBOOK_AUTO_MDNIE,	NULL},
	},
	// VIDEO_ENHANCER_THIRD_APP
	{
		{DSI0_VIDEO_ENHANCER_THIRD_D65_MDNIE,	NULL},
		{DSI0_VIDEO_ENHANCER_THIRD_D65_MDNIE,	NULL},
		{DSI0_VIDEO_ENHANCER_THIRD_D65_MDNIE,	NULL},
		{NULL,	NULL},
		{DSI0_VIDEO_ENHANCER_THIRD_AUTO_MDNIE,	NULL},
		{DSI0_EBOOK_AUTO_MDNIE,	NULL},
	},
	// TDMB_APP
	{
		{DSI0_TDMB_DYNAMIC_MDNIE,       NULL},
		{DSI0_TDMB_STANDARD_MDNIE,      NULL},
		{DSI0_TDMB_NATURAL_MDNIE,       NULL},
		{NULL,         NULL},
		{DSI0_TDMB_AUTO_MDNIE,          NULL},
		{DSI0_EBOOK_AUTO_MDNIE,	NULL},
	},
};

static struct dsi_cmd_desc DSI0_HMT_COLOR_TEMP_3000K_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HMT_COLOR_TEMP_3000K_MDNIE_1), DSI0_HMT_COLOR_TEMP_3000K_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HMT_COLOR_TEMP_3000K_MDNIE_2), DSI0_HMT_COLOR_TEMP_3000K_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HMT_COLOR_TEMP_3000K_MDNIE_3), DSI0_HMT_COLOR_TEMP_3000K_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_HMT_COLOR_TEMP_4000K_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HMT_COLOR_TEMP_4000K_MDNIE_1), DSI0_HMT_COLOR_TEMP_4000K_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HMT_COLOR_TEMP_4000K_MDNIE_2), DSI0_HMT_COLOR_TEMP_4000K_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HMT_COLOR_TEMP_4000K_MDNIE_3), DSI0_HMT_COLOR_TEMP_4000K_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_HMT_COLOR_TEMP_5000K_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HMT_COLOR_TEMP_5000K_MDNIE_1), DSI0_HMT_COLOR_TEMP_5000K_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HMT_COLOR_TEMP_5000K_MDNIE_2), DSI0_HMT_COLOR_TEMP_5000K_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HMT_COLOR_TEMP_5000K_MDNIE_3), DSI0_HMT_COLOR_TEMP_5000K_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_HMT_COLOR_TEMP_6500K_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HMT_COLOR_TEMP_6500K_MDNIE_1), DSI0_HMT_COLOR_TEMP_6500K_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HMT_COLOR_TEMP_6500K_MDNIE_2), DSI0_HMT_COLOR_TEMP_6500K_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HMT_COLOR_TEMP_6500K_MDNIE_3), DSI0_HMT_COLOR_TEMP_6500K_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_HMT_COLOR_TEMP_7500K_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HMT_COLOR_TEMP_7500K_MDNIE_1), DSI0_HMT_COLOR_TEMP_7500K_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HMT_COLOR_TEMP_7500K_MDNIE_2), DSI0_HMT_COLOR_TEMP_7500K_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HMT_COLOR_TEMP_7500K_MDNIE_3), DSI0_HMT_COLOR_TEMP_7500K_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc *hmt_color_temperature_tune_value_dsi0[HMT_COLOR_TEMP_MAX] = {
	/*
		HMT_COLOR_TEMP_3000K, // 3000K
		HMT_COLOR_TEMP_4000K, // 4000K
		HMT_COLOR_TEMP_5000K, // 5000K
		HMT_COLOR_TEMP_6500K, // 6500K
		HMT_COLOR_TEMP_7500K, // 7500K
	*/
	NULL,
	DSI0_HMT_COLOR_TEMP_3000K_MDNIE,
	DSI0_HMT_COLOR_TEMP_4000K_MDNIE,
	DSI0_HMT_COLOR_TEMP_5000K_MDNIE,
	DSI0_HMT_COLOR_TEMP_6500K_MDNIE,
	DSI0_HMT_COLOR_TEMP_7500K_MDNIE,
};

static struct dsi_cmd_desc *light_notification_tune_value_dsi0[LIGHT_NOTIFICATION_MAX] = {
	NULL,
	DSI0_LIGHT_NOTIFICATION_MDNIE,
};

static struct dsi_cmd_desc *hdr_tune_value_dsi0[HDR_MAX] = {
	NULL,
	DSI0_HDR_VIDEO_1_MDNIE,
	DSI0_HDR_VIDEO_2_MDNIE,
	DSI0_HDR_VIDEO_3_MDNIE,
	DSI0_HDR_VIDEO_4_MDNIE,
	DSI0_HDR_VIDEO_5_MDNIE,
};

#define DSI0_RGB_SENSOR_MDNIE_1_SIZE ARRAY_SIZE(DSI0_RGB_SENSOR_MDNIE_1)
#define DSI0_RGB_SENSOR_MDNIE_2_SIZE ARRAY_SIZE(DSI0_RGB_SENSOR_MDNIE_2)
#define DSI0_RGB_SENSOR_MDNIE_3_SIZE ARRAY_SIZE(DSI0_RGB_SENSOR_MDNIE_3)

#endif


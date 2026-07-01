/*
 * emu_tc_programming.cpp
 *
 *  Created on: Jan 13, 2017
 *
 *  Created on: Oct 26, 2026
 *      Author: Oscar Rodriguez Polo
 */

/****************************************************************************
 *
 *   This program is free software; you can redistribute it and/or
 *   modify it under the terms of the GNU General Public License
 *   as published by the Free Software Foundation; either version 2
 *   of the License, or (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307,USA.
 *
 *
 ****************************************************************************/

#include <public/emu_hw_timecode_drv_v1.h>
#include <public/emu_sc_channel_drv_v1.h>
#include <public/emu_gss_v1.h>

#define OBT_START_FT_ST01_0030 OBT_AFTER_POWER_ON + 10

#define FT_UAH_ASW_SERV_1_REJ_TC_0030

#ifdef FT_UAH_ASW_SERV_1_REJ_TC_0030


#define FT_ST01_0030_TIME_step0 (OBT_START_FT_ST01_0030 + 2)


EmuGSS_TCProgram17_3 prog_FT_ST01_0030_step_0(FT_ST01_0030_TIME_step0,
		"FT_UAH_ASW_SERV_1_0030 step 0, Rejected TC",0xFF);

#endif







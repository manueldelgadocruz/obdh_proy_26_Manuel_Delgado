/*
 * emu_tc_programming.cpp
 *
 *  Created on: Jan 13, 2017
 *
 *  Created on: Oct 26, 2024
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

#define OBT_START_FT_ST03_0065 (OBT_AFTER_POWER_ON + 20)

#define FT_UAH_ASW_ICU_SERV_3_ENABLE_DISABLE_SID11_0065


#ifdef FT_UAH_ASW_ICU_SERV_3_ENABLE_DISABLE_SID11_0065


#define FT_ST03_0065_TIME_step0 (OBT_START_FT_ST03_0065)
#define FT_ST03_0065_TIME_step1 (OBT_START_FT_ST03_0065 + 2)
#define FT_ST03_0065_TIME_step2 (OBT_START_FT_ST03_0065 + 20)

EmuGSS_TCProgram3_5 prog_FT_ST03_0065_step_0(FT_ST03_0065_TIME_step0,
		"FT_UAH_ASW_ICU_SERV_3_0065 step 0, Enable SID 11 ",11);

EmuGSS_TCProgram3_31 prog_FT_ST03_0065_step_1(FT_ST03_0065_TIME_step1,
		"FT_UAH_ASW_ICU_SERV_3_0065 step 1, Update SID 11 Rate to 3",11,3);

EmuGSS_TCProgram3_6 prog_FT_ST03_0065_step_2(FT_ST03_0065_TIME_step2,
		"FT_UAH_ASW_ICU_SERV_3_0065 step 2, Disable SID 11 ",11);


#endif


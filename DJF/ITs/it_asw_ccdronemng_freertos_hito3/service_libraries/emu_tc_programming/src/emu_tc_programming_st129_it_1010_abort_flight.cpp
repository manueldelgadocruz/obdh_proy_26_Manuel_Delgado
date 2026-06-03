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


//TODO 19 Comment IT_UAH_DRONE_EXEC_PLAN_1000 and Execute the Test IT_UAH_DRONE_ABORT_FIGHT_1010
//This test uses the TC[129,2] and TC[129,4]

//#define IT_UAH_DRONE_ABORT_FIGHT_1010


#ifdef IT_UAH_DRONE_ABORT_FIGHT_1010

#define IT_1010_TIME_step0 (OBT_AFTER_POWER_ON + 3)
#define IT_1010_TIME_step1 (OBT_AFTER_POWER_ON + 4)
#define IT_1010_TIME_step2 (OBT_AFTER_POWER_ON + 5)
#define IT_1010_TIME_step3 (OBT_AFTER_POWER_ON + 25)

EmuGSS_TCProgram129_2 prog_IT_1010_step_0(IT_1010_TIME_step0,
		"IT_UAH_DRONE_1010 step 0, Set PID Params to 0.15, 0.1, 0.05",0.15,0.1,0.05);

EmuGSS_TCProgram129_1 prog_IT_1010_step_1(IT_1010_TIME_step1,
		"IT_UAH_DRONE_1010 step 1, Set Flight Plan x=-40.0, y=-120.5, z=18.3",-40.0,-120.5,18.3);

EmuGSS_TCProgram129_3 prog_IT_1010_step_2(IT_1010_TIME_step2,
		"IT_UAH_DRONE_1010 step 2, Exec Flight Plan");

EmuGSS_TCProgram129_4 prog_IT_1010_step_3(IT_1010_TIME_step3,
		"IT_UAH_DRONE_1010 step 3, Abort Flight Plan");


#endif




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

//TODO 15 Part1 Configure the ST[03] to obtain the following SIDs configuration

//SID 0, Enabled, Collection Interval =3, Parameter Number = 6
	//Param IDs { 0, 1, 2, 3, 4, UAH_DRONE_Wind,...},

//SID 10, Enabled, Collection Interval =2, Parameter Number=6
	//Param IDs { UAH_DRONE_X, UAH_DRONE_Y, UAH_DRONE_Z, UAH_DRONE_VX, UAH_DRONE_VY, UAH_DRONE_VZ, ...},

//SID 11, Disabled, Collection Interval =5,  Parameter Number=2
	//Param IDs { 14, 15, 0, ... },



//TODO 15 Part 2 Execute the Functional Test and compare with the expected output

#define IT_UAH_DRONE_EXEC_PLAN_1000

#ifdef IT_UAH_DRONE_EXEC_PLAN_1000

#define IT_1000_TIME_step0 (OBT_AFTER_POWER_ON + 3)
#define IT_1000_TIME_step1 (OBT_AFTER_POWER_ON + 4)



EmuGSS_TCProgram129_1 prog_IT_1000_step_0(IT_1000_TIME_step0,
		"IT_UAH_DRONE_1000 step 1, Set Flight Plan x=100.5, y=50.5, z=15.5",100.5,50.5,15.5);

EmuGSS_TCProgram129_3 prog_IT_1000_step_1(IT_1000_TIME_step1,
		"IT_UAH_DRONE_1000 step 2, Exec Flight Plan");


#endif





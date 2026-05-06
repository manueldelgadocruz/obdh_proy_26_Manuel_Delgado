/*
 * aux_pus_service129_exec_tc.c
 *
 *  Created on: Feb 13, 2025
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
#include <public/pus_tc_handler.h>
#include "public/config.h"
#include "pus_service129/aux_pus_service129_exec_tc.h"
#include "pus_service129/aux_pus_service129_drone_mng.h"
#include "public/pus_service129.h"
#include "public/pus_service01.h"


void pus_service129_exec_TC_129_1(tc_handler_t *ptc_handler) {

	error_code_t error;

	float FP_x, FP_y, FP_z;

	// TODO 14 Part1 TC -> FP_x use tc_handler_get_float_appdata_field

	// TODO 14 Part2  -> FP_y use tc_handler_get_float_appdata_field

	// TODO 14 Part3  TC -> FP_z use tc_handler_get_float_appdata_field

	if (error) {

		// error in pack length
		pus_service1_tx_TM_1_4_short_pack_length(ptc_handler);

	} else {

		if (pus_service129_flight_plan_is_valid(FP_x, FP_y, FP_z)) {

			pus_service1_tx_TM_1_3(ptc_handler);

			pus_service129_set_flight_plan(FP_x, FP_y, FP_z);

			pus_service1_tx_TM_1_7(ptc_handler);
		} else {

			pus_service1_tx_TM_1_4_TC_129_1_INVALID_FLIGHT_PLAN(ptc_handler);

		}

	}

	//free memory
	tc_handler_free_memory(ptc_handler);

}

void pus_service129_exec_TC_129_2(tc_handler_t *ptc_handler) {

	error_code_t error;

	float Kp;
	float Ki;
	float Kd;

	// TODO 17 Part1 TC -> Kp use tc_handler_get_float_appdata_field

	// TODO 17 Part1 TC -> Ki use tc_handler_get_float_appdata_field

	// TODO 17 Part1 TC -> Kd use tc_handler_get_float_appdata_field

	if (error) {

		// error in pack length
		pus_service1_tx_TM_1_4_short_pack_length(ptc_handler);

	} else {

		if (pus_service129_PID_Kx_isValid(Kp) &&
				pus_service129_PID_Kx_isValid(Ki) &&
				pus_service129_PID_Kx_isValid(Kd)) {

			pus_service1_tx_TM_1_3(ptc_handler);

			pus_service129_drone_set_Kp_Ki_Kd(Kp, Ki, Kd);

			pus_service1_tx_TM_1_7(ptc_handler);
		} else {

			pus_service1_tx_TM_1_4_TC_129_2_INVALID_KP_KI_KD(ptc_handler);
		}

	}

	//free memory
	tc_handler_free_memory(ptc_handler);

}

void pus_service129_exec_TC_129_3(tc_handler_t *ptc_handler) {

	pus_service1_tx_TM_1_3(ptc_handler);
	float Xtarget,Ytarget,Ztarget;



	pus_service129_get_flight_plan(&Xtarget,&Ytarget,&Ztarget);

	if (pus_service129_flight_plan_is_valid(Xtarget, Ytarget, Ztarget)){

		pus_service1_tx_TM_1_7(ptc_handler);

		pus_service129_set_flight_plan_ready();

	}else{

		pus_service1_tx_TM_1_8_NotValidFlightPlanReady(ptc_handler);

	}



	//free memory
	tc_handler_free_memory(ptc_handler);

}

void pus_service129_exec_TC_129_4(tc_handler_t *ptc_handler) {

	pus_service1_tx_TM_1_3(ptc_handler);

	uint8_t error;

	error=pus_service129_abort_current_flight_plan();

	if(!error){

		pus_service1_tx_TM_1_7(ptc_handler);

	}else{

		pus_service1_tx_TM_1_8_DroneIsNotFlying(ptc_handler);

	}



	//free memory
	tc_handler_free_memory(ptc_handler);

}

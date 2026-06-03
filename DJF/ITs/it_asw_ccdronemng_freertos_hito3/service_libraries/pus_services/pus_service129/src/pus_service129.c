/*
 * icuasw_pus_service129.c
 *
 *  Created on: Dec 22, 2025
 *      Author: user
 */

#include "public/pus_service01.h"
#include "public/pus_service05.h"
#include "public/pus_service129.h"
#include "public/drone_flight_pid_ctrl.h"
#include "public/emu_uah_drone_cinematics.h"

#include "pus_service129/aux_pus_service129_exec_tc.h"
#include "pus_service129/aux_pus_service129_drone_mng.h"

enum FlightStage CurrenStage;


void pus_service129_drone_selftest(){

	pus_service1_tx_TM_5_1_drone_self_test_done();
}

void pus_service129_setup(struct CDDroneConfig droneconfig){


	pus_service129_drone_set_Kp_Ki_Kd(droneconfig.DefaultKp, droneconfig.DefaultKi
			, droneconfig.DefaultKd);

	pus_service129_drone_set_min_high_before_advance(droneconfig.ZMinBeforeAdvance);

	//Default flight plan
	pus_service129_set_flight_plan(droneconfig.ZMinBeforeAdvance*4,
									droneconfig.ZMinBeforeAdvance*4,
									droneconfig.ZMinBeforeAdvance);

}

void pus_service129_exec_tc(tc_handler_t *ptc_handler) {

	switch (ptc_handler->tc_df_header.subtype) {
	case (1):
		pus_service129_exec_TC_129_1(ptc_handler);
		break;
	case (2):
		pus_service129_exec_TC_129_2(ptc_handler);
		break;
	case (3):
		pus_service129_exec_TC_129_3(ptc_handler);
		break;
	case (4):
		pus_service129_exec_TC_129_4(ptc_handler);
		break;

	default:
		break;
	}

}

void pus_service129_init_flight_plan(){


	pus_service129_drone_take_off();
	CurrenStage=DroneTakeOff;
	pus_service1_tx_TM_5_1_drone_take_off();




}

void pus_service129_flight_ctrl_algorithm(){

	//Update Kinematic with the previous values of Fx, sFy y sFz.
	enum FlightStage nextStage;
	nextStage=pus_service129_apply_ctrl_algorithm(CurrenStage);

	if(nextStage!=CurrenStage){

		CurrenStage=nextStage;
		switch (CurrenStage) {
				case (DroneAdvance):
				pus_service1_tx_TM_5_1_drone_min_hight_reached();
				break;
				case (DroneLanding):
				pus_service1_tx_TM_5_1_drone_landing();
				break;
				case (DroneLanded):
				pus_service1_tx_TM_5_1_drone_landed();
				break;

				default:
					break;

			}

	}

	pus_service129_update_system_data_pool();

}

uint8_t pus_service129_flight_plan_ready(){

	return pus_service129_check_flight_plan();

}

uint8_t pus_service129_flight_plan_done(){

	return (DroneLanded==CurrenStage);

}



void pus_service129_drone_ready(){


	pus_service129_drone_on_ground();

}

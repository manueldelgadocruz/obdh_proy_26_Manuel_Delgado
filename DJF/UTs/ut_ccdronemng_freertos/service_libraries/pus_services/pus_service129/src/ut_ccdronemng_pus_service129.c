/*
 * icuasw_pus_service129.c
 *
 *  Created on: Dec 22, 2025
 *      Author: user
 */

#include "public/pus_service01.h"
#include "public/pus_service129.h"



void pus_service129_drone_selftest(){

	ut_ccdrone_mng_add_trace(DRONE_SELF_TEST_TRACE_ID);

}

void pus_service129_setup(struct CDDroneConfig droneconfig){

	ut_ccdrone_mng_add_trace(DRONE_SET_UP_TRACE_ID);


}

void pus_service129_drone_ready(){


	ut_ccdrone_mng_add_trace(DRONE_DRONE_READY_ID);

}

void pus_service129_exec_tc(tc_handler_t *ptc_handler) {

	ut_ccdrone_mng_add_trace(DRONE_EXEC_TC_TRACE_ID);

}

#define NUM_TCS_BEFORE_READY  3
uint8_t pus_service129_flight_plan_ready(){
	static int num_tcs=0;

	ut_ccdrone_mng_add_trace(DRONE_FLIGH_PLAN_READY_ID);

	num_tcs++;
	return (num_tcs>=NUM_TCS_BEFORE_READY);
}

void pus_service129_init_flight_plan(){

	ut_ccdrone_mng_add_trace(DRONE_INIT_FLIGHT_PLAN_ID);


}

void pus_service129_flight_ctrl_algorithm(){

	ut_ccdrone_mng_add_trace(DRONE_FLIGHT_CTRL_ALG_ID);


}



#define NUM_CTRL_CYCLES_BEFORE_DONE  10
uint8_t pus_service129_flight_plan_done(){
	static int num_ctrl_cycles=0;

	ut_ccdrone_mng_add_trace(DRONE_FLIGH_PLAN_DONE_ID);
	num_ctrl_cycles++;

	return (num_ctrl_cycles>=NUM_CTRL_CYCLES_BEFORE_DONE);
}





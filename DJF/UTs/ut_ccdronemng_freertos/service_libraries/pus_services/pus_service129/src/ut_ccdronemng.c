/*
 * ut_ccdronemng_check_trace.c
 *
 *  Created on: Apr 15, 2026
 *      Author: opolo70
 */

#include "pus_service129/ut_ccdronemng.h"
#include <stdio.h>
#include <stdlib.h>

#define TRACE_ITEMS_TO_CHECK	31
uint8_t UT_CCDRONEMng0010Log[MAX_TRACE_ITEMS];
double UT_CCDRONEMng0010LogTime[MAX_TRACE_ITEMS];
uint8_t UT_TraceIndex = 0;

uint8_t UT_CCDRONEMng0010ExpectedLog[TRACE_ITEMS_TO_CHECK] = {
DRONE_SELF_TEST_TRACE_ID,
DRONE_SET_UP_TRACE_ID,
DRONE_DRONE_READY_ID,
DRONE_EXEC_TC_TRACE_ID,
DRONE_FLIGH_PLAN_READY_ID,
DRONE_EXEC_TC_TRACE_ID,
DRONE_FLIGH_PLAN_READY_ID,
DRONE_EXEC_TC_TRACE_ID,
DRONE_FLIGH_PLAN_READY_ID,
DRONE_INIT_FLIGHT_PLAN_ID,
DRONE_FLIGHT_CTRL_ALG_ID,
DRONE_FLIGH_PLAN_DONE_ID,
DRONE_FLIGHT_CTRL_ALG_ID,
DRONE_FLIGH_PLAN_DONE_ID,
DRONE_FLIGHT_CTRL_ALG_ID,
DRONE_FLIGH_PLAN_DONE_ID,
DRONE_FLIGHT_CTRL_ALG_ID,
DRONE_FLIGH_PLAN_DONE_ID,
DRONE_FLIGHT_CTRL_ALG_ID,
DRONE_FLIGH_PLAN_DONE_ID,
DRONE_FLIGHT_CTRL_ALG_ID,
DRONE_FLIGH_PLAN_DONE_ID,
DRONE_FLIGHT_CTRL_ALG_ID,
DRONE_FLIGH_PLAN_DONE_ID,
DRONE_FLIGHT_CTRL_ALG_ID,
DRONE_FLIGH_PLAN_DONE_ID,
DRONE_FLIGHT_CTRL_ALG_ID,
DRONE_FLIGH_PLAN_DONE_ID,
DRONE_FLIGHT_CTRL_ALG_ID,
DRONE_FLIGH_PLAN_DONE_ID,
DRONE_DRONE_READY_ID };

#define MAX_INTERVAL_ERROR (0.05)

double UT_CCDRONEMng0010ExpectedMAXInterval[(TRACE_ITEMS_TO_CHECK - 1)] = {
		0.01, 0.01, 1.0, 0.01, 1.0, 0.01, 0.01, 0.01, 0.01, 0.1, 0.01, 0.1,
		0.01, 0.1, 0.01, 0.1, 0.01, 0.1, 0.01, 0.1, 0.01, 0.1, 0.01, 0.1, 0.01,
		0.1, 0.01, 0.1, 0.01, 0.01 };

void ut_ccdrone_mng_add_trace(uint8_t trace_id) {
	if (UT_TraceIndex < MAX_TRACE_ITEMS) {

		UT_CCDRONEMng0010Log[UT_TraceIndex] = trace_id;
		UT_CCDRONEMng0010LogTime[UT_TraceIndex] =
				ut_ccdrone_mng_get_time_stamp();

		UT_TraceIndex++;
	}
}

char *TEST_ID[8] = { "pus_service129_drone_selftest", "pus_service129_setup",
		"pus_service129_drone_ready", "pus_service129_exec_tc",
		"pus_service129_flight_plan_ready?", "pus_service129_init_flight_plan",
		"pus_service129_flight_ctrl_algorithm",
		"pus_service129_flight_plan_done?" };

void StepMsg(uint8_t step_id) {

	if (step_id < 8)
		printf("%s", TEST_ID[step_id]);
	else
		printf("unexpected step");
}

void ut_ccdrone_mng_check_trace() {
	uint8_t current_step = 0;
	uint8_t timing_error = 0;

	while (current_step < UT_TraceIndex) {

		if (UT_CCDRONEMng0010Log[current_step]
				!= UT_CCDRONEMng0010ExpectedLog[current_step]) {

			printf("\nError in step %d: ", (current_step + 1));
			printf("Expected step: ");
			StepMsg(UT_CCDRONEMng0010ExpectedLog[current_step] - 1);
			printf(" Traced step: ");
			StepMsg(UT_CCDRONEMng0010Log[current_step] - 1);
			printf("\n");
		} else {
			printf("\nStep %d OK: ", (current_step + 1));
			StepMsg(UT_CCDRONEMng0010Log[current_step] - 1);
			printf("\n");

		}

		//No last
		if (current_step < (UT_TraceIndex - 1)) {
			double interval;
			interval = UT_CCDRONEMng0010LogTime[current_step + 1]
					- UT_CCDRONEMng0010LogTime[current_step];

			if (((interval - MAX_INTERVAL_ERROR)
					<= UT_CCDRONEMng0010ExpectedMAXInterval[current_step])
					&& ((interval + MAX_INTERVAL_ERROR)
							>= UT_CCDRONEMng0010ExpectedMAXInterval[current_step])) {

				printf("\nStep %d to %d Timing is OK", current_step + 1,
						(current_step + 2));

			} else {
				timing_error = 1;
				printf("\nStep %d to %d Timing Failure. Interval = %f ",
						current_step + 1, (current_step + 2), (float) interval);
				printf(", Expected Max Interval = %f ",
						(float) UT_CCDRONEMng0010ExpectedMAXInterval[current_step]);
			}
		}

		current_step++;
	}

	if (TRACE_ITEMS_TO_CHECK > UT_TraceIndex) {
		printf("\n\n\n*********************** ");
		printf("UT_CCDroneMng ERROR ***********************");
		printf("\n\nNo progress after: ");
		StepMsg(UT_CCDRONEMng0010Log[UT_TraceIndex - 1] - 1);
		printf("\nExpected next step: ");
		StepMsg(UT_CCDRONEMng0010ExpectedLog[UT_TraceIndex] - 1);
		printf("\n");
		exit(0);

	} else {

		if (timing_error) {
			printf("\n\n\n*********************** ");
			printf(
					"UT_CCDroneMng Timing Error. Check Log ***********************\n");

			exit(0);
		} else {
			printf("\n\n\n*********************** ");
			printf("UT_CCDroneMng OK ***********************\n");
			exit(0);
		}

	}

}


/*
 * ut_ccdronemng.h
 *
 *  Created on: Apr 15, 2026
 *      Author: opolo70
 */

#ifndef SERVICE_LIBRARIES_PUS_SERVICES_PUS_SERVICE129_INCLUDE_PUS_SERVICE129_UT_CCDRONEMNG_H_
#define SERVICE_LIBRARIES_PUS_SERVICES_PUS_SERVICE129_INCLUDE_PUS_SERVICE129_UT_CCDRONEMNG_H_


#define DRONE_SELF_TEST_TRACE_ID 	0x01
#define DRONE_SET_UP_TRACE_ID 		0x02
#define DRONE_DRONE_READY_ID 		0x03
#define DRONE_EXEC_TC_TRACE_ID 		0x04
#define DRONE_FLIGH_PLAN_READY_ID 	0x05
#define DRONE_INIT_FLIGHT_PLAN_ID 	0x06
#define DRONE_FLIGHT_CTRL_ALG_ID 	0x07
#define DRONE_FLIGH_PLAN_DONE_ID 	0x08

#include "public/config.h"
#include "public/basic_types.h"

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_TRACE_ITEMS			256

void ut_ccdrone_mng_add_trace(uint8_t trace_id);

void ut_ccdrone_mng_check_trace();

double ut_ccdrone_mng_get_time_stamp();

#ifdef __cplusplus
}
#endif

#endif /* SERVICE_LIBRARIES_PUS_SERVICES_PUS_SERVICE129_INCLUDE_PUS_SERVICE129_UT_CCDRONEMNG_H_ */

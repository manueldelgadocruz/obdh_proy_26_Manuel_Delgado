/*
 * icuasw_pus_service129.h
 *
 *  Created on: May 7, 2024
 *      Author: opolo70
 */

#ifndef SERVICE_LIBRARIES_ICUASW_PUS_SERVICES_INCLUDE_ICUASW_PUS_SERVICES_ICUASW_PUS_SERVICE129_H_
#define SERVICE_LIBRARIES_ICUASW_PUS_SERVICES_INCLUDE_ICUASW_PUS_SERVICES_ICUASW_PUS_SERVICE129_H_

#include "public/config.h"
#include "public/basic_types.h"

#include "public/pus_tc_handler.h"
#include "public/pus_tm_handler.h"
#include "public/pus_sys_data_pool.h"

#include "public/cddroneconfig.h"
#include "pus_service129/ut_ccdronemng.h"

#ifdef __cplusplus
extern "C" {
#endif


/**
 * \brief drone
 */

void pus_service129_drone_selftest();

/**
 * \brief flight to ready
 */

void pus_service129_setup (struct CDDroneConfig droneConfig);

/**
 * \brief flight to ready
 */

void pus_service129_drone_ready();

/**
 * \brief executes a TC[129,X] telecommand
 * \param ptc_handler pointer to the tc handler
 */
void pus_service129_exec_tc(tc_handler_t *ptc_handler);

/**
 * \brief init flight plan
 */
void pus_service129_init_flight_plan();

/**
 * \brief do attitude ctrl
 */

void pus_service129_flight_ctrl_algorithm();


/**
 * \brief check if flight plan is done
 * return true if flight plan is done;
 */

uint8_t pus_service129_flight_plan_ready();

/**
 * \brief check if flight plan is done
 * return true if flight plan is done;
 */

uint8_t pus_service129_flight_plan_done();




#ifdef __cplusplus
}
#endif




#endif /* SERVICE_LIBRARIES_ICUASW_PUS_SERVICES_INCLUDE_ICUASW_PUS_SERVICES_ICUASW_PUS_SERVICE129_H_ */

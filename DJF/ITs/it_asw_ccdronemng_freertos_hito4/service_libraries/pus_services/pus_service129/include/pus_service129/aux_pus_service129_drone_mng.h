/*
 * aux_pus_service129_observ_mng.h
 *
 *  Created on: Oct 25, 2024
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

#ifndef SERVICE_LIBRARIES_PUS_SERVICES_PUS_SERVICE129_INCLUDE_PUS_SERVICE1_AUX_PUS_SERVICE129_OBS_MNG_H_
#define SERVICE_LIBRARIES_PUS_SERVICES_PUS_SERVICE129_INCLUDE_PUS_SERVICE1_AUX_PUS_SERVICE129_OBS_MNG_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <public/pus_tm_handler.h>
#include "public/config.h"
#include "public/basic_types.h"

#include "public/pus_tc_handler.h"

enum FlightStage{DroneLanded,DroneTakeOff,DroneAdvance,DroneLanding};

/**
 * \brief Set Min High Before Advance
 * \param min_high minimum high before advance
 */
void pus_service129_drone_set_min_high_before_advance(float min_high);

/**
 * \brief Set Ks PID Controller
 * \param Kp Kp of PID Controller
 * \param Ki Ki of PID Controller
 * \param Kd Kd of PID Controller
 *
 */
void pus_service129_drone_set_Kp_Ki_Kd(float kp, float ki, float kd);

/**
 * \brief Set Flight Plan
 * \param x target position x coordinate
 * \param y target position y coordinate
 * \param z target position z coordinate
 *
 */
void pus_service129_set_flight_plan(float x, float y, float z);


/**
 * \brief Get Flight Plan
 * \param pX pointer to var where target position x coordinate is copied
 * \param pY pointer to var where target position y coordinate is copied
 * \param pZ pointer to var where target position z coordinate is copied
 *
 */
void pus_service129_get_flight_plan(float *pX, float *pY, float *pZ);


/**
 * \brief Abort Flight Plan
 *
 *\return 0 if plan can be aborted, 1 if not because no plan is in execution
 */
uint8_t pus_service129_abort_current_flight_plan();

/**
 * \brief Set Flight Plan as Ready
 *
 */
void pus_service129_set_flight_plan_ready();

/**
 * \brief Check Flight Plan
 * \return return true Flight Plan is Ready
 *
 */
uint8_t pus_service129_check_flight_plan();

/**
 * \brief Drone Take Off
 *
 */
void pus_service129_drone_take_off();

/**
 * \brief Drone is on ground
 *
 */
void pus_service129_drone_on_ground();

/**
 * \brief Apply Ctrl Algorithm
 *
 */
enum FlightStage pus_service129_apply_ctrl_algorithm(enum FlightStage currenStage);

/**
 * \brief Cal and apply torques
 *
 */
void pus_service129_update_system_data_pool();


bool_t pus_service129_flight_plan_is_valid(float x, float y, float z);

bool_t pus_service129_PID_Kx_isValid(float kx);


#ifdef __cplusplus
}
#endif

#endif /* SERVICE_LIBRARIES_PUS_SERVICES_PUS_SERVICE129_INCLUDE_PUS_SERVICE1_AUX_PUS_SERVICE129_OBS_MNG_H_ */

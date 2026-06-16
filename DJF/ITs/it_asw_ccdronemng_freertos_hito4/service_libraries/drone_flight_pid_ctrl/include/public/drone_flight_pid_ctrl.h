/*
 * attitude_pid_ctrl.h
 *
 *  Created on: Apr 28, 2025
 *      Author: opolo70
 */

#ifndef SERVICE_LIBRARIES_DRONE_FLIGHT_PID_CTRL_INCLUDE_PUBLIC_DRONE_FLIGHT_PID_CTRL_H_
#define SERVICE_LIBRARIES_DRONE_FLIGHT_PID_CTRL_INCLUDE_PUBLIC_DRONE_FLIGHT_PID_CTRL_H_

#include "public/basic_types.h"
#include "public/config.h"

#include "public/emu_uah_drone_cinematics.h"

#ifdef __cplusplus
extern "C" {
#endif




struct flight_ctrl{
	double Fx;
	double Fy;
	double Fz;
};

typedef struct flight_ctrl flight_ctrl_t;

struct pid_params{
	double Kp;
	double Ki;
	double Kd;
};

typedef struct pid_params pid_params_t;


/**
* \brief	calculate Satellite Attitude control.
* @param current_attitude current attitude
*
* @return the flight control to apply
*/

flight_ctrl_t drone_flight_pid_ctrl( const uah_drone_state_t *p_current_state,
								 const uah_drone_state_t *p_target_state,
								 const double Vx, const double Vy, const double Vz,
								 const pid_params_t *p_pid_params);




#ifdef __cplusplus
}
#endif



#endif /* SERVICE_LIBRARIES_DRONE_FLIGHT_PID_CTRL_INCLUDE_PUBLIC_DRONE_FLIGHT_PID_CTRL_H_ */

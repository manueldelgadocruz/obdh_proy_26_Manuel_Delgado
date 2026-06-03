/*
 * attitude_pid_ctrl.c
 *
 *  Created on: Apr 28, 2025
 *      Author: opolo70
 */

#include "../include/public/drone_flight_pid_ctrl.h"

#define MarsGC 3.721

const double ForceXYLimit = 5; //10 NewtonsxM
const double ForceZLimit = 5; //5 NewtonsxM +  MarsGC

float limit_force(float force, float limit) {

	float maxForce = force;
	if (maxForce > limit)
		maxForce = limit;
	else if (maxForce < (-limit)) {
		maxForce = -limit;
	}
	return maxForce;
}

flight_ctrl_t drone_flight_pid_ctrl( const uah_drone_state_t *p_current_state,
								 const uah_drone_state_t *p_target_state,
								 const double Vx, const double Vy, const double Vz,
								 const pid_params_t *p_pid_params) {

	flight_ctrl_t flight_ctrl;

	static double ErrorX = 0;
	static double ErrorY = 0;
	static double ErrorZ = 0;
	static double IntegralErrorX = 0;
	static double IntegralErrorY = 0;
	static double IntegralErrorZ = 0;

	double prev_error_x = ErrorX;
	double prev_error_y = ErrorY;
	double prev_error_z = ErrorZ;

	double ForceXWithoutIntegral;
	double ForceYWithoutIntegral;
	double ForceZWithoutIntegral;

	double ForceX;
	double ForceY;
	double ForceZ;

	//Calculate Errors
	ErrorX=p_target_state->X-p_current_state->X;
	ErrorY=p_target_state->Y-p_current_state->Y;
	ErrorZ=p_target_state->Z-p_current_state->Z;

	//Calculate Errors Integral with a forgetting factor
	IntegralErrorX = 0.75 * ErrorX + 0.25 * IntegralErrorX;
	IntegralErrorY = 0.75 * ErrorY + 0.25 * IntegralErrorY;
	IntegralErrorZ = 0.75 * ErrorZ + 0.25 * IntegralErrorZ;

	//Calculate Forces to apply in the next period


	//Proportional action
	ForceXWithoutIntegral = ErrorX * p_pid_params->Kp - Vx;
	ForceYWithoutIntegral = ErrorY * p_pid_params->Kp - Vy;
	ForceZWithoutIntegral = ErrorZ * p_pid_params->Kp - Vz;


	//Derivative action
	ForceXWithoutIntegral += (ErrorX - prev_error_x)*p_pid_params->Kd;
	ForceYWithoutIntegral += (ErrorY - prev_error_y)*p_pid_params->Kd;
	ForceZWithoutIntegral += (ErrorZ - prev_error_z)*p_pid_params->Kd;

	ForceXWithoutIntegral=limit_force(ForceXWithoutIntegral, ForceXYLimit);
	ForceYWithoutIntegral=limit_force(ForceYWithoutIntegral, ForceXYLimit);
	ForceZWithoutIntegral=limit_force(ForceZWithoutIntegral, ForceZLimit);


	//Integral action
	ForceX=ForceXWithoutIntegral + IntegralErrorX*p_pid_params->Ki;
	ForceY=ForceYWithoutIntegral + IntegralErrorY*p_pid_params->Ki;
	ForceZ=ForceZWithoutIntegral + IntegralErrorZ*p_pid_params->Ki;

	//Gravity compensation


	//Limit Torque
	flight_ctrl.Fx=limit_force(ForceX, ForceXYLimit);
	flight_ctrl.Fy=limit_force(ForceY, ForceXYLimit);
	flight_ctrl.Fz=limit_force(ForceZ, ForceZLimit);


	//Anti wind-up
	IntegralErrorX=flight_ctrl.Fx-ForceXWithoutIntegral;
	IntegralErrorY=flight_ctrl.Fy-ForceYWithoutIntegral;
	IntegralErrorZ=flight_ctrl.Fz-ForceZWithoutIntegral;

	flight_ctrl.Fz+=MarsGC;

	return flight_ctrl;

}


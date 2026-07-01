/*
 * aux_pus_service129_x_utils.c
 *
 *  Created on: May 2, 2025
 *      Author: opolo70
 */

#include "public/config.h"
#include "public/pus_tc_handler.h"
#include "public/pus_service01.h"
#include "public/pus_service129.h"

#include "pus_service129/aux_pus_service129_drone_mng.h"

#include "public/drone_flight_pid_ctrl.h"
#include "public/emu_uah_drone_cinematics.h"
#include "public/display_drv.h"

#define POS_TARGET_ERROR   1.0

static pid_params_t DronePID_Params;

static float ZMinBeforeAdvance;

static float XDroneFlightPlan;
static float YDroneFlightPlan;
static float ZDroneFlightPlan;

static uah_drone_state_t CurrentState;
static uah_drone_state_t TargetState;
static uah_drone_veloc_t DroneVeloc;

static uint8_t FlightPlanReady = 0;
static uint8_t DroneFlying = 0;
static uint8_t DroneAbortFlight = 0;

static uint32_t WindEmulation = 0x100;

float get_abs_error(float target, float current) {
	float abs_error;

	if (target > current)
		abs_error = target - current;
	else
		abs_error = current - target;

	return abs_error;

}

bool_t pus_service129_flight_plan_is_valid(float x, float y, float z) {

	bool_t is_valid=true;

	if ((x>125) && (x<-125))
		is_valid=false;
	else if ((y>125) && (y<-125))
		is_valid=false;
	else
		is_valid=((z >= ZMinBeforeAdvance) && (4 * z * z < (x * x + y * y)));

	return is_valid;
}

bool_t pus_service129_PID_Kx_isValid(float kx) {

	return ((kx <= (0.7)) && (kx >= 0.01));

}

void pus_service129_drone_set_min_high_before_advance(float min_high) {

	ZMinBeforeAdvance = min_high;
}

void pus_service129_drone_set_Kp_Ki_Kd(float kp, float ki, float kd) {

	DronePID_Params.Kp = kp;
	DronePID_Params.Ki = ki;
	DronePID_Params.Kd = kd;

}

void pus_service129_set_flight_plan(float x, float y, float z) {

	XDroneFlightPlan = x;
	YDroneFlightPlan = y;
	ZDroneFlightPlan = z;

}

void pus_service129_get_flight_plan(float *pX, float *pY, float *pZ) {

	*pX = XDroneFlightPlan;
	*pY = YDroneFlightPlan;
	*pZ = ZDroneFlightPlan;

}

uint8_t pus_service129_abort_current_flight_plan() {

	uint8_t error = 0;

	if (DroneFlying) {
		DroneAbortFlight = 1;
		if (TargetState.X > 0) {
			if ((TargetState.X - CurrentState.X) > CurrentState.Z) {
				TargetState.X = CurrentState.X + CurrentState.Z;
			}
		} else {
			if ((CurrentState.X - TargetState.X) > CurrentState.Z) {
				TargetState.X = CurrentState.X - CurrentState.Z;
			}
		}

		if (TargetState.Y > 0) {
			if ((TargetState.Y - CurrentState.Y) > CurrentState.Z) {
				TargetState.Y = CurrentState.Y + CurrentState.Z;
			}
		} else {
			if ((CurrentState.Y - TargetState.Y) > CurrentState.Z) {
				TargetState.Y = CurrentState.Y - CurrentState.Z;
			}
		}

		TargetState.Z = 0;


		display_drv_show_abort_msg();


	} else {

		error = 1;
	}

	return error;

}

void pus_service129_set_flight_plan_ready() {

	FlightPlanReady = 1;

}

uint8_t pus_service129_check_flight_plan() {

	return FlightPlanReady;

}

void pus_service129_drone_take_off() {

	CurrentState.X = 0.0;
	CurrentState.Y = 0.0;
	CurrentState.Z = 0.0;

	DroneFlying = 1;
	DroneAbortFlight = 0;
	emu_uah_drone_take_off();

	TargetState.X = 0.0;
	TargetState.Y = 0.0;
	TargetState.Z = ZMinBeforeAdvance;

}

void pus_service129_drone_on_ground() {

	FlightPlanReady = 0;
	DroneFlying = 0;
	DroneAbortFlight = 0;

	emu_uah_drone_on_ground();

	CurrentState.X = 0.0;
	CurrentState.Y = 0.0;
	CurrentState.Z = 0.0;

	TargetState.X = 0.0;
	TargetState.Y = 0.0;
	TargetState.Z = 0.0;

	DroneVeloc.Vx = 0;
	DroneVeloc.Vy = 0;
	DroneVeloc.Vz = 0;
	pus_service129_update_system_data_pool();
}

enum FlightStage pus_service129_apply_ctrl_algorithm(
		enum FlightStage currenStage) {

	flight_ctrl_t flight_ctrl;
	enum FlightStage nextStage = currenStage;
	float XYDistanceStartLanding = ZDroneFlightPlan - ZMinBeforeAdvance;
	float abs_error;
	//Calculate Control

	flight_ctrl = drone_flight_pid_ctrl(&CurrentState, &TargetState,
			DroneVeloc.Vx, DroneVeloc.Vy, DroneVeloc.Vz, &DronePID_Params);

	//Emu apply forces
	DroneVeloc = emu_uah_drone_apply_control(&CurrentState, flight_ctrl.Fx,
			flight_ctrl.Fy, flight_ctrl.Fz);

	if (DroneAbortFlight) {
		DroneAbortFlight = 0;
		nextStage = DroneLanding;
	} else {

		switch (currenStage) {
		case (DroneTakeOff):

			abs_error = get_abs_error(ZMinBeforeAdvance, CurrentState.Z);

			if (POS_TARGET_ERROR > abs_error) {
				if (XDroneFlightPlan > 0)
					TargetState.X = XDroneFlightPlan - XYDistanceStartLanding;
				else
					TargetState.X = XDroneFlightPlan + XYDistanceStartLanding;
				if (YDroneFlightPlan > 0)
					TargetState.Y = YDroneFlightPlan - XYDistanceStartLanding;
				else
					TargetState.Y = YDroneFlightPlan + XYDistanceStartLanding;
				TargetState.Z = ZDroneFlightPlan;
				nextStage = DroneAdvance;
			}

			break;
		case (DroneAdvance):

			abs_error = get_abs_error(CurrentState.X, TargetState.X)
					+ get_abs_error(CurrentState.Y, TargetState.Y);

			if (POS_TARGET_ERROR > abs_error) {

				TargetState.X = XDroneFlightPlan;
				TargetState.Y = YDroneFlightPlan;
				TargetState.Z = 0;
				nextStage = DroneLanding;
			}

			break;
		case (DroneLanding):

			abs_error = get_abs_error(CurrentState.Z, 0);

			if (POS_TARGET_ERROR / 40 > abs_error) {

				nextStage = DroneLanded;

			}

			break;

		default:
			break;

		}
	}
	//Wind emulation
	if (CurrentState.Z > ZMinBeforeAdvance) {

		WindEmulation = (10.0 + CurrentState.Z/2.0)*4096/60.0  ;
	} else
		WindEmulation =  (10.0 + CurrentState.Z/4.0)*4096/60.0 ;

	return nextStage;

}

void pus_service129_update_system_data_pool() {

	//Set SystemDataPool parameters

	sys_data_pool_set_int16_param(UAH_DRONE_X,
			(int16_t) (CurrentState.X * 100.0));

	sys_data_pool_set_int16_param(UAH_DRONE_Y,
			(int16_t) (int16_t) (CurrentState.Y * 100.0));

	sys_data_pool_set_int16_param(UAH_DRONE_Z,
			(int16_t) (int16_t) (CurrentState.Z * 100.0));

	sys_data_pool_set_int16_param(UAH_DRONE_VX,
			(int16_t) (DroneVeloc.Vx * 1000.0));

	sys_data_pool_set_int16_param(UAH_DRONE_VY,
			(int16_t) (DroneVeloc.Vy * 1000.0));

	sys_data_pool_set_int16_param(UAH_DRONE_VZ,
			(int16_t) (DroneVeloc.Vz * 1000.0));

	sys_data_pool_set_uint32_param(UAH_DRONE_Wind, (uint32_t) WindEmulation);

	display_drv_show_X_Y_Z((int8_t) CurrentState.X, (int8_t) CurrentState.Y,
			(int8_t) CurrentState.Z);

}

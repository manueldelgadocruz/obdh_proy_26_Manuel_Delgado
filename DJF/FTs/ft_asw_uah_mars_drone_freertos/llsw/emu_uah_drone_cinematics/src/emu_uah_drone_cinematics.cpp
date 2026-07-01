/*
 * emu_uah_exp_cinematics.cpp
 *
 *  Created on: May 7, 2024
 *      Author: opolo70
 */


#include "public/emu_uah_drone_cinematics.h"
#include "public/edroombp.h"

#define MarsGC 3.721

double DroneMass=1.0;

struct uah_drone_veloc DroneVelocity;

Pr_Time RefTime;

void emu_uah_drone_on_ground(){

	DroneVelocity.Vx=0;
	DroneVelocity.Vy=0;
	DroneVelocity.Vz=0;

}


/**
 * \brief Drone Take_off.
 *
 */
void emu_uah_drone_take_off(){

	RefTime.GetTime();
	DroneVelocity.Vx=0;
	DroneVelocity.Vy=0;
	DroneVelocity.Vz=0;

}

struct uah_drone_veloc emu_uah_drone_apply_control(
		uah_drone_state_t *p_current_state,
		double Fx, double Fy, double Fz){

	Pr_Time aux;

	double interval;

	aux.GetTime();
	aux-=RefTime;

	interval=aux.FineTime();

	p_current_state->X+=DroneVelocity.Vx*interval;
	p_current_state->Y+=DroneVelocity.Vy*interval;
	p_current_state->Z+=DroneVelocity.Vz*interval;

	//Se actualiza el tiempo de referencia:
	RefTime.GetTime();

	DroneVelocity.Vx+=(Fx/DroneMass)*interval;
	DroneVelocity.Vy+=(Fy/DroneMass)*interval;
	DroneVelocity.Vz+=((Fz - MarsGC)/DroneMass)*interval;


	return DroneVelocity;
}

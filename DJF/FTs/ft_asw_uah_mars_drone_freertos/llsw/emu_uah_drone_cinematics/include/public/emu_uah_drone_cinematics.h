/*
 * emu_exp_sim_cinematics.h
 *
 *  Created on: May 7, 2024
 *      Author: opolo70
 */

#ifndef LLSW_EMU_UAH_DRONE_CINEMATICS_INCLUDE_PUBLIC_EMU_UAH_DRONE_CINEMATICS_H_
#define LLSW_EMU_UAH_DRONE_CINEMATICS_INCLUDE_PUBLIC_EMU_UAH_DRONE_CINEMATICS_H_

#ifdef __cplusplus
extern "C" {
#endif

struct uah_drone_state{
	double X;
	double Y;
	double Z;
};

typedef struct uah_drone_state uah_drone_state_t;

struct uah_drone_veloc{
 double Vx;
 double Vy;
 double Vz;
};

typedef struct uah_drone_veloc uah_drone_veloc_t;

/**
 * \brief Update Drone status when drone is on ground.
 *
 */
void emu_uah_drone_on_ground();


/**
 * \brief Drone Take_off.
 *
 */
void emu_uah_drone_take_off();


/**
 * \brief Update Drone Velocity after forces applied.
 *
 * \param Fx applied force in x axis
 * \param Fy applied force in y axis
 * \param Fz applied force in z axis
 *
 * \return the drone velocity as struct uah_drone_veloc
 */
uah_drone_veloc_t emu_uah_drone_apply_control(uah_drone_state_t *p_current_state
										,double Fx, double Fy, double Fz);




#ifdef __cplusplus
}
#endif





#endif /* LLSW_EMU_UAH_DRONE_CINEMATICS_INCLUDE_PUBLIC_EMU_UAH_DRONE_CINEMATICS_H_ */

/*
 * display_drv.h
 *
 *  Created on: May 1, 2026
 *      Author: opolo70
 */

#ifndef LLSW_EMU_DISPLAY_DRV_INCLUDE_PUBLIC_DISPLAY_DRV_H_
#define LLSW_EMU_DISPLAY_DRV_INCLUDE_PUBLIC_DISPLAY_DRV_H_

#include "public/config.h"
#include "public/basic_types.h"

void display_drv_show_abort_msg();

void display_drv_show_X_Y_Z(int8_t X, int8_t Y, uint8_t Z);

#endif /* LLSW_EMU_DISPLAY_DRV_INCLUDE_PUBLIC_DISPLAY_DRV_H_ */

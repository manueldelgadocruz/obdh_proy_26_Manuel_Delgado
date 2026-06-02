/*
 * ut_ccdrone_time_stamp.cpp
 *
 *  Created on: Apr 21, 2026
 *      Author: opolo70
 */

#include "public/edroombp.h"

extern "C" double ut_ccdrone_mng_get_time_stamp(){

	 Pr_Time aux;
	 aux.GetTime();

	 return aux.FineTime();

}

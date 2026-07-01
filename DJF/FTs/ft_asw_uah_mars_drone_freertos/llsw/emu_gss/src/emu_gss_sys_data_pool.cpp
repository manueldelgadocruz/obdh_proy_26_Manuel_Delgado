/*
 * emu_gss_sys_data_pool.cpp
 *
 *  Created on: Nov 7, 2024
 *      Author: opolo70
 */

#include "emu_gss/emu_gss_sys_data_pool.h"

#define SID0_ParamNum 6

double SID0_Slope[SID0_ParamNum] = { 20.0 / 4096, 20.0 / 4096, 20.0 / 4096, 20.0
		/ 4096, 10.0 / 4096, 60.0 / 4096 };

float SID0_Intercept[SID0_ParamNum] = { -10, -10, -10, -10, -10, 0 };

const char *SID0_Param0_Desc = "V5: ";
const char *SID0_Param1_Desc = "V3.3: ";
const char *SID0_Param2_Desc = "I5: ";
const char *SID0_Param3_Desc = "I3.3: ";
const char *SID0_Param4_Desc = "Temp: ";
const char *SID0_Param5_Desc = "Wind: ";


const char *SID0_Desc[SID0_ParamNum] = { SID0_Param0_Desc, SID0_Param1_Desc,
		SID0_Param2_Desc, SID0_Param3_Desc, SID0_Param4_Desc, SID0_Param5_Desc };


const char *SID0_Param0_Unit = "volts";
const char *SID0_Param1_Unit = "volts";
const char *SID0_Param2_Unit = "mA";
const char *SID0_Param3_Unit = "mA";
const char *SID0_Param4_Unit = "degree";
const char *SID0_Param5_Unit = "m/s";


const char *SID0_Units[SID0_ParamNum] = { SID0_Param0_Unit, SID0_Param1_Unit,
		SID0_Param2_Unit, SID0_Param3_Unit, SID0_Param4_Unit, SID0_Param5_Unit };

void GSSSysDataPool::ShowPIDValue(uint16_t pid,
		data_pool_item_t data_item_raw) {

	data_pool_item_type_t data_type;
	data_type = sys_data_pool_item_type(pid);

	switch (data_type) {

	case (uint32_item_type):


		if ((0 <= pid) && (pid < SID0_ParamNum)) {


			printf("%s", SID0_Desc[pid]);

			float pid_value = data_item_raw.uint32_data * SID0_Slope[pid]
					+ SID0_Intercept[pid];



			printf("%.2f ", pid_value);
			printf("%s", SID0_Units[pid]);

			if (UAH_DRONE_Temp == pid)
					printf("\n\t\t\t\t\t");

		} else {

			printf("0x%X", data_item_raw.uint32_data);

		}

		break;
	case (uint8_item_type):

		if (pid > 15) {
			printf("0x%x", data_item_raw.uint8_data);
		} else {
			printf("%d", data_item_raw.uint8_data);
		}
		break;
	case (int16_item_type): {
		float meters = data_item_raw.int16_data;

		switch (pid) {

		case (UAH_DRONE_X):
			meters = meters / 100.0;
			printf("X= ");
			printf("%.2f", meters);
			printf(" m");

			break;
		case (UAH_DRONE_Y):
			meters = meters / 100.0;
			printf("Y= ");
			printf("%.2f", meters);
			printf(" m");

			break;
		case (UAH_DRONE_Z):
			meters = meters / 100.0;
			printf("Z= ");
			printf("%.2f", meters);
			printf(" m");

			break;
		case (UAH_DRONE_VX):
			meters = meters / 1000.0;
			printf("\n\t\t\t\t\t Vx= ");
			printf("%.2f", meters);
			printf(" m/s");

			break;
		case (UAH_DRONE_VY):
			meters = meters / 1000.0;
			printf("Vy= ");
			printf("%.2f", meters);
			printf(" m/s");
			break;
		case (UAH_DRONE_VZ):
			meters = meters / 1000.0;
			printf("Vz= ");
			printf("%.2f", meters);
			printf(" m/s");

			break;
		default:
			printf("%i", data_item_raw.int16_data);
			break;

		}
		break;
	}
	default:
		break;
	}

}


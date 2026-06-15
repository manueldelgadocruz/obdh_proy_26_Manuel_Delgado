################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../llsw/freertos_osswr/Source/croutine.c \
../llsw/freertos_osswr/Source/event_groups.c \
../llsw/freertos_osswr/Source/list.c \
../llsw/freertos_osswr/Source/queue.c \
../llsw/freertos_osswr/Source/stream_buffer.c \
../llsw/freertos_osswr/Source/tasks.c \
../llsw/freertos_osswr/Source/timers.c 

C_DEPS += \
./llsw/freertos_osswr/Source/croutine.d \
./llsw/freertos_osswr/Source/event_groups.d \
./llsw/freertos_osswr/Source/list.d \
./llsw/freertos_osswr/Source/queue.d \
./llsw/freertos_osswr/Source/stream_buffer.d \
./llsw/freertos_osswr/Source/tasks.d \
./llsw/freertos_osswr/Source/timers.d 

OBJS += \
./llsw/freertos_osswr/Source/croutine.o \
./llsw/freertos_osswr/Source/event_groups.o \
./llsw/freertos_osswr/Source/list.o \
./llsw/freertos_osswr/Source/queue.o \
./llsw/freertos_osswr/Source/stream_buffer.o \
./llsw/freertos_osswr/Source/tasks.o \
./llsw/freertos_osswr/Source/timers.o 


# Each subdirectory must supply rules for building sources it contributes
llsw/freertos_osswr/Source/%.o: ../llsw/freertos_osswr/Source/%.c llsw/freertos_osswr/Source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/atcsol/obdh_proy_26_Manuel_Delgado/DJF/ITs/it_asw_ccdronemng_freertos_hito3/llsw/freertos_osswr/Source/include" -I"/home/atcsol/obdh_proy_26_Manuel_Delgado/DJF/ITs/it_asw_ccdronemng_freertos_hito3/llsw/emu_display_drv/include" -I"/home/atcsol/obdh_proy_26_Manuel_Delgado/DJF/ITs/it_asw_ccdronemng_freertos_hito3/llsw/emu_uah_drone_cinematics/include" -I"/home/atcsol/obdh_proy_26_Manuel_Delgado/DJF/ITs/it_asw_ccdronemng_freertos_hito3/service_libraries/drone_flight_pid_ctrl/include" -I"/home/atcsol/obdh_proy_26_Manuel_Delgado/DJF/ITs/it_asw_ccdronemng_freertos_hito3/service_libraries/drone_flight_pid_ctrl/include" -I"/home/atcsol/obdh_proy_26_Manuel_Delgado/DJF/ITs/it_asw_ccdronemng_freertos_hito3/llsw/emu_uah_drone_cinematics/include" -I"/home/atcsol/obdh_proy_26_Manuel_Delgado/DJF/ITs/it_asw_ccdronemng_freertos_hito3/asw/dataclasses/CDDroneConfig/include" -I"/home/atcsol/obdh_proy_26_Manuel_Delgado/DJF/ITs/it_asw_ccdronemng_freertos_hito3/llsw/tc_rate_ctrl/include" -I"/home/atcsol/obdh_proy_26_Manuel_Delgado/DJF/ITs/it_asw_ccdronemng_freertos_hito3/service_libraries/pus_services/pus_service129/include" -I"/home/atcsol/obdh_proy_26_Manuel_Delgado/DJF/ITs/it_asw_ccdronemng_freertos_hito3/service_libraries/pus_services/pus_service04/include" -I"/home/atcsol/obdh_proy_26_Manuel_Delgado/DJF/ITs/it_asw_ccdronemng_freertos_hito3/llsw/emu_watchdog_drv/include" -I"/home/atcsol/obdh_proy_26_Manuel_Delgado/DJF/ITs/it_asw_ccdronemng_freertos_hito3/llsw/device_drv/include" -I"/home/atcsol/obdh_proy_26_Manuel_Delgado/DJF/ITs/it_asw_ccdronemng_freertos_hito3/service_libraries/pus_services/pus_service02/include" -I"/home/atcsol/obdh_proy_26_Manuel_Delgado/DJF/ITs/it_asw_ccdronemng_freertos_hito3/service_libraries/pus_services/pus_service19/include" -I"/home/atcsol/obdh_proy_26_Manuel_Delgado/DJF/ITs/it_asw_ccdronemng_freertos_hito3/service_libraries/pus_services/pus_service12/include" -I"/home/atcsol/obdh_proy_26_Manuel_Delgado/DJF/ITs/it_asw_ccdronemng_freertos_hito3/service_libraries/pus_services/include" -I"/home/atcsol/obdh_proy_26_Manuel_Delgado/DJF/ITs/it_asw_ccdronemng_freertos_hito3/service_libraries/pus_services/pus_service20/include" -I"/home/atcsol/obdh_proy_26_Manuel_Delgado/DJF/ITs/it_asw_ccdronemng_freertos_hito3/service_libraries/pus_services/pus_service05/include" -I"/home/atcsol/obdh_proy_26_Manuel_Delgado/DJF/ITs/it_asw_ccdronemng_freertos_hito3/service_libraries/pus_services/pus_service03/include" -I"/home/atcsol/obdh_proy_26_Manuel_Delgado/DJF/ITs/it_asw_ccdronemng_freertos_hito3/service_libraries/pus_services/pus_sys_data_pool/include" -I"/home/atcsol/obdh_proy_26_Manuel_Delgado/DJF/ITs/it_asw_ccdronemng_freertos_hito3/service_libraries/pus_services/pus_tm_handler/include" -I"/home/atcsol/obdh_proy_26_Manuel_Delgado/DJF/ITs/it_asw_ccdronemng_freertos_hito3/service_libraries/pus_services/pus_service01/include" -I"/home/atcsol/obdh_proy_26_Manuel_Delgado/DJF/ITs/it_asw_ccdronemng_freertos_hito3/service_libraries/pus_services/pus_service17/include" -I"/home/atcsol/obdh_proy_26_Manuel_Delgado/DJF/ITs/it_asw_ccdronemng_freertos_hito3/service_libraries/pus_services/pus_tm_handler/include" -I"/home/atcsol/obdh_proy_26_Manuel_Delgado/DJF/ITs/it_asw_ccdronemng_freertos_hito3/llsw/obt_drv/include" -I"/home/atcsol/obdh_proy_26_Manuel_Delgado/DJF/ITs/it_asw_ccdronemng_freertos_hito3/service_libraries/pus_services/pus_tc_handler/include" -I"/home/atcsol/obdh_proy_26_Manuel_Delgado/DJF/ITs/it_asw_ccdronemng_freertos_hito3/service_libraries/pus_services/pus_tc_accept_report/include" -I"/home/atcsol/obdh_proy_26_Manuel_Delgado/DJF/ITs/it_asw_ccdronemng_freertos_hito3/llsw/emu_hw_timecode_drv/include" -I"/home/atcsol/obdh_proy_26_Manuel_Delgado/DJF/ITs/it_asw_ccdronemng_freertos_hito3/llsw/emu_adc_drv/include" -I"/home/atcsol/obdh_proy_26_Manuel_Delgado/DJF/ITs/it_asw_ccdronemng_freertos_hito3/asw/edroom_glue/include" -I"/home/atcsol/obdh_proy_26_Manuel_Delgado/DJF/ITs/it_asw_ccdronemng_freertos_hito3/service_libraries/crc/include" -I"/home/atcsol/obdh_proy_26_Manuel_Delgado/DJF/ITs/it_asw_ccdronemng_freertos_hito3/service_libraries/edroomsl/edroombp/include" -I"/home/atcsol/obdh_proy_26_Manuel_Delgado/DJF/ITs/it_asw_ccdronemng_freertos_hito3/llsw/emu_gss/include" -I"/home/atcsol/obdh_proy_26_Manuel_Delgado/DJF/ITs/it_asw_ccdronemng_freertos_hito3/service_libraries/ccsds_pus/include" -I"/home/atcsol/obdh_proy_26_Manuel_Delgado/DJF/ITs/it_asw_ccdronemng_freertos_hito3/llsw/tmtc_dyn_mem/include" -I"/home/atcsol/obdh_proy_26_Manuel_Delgado/DJF/ITs/it_asw_ccdronemng_freertos_hito3/service_libraries/serialize/include" -I"/home/atcsol/obdh_proy_26_Manuel_Delgado/DJF/ITs/it_asw_ccdronemng_freertos_hito3/llsw/config/include" -I"/home/atcsol/obdh_proy_26_Manuel_Delgado/DJF/ITs/it_asw_ccdronemng_freertos_hito3/llsw/emu_sc_channel_drv/include" -I"/home/atcsol/obdh_proy_26_Manuel_Delgado/DJF/ITs/it_asw_ccdronemng_freertos_hito3/llsw/sc_channel_drv/include" -I"/home/atcsol/obdh_proy_26_Manuel_Delgado/DJF/ITs/it_asw_ccdronemng_freertos_hito3/llsw/config/include" -I"/home/atcsol/obdh_proy_26_Manuel_Delgado/DJF/ITs/it_asw_ccdronemng_freertos_hito3/llsw/freertos_osswr" -I"/home/atcsol/obdh_proy_26_Manuel_Delgado/DJF/ITs/it_asw_ccdronemng_freertos_hito3/llsw/freertos_osswr/Source/portable/ThirdParty/GCC/Posix" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-llsw-2f-freertos_osswr-2f-Source

clean-llsw-2f-freertos_osswr-2f-Source:
	-$(RM) ./llsw/freertos_osswr/Source/croutine.d ./llsw/freertos_osswr/Source/croutine.o ./llsw/freertos_osswr/Source/event_groups.d ./llsw/freertos_osswr/Source/event_groups.o ./llsw/freertos_osswr/Source/list.d ./llsw/freertos_osswr/Source/list.o ./llsw/freertos_osswr/Source/queue.d ./llsw/freertos_osswr/Source/queue.o ./llsw/freertos_osswr/Source/stream_buffer.d ./llsw/freertos_osswr/Source/stream_buffer.o ./llsw/freertos_osswr/Source/tasks.d ./llsw/freertos_osswr/Source/tasks.o ./llsw/freertos_osswr/Source/timers.d ./llsw/freertos_osswr/Source/timers.o

.PHONY: clean-llsw-2f-freertos_osswr-2f-Source


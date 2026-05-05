################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../service_libraries/emu_tc_programming/src/emu_tc_programming_st01_st17.cpp \
../service_libraries/emu_tc_programming/src/emu_tc_programming_st03.cpp \
../service_libraries/emu_tc_programming/src/emu_tc_programming_st20.cpp 

CPP_DEPS += \
./service_libraries/emu_tc_programming/src/emu_tc_programming_st01_st17.d \
./service_libraries/emu_tc_programming/src/emu_tc_programming_st03.d \
./service_libraries/emu_tc_programming/src/emu_tc_programming_st20.d 

OBJS += \
./service_libraries/emu_tc_programming/src/emu_tc_programming_st01_st17.o \
./service_libraries/emu_tc_programming/src/emu_tc_programming_st03.o \
./service_libraries/emu_tc_programming/src/emu_tc_programming_st20.o 


# Each subdirectory must supply rules for building sources it contributes
service_libraries/emu_tc_programming/src/%.o: ../service_libraries/emu_tc_programming/src/%.cpp service_libraries/emu_tc_programming/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	sparc-gaisler-rtems5-g++ -I/opt/rcc-1.3.2-gcc/sparc-gaisler-rtems5/leon3/lib/include -I"/home/opolo70/OBDH_2026-workspace/asw_pus_rtems_5_0_leon3_st20_resuelto/asw/components/cchk_fdirmng/include" -I"/home/opolo70/OBDH_2026-workspace/asw_pus_rtems_5_0_leon3_st20_resuelto/llsw/emu_watchdog_drv/include" -I"/home/opolo70/OBDH_2026-workspace/asw_pus_rtems_5_0_leon3_st20_resuelto/llsw/device_drv/include" -I"/home/opolo70/OBDH_2026-workspace/asw_pus_rtems_5_0_leon3_st20_resuelto/asw/components/ccbkgtcexec/include" -I"/home/opolo70/OBDH_2026-workspace/asw_pus_rtems_5_0_leon3_st20_resuelto/asw/components/uah_asw/include" -I"/home/opolo70/OBDH_2026-workspace/asw_pus_rtems_5_0_leon3_st20_resuelto/asw/components/cctcmanager/include" -I"/home/opolo70/OBDH_2026-workspace/asw_pus_rtems_5_0_leon3_st20_resuelto/asw/edroom_glue/include" -I"/home/opolo70/OBDH_2026-workspace/asw_pus_rtems_5_0_leon3_st20_resuelto/asw/dataclasses/CDTCExecCtrl/include" -I"/home/opolo70/OBDH_2026-workspace/asw_pus_rtems_5_0_leon3_st20_resuelto/asw/dataclasses/CDTCAcceptReport/include" -I"/home/opolo70/OBDH_2026-workspace/asw_pus_rtems_5_0_leon3_st20_resuelto/asw/dataclasses/CDTCMemDescriptor/include" -I"/home/opolo70/OBDH_2026-workspace/asw_pus_rtems_5_0_leon3_st20_resuelto/asw/dataclasses/CDEvAction/include" -I"/home/opolo70/OBDH_2026-workspace/asw_pus_rtems_5_0_leon3_st20_resuelto/asw/dataclasses/CDTCHandler/include" -I"/home/opolo70/OBDH_2026-workspace/asw_pus_rtems_5_0_leon3_st20_resuelto/service_libraries/pus_services/pus_service20/include" -I"/home/opolo70/OBDH_2026-workspace/asw_pus_rtems_5_0_leon3_st20_resuelto/service_libraries/pus_services/pus_sys_data_pool/include" -I"/home/opolo70/OBDH_2026-workspace/asw_pus_rtems_5_0_leon3_st20_resuelto/service_libraries/pus_services/pus_service03/include" -I"/home/opolo70/OBDH_2026-workspace/asw_pus_rtems_5_0_leon3_st20_resuelto/service_libraries/pus_services/pus_tm_handler/include" -I"/home/opolo70/OBDH_2026-workspace/asw_pus_rtems_5_0_leon3_st20_resuelto/service_libraries/pus_services/pus_service17/include" -I"/home/opolo70/OBDH_2026-workspace/asw_pus_rtems_5_0_leon3_st20_resuelto/service_libraries/pus_services/pus_service01/include" -I"/home/opolo70/OBDH_2026-workspace/asw_pus_rtems_5_0_leon3_st20_resuelto/service_libraries/pus_services/pus_tc_handler/include" -I"/home/opolo70/OBDH_2026-workspace/asw_pus_rtems_5_0_leon3_st20_resuelto/service_libraries/pus_services/pus_tc_accept_report/include" -I"/home/opolo70/OBDH_2026-workspace/asw_pus_rtems_5_0_leon3_st20_resuelto/service_libraries/pus_services/include" -I"/home/opolo70/OBDH_2026-workspace/asw_pus_rtems_5_0_leon3_st20_resuelto/service_libraries/crc/include" -I"/home/opolo70/OBDH_2026-workspace/asw_pus_rtems_5_0_leon3_st20_resuelto/service_libraries/ccsds_pus/include" -I"/home/opolo70/OBDH_2026-workspace/asw_pus_rtems_5_0_leon3_st20_resuelto/service_libraries/serialize/include" -I"/home/opolo70/OBDH_2026-workspace/asw_pus_rtems_5_0_leon3_st20_resuelto/service_libraries/edroomsl/edroombp/include" -I"/home/opolo70/OBDH_2026-workspace/asw_pus_rtems_5_0_leon3_st20_resuelto/service_libraries/edroomsl/edroomsl/include" -I"/home/opolo70/OBDH_2026-workspace/asw_pus_rtems_5_0_leon3_st20_resuelto/service_libraries/edroomsl/edroomsl_types/include" -I"/home/opolo70/OBDH_2026-workspace/asw_pus_rtems_5_0_leon3_st20_resuelto/llsw/emu_gss/include" -I"/home/opolo70/OBDH_2026-workspace/asw_pus_rtems_5_0_leon3_st20_resuelto/llsw/emu_adc_drv/include" -I"/home/opolo70/OBDH_2026-workspace/asw_pus_rtems_5_0_leon3_st20_resuelto/llsw/emu_hw_timecode_drv/include" -I"/home/opolo70/OBDH_2026-workspace/asw_pus_rtems_5_0_leon3_st20_resuelto/llsw/tc_rate_ctrl/include" -I"/home/opolo70/OBDH_2026-workspace/asw_pus_rtems_5_0_leon3_st20_resuelto/llsw/tc_queue_drv/include" -I"/home/opolo70/OBDH_2026-workspace/asw_pus_rtems_5_0_leon3_st20_resuelto/llsw/config/include" -I"/home/opolo70/OBDH_2026-workspace/asw_pus_rtems_5_0_leon3_st20_resuelto/llsw/obt_drv/include" -I"/home/opolo70/OBDH_2026-workspace/asw_pus_rtems_5_0_leon3_st20_resuelto/llsw/sc_channel_drv/include" -I"/home/opolo70/OBDH_2026-workspace/asw_pus_rtems_5_0_leon3_st20_resuelto/llsw/emu_sc_channel_drv/include" -I"/home/opolo70/OBDH_2026-workspace/asw_pus_rtems_5_0_leon3_st20_resuelto/llsw/tmtc_dyn_mem/include" -I"/home/opolo70/OBDH_2026-workspace/asw_pus_rtems_5_0_leon3_st20_resuelto/llsw/rtems_osswr/include" -O0 -g3 -Wall -c -fmessage-length=0 -mcpu=leon3 -qbsp=leon3 -msoft-float -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-service_libraries-2f-emu_tc_programming-2f-src

clean-service_libraries-2f-emu_tc_programming-2f-src:
	-$(RM) ./service_libraries/emu_tc_programming/src/emu_tc_programming_st01_st17.d ./service_libraries/emu_tc_programming/src/emu_tc_programming_st01_st17.o ./service_libraries/emu_tc_programming/src/emu_tc_programming_st03.d ./service_libraries/emu_tc_programming/src/emu_tc_programming_st03.o ./service_libraries/emu_tc_programming/src/emu_tc_programming_st20.d ./service_libraries/emu_tc_programming/src/emu_tc_programming_st20.o

.PHONY: clean-service_libraries-2f-emu_tc_programming-2f-src


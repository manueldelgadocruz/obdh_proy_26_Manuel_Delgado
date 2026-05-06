################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../llsw/emu_display_drv/src/emu_display_drv.c 

C_DEPS += \
./llsw/emu_display_drv/src/emu_display_drv.d 

OBJS += \
./llsw/emu_display_drv/src/emu_display_drv.o 


# Each subdirectory must supply rules for building sources it contributes
llsw/emu_display_drv/src/%.o: ../llsw/emu_display_drv/src/%.c llsw/emu_display_drv/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/opolo70/OBDH_2026_Proy-workspace/ft_uah_mars_drone_freertos_hito3/llsw/freertos_osswr/Source/include" -I"/home/opolo70/OBDH_2026_Proy-workspace/ft_uah_mars_drone_freertos_hito3/llsw/emu_display_drv/include" -I"/home/opolo70/OBDH_2026_Proy-workspace/ft_uah_mars_drone_freertos_hito3/llsw/emu_uah_drone_cinematics/include" -I"/home/opolo70/OBDH_2026_Proy-workspace/ft_uah_mars_drone_freertos_hito3/service_libraries/drone_flight_pid_ctrl/include" -I"/home/opolo70/OBDH_2026_Proy-workspace/ft_uah_mars_drone_freertos_hito3/service_libraries/drone_flight_pid_ctrl/include" -I"/home/opolo70/OBDH_2026_Proy-workspace/ft_uah_mars_drone_freertos_hito3/llsw/emu_uah_drone_cinematics/include" -I"/home/opolo70/OBDH_2026_Proy-workspace/ft_uah_mars_drone_freertos_hito3/asw/dataclasses/CDDroneConfig/include" -I"/home/opolo70/OBDH_2026_Proy-workspace/ft_uah_mars_drone_freertos_hito3/llsw/tc_rate_ctrl/include" -I"/home/opolo70/OBDH_2026_Proy-workspace/ft_uah_mars_drone_freertos_hito3/service_libraries/pus_services/pus_service129/include" -I"/home/opolo70/OBDH_2026_Proy-workspace/ft_uah_mars_drone_freertos_hito3/llsw/emu_watchdog_drv/include" -I"/home/opolo70/OBDH_2026_Proy-workspace/ft_uah_mars_drone_freertos_hito3/llsw/device_drv/include" -I"/home/opolo70/OBDH_2026_Proy-workspace/ft_uah_mars_drone_freertos_hito3/service_libraries/pus_services/include" -I"/home/opolo70/OBDH_2026_Proy-workspace/ft_uah_mars_drone_freertos_hito3/service_libraries/pus_services/pus_service05/include" -I"/home/opolo70/OBDH_2026_Proy-workspace/ft_uah_mars_drone_freertos_hito3/service_libraries/pus_services/pus_sys_data_pool/include" -I"/home/opolo70/OBDH_2026_Proy-workspace/ft_uah_mars_drone_freertos_hito3/service_libraries/pus_services/pus_tm_handler/include" -I"/home/opolo70/OBDH_2026_Proy-workspace/ft_uah_mars_drone_freertos_hito3/service_libraries/pus_services/pus_service01/include" -I"/home/opolo70/OBDH_2026_Proy-workspace/ft_uah_mars_drone_freertos_hito3/service_libraries/pus_services/pus_tm_handler/include" -I"/home/opolo70/OBDH_2026_Proy-workspace/ft_uah_mars_drone_freertos_hito3/llsw/obt_drv/include" -I"/home/opolo70/OBDH_2026_Proy-workspace/ft_uah_mars_drone_freertos_hito3/service_libraries/pus_services/pus_tc_handler/include" -I"/home/opolo70/OBDH_2026_Proy-workspace/ft_uah_mars_drone_freertos_hito3/service_libraries/pus_services/pus_tc_accept_report/include" -I"/home/opolo70/OBDH_2026_Proy-workspace/ft_uah_mars_drone_freertos_hito3/llsw/emu_hw_timecode_drv/include" -I"/home/opolo70/OBDH_2026_Proy-workspace/ft_uah_mars_drone_freertos_hito3/llsw/emu_adc_drv/include" -I"/home/opolo70/OBDH_2026_Proy-workspace/ft_uah_mars_drone_freertos_hito3/asw/edroom_glue/include" -I"/home/opolo70/OBDH_2026_Proy-workspace/ft_uah_mars_drone_freertos_hito3/service_libraries/crc/include" -I"/home/opolo70/OBDH_2026_Proy-workspace/ft_uah_mars_drone_freertos_hito3/service_libraries/edroomsl/edroombp/include" -I"/home/opolo70/OBDH_2026_Proy-workspace/ft_uah_mars_drone_freertos_hito3/llsw/emu_gss/include" -I"/home/opolo70/OBDH_2026_Proy-workspace/ft_uah_mars_drone_freertos_hito3/service_libraries/ccsds_pus/include" -I"/home/opolo70/OBDH_2026_Proy-workspace/ft_uah_mars_drone_freertos_hito3/llsw/tmtc_dyn_mem/include" -I"/home/opolo70/OBDH_2026_Proy-workspace/ft_uah_mars_drone_freertos_hito3/service_libraries/serialize/include" -I"/home/opolo70/OBDH_2026_Proy-workspace/ft_uah_mars_drone_freertos_hito3/llsw/config/include" -I"/home/opolo70/OBDH_2026_Proy-workspace/ft_uah_mars_drone_freertos_hito3/llsw/emu_sc_channel_drv/include" -I"/home/opolo70/OBDH_2026_Proy-workspace/ft_uah_mars_drone_freertos_hito3/llsw/sc_channel_drv/include" -I"/home/opolo70/OBDH_2026_Proy-workspace/ft_uah_mars_drone_freertos_hito3/llsw/config/include" -I"/home/opolo70/OBDH_2026_Proy-workspace/ft_uah_mars_drone_freertos_hito3/llsw/freertos_osswr" -I"/home/opolo70/OBDH_2026_Proy-workspace/ft_uah_mars_drone_freertos_hito3/llsw/freertos_osswr/Source/portable/ThirdParty/GCC/Posix" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-llsw-2f-emu_display_drv-2f-src

clean-llsw-2f-emu_display_drv-2f-src:
	-$(RM) ./llsw/emu_display_drv/src/emu_display_drv.d ./llsw/emu_display_drv/src/emu_display_drv.o

.PHONY: clean-llsw-2f-emu_display_drv-2f-src


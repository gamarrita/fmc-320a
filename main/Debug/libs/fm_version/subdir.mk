################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/githubs/fmc-320a/libs/fm_version/fm_version.c 

OBJS += \
./libs/fm_version/fm_version.o 

C_DEPS += \
./libs/fm_version/fm_version.d 


# Each subdirectory must supply rules for building sources it contributes
libs/fm_version/fm_version.o: D:/githubs/fmc-320a/libs/fm_version/fm_version.c libs/fm_version/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L452xx -DTX_INCLUDE_USER_DEFINE_FILE -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../AZURE_RTOS/App -I../Middlewares/ST/threadx/common/inc/ -I../Middlewares/ST/threadx/ports/cortex_m4/gnu/inc/ -I../Middlewares/ST/threadx/utility/low_power/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-libs-2f-fm_version

clean-libs-2f-fm_version:
	-$(RM) ./libs/fm_version/fm_version.cyclo ./libs/fm_version/fm_version.d ./libs/fm_version/fm_version.o ./libs/fm_version/fm_version.su

.PHONY: clean-libs-2f-fm_version


################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/githubs/fmc-320a/libs/fm_keypad/fm_keypad.c 

OBJS += \
./libs/fm_keypad/fm_keypad.o 

C_DEPS += \
./libs/fm_keypad/fm_keypad.d 


# Each subdirectory must supply rules for building sources it contributes
libs/fm_keypad/fm_keypad.o: D:/githubs/fmc-320a/libs/fm_keypad/fm_keypad.c libs/fm_keypad/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L452xx -DTX_INCLUDE_USER_DEFINE_FILE -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../AZURE_RTOS/App -I../Middlewares/ST/threadx/common/inc/ -I../Middlewares/ST/threadx/ports/cortex_m4/gnu/inc/ -I../Middlewares/ST/threadx/utility/low_power/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-libs-2f-fm_keypad

clean-libs-2f-fm_keypad:
	-$(RM) ./libs/fm_keypad/fm_keypad.cyclo ./libs/fm_keypad/fm_keypad.d ./libs/fm_keypad/fm_keypad.o ./libs/fm_keypad/fm_keypad.su

.PHONY: clean-libs-2f-fm_keypad


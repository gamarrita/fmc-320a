################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/githubs/fmc-320a/libs/fm_debug/fm_debug.c 

OBJS += \
./libs/fm_debug/fm_debug.o 

C_DEPS += \
./libs/fm_debug/fm_debug.d 


# Each subdirectory must supply rules for building sources it contributes
libs/fm_debug/fm_debug.o: D:/githubs/fmc-320a/libs/fm_debug/fm_debug.c libs/fm_debug/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L452xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-libs-2f-fm_debug

clean-libs-2f-fm_debug:
	-$(RM) ./libs/fm_debug/fm_debug.cyclo ./libs/fm_debug/fm_debug.d ./libs/fm_debug/fm_debug.o ./libs/fm_debug/fm_debug.su

.PHONY: clean-libs-2f-fm_debug


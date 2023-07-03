################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/led.c 

OBJS += \
./Inc/led.o 

C_DEPS += \
./Inc/led.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/%.o Inc/%.su Inc/%.cyclo: ../Inc/%.c Inc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -c -I../Inc -I/home/parth/Work/RTOS/cube/new_led/chip_headers/Include/ -I/home/parth/Work/RTOS/cube/new_led/chip_headers/Device/ST/STM32F0xx/Include/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Inc

clean-Inc:
	-$(RM) ./Inc/led.cyclo ./Inc/led.d ./Inc/led.o ./Inc/led.su

.PHONY: clean-Inc


################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/led.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/uart.c 

OBJS += \
./Src/led.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/uart.o 

C_DEPS += \
./Src/led.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -c -I../Inc -I/home/parth/Work/RTOS/cube/new_led/chip_headers/Include/ -I/home/parth/Work/RTOS/cube/new_led/chip_headers/Device/ST/STM32F0xx/Include/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/led.cyclo ./Src/led.d ./Src/led.o ./Src/led.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su ./Src/uart.cyclo ./Src/uart.d ./Src/uart.o ./Src/uart.su

.PHONY: clean-Src


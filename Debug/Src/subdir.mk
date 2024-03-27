################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/ADC.c \
../Src/ConFig.c \
../Src/HeadLight.c \
../Src/Indicators.c \
../Src/UART.c \
../Src/UARTCall.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/ADC.o \
./Src/ConFig.o \
./Src/HeadLight.o \
./Src/Indicators.o \
./Src/UART.o \
./Src/UARTCall.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/ADC.d \
./Src/ConFig.d \
./Src/HeadLight.d \
./Src/Indicators.d \
./Src/UART.d \
./Src/UARTCall.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F405RGTx -c -I../Inc -I"C:/Users/XVX2KOR/Desktop/Training/STM-32/Headers/include" -I"C:/Users/XVX2KOR/Desktop/Training/STM-32/Headers/core" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/ADC.d ./Src/ADC.o ./Src/ADC.su ./Src/ConFig.d ./Src/ConFig.o ./Src/ConFig.su ./Src/HeadLight.d ./Src/HeadLight.o ./Src/HeadLight.su ./Src/Indicators.d ./Src/Indicators.o ./Src/Indicators.su ./Src/UART.d ./Src/UART.o ./Src/UART.su ./Src/UARTCall.d ./Src/UARTCall.o ./Src/UARTCall.su ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src


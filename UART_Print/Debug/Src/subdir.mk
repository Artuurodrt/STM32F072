################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/main.c \
../Src/printf-stdarg.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/system_stm32f0xx.c \
../Src/systemclk_Config.c \
../Src/uartPrint.c \
../Src/userLed.c 

OBJS += \
./Src/main.o \
./Src/printf-stdarg.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/system_stm32f0xx.o \
./Src/systemclk_Config.o \
./Src/uartPrint.o \
./Src/userLed.o 

C_DEPS += \
./Src/main.d \
./Src/printf-stdarg.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/system_stm32f0xx.d \
./Src/systemclk_Config.d \
./Src/uartPrint.d \
./Src/userLed.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F0 -DSTM32F072RBTx -DNUCLEO_F072RB -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/main.d ./Src/main.o ./Src/printf-stdarg.d ./Src/printf-stdarg.o ./Src/syscalls.d ./Src/syscalls.o ./Src/sysmem.d ./Src/sysmem.o ./Src/system_stm32f0xx.d ./Src/system_stm32f0xx.o ./Src/systemclk_Config.d ./Src/systemclk_Config.o ./Src/uartPrint.d ./Src/uartPrint.o ./Src/userLed.d ./Src/userLed.o

.PHONY: clean-Src


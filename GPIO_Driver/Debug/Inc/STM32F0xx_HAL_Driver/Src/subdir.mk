################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal.c \
../Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_cortex.c \
../Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_dma.c \
../Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_exti.c \
../Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_flash.c \
../Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_flash_ex.c \
../Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_gpio.c \
../Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_i2c.c \
../Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_i2c_ex.c \
../Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_pwr.c \
../Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_pwr_ex.c \
../Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_rcc.c \
../Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_rcc_ex.c \
../Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_tim.c \
../Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_tim_ex.c \
../Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_uart.c \
../Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_uart_ex.c 

OBJS += \
./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal.o \
./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_cortex.o \
./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_dma.o \
./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_exti.o \
./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_flash.o \
./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_flash_ex.o \
./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_gpio.o \
./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_i2c.o \
./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_i2c_ex.o \
./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_pwr.o \
./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_pwr_ex.o \
./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_rcc.o \
./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_rcc_ex.o \
./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_tim.o \
./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_tim_ex.o \
./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_uart.o \
./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_uart_ex.o 

C_DEPS += \
./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal.d \
./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_cortex.d \
./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_dma.d \
./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_exti.d \
./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_flash.d \
./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_flash_ex.d \
./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_gpio.d \
./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_i2c.d \
./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_i2c_ex.d \
./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_pwr.d \
./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_pwr_ex.d \
./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_rcc.d \
./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_rcc_ex.d \
./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_tim.d \
./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_tim_ex.d \
./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_uart.d \
./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_uart_ex.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/STM32F0xx_HAL_Driver/Src/%.o: ../Inc/STM32F0xx_HAL_Driver/Src/%.c Inc/STM32F0xx_HAL_Driver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F0 -DSTM32F072RBTx -DNUCLEO_F072RB -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Inc-2f-STM32F0xx_HAL_Driver-2f-Src

clean-Inc-2f-STM32F0xx_HAL_Driver-2f-Src:
	-$(RM) ./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal.d ./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal.o ./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_cortex.d ./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_cortex.o ./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_dma.d ./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_dma.o ./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_exti.d ./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_exti.o ./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_flash.d ./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_flash.o ./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_flash_ex.d ./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_flash_ex.o ./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_gpio.d ./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_gpio.o ./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_i2c.d ./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_i2c.o ./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_i2c_ex.d ./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_i2c_ex.o ./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_pwr.d ./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_pwr.o ./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_pwr_ex.d ./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_pwr_ex.o ./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_rcc.d ./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_rcc.o ./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_rcc_ex.d ./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_rcc_ex.o ./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_tim.d ./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_tim.o ./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_tim_ex.d ./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_tim_ex.o ./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_uart.d ./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_uart.o ./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_uart_ex.d ./Inc/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_uart_ex.o

.PHONY: clean-Inc-2f-STM32F0xx_HAL_Driver-2f-Src


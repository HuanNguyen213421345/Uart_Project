################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Array_Lib/Array_Lib.c 

OBJS += \
./Drivers/Array_Lib/Array_Lib.o 

C_DEPS += \
./Drivers/Array_Lib/Array_Lib.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Array_Lib/%.o Drivers/Array_Lib/%.su Drivers/Array_Lib/%.cyclo: ../Drivers/Array_Lib/%.c Drivers/Array_Lib/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/ASUS/STM32CubeIDE/workspace_1.16.1/UART_Project/Drivers/Array_Lib" -I"C:/Users/ASUS/STM32CubeIDE/workspace_1.16.1/UART_Project/UART_MiddleWare" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-Array_Lib

clean-Drivers-2f-Array_Lib:
	-$(RM) ./Drivers/Array_Lib/Array_Lib.cyclo ./Drivers/Array_Lib/Array_Lib.d ./Drivers/Array_Lib/Array_Lib.o ./Drivers/Array_Lib/Array_Lib.su

.PHONY: clean-Drivers-2f-Array_Lib


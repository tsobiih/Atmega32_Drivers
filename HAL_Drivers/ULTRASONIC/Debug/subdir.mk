################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_program.c \
../GIE_program.c \
../TIMER2_program.c \
../UART_program.c \
../ULTRASONIC_program.c \
../main.c 

OBJS += \
./DIO_program.o \
./GIE_program.o \
./TIMER2_program.o \
./UART_program.o \
./ULTRASONIC_program.o \
./main.o 

C_DEPS += \
./DIO_program.d \
./GIE_program.d \
./TIMER2_program.d \
./UART_program.d \
./ULTRASONIC_program.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



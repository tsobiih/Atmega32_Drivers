################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_program.c \
../GIE_program.c \
../PWM_program.c \
../TIMER0_program.c \
../main.c 

OBJS += \
./DIO_program.o \
./GIE_program.o \
./PWM_program.o \
./TIMER0_program.o \
./main.o 

C_DEPS += \
./DIO_program.d \
./GIE_program.d \
./PWM_program.d \
./TIMER0_program.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



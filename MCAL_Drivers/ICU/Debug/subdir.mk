################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CLCD_Program.c \
../DIO_program.c \
../GIE_program.c \
../TIMER0_program.c \
../TIMER1_program.c \
../main.c 

OBJS += \
./CLCD_Program.o \
./DIO_program.o \
./GIE_program.o \
./TIMER0_program.o \
./TIMER1_program.o \
./main.o 

C_DEPS += \
./CLCD_Program.d \
./DIO_program.d \
./GIE_program.d \
./TIMER0_program.d \
./TIMER1_program.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CLCD_Program.c \
../DIO_program.c \
../SLAVE_main.c \
../SPI_program.c 

OBJS += \
./CLCD_Program.o \
./DIO_program.o \
./SLAVE_main.o \
./SPI_program.o 

C_DEPS += \
./CLCD_Program.d \
./DIO_program.d \
./SLAVE_main.d \
./SPI_program.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



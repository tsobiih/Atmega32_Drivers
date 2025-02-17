#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "EXTI0_interface.h"
#include "GIE_interface.h"



int DC_MOTOR_ON_OFF_FLAG = 0;



int main(void)
{
	EXTI0_voidInit();  // Initialize EXTI0 with falling edge trigger
	EXTI0_voidEnable();
	GIE_voidEnable();  // Enable global interrupts

    DIO_voidSetPinDirection(DIO_u8PORTC, DIO_u8PIN0, DIO_u8OUTPUT);  // LED output
    DIO_voidSetPinDirection(DIO_u8PORTD, DIO_u8PIN2, DIO_u8INPUT);   // Switch input
    DIO_voidSetPinValue(DIO_u8PORTD, DIO_u8PIN2, DIO_u8HIGH);        // Enable pull-up resistor



    while(1)
    {
        // Main loop
    }
}

void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	GIE_voidDisable();
	if ( (DC_MOTOR_ON_OFF_FLAG % 2) == 0) {
		DIO_voidSetPinValue(DIO_u8PORTC, DIO_u8PIN0, DIO_u8HIGH);  // Turn on LED when interrupt occurs
		DC_MOTOR_ON_OFF_FLAG++;
	}
	else {
		DIO_voidSetPinValue(DIO_u8PORTC, DIO_u8PIN0, DIO_u8LOW);  // Turn on LED when interrupt occurs
		DC_MOTOR_ON_OFF_FLAG++;
	}
	GIE_voidEnable();
}

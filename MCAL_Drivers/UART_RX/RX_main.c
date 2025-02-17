#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "UART_interface.h"
#include "util/delay.h"
#include "CLCD_Interface.h"

int main(void)
{
	u8 CompareValue=0;
	//PWM PIN3
	DIO_voidSetPinDirection(DIO_u8PORTB , DIO_u8PIN3 , DIO_u8OUTPUT);

	//TX Pin
	DIO_voidSetPinDirection(DIO_u8PORTA , DIO_u8PIN1 , DIO_u8OUTPUT );

	//RX Pin
	DIO_voidSetPinDirection(DIO_u8PORTA , DIO_u8PIN0 , DIO_u8INPUT );


	UART_voidInit();
	CLCD_voidInit();
	TIMER0_voidInit();

	while(1)
	{
		CompareValue = UART_u8ReceiveData();

		TIMER0_voidSetCompareValue(CompareValue);

		CLCD_voidClearDisplay();
		CLCD_voidSendInteger(CompareValue);
	}
}

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"

#include "DIO_interface.h"
#include "WDT_interface.h"


int main(void)
{
	WDT_voidInit();

	DIO_voidSetPinDirection(DIO_u8PORTA , DIO_u8PIN0 , DIO_u8OUTPUT);
	DIO_voidSetPinDirection(DIO_u8PORTA , DIO_u8PIN1 , DIO_u8OUTPUT);
	DIO_voidSetPinValue(DIO_u8PORTA , DIO_u8PIN0 , DIO_u8LOW);
	DIO_voidSetPinValue(DIO_u8PORTA , DIO_u8PIN1 , DIO_u8LOW);
	_delay_ms(500);

	while(1)
	{
		DIO_voidSetPinValue(DIO_u8PORTA , DIO_u8PIN0 , DIO_u8HIGH);
		DIO_voidSetPinValue(DIO_u8PORTA , DIO_u8PIN1 , DIO_u8HIGH);
		WDT_voidReset();
	}
}

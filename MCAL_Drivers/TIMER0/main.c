
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "TIMER0_interface.h"
#include "GIE_interface.h"

void LED(void);

int main(void)
{
	DIO_voidSetPinDirection(DIO_u8PORTB , DIO_u8PIN3 , DIO_u8OUTPUT);

	TIMER0_voidInit();

	TIMER0_voidSetCallBack(LED);

	GIE_voidEnable();

	while(1)
	{

	}
}


void LED(void)
{
	static u16 Local_u16Counter=0;
	static u8 Local_u8LedState=0;

	Local_u16Counter++;
	if(Local_u16Counter == 4000)
	{
		TOGGLE_BIT(Local_u8LedState , 0);
		DIO_voidSetPinValue(DIO_u8PORTA , DIO_u8PIN0 , Local_u8LedState);

		Local_u16Counter=0;
	}

}

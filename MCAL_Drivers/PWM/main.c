
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"


#include "PWM_interface.h"
#include "DIO_interface.h"
#include "TIMER0_interface.h"


int main(void)
{
	DIO_voidSetPortDirection(DIO_u8PORTB , DIO_u8PIN3 , DIO_u8OUTPUT);
	TIMER0_voidSetCompareValue(128);
	TIMER0_voidInit();

	DIO_voidSetPortDirection(DIO_u8PORTD , DIO_u8PIN5 , DIO_u8INPUT);


	while(1)
	{


	}
}


//void DC_Motor(void)
//{
//	static u16 Local_u16Counter=0;
//
//	Local_u16Counter++;
//	DIO_voidSetPinValue(DIO_u8PORTD , DIO_u8PIN4 , DIO_u8HIGH);
//	if(Local_u16Counter > 0 && Local_u16Counter <= 100)
//	{
//		DIO_voidSetPinValue(DIO_u8PORTD , DIO_u8PIN4 , DIO_u8HIGH);
//	}
//	else if(Local_u16Counter > 100 && Local_u16Counter <= 160)
//	{
//		DIO_voidSetPinValue(DIO_u8PORTD , DIO_u8PIN4 , DIO_u8LOW);
//		DIO_voidSetPinValue(DIO_u8PORTD , DIO_u8PIN5 , DIO_u8HIGH);
//	}
//	else if(Local_u16Counter > 160 && Local_u16Counter <= 260)
//	{
//		DIO_voidSetPinValue(DIO_u8PORTD , DIO_u8PIN4 , DIO_u8LOW);
//		DIO_voidSetPinValue(DIO_u8PORTD , DIO_u8PIN5 , DIO_u8LOW);
//	}
//	else
//	{
//		Local_u16Counter=0;
//	}
//}

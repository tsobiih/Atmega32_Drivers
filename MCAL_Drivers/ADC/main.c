#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"

#include "DIO_interface.h"
#include "ADC_interface.h"
#include "CLCD_Interface.h"

int main(void)
{
	u16 Reading;
	u16 Temp;
	u16 LastTemp=100;
	
	DIO_voidSetPinDirection(DIO_u8PORTB , DIO_u8PIN6 , DIO_u8OUTPUT);
	DIO_voidSetPinDirection(DIO_u8PORTB , DIO_u8PIN7 , DIO_u8OUTPUT);

	DIO_voidSetPinDirection(DIO_u8PORTA , DIO_u8PIN0 , DIO_u8INPUT);

	CLCD_voidInit();
	ADC_voidInit();
//	CLCD_voidSendInteger(50);

	while(1)
	{
		Reading = ADC_u16ReadChannel(0);
		Temp = Reading*0.4883;
		if(LastTemp != Temp)
		{
			CLCD_voidClearDisplay();
			CLCD_voidSendInteger(Temp);
			LastTemp = Temp;
		}


		if(Temp > 35)
		{
			DIO_voidSetPinValue(DIO_u8PORTB , DIO_u8PIN6 , DIO_u8LOW);

		}
		else
		{
			DIO_voidSetPinValue(DIO_u8PORTB , DIO_u8PIN6 , DIO_u8HIGH);
		}
		if(Temp > 40)
		{
			DIO_voidSetPinValue(DIO_u8PORTB , DIO_u8PIN7 , DIO_u8HIGH);
			_delay_ms(200);
			DIO_voidSetPinValue(DIO_u8PORTB , DIO_u8PIN7 , DIO_u8LOW);
			_delay_ms(200);
		}
		else
		{
		    DIO_voidSetPinValue(DIO_u8PORTB , DIO_u8PIN7 , DIO_u8HIGH);
		}
	}
}



























//		if(Reading < 128)		DIO_voidSetPortValue(DIO_u8PORTD , 0b00000000);
//		else if(Reading<256)	DIO_voidSetPortValue(DIO_u8PORTD , 0b00000001);
//		else if(Reading<384)	DIO_voidSetPortValue(DIO_u8PORTD , 0b00000011);
//		else if(Reading<512)	DIO_voidSetPortValue(DIO_u8PORTD , 0b00000111);
//		else if(Reading<637)	DIO_voidSetPortValue(DIO_u8PORTD , 0b00001111);
//		else if(Reading<765)	DIO_voidSetPortValue(DIO_u8PORTD , 0b00011111);
//		else if(Reading<893)	DIO_voidSetPortValue(DIO_u8PORTD , 0b00111111);
//		else if(Reading<1021)	DIO_voidSetPortValue(DIO_u8PORTD , 0b01111111);

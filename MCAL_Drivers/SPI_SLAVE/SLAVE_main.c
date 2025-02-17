#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SPI_interface.h"
#include "CLCD_Interface.h"

int main(void)
{
	u8 Local_u8Temp;
	u8 LastTemp=0;

	//MOSI PIN : output
	DIO_voidSetPinDirection(DIO_u8PORTB , DIO_u8PIN5 , DIO_u8INPUT);

	//Miso PIN : intput
	DIO_voidSetPinDirection(DIO_u8PORTB , DIO_u8PIN6 , DIO_u8OUTPUT);

	//SCK PIN
	DIO_voidSetPinDirection(DIO_u8PORTB , DIO_u8PIN7 , DIO_u8INPUT);

	// SS PIN
	DIO_voidSetPinDirection(DIO_u8PORTB , DIO_u8PIN4 , DIO_u8INPUT);

	//Motor PIN
	DIO_voidSetPinDirection(DIO_u8PORTA , DIO_u8PIN0 , DIO_u8OUTPUT);

	CLCD_voidInit();
	SPI_voidInit();

	while(1)
	{
		Local_u8Temp = SPI_u8Transceiver(0);

		if(LastTemp != Local_u8Temp)
		{
			CLCD_voidClearDisplay();
			CLCD_voidSendInteger(Local_u8Temp);
			LastTemp = Local_u8Temp;
		}

		if(Local_u8Temp > 26)
		{
			DIO_voidSetPinValue(DIO_u8PORTA , DIO_u8PIN0 , DIO_u8HIGH);
		}
		else
		{
			DIO_voidSetPinValue(DIO_u8PORTA , DIO_u8PIN0 , DIO_u8LOW);
		}
	}
}

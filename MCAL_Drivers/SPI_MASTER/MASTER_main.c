#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"

#include "CLCD_Interface.h"
#include "ADC_interface.h"
#include "DIO_interface.h"
#include "SPI_interface.h"

int main(void)
{
	u16 Reading;
	u8 Temp;
//	u8 LastTemp=0;//

	//MOSI PIN : output
	DIO_voidSetPinDirection(DIO_u8PORTB , DIO_u8PIN5 , DIO_u8OUTPUT);
	//Miso PIN : intput
	DIO_voidSetPinDirection(DIO_u8PORTB , DIO_u8PIN6 , DIO_u8INPUT);
	//SCK PIN
	DIO_voidSetPinDirection(DIO_u8PORTB , DIO_u8PIN7 , DIO_u8OUTPUT);
	// SS PIN
	DIO_voidSetPinDirection(DIO_u8PORTB , DIO_u8PIN4 , DIO_u8OUTPUT);
	//ADC channle input
	DIO_voidSetPinDirection(DIO_u8PORTA , DIO_u8PIN0 , DIO_u8INPUT);

	CLCD_voidInit();
	ADC_voidInit();
	SPI_voidInit();

	while(1)
	{
		Reading = ADC_u16ReadChannel(0);
		Temp = Reading*0.4883;
		SPI_u8Transceiver(Temp);

//		if(LastTemp != Temp)
//		{
//			CLCD_voidClearDisplay();
//			CLCD_voidSendInteger(Temp);
//			LastTemp = Temp;
//		}
	}
}

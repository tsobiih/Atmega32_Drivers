#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <string.h>
#include <stdio.h>

#include "DIO_interface.h"
#include "UART_interface.h"
#include "InfraRed_Interface.h"

int main(void)
{
	u8 MSensor;
	u8 LSensor;
	u8 RSensor;

//	DIO_voidSetPinDirection(DIO_u8PORTB , DIO_u8PIN1 , DIO_u8OUTPUT );
//	DIO_voidSetPinValue(DIO_u8PORTB , DIO_u8PIN1 , DIO_u8HIGH );

	InfraRed_voidInit();

	while(1)
	{
		 MSensor = InfraRed_u8GetFrontRead();
		 LSensor = InfraRed_u8GetLeftRead();
		 RSensor = InfraRed_u8GetRightRead();  // || LSensor==1 || RSensor==1

//		 if (MSensor == 1)
//		 {
//				DIO_voidSetPinValue(DIO_u8PORTB , DIO_u8PIN1 , DIO_u8LOW );
//		 }
//		 else
//		 {
//				DIO_voidSetPinValue(DIO_u8PORTB , DIO_u8PIN1 , DIO_u8HIGH );
//		 }

	}
}

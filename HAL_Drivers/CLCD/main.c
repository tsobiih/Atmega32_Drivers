/*
 * main.c
 *
 *  Created on: Sep 14, 2024
 *      Author: elwady
 */
#include <stdio.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"

#include "CLCD_Config.h"
#include "DIO_interface.h"
#include "CLCD_Interface.h"

int main(void)
{
//	u8 heart[6] = {
//	    0b00100,
//	    0b00100,
//	    0b01110,
//	    0b11111,
//	    0b11111,
//	    0b01110,
//		0b00000,
//		0b00000
//	};

	DIO_voidSetPortDirection(DIO_u8PORTA , DIO_u8PORTOUTPUT);

	DIO_voidSetPinDirection(DIO_u8PORTC , DIO_u8PIN0 , DIO_u8OUTPUT);
	DIO_voidSetPinDirection(DIO_u8PORTC , DIO_u8PIN1 , DIO_u8OUTPUT);
	DIO_voidSetPinDirection(DIO_u8PORTC , DIO_u8PIN2 , DIO_u8OUTPUT);

	CLCD_voidInit();

//	CLCD_voidSetXYPosition(2 , 0);

//	CLCD_voidSendString("Tarek Sobih");
//	CLCD_voidSendInteger(3);
//	while(1)
//	{

	CLCD_voidSendFloat(1354.45557);

//	}
//	return 0;

}

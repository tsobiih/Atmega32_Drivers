
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "SS_interface.h"
#include "SS_private.h"
#include "SS_config.h"

u8 Local_SS_NumberArray[11] ={    
    0xC0, // 0
    0xF9, // 1
    0xA4, // 2
    0xB0, // 3
    0x99, // 4
    0x92, // 5
    0x82, // 6
    0xF8, // 7
    0x80, // 8
    0x90
} ;

void SS_voidInitializPort(u8 Copy_u8Port)
{
	DIO_voidSetPortDirection(Copy_u8Port , 0xff);
}


void SS_voidSetNumber(u8 Copy_u8Port , u8 Copy_u8Number)
{
	switch(Copy_u8Port)
	{
	case DIO_u8PORTA : DIO_voidSetPortValue(DIO_u8PORTA , Local_SS_NumberArray[Copy_u8Number]); break;
	case DIO_u8PORTB : DIO_voidSetPortValue(DIO_u8PORTB , Local_SS_NumberArray[Copy_u8Number]); break;
	case DIO_u8PORTC : DIO_voidSetPortValue(DIO_u8PORTC , Local_SS_NumberArray[Copy_u8Number]); break;
	case DIO_u8PORTD : DIO_voidSetPortValue(DIO_u8PORTD , Local_SS_NumberArray[Copy_u8Number]); break;
	}

}

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"

#include "DIO_interface.h"

int main(void)
{
//    u8 Local_u8Switch;
    DIO_voidSetPinDirection(DIO_u8PORTA , DIO_u8PIN0 , DIO_u8OUTPUT);
    DIO_voidSetPinValue(DIO_u8PORTA , DIO_u8PIN0 , DIO_u8HIGH);
//    DIO_voidSetPinDirection(DIO_u8PORTD , DIO_u8PIN0 , DIO_u8INPUT);
//    DIO_voidSetPinValue(DIO_u8PORTD , DIO_u8PIN0 , DIO_u8HIGH);
//
//    while(1)
//    {
//        Local_u8Switch = DIO_u8GetPinValue(DIO_u8PORTD , DIO_u8PIN0);
//        if(Local_u8Switch == DIO_u8LOW)
//        {
//            DIO_voidSetPinValue(DIO_u8PORTA , DIO_u8PIN0 , DIO_u8HIGH);
//        }
//        else
//        {
//            DIO_voidSetPinValue(DIO_u8PORTA , DIO_u8PIN0 , DIO_u8LOW);
//        }
//    }
}

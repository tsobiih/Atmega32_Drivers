#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"

#include "DIO_interface.h"
#include "KPD_interface.h"
#include "CLCD_Interface.h"
#include "SS_interface.h"

int main(void)
{
    u8 Local_u8Key = NOT_PRESSED;

    DIO_voidSetPortDirection(DIO_u8PORTA, DIO_u8PORTOUTPUT);

    DIO_voidSetPinDirection(DIO_u8PORTC, DIO_u8PIN0, DIO_u8OUTPUT);
    DIO_voidSetPinDirection(DIO_u8PORTC, DIO_u8PIN1, DIO_u8OUTPUT);
    DIO_voidSetPinDirection(DIO_u8PORTC, DIO_u8PIN2, DIO_u8OUTPUT);

    CLCD_voidInit();
    KPD_voidInit();

    while(1)
    {
        Local_u8Key = KPD_u8GetPressedKey();
        if(Local_u8Key != NOT_PRESSED)
        {
            CLCD_voidSendData(Local_u8Key);
            if( CLR_SCREAN == Local_u8Key)
			{
				CLCD_voidClearDisplay();
			}
        }

    }
}

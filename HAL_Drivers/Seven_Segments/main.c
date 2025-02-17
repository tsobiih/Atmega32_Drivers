#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>


#include "DIO_interface.h"
#include "SS_interface.h"



int main(void)
{
	u8 Local_u8Counter;
	SS_voidInitializPort(DIO_u8PORTD);
	while(1)
	{
		for(Local_u8Counter = 0 ; Local_u8Counter < 10 ; Local_u8Counter++)
		{
			SS_voidSetNumber(DIO_u8PORTD , Local_u8Counter);
			_delay_ms(1000);
		}
		Local_u8Counter = 0;
	}
}

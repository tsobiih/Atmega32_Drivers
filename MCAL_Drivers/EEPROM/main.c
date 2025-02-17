#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"

#include "CLCD_Interface.h"
#include "DIO_interface.h"
#include "TWI_interface.h"
#include "EEPROM_interface.h"


int main(void)
{
	u8 Local_u8Data;

	CLCD_voidInit();

	TWI_voidMasterInit();

	EEPROM_voidWriteData( 'T' , 0 );
	Local_u8Data = EEPROM_u8ReadData(0);

	CLCD_voidSendData(Local_u8Data);
	while(1)
	{

	}
}

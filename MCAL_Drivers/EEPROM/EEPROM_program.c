#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"

#include "TWI_interface.h"
#include "EEPROM_config.h"
#include "EEPROM_interface.h"
#include "EEPROM_private.h"

void EEPROM_voidWriteData(u8 Copy_u8Data , u8 Copy_u8Address)
{
	TWI_voidSendStartCondition();
	TWI_voidSendSlaveAddressWithWrite(CHIP_ADDRESS);
	TWI_voidMasterSendDataWithAck(Copy_u8Address);
	TWI_voidMasterSendDataWithAck(Copy_u8Data);
	TWI_voidSendStopCondition();
	_delay_ms(10);
}

u8	 EEPROM_u8ReadData(u8 Copy_u8Adress)
{
	u8 Local_u8Data;
	TWI_voidSendStartCondition();
	TWI_voidSendSlaveAddressWithWrite(CHIP_ADDRESS);
	TWI_voidMasterSendDataWithAck(Copy_u8Adress);

	TWI_voidSendRepeatedStart();
	TWI_voidSendSlaveAddressWithRead(CHIP_ADDRESS);
	Local_u8Data = TWI_u8MasterReceiveDataWithNack();
	TWI_voidSendStopCondition();

	return Local_u8Data;
}

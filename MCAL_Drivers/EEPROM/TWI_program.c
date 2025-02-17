#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TWI_config.h"
#include  "TWI_interface.h"
#include "TWI_private.h"
#include "TWI_register.h"





void TWI_voidMasterInit(void)
{
	if(SLAVE_ADDRESS == NO_ADDRESS)
	{
		asm("NOP");
	}
	else
	{
		TWAR = (SLAVE_ADDRESS<<1);
	}

	CLR_BIT(TWSR , 1);
	CLR_BIT(TWSR , 0);
	TWBR = 2;
}
void TWI_voidSlaveInit(void)
{
	TWAR = (SLAVE_ADDRESS<<1);

}

void TWI_voidSendStartCondition(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	 while (!(TWCR & (1<<TWINT)))
	 {
		 asm("NOP");
	 }
}
void TWI_voidSendRepeatedStart(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	 while (!(TWCR & (1<<TWINT)))
	 {
		 asm("NOP");
	 }
}

void TWI_voidSendSlaveAddressWithWrite(u8 Copy_u8Address)
{
	 TWDR = (Copy_u8Address<<1);
	 CLR_BIT(TWDR ,0);
	 TWCR = (1<<TWINT) | (1<<TWEN);
	 while (!(TWCR & (1<<TWINT)))
	 {
		 asm("NOP");
	 }
}
void TWI_voidSendSlaveAddressWithRead(u8 Copy_u8Address)
{
	 TWDR = (Copy_u8Address<<1);
	 SET_BIT(TWDR ,0);
	 TWCR = (1<<TWINT) | (1<<TWEN);
	 while (!(TWCR & (1<<TWINT)))
	 {
		 asm("NOP");
	 }
}


void TWI_voidMasterSendDataWithAck(u8 Copy_u8Data)
{
	 TWDR = Copy_u8Data;
	 TWCR = (1<<TWINT) | (1<<TWEN)|(1<<TWEA);
	 while (!(TWCR & (1<<TWINT)))
	 {
		 asm("NOP");
	 }
}
void TWI_voidMasterSendDataWithNack(u8 Copy_u8Data)
{
	 TWDR = Copy_u8Data;
	 TWCR = (1<<TWINT) | (1<<TWEN);
	 while (!(TWCR & (1<<TWINT)))
	 {
		 asm("NOP");
	 }
}

u8 	 TWI_u8MasterReceiveDataWithAck(void)
{
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
	 while (!(TWCR & (1<<TWINT)))
	 {
		 asm("NOP");
	 }
	 return TWDR;
}

u8 	 TWI_u8MasterReceiveDataWithNack(void)
{
	TWCR = (1<<TWINT) | (1<<TWEN);
	 while (!(TWCR & (1<<TWINT)))
	 {
		 asm("NOP");
	 }
	 return TWDR;
}

void TWI_voidSendStopCondition(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}

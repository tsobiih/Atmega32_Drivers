#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"

#include "DIO_interface.h"
#include "CLCD_Interface.h"
#include "CLCD_Config.h"
#include  "CLCD_Private.h"



void CLCD_voidSendData(u8 Copy_u8Data)
{
    //Set rs pin to high for send data
    DIO_voidSetPinValue(CLCD_CTRL_PORT , CLCD_RS_PORT , DIO_u8HIGH);

    //Set rw pin to low for write
    DIO_voidSetPinValue(CLCD_CTRL_PORT , CLCD_RW_PORT , DIO_u8LOW);

    //Put data
    DIO_voidSetPortValue(CLCD_DATA_PORT , Copy_u8Data);

    //generate enable pulse
    DIO_voidSetPinValue(CLCD_CTRL_PORT , CLCD_E_PORT , DIO_u8HIGH);
    _delay_ms(2);
    DIO_voidSetPinValue(CLCD_CTRL_PORT , CLCD_E_PORT , DIO_u8LOW);

}
void CLCD_voidSendCommand(u8 Copy_u8DCommand)
{
    //Set rs pin to high for send data
    DIO_voidSetPinValue(CLCD_CTRL_PORT , CLCD_RS_PORT , DIO_u8LOW);

    //Set rw pin to low for write
    DIO_voidSetPinValue(CLCD_CTRL_PORT , CLCD_RW_PORT , DIO_u8LOW);

    //Put data
    DIO_voidSetPortValue(CLCD_DATA_PORT , Copy_u8DCommand);

    //generate enable pulse
    DIO_voidSetPinValue(CLCD_CTRL_PORT , CLCD_E_PORT , DIO_u8HIGH);
    _delay_ms(2);
    DIO_voidSetPinValue(CLCD_CTRL_PORT , CLCD_E_PORT , DIO_u8LOW);
}

void CLCD_voidClearDisplay(void)
{
	CLCD_voidSendCommand(0b00000001);
}


void CLCD_voidInit(void)
{
    //Wait for more than 30 ms
    _delay_ms(40);
    //Set Function
    CLCD_voidSendCommand(0b00111000);
    //Display ON/OFF
    CLCD_voidSendCommand(0b00001111);
    //Display Clear
    CLCD_voidSendCommand(0b00000001);
}

void CLCD_voidSendString(const char *Copy_pString)
{
	u8 Local_u8Counter=0;
	while(Copy_pString[Local_u8Counter] != '\0')
	{
		CLCD_voidSendData(Copy_pString[Local_u8Counter]);
		Local_u8Counter++;
	}
}


void CLCD_voidSendInteger(u32 Copy_u32Integer)
{
	u8 Local_u8Number[10];
	u8 i=0;
	while(Copy_u32Integer >= 10)
	{
		Local_u8Number[i] = Copy_u32Integer%10 + ZERO_ASCII;
		Copy_u32Integer = Copy_u32Integer/10;
		i++;
	}
	Local_u8Number[i] = Copy_u32Integer + ZERO_ASCII;

	for(s8 j=i ; j>=0 ; j--)
	{
		CLCD_voidSendData(Local_u8Number[j]);
	}
}



void CLCD_voidSetXYPosition(u8 Copy_u8XPositin , u8 Copy_u8YPositin)
{
	u8 Local_u8Address;

	if(Copy_u8YPositin == 0)
	{
		Local_u8Address = Copy_u8XPositin;
	}
	else if(Copy_u8YPositin == 1)
	{
		Local_u8Address = Copy_u8XPositin + 0x40;
	}
	SET_BIT(Local_u8Address , 7);

	CLCD_voidSendCommand(Local_u8Address);
}























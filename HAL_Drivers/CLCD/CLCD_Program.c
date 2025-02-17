#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"

#include "DIO_interface.h"
#include "CLCD_Interface.h"
#include "CLCD_Config.h"
#include "CLCD_Private.h"


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



void CLCD_voidScrollTextLeftToRight(char *Copy_u8Text)
{
	u8 STR_u8Lenght=0;
	while(Copy_u8Text[STR_u8Lenght] != '\0')
	{
		STR_u8Lenght++;
	}

	for(s8 position = -STR_u8Lenght ; position<=16 ; position++)
	{
		CLCD_voidSendCommand(0x01);    //Clear Display
		if(position >= 0) CLCD_voidSetXYPosition(position , 0);
		else if(position < 0) CLCD_voidSetXYPosition(0 , 0);

		for(u8 i=0 ; i<STR_u8Lenght ; i++)
		{
			if(i + position >= 0 && i + position < 16 )
			{
				CLCD_voidSendData(Copy_u8Text[i]);
			}
		}
		_delay_ms(300);
	}
}


void CLCD_voidScrollTextRightToLeft(char *Copy_u8Text)
{
    u8 STR_u8Length = 0;

    while(Copy_u8Text[STR_u8Length] != '\0')
    {
        STR_u8Length++;
    }

    for(s8 position = 16; position >= -STR_u8Length; position--)
    {
        CLCD_voidSendCommand(0x01);  //Clear display

        if(position >= 0)
        {
            CLCD_voidSetXYPosition(position, 0);
        }
        else
        {
            CLCD_voidSetXYPosition(0, 0);
        }

        for (u8 i = 0; i < STR_u8Length; i++)
        {
            if (i + position >= 0 && i + position < 16)
            {
                CLCD_voidSendData(Copy_u8Text[i]);
            }
        }

        _delay_ms(300);
    }
}


void CLCD_voidScrollTextSinsoidalwave(char *Copy_u8Text)
{
	u8 STR_u8Lenght=0;
	while(Copy_u8Text[STR_u8Lenght] != '\0')
	{
		STR_u8Lenght++;
	}

	for(s8 position = -STR_u8Lenght ; position<=16 ; position++)
	{
		CLCD_voidSendCommand(0x01);    //Clear Display
		if(position >= 0) CLCD_voidSetXYPosition(position , (position%2));
		else if(position < 0) CLCD_voidSetXYPosition(0 , 0);

		for(u8 i=0 ; i<STR_u8Lenght ; i++)
		{
			if(i + position >= 0 && i + position < 16 )
			{
				CLCD_voidSendData(Copy_u8Text[i]);
			}
		}
		_delay_ms(300);
	}
}


void CLCD_voidClearDisplay(void)
{
	CLCD_voidSendCommand(0x01);
	_delay_ms(2);
}

void CLCD_voidShift(CLCD_SHIFT Copy_enuShiftDirection)
{
	if((Copy_enuShiftDirection == CLCD_SHIFT_RIGHT)||(Copy_enuShiftDirection == CLCD_SHIFT_LEFT))
	{
		CLCD_voidSendCommand(Copy_enuShiftDirection);
	}
}


void CLCD_voidCreateShape(u8 Copy_u8Location,u8 *Copy_pu8Shape)
{
	if((Copy_u8Location <= 7) && (Copy_u8Location >= 0))
	{
		CLCD_voidSendCommand( 0x40 | (Copy_u8Location *8));
		for(u8 i = 0 ; i<8 ; i++ )
		{
			CLCD_voidSendData(Copy_pu8Shape[i]);
		}
	}
}


void CLCD_voidDrawShape(u8 Copy_u8Location)
{
	CLCD_voidSendData(Copy_u8Location);
}

void CLCD_voidSendFloat(f64 Copy_s32float)
{
	int integer_part = (int)Copy_s32float;          // Extract the integer part
	int decimal_part = (int)((Copy_s32float - integer_part) * 100);  // Extract the decimal part (2 decimal places)

	char buffer[20];  // Buffer to hold the converted string

	// Format and print the integer and decimal parts separately
	sprintf(buffer, "%d.%02d", integer_part, decimal_part);

	CLCD_voidSendString(buffer);
}










#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"

#include "DIO_interface.h"

#include "Stepper_config.h"
#include "Stepper_interface.h"


void Stepper_voidInit(void)
{
    DIO_voidSetPinDirection(CTRL_PORT , STEPPER_BLUE_PIN   , DIO_u8OUTPUT);
    DIO_voidSetPinDirection(CTRL_PORT , STEPPER_PINK_PIN   , DIO_u8OUTPUT);
    DIO_voidSetPinDirection(CTRL_PORT , STEPPER_YELLOW_PIN , DIO_u8OUTPUT);
	DIO_voidSetPinDirection(CTRL_PORT , STEPPER_ORANGE_PIN , DIO_u8OUTPUT);

}



void Stepper_voidRotateCW(u16 Copy_u8Degree)
{
	u16 Steps = Copy_u8Degree/0.703125;
	for(u16 i=0 ; i <= Steps ; i++)
	{
		DIO_voidSetPinValue(CTRL_PORT, STEPPER_BLUE_PIN  , DIO_u8HIGH);
		DIO_voidSetPinValue(CTRL_PORT, STEPPER_PINK_PIN  , DIO_u8LOW);
		DIO_voidSetPinValue(CTRL_PORT, STEPPER_YELLOW_PIN, DIO_u8LOW);
		DIO_voidSetPinValue(CTRL_PORT, STEPPER_ORANGE_PIN, DIO_u8LOW);
		_delay_ms(10); //

		//  2
		DIO_voidSetPinValue(CTRL_PORT, STEPPER_BLUE_PIN  , DIO_u8LOW);
		DIO_voidSetPinValue(CTRL_PORT, STEPPER_PINK_PIN  , DIO_u8HIGH);
		DIO_voidSetPinValue(CTRL_PORT, STEPPER_YELLOW_PIN, DIO_u8LOW);
		DIO_voidSetPinValue(CTRL_PORT, STEPPER_ORANGE_PIN, DIO_u8LOW);
		_delay_ms(10); //

		//  3
		DIO_voidSetPinValue(CTRL_PORT,STEPPER_BLUE_PIN  , DIO_u8LOW);
		DIO_voidSetPinValue(CTRL_PORT,STEPPER_PINK_PIN  , DIO_u8LOW);
		DIO_voidSetPinValue(CTRL_PORT,STEPPER_YELLOW_PIN, DIO_u8HIGH);
		DIO_voidSetPinValue(CTRL_PORT,STEPPER_ORANGE_PIN, DIO_u8LOW);
		_delay_ms(10); //

		//  4
		DIO_voidSetPinValue(CTRL_PORT, STEPPER_BLUE_PIN  , DIO_u8LOW);
		DIO_voidSetPinValue(CTRL_PORT, STEPPER_PINK_PIN  , DIO_u8LOW);
		DIO_voidSetPinValue(CTRL_PORT, STEPPER_YELLOW_PIN, DIO_u8LOW);
		DIO_voidSetPinValue(CTRL_PORT, STEPPER_ORANGE_PIN, DIO_u8HIGH);
		_delay_ms(10);
	}
}


void Stepper_voidRotateCCW(u16 Copy_u8Degree)
{
	u16 Steps = Copy_u8Degree/0.703125;
	for(u16 i=0 ; i <= Steps ; i++)
	{
		DIO_voidSetPinValue(CTRL_PORT, STEPPER_BLUE_PIN  , DIO_u8LOW);
		DIO_voidSetPinValue(CTRL_PORT, STEPPER_PINK_PIN  , DIO_u8LOW);
		DIO_voidSetPinValue(CTRL_PORT, STEPPER_YELLOW_PIN, DIO_u8LOW);
		DIO_voidSetPinValue(CTRL_PORT, STEPPER_ORANGE_PIN, DIO_u8HIGH);
		_delay_ms(10);

		//  3
		DIO_voidSetPinValue(CTRL_PORT, STEPPER_BLUE_PIN  , DIO_u8LOW);
		DIO_voidSetPinValue(CTRL_PORT, STEPPER_PINK_PIN  , DIO_u8LOW);
		DIO_voidSetPinValue(CTRL_PORT, STEPPER_YELLOW_PIN, DIO_u8HIGH);
		DIO_voidSetPinValue(CTRL_PORT, STEPPER_ORANGE_PIN, DIO_u8LOW);
		_delay_ms(10);

		//  2
		DIO_voidSetPinValue(CTRL_PORT,STEPPER_BLUE_PIN  , DIO_u8LOW);
		DIO_voidSetPinValue(CTRL_PORT,STEPPER_PINK_PIN  , DIO_u8HIGH);
		DIO_voidSetPinValue(CTRL_PORT,STEPPER_YELLOW_PIN, DIO_u8LOW);
		DIO_voidSetPinValue(CTRL_PORT,STEPPER_ORANGE_PIN, DIO_u8LOW);
		_delay_ms(10);

		//  1
		DIO_voidSetPinValue(CTRL_PORT, STEPPER_BLUE_PIN  , DIO_u8HIGH);
		DIO_voidSetPinValue(CTRL_PORT, STEPPER_PINK_PIN  , DIO_u8LOW);
		DIO_voidSetPinValue(CTRL_PORT, STEPPER_YELLOW_PIN, DIO_u8LOW);
		DIO_voidSetPinValue(CTRL_PORT, STEPPER_ORANGE_PIN, DIO_u8LOW);
		_delay_ms(10);

	}
}


void STEPPER_voidStop(void)
{
	DIO_voidSetPinValue(CTRL_PORT , STEPPER_BLUE_PIN   , DIO_u8LOW );
	DIO_voidSetPinValue(CTRL_PORT , STEPPER_PINK_PIN   , DIO_u8LOW );
	DIO_voidSetPinValue(CTRL_PORT , STEPPER_YELLOW_PIN , DIO_u8LOW );
	DIO_voidSetPinValue(CTRL_PORT , STEPPER_ORANGE_PIN , DIO_u8LOW );
}


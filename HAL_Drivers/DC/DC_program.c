#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "DC_config.h"
#include "DC_interface.h"
#include "DC_private.h"


void DC_voidInit(void)
{
	DIO_voidSetPinDirection(DC_PORT , DC_PIN0 , DIO_u8OUTPUT);
	DIO_voidSetPinDirection(DC_PORT , DC_PIN1 , DIO_u8OUTPUT);
}


void DC_voidRotateCW(void)
{
	DIO_voidSetPinValue(DC_PORT , DC_PIN0 , DIO_u8LOW);
	DIO_voidSetPinValue(DC_PORT , DC_PIN1 , DIO_u8HIGH);
}


void DC_voidRotateCounterCW(void)
{
	DIO_voidSetPinValue(DC_PORT , DC_PIN1 , DIO_u8LOW);
	DIO_voidSetPinValue(DC_PORT , DC_PIN0 , DIO_u8HIGH);
}

void DC_voidBreake(void)
{
	DIO_voidSetPinValue(DC_PORT , DC_PIN1 , DIO_u8LOW);
	DIO_voidSetPinValue(DC_PORT , DC_PIN0 , DIO_u8LOW);
}

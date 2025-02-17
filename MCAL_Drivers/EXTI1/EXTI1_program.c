#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI1_config.h"
#include "EXTI1_register.h"
#include "EXTI1_interface.h"
#include "EXTI1_private.h"


void EXTI1_voidInit(void)
{
	switch(SENSE)
	{
	case LOW_LEVEL:
		CLR_BIT(MCUCR , 2);
		CLR_BIT(MCUCR , 3);
		break;
	case ANY_CHANGE:
		CLR_BIT(MCUCR , 2);
		SET_BIT(MCUCR , 3);
		break;
	case FALLING_EDGE:
		SET_BIT(MCUCR , 2);
		CLR_BIT(MCUCR , 3);
		break;
	case RISING_EDGE:
		SET_BIT(MCUCR , 2);
		SET_BIT(MCUCR , 3);
		break;
	}
}


void EXTI1_voidSetSenseControl(u8 Copy_u8Sense)
{
	switch(Copy_u8Sense)
	{
	case LOW_LEVEL:
		CLR_BIT(MCUCR , 2);
		CLR_BIT(MCUCR , 3);
		break;
	case ANY_CHANGE:
		CLR_BIT(MCUCR , 2);
		SET_BIT(MCUCR , 3);
		break;
	case FALLING_EDGE:
		SET_BIT(MCUCR , 2);
		CLR_BIT(MCUCR , 3);
		break;
	case RISING_EDGE:
		SET_BIT(MCUCR , 2);
		SET_BIT(MCUCR , 3);
		break;
	}
}

void EXTI1_voidEnable(void)
{
	SET_BIT(GICR , 7);
}

void EXTI1_voidDisable(void)
{
	CLR_BIT(GICR , 7);
}

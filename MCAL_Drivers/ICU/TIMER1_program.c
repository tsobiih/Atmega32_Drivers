/*
 * TIMER1_program.c
 *
 *  Created on: Oct 12, 2024
 *      Author: elwady
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER1_config.h"

#include "TIMER1_interface.h"
#include "TIMER1_private.h"
#include "TIMER1_register.h"

void (*PWM_CallBackFun)(void);

void TIMER1_voidInit(void)
{
	//Set mode "fast PWM"
#if(MODE == Fast_PWM)
	{
		CLR_BIT(TCCR1A , 0);
		SET_BIT(TCCR1A , 1);
		SET_BIT(TCCR1B , 3);
		SET_BIT(TCCR1B , 4);
	}
#elif(MODE == Phase_Correct)
	{
		SET_BIT(TCCR1A , 0);
		SET_BIT(TCCR1A , 1);
		CLR_BIT(TCCR1B , 3);
		SET_BIT(TCCR1B , 4);
	}
#elif(MODE == CTC_Mode)
	{
		CLR_BIT(TCCR1A , 0);
		CLR_BIT(TCCR1A , 1);
		SET_BIT(TCCR1B , 3);
		SET_BIT(TCCR1B , 4);
	}
#elif(MODE == Normal_Mode)
	{
		CLR_BIT(TCCR1A , 0);
		CLR_BIT(TCCR1A , 1);
		CLR_BIT(TCCR1B , 3);
		CLR_BIT(TCCR1B , 4);
		TCNT1 = 0;
	}
#endif

	//set Compare output mode "1A"
#if(COM1A_MODE == Disconnected)
	{
		TCCR1A &= 0b00111111;
	}
#elif(COM1A_MODE == Toggle_On_COM)
	{
		TCCR1A &= 0b00111111;
		TCCR1A |= Toggle_COM1A_Bits;
	}
#elif(COM1A_MODE == Clear_On_COM)
	{
//		CLR_BIT(TCCR1A , 6);
//		SET_BIT(TCCR1A , 7);
		TCCR1A &= 0b00111111;
		TCCR1A |= Clear_COM1A_Bits;
	}
#elif(COM1A_MODE == Set_On_COM)
	{
		TCCR1A &= 0b00111111;
		TCCR1A |= Set_COM1A_Bits;
	}
#endif

	//set Compare output mode "1B"
#if(COM1B_MODE == Disconnected)
	{
		TCCR1A &= 0b11001111;
	}
#elif(COM1B_MODE == Toggle_On_COM)
	{
		TCCR1A &= 0b11001111;
		TCCR1A |= Toggle_COM1B_Bits;
	}
#elif(COM1B_MODE == Clear_On_COM)
	{
		TCCR1A &= 0b11001111;
		TCCR1A |= Clear_COM1B_Bits;
	}
#elif(COM1B_MODE == Set_On_COM)
	{
		TCCR1A &= 0b11001111;
		TCCR1A |= Set_COM1B_Bits;
	}
#endif

	//Set Prescaler
	TCCR1B &= 0b11111000;
	TCCR1B |= PRESCALER;

	//select edge trigre
#if(ICU_EDGE_TRIGRE == TIMER1_RISING_EDGE)
	{
		SET_BIT(TCCR1B , 6);
		SET_BIT(TCCR1B , 7);
	}
#elif(ICU_EDGE_TRIGRE == TIMER1_FALLING_EDGE)
	{
		CLR_BIT(TCCR1B , 6);
	}
#endif
}


void TIMER1_voidSetTopValue(u16 Copy_u16TopValue)
{
	ICR1 = Copy_u16TopValue;
}


void TIMER1_voidSetCompareValue(u16 Copy_u16COM1A_Value , u16 Copy_u16COM1B_Value)
{
	if(COM1B_MODE != Disconnected)
		{
		OCR1B = Copy_u16COM1B_Value;
		}
	if(COM1A_MODE != Disconnected)
		{
		OCR1A = Copy_u16COM1A_Value;
		}
}

void TIMER1_voidCallBackFunction(void (*Copy_pvCallBackFn)(void))
{
	PWM_CallBackFun = Copy_pvCallBackFn;
}

void __vector_8(void) __attribute__((signal));
void __vector_8(void)
{
	PWM_CallBackFun();
}

void __vector_9(void) __attribute__((signal));
void __vector_9(void)
{
	PWM_CallBackFun();
}


void TIMER1_voidDelaySecond(u16 Copy_u16Sec)
{
	u16 Count_Per_Sec = 7813;
	u16 overflow_counter = 0;

	while(Copy_u16Sec > 0)
	{
		TCNT1 = 0;

		while (TCNT1 < Count_Per_Sec);

		 overflow_counter++;  // Count how many times we waited

		if (overflow_counter == 1)  // 1 second passed
		{
			Copy_u16Sec--;  // Decrement the seconds remaining
			overflow_counter = 0;  // Reset overflow counter for the next second
		}

	}
}


void __vector_6(void) __attribute__((signal));
void __vector_6(void)
{
	PWM_CallBackFun();
}


u16 TIMER1_u16ReadCaptureValue(void)
{
	u16 Reading=0;
	Reading = ICR1;
	return Reading;
}


void TIMER1_voidSetICUEdgeTrigre(u8 Copy_u8Edge)			//there is edition here!!!
{
	if(Copy_u8Edge == TIMER1_RISING_EDGE)
	{
		SET_BIT(TCCR1B , 6);
	}
	else if(Copy_u8Edge == TIMER1_FALLING_EDGE)
	{
		CLR_BIT(TCCR1B , 6);
	}
}

void TIMER1_voidICUInterruptEnable(void)
{
	SET_BIT(TIMSK , 5);
}

void TIMER1_voidICUInterruptDisable(void)
{
	CLR_BIT(TIMSK , 5);
}















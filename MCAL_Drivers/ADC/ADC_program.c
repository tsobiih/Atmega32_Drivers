
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_config.h"
#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_register.h"


void ADC_voidInit(void)
{
	//select votage efrence
	#if(REFRENCE_VOLTAGE == AREF)
		CLR_BIT(ADMUX , 7);
		CLR_BIT(ADMUX , 6);
	#elif (REFRENCE_VOLTAGE == AVCC)
		CLR_BIT(ADMUX , 7);
		SET_BIT(ADMUX , 6);
	#elif(REFRENCE_VOLTAGE == INTERNAL_VOLTAGE)
		SET_BIT(ADMUX , 7);
		SET_BIT(ADMUX , 6);
	#endif


	//select prescaler
	CLR_BIT(ADCSRA , 2);
	CLR_BIT(ADCSRA , 1);
	CLR_BIT(ADCSRA , 0);

	//enable ADC
	SET_BIT(ADCSRA , 7);
}


u16 ADC_u16ReadChannel(u8 Copy_u8ChannelNumber)
{
	//Select Channel
	ADMUX &= 0b11100000;
	ADMUX |= Copy_u8ChannelNumber;

	//Start Conversion
	SET_BIT(ADCSRA , 6);

	//Polling
	while((GET_BIT(ADCSRA , 4)) != 1)
	{
		asm("NOP");
	}

	//Clear the Flag
	SET_BIT(ADCSRA , 4);

	//Return Reading
	return ADC;
}

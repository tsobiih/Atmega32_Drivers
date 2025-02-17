/*
 * ADC_register.h
 *
 *  Created on: Oct 4, 2024
 *      Author: elwady
 */

#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_

#define ADMUX			*((volatile u8*)(0x27))
#define ADCSRA			*((volatile u8*)(0x26))
#define ADC				*((volatile u16*)(0x24))
#define SFIOR			*((volatile u8*)(0x50))


#endif /* ADC_REGISTER_H_ */

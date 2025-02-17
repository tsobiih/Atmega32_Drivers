#include "STD_TYPES.h"
#include "DIO_interface.h"


#ifndef STEPPER_INTERFACE_H_
#define STEPPER_INTERFACE_H_

void STEPPER_voidStop(void);
void Stepper_voidInit(void);
void Stepper_voidRotateCW(u16 Copy_u8Degree);
void Stepper_voidRotateCCW(u16 Copy_u8Degree);

#endif /* STEPPER_INTERFACE_H_ */

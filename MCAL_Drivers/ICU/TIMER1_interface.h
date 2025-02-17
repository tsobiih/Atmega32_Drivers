
#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_

void TIMER1_voidInit(void);
void TIMER1_voidSetTopValue(u16 Copy_u16TopValue);
void TIMER1_voidSetCompareValue(u16 Copy_u16COM1A_Value , u16 Copy_u16COM1B_Value);
void TIMER1_voidCallBackFunction(void (*Copy_pvCallBackFn)(void));
void TIMER1_voidDelaySecond(u16 Copy_u16Sec);

u16 TIMER1_u16ReadCaptureValue(void);
void TIMER1_voidSetICUEdgeTrigre(u8 Copy_u8Edge);
void TIMER1_voidCallBackFunction(void (*Copy_pvCallBackFn)(void));
void TIMER1_voidICUInterruptEnable(void);
void TIMER1_voidICUInterruptDisable(void);

//
#define TIMER1_RISING_EDGE			1
#define TIMER1_FALLING_EDGE			0


//PWM mode
#define Fast_PWM					1
#define Phase_Correct				2
#define Normal_Mode					3
#define CTC_Mode					4

//Mode of COM
#define Disconnected				1
#define Toggle_On_COM               2
#define Clear_On_COM                3
#define Set_On_COM                  4

//Bits of COM1A
#define	Toggle_COM1A_Bits				0b01000000
#define Clear_COM1A_Bits				0b10000000
#define Set_COM1A_Bits					0b11000000

//Bits of COM1B
#define	Toggle_COM1B_Bits				0b00010000
#define Clear_COM1B_Bits				0b00100000
#define Set_COM1B_Bits					0b00110000

//Set Prescaler
#define DIVISION_BY_8			0b00000010
#define DIVISION_BY_1024			0b00000101

#endif /* TIMER1_INTERFACE_H_ */

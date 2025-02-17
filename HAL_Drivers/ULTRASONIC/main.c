#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "util/delay.h"

#include "UART_interface.h"
#include "DIO_interface.h"
#include "ULTRASONIC_interface.h"

int main(void)
{
	char str[10];
	f32 distance=0.0;
	u8 Switch;

	DIO_voidSetPinDirection(DIO_u8PORTD , DIO_u8PIN0 , DIO_u8INPUT);
	DIO_voidSetPinDirection(DIO_u8PORTD , DIO_u8PIN1 , DIO_u8OUTPUT);

	UART_voidInit();
	ULTRASONIC_voidInit();

	DIO_voidSetPinDirection(DIO_u8PORTB , DIO_u8PIN2 , DIO_u8OUTPUT);
	DIO_voidSetPinValue(DIO_u8PORTB , DIO_u8PIN2 , DIO_u8HIGH);

	while(1)
	{
			Switch = UART_u8ReceiveData();

			if(Switch == 'K' )
			{
				DIO_voidSetPinValue(DIO_u8PORTB , DIO_u8PIN2, DIO_u8LOW);
				_delay_ms(200);
				DIO_voidSetPinValue(DIO_u8PORTB , DIO_u8PIN2 , DIO_u8HIGH);
				UART_voidSendData('K');
			}
			else if(Switch == 'S')
			{
				DIO_voidSetPinValue(DIO_u8PORTB , DIO_u8PIN2 , DIO_u8LOW);
				_delay_ms(200);
				DIO_voidSetPinValue(DIO_u8PORTB , DIO_u8PIN2 , DIO_u8HIGH);
				UART_voidSendString("OK");
			}
			else if(Switch == 'F')
			{
				DIO_voidSetPinValue(DIO_u8PORTB , DIO_u8PIN2, DIO_u8LOW);
				_delay_ms(200);
				DIO_voidSetPinValue(DIO_u8PORTB , DIO_u8PIN2 , DIO_u8HIGH);
				distance = ULTRASONIC_f32GetFrontDistance();
				_delay_ms(20);
				dtostrf(distance, 10 , 2, str);
				UART_voidSendString(str);
			}
			else if(Switch == 'L')
			{
				DIO_voidSetPinValue(DIO_u8PORTB , DIO_u8PIN2, DIO_u8LOW);
				_delay_ms(200);
				DIO_voidSetPinValue(DIO_u8PORTB , DIO_u8PIN2 , DIO_u8HIGH);
				distance = ULTRASONIC_f32GetLeftDistance();
				_delay_ms(20);
				dtostrf(distance, 10 , 2, str);
				UART_voidSendString(str);
			}
			else if(Switch == 'R')
			{
				DIO_voidSetPinValue(DIO_u8PORTB , DIO_u8PIN2, DIO_u8LOW);
				_delay_ms(200);
				DIO_voidSetPinValue(DIO_u8PORTB , DIO_u8PIN2 , DIO_u8HIGH);
				distance = ULTRASONIC_f32GetRightDistance();
				_delay_ms(20);
				dtostrf(distance, 10 , 2, str);
				UART_voidSendString(str);
			}

	}
}

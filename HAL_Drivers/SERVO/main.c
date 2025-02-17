
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"

#include "SERVO_interface.h"
#include "PWM_interface.h"
#include "DIO_interface.h"


int main(void)
{
	SERVO_voidInit();

	while(1)
	{
		SERVO_voidSetPosition(0);
		_delay_ms(500);
		SERVO_voidSetPosition(90);
		_delay_ms(500);
		SERVO_voidSetPosition(180);
		_delay_ms(500);
	}
}

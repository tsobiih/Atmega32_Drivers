#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"

#include "DIO_interface.h"
#include "Stepper_interface.h"

int main(void)
{
	Stepper_voidInit();

	Stepper_voidRotateCCW(360);
	_delay_ms(10);
}

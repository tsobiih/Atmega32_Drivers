#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"

#include "DIO_interface.h"

#include "DC_interface.h"

int main(void)
{
	DC_voidInit();
	while(1)
	{
		DC_voidRotateCW();
		_delay_ms(1000);
		DC_voidBreake();
		_delay_ms(1000);
		DC_voidRotateCounterCW();
		_delay_ms(1000);
		DC_voidBreake();
		_delay_ms(1000);
	}
}

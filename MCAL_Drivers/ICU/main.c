
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"

#include "GIE_interface.h"
#include "TIMER1_interface.h"
#include "DIO_interface.h"
#include "TIMER0_interface.h"
#include "CLCD_Interface.h"

void CapturedValues(void);

u16 Rising_Edge1_Time=0;
u16 Rising_Edge2_Time=0;

u16 Falling_Edge_Time=0;
u8 flag=0;
u8 switchState = 0;

int main(void)
{
	GIE_voidEnable();
	DIO_voidSetPinDirection(DIO_u8PORTB , DIO_u8PIN7 , DIO_u8INPUT);			//for switch
	DIO_voidSetPinValue(DIO_u8PORTB , DIO_u8PIN7 , DIO_u8HIGH);					//activate pull up resisrance

	CLCD_voidInit();
	CLCD_voidSendData('t');
	DIO_voidSetPinDirection(DIO_u8PORTB , DIO_u8PIN3 , DIO_u8OUTPUT);
	TIMER0_voidInit();
	TIMER0_voidSetCompareValue(128);

	DIO_voidSetPinDirection(DIO_u8PORTD , DIO_u8PIN6 , DIO_u8INPUT);

	TIMER1_voidInit();

	TIMER1_voidCallBackFunction(CapturedValues);

	TIMER1_voidICUInterruptEnable();
	while(1)
	{
		u16 total_time = Rising_Edge2_Time - Rising_Edge1_Time;
		u16 on_time = Falling_Edge_Time - Rising_Edge1_Time;

        u8 currentSwitchState = DIO_u8GetPinValue(DIO_u8PORTB, DIO_u8PIN7);

        // Check if DIP switch is toggled (0 for pressed/ON state)
        if (currentSwitchState == 0 && switchState == 1)
        {
            _delay_ms(50);  // Debounce delay to avoid multiple triggers
            if (DIO_u8GetPinValue(DIO_u8PORTB, DIO_u8PIN7) == 0)  // Confirm state change
            {
                switchState = 0;  // Update switch state
                TIMER1_voidICUInterruptEnable();  // Enable the input capture interrupt
            }
        }

        // Reset switch state when toggled back to OFF
        if (currentSwitchState == 1 && switchState == 0)
        {
            _delay_ms(50);  // Debounce delay
            switchState = 1;  // Update to allow new capture
        }

		if(flag == 1)
		{
			_delay_ms(1000);
			CLCD_voidSetXYPosition(0,0);
			CLCD_voidSendString("Total Time:");
			CLCD_voidSendInteger(total_time);

			CLCD_voidSetXYPosition(0,1);
			CLCD_voidSendString("On Time:");
			CLCD_voidSendInteger(on_time);

			flag=0;
		}
	}
}

void CapturedValues(void)
{
	static u8 Edge_count=0;

	if (Edge_count == 1)
	{
		Rising_Edge1_Time = TIMER1_u16ReadCaptureValue();
		TIMER1_voidSetICUEdgeTrigre(0);
		Edge_count=2;
	}
	else if (Edge_count == 2)
	{
		Falling_Edge_Time = TIMER1_u16ReadCaptureValue();
		TIMER1_voidSetICUEdgeTrigre(1);
		Edge_count=3;
	}

	else if(Edge_count == 3)
	{
		Rising_Edge2_Time = TIMER1_u16ReadCaptureValue();
		Edge_count=0;
		TIMER1_voidICUInterruptDisable();
		flag=1;
	}
}


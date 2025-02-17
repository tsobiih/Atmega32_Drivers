#include <string.h>
#include "stdio.h"
#include "stdlib.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "UART_interface.h"
#include "util/delay.h"
#include "KPD_interface.h"
#include "CLCD_Interface.h"

int main(void)
{
    u8 Local_u8Key[4] = {0};  // Array to store the digits
    u8 PressedKey = NOT_PRESSED;
    u8 CompreMatchValue = 0;
    u8 i = 0;

    // Pin configurations
    DIO_voidSetPinDirection(DIO_u8PORTD, DIO_u8PIN1, DIO_u8OUTPUT);
    DIO_voidSetPinDirection(DIO_u8PORTD, DIO_u8PIN0, DIO_u8INPUT);

    UART_voidInit();
    KPD_voidInit();
    CLCD_voidInit();

    while (1)
    {
        PressedKey = KPD_u8GetPressedKey();
        if (PressedKey != '=' && PressedKey != NOT_PRESSED && i < 3)
        {
            // Store the digit in the array as a character
            Local_u8Key[i] = PressedKey;
            CLCD_voidSetXYPosition(13 + i, 1);
            CLCD_voidSendData(PressedKey); // Display the digit on the screen
            i++;
        }
        else if (PressedKey == '=')
        {
            // Add string terminator
            Local_u8Key[i] = '\0'; // End the string

            // Convert the string to an integer value
            CompreMatchValue = atoi((char*)Local_u8Key); // Convert the array to an integer

            // Send data via UART and display it on the screen
            UART_voidSendData(CompreMatchValue);
            CLCD_voidClearDisplay();
            CLCD_voidSendInteger(CompreMatchValue); // Print the number

            // Clear the array
            memset(Local_u8Key, 0, sizeof(Local_u8Key)); // Clear the array
            i = 0; // Reset the index
        }
    }
}


# AVR Drivers for ATmega32

This repository contains a collection of drivers for AVR microcontrollers, specifically designed for the **ATmega32** microcontroller. These drivers aim to simplify the usage of peripherals like GPIO, UART, Timers, and more, for efficient embedded development.

## Requirements

- **ATmega32 Microcontroller**
- **AVR Toolchain**: Make sure you have the appropriate development tools installed, such as AVR-GCC and AVRDUDE for compiling and uploading the code.
- **IDE**: You can use any IDE that supports AVR programming, such as Eclipse, Atmel Studio, or PlatformIO.

## Installation

1. Download all the files from [this repository link].
2. Include the necessary files in your project folder (e.g., `GPIO.c`, `GPIO.h`, `UART.c`, `UART.h`, etc.).
3. Ensure your development environment is properly set up for AVR, including the toolchain and programmer for uploading the code to the ATmega32.

## Usage

### 1. Include the Drivers in Your Project

To include the drivers in your project, simply add the following files:
- `GPIO.c`, `GPIO.h`
- `UART.c`, `UART.h`
- `TIMER.c`, `TIMER.h`

### 2. Example Usage

Here is a simple example to get started with the UART and GPIO:

```c
#include "GPIO.h"
#include "UART.h"

int main(void)
{
    // Initialize GPIO and UART peripherals
    GPIO_Init();
    UART_Init();

    while (1)
    {
        // Transmit data over UART
        UART_Transmit('A');
        _delay_ms(1000);  // 1-second delay
    }
}

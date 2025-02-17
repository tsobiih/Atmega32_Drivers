/*
 * UART_interface.h
 *
 *  Created on: Oct 26, 2024
 *      Author: elwady
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART_voidInit(void);
void UART_voidSendData(u8 Copy_u8Data);
u8	 UART_u8ReceiveData(void);
void UART_voidSendString(const char *Copy_u8Data);
void UART_u8ReceiveString(u8* Copy_u8RecievedData);

#endif /* UART_INTERFACE_H_ */

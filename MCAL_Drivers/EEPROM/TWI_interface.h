/*
 * TWI_interface.h
 *
 *  Created on: Nov 1, 2024
 *      Author: elwady
 */

#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_

void TWI_voidMasterInit(void);
void TWI_voidSlaveInit(void);

void TWI_voidSendStartCondition(void);
void TWI_voidSendRepeatedStart(void);

void TWI_voidSendSlaveAddressWithWrite(u8 Copy_u8Address);
void TWI_voidSendSlaveAddressWithRead(u8 Copy_u8Address);

void TWI_voidMasterSendDataWithAck(u8 Copy_u8Data);
void TWI_voidMasterSendDataWithNack(u8 Copy_u8Data);

u8 	 TWI_u8MasterReceiveDataWithAck(void);
u8 	 TWI_u8MasterReceiveDataWithNack(void);

void TWI_voidSendStopCondition(void);


#endif /* TWI_INTERFACE_H_ */

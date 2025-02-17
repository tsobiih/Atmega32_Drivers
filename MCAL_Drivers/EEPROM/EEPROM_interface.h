/*
 * EEPROM_interface.h
 *
 *  Created on: Nov 1, 2024
 *      Author: elwady
 */

#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

void EEPROM_voidWriteData(u8 Copy_u8Data , u8 Copy_u8Address);
u8	 EEPROM_u8ReadData(u8 Copy_u8Adress);

#endif /* EEPROM_INTERFACE_H_ */

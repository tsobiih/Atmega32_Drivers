

#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

void CLCD_voidSendData(u8 Copy_u8Data);
void CLCD_voidSendCommand(u8 Copy_u8DCommand);
void CLCD_voidInit(void);
void CLCD_voidSendString(const char *Copy_pString);
void CLCD_voidSendInteger(u32 Copy_u32Integer);
void CLCD_voidSetXYPosition(u8 Copy_u8XPositin , u8 Copy_u8YPositin);
void CLCD_voidClearDisplay(void);

#endif /* CLCD_INTERFACE_H_ */

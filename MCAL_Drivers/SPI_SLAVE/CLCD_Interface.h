

#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_


typedef enum
{
	CLCD_SHIFT_RIGHT = 0x1c,
	CLCD_SHIFT_LEFT = 0x18
}CLCD_SHIFT;

void CLCD_voidSendData(u8 Copy_u8Data);
void CLCD_voidSendCommand(u8 Copy_u8DCommand);
void CLCD_voidInit(void);
void CLCD_voidSendString(const char *Copy_pString);
void CLCD_voidSendInteger(u32 Copy_u32Integer);
void CLCD_voidSetXYPosition(u8 Copy_u8XPositin , u8 Copy_u8YPositin);
void CLCD_voidScrollTextRightToLeft(char *Copy_u8Text);
void CLCD_voidScrollTextLeftToRight(char *Copy_u8Text);
void CLCD_voidScrollTextSinsoidalwave(char *Copy_u8Text);
void CLCD_voidShift(CLCD_SHIFT Copy_enuShiftDirection);
void CLCD_voidClearDisplay(void);
void CLCD_voidCreateShape(u8 Copy_u8Location,u8 *Copy_pu8Shape);
void CLCD_voidDrawShape(u8 Copy_u8Location);
void CLCD_voidSendFloat(f64 Copy_s32float);


#endif /* CLCD_INTERFACE_H_ */

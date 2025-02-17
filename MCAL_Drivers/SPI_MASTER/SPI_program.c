#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_config.h"
#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_register.h"







void SPI_voidInit(void)
{
	#if(SPI_MODE == MASTER)
		{
			//Select Master Mode
			SET_BIT(SPCR , 4);

			//Select Frequency F/4
			CLR_BIT(SPCR , 0);
			CLR_BIT(SPCR , 1);
			CLR_BIT(SPSR , 0);
		}
	#elif(SPI_MODE == SLAVE)
		{
			CLR_BIT(SPCR , 4);
		}
	#endif

	//Enable SPI
	SET_BIT(SPCR , 6);
}

u8 SPI_u8Transceiver(u8 Copy_u8Data)
{
	SPDR = Copy_u8Data;

	while((GET_BIT(SPSR , 7)) != 1)
	{
		asm("NOP");
	}

	return SPDR;
}

/**************************************************/
/*   AUTHOR      : Mohamed	MeGa	              */
/*   Description : DIO DRIVER                     */
/*   DATE        : 30 SEPT 2021                   */
/*   VERSION     : V01                            */
/**************************************************/

/*		library Directives						  */
#include	"STD_Types.h"
#include	"Bit_Math.h"

/**			DIO Directives						 */
#include	"DIO_int.h"


/**			DIO Directives						 */
#include	"SEV_int.h"
#include	"SEV_config.h"
#include	"SEV_priv.h"



void	SEV_VoidSET7SegmentValue(u8	COPY_U8SEVSEGMENTNUM, u8	COPY_U8SEVSEGMENTVALUE)
{
	u8 SEG[10] = {0xC0 , 0xF9 , 0xA4 , 0xB0 , 0x99 , 0x92 , 0x82,0xf8, 0x80,0x90};
	u8 LOC_u8_loop = SEV_SEG_START;
	if(COPY_U8SEVSEGMENTNUM	== SEV_SEG_LEFT)
	{
		DIO_voidSetPinValue(SEV_1_U8_A, GET_BIT(SEG[COPY_U8SEVSEGMENTVALUE], (LOC_u8_loop++) ));
		DIO_voidSetPinValue(SEV_1_U8_B, GET_BIT(SEG[COPY_U8SEVSEGMENTVALUE], (LOC_u8_loop++) ));
		DIO_voidSetPinValue(SEV_1_U8_C, GET_BIT(SEG[COPY_U8SEVSEGMENTVALUE], (LOC_u8_loop++) ));
		DIO_voidSetPinValue(SEV_1_U8_D, GET_BIT(SEG[COPY_U8SEVSEGMENTVALUE], (LOC_u8_loop++) ));
		DIO_voidSetPinValue(SEV_1_U8_E, GET_BIT(SEG[COPY_U8SEVSEGMENTVALUE], (LOC_u8_loop++) ));
		DIO_voidSetPinValue(SEV_1_U8_F, GET_BIT(SEG[COPY_U8SEVSEGMENTVALUE], (LOC_u8_loop++) ));
		DIO_voidSetPinValue(SEV_1_U8_G, GET_BIT(SEG[COPY_U8SEVSEGMENTVALUE], (LOC_u8_loop++) ));
		DIO_voidSetPinValue(SEV_1_U8_H, GET_BIT(SEG[COPY_U8SEVSEGMENTVALUE], (LOC_u8_loop++) ));
	}
	else if(COPY_U8SEVSEGMENTNUM	== 	SEV_SEG_RIGHT)
	{
		DIO_voidSetPinValue(SEV_0_U8_A, GET_BIT(SEG[COPY_U8SEVSEGMENTVALUE], (LOC_u8_loop++) ));
		DIO_voidSetPinValue(SEV_0_U8_B, GET_BIT(SEG[COPY_U8SEVSEGMENTVALUE], (LOC_u8_loop++) ));
		DIO_voidSetPinValue(SEV_0_U8_C, GET_BIT(SEG[COPY_U8SEVSEGMENTVALUE], (LOC_u8_loop++) ));
		DIO_voidSetPinValue(SEV_0_U8_D, GET_BIT(SEG[COPY_U8SEVSEGMENTVALUE], (LOC_u8_loop++) ));
		DIO_voidSetPinValue(SEV_0_U8_E, GET_BIT(SEG[COPY_U8SEVSEGMENTVALUE], (LOC_u8_loop++) ));
		DIO_voidSetPinValue(SEV_0_U8_F, GET_BIT(SEG[COPY_U8SEVSEGMENTVALUE], (LOC_u8_loop++) ));
		DIO_voidSetPinValue(SEV_0_U8_G, GET_BIT(SEG[COPY_U8SEVSEGMENTVALUE], (LOC_u8_loop++) ));
		DIO_voidSetPinValue(SEV_0_U8_H, GET_BIT(SEG[COPY_U8SEVSEGMENTVALUE], (LOC_u8_loop++) ));
	}
}
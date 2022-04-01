/*********************************************************************************************************/
/*                                          Author: Mohamed MeGa                                       */
/*                                          Date: 15/3/2019                                              */
/*                                          Version: 1.0v                                                */
/*                                          Description: Bit_Math lib                                    */
/*********************************************************************************************************/
#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_

#define	SET_BIT(REG, BitNUM)	( REG |=(1 << BitNUM))

#define	CLEAR_BIT(REG, BitNUM)	( REG &= ~(1 << BitNUM))

#define	TOGGLE_BIT(REG, BitNUM)	( REG ^= (1 << BitNUM))

#define	GET_BIT(REG, BitNUM)	( (REG >> BitNUM) & (0x01))

#define	SET_BYTE(Byte, value)	Byte = value

#define	conc_help(x7,x6,x5,x4,x3,x2,x1,x0)	0b##x7##x6##x5##x4##x3##x2##x1##x0

#define	conc(x7,x6,x5,x4,x3,x2,x1,x0)		conc_help(x7,x6,x5,x4,x3,x2,x1,x0)

#endif

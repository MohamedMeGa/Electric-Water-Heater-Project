/************************************************************/
/**   		AUTHOR      : Mohamed	MeGa           		  	*/
/**   		Description : EXTERNAL INTERRUPT DRIVER      	*/
/**   		DATE        : 7 OCT 2021 					  	*/
/**   		VERSION     : V01                            	*/
/************************************************************/

#ifndef	EXTI2_PRIV_H
#define	EXTI2_PRIV_H




/************************************************************/
/* Description :  Memory Mapped of EXTERNAL	INTERRUPT 0    	*/
/************************************************************/

#define	MCUCR	*((volatile	u8	*)	0x55)
#define	MCUCSR	*((volatile	u8	*)	0x54)
#define	GICR	*((volatile	u8	*)	0x5B)
#define	GIFR	*((volatile	u8	*)	0x5A)



	
#endif
/**************************************************/
/*   AUTHOR      : Mohamed	MeGa           		  */
/*   Description : ADC DRIVER      				  */
/*   DATE        : 9 OCT 2021 					  */
/*   VERSION     : V01                            */
/**************************************************/

#ifndef	ADC_PRIV_H
#define	ADC_PRIV_H


/***************************************************/
/* Description :  MEMEROY MAPPING I/O  Peripheral  */
/***************************************************/

	#define	ADMUX	*((volatile	u8	*)	0x27)
	#define	ADCSRA	*((volatile	u8	*)	0x26)
	#define	ADCL	*((volatile	u8	*)	0x24)
	#define	ADCH	*((volatile	u8	*)	0x25)
	#define	SFIOR	*((volatile	u8	*)	0x50)
	



	
#endif
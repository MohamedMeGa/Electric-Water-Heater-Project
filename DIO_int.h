/************************************************************/
/*   		AUTHOR      : MOHAMED	MEGA	              	*/
/*   		Description : DIO DRIVER                     	*/
/*   		DATE        : 29 SET 2021                    	*/
/*   		VERSION     : V02                            	*/
/************************************************************/

#ifndef	DIO_INT_H
#define	DIO_INT_H

/************************************************************/
/**			LOW & HIGH 	DEFINITION							*/
/************************************************************/
#define	DIO_HIGH				1
#define	DIO_LOW					0



/************************************************************/
/* 			Description :  pins of port A 			   	   */
/************************************************************/
#define	DIO_PIN0		0
#define	DIO_PIN1		1
#define	DIO_PIN2		2
#define	DIO_PIN3		3
#define	DIO_PIN4		4
#define	DIO_PIN5		5
#define	DIO_PIN6		6
#define	DIO_PIN7		7



/************************************************************/
/* 			Description :  pins of port B 			   	   */
/************************************************************/
#define	DIO_PIN8		8
#define	DIO_PIN9		9
#define	DIO_PIN10		10
#define	DIO_PIN11		11
#define	DIO_PIN12		12
#define	DIO_PIN13		13
#define	DIO_PIN14		14
#define	DIO_PIN15		15



/************************************************************/
/* 			Description :  pins of port C 			   	   */
/************************************************************/
#define	DIO_PIN16		16
#define	DIO_PIN17		17
#define	DIO_PIN18		18
#define	DIO_PIN19		19
#define	DIO_PIN20		20
#define	DIO_PIN21		21
#define	DIO_PIN22		22
#define	DIO_PIN23		23



/************************************************************/
/* 			Description :  pins of port D 			   	    */
/************************************************************/
#define	DIO_PIN24		24
#define	DIO_PIN25		25
#define	DIO_PIN26		26
#define	DIO_PIN27		27
#define	DIO_PIN28		28
#define	DIO_PIN29		29
#define	DIO_PIN30		30
#define	DIO_PIN31		31


/************************************************************/
/* 			Description :  PROTOTYPE DECLARTION 		   	*/
/************************************************************/


/************************************************************/
/* Description :  function for initialization and define	*/
/*				   the direction of ports					*/
/************************************************************/

void	DIO_VoidInitialization(void);



/************************************************************/
/* Description :  function to set the value of any 			*/
/*				  pin to LOW or HIGH						*/
/************************************************************/
void	DIO_voidSetPinValue(u8	copy_u8PinNum, u8	copy_u8PinValue);



/************************************************************/
/* Description :  function to Get the value of any 			*/
/*				  pin 										*/
/************************************************************/
u8	DIO_u8GetPinValue(u8	copy_u8PinNum);



/************************************************************/
/* Description :  function to set the direction of any 		*/
/*				  pin to OUTPUT or INPUT					*/
/************************************************************/
void	DIO_voidSetPinDirection(u8	copy_u8PinNum, u8	copy_u8PinDir);



/************************************************************/
/* Description :  function to Toggle the value of any 		*/
/*				  pin to LOW or HIGH						*/
/************************************************************/
void	DIO_voidTogglePin(u8	copy_u8PinNum);



#endif
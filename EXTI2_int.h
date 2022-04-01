/************************************************************/
/**   		AUTHOR      : MOHAMED	MEGA	              	*/
/**   		Description :  EXTERNAL INTERRUPT 2 DRIVER	 	*/
/**   		DATE        : 29 MAR 2022                    	*/
/**   		VERSION     : V01                            	*/
/************************************************************/

#ifndef	EXTI2_INT_H
#define	EXTI2_INT_H

#define NULL (void *)0

/************************************************************/
/**			Sense Mode Options					 			 */
/************************************************************/
#define		FallingEdge			2
#define		RisingEdge			3



/************************************************************/
/** 		Description :  PROTOTYPE DECLARTION 		   	*/
/************************************************************/


/************************************************************/
/* Description :  function for initialization The Interrupt	*/
/************************************************************/

void	EXTI2_VoidInitialization(void);


/************************************************************/
/** Description :  function to set callback function		*/
/************************************************************/

void	EXTI2_VoidSetCallBack(pf	copy_FuncAddress);


/************************************************************/
/** Description :  function to set the sense mode of the 	*/
/**				Interrupt									*/
/************************************************************/	

void	EXTI2_VoidSetSenseMode(u8	copy_U8SenseMode);


/************************************************************/
/* Description :  function to Enable the Intterupt			*/
/************************************************************/

void	EXTI2_VoidEnableEXTI2();



/************************************************************/
/* Description :  function to Disable the Intterupt			*/
/************************************************************/

void	EXTI2_VoidDisableEXTI2();

#endif
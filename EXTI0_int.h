/************************************************************/
/**   		AUTHOR      : MOHAMED	MEGA	              	*/
/**   		Description :  EXTERNAL INTERRUPT 0 DRIVER	 	*/
/**   		DATE        : 29 SET 2021                    	*/
/**   		VERSION     : V02                            	*/
/************************************************************/

#ifndef	EXTI0_INT_H
#define	EXTI0_INT_H

#define NULL (void *)0

/************************************************************/
/**			Sense Mode Options					 			 */
/************************************************************/
#define		FallingEdge			2
#define		RisingEdge			3
#define		IOC					4
#define		LowLevel			5


/************************************************************/
/** 		Description :  PROTOTYPE DECLARTION 		   	*/
/************************************************************/


/************************************************************/
/* Description :  function for initialization The Interrupt	*/
/************************************************************/

void	EXTI0_VoidInitialization(void);


/************************************************************/
/** Description :  function to set callback function		*/
/************************************************************/

void	EXTI0_VoidSetCallBack(pf	copy_FuncAddress);


/************************************************************/
/** Description :  function to set the sense mode of the 	*/
/**				Interrupt									*/
/************************************************************/	

void	EXTI0_VoidSetSenseMode(u8	copy_U8SenseMode);


/************************************************************/
/* Description :  function to Enable the Intterupt			*/
/************************************************************/

void	EXTI0_VoidEnableEXTI0();



/************************************************************/
/* Description :  function to Disable the Intterupt			*/
/************************************************************/

void	EXTI0_VoidDisableEXTI0();

#endif
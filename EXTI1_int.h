/************************************************************/
/**   		AUTHOR      : MOHAMED	MEGA	              	*/
/**   		Description :  EXTERNAL INTERRUPT 0 DRIVER	 	*/
/**   		DATE        : 29 MAR 2021                    	*/
/**   		VERSION     : V01                            	*/
/************************************************************/

#ifndef	EXTI1_INT_H
#define	EXTI1_INT_H

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

void	EXTI1_VoidInitialization(void);


/************************************************************/
/** Description :  function to set callback function		*/
/************************************************************/

void	EXTI1_VoidSetCallBack(pf	copy_FuncAddress);


/************************************************************/
/** Description :  function to set the sense mode of the 	*/
/**				Interrupt									*/
/************************************************************/	

void	EXTI1_VoidSetSenseMode(u8	copy_U8SenseMode);


/************************************************************/
/* Description :  function to Enable the Intterupt			*/
/************************************************************/

void	EXTI1_VoidEnableEXTI1();



/************************************************************/
/* Description :  function to Disable the Intterupt			*/
/************************************************************/

void	EXTI1_VoidDisableEXTI1();

#endif
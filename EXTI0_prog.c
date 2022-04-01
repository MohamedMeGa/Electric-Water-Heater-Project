/************************************************************/
/*   		AUTHOR      : Mohamed	MeGa	                */
/*   		Description : EXTERNAL INTERRUPT DRIVER	 	    */
/*   		DATE        : 07 OCT 2021                       */
/*   		VERSION     : V01                               */
/************************************************************/

/*		library Directives						  */
#include	"STD_Types.h"
#include	"Bit_Math.h"

/**			EXTI Directives						 */
#include	"EXTI0_int.h"
#include	"EXTI0_config.h"
#include	"EXTI0_priv.h"


volatile	pf	EXTI0_CallBackFunction;

/************************************************************/
/* 		Description :  ExTI0	Implemention 		   	   */
/************************************************************/


/************************************************************/
/* Description :  function for initialization The Interrupt	*/
/************************************************************/

void	EXTI0_VoidInitialization(void)
{
	/**	Set The Sense Mode		*/
	#if   SenseMode == LowLevel
		CLEAR_BIT(MCUCR, 0);
		CLEAR_BIT(MCUCR, 1);
		
	#elif SenseMode == IOC
		SET_BIT(MCUCR, 0);
		CLEAR_BIT(MCUCR, 1);
		
	#elif SenseMode == FallingEdge
		CLEAR_BIT(MCUCR, 0);
		SET_BIT(MCUCR, 1);
		
	#elif SenseMode == RisingEdge
		SET_BIT(MCUCR, 0);
		SET_BIT(MCUCR, 1);
	#endif
	
	/**	Disable the Interrupt 	*/
	CLEAR_BIT(GICR, 6);
	/**	clear the int flag 		*/
	SET_BIT(GIFR, 6);
}

/************************************************************/
/* Description :  function to Enable the Intterupt			*/
/************************************************************/

void	EXTI0_VoidEnableEXTI0()
{
	
	/**	Enable the external Interrupt 	*/
	SET_BIT(GICR, 6);
	
}


/************************************************************/
/* Description :  function to Disable the Intterupt			*/
/************************************************************/

void	EXTI0_VoidDisableEXTI0()
{
	
	/**	Disable the external Interrupt 	*/
	CLEAR_BIT(GICR, 6);
	
}



/************************************************************/
/* Description :  function to Set Sense Mode 				*/
/************************************************************/
	
void	EXTI0_VoidSetSenseMode(u8	copy_U8SenseMode)
{
	
	/**	Set The Sense Mode		*/
	if(   copy_U8SenseMode == LowLevel	)
	{
		CLEAR_BIT(MCUCR, 0);
		CLEAR_BIT(MCUCR, 1);
	}
	else if( copy_U8SenseMode == IOC	)
	{
		SET_BIT(MCUCR, 0);
		CLEAR_BIT(MCUCR, 1);
	}
	else if( copy_U8SenseMode == FallingEdge	)
	{
		CLEAR_BIT(MCUCR, 0);
		SET_BIT(MCUCR, 1);
	}
	else if( copy_U8SenseMode == RisingEdge	)
	{
		SET_BIT(MCUCR, 0);
		SET_BIT(MCUCR, 1);
	}
	else
	{
		//Error
	}
}



/************************************************************/
/* Description :  function to set callback function			*/
/************************************************************/

void	EXTI0_VoidSetCallBack(pf	copy_FuncAddress)
{
	if(copy_FuncAddress != NULL)
	{
		EXTI0_CallBackFunction = copy_FuncAddress;
	}
}


/** 			Linker Problem solved				 */
void __vector_1(void)	__attribute__((signal, used));

void __vector_1(void)
{
	EXTI0_CallBackFunction();
}


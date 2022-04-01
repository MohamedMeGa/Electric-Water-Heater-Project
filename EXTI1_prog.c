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
#include	"EXTI1_int.h"
#include	"EXTI1_config.h"
#include	"EXTI1_priv.h"


volatile	pf	EXTI1_CallBackFunction;

/************************************************************/
/* 		Description :  ExTI0	Implemention 		   	   */
/************************************************************/


/************************************************************/
/* Description :  function for initialization The Interrupt	*/
/************************************************************/

void	EXTI1_VoidInitialization(void)
{
	/**	Set The Sense Mode		*/
	#if   SenseMode1 == LowLevel
		CLEAR_BIT(MCUCR, 2);
		CLEAR_BIT(MCUCR, 3);
		
	#elif SenseMode1 == IOC
		SET_BIT(MCUCR, 2);
		CLEAR_BIT(MCUCR, 3);
		
	#elif SenseMode1 == FallingEdge
		CLEAR_BIT(MCUCR, 2);
		SET_BIT(MCUCR, 3);
		
	#elif SenseMode1 == RisingEdge
		SET_BIT(MCUCR, 2);
		SET_BIT(MCUCR, 3);
	#endif
	
	/**	Disable the Interrupt 	*/
	CLEAR_BIT(GICR, 7);
	/**	clear the int flag 		*/
	SET_BIT(GIFR, 7);
}

/************************************************************/
/* Description :  function to Enable the Intterupt			*/
/************************************************************/

void	EXTI1_VoidEnableEXTI1()
{
	
	/**	Enable the external Interrupt 	*/
	SET_BIT(GICR, 7);
	
}


/************************************************************/
/* Description :  function to Disable the Intterupt			*/
/************************************************************/

void	EXTI1_VoidDisableEXTI1()
{
	
	/**	Disable the external Interrupt 	*/
	CLEAR_BIT(GICR, 7);
	
}



/************************************************************/
/* Description :  function to Set Sense Mode 				*/
/************************************************************/
	
void	EXTI1_VoidSetSenseMode(u8	copy_U8SenseMode)
{
	
	/**	Set The Sense Mode		*/
	if(   copy_U8SenseMode == LowLevel	)
	{
		CLEAR_BIT(MCUCR, 2);
		CLEAR_BIT(MCUCR, 3);
	}
	else if( copy_U8SenseMode == IOC	)
	{
		SET_BIT(MCUCR, 2);
		CLEAR_BIT(MCUCR, 3);
	}
	else if( copy_U8SenseMode == FallingEdge	)
	{
		CLEAR_BIT(MCUCR, 2);
		SET_BIT(MCUCR, 3);
	}
	else if( copy_U8SenseMode == RisingEdge	)
	{
		SET_BIT(MCUCR, 2);
		SET_BIT(MCUCR, 3);
	}
	else
	{
		//Error
	}
}



/************************************************************/
/* Description :  function to set callback function			*/
/************************************************************/

void	EXTI1_VoidSetCallBack(pf	copy_FuncAddress)
{
	if(copy_FuncAddress != NULL)
	{
		EXTI1_CallBackFunction = copy_FuncAddress;
	}
}


/** 			Linker Problem solved				 */
void __vector_2(void)	__attribute__((signal, used));

void __vector_2(void)
{
	EXTI1_CallBackFunction();
}


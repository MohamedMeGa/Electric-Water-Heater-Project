/************************************************************/
/*   		AUTHOR      : Mohamed	MeGa	                */
/*   		Description : EXTERNAL INTERRUPT DRIVER	 	    */
/*   		DATE        : 29 MAR 2022                       */
/*   		VERSION     : V01                               */
/************************************************************/

/*		library Directives						  */
#include	"STD_Types.h"
#include	"Bit_Math.h"

/**			EXTI Directives						 */
#include	"EXTI2_int.h"
#include	"EXTI2_config.h"
#include	"EXTI2_priv.h"


volatile	pf	EXTI2_CallBackFunction;

/************************************************************/
/* 		Description :  ExTI0	Implemention 		   	   */
/************************************************************/


/************************************************************/
/* Description :  function for initialization The Interrupt	*/
/************************************************************/

void	EXTI2_VoidInitialization(void)
{
	/**	Set The Sense Mode		*/
	#if SenseMode2 == FallingEdge
		CLEAR_BIT(MCUCSR, 6);
		
	#elif SenseMode2 == RisingEdge
		SET_BIT(MCUCSR, 6);
	#endif
	
	/**	Disable the Interrupt 	*/
	CLEAR_BIT(GICR, 5);
	/**	clear the int flag 		*/
	SET_BIT(GIFR, 5);
}

/************************************************************/
/* Description :  function to Enable the Intterupt			*/
/************************************************************/

void	EXTI2_VoidEnableEXTI2()
{
	
	/**	Enable the external Interrupt 	*/
	SET_BIT(GICR, 5);
	
}


/************************************************************/
/* Description :  function to Disable the Intterupt			*/
/************************************************************/

void	EXTI2_VoidDisableEXTI2()
{
	
	/**	Disable the external Interrupt 	*/
	CLEAR_BIT(GICR, 5);
	
}



/************************************************************/
/* Description :  function to Set Sense Mode 				*/
/************************************************************/
	
void	EXTI2_VoidSetSenseMode(u8	copy_U8SenseMode)
{
	
	/**	Set The Sense Mode		*/
	if( copy_U8SenseMode == FallingEdge	)
	{
		CLEAR_BIT(MCUCR, 6);
	}
	else if( copy_U8SenseMode == RisingEdge	)
	{
		SET_BIT(MCUCR, 6);
	}
	else
	{
		//Error
	}
}



/************************************************************/
/* Description :  function to set callback function			*/
/************************************************************/

void	EXTI2_VoidSetCallBack(pf	copy_FuncAddress)
{
	if(copy_FuncAddress != NULL)
	{
		EXTI2_CallBackFunction = copy_FuncAddress;
	}
}


/** 			Linker Problem solved				 */
void __vector_3(void)	__attribute__((signal, used));

void __vector_3(void)
{
	EXTI2_CallBackFunction();
}


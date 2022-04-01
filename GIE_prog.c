/************************************************************/
/*   		AUTHOR      : Mohamed	MeGa	                */
/*   		Description : General INTERRUPT DRIVER	 	    */
/*   		DATE        : 19 OCT 2021                       */
/*   		VERSION     : V01                               */
/************************************************************/

/*		library Directives						  			*/
#include	"STD_Types.h"
#include	"Bit_Math.h"

/**			EXTI Directives						 			*/
#include	"GIE_int.h"
#include	"GIE_config.h"
#include	"GIE_priv.h"


/************************************************************/
/* 		Description :  GIE	Implemention 		   	   		*/
/************************************************************/


/************************************************************/
/* Description :  function to Enable the ADC Interrupt	 	*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 Interrupt Initializtion	 			*/
/************************************************************/

void	GIE_VoidGIEEnable(void)
{
	SET_BIT(SREG, 7);
}




/************************************************************/
/* Description :  function to Disable the ADC Interrupt	 	*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 Interrupt Initializtion	 			*/
/************************************************************/

void	GIE_VoidGIEDisable(void)
{
	CLEAR_BIT(SREG, 7);
}


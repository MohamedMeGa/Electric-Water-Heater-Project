/************************************************************/
/*   		AUTHOR      : Mohamed	MeGa	              	*/
/*   		Description : ADC DRIVER	  					*/
/*   		DATE        : 07 OCT 2021                    	*/
/*   		VERSION     : V02                            	*/
/************************************************************/

/************************************************************/
/*			library Directives						  		*/
/************************************************************/
#include	"STD_Types.h"
#include	"Bit_Math.h"


/************************************************************/
/**			EXTI Directives						 			*/
/************************************************************/
#include	"ADC_int.h"
#include	"ADC_config.h"
#include	"ADC_priv.h"

#define 	NULL	(void *)0
/************************************************************/
/* Description :  ADC	Implemention 		   	   			*/
/************************************************************/

volatile pf x;

/************************************************************/
/* Description :  function for initialization The ADC		*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/	  
void	ADC_VoidInitialization(void)
{
/**					Disable ADC								**/
	CLEAR_BIT(ADCSRA, 7);
	
/**				Do not Start Conversion						**/
	CLEAR_BIT(ADCSRA, 6);
	
/**				Auto Trigger disable						**/
	CLEAR_BIT(ADCSRA, 5);

/**				Interrupt flag CLEARED						**/
	SET_BIT(ADCSRA, 4);
	
/**				Deactive ADC Interrupt						**/
	CLEAR_BIT(ADCSRA, 3);
	
/**			Register Adjustment Options		   	   */
	#if	REG_ADJ == Left_Adgustment
		SET_BIT(ADMUX,5);
	#elif	REG_ADJ == Right_Adgustment
		CLEAR_BIT(ADMUX,5);
	#endif
	
/**			Reference Selections Options		   */
	#if	REF_SELECT == AREF
		CLEAR_BIT(ADMUX,6);
		CLEAR_BIT(ADMUX,7);
	#elif	REF_SELECT == AVCC
		SET_BIT(ADMUX,6);
		CLEAR_BIT(ADMUX,7);
	#elif	REF_SELECT == Internal
		SET_BIT(ADMUX,6);
		SET_BIT(ADMUX,7);
	#endif


	
/**			Channels selection Options		   	   */
	CLEAR_BIT(ADMUX, 4);
	CLEAR_BIT(ADMUX, 3);
	
	#if		ADC_CHANNEL	== ADC0
		CLEAR_BIT(ADMUX, 2);
		CLEAR_BIT(ADMUX, 1);
		CLEAR_BIT(ADMUX, 0);
	#elif	ADC_CHANNEL	== ADC1
		CLEAR_BIT(ADMUX, 2);
		CLEAR_BIT(ADMUX, 1);
		SET_BIT(ADMUX, 0);
	#elif	ADC_CHANNEL	== ADC2
		CLEAR_BIT(ADMUX, 2);
		SET_BIT(ADMUX, 1);
		CLEAR_BIT(ADMUX, 0);
	#elif	ADC_CHANNEL	== ADC3
		CLEAR_BIT(ADMUX, 2);
		SET_BIT(ADMUX, 1);
		SET_BIT(ADMUX, 0);
	#elif	ADC_CHANNEL	== ADC4
		SET_BIT(ADMUX, 2);
		CLEAR_BIT(ADMUX, 1);
		CLEAR_BIT(ADMUX, 0);
	#elif	ADC_CHANNEL	== ADC5
		SET_BIT(ADMUX, 2);
		CLEAR_BIT(ADMUX, 1);
		SET_BIT(ADMUX, 0);
	#elif	ADC_CHANNEL	== ADC6
		SET_BIT(ADMUX, 2);
		SET_BIT(ADMUX, 1);
		CLEAR_BIT(ADMUX, 0);
	#elif	ADC_CHANNEL	== ADC7
		SET_BIT(ADMUX, 2);
		SET_BIT(ADMUX, 1);
		SET_BIT(ADMUX, 0);
	#endif

	
/**			Prescaller selections Options		   */
	#if		PRESCALE	== PRES_2_DIV
		CLEAR_BIT(ADCSRA, 2);
		CLEAR_BIT(ADCSRA, 1);
		CLEAR_BIT(ADCSRA, 0);
	#elif	PRESCALE	== PRES_4_DIV
		CLEAR_BIT(ADCSRA, 2);
		SET_BIT(ADCSRA, 1);
		CLEAR_BIT(ADCSRA, 0);
	#elif	PRESCALE	== PRES_8_DIV
		CLEAR_BIT(ADCSRA, 2);
		SET_BIT(ADCSRA, 1);
		SET_BIT(ADCSRA, 0);
	#elif	PRESCALE	== PRES_16_DIV
		SET_BIT(ADCSRA, 2);
		CLEAR_BIT(ADCSRA, 1);
		CLEAR_BIT(ADCSRA, 0);
	#elif	PRESCALE	== PRES_32_DIV
		SET_BIT(ADCSRA, 2);
		CLEAR_BIT(ADCSRA, 1);
		SET_BIT(ADCSRA, 0);
	#elif	PRESCALE	== PRES_64_DIV
		SET_BIT(ADCSRA, 2);
		SET_BIT(ADCSRA, 1);
		CLEAR_BIT(ADCSRA, 0);
	#elif	PRESCALE	== PRES_128_DIV
		SET_BIT(ADCSRA, 2);
		SET_BIT(ADCSRA, 1);
		SET_BIT(ADCSRA, 0);
	#endif
	

}




/************************************************************/
/* Description :  function to Enable the ADC 	 			*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 ADC Initializtion	 					*/
/************************************************************/
void	ADC_VoidADCEnable(void)
{
	
	SET_BIT(ADCSRA, 7);
	
}




/************************************************************/
/* Description :  function to Read the ADC value by Poling	*/
/*				  input	 :	void							*/
/*				  output :	u16								*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 Start conversion	 					*/
/************************************************************/
u16		ADC_U16ReadADC(void)
{
	u16	Local_ADCReturn = 0;
	
	/**		Start Conversion								*/
	ADC_VoidStartConverstion();
	
	while(GET_BIT(ADCSRA, 4) == 0);
	SET_BIT(ADCSRA, 4);

	#if		REG_ADJ == Left_Adgustment
		Local_ADCReturn	=  ADCH ;
		
	#elif	REG_ADJ == Right_Adgustment
		Local_ADCReturn	=  ADCH ## ADCL;
	#endif
	
	return	Local_ADCReturn;
}




/************************************************************/
/* Description :  function to Disable the ADC 	 			*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 ADC Initializtion	 					*/
/************************************************************/
void	ADC_VoidADCDisable(void)
{
	
	CLEAR_BIT(ADCSRA, 7);
	
}


/************************************************************/
/* Description :  function to Enable the ADC Interrupt	 	*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 ADC Initializtion	 					*/
/************************************************************/
void	ADC_VoidInterruptEnable(void)
{
	
	SET_BIT(ADCSRA, 3);
	
}




/************************************************************/
/* Description :  function to Start Converstion		 		*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 ADC Enable			 					*/
/************************************************************/
void	ADC_VoidStartConverstion(void)
{
	SET_BIT(ADCSRA, 6);
}





/************************************************************/
/* Description :  function to set Auto Trigger value		*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 Interrupt initialized 					*/
/************************************************************/

void	ADC_VoidAutoTrigger(void)
{
/**				Auto Trigger disable						**/
	SET_BIT(ADCSRA, 5);
	
/**				Auto Triggeer Options				   		**/
	#if		TRIGGER_SELECT	== Free_Running
		CLEAR_BIT(SFIOR, 7);
		CLEAR_BIT(SFIOR, 6);
		CLEAR_BIT(SFIOR, 5);
	#elif	TRIGGER_SELECT	== Analog_Comp
		CLEAR_BIT(SFIOR, 7);
		CLEAR_BIT(SFIOR, 6);
		SET_BIT(SFIOR, 5);
	#elif	TRIGGER_SELECT	== EXTI_0
		CLEAR_BIT(SFIOR, 7);
		SET_BIT(SFIOR, 6);
		CLEAR_BIT(SFIOR, 5);
	#elif	TRIGGER_SELECT	== Count0_Comp_Match
		CLEAR_BIT(SFIOR, 7);
		SET_BIT(SFIOR, 6);
		SET_BIT(SFIOR, 5);
	#elif	TRIGGER_SELECT	== Count0_Overflow
		SET_BIT(SFIOR, 7);
		CLEAR_BIT(SFIOR, 6);
		CLEAR_BIT(SFIOR, 5);
	#elif	TRIGGER_SELECT	== Count0_Comp_MatchB
		SET_BIT(SFIOR, 7);
		CLEAR_BIT(SFIOR, 6);
		SET_BIT(SFIOR, 5);
	#elif	TRIGGER_SELECT	== Count1_Overflow
		SET_BIT(SFIOR, 7);
		SET_BIT(SFIOR, 6);
		CLEAR_BIT(SFIOR, 5);
	#elif	TRIGGER_SELECT	== Count1_Capt_Event
		SET_BIT(SFIOR, 7);
		SET_BIT(SFIOR, 6);
		SET_BIT(SFIOR, 5);
	#endif
}

void	ADC_VoidSetADCCallback(pf	copy_FunctionAdress)
{
	if(copy_FunctionAdress	!=	NULL)
	{
		x	=	copy_FunctionAdress;
	}
}

//vector 17
void	__vector_20(void)	__attribute__(( signal , used ));

void	__vector_20(void)
{
	x();
}
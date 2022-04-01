/**************************************************/
/*   AUTHOR      : MOHAMED	MEGA	              */
/*   Description : ADC 	DRIVER					  */
/*   DATE        : 08 OCT 2021                    */
/*   VERSION     : V01                            */
/**************************************************/

#ifndef	ADC_INT_H
#define	ADC_INT_H

/***************************************************/
/**			Register Adjustment Options		   	   */
/***************************************************/
#define		Left_Adgustment		0
#define		Right_Adgustment	1

/***************************************************/
/**			Reference Selections Options		   */
/***************************************************/
#define		AREF				4					//Internal Vref turned off
#define		AVCC				5
#define		Internal			2


/***************************************************/
/**			Channels selection Options		   	   */
/***************************************************/
#define		ADC0				0
#define		ADC1				1
#define		ADC2				2
#define		ADC3				3
#define		ADC4				4
#define		ADC5				5
#define		ADC6				6
#define		ADC7				7

/***************************************************/
/**			Prescaller selections Options		   */
/***************************************************/
#define		PRES_2_DIV			0
#define		PRES_4_DIV			2
#define		PRES_8_DIV			3
#define		PRES_16_DIV			4
#define		PRES_32_DIV			5
#define		PRES_64_DIV			6
#define		PRES_128_DIV		7

/***************************************************/
/**			Auto Triggeer Options				   */
/***************************************************/
#define		Free_Running		0
#define		Analog_Comp			1
#define		EXTI_0				2
#define		Count0_Comp_Match	3
#define		Count0_Overflow		4
#define		Count0_Comp_MatchB	5
#define		Count1_Overflow		6
#define		Count1_Capt_Event	7




/***************************************************/
/* Description :  PROTOTYPE DECLARTION 		   	   */
/***************************************************/

/************************************************************/
/* Description :  function for initialization The ADC		*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/

void	ADC_VoidInitialization(void);



/************************************************************/
/* Description :  function to Enable the ADC 	 			*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 ADC Initializtion	 					*/
/************************************************************/

void	ADC_VoidADCEnable(void);





/************************************************************/
/* Description :  function to Read the ADC value 			*/
/*				  input	 :	u8								*/
/*				  output :	void							*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 Start conversion	 					*/
/************************************************************/

u16		ADC_U16ReadADC(void);




/************************************************************/
/* Description :  function to Disable the ADC 	 			*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 ADC Initializtion	 					*/
/************************************************************/

void	ADC_VoidADCDisable(void);




/************************************************************/
/* Description :  function to Enable the ADC Interrupt	 	*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 ADC Initializtion	 					*/
/************************************************************/

void	ADC_VoidInterruptEnable(void);



/************************************************************/
/* Description :  function to Start Converstion		 		*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 ADC Enable			 					*/
/************************************************************/

void	ADC_VoidStartConverstion(void);



/************************************************************/
/* Description :  function to set Auto Trigger value		*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 Interrupt initialized 					*/
/************************************************************/
void	ADC_VoidAutoTrigger(void);


/************************************************************/
/* Description :  function to set ADC Callback Function		*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 enable ADC Interrupt 					*/
/************************************************************/

void	ADC_VoidSetADCCallback(pf	copy_FunctionAdress);



#endif
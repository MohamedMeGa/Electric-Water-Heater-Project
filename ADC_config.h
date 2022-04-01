/************************************************************/
/* 			AUTHOR      : Mohamed MeGa	                   	*/
/* 			DISCRIPTION : ADC DRIVER     			       	*/
/* 			DATE        : 08 OCT 2021                       */
/* 			VERSION     : V01                              	*/
/************************************************************/

#ifndef	ADC_CONFIG_H
#define	ADC_CONFIG_H
/***************************************************/
/**			ADC Adjustment Can be :			   	   */
/**							Left_Adgustment        */
/**							Right_Adgustment	   */
/***************************************************/
#define	REG_ADJ				Left_Adgustment




/***************************************************/
/**			ADC voltage Reference Can be :		   */
/**							AREF        		   */
/**							AVCC		   		   */
/**							Internal	 		   */
/***************************************************/
#define	REF_SELECT			AVCC




/***************************************************/
/**			ADC CHANNEL Can be :			   	   */
/**							ADC0        		   */
/**							ADC1		   		   */
/**							ADC2		 		   */
/**							ADC3				   */
/**							ADC4				   */
/**							ADC5				   */
/**							ADC6				   */
/**							ADC7				   */
/***************************************************/
#define	ADC_CHANNEL			ADC0



/***************************************************/
/**			ADC Adjustment Can be :			   	   */
/**							PRES_2_DIV        	   */
/**							PRES_4_DIV	 		   */
/**							PRES_8_DIV	 		   */
/**							PRES_16_DIV			   */
/**							PRES_32_DIV			   */
/**							PRES_64_DIV			   */
/**							PRES_128_DIV		   */
/***************************************************/
#define	PRESCALE			PRES_64_DIV


/***************************************************/
/**			ADC Adjustment Can be :			   	   */
/**							Free_Running           */
/**							Analog_Comp		   	   */
/**							EXTI_0		 		   */
/**							Count0_Comp_Match	   */
/**							Count0_Overflow		   */
/**							Count0_Comp_MatchB	   */
/**							Count1_Overflow		   */
/***************************************************/
#define	TRIGGER_SELECT		Free_Running

#endif
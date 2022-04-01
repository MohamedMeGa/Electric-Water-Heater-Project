/************************************************************/
/**   		AUTHOR      : MOHAMED	MEGA	              	*/
/**   		Description : General INTERRUPT DRIVER	 		*/
/**   		DATE        : 19 OCT 2021                    	*/
/**   		VERSION     : V02                            	*/
/************************************************************/

#ifndef	GIE_INT_H
#define	GIE_INT_H


/************************************************************/
/** 		Description :  PROTOTYPE DECLARTION 		   	*/
/************************************************************/


/************************************************************/
/* Description :  function to Enable the ADC Interrupt	 	*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 Interrupt Initializtion	 			*/
/************************************************************/

void	GIE_VoidGIEEnable(void);




/************************************************************/
/* Description :  function to Disable the ADC Interrupt	 	*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 Interrupt Initializtion	 			*/
/************************************************************/

void	GIE_VoidGIEDisable(void);




#endif
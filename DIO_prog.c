/************************************************************/
/**   		AUTHOR      : Mohamed	MeGa	              	*/
/**   		Description : DIO DRIVER                     	*/
/**   		DATE        : 30 SEPT 2021                   	*/
/**   		VERSION     : V01                            	*/
/************************************************************/

/************************************************************/
/*			library Directives						  		*/
/************************************************************/
#include	"STD_Types.h"
#include	"Bit_Math.h"

/************************************************************/
/**			DIO Directives						 			*/
/************************************************************/
#include	"DIO_int.h"
#include	"DIO_config.h"
#include	"DIO_priv.h"


/************************************************************/
/* 			Description :  DIO	Implemention 		   	   */
/************************************************************/

/************************************************************/
/* 	Description :  function for initialization and define	*/
/*				   the direction of ports					*/
/************************************************************/

void	DIO_VoidInitialization(void)
{
	DDRA = DIO_u8_PORTA_DIRECTIONS;
	DDRB = DIO_u8_PORTB_DIRECTIONS;
	DDRC = DIO_u8_PORTC_DIRECTIONS;
	DDRD = DIO_u8_PORTD_DIRECTIONS;
}
/************************************************************/
/* Description :  function to set the value of any 			*/
/*				  pin to LOW or HIGH						*/
/************************************************************/

void	DIO_voidSetPinValue(u8	copy_u8PinNum, u8	copy_u8PinValue)
{
	if(copy_u8PinNum >= DIO_U8_PORTA_START && copy_u8PinNum <= DIO_U8_PORTA_END)
	{
		if(copy_u8PinValue == DIO_HIGH)
		{
			SET_BIT(PORTA, copy_u8PinNum);
		}
		else
		{
			CLEAR_BIT(PORTA, copy_u8PinNum);
		}
	}
	else if(copy_u8PinNum >= DIO_U8_PORTB_START && copy_u8PinNum <= DIO_U8_PORTB_END)
	{
		copy_u8PinNum = copy_u8PinNum - DIO_U8_PORTA_SIZE;
		if(copy_u8PinValue == DIO_HIGH)
		{
			SET_BIT(PORTB, copy_u8PinNum);
		}
		else
		{
			CLEAR_BIT(PORTB, copy_u8PinNum);
		}
	}
	
	else if(copy_u8PinNum >= DIO_U8_PORTC_START && copy_u8PinNum <= DIO_U8_PORTC_END)
	{
		copy_u8PinNum = copy_u8PinNum - (DIO_U8_PORTA_SIZE + DIO_U8_PORTB_SIZE);
		
		if(copy_u8PinValue == DIO_HIGH)
		{
			SET_BIT(PORTC, copy_u8PinNum);
		}
		else
		{
			CLEAR_BIT(PORTC, copy_u8PinNum);
		}
	}
	
	else if(copy_u8PinNum >= DIO_U8_PORTD_START && copy_u8PinNum <= DIO_U8_PORTD_END)
	{
		copy_u8PinNum = copy_u8PinNum - (DIO_U8_PORTA_SIZE + DIO_U8_PORTB_SIZE + DIO_U8_PORTC_SIZE);
		
		if(copy_u8PinValue == DIO_HIGH)
		{
			SET_BIT(PORTD, copy_u8PinNum);
		}
		else
		{
			CLEAR_BIT(PORTD, copy_u8PinNum);
		}
	}
}
/************************************************************/
/* Description :  function to Get the value of any pin 		*/
/************************************************************/

u8	DIO_u8GetPinValue(u8	copy_u8PinNum)
{
	u8 Loc_u8ReturnPinValue;
	if(copy_u8PinNum >= DIO_U8_PORTA_START && copy_u8PinNum <= DIO_U8_PORTA_END)
	{
		Loc_u8ReturnPinValue = GET_BIT(PINA, copy_u8PinNum);
	}
	else if(copy_u8PinNum >= DIO_U8_PORTB_START && copy_u8PinNum <= DIO_U8_PORTB_END)
	{
		copy_u8PinNum = copy_u8PinNum - DIO_U8_PORTA_SIZE;
		Loc_u8ReturnPinValue = GET_BIT(PINB, copy_u8PinNum);
		
	}
	
	else if(copy_u8PinNum >= DIO_U8_PORTC_START && copy_u8PinNum <= DIO_U8_PORTC_END)
	{
		copy_u8PinNum = copy_u8PinNum - (DIO_U8_PORTA_SIZE + DIO_U8_PORTB_SIZE);
		
		Loc_u8ReturnPinValue = GET_BIT(PINC, copy_u8PinNum);
	}
	
	else if(copy_u8PinNum >= DIO_U8_PORTD_START && copy_u8PinNum <= DIO_U8_PORTD_END)
	{
		copy_u8PinNum = copy_u8PinNum - (DIO_U8_PORTA_SIZE + DIO_U8_PORTB_SIZE + DIO_U8_PORTC_SIZE);
		
		Loc_u8ReturnPinValue = GET_BIT(PIND, copy_u8PinNum);
	}
	return Loc_u8ReturnPinValue;
}
/************************************************************/
/* 		Description :  function to set the direction of any */
/*				  pin to OUTPUT or INPUT					*/
/************************************************************/

void	DIO_voidSetPinDirection(u8	copy_u8PinNum, u8	copy_u8PinDir)
{
	if(copy_u8PinNum >= DIO_U8_PORTA_START && copy_u8PinNum <= DIO_U8_PORTA_END)
	{
		if(copy_u8PinDir == DIO_u8_OUTPUT)
		{
			SET_BIT(DDRA, copy_u8PinNum);
		}
		else
		{
			CLEAR_BIT(DDRA, copy_u8PinNum);
		}
	}
	else if(copy_u8PinNum >= DIO_U8_PORTB_START && copy_u8PinNum <= DIO_U8_PORTB_END)
	{
		copy_u8PinNum = copy_u8PinNum - DIO_U8_PORTA_SIZE;
		if(copy_u8PinDir == DIO_u8_OUTPUT)
		{
			SET_BIT(DDRB, copy_u8PinNum);
		}
		else
		{
			CLEAR_BIT(DDRB, copy_u8PinNum);
		}
	}
	
	else if(copy_u8PinNum >= DIO_U8_PORTC_START && copy_u8PinNum <= DIO_U8_PORTC_END)
	{
		copy_u8PinNum = copy_u8PinNum - (DIO_U8_PORTA_SIZE + DIO_U8_PORTB_SIZE);
		
		if(copy_u8PinDir == DIO_u8_OUTPUT)
		{
			SET_BIT(DDRC, copy_u8PinNum);
		}
		else
		{
			CLEAR_BIT(DDRC, copy_u8PinNum);
		}
	}
	
	else if(copy_u8PinNum >= DIO_U8_PORTD_START && copy_u8PinNum <= DIO_U8_PORTD_END)
	{
		copy_u8PinNum = copy_u8PinNum - (DIO_U8_PORTA_SIZE + DIO_U8_PORTB_SIZE + DIO_U8_PORTC_SIZE);
		
		if(copy_u8PinDir == DIO_u8_OUTPUT)
		{
			SET_BIT(DDRD, copy_u8PinNum);
		}
		else
		{
			CLEAR_BIT(DDRD, copy_u8PinNum);
		}
	}
}
/************************************************************/
/* Description :  function to Toggle the value of any 		*/
/*				  pin to LOW or HIGH						*/
/************************************************************/
void	DIO_voidTogglePin(u8	copy_u8PinNum)
{
	if(copy_u8PinNum >= DIO_U8_PORTA_START && copy_u8PinNum <= DIO_U8_PORTA_END)
	{
		
		TOGGLE_BIT(PORTA, copy_u8PinNum);
		
	}
	else if(copy_u8PinNum >= DIO_U8_PORTB_START && copy_u8PinNum <= DIO_U8_PORTB_END)
	{
		copy_u8PinNum = copy_u8PinNum - DIO_U8_PORTA_SIZE;
		
		TOGGLE_BIT(PORTB, copy_u8PinNum);
		
	}
	
	else if(copy_u8PinNum >= DIO_U8_PORTC_START && copy_u8PinNum <= DIO_U8_PORTC_END)
	{
		copy_u8PinNum = copy_u8PinNum - (DIO_U8_PORTA_SIZE + DIO_U8_PORTB_SIZE);
		
		TOGGLE_BIT(PORTC, copy_u8PinNum);
		
	}
	
	else if(copy_u8PinNum >= DIO_U8_PORTD_START && copy_u8PinNum <= DIO_U8_PORTD_END)
	{
		copy_u8PinNum = copy_u8PinNum - (DIO_U8_PORTA_SIZE + DIO_U8_PORTB_SIZE + DIO_U8_PORTC_SIZE);
		
		TOGGLE_BIT(PORTD, copy_u8PinNum);
		
	}
}
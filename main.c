/*
 * main.c
 *
 *  Created on: Mar 29, 2022
 *      Author: mabdalneeam
 *
 *		Input Pins
 *      D2 : Up Button
 *      D3 : DownButton
 *      B2 : ON / OFF Button
 *      A0 : Temperature Sensor
 *
 *
 *		Output Pins
 *      B1 : Header LED
 *      B5 : Heater
 *      B6 : Cooler
 *      A1 :: A7 : 7 Segment
 */

#include "STD_TYPES.h"
#include "Bit_Math.h"
#include "DIO_int.h"
#include "SEV_int.h"
#include "GIE_int.h"
#include "EXTI0_int.h"
#include "EXTI1_int.h"
#include "EXTI2_int.h"
#include "ADC_int.h"
#include <util/delay.h>

void Water_Heat(void);
void Water_Cool(void);
void ON_OFFMode(void);


static u16 temperature;
static mode = 0;			//to set ON or OFF Mode

int main(void)
{
	u8 temp1 = 0;
	u8 temp2 = 0;
	DIO_VoidInitialization();
	ADC_VoidInitialization();
	ADC_VoidADCEnable();

	EXTI0_VoidInitialization();
	EXTI0_VoidEnableEXTI0();
	EXTI0_VoidSetCallBack(Water_Heat);

	EXTI1_VoidInitialization();
	EXTI1_VoidEnableEXTI1();
	EXTI1_VoidSetCallBack(Water_Cool);

	EXTI2_VoidInitialization();
	EXTI2_VoidEnableEXTI2();
	EXTI2_VoidSetCallBack(ON_OFFMode);

	GIE_VoidGIEEnable();
	TIMER0_VoidInitialization();

	DIO_voidSetPinValue(DIO_PIN26, DIO_HIGH);	//EXTI 0 to heat
	DIO_voidSetPinValue(DIO_PIN27, DIO_HIGH);	//EXTI 1 to Cool
	DIO_voidSetPinValue(DIO_PIN10, DIO_HIGH);	//EXTI 2 to ON/OFF


	//Setting Mode to up temperature to 60c
	while(temperature <= 60)
	{
		Water_Heat();
		temperature  = ADC_U16ReadADC();
		temp1 = (u8)(temperature & 0xFF);		//to split int into two char
		temp2 = (u8)(temperature >> 8);
		SEV_VoidSET7SegmentValue(SEV_SEG_RIGHT, temp1);
		SEV_VoidSET7SegmentValue(SEV_SEG_LEFT, temp2);

	}



	while(1)
	{
		if(mode == 1)		//ON mode
		{
			temperature  = ADC_U16ReadADC();

			temp1 = (u8)(temperature & 0xFF);	//to split int into two char
			temp2 = (u8)(temperature >> 8);
			SEV_VoidSET7SegmentValue(SEV_SEG_RIGHT, temp1);
			SEV_VoidSET7SegmentValue(SEV_SEG_LEFT, temp2);
			_delay_ms(100);

		}else if(mode == 0)	//OFF Mode
		{
			DIO_voidSetPinValue(DIO_PIN13, DIO_LOW);	//heater OFF
			DIO_voidSetPinValue(DIO_PIN14, DIO_LOW);	//cOOLER oFF
		}
	}
	return 0;

}



void Water_Heat(void)
{
	if(temperature >= 0 && temperature < 75)
	{
		DIO_voidSetPinValue(DIO_PIN13, DIO_HIGH);

		//ASSUME THAT WE NEED TO TURN ON HEATER 10 SEC TO INCREASE TEMPERATURE BY 5
		for(int i=0; i<10; i++){
			DIO_voidTogglePin(DIO_PIN9);
			_delay_ms(1000);
		}

		DIO_voidSetPinValue(DIO_PIN13, DIO_LOW);
	}else
	{
		DIO_voidSetPinValue(DIO_PIN13, DIO_LOW);
	}
}




void Water_Cool(void)
{
	if(temperature > 75 && temperature > 35)
	{
		//ASSUME THAT WE NEED TO TURN ON COOLER 10 SEC TO DECREASE TEMPERATURE BY 5
		DIO_voidSetPinValue(DIO_PIN14, DIO_HIGH);
		DIO_voidSetPinValue(DIO_PIN9, DIO_HIGH);
		_delay_ms(10000);

		DIO_voidSetPinValue(DIO_PIN14, DIO_LOW);
		DIO_voidSetPinValue(DIO_PIN9, DIO_LOW);
	}else
	{
		DIO_voidSetPinValue(DIO_PIN14, DIO_LOW);
	}
}






void ON_OFFMode(void)
{
	if(mode == 0)
	{
		mode = 1;

	}else if(mode == 1)
	{
		mode = 0;
	}
}

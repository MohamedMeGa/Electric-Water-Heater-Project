#include "Std_Types.h"
#include "Bit_Math.h"

#include "TWI_interface.h"

#include "EEPROM_private.h"
#include "EEPROM_config.h"
#include "EEPROM_int.h"
/*1020*/
u8		EEPROM_u8WriteByte(u16 Add , u8 Data)
{
	u8 Local_State = 1;
	/*	Start Condition						*/
	TWI_enuSendStartCondition();
	/*	Send Slave Add	(1010(A2)(A1)(A0))	*/
	TWI_enuSendSLAwithWrite( EEPROM_ADD | ((Add>>8)&0x7)  );
	/*	Send Byte Add						*/
	TWI_enuSendDataByteMaster(((u8)Add));
	/*	Send Data Byte						*/
	TWI_enuSendDataByteMaster(Data);
	/*	Stop Condition						*/
	TWI_voidSendStopCondition();
}

u8		EEPROM_u8ReadByte(u16 Add , u8 * Data)
{
	u8 Local_State = 1;
	/*	Start Condition						*/
	TWI_enuSendStartCondition();
	/*	Send Slave Add	(1010(A2)(A1)(A0))	*/
	TWI_enuSendSLAwithWrite( EEPROM_ADD | ((Add>>8)&0x7)  );
	/*	Send Byte Add						*/
	TWI_enuSendDataByteMaster(((u8)Add));
	
	/*	Repeated Start Condition			*/	
	TWI_enuSendReStartCondition();
	/*	Send Slave Add	(1010(A2)(A1)(A0))	*/
	TWI_enuSendSLAwithRead( EEPROM_ADD | ((Add>>8)&0x7)  );
	/*	Read Data Byte						*/
	TWI_enuSendReadDataByteMaster(Data);
	/*	Stop Condition						*/
	TWI_voidSendStopCondition();	
}
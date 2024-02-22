#include "STD_TYPES.h"
#include "TWI_interface.h"
#include "PORT_interface.h"
#include "DIO_interface.h"

#include "EEPROM_interface.h"

void main(void)
{
	u8 Local_u8ReceivedData;
	PORT_voidInit();		/*Define PORTA as output*/

	TWI_voidInitMaster(0);

	EEPROM_voidSendDataByte(0, 0x55);

	Local_u8ReceivedData = EEPROM_u8ReadDataByte(0);

	DIO_u8SetPortValue(DIO_u8PORTA,Local_u8ReceivedData);

	while(1)
	{

	}
}

#include "STD_TYPES.h"

#include "CLCD_interface.h"
#include "DIO_interface.h"

void main(void)
{
	/*Initialize LCD pins direction*/
	DIO_u8SetPortDirection(DIO_u8PORTA,DIO_u8PORT_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTC,DIO_u8PIN2,DIO_u8PIN_OUTPUT);

	CLCD_voidInit();

	CLCD_voidSendData('A');
	CLCD_voidSendData('M');
	CLCD_voidSendData('G');
	CLCD_voidSendData('A');
	CLCD_voidSendData('D');

	while(1)
	{

	}
}

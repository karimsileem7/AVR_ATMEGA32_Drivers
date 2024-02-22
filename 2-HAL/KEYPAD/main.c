#include "STD_TYPES.h"
#include "PORT_interface.h"
#include "DIO_interface.h"
#include <util/delay.h>
#include "CLCD_interface.h"
#include "KPD_interface.h"
#include "BIT_MATH.h"


void main(void)
{
//u8 Local_u8Key;
	PORT_voidInit();

	while(1){
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN7,DIO_u8PIN_HIGH);
		_delay_ms(1000);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN7,DIO_u8PIN_LOW);
		_delay_ms(1000);
	}

}



/*CLCD_voidInit();

while(1)
{
	do {
		Local_u8Key=KPD_u8GetPressedKey();

	}while(Local_u8Key==0xff);

	CLCD_voidSendData(Local_u8Key+'0');
}*/






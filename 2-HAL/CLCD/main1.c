#include "STD_TYPES.h"
#include "CLCD_interface.h"
#include "DIO_interface.h"
#include<util/delay.h>
#include "PORT_interface.h"


void main(void)
{
	/*initialize LCD pins Direction*/

PORT_voidInit();

	CLCD_voidInit();

	/*CLCD_voidSendData('Z');
	CLCD_voidSendData('A');
	CLCD_voidSendData('M');
	CLCD_voidSendData('A');
	CLCD_voidSendData('L');
	CLCD_voidSendData('E');
	CLCD_voidSendData('K');*/

	CLCD_voidGoToXY(0,4);

	//	CLCD_voidSendString("A7A");

CLCD_voidWriteNumber(1234);


while(1)
{

}




}

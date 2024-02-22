/*********************************************************/
/***********		ENG: KARIM SILEEM 	**************/
/***********		Layer: HAL			 	**************/
/***********		Component: CLCD 		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 14-8/2020		 	**************/
/*********************************************************/

#include "STD_TYPES.h"
#include <util/delay.h>

#include "DIO_interface.h"

#include "CLCD_config.h"
#include "CLCD_interface.h"
#include "CLCD_private.h"

void CLCD_voidSendCommand(u8 Copy_u8Command)
{
	/*Set RS pin to low for command*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_LOW);

	/*Set RW pin to low for write*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);

	/*Set command to data pins*/
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Command);

	/*Send enable pulse*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
}

void CLCD_voidSendData(u8 Copy_u8Data)
{
	/*Set RS pin to high for data*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_HIGH);

	/*Set RW pin to low for write*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);

	/*Set Data to data pins*/
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Data);

	/*Send enable pulse*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
}

void CLCD_voidInit(void)
{
	/*Wait for more than 30 ms*/
	_delay_ms(40);

	/*Function set command: 2 lines, 5*8 Font size*/
	CLCD_voidSendCommand(0b00111000);

	/*Display on off control: display enable, disable cursor, no blink cursor*/
	CLCD_voidSendCommand(0b00001100);

	/*Clear display*/
	CLCD_voidSendCommand(1);
}

void CLCD_voidSendString(const char * Copy_pcString)
{
	s8 i=0;
	while(Copy_pcString[i]!='\0')
	{
		CLCD_voidSendData(Copy_pcString[i]);
		i++;
	}
}


void CLCD_voidGoToXY(u8 Copy_u8XPos,u8 Copy_u8YPos)
{
	u8 Local_u8Address;
	if(Copy_u8XPos==0)
	{
		/*location at first line*/
		Local_u8Address=Copy_u8YPos;
	}
	else if(Copy_u8XPos==1)
	{
		/*location at second line*/
		Local_u8Address=Copy_u8YPos+0x40;
	}
	/*from data sheet to set DDRAM TO stay first 7 Pins of Local_u8Address of as normal and last Pin should be 1*/
	CLCD_voidSendCommand(Local_u8Address+128);
}

void CLCD_voidWriteSpecialcharacter(u8* Copy_pu8Pattern ,u8 Copy_u8PatternNumber,u8 Copy_u8XPos,u8 Copy_u8YPos)
{

	u8 Local_u8Address=0,Local_u8Iterator;
	/*calculate the CGRAM address whose each block is 8 bytes*/
	u8 Local_u8CGRAMAddress=Copy_u8PatternNumber*8;

	/*to access CGRAM according to Data Sheet */
	CLCD_voidSendCommand(Local_u8Address+64);
	/*to Write at CGRAM*/
	for(Local_u8Iterator=0;Local_u8Iterator<8;Local_u8Iterator++)
	{
		CLCD_voidSendData(Copy_pu8Pattern[Local_u8Iterator]);
	}
	/*back to DDRAM to display*/
	CLCD_voidGoToXY(Copy_u8XPos,Copy_u8YPos);

	CLCD_voidSendData(Copy_u8PatternNumber);



}

void CLCD_voidWriteNumber(u32 Copy_u32Number)
{
	u32 Local_u32Reserved=1;

	while(Copy_u32Number!=0)
	{
		Local_u32Reserved=Local_u32Reserved*10 + Copy_u32Number%10;
		Copy_u32Number/=10;
	}
	do
	{
		CLCD_voidSendData((Local_u32Reserved%10)+'0');
		Local_u32Reserved/=10;
	}
	while(Local_u32Reserved!=1);
}































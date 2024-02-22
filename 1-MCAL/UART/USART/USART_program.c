#include "../../4-LIB/STD_TYPES.h"
#include "../../4-LIB/BITS_MATH.h"


#include "USART_config.h"
#include "USART_private.h"
#include "USART_interface.h"
#include "USART_register.h"



void USART_voidInit(void){
	u8 Local_u8UCSRCValue=0;
	Set_Bit(Local_u8UCSRCValue,7);			//use UCSRRC
	Set_Bit(Local_u8UCSRCValue,UCSRC_UCSZ1); //set to 8 bit
	Set_Bit(Local_u8UCSRCValue,UCSRC_UCSZ0);//set to 8 bit

	UCSRC=Local_u8UCSRCValue;

	UBRRL=51;								//baud rate 9600 bit/sec



	Set_Bit(UCSRB,UCSRB_TXEN);//TX	En
	Set_Bit(UCSRB,UCSRB_RXEN); //Re enable


}

u8 USART_u8Receive(void){
	while(Get_Bit(UCSRA,UCSRA_RXC)==0); 	//wait until RXC flag is set
	return UDR;


}

void USART_voidSend(u8 Copy_u8data){
	while(Get_Bit(UCSRA,UCSRA_UDRE)==0);	//wait until transmit data is empty
	UDR=Copy_u8data;

}




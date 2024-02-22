/*********************************************************/
/***********		Author: KARIM SILEEM 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: PORT 		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 14-8/2020		 	**************/
/*********************************************************/


#include "STD_TYPES.h"

#include  "PORT_config.h"
#include  "PORT_private.h"
#include  "PORT_interface.h"
#include  "PORT_register.h"


void PORT_voidInit(void)
{
	DDRA=PORTA_DIR;
	DDRB=PORTB_DIR;
	DDRC=PORTC_DIR;
	DDRD=PORTD_DIR;
	
	PORTA=PORTA_INITIAL_VALUE;
	PORTB=PORTB_INITIAL_VALUE;
	PORTC=PORTC_INITIAL_VALUE;
	PORTD=PORTD_INITIAL_VALUE;

	
	
	

	
		
}


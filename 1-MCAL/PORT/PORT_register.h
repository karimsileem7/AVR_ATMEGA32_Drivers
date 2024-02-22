/*********************************************************/
/***********		Author: KARIM SILEEM 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: PORT 		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 14-8/2020		 	**************/
/*********************************************************/


#ifndef PORT_REGISTER_H_
#define PORT_REGISTER_H_

#define DDRA 		*((volatile u8*)0x3a)
#define DDRB 		*((volatile u8*)0x37)
#define DDRC 		*((volatile u8*)0x34)
#define DDRD 		*((volatile u8*)0x31)

#define PORTA 		*((volatile u8*)0x3b)
#define PORTB 		*((volatile u8*)0x38)
#define PORTC 		*((volatile u8*)0x35)
#define PORTD 		*((volatile u8*)0x32)




#endif
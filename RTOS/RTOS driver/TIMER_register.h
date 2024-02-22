/**********************************************************************/
/**********************************************************************/
/*****************		Author: Amgad Samir		***********************/
/*****************		Layer:	MCAL 			***********************/
/*****************		SWC:	TIMER			***********************/
/*****************		Version:1.00			***********************/
/**********************************************************************/
/**********************************************************************/

#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_

#define TCCR0			*((volatile u8*)0x53)			/*Timer0 control reister*/
#define TCCR0_WGM00		6								/*Wavefoem generation Mode bit0*/
#define TCCR0_WGM01		3                               /*Waveform generation mode bit1*/
#define TCCR0_CS02		2                               /*Prescaler bit2*/
#define TCCR0_CS01		1                               /*Prescaler bit1*/
#define TCCR0_CS00		0                               /*Prescaler bit0*/

#define TCCR1B			*((volatile u8*)0x4E)			/*Timer1 control register B*/
#define TCCR1B_CS12		2                               /*Prescaler bit2*/
#define TCCR1B_CS11		1                               /*Prescaler bit1*/
#define TCCR1B_CS10		0                               /*Prescaler bit0*/

#define TCNT1			*((volatile u16*)0x4C)			/*Timer/counter1 register*/
														
#define OCR0			*((volatile u8*)0x5C)			/*Output compare register 0*/

#define TIMSK			*((volatile u8*)0x59)			/*Timer mask*/
#define TIMSK_OCIE0		1								/*Output compare 0 interrupt enable*/


#endif

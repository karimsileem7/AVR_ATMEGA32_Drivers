/*********************************************************/
/***********		Author: KARIM SILEEM 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: SPI 		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 14-8/2020		 	**************/
/*********************************************************/


#ifndef SPI_REGISTER_H_
#define SPI_REGISTER_H_
 #define SPDR   *((volatile u8*0x2F))
 
 #define SPSR   *((volatile u8*)0x2E)
 #define SPSR_SPIF     7
 #define SPSR_SPI2X    0
 
 #define SPCR         *((volatile u8*)0x2D)
 #define SPCR_SPE     6
 #define SPCR_MSTR    4
 #define SPCR_SPR1    1
 #define SPCR_SPR0    0
 
 
 

#endif
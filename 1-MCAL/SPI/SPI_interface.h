/*********************************************************/
/***********		Author: KARIM SILEEM 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: SPI 		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 14-8/2020		 	**************/
/*********************************************************/


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

void SPI_voidInitMaster(void);

void SPI_voidInitSlave(void);

u8 SPI_u8Transcieve(u8 Copy_u8Data);






#endif
/*****************************************************************/
/*****************************************************************/
/********************		Author: Amgad Samir		**************/
/********************		Layer: MCAL				**************/
/********************		SWC: ADC				**************/
/********************		Version: 1.00			**************/
/********************		Date: 5-9-2020			**************/
/*****************************************************************/
/*****************************************************************/

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

void ADC_voidInit(void);

u8 ADC_u8StartConversionSynch(u8 Copy_u8Channel, u8* Copy_pu8Reading);

u8 ADC_u8StartConversionAsynch(u8 Copy_u8Channel, u8* Copy_pu8Reading, void(*Copy_pvNotificationFunc)(void));



#endif

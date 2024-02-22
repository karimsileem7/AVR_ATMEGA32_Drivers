/********************		Author: Abdelrahman Moustafa		**************/
/********************		Layer: MCAL							**************/
/********************		SWC: TWI							**************/
/********************		Version: 1.00						**************/
/********************		Date: 28-8-2020						**************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_

typedef enum
{
	NoError,
	StartConditionErr,
	RepeatedStartErr,
	SlaveAddressWithWriteErr,
	SlaveAddressWithReadErr,
	MasterWriteByteErr,
	MasterReadByteErr,
}TWI_Errstatus;

/*Pass 0 in the Slave address Argument if master will not be addressed*/
void TWI_voidMasterInit(u8 Copy_u8SlaveAddress);

void TWI_voidSlaveInit(u8 Copy_u8SlaveAddress);

TWI_Errstatus TWI_SendStartCondition(void);

TWI_Errstatus TWI_SendRepeatStart(void);

TWI_Errstatus TWI_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress);

TWI_Errstatus TWI_SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress);

TWI_Errstatus TWI_MasterWriteDataByte(u8 Copy_u8DataByte);

TWI_Errstatus TWI_MasterReadDataByte(u8 * Copy_pu8DataByte);

void TWI_SendStopCondition(void);

#endif

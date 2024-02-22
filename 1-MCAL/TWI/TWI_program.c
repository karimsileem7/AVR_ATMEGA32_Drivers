/********************		Author: Abdelrahman Moustafa		**************/
/********************		Layer: MCAL							**************/
/********************		SWC: TWI							**************/
/********************		Version: 1.00						**************/
/********************		Date: 28-8-2020						**************/
/*****************************************************************************/
/*****************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TWI_config.h"
#include "TWI_interface.h"
#include "TWI_private.h"
#include "TWI_register.h"

void TWI_voidMasterInit(u8 Copy_u8SlaveAddress)
{
	/*Set Clock Frequency To 400Kbps*/
	/*Set TWBR to 2*/
	TWBR = 2;

	/*Clear the 2 bits of TWPS*/
	CLR_BIT(TWSR,TWSR_TWPS0);
	CLR_BIT(TWSR,TWSR_TWPS1);

	/*INitialize the node address*/
	if(Copy_u8SlaveAddress != 0)
	{
		TWAR = Copy_u8SlaveAddress << 1;
	}

	/*Enable TWI*/
	SET_BIT(TWCR,TWCR_TWEN);
}

void TWI_voidSlaveInit(u8 Copy_u8SlaveAddress)
{
	/*INitialize the node address*/
	TWAR = Copy_u8SlaveAddress << 1;

	/*Enable TWI*/
	SET_BIT(TWCR,TWCR_TWEN);
}

TWI_Errstatus TWI_SendStartCondition(void)
{
	TWI_Errstatus Local_ErrorStatus = NoError;

	/*Send Start Condition on The Bus*/
	SET_BIT(TWCR,TWCR_TWSTA);

	/*Clear the interrupt flag to start the previous operation is complete*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*wait until the interrupt flag is raised again*/
	while((GET_BIT(TWCR,TWCR_TWINT)) == 0);

	/*Check the operation status in the status register*/
	if(TWSR & 0xF8 != START_ACK)
	{
		Local_ErrorStatus = StartConditionErr;
	}
	else
	{
		/*Do nothing*/
	}
	return Local_ErrorStatus;
}

TWI_Errstatus TWI_SendRepeatStart(void)
{
	TWI_Errstatus Local_ErrorStatus = NoError;

	/*Send Start Condition on The Bus*/
	SET_BIT(TWCR,TWCR_TWSTA);

	/*Clear the interrupt flag to start the previous operation is complete*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*wait until the interrupt flag is raised again*/
	while((GET_BIT(TWCR,TWCR_TWINT)) == 0);

	/*Check the operation status in the status register*/
	if(TWSR & 0xF8 != REP_START_ACK)
	{
		Local_ErrorStatus = RepeatedStartErr;
	}
	else
	{
		/*Do nothing*/
	}
	return Local_ErrorStatus;
}

TWI_Errstatus TWI_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress)
{
	TWI_Errstatus Local_ErrorStatus = NoError;

	/*Clear The Start condition bit*/
	CLR_BIT(TWCR,TWCR_TWSTA);

	/*Set the slave address in the 7 MSB in the data register*/
	TWDR = Copy_u8SlaveAddress << 1;
	/*For write request*/
	CLR_BIT(TWDR,0);

	/*Clear the interrupt flag to start the previous operation is complete*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*wait until the interrupt flag is raised again*/
	while((GET_BIT(TWCR,TWCR_TWINT)) == 0);

	/*Check the operation status in the status register*/
	if(TWSR & 0xF8 != SLAVE_ADD_AND_WR_ACK)
	{
		Local_ErrorStatus = SlaveAddressWithWriteErr;
	}
	else
	{
		/*Do nothing*/
	}

	return Local_ErrorStatus;
}

TWI_Errstatus TWI_SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress)
{
	TWI_Errstatus Local_ErrorStatus = NoError;

	/*Clear The Start condition bit*/
	CLR_BIT(TWCR,TWCR_TWSTA);

	/*Set the slave address in the 7 MSB in the data register*/
	TWDR = Copy_u8SlaveAddress << 1;
	/*For Read request*/
	SET_BIT(TWDR,0);

	/*Clear the interrupt flag to start the previous operation is complete*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*wait until the interrupt flag is raised again*/
	while((GET_BIT(TWCR,TWCR_TWINT)) == 0);

	/*Check the operation status in the status register*/
	if(TWSR & 0xF8 != SLAVE_ADD_AND_RD_ACK)
	{
		Local_ErrorStatus = SlaveAddressWithReadErr;
	}
	else
	{
		/*Do nothing*/
	}


	return Local_ErrorStatus;
}

TWI_Errstatus TWI_MasterWriteDataByte(u8 Copy_u8DataByte)
{
	TWI_Errstatus Local_ErrorStatus = NoError;

	/*Write the data byte*/
	TWDR = Copy_u8DataByte;

	/*Clear the interrupt flag to start the previous operation is complete*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*wait until the interrupt flag is raised again*/
	while((GET_BIT(TWCR,TWCR_TWINT)) == 0);

	/*Check the operation status in the status register*/
	if(TWSR & 0xF8 != MSTR_WR_BYTE_ACK)
	{
		Local_ErrorStatus = MasterWriteByteErr;
	}
	else
	{
		/*Do nothing*/
	}

	return Local_ErrorStatus;
}

TWI_Errstatus TWI_MasterReadDataByte(u8 * Copy_pu8DataByte)
{
	TWI_Errstatus Local_ErrorStatus = NoError;

	/*Enable Master generation Acknowledge bit after receiving the data */
	SET_BIT(TWCR,TWCR_TWEA)

	/*Clear the interrupt flag to start the Slave Sending Data*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*wait until the interrupt flag is raised again*/
	while((GET_BIT(TWCR,TWCR_TWINT)) == 0);

	/*Check the operation status in the status register*/
	if(TWSR & 0xF8 != MSTR_RD_BYTE_WITH_ACK)
	{
		Local_ErrorStatus = MasterReadByteErr;
	}
	else
	{
		/*Read the received data*/
		*Copy_pu8DataByte = TWDR;
	}

	return Local_ErrorStatus;
}

void TWI_SendStopCondition(void)
{
	/*Generate Stop Condition on The Bus*/
	SET_BIT(TWCR,TWCR_TWSTO);

	/*Clear the interrupt flag to start the previous operation is complete*/
	SET_BIT(TWCR,TWCR_TWINT);
}

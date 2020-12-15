#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include"TWI_Priv.h"
#include"TWI_Config.h"
#include"../Global Interrupt/GIE_Config.h"





void TWI_VidMasterInit(void)
{
	/*ENABLE ACK*/
	SET_BIT(TWCR,TWEA); 
	/*ENABLE TWI*/
	SET_BIT(TWCR,TWEN); 
	
	/*SPEED OF TWI*/
	
	/*TWPS-PRESCALER*/
	CLR_BIT(TWSR,TWPS0);
	CLR_BIT(TWSR,TWPS1);
	/*TWBR-VALUE*/
	TWBR=32;	
}


void TWI_VidSlaveInit(u8 LOC_u8SlaveAdress)
{
	/*TWAR-SLAVE ADRESS*/
	TWAR=(LOC_u8SlaveAdress << 1)| TWAR;
	/*ENABLE ACK*/
	SET_BIT(TWCR,TWEA); 
	/*ENABLE TWI*/
	SET_BIT(TWCR,TWEN); 
}

u8 TWI_u8StartCondition(void)
{
	u8 ERROR_STATUS=NOK;
	/*START CONDITION */
	SET_BIT(TWCR,TWSTA);
	/*CLEAR FLAG*/
	SET_BIT(TWCR,TWINT);
	while ( (GET_BIT(TWCR,TWINT)) != 1){} //WAITING FOR FLAG
	if((TWSR>>3) == STARTCONDITION )
	{
		ERROR_STATUS=OK;
	}
	return ERROR_STATUS;	
}

u8 TWI_u8SendSlaveAdressWithWrite(u8 LOC_u8SlaveAdress)
{
	u8 ERROR_STATUS=NOK;
	TWDR=((LOC_u8SlaveAdress<<1)|0x00);
	/*CLEAR START CONDITION */
	CLR_BIT(TWCR,TWSTA);
	/*CLEAR FLAG*/
	SET_BIT(TWCR,TWINT);
	while ( (GET_BIT(TWCR,TWINT)) != 1){} //WAITING FOR FLAG
	if((TWSR>>3) == SendSlaveAdressWithWrite )
	{
   	ERROR_STATUS=OK;
    }
    return ERROR_STATUS;	
}
u8 TWI_u8SendSlaveAdressWithRead(u8 LOC_u8SlaveAdress)
{
	u8 ERROR_STATUS=NOK;
	TWDR=((LOC_u8SlaveAdress<<1)|0x01);
	/*CLEAR START CONDITION */
	CLR_BIT(TWCR,TWSTA);
	/*CLEAR FLAG*/
	SET_BIT(TWCR,TWINT);
	while ( (GET_BIT(TWCR,TWINT)) != 1){} //WAITING FOR FLAG
	if((TWSR>>3) == SendSlaveAdressWithRead )
	{
	ERROR_STATUS=OK;
    }
    return ERROR_STATUS;
}

u8 TWI_u8MasterSendData(u8 LOC_u8Data)
{
	u8 ERROR_STATUS=NOK;
	TWDR=((LOC_u8Data<<1)| 0x01);
	/*CLEAR START CONDITION */
	CLR_BIT(TWCR,TWSTA);
	/*CLEAR FLAG*/
	SET_BIT(TWCR,TWINT);
	while ( (GET_BIT(TWCR,TWINT)) != 1){} //WAITING FOR FLAG
    if((TWSR>>3) == MasterSendData )
    {
    ERROR_STATUS=OK;
    }
    return ERROR_STATUS;
}

u8 TWI_u8MasterReceieveData(u8*ReceivedData)
{
	u8 ERROR_STATUS=NOK;
	/*CLEAR START CONDITION */
	CLR_BIT(TWCR,TWSTA);
	/*CLEAR FLAG*/
	SET_BIT(TWCR,TWINT);
	while ( (GET_BIT(TWCR,TWINT)) != 1){} //WAITING FOR FLAG
	if((TWSR>>3) == MasterReceieveData )
	{
	 *ReceivedData=TWDR;
	 ERROR_STATUS=OK;
	}
	return ERROR_STATUS;
}

u8 TWI_u8StopCondition(void)
{
	u8 ERROR_STATUS=NOK;
	/*STOP CONDITION */
	SET_BIT(TWCR,TWSTO);
	/*CLEAR FLAG*/
	SET_BIT(TWCR,TWINT);
  return ERROR_STATUS;	
}


u8 TWI_u8RepeatedStartCondition(void)
{
	u8 ERROR_STATUS=NOK;
	/*START CONDITION */
	SET_BIT(TWCR,TWSTA);
	/*CLEAR FLAG*/
	SET_BIT(TWCR,TWINT);
	while ( (GET_BIT(TWCR,TWINT)) != 1){} //WAITING FOR FLAG
	if((TWSR>>3) == REPEATEDSTARTCONDITION )
	{
		ERROR_STATUS=OK;
    }
    return ERROR_STATUS;
}	

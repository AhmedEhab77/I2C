#ifndef  _TWI_INT_H_
#define  _TWI_INT_H_


void TWI_VidMasterInit(void);

void TWI_VidSlaveInit(u8 LOC_u8SlaveAdress);

u8 TWI_u8StartCondition(void);

u8 TWI_u8RepeatedStartCondition(void);
	   
u8 TWI_u8SendSlaveAdressWithWrite(u8 LOC_u8SlaveAdress);
	   
u8 TWI_u8SendSlaveAdressWithRead(u8 LOC_u8SlaveAdress);
	   
u8 TWI_u8MasterSendData(u8 LOC_u8Data);
	   
u8 TWI_u8MasterRecieveData(u8*ReceivedData);

u8 TWI_u8StopCondition(void);











#endif
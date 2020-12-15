#ifndef  _TWI_CONFIG_H_
#define  _TWI_CONFIG_H_


      
/*TWI Control Register -TWCR*/
#define TWINT     7
#define TWEA      6
#define TWSTA     5
#define TWSTO     4
#define TWWC      3
#define TWEN      2
#define TWIE      0

       
/*TWI Status Register -TWSR*/
#define TWS7      7
#define TWS6      6
#define TWS5      5
#define TWS4      4
#define TWS3      3
#define TWPS1     1
#define TWPS0     0

/*TWI Slave Adress Register -TWAR*/
#define TWGCE     0

/*TWI ERROR STATE*/
#define NOK    0
#define OK     1


/*STATUS OF TWSR REGISTER */
#define STARTCONDITION            0x08   

#define SendSlaveAdressWithWrite  0x18

#define SendSlaveAdressWithRead   0x40

#define MasterSendData            0x28

#define MasterReceieveData        0x50

#define REPEATEDSTARTCONDITION    0x10








#endif
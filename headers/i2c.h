#ifndef I2C_H_
#define I2C_H_

#include "Std_types.h"

#define TWBR    *((volatile u8*)(0x20))
#define TWSR    *((volatile u8*)(0x21))
#define TWAR    *((volatile u8*)(0x22))
#define TWDR    *((volatile u8*)(0x23))
#define TWCR    *((volatile u8*)(0x56))

#define TWEN    2
#define TWSTO   4
#define TWSTA   5
#define TWEA    6
#define TWINT   7

/* Read/Write Options */
#define I2C_WRITE   0
#define I2C_READ    1


void I2C_Init(void);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_Write(u8 data);
u8   I2C_ReadAck(void);
u8   I2C_ReadNack(void);

#endif
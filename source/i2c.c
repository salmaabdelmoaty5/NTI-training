#include "i2c.h"

/* Initialize I2C Master Mode (100kHz bit rate at 16MHz clock) */
void I2C_Init(void)
{
    TWBR = 32;          /* Bit rate generator register */
    TWSR = 0x00;        /* Prescaler = 1 */
    TWCR = (1 << TWEN); /* Enable I2C module */
}

void I2C_Start(void)
{
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
}
void I2C_Stop(void)
{
    TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
}

void I2C_Write(u8 data)
{
    TWDR = data;
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT))); 
}


u8 I2C_ReadAck(void)
{
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
    while (!(TWCR & (1 << TWINT)));
    return TWDR;
}


u8 I2C_ReadNack(void)
{
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    return TWDR;
}
#ifndef SPI_H_
#define SPI_H_


#define SPI_MASTER    0
#define SPI_SLAVE     1
#define SPI_MODE      SPI_MASTER


#define SPCR          (*(volatile u8*)0x2D)
#define SPSR          (*(volatile u8*)0x2E)
#define SPDR          (*(volatile u8*)0x2F)


void SPI_Init(void);
void SPI_SendChar(u8 copy_u8Data);
u8 SPI_GetChar(void);
u8 SPI_Transceive(u8 copy_u8Data);

#endif 
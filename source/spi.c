
#include "Std_types.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "SPI.h"

void SPI_Init(void)
{
#if SPI_MODE == SPI_MASTER
    DIO_voidSetPinDirection(PORTB, PIN4, OUTPUT);
    DIO_voidSetPinDirection(PORTB, PIN5, OUTPUT);
    DIO_voidSetPinDirection(PORTB, PIN7, OUTPUT);
    DIO_voidSetPinDirection(PORTB, PIN6, INPUT);
    

    DIO_voidSetPinValue(PORTB, PIN6, HIGH);
    SPCR = 0b01011010;

#elif SPI_MODE == SPI_SLAVE

    DIO_voidSetPinDirection(PORTB, PIN4, INPUT);
    DIO_voidSetPinDirection(PORTB, PIN5, INPUT);
    DIO_voidSetPinDirection(PORTB, PIN7, INPUT);
    DIO_voidSetPinDirection(PORTB, PIN6, OUTPUT);
    SPCR = 0b01001010;
#endif

    CLR_BIT(SPSR, PIN0);
}

void SPI_SendChar(u8 copy_u8Data)
{
    SPDR = copy_u8Data;
    while (!GET_BIT(SPSR, PIN7));
}

u8 SPI_GetChar(void)
{
    while (!GET_BIT(SPSR, PIN7));
    return SPDR;
}

u8 SPI_Transceive(u8 copy_u8Data)
{
    SPDR = copy_u8Data;
    while (!GET_BIT(SPSR, PIN7));
    return SPDR;
}

/*
 * SPI.c
 *
 * Created on: Sep 9, 2026
 * Author: Hager Adel
 */

#include "Std_types.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "SPI.h"

void SPI_Init(void)
{
#if SPI_MODE == SPI_MASTER
    DIO_voidSetPinDirection(PORTB, 4, OUTPUT);
    DIO_voidSetPinDirection(PORTB, 5, OUTPUT);
    DIO_voidSetPinDirection(PORTB, 7, OUTPUT);
    DIO_voidSetPinDirection(PORTB, 6, INPUT);
    

    DIO_voidSetPinValue(PORTB, 6, HIGH);
    SPCR = 0b01011010;

#elif SPI_MODE == SPI_SLAVE

    DIO_voidSetPinDirection(PORTB, 4, INPUT);
    DIO_voidSetPinDirection(PORTB, 5, INPUT);
    DIO_voidSetPinDirection(PORTB, 7, INPUT);
    DIO_voidSetPinDirection(PORTB, 6, OUTPUT);
    SPCR = 0b01001010;
#endif

    CLR_BIT(SPSR, 0);
}

void SPI_SendChar(u8 copy_u8Data)
{
    SPDR = copy_u8Data;
    while (!GET_BIT(SPSR, 7));
}

u8 SPI_GetChar(void)
{
    while (!GET_BIT(SPSR, 7));
    return SPDR;
}

u8 SPI_Transceive(u8 copy_u8Data)
{
    SPDR = copy_u8Data;
    while (!GET_BIT(SPSR, 7));
    return SPDR;
}
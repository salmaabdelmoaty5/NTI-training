
#include <avr/io.h>
#include "Std_types.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "SPI.h"

int main(void)
{
	u8 Local_u8ReceivedData = 0;
	SPI_Init();
	DIO_voidSetPinDirection(PORTA, PIN0, OUTPUT);

	while (1)
	{
		
		Local_u8ReceivedData = SPI_GetChar();
		if (Local_u8ReceivedData == '1')
		{
			if (DIO_u8ReadPinValue(PORTA, PIN0) == HIGH)
			{
				DIO_voidSetPinValue(PORTA, PIN0, LOW);
			}
			else
			{
				DIO_voidSetPinValue(PORTA, PIN0, HIGH);
			}
		}
	}

	return 0;
}
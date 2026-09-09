
#include "Std_types.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "UART.h"



int main(void)
{
	u8 Local_u8ReceivedData = 0;
	UART_Init();
	DIO_voidSetPinDirection(PORTA, PIN0, OUTPUT);

	while (1)
	{

		Local_u8ReceivedData = UART_GetChar();
		if (Local_u8ReceivedData == '1')
		{
			if (DIO_u8ReadPinValue(PORTA, 0) == HIGH)
			{
				DIO_voidSetPinValue(PORTA, 0, LOW);
			}
			else
			{
				DIO_voidSetPinValue(PORTA, 0, HIGH);
			}
		}
	}

	return 0;
}
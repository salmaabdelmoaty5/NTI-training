#include "Std_types.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "UART.h"
#include <util/delay.h>



int main(void)
{
	u8 Local_u8ReceivedData = 0;

	UART_Init();

	/* Configure LED 1 (PA0) as output on U1 */
	DIO_voidSetPinDirection(PORTA, PIN0, OUTPUT);

	while (1)
	{
	
		UART_SendChar('1');
		_delay_ms(1000);
	}

	return 0;
}

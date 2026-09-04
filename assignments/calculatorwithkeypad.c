
#include <avr/io.h>
#include "Bit_Math.h"
#include "Std_types.h"
#include "DIO.h"
#include "LCD.H"
#include "keypad.h"
#define F_CPU 8000000UL
#include <util/delay.h>

#include "Std_types.h"
#include "DIO.h"
#include "LCD.H"
#include "keypad.h"
#include <util/delay.h>

int main(void)
{
	LCD_init();
	KEYPAD_init();

	s32 num1 = 0;
	s32 num2 = 0;
	char op = '\0';
	u8 calculating = 0;

	while (1)
	{
		char key = KEYPAD_getPressedKey();

		if (key != '\0')
		{
			if (key == 'C')
			{
				LCD_SendCommand(0b00000001); 
				num1 = 0;
				num2 = 0;
				op = '\0';
				calculating = 0;
			}
			else if (key >= '0' && key <= '9')
			{
				LCD_sendChar(key);
				
				if (calculating == 0)
				{
					num1 = (num1 * 10) + (key - '0');
				}
				else
				{
					num2 = (num2 * 10) + (key - '0');
				}
			}
			else if (key == '+' || key == '-' || key == '*' || key == '/')
			{
				if (calculating == 0)
				{
					op = key;
					calculating = 1;
					LCD_sendChar(op);
				}
			}
			else if (key == '=')
			{
				LCD_sendChar('=');
				s32 result = 0;
				u8 error_flag = 0;

				switch (op)
				{
					case '+': result = num1 + num2; break;
					case '-': result = num1 - num2; break;
					case '*': result = num1 * num2; break;
					case '/':
					if (num2 != 0) {
						result = num1 / num2;
						} else {
						error_flag = 1;
					}
					break;
					default: error_flag = 1; break;
				}

				if (error_flag)
				{
					LCD_SendString("Error");
				}
				else
				{
					LCD_voidWriteNumber(result);
				}
				num1 = result;
				num2 = 0;
				calculating = 0;
				op = '\0';
			}
			
			_delay_ms(150); 
		}
	}

	return 0;
}
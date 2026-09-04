#include "LCD.H"
#include "Std_types.h"
#include <util/delay.h>


	
void LCD_init(void)
{
	DIO_voidSetPinDirection(PORTB, PIN0, OUTPUT);
	DIO_voidSetPinDirection(PORTB, PIN1, OUTPUT);
	DIO_voidSetPinDirection(PORTB, PIN2, OUTPUT);
	DIO_voidSetPortDirection(PORTA, 0B11111111);

	_delay_ms(40);

	LCD_SendCommand(0b00111000);
	_delay_us(39);
	LCD_SendCommand(0b00001100);
	_delay_us(39);

	LCD_SendCommand(0b00000001);
	_delay_ms(2);
}
	
void LCD_SendCommand(u8 command){
	DIO_voidSetPinValue(PORTB,PIN0, LOW);
	DIO_voidSetPinValue(PORTB,PIN1, LOW);
	
	DIO_voidSetPortValue(PORTA, command);
	
    DIO_voidSetPinValue(PORTB, PIN2, HIGH);
    _delay_ms(1);
    DIO_voidSetPinValue(PORTB, PIN2, LOW);
}
void LCD_sendChar(u8 Data){
	DIO_voidSetPinValue(PORTB, PIN0, HIGH); 
	DIO_voidSetPinValue(PORTB, PIN1, LOW);  
	
	DIO_voidSetPortValue(PORTA, Data);      	

	DIO_voidSetPinValue(PORTB, PIN2, HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(PORTB, PIN2, LOW);
}
void LCD_SendString(u8 *str){
	u8 i = 0;
	while (str[i]  != '\0')
	{
		LCD_sendChar(str[i]);
		i++;
	}
}
	
void GoToXY(u8 x, u8 y)
{
	u8 Local_u8Address = 0;
	
	if (y == 0)
	{
		Local_u8Address = x; 
	}
	else if (y == 1)
	{
		Local_u8Address = x + 0x40; 
	}

	LCD_SendCommand(0x80 | Local_u8Address);
}
void LCD_voidWriteNumber(s32 num)
{
	if (num == 0)
	{
		LCD_sendChar('0');
		return;
	}

	u8 digits[10];
	u8 i = 0;

	while (num > 0)
	{
		digits[i] = (num % 10) + '0';
		num /= 10;
		i++;
	}

	// Print digits in correct reverse order
	while (i > 0)
	{
		i--;
		LCD_sendChar(digits[i]);
	}
}

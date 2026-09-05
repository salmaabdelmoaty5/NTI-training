#include "stepper.H"
#include "Std_types.h"
#include <avr/io.h>
#include "DIO.h"
#include <util/delay.h>



void Stepper_voidInit(void)
{
	DIO_voidSetPinDirection(PORTC, PIN0, OUTPUT);
	DIO_voidSetPinDirection(PORTC, PIN1, OUTPUT);
	DIO_voidSetPinDirection(PORTC, PIN2, OUTPUT);
	DIO_voidSetPinDirection(PORTC, PIN3, OUTPUT);
}

void Stepper_voidRotate(u8 Copy_u8Direction, u8 Copy_u8Mode)
{
	if (Copy_u8Mode == FULL_STEP)
	{
		if (Copy_u8Direction == CLOCKWISE)
		{
			DIO_voidSetPinValue(PORTC, PIN0, HIGH);
			DIO_voidSetPinValue(PORTC, PIN1, LOW);
			DIO_voidSetPinValue(PORTC, PIN2, LOW);
			DIO_voidSetPinValue(PORTC, PIN3, LOW);
			_delay_ms(10);
			DIO_voidSetPinValue(PORTC, PIN0, LOW);
			DIO_voidSetPinValue(PORTC, PIN1, HIGH);
			DIO_voidSetPinValue(PORTC, PIN2, LOW);
			DIO_voidSetPinValue(PORTC, PIN3, LOW);
			_delay_ms(10);
			DIO_voidSetPinValue(PORTC, PIN0, LOW);
			DIO_voidSetPinValue(PORTC, PIN1, LOW);
			DIO_voidSetPinValue(PORTC, PIN2, HIGH);
			DIO_voidSetPinValue(PORTC, PIN3, LOW);
			_delay_ms(10);
			DIO_voidSetPinValue(PORTC, PIN0, LOW);
			DIO_voidSetPinValue(PORTC, PIN1, LOW);
			DIO_voidSetPinValue(PORTC, PIN2, LOW);
			DIO_voidSetPinValue(PORTC, PIN3, HIGH);
			_delay_ms(10);
		}
		else if (Copy_u8Direction == COUNTERCLOCKWISE)
		{
			DIO_voidSetPinValue(PORTC, PIN0, LOW);
			DIO_voidSetPinValue(PORTC, PIN1, LOW);
			DIO_voidSetPinValue(PORTC, PIN2, LOW);
			DIO_voidSetPinValue(PORTC, PIN3, HIGH);
			_delay_ms(10);
			DIO_voidSetPinValue(PORTC, PIN0, LOW);
			DIO_voidSetPinValue(PORTC, PIN1, LOW);
			DIO_voidSetPinValue(PORTC, PIN2, HIGH);
			DIO_voidSetPinValue(PORTC, PIN3, LOW);
			_delay_ms(10);
			DIO_voidSetPinValue(PORTC, PIN0, LOW);
			DIO_voidSetPinValue(PORTC, PIN1, HIGH);
			DIO_voidSetPinValue(PORTC, PIN2, LOW);
			DIO_voidSetPinValue(PORTC, PIN3, LOW);
			_delay_ms(10);
			DIO_voidSetPinValue(PORTC, PIN0, HIGH);
			DIO_voidSetPinValue(PORTC, PIN1, LOW);
			DIO_voidSetPinValue(PORTC, PIN2, LOW);
			DIO_voidSetPinValue(PORTC, PIN3, LOW);
			_delay_ms(10);
		}
	}
	else if (Copy_u8Mode == HALF_STEP)
	{
		if (Copy_u8Direction == CLOCKWISE)
		{
	
			DIO_voidSetPinValue(PORTC, PIN3, HIGH);
			 DIO_voidSetPinValue(PORTC, PIN2, LOW); 
			  DIO_voidSetPinValue(PORTC, PIN1, LOW);
			    DIO_voidSetPinValue(PORTC, PIN0, HIGH);
				 _delay_ms(10);
	
			DIO_voidSetPinValue(PORTC, PIN3, LOW); 
			 DIO_voidSetPinValue(PORTC, PIN2, LOW);
			   DIO_voidSetPinValue(PORTC, PIN1, LOW);
			     DIO_voidSetPinValue(PORTC, PIN0, HIGH);
				  _delay_ms(10);
	
			DIO_voidSetPinValue(PORTC, PIN3, LOW); 
			 DIO_voidSetPinValue(PORTC, PIN2, LOW); 
			  DIO_voidSetPinValue(PORTC, PIN1, HIGH); 
			  DIO_voidSetPinValue(PORTC, PIN0, HIGH);
			   _delay_ms(10);
	
			DIO_voidSetPinValue(PORTC, PIN3, LOW); 
			 DIO_voidSetPinValue(PORTC, PIN2, LOW); 
			  DIO_voidSetPinValue(PORTC, PIN1, HIGH);
			   DIO_voidSetPinValue(PORTC, PIN0, LOW);
			     _delay_ms(10);

			DIO_voidSetPinValue(PORTC, PIN3, LOW); 
			 DIO_voidSetPinValue(PORTC, PIN2, HIGH);
			  DIO_voidSetPinValue(PORTC, PIN1, HIGH);
			   DIO_voidSetPinValue(PORTC, PIN0, LOW);
			     _delay_ms(10);

			DIO_voidSetPinValue(PORTC, PIN3, LOW);
			  DIO_voidSetPinValue(PORTC, PIN2, HIGH);
			   DIO_voidSetPinValue(PORTC, PIN1, LOW); 
			    DIO_voidSetPinValue(PORTC, PIN0, LOW);
				  _delay_ms(10);

			DIO_voidSetPinValue(PORTC, PIN3, HIGH);
			 DIO_voidSetPinValue(PORTC, PIN2, HIGH);
			  DIO_voidSetPinValue(PORTC, PIN1, LOW);
			    DIO_voidSetPinValue(PORTC, PIN0, LOW); 
				 _delay_ms(10);

			DIO_voidSetPinValue(PORTC, PIN3, HIGH);
			 DIO_voidSetPinValue(PORTC, PIN2, LOW);
			   DIO_voidSetPinValue(PORTC, PIN1, LOW); 
			    DIO_voidSetPinValue(PORTC, PIN0, LOW);
				  _delay_ms(10);
		}
		else if (Copy_u8Direction == COUNTERCLOCKWISE)
		{
			
			
			DIO_voidSetPinValue(PORTC, PIN3, HIGH);
			 DIO_voidSetPinValue(PORTC, PIN2, LOW);
			   DIO_voidSetPinValue(PORTC, PIN1, LOW);
			     DIO_voidSetPinValue(PORTC, PIN0, LOW);
				   _delay_ms(10);
		
			DIO_voidSetPinValue(PORTC, PIN3, HIGH);
			 DIO_voidSetPinValue(PORTC, PIN2, HIGH);
			  DIO_voidSetPinValue(PORTC, PIN1, LOW);
			    DIO_voidSetPinValue(PORTC, PIN0, LOW);
				  _delay_ms(10);
		
			DIO_voidSetPinValue(PORTC, PIN3, LOW);
			  DIO_voidSetPinValue(PORTC, PIN2, HIGH);
			   DIO_voidSetPinValue(PORTC, PIN1, LOW); 
			    DIO_voidSetPinValue(PORTC, PIN0, LOW);
				  _delay_ms(10);

			DIO_voidSetPinValue(PORTC, PIN3, LOW); 
			 DIO_voidSetPinValue(PORTC, PIN2, HIGH);
			  DIO_voidSetPinValue(PORTC, PIN1, HIGH);
			   DIO_voidSetPinValue(PORTC, PIN0, LOW);
			     _delay_ms(10);


			DIO_voidSetPinValue(PORTC, PIN3, LOW);
			  DIO_voidSetPinValue(PORTC, PIN2, LOW);
			    DIO_voidSetPinValue(PORTC, PIN1, HIGH);
				 DIO_voidSetPinValue(PORTC, PIN0, LOW); 
				  _delay_ms(10);
		
			DIO_voidSetPinValue(PORTC, PIN3, LOW);
			  DIO_voidSetPinValue(PORTC, PIN2, LOW);
			    DIO_voidSetPinValue(PORTC, PIN1, HIGH); 
				DIO_voidSetPinValue(PORTC, PIN0, HIGH);
				 _delay_ms(10);
		
			DIO_voidSetPinValue(PORTC, PIN3, LOW);
			  DIO_voidSetPinValue(PORTC, PIN2, LOW); 
			   DIO_voidSetPinValue(PORTC, PIN1, LOW); 
			    DIO_voidSetPinValue(PORTC, PIN0, HIGH);
				 _delay_ms(10);
		
			DIO_voidSetPinValue(PORTC, PIN3, HIGH);
			 DIO_voidSetPinValue(PORTC, PIN2, LOW);
			   DIO_voidSetPinValue(PORTC, PIN1, LOW); 
			    DIO_voidSetPinValue(PORTC, PIN0, HIGH);
				 _delay_ms(10);
		}
	}
}
#include "Std_types.h"
#include "Bit_Math.h"
#include "ADC.h"

void ADC_Init(void)
{
	//This is AVCC m3 external capacitor (100nF) (REFERENCE SELECTION BITS)
	CLR_BIT(ADMUX_Reg, PIN7);
	SET_BIT(ADMUX_Reg, PIN6); 
	// Default to Right Adjust Result (ADLAR = 0)
	CLR_BIT(ADMUX_Reg, PIN5);
	//PRESCALER DIV (el howa division factor = 128)
	SET_BIT(ADCSRA_Reg, PIN2);
	SET_BIT(ADCSRA_Reg, PIN1); 
	SET_BIT(ADCSRA_Reg, PIN0); 
	//enabling el adc
	SET_BIT(ADCSRA_Reg, PIN7);
}

u16 ADC_Read(u8 Copy_u8Channel)
{
	ADMUX_Reg &= 0b11100000;
	ADMUX_Reg |= (Copy_u8Channel & 0b00011111);
	SET_BIT(ADCSRA_Reg, PIN6); // el start conversion bit
	while (GET_BIT(ADCSRA_Reg, PIN4) == 0); //polling the flag
	SET_BIT(ADCSRA_Reg, PIN4);
	u16 Local_u16Result = ADCL_Reg; //read el lowdata
	Local_u16Result |= ((u16)ADCH_Reg << 8); // read el high data b3den bshift b 8 b3den bahotha 3la el lowdata

	return Local_u16Result;
}
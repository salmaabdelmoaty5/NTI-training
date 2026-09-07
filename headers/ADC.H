#ifndef ADC_H_
#define ADC_H_

#include "Std_types.h"
#include <avr/io.h>
#include "Bit_Math.h"
#include "DIO.h"

#define ADMUX_Reg   *((volatile u8*)0x27)   // ADC Multiplexer Register
#define ADCSRA_Reg  *((volatile u8*)0x26)   // ADC Control And Status Register
#define ADCH_Reg    *((volatile u8*)0x25)   // ADC High Register
#define ADCL_Reg    *((volatile u8*)0x24)   // ADC Low Register

void ADC_Init(void);                      // ADC Initialization And Enable
u16 ADC_Read(u8 Copy_u8Channel);          // Read From The ADC Channel

#endif /* ADC_H_ */


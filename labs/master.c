#include <avr/io.h>
#include "Std_types.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "SPI.h"
#include <util/delay.h>

int main(void){
	SPI_Init();
	while (1){
		SPI_Transceive('1');
		_delay_ms(1000);
	}

	return 0;
}
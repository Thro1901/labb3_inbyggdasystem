#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>
#include <util/delay.h>

#include "led.h"
#include "serial.h"
#include "timer.h"
#include "button.h"
#include "adc.h"

volatile int adc_val;
ISR(ADC_vect) { //Interrupt Service Routine
	adc_val = ADC_read();  //ADCL

}
ISR(TIMER2_COMPA_vect) {  // timer2 Interrupt Service Routine
	ADCSRA |= (1 << ADSC);
	OCR0A = adc_val;
}

int main(void) {
	cli();  //clears the global interrupt
	
	LED_init();
	uart_init();
	timer_init();
	button_init();
	ADC_init();

	sei(); // Global enable interrupt
	
	while (1) {}

	return 0;
}



#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>

volatile int adc_val;
int button_pressed_count = 0;

volatile int DoFunctions = 0;


#include "enum.h"
#include "led.h"
#include "serial.h"
#include "timer.h"
#include "button.h"
#include "adc.h"
#include "statehandler.h"
#include "stateexecuter.h"


ISR(ADC_vect) { //Interrupt Service Routine
	adc_val = ADC_read();  // Save ADC value to adc_val

}
ISR(TIMER2_COMPA_vect) {  // timer2 Interrupt Service Routine
	button_pressed(&button_pressed_count);
	DoFunctions = 1;
}

int main(void) {
	cli();  //clears the global interrupt

	LED_init();
	uart_init();
	timer_init();
	button_init();
	ADC_init();

	sei(); // Global enable interrupt

	while (1) {
		if (DoFunctions == 1) {
		stateHandler(&button_pressed_count); // send in button_pressed_count to set STATE
		ExecuteState(adc_val); // execute STATE
		DoFunctions = 0;
		}
	}

	return 0;
}



#include <avr/pgmspace.h>
#include <stdio.h>

#include "button.h"

char Pressed[] = { "pushed\r\n" };
char NotPressed[] = { "released\r\n" };

uint8_t buttonstate = 0;
uint8_t lastbuttonstate = 0;

void button_init() {
	DDRD &= ~(1 << PD2); // PD2 input

}

void button_pressed() {
	if (PIND & (1 << PD2)) { // if PIN2D is high 
		buttonstate = 1;
	}
	else if (!(PIND & (1 << PD2))) {  // if PIN2D is low 
		buttonstate = 0;
	}

	if (buttonstate == 1 && lastbuttonstate == 0) {  
		printf_P(PSTR("%s"), Pressed);
	}
	else if (buttonstate == 0 && lastbuttonstate == 1) {
		printf_P(PSTR("%s"), NotPressed);
	}
	lastbuttonstate = buttonstate;  // Save buttonstate to lastbuttonstate
}


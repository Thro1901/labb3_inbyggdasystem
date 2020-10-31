#include <avr/io.h>
#include <stdbool.h> 
#include <avr/pgmspace.h>
#include "led.h"

int count = 0;
int slowdown;

static bool Increasing = true;
static uint8_t Brightness = 0;

void LED_init() {
    DDRD |= (1 << PD6); //PORTD To output pwn pin 6
}

uint8_t simple_ramp() {
    slowdown++;
    if (slowdown == 100) {
        if (Brightness == 255) {
            Increasing = false;
        }
        else if (Brightness == 0) {
            Increasing = true;
        }
    
        if (Increasing == true) {
            Brightness++;
        }
        else if (Increasing == false) {
            Brightness--;
        }
        slowdown = 0;
    }

    return Brightness;
}

void TOGGLE_led() {
   count++;

   if (count == 8000) {
   PORTD ^= (1 << PD6);
   count = 0;
   }

}

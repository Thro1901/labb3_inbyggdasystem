#include <avr/io.h>
#include <stdbool.h> 
#include "led.h"

static bool Increasing = true;
static uint8_t Brightness = 0;
static uint8_t Period = 255;  // max brightness

void LED_init() {
    
}

uint8_t simple_ramp() {

    if (Brightness <= Period && Increasing == true) {
        Brightness++;
    }
    else if (Brightness <= Period && Increasing == false) {
        Brightness--;
    }

    if (Brightness == 255) {
        Increasing = false;
    }
    else if (Brightness == 0) {
        Increasing = true;
    }

    return Brightness;
}

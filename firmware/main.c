/* Name: main.c
 * Projekt: neopixel_example
 * Author: Thorsten Kattanek
 * Geändert am: 09.11.2020
 * Copyright: Thorsten Kattanek
 * License: GNU GPL v2 (see License.txt), GNU GPL v3 or proprietary (CommercialLicense.txt)
 *
 */

#define F_CPU   8000000UL
    
#include <avr/io.h>
#include <avr/wdt.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/pgmspace.h>   /* benötigt von usbdrv.h */

// PinOut
// PB4 - LED_DATA

int main(void)
{
    DDRB |= 1 << PIN4;
    
    while(1)
    {
        PORTB |= 1 << PIN4;
        _delay_us(1);
        PORTB &= ~(1 << PIN4);
        _delay_us(1);
    }
}

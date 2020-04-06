/*	Author: lab
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
    /* Insert your solution below */
	unsigned char cnt;
	unsigned char i;
	unsigned char tempA = 0x00;
    while (1) {
	cnt = 0x00;
	tempA = PINA & 0x0F;
	for(i = 0; i < 4; ++i) {
		if(!(PINA & (0x01 << i))) {
			cnt++;
		}
	}
	if(cnt == 0x00) {
		cnt = 0x80;
	}
	PORTC = cnt;
    }
    return 1;
}

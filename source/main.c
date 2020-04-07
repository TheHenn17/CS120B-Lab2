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
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0x00; PORTC = 0xFF;
	DDRD = 0xFF; PORTD = 0x00;
    /* Insert your solution below */
	unsigned char tempA;
	unsigned char tempB;
	unsigned char tempC;
	unsigned char tempD;
	unsigned short weight;
	signed short diff;
    while (1) {
	tempA = PINA;
	tempB = PINB;
	tempC = PINC;
	tempD = 0x00;
	weight = tempA + tempB + tempC;
	if(weight > 140) {
		tempD = tempD | 0x01;
	}
	diff = tempA - tempC;
	if((diff > 80) || (diff < -80)) {
		tempD = tempD | 0x02;
	}
	weight = weight >> 4;
	weight = weight << 2;
	tempD = weight | tempD;
	PORTD = tempD;
    }
    return 1;
}

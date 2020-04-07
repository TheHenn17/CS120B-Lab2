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
	//checks weight to see if it exceeds maximum
	if(weight > 140) {
		tempD = tempD | 0x01;
	}
	diff = tempA - tempC;
	//checks diff to see if it is 80 or more
	if((diff > 80) || (diff < -80)) {
		tempD = tempD | 0x02;
	}
	//PD2 lights up if the total weight is under 150 kg
	if(weight <= 150) {
		tempD = tempD | 0x04;
	}
	//PD3 lights up if the total weight is between 300-151
	else if ((weight <= 300) && (weight > 150)) {
		tempD = tempD | 0x08;
	}
	//PD4 lights up if the total weight is between 450-301
	else if ((weight <= 450) && (weight > 300)) {
                tempD = tempD | 0x10;
        }
	//PD5 lights up if the total weight is between 600-451
	else if ((weight <= 600) && (weight > 450)) {
                tempD = tempD | 0x20;
        }
	//PD6 lights up if the total weight is between 750-601
	else if ((weight <= 750) && (weight > 600)) {
                tempD = tempD | 0x40;
        }
	//PD7 lights up if the total weight is above 751 kg
	else  {
		tempD = tempD | 0x80;
	}
	PORTD = tempD;
    }
    return 1;
}

/*	Author: achau020
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
	DDRB = 0xFF; PORTB = 0x00;
	unsigned char tmpA = 0x00;
	unsigned char state = 0x01; //button starts at 1
    /* Insert your solution below */
    while (1) {
	//tmpB = 0x01;
	tmpA = PINA & 0x01;
	if((tmpA == 0x01) && (state == 0x01)) { //if button B0 is one then B0 = 2
		state = 0x02;	
	} else if((tmpA == 0x01) && (state == 0x02)){ //if button B0 = 2 then B0 = 1
		state = 0x01;
	} else{}
	PORTB = state;

    }
    return 1;
}

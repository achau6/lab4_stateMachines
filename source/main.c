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
#include <stdbool.h>
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	unsigned char tmpA = 0x00;
	unsigned char tmpC = 0x08;
	bool hold1 = false;
	bool hold2 = false;
	bool reset = false;
    /* Insert your solution below */
    while (1) {
	tmpA = PINA;
	// x = 00, y = 0x01, # = 0x02
	if(tmpA == 0x04 && reset == false){ //need false to press once and release
		tmpC = 0x03; //rendom assign value
		hold1 = true;
		reset = true;
	}else if(tmpA == 0x02 && reset == false){
		tmpC = 0x04;
		hold2 = true;
		reset = true;
	} else if(tmpA == 0x01){
		tmpC = 0x05;
		reset = true;
		hold1 = false; //press any other button then combo is ruined
		hold2 = false;
	} else if(tmpA == 0x00){//reset
		reset = false;
	} else if(tmpA = 0x07){ //combo is gone
		tmpC = 0x00;
		reset = true;
		hold1 = false;
                hold2 = false;
		reset = false;
	}else {
		tmpC = 0x08; //reset value
	}

	if(hold1 == true && hold2 == true){
		tmpC = 0x01;
		hold1 = false;
                hold2 = false;
		reset = false;
	}
	PORTC = tmpC;

    }
    return 1;
}

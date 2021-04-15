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
	//unsigned char state = 0x01; //button starts at 1
	bool hold1 = false;
	bool hold2 = false;
	int value = 7;
    /* Insert your solution below */
    while (1) {
	tmpA = PINA;
	if((tmpA == 0x01) && (value < 9) && (hold1 == false))
	{ 
		value ++;
		hold1 = true;	
	} else if((tmpA == 0x02) && (value != 0) && (hold2 == false))
	{ 
	 	value --;
		hold2 = true;
	} else if(tmpA == 0x00){
		hold1 = false;
		hold2 = false;
	}

	if(hold1 == true && hold2 == true){ //if 1 and 2 are pressed at 2 different times
		value = 0x00;
		hold1 = false;
		hold2 = false;
	}
	if(tmpA == 0x03){ //if 1 and 2 are press go to 0
		value = 0x00;
		hold1 = false;
		hold2 = false;
	}
	PORTC = value;

    }
    return 1;
}

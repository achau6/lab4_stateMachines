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


enum SM1_STATES { SM1_SMStart, Init, SM_Pound, SM_Y, SM_Lock, SM_Unlock } SM_STATE;
bool lock;

void Tick_Door() {
	//PORTB = 0x00;
	bool reset;
	//bool lock = false;
	switch(SM_STATE) {
		case SM1_SMStart:
			//PORTB = 0x00;
			SM_STATE = Init;
		break;
		case Init:
			if(PINA == 0x04){
                                SM_STATE = SM_Pound;
                        //} else if(A == 0x02){
                        //         SM_STATE = SM_Y;
                        //} else if(A == 0x01){
                        //        SM_STATE = SM_X;
                        } else if(PINA == 0x80){
                                SM_STATE = SM_Lock;
                        } else { 
				SM_STATE = Init; 
			}
		break;
		case SM_Pound:
			if(PINA == 0x04){
				SM_STATE = SM_Pound;
			} else if(PINA == 0x02) {
				//PORTB = 0x00;
				reset = true;
			} else{ 
				SM_STATE = SM_Y;
			}
		break;
		case SM_Y:
			if(PINA == 0x02){
				if(reset == false) {
					SM_STATE = SM_Unlock;
				} else {
					PORTB = 0x00;
					//SM_STATE = SM_Lock;	
				}
			} else if(PINA == 0x00) {
				SM_STATE = SM_Y;
			} else {	
				SM_STATE = Init;
			}
		break;
		//case SM_X:
			//SM_STATE = SM_Lock;
		//break;
		case SM_Lock:
			if(PINA == 0x80){
				SM_STATE = SM_Lock;
			} else { SM_STATE = Init; }

		break;
		case SM_Unlock:
			if(PINA == 0x02){
                                SM_STATE = SM_Unlock;
				
                        } else {
                                SM_STATE = Init;
                        }
		break;
		
		//default:
		//	SM_STATE = SM1_SMStart;
		//break;
	}

	switch(SM_STATE){
		case SM1_SMStart:
			PORTB = 0x00;
		break;
		case SM_Lock:
			PORTB = 0x00;
		break;
		case Init:
			//PORTB = 0x00;
		break;
		case SM_Y:
			//PORTB = 0x00;
		break;
		//case SM_X:
		//break;
		case SM_Unlock:
			if(lock == true){
				lock = false;
				PORTB = 0x01;
				
			} else {
				lock = true;
				PORTB = 0x00;
				//SM_STATE = SM_Lock;
			}
		break;
		case SM_Pound:
			//PORTB = 0x00;
		break;
	
	}

}
int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	//unsigned char tmpA = 0x00;
	//unsigned char tmpC = 0x00;
	//B = 0;
	SM_STATE = SM1_SMStart;
    /* Insert your solution below */
	//PORTB = 0x00;
    while (1) {
	//tmpA = PINA;
	//can ignore X since we dont need it for success
	Tick_Door();

    }
    return 1;
}

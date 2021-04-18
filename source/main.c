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


enum SM1_STATES { SM1_SMStart, Init, SM_Pound, SM_Y, SM_X, SM_Lock, SM_Unlock } SM_STATE;

void Tick_Door() {
	switch(SM_STATE) {
		case SM1_SMStart:
			SM_STATE = Init;
		break;
		case Init:
			if(PINA == 0x04){
                                SM_STATE = SM_Pound;
                        //} else if(A == 0x02){
                        //         SM_STATE = SM_Y;
                        //} else if(A == 0x01){
                        //        SM_STATE = SM_X;
                        } else if(PINA == 0x07){
                                SM_STATE = SM_Lock;
                        } else { SM_STATE = Init; }
		break;
		case SM_Pound:
			if(PINA == 0x04){
				SM_STATE = SM_Pound;
			} else { 
				SM_STATE = SM_Y;
			}
		break;
		case SM_Y:
			if(PINA == 0x02){
				SM_STATE = SM_Unlock;
			} else if(PINA == 0x00) {
				SM_STATE = SM_Y;
			} else {	
				SM_STATE = Init;
			}
		break;
		case SM_X:
			SM_STATE = SM_Lock;
		break;
		case SM_Lock:
			if(PINA == 0x07){
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
		
		default:
			SM_STATE = SM1_SMStart;
		break;
	}

	switch(SM_STATE){
		case SM1_SMStart:
			PORTB = 0x00;
		break;
		case SM_Lock:
			PORTB = 0x00;
		break;
		case Init:
		break;
		case SM_Y:
		break;
		case SM_X:
		break;
		case SM_Unlock:
			PORTB = 0x01;
		break;
		case SM_Pound:
		break;
	
	}

}
int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	//unsigned char tmpA = 0x00;
	//unsigned char tmpC = 0x00;
	//bool hold1 = false;
	//bool hold2 = false;
	//bool reset = false;
	//B = 0;
	//SM_STATE = SM1_SMStart;
    /* Insert your solution below */
    while (1) {
	//tmpA = PINA;
	//can ignore X since we dont need it for success
	Tick_Door();
	//hold1 = false;
	//hold2 = false;
	//reset = false;
	// x = 00, y = 0x01, # = 0x02
	/*if(tmpA == 0x04 && reset == false){ //need false to press once and release
		tmpC = 0x00; //rendom assign value
		//if(reset == false){
                        hold1 = true;
                        reset = true;
                //} else if(reset == true){
                        //hold2 = false;
                  //      reset = false;
                //}
		//hold1 = true;
		//reset = true;
	} else if(tmpA == 0x02 && reset == false){
		tmpC = 0x00;
		//if(reset == false){
			hold2 = true;
                	reset = true;
		//} else if(reset == true){
			//hold2 = false;
		//	reset = false;
		//}
		//hold2 = true;
		//reset = true;
	} else if(tmpA == 0x01){
		//tmpC = 0x05;
		reset = true;
		hold1 = false; //press any other button then combo is ruined
		hold2 = false;
	} else if(tmpA == 0x00){//reset
		//tmpC = 0x00;
		reset = false;
	} else if(tmpA = 0x07){ //combo is gone
		tmpC = 0x00;
		reset = false;
		hold1 = false;
                hold2 = false;
		//reset = false;
	}else {
		tmpC = 0x00; //reset value
	}

	if(hold1 == true && hold2 == true){
		tmpC = 0x01;
		hold1 = false;
                hold2 = false;
		reset = false;
	}*/
	//PORTB = tmpC;

    }
    return 1;
}

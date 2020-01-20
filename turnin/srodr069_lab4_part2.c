/*	Author: stevenrodriguez
 *  Partner(s) Name: Anthony Pham
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

unsigned char C = 0x07; // count is initialized to 7

enum States {start, init, increment, decrement, zero} State;
#define A (PINA & 0x03)

void tickButton() {
	//unsigned char A = PINA & 0x03; //set A to pins A1 A0
    switch(State) { //transitions
		case start:
			C = 0x07;          // start of SM
	    	State = init; // first state, PB0 is ON
	    	break;
		case init:
			if (A == 0x01) { //goes to increment if A0 pressed
				State = increment;
			}

			else if (A == 0x02) {  // goes to decrement if A1 pressed
				State = decrement;
			}

			else if (A == 0x03) { // sets C to 0 when both buttons are pressed
				State = zero;
			}

			else {
				State = init;
			}
			break; 

		case increment: //using init as a wait state
	    /*if (A == 0x01 && C < 9) {      // if button pressed, go to state2
			State = increment;
	    }
	    if (A == 0x02){
	    	State = decrement;
	    }

	    if (A == 0x03){
	    	State == zero;
	    }

	    if (A == 0x01 && C == 9){
	    	State == stop;
	    }*/

		    State = init;	
		    
	    	break;
		
		case decrement: //using init as a wait state
	    /*if (A == 0x02 && C > 0) {      // if button pressed, go to state2
			State = decrement;
	    }
	    if (A == 0x01){
	    	State = increment;
	    }

	    if (A == 0x03){
	    	State = zero;
	    }

	    if (A == 0x02 && C == 0){
	    	State = stop;
	    } */

			State = init;
	   		break;

		case zero: //using init as a wait state
		/*if (A == 0x03){
			State = zero;
		}

		else if (A == 0x01){
			State = increment;
		}
		else {
			State = zero;
		} */
			State = init;
			break;
		default:
			State = start;
	}
    
    switch(State) { //state actions
		case start:
		//C = 0x07;
	    	break;
		case init:
			break;
		case increment:
			if (C < 0x09){
				C = C + 1;
			}

			else {
				C = 0x09;
			}
	    	break;
		case decrement:
			if (C > 0){
				C = C - 1;
			}
			else {
				C = 0x00;
			}
	    	break;    
		case zero:
			C = 0x00;
			break;
		default:
			break;
    }    


}

int main(void) {
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	
	//C = 0x07;
	State = start;   // initial call
	
	while(1) {
		tickButton();	
		PORTC = C;
	}
    
    return 1;
}

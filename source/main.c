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

unsigned char SetBit(unsigned char x, unsigned char k, unsigned char b) {
   return (b ?  (x | (0x01 << k))  :  (x & ~(0x01 << k)) );
              //   Set bit to 1           Set bit to 0
}

unsigned char GetBit(unsigned char x, unsigned char k) {
   return ((x & (0x01 << k)) != 0);
}

unsigned char B = 0x01;         //B0 is initially on (LED)
//unsigned char A0 = PINA; //reads input A0 (button)
//#define A0 (PINA & 0x01)

enum States { Start, state1, state2} State;

void tickButton() {
	unsigned char A0 = PINA & 0x01;
    switch(State) {
	case Start:         // start of SM
	    State = state1; // first state, PB0 is ON
	    break;
	case state1:
	    if (A0) {      // if button pressed, go to state2
		State = state2;
	    }	
	    else {         // if no button pressed, stay at state1
		State = state1;
	    }
	    break;
	case state2:
	    if (A0) {
		State = state1;
	    } 
	    else {
		State = state2;
	    }
	    break;
	default:
	    State = Start;
	    break;
    }
    
    switch(State) {
	case Start:
	    //B = 0x01;
	    break;
	case state1:
	    //B = SetBit(B, 0, 1);
	    //B = SetBit(B, 1, 0);
		B = 0x01;
	    break;
	case state2: // WHY CANT WE LEAVE STATE2222222
	    //B = SetBit(B, 0, 0);
        //B = SetBit(B, 1, 1);
		B = 0x02;
	    break;    
    }    

}

int main(void) {
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	
	
	State = Start;   // initial call
	
    while(1) {
	tickButton();	
	PORTB = B;
       B = 0x01;
	}
    
    return 1;
}

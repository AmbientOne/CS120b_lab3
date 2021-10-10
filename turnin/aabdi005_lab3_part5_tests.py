/*	Author: aabdi005
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
    //DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFE; PORTB = 0x01;
    DDRD= 0xFF; PORTD = 0x00;

    //unsigned char tmpA = 0x00;
    unsigned char tmpB = 0x00;
    unsigned char tmpD = 0x00;
    unsigned short totalWeight = 0;

    /* Insert your solution below */
    while(1){
        tmpB = PINB;
        tmpD = PIND;
        
	totalWeight = (tmpD << 1) + (tmpB & 0x01);
	PORTB = 0x0;
        if( totalWeight >= 70) PORTB = 0x02;
	if( totalWeight > 5 && totalWeight < 70) PORTB = 0x04;       
}
    return 1;
}

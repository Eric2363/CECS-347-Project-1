/*
Name: Eric Santana
ID: 015107467
ORG: CSULB
Class: CECS 347
--------------------------
Description: Enable the general purpose timer 1A to produce a 10us delay.
Timer 1A Config: 16bit mode, One shot, down counter
*/

#include "timer1.h"

void Timer1A_Init(void){
	
	//Timer 1 Setup
	//===========================================================================
  SYSCTL_RCGCTIMER_R |= TIMER1;      	// Activate TIMER1
  TIMER1_CTL_R = DISABLE;       			// Disable TIMER1 A & B during setup
	
	// Timer A Setup
	//===========================================================================
  TIMER1_CFG_R = MODE_16bit;          // Configure for 16-bit mode
  TIMER1_TAMR_R = ONE_SHOT_MODE;      // One shot mode, down-counter
  TIMER1_TAILR_R = MAX_RELOAD;        // Reload value (16-bit max)
  TIMER1_TAPR_R = PRESCALE;           // prescale = 0. Withing resoultion of 16 bits.
	//===========================================================================
	
	// Timer B Setup
	//===========================================================================
	
	
}



void delay(){
	
	  TIMER1_TAILR_R = 159;                    // 160 - 1 cycles = 10us @16MHz
    TIMER1_ICR_R = TIMER_ICR_TATOCINT;       // Clear timeout flag
    TIMER1_CTL_R |= TIMER_CTL_TAEN;          // Start timer

    while((TIMER1_RIS_R & TIMER_RIS_TATORIS) == 0); // Wait
    TIMER1_ICR_R = TIMER_ICR_TATOCINT;       // Clear flag
	
}





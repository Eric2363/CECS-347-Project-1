/*
Name: Eric Santana
ID: 015107467
ORG: CSULB
Class: CECS 347 Embedded Systems II
--------------------------
Description: Enable the general purpose timer 1
Timer 1A: 16-bit periodic, 10 µs delay
Timer 1B: 16-bit periodic, stopwatch for echo pulse
*/

#include "timer1.h"

// Timer1 Setup
//===========================================================================
void Timer1_Init(){
    SYSCTL_RCGCTIMER_R |= TIMER1;       // Activate TIMER1
    TIMER1_CFG_R = MODE_16bit;          // Configure for 16-bit mode
    Timer1A_Init();
    Timer1B_Init();
}

// Timer A Setup (10 µs delay)
//===========================================================================
void Timer1A_Init(){
    TIMER1_CTL_R &= ~TIMER1A_MASK;      // Disable Timer1A during setup
    TIMER1_TAMR_R = PERIODIC;           // Periodic mode, down counter
    TIMER1_TAILR_R = A_RELOAD_VALUE;    // Reload value 159 for 10 µs
    TIMER1_TAPR_R = A_PRESCALE;         // Prescale = 0
}

void delayA(void){
    TIMER1_TAILR_R = A_RELOAD_VALUE;
    TIMER1_ICR_R   = TIMER_ICR_TATOCINT; // Clear timeout flag
    TIMER1_CTL_R  |= TIMER_CTL_TAEN;     // Start timer

    while((TIMER1_RIS_R & TIMER_RIS_TATORIS) == 0); // Wait
    TIMER1_ICR_R   = TIMER_ICR_TATOCINT; // Clear flag
}

// Timer B Setup (stopwatch)
//===========================================================================
void Timer1B_Init(){
    TIMER1_CTL_R &= ~TIMER1B_MASK;           // Disable Timer1B
    TIMER1_TBMR_R = 0;                       // Clear mode bits
    TIMER1_TBMR_R |= TIMER_TBMR_TBMR_PERIOD; // Periodic mode
    TIMER1_TBILR_R = B_RELOAD_VALUE;         // Reload value (e.g. 18175)
    TIMER1_TBPR_R  = B_PRESCALE;             // Prescale (e.g. 9)
    TIMER1_ICR_R   = TIMER_ICR_TBTOCINT;     // Clear timeout
}

// Start Timer1B
void StartTimerB(void){
    TIMER1_ICR_R  = TIMER_ICR_TBTOCINT;      // Clear timeout flag
    TIMER1_CTL_R |= TIMER_CTL_TBEN;          // Start Timer1B
}

// Stop Timer1B
void StopTimerB(void){
    TIMER1_CTL_R &= ~TIMER_CTL_TBEN;         // Stop Timer1B
}

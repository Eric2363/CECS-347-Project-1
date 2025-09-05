/*
Name: Eric Santana
ID: 015107467
ORG: CSULB
Class: CECS 347
--------------------------
Description: Enable the general purpose timer 1A to produce a 0.25s delay 
using a interupt in 16 bit mode.
*/

#include "timer1.h"

void Timer1A_Init(void){
  SYSCTL_RCGCTIMER_R |= TIMER1;      	// Activate TIMER1
  TIMER1_CTL_R = DISABLE;       			// Disable TIMER1A during setup
  TIMER1_CFG_R = MODE_16bit;          // Configure for 16-bit mode
  TIMER1_TAMR_R = PERIODIC_MODE;      // Periodic mode, down-counter
  TIMER1_TAILR_R = MAX_RELOAD;        // Reload value (16-bit max)
  TIMER1_TAPR_R = PRESCALE;           // Prescale for ~0.25s at 16 MHz
  TIMER1_ICR_R = CLEAR_TIMEOUT_FLAG;  // Clear timeout flag
  TIMER1_IMR_R = ARM_TIMEOUT_INTERUPT;// Arm timeout interrupt
  NVIC_PRI5_R = (NVIC_PRI5_R&0xFFFF1FFF)|0x00000000; // Priority 0
  NVIC_EN0_R = 1<<IRQ;              // Enable IRQ 21 in NVIC
  TIMER1_CTL_R = ENABLE_TIMER1;     // Enable TIMER1A
}





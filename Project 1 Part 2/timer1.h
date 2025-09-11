/*
Name: Eric Santana
ID: 015107467
ORG: CSULB
Class: CECS 347
--------------------------
Description: Enable the general purpose timer 1A to produce a 10us delay.
Timer 1A Config: 16bit mode, One shot, down counter
*/

#include "tm4c123gh6pm.h"

#define TIMER1 0x02
#define DISABLE 0x00000000
#define MODE_16bit 0x00000004



// Timer A : 10us delay
//====================================================

#define MAX_RELOAD 159
#define PRESCALE 0
#define CLEAR_TIMEOUT_FLAG 0x00000001
#define ONE_SHOT_MODE 0x00000002 // one shot mode

// Timer B : Max count time of 38ms
//====================================================



//#define ARM_TIMEOUT_INTERUPT 0x00000001
//#define IRQ 21
//#define ENABLE_TIMER1 0x00000001

void Timer1A_Init(void);
void delay();


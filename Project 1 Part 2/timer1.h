/*
Name: Eric Santana
ID: 015107467
ORG: CSULB
Class: CECS 347 Embedded Systems II
--------------------------
Description: Enable the general purpose timer 1A to produce a 10us delay.
Timer 1A Config: 16bit mode, One shot, down counter
*/

#include "tm4c123gh6pm.h"
#include <stdint.h>

//Timer1 Setup: Shared config for A & B Timers
//====================================================
#define TIMER1 0x02
#define MODE_16bit 0x00000004
#define PERIODIC 0x00000002 // Periodic mode


// Timer A : 10us delay
//====================================================
#define TIMER1A_MASK 0x00000001
#define A_RELOAD_VALUE 159
#define A_PRESCALE 0
#define CLEAR_TIMEOUT_FLAG 0x00000001


// Timer B : Max count time of 38ms
//====================================================

#define TIMER1B_MASK 0x00000100
#define B_RELOAD_VALUE 18176 // 38ms
#define B_PRESCALE 9

//#define ARM_TIMEOUT_INTERUPT 0x00000001
//#define IRQ 21
//#define ENABLE_TIMER1 0x00000001

void Timer1_Init();
void Timer1A_Init();
void Timer1B_Init();
void delayA();
void StartTimerB();
void StopTimerB();
uint32_t Timer1B_GetElapsed(void);

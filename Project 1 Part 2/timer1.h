/*
Name: Eric Santana
ID: 015107467
ORG: CSULB
Class: CECS 347
--------------------------
Description: Enable the general purpose timer 1 to produce a 0.25s delay 
using a interupt in 16 bit mode.
*/

#include "tm4c123gh6pm.h"

#define TIMER1 0x02
#define DISABLE 0x00000000
#define MODE_16bit 0x00000004
#define PERIODIC_MODE 0x00000002
#define MAX_RELOAD 0xFFFF
#define PRESCALE 60
#define CLEAR_TIMEOUT_FLAG 0x00000001
#define ARM_TIMEOUT_INTERUPT 0x00000001
#define IRQ 21
#define ENABLE_TIMER1 0x00000001

void Timer1A_Init(void);
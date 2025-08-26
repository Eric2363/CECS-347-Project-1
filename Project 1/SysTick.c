/*
Name: Eric Santana
ID: 015107467
ORG: CSULB
Class: CECS 347
--------------------------
Description: Sytick timer is configured to generate 0.5s delay*/

#include "tm4c123gh6pm.h"
#include <stdint.h>
#include "SysTick.h"


void SysTick_Init(){

	NVIC_ST_CTRL_R = CLEAR_REG;	//Disable SysTick.
	NVIC_ST_RELOAD_R = HALF_SEC - 1;	// Load HALF_SEC .
	NVIC_ST_CURRENT_R = CLEAR_REG;	// Clear current value.
	

}

void Delay(){
	
	NVIC_ST_CTRL_R = EN_SYSTICK;	// Enable SRC Clock and turn on timer.
	
	while((NVIC_ST_CTRL_R & 0x00010000)==0){} // wait for counter flag.
		
	
	
}
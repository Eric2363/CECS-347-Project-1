/*
Name: Eric Santana
ID: 015107467
ORG: CSULB
Class: CECS 347
--------------------------
Description: Enable the use of the red LED on port F*/

#include "PortF.h"

void PortF_Init(void){
	
	// Port F Clk Setup
	//------------------------------
	SYSCTL_RCGCGPIO_R |= 0x20;
	
	while((SYSCTL_RCGCGPIO_R)== 0){}//wait for Port F clk to startup
	
		
	// GPIO SETUP
	//------------------------------
	GPIO_PORTF_LOCK_R |= PORTF_UNLOCK_CODE; // Unlock port F.
	GPIO_PORTF_CR_R |= PORTF_CR_CODE;	// Enable changes to port F.
	GPIO_PORTF_DIR_R |= RED_LED_MASK; // Set F1 as output.
	GPIO_PORTF_AFSEL_R &=~RED_LED_MASK;// Disable Alternate Function
	GPIO_PORTF_DEN_R |= RED_LED_MASK;	// Enable F1 pin
	GPIO_PORTF_AMSEL_R &=~RED_LED_MASK;	// Disable Analog Mode
	GPIO_PORTF_PCTL_R |= PORTF_PCTL_CODE;	// Enable F1 pctl
		
		
		
		
		
		
}
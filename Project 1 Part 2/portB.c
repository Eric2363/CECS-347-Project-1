/*
Name: Eric Santana
ID: 015107467
ORG: CSULB
Class: CECS 347
--------------------------
Description: Enable Port B, pins B4 as input(Echo) and 
pin B5 output "Trigger".
*/

#include "portB.h"


void portB_Init(){
	
	SYSCTL_RCGCGPIO_R |= PORTB_MASK;
	
	while((SYSCTL_RCGCGPIO_R) == 0){
	}
	
	GPIO_PORTB_DIR_R |= B5_MASK;// B5 as output
	GPIO_PORTB_DIR_R &=~ B4_MASK;// B4 as input
	GPIO_PORTB_AFSEL_R &=~ B4_B5_MASK;// disable AFSEL B4,B5.
	GPIO_PORTB_DEN_R |= B4_B5_MASK;// Enable B4,B5.
	GPIO_PORTB_AMSEL_R &=~ B4_B5_MASK; // Disable AMSEL B4,B5.
	GPIO_PORTB_PCTL_R &=~ PORTB_PCTL_CODE;
	
	//Interupt Setup Need to add edge interupt for B4 ECHO. Input
	GPIO_PORTB_IS_R &=~B4_MASK;
	GPIO_PORTB_IBE_R |= B4_MASK;
	GPIO_PORTB_IM_R |= B4_MASK;
	GPIO_PORTB_ICR_R = B4_MASK;
	
	// Priority Level setup
	NVIC_PRI0_R |= (NVIC_PRI0_R & 0xFFFF1FFF) | PORTB_PRIORITY_1;
	NVIC_EN0_R |= 0x00000001;
	
	
	
	
}
	
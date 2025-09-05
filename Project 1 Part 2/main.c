#include <stdio.h>
#include "PLL.h"
#include "SysTick.h"
#include "PortF.h"
#include "timer1.h"

#define RED_LED 0x02

void Blink(void);

int main(void){

	PLL_Init();
	PortF_Init();
	Timer1A_Init();
	
	

	while(1){
		
		// shouldnt leave empty, something should indicate it is waiting for interupt.
	
	
	}


	return 0;
	
}



void Timer1A_Handler(){
	TIMER1_ICR_R = TIMER_ICR_TATOCINT;
	GPIO_PORTF_DATA_R ^= RED_LED;
}
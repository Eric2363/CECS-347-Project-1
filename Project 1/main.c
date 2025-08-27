#include <stdio.h>
#include "PLL.h"
#include "SysTick.h"
#include "PortF.h"


#define RED_LED 0x02

int main(void){

	PLL_Init();
	SysTick_Init();
	PortF_Init();
	

	while(1){
		
		// shouldnt leave empty, something should indicate it is waiting for interupt.
	
	
	}


	return 0;
	
}


void SysTick_Handler(void){

		GPIO_PORTF_DATA_R ^= RED_LED;
	
	}
#include <stdio.h>
#include "PLL.h"
#include "SysTick.h"
#include "PortF.h"




int main(void){

	PLL_Init();
	SysTick_Init();
	PortF_Init();
	

	while(1){
		
		GPIO_PORTF_DATA_R |=0x02;
		Delay();
		GPIO_PORTF_DATA_R &=~0x02;
		Delay();
	
	
	}


	return 0;
	
}
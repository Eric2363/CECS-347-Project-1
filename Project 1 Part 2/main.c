#include <stdio.h>
#include "PLL.h"
#include "SysTick.h"
#include "PortF.h"
#include "timer1.h"
#include "portB.h"
#define RED_LED 0x02

void Trigger(void){
		GPIO_PORTB_DATA_R |= 0x20;
		delay();
		GPIO_PORTB_DATA_R &=~ 0x20;
		

}

int main(void){

	PLL_Init();
	PortF_Init();
	Timer1A_Init();
	portB_Init();
	

	while(1){
		
		Trigger();
		
	
	
	}


	return 0;
	
}


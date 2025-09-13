
#include "PLL.h"
//#include "Uart.h"
#include "SysTick.h"
#include "PortF.h"
#include "timer1.h"
#include "portB.h"
#include <stdio.h>
#include <stdint.h>


#define RED_LED 								0x02
#define ECHO_VALUE 							0x10
#define MACHINE_CYCLE_LENGTH 		0.0625
#define SOUND_SPEED 						0.0343


static volatile uint8_t done = 0;
static volatile uint32_t distance = 0;



void Trigger(void){
	
		GPIO_PORTB_DATA_R |= 0x20;
		delayA();
		GPIO_PORTB_DATA_R &=~ 0x20;
		delayA();
		delayA();
		delayA();
		delayA();

}

int main(void){

	PLL_Init();
	Timer1_Init();
	//Uart_Init();
	PortF_Init();
	portB_Init();
	
	

	while(1){
		done = 0;
		distance = 0;
		
		Trigger();
		
		
	
	
	}


	return 0;
	
}

void GPIOPortB_Handler(void) {
		GPIO_PORTF_DATA_R ^= RED_LED;
    if (GPIO_PORTB_DATA_R & ECHO_VALUE) {
        // Rising edge ? start Timer1B
        StartTimerB();
    } else {
        // Falling edge ? stop Timer1B and calculate distance
        StopTimerB();

        // Combine prescaler + 16-bit value into a 24-bit count
        uint32_t current = (TIMER1_TBPR_R << 16) | TIMER1_TBV_R;
        uint32_t reload  = (B_PRESCALE << 16) | B_RELOAD_VALUE;
        uint32_t elapsed = reload - current;

        // Convert ticks ? distance in cm
        distance = (uint32_t)(elapsed * MACHINE_CYCLE_LENGTH * SOUND_SPEED / 2);

        done = 1;
    }

    GPIO_PORTB_ICR_R = ECHO_VALUE;   // Clear interrupt flag for PB4
}







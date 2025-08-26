
#include "tm4c123gh6pm.h"

#define PORTF_UNLOCK_CODE 0x4C4F434B
#define PORTF_CR_CODE 0x1F // Allow changes to portF. 
#define RED_LED_MASK 0x02 // Bit mask for Red LED.
#define PORTF_PCTL_CODE 0x000F0// PCTL for red LED Pin F1.


void PortF_Init(void);

#define HALF_SEC 8000000	//0.5s at 16MHz
#define CLEAR_REG 0
#define EN_SYSTICK 0x00000005 // Enable Counter and Use System Clock.

void SysTick_Init();

void Delay();
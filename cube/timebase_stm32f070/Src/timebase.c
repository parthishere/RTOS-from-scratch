#include "timebase.h"


#define CLOCK_SOURCE 8000000


#define CSR_TICKINIT (1 << 1U)
#define CSR_ENABLE (1 << 0)
#define CSR_CLKSOURCE (1 << 2U)
#define CSR_COUNTFLAG (1 << 16U)

volatile uint32_t times_it_got_full = 0;

#define MAX_DELAY		0xFFFFFFFFU

volatile uint32_t g_curr_tick;
volatile uint32_t g_curr_tick_p;

volatile uint32_t tick_freq = 1;

/*Delay in seconds*/
void delay(uint32_t s)
{
	uint32_t tickstart =  get_tick();

	if(s < MAX_DELAY)
	{
		s += (uint32_t)(tick_freq);
	}

	while((get_tick() - tickstart) < s);

}

uint32_t get_tick(void)
{
	__disable_irq();
	uint32_t r_times_it_got_full = times_it_got_full;
	__enable_irq();


	return r_times_it_got_full;
}



void timebase_init(){
	// Reload the timer with value
	SysTick->LOAD = (CLOCK_SOURCE - 1);
	// Clear the current value register
	SysTick->VAL = 0;
	// Select internal clock source && Enable clock inturupt
	SysTick->CTRL = (CSR_CLKSOURCE | CSR_TICKINIT);
	// Enable Systick
	SysTick->CTRL |=  CSR_ENABLE;
	// Enable global inturrupt
	__enable_irq();
}

void SysTick_Handler(){
	times_it_got_full += 1;
}

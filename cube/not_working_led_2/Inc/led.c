#include "led.h"

#define IOCEN (1 << 4)
#define LEDPIN (1 << 13)
void led_init(void){
	/* Enable clock access to the led port*/
	RCC->APB2ENR |= IOCEN;

	GPIOC->CRH |= (1 << 20);
	GPIOC->CRH &= ~(1 << 21);
	// Set led pin to output pin
}

void led_on(void){
	// PC13 should be on
	GPIOC->ODR |= LEDPIN;
}

void led_off(void){
	// PC13 should be off
	GPIOC->ODR &= ~LEDPIN;
}

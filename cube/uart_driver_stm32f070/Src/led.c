#include "led.h"

#define GPIOA_EN (1 << 17)
#define LED_PIN (1 << 5);
void led_init(void){
	RCC->AHBENR |= GPIOA_EN;
	GPIOA->MODER |= (1 << 10);
	GPIOA->MODER &= ~(1 << 11);

}

void led_on(void){
	GPIOA->ODR |= LED_PIN;
}

void led_off(void){
	GPIOA->ODR &= ~LED_PIN;
}

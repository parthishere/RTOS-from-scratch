#include <stdint.h>
#include <stdio.h>
#include "led.h"
#include "uart.h"
#include "timebase.h"



int main(){
	led_init();
	uart2_init();
	timebase_init();
	while(1){
		led_on();
		delay(1);
		led_off();
		delay(1);
		printf("hellow from stm32070 wohooo \n\r");
	}
}

#include "led.h"
#include "uart.h"

int main(){
	led_init();
	uart2_init();
	while(1){
		led_on();
		for (int i=0; i<999990; i++);
		led_off();
		for (int i=0; i<999990; i++);
		printf("hellow from stm32070 wohooo \n\r");
	}
}

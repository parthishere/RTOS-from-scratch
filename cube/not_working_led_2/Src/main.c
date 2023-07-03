#include "led.h"

int main(){
	led_init();

	while(1){
		led_on();
		for (int i=0; i<9999; i++);
		led_off();
		for (int i=0; i<9999; i++);
	}
}

#ifndef __TIMEBASE_H__
#define __TIMEBASE_H__

#define stm32f070xb

#include "stm32f070xb.h"

uint32_t get_tick(void);
void timebase_init();
void delay(uint32_t s);

#endif

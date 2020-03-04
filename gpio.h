#ifndef GPIO_H_
#define GPIO_H_

#include "MK64F12.h"

#define D0_S 0
#define D1_S 1
#define D2_S 2
#define D3_S 3

#define TOGGLE_RED	GPIOB_PTOR |= ( 1 << RED_LED_S )
#define TOGGLE_BLUE	GPIOB_PTOR |= ( 1 << BLUE_LED_S )


void gpio_init(void);

#endif

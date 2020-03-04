#ifndef GPIO_H_
#define GPIO_H_

#include "MK64F12.h"

#define D0_S 0
#define D1_S 1
#define D2_S 2
#define D3_S 3

#define TOGGLE_RED	GPIOB_PTOR |= ( 1 << RED_LED_S )
#define TOGGLE_BLUE	GPIOB_PTOR |= ( 1 << BLUE_LED_S )

#define CLEAR_ALL_PINS GPIOD_PCOR |= ( 1 << D0_S ); \
                       GPIOD_PCOR |= ( 1 << D1_S ); \
                       GPIOD_PCOR |= ( 1 << D2_S ); \
                       GPIOD_PCOR |= ( 1 << D3_S );
                       
#define TURN_ON_A GPIOD_PSOR |= ( 1 << D0_S );
#define TURN_ON_B GPIOD_PSOR |= ( 1 << D1_S );
#define TURN_ON_C GPIOD_PSOR |= ( 1 << D2_S );
#define TURN_ON_D GPIOD_PSOR |= ( 1 << D3_S );

void gpio_init(void);

#endif

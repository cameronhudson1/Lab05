#include "gpio.h"

void gpio_init(void){
	//initialize push buttons and LEDs
	// D0
	// D1
    // D2
    // D3

	//initialize clocks for each different port used.
	SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;

	// Configure mux for Outputs
  	PORTD_PCR0 = PORT_PCR_MUX(1);
  	PORTD_PCR1 = PORT_PCR_MUX(1);
	PORTD_PCR2 = PORT_PCR_MUX(1);
  	PORTD_PCR3 = PORT_PCR_MUX(1);

	// Switch the GPIO pins to output mode (Red and Blue LEDs)
  	GPIOD_PDDR |= ( 1 << D0_S );
    GPIOD_PDDR |= ( 1 << D1_S );
    GPIOD_PDDR |= ( 1 << D2_S );
    GPIOD_PDDR |= ( 1 << D3_S );

	// Turn off the LEDs
	GPIOD_PSOR |= ( 1 << D0_S );
    GPIOD_PSOR |= ( 1 << D1_S );
    GPIOD_PSOR |= ( 1 << D2_S );
    GPIOD_PSOR |= ( 1 << D3_S );
}

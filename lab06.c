/*
 * Main module for testing the PWM Code for the K64F
 * 
 * Author:  
 * Created:  
 * Modified: Carson Clarke-Magrab <ctc7359@rit.edu> 
 */

#include "MK64F12.h"
#include "uart.h"
#include "pwm.h"
#include "gpio.h"


//#define PART1
//#define PART2
#define PART3

void delay(int del);

int main(void) {
    
#ifdef PART1
	// Initialize UART and PWM
	FTM0_init();
    uart0_init();

	// Print welcome over serial
	uart0_put("Running... \n\r");
	

	// Generate 20% duty cycle at 10kHz
    FTM0_set_duty_cycle(20, 10000, 1);
#endif
#ifdef PART2
    FTM0_init();
    uart0_init();
    
	//for(;;) ;  //then loop forever
	for(;;)  //loop forever
	{
		//uint16_t dc = 0;
		uint16_t freq = 10000; // Frequency = 10 kHz 
		//uint16_t dir = 0;
		//char c = 48;
		int i=0;
		
		// 0 to 100% duty cycle in forward direction
		for (i=0; i<100; i++) {
		    FTM0_set_duty_cycle(i, freq, 1);
			
			delay(10);
		}
		
		// 100% down to 0% duty cycle in the forward direction
		for (i=100; i>=0; i--) {
		    FTM0_set_duty_cycle(i, freq, 1);
			
			delay(10);
		}
		
		// 0 to 100% duty cycle in reverse direction
		for (i=0; i<100; i++) {
		    FTM0_set_duty_cycle(i, freq, 0);
			
			delay(10);
		}
		
		// 100% down to 0% duty cycle in the reverse direction
		for (i=100; i>=0; i--) {
		    FTM0_set_duty_cycle(i, freq, 0);
			
			delay(10);
		}

	}
#endif
    
#ifdef PART3
    
    gpio_init();
    
    int forward = 0;
    int phase = 0;
    for (;;){
        // Turn off all coils , Set GPIO pins to 0
        // Set one pin high at a time
        CLEAR_ALL_PINS
        if( forward )
        {
            if( phase == 0)
            { 
                TURN_ON_A
                phase ++;
            } //A, 1a
            else if( phase == 1)
            { 
                TURN_ON_B
                phase ++;
            } //B ,2a
            else if ( phase == 2) 
            { 
                TURN_ON_C
                phase ++;
            } //C ,1b
            else 
            { 
                TURN_ON_D
                phase =0;
            } //D ,2b
        }
        else 
        {// reverse
            if ( phase == 0)
            { 
                TURN_ON_D
                phase ++;
            } //D ,2b
            else if ( phase == 1) 
            { 
                TURN_ON_C
                phase ++;
            } //C ,1b
            else if ( phase == 2)
            { 
                TURN_ON_B
                phase ++;
            } //B ,2a
            else 
            { 
                TURN_ON_A
                phase = 0;
            } //A ,1a
        }
        delay (1 ); // smaller values = faster speed
    }
#endif
#ifdef PART4
    FTM0_init();
    uart0_init();
    
    //for(;;) ;  //then loop forever
	for(;;)  //loop forever
	{
		//uint16_t dc = 0;
		uint16_t freq = 10000; // Frequency = 10 kHz 
		//uint16_t dir = 0;
		//char c = 48;
		int i=0;
		
		// 0 to 100% duty cycle in forward direction
		for (i=0; i<100; i++) 
        {
		    FTM0_set_duty_cycle(i, freq, 1);
			
			delay(10);
		}
		
		// 100% down to 0% duty cycle in the forward direction
		for (i=100; i>=0; i--) 
        {
		    FTM0_set_duty_cycle(i, freq, 1);
			
			delay(10);
		}
		
		// 0 to 100% duty cycle in reverse direction
		for (i=0; i<100; i++) 
        {
		    FTM0_set_duty_cycle(i, freq, 0);
			
			delay(10);
		}
		
		// 100% down to 0% duty cycle in the reverse direction
		for (i=100; i>=0; i--) 
        {
		    FTM0_set_duty_cycle(i, freq, 0);
			
			delay(10);
		}

	}
    
#endif
    
	return 0;
}


/**
 * Waits for a delay (in milliseconds)
 * 
 * del - The delay in milliseconds
 */
void delay(int del){
	int i;
	for (i=0; i<del*50000; i++){
		// Do nothing
	}
}

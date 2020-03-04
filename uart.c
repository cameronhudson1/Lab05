 /*
 * File:        uart.c
 * Purpose:     Provide UART routines for serial IO
 *
 * Notes:		
 *
 */

#include "uart.h"
#include "stdio.h"

void uart0_init()
{
//define variables for baud rate and baud rate fine adjust
uint16_t ubd, brfa;

//Enable clock for UART
SIM_SCGC4 |= SIM_SCGC4_UART0_MASK; // enable clk to uart0
SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK; //enables clk for port B

//Configure the port control register to alternative 3 (which is UART mode for K64)
PORTB_PCR16 |= PORT_PCR_MUX(3); //enable alt 3 for PTB16
PORTB_PCR17 |= PORT_PCR_MUX(3); //enable alt 3 for PTB17

/*Configure the UART for establishing serial communication*/

//Disable transmitter and receiver until proper settings are chosen for the UART module
uart0_disable();

//Select default transmission/reception settings for serial communication of UART by clearing the control register 1
uart0_default_config();

//UART Baud rate is calculated by: baud rate = UART module clock / (16 × (SBR[12:0] + BRFD))
//13 bits of SBR are shared by the 8 bits of UART3_BDL and the lower 5 bits of UART3_BDH 
//BRFD is dependent on BRFA, refer Table 52-234 in K64 reference manual
//BRFA is defined by the lower 4 bits of control register, UART0_C4 

//calculate baud rate settings: ubd = UART module clock/16* baud rate
ubd = (uint16_t)((SYS_CLOCK)/(BAUD_RATE * 16));  

//clear SBR bits of BDH
UART0_BDH &= ~(UART_BDH_SBR_MASK);

//distribute this ubd in BDH and BDL
UART0_BDH |= UART_BDL_SBR(ubd >> 8);
UART0_BDL |= UART_BDL_SBR(ubd);

//BRFD = (1/32)*BRFA 
//make the baud rate closer to the desired value by using BRFA
brfa = (((SYS_CLOCK*32)/(BAUD_RATE * 16)) - (ubd * 32));

//write the value of brfa in UART0_C4
UART0_C4 |= UART_C4_BRFA(brfa);
	
//Enable transmitter and receiver of UART
uart0_en();

}


uint8_t uart0_getchar()
{
    /* Wait until there is space for more data in the receiver buffer*/
    while ((UART0_S1 & (1 << UART_S1_RDRF_SHIFT)) == 0)  { }//asm(""); } 
    /* Return the 8-bit data from the receiver */
    return UART0_D;
}

void uart0_putchar(char ch)
{
    /* Wait until transmission of previous bit is complete */
    while ((UART0_S1 & (1 << UART_S1_TDRE_SHIFT)) == 0)  { }//asm(""); }
    /* Send the character */
    UART0_D = ch;
}

void uart0_put(char *ptr_str){
	/*use putchar to print string*/
    while(*ptr_str)
		uart0_putchar(*ptr_str++);
}

void uart0_putNumU(int i){
    char num[10];
    sprintf(num, "%d", i);
    uart0_put(num);
}

void uart0_putNumF(float i){
    char num[10];
    sprintf(num, "%f", i);
    uart0_put(num);
}

void uart0_putNumHex(int i){
    char num[10];
    sprintf(num, "0x%x", i);
    uart0_put(num);
}

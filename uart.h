/*
 * Header for UART 0 string control
 * literaly vibe
 * Ryan Radicello 01-22-2020
*/
#ifndef UART_H
#define UART_H

#include "MK64F12.h"
#define BAUD_RATE 9600      //default baud rate 
#define SYS_CLOCK 20485760 //default system clock (see DEFAULT_SYSTEM_CLOCK  in system_MK64F12.c)
//#define CHAR_COUNT 10      //change this to modify the max. permissible length of a sentence

#define Rx_shift 16
#define Tx_shift 17
#define transmit_en 3
#define receive_en 2
#define uart0_disable() UART0_C2 &= ~(UART_C2_RE_MASK | UART_C2_TE_MASK) //clear the 2 en bits
#define uart0_en()      UART0_C2 |= (UART_C2_RE_MASK | UART_C2_TE_MASK) //set the two en bits
#define uart0_default_config()    UART0_C1 &= 00000000 //set config to default

#define uart3_disable() UART3_C2 &= ~(UART_C2_RE_MASK | UART_C2_TE_MASK) //clear the 2 en bits
#define uart3_en()      UART3_C2 |= (UART_C2_RE_MASK | UART_C2_TE_MASK) //set the two en bits
#define uart3_default_config()    UART3_C1 &= 00000000 //set config to default

void uart0_init(void);
void uart0_put(char *ptr_str);
void uart0_putNumU(int i);
void uart0_putNumHex(int i);
void uart0_putNumF(float i);
uint8_t uart0_getchar(void);
void uart0_putchar(char ch);

#endif

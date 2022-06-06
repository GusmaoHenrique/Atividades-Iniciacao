/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef FUNCTIONS_H
#define	FUNCTIONS_H

/* DEFINIÇÕES */
#define _XTAL_FREQ 32000000
#define LED PORTDbits.RD2
#define LED2 PORTDbits.RD3
#define Timer0_Interrupt if(TMR0IF)
#define INT0_Interrupt if(INT0IF)

//#define RTOS_LED1() if((contTime - aux) >= 10000)
/* FUNCTIONS */

void InitConfig();
void InitTimer0();
void recarregaTimer0();
void delay_us(int XX);

/*END FUNCTIONS */

#endif	/* XC_HEADER_TEMPLATE_H */


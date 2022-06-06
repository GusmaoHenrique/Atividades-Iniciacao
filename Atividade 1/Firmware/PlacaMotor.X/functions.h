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
#define _XTAL_FREQ 48000000
#define LED PORTDbits.RD0
#define LED2 PORTDbits.RD1
#define LED3 PORTDbits.RD2
#define LED4 PORTDbits.RD3
#define Timer0_Interrupt() if(TMR0IF)

/* FUNCTIONS */
void InitConfig();
void InitTimer0();
int adc_read(char canal);
/*END FUNCTIONS */

#endif	/* XC_HEADER_TEMPLATE_H */
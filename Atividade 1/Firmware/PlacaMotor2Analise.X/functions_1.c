/*
 * File:   functions.c
 * Author: T-Gamer
 *
 * Created on 11 de Junho de 2020, 23:02
 */

#include "functions_1.h"
#include <xc.h>

/* FUNCTIONS */
void InitConfig()           //Configurações Iniciais
{
    TRISA = 0xFF;
    TRISB = 0xFF;
    PORTBbits.RB0 = 0;
    TRISD = 0x00;
    PORTD = 0x00;
    
    ADCON0 = 0x01;
    ADCON1 = 0x0E;
    ADCON2 = 0x80;
    /*
     Interruptçao*/
    GIE = 1;
    PEIE = 1;
    TMR0IE = 0;
    INT0IE = 1;             //HABILITA INTERRUPÇÃO EXTERNA TIMER0
    TMR0IF = 0;
    INT0IF = 0;
    INTEDG0 = 1;            //CONFIGURA BORDA DE SUBIDA 1-subida, 0-descida
}
void InitTimer0()           //Inicializa Timer0
{
    TMR0ON = 0;
    T08BIT = 0;
    T0CS = 0;
    T0SE = 0;
    PSA = 0;
    T0CONbits.T0PS0 = 0;
    T0CONbits.T0PS1 = 1;     // prescaler 1/8 : 010 : 1us
    T0CONbits.T0PS2 = 0;
    TMR0 = 0;      //8 bits = 0 a 255 , 16bits 0 a 65535 * 2 1us por instruçao
    TMR0ON = 1;
}
/* END FUNCTIONS */
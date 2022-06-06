/*
 * File:   functions.c
 * Author: T-Gamer
 *
 * Created on 11 de Junho de 2020, 23:02
 */

#include "functions.h"
#include <xc.h>
/* FUNCTIONS */
void InitConfig()              //Configurações Iniciais
{
    TRISD = 0x00;
    PORTD = 0x00;
    TRISA = 0xFF;
    ADCON0 = 0x01;
    ADCON1 = 0x0E;
    ADCON2 = 0x80;
    /*
     Interruptçao*/
    GIE = 1;
    PEIE = 1;
    TMR0IE = 1;
    TMR0IF = 0;
}
void InitTimer0()           //Configurações Timer0
{
    TMR0ON = 0;
    T08BIT = 0;
    T0CS = 0;
    T0SE = 0;
    PSA = 1;
    T0CONbits.T0PS0 = 0;
    T0CONbits.T0PS1 = 0;
    T0CONbits.T0PS2 = 0;
    TMR0 = 64360;
    TMR0ON = 1;
}
int adc_read(char canal)       //Função Leitura Canal Analógico
{
    int result;
    ADCON0 = ADCON0 | ((canal & 0x0F) << 2); // SELECIONA O CANAL
    
    ADCON0bits.GO_nDONE = 1;
    while(ADCON0bits.GO_nDONE);
    
    result = ADRESL + (ADRESH << 8);
    
    return result;
}
/* END FUNCTIONS */
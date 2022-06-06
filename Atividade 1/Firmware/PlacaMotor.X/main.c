/*
 * File:   main.c
 * Author: T-Gamer
 *
 * Created on 11 de Junho de 2020, 23:00
 */

#include <xc.h>
#include "fuses.h"
#include "functions.h"

/*
 Variaveis Globais*/
unsigned int tempoInt;
int dente = 0;

void __interrupt () my_isr_routine (void)     //Interrupção Timer
{
    Timer0_Interrupt()
    {
        TMR0 = tempoInt;
        TMR0IF = 0;
        dente ++;
        if(dente <= 58)                      //Roda Fônica
        {
            LED = !LED;
        }
        else if(dente <= 60)                 //Falha da Roda Fônica
        {
            LED = 0;
        }
        else dente = 0;
        if (dente == 1)                      //Sinal de Fase
        {
            LED2 =~ LED2;
        }
    }
}
void main(void) 
{
    InitConfig();
    InitTimer0();
    
    float adx;                              //Variáveis Cálculo
    float tempo;
    while(1)
    {  
        adx = adc_read(0);
        tempo = (1833.0*adx)/1023.0;        //Cálculo A/D
        tempo = 2000.0-tempo;
        tempo *=6;
        tempoInt = 65536-tempo;
        
        if(dente <=35  && dente >=25)       //PMS Cilindro 1
            LED3 = 1;
        else 
            LED3 = 0;
    }
}


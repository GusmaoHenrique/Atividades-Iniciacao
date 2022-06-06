/*
 * File:   main.c
 * Author: T-Gamer
 *
 * Created on 11 de Junho de 2020, 23:00
 */

#include "fuses_1.h"
#include "functions_1.h"
#include "LCD_Lib.h"
#include <xc.h>
#include <stdio.h>

/* Variaveis Globais*/
unsigned long subida = 0; 
unsigned long descida = 0;
unsigned long temp = 0;
float rotacao = 0;
int auxx = 0;
int falha = 0;

void __interrupt () my_isr_routine (void)               //Interrupção
{   
    INT0_Interrupt
    {
        if(auxx == 0)                           //Cálculo Período de Pulso
        {
            descida = TMR0;                     //Tempo Período        
            TMR0 = 0;
            temp = descida - subida;
            
            if(temp < (subida*3) && temp > 165)
            {
                temp += subida;
            }
            else                                //Falha Roda Fônica
            {
                temp = subida*2;
                falha ++;                   
            }
            INT0IF = 0;
            INTEDG0 = 0;
            auxx ++;
        }
        else                                //Tempo de Meia-onda
        {   
            subida = TMR0;
            INT0IF = 0;
            INTEDG0 = 1;            
            auxx = 0;
        }
    }        
}
void main(void) 
{   
    char txt [6];                     //String de texto auxiliar
    char txt2 [6];
    
    InitConfig();
    InitTimer0();
    
    LCD_Begin();       //initialize LCD module
    __delay_ms(100);
    LCD_Cmd(LCD_CLEAR);       //Limpa LCD
    while (1)
    {   
        sprintf(txt2, "%d", temp);      //Tranforma em Forma de Texto
        LCD_Goto(7, 1);                 //Config Coluna e Linha
        __delay_ms(100);                //Aguarda
        LCD_Print(txt2);                //Escreve no LCD
        LCD_Print("us"); 
        
        rotacao = temp*60;
        rotacao = 1/rotacao;
        rotacao *= 60;
        rotacao *= 1000000;
        
        sprintf(txt, "%.1f", rotacao);   //Tranforma em Forma de Texto
        LCD_Goto(5, 2);                 //Config Coluna e Linha
        __delay_ms(100);                //Aguarda
        LCD_Print(txt);                //Escreve no LCD
        LCD_Print("rpm");
    }
}


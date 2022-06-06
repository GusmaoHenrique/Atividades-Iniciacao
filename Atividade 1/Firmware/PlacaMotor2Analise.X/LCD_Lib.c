/*******************************************************************************
 * LCD_Lib.c                                                                   *
 * MPLAB XC8 compiler LCD driver for LCDs with HD44780 compliant controllers.  *
 * https://simple-circuit.com/                                                 *
 *                                                                             *
 ******************************************************************************/
#include <stdint.h>
#include "LCD_Lib.h"
#include "fuses_1.h"
#include "functions_1.h"
#include <xc.h>

void LCD_Write_Nibble(unsigned char n)
{
  LCD_RS = RS;
  LCD_D4 = n & 0x01;
  LCD_D5 = (n >> 1) & 0x01;
  LCD_D6 = (n >> 2) & 0x01;
  LCD_D7 = (n >> 3) & 0x01;

  // send enable pulse
  LCD_EN = 0;
  __delay_us(1);
  LCD_EN = 1;
  __delay_us(1);
  LCD_EN = 0;
  __delay_us(100);
}
void LCD_Cmd(unsigned char Command)
{
  RS = 0;
  LCD_Write_Nibble(Command >> 4);
  LCD_Write_Nibble(Command);
  if((Command == LCD_CLEAR) || (Command == LCD_RETURN_HOME))
    __delay_ms(2);
}
void LCD_Goto(unsigned char col, unsigned char row)
{
  switch(row)
  {
    case 2:
      LCD_Cmd(LCD_SECOND_ROW + col - 1);
      break;
    case 3:
      LCD_Cmd(LCD_THIRD_ROW  + col - 1);
      break;
    case 4:
      LCD_Cmd(LCD_FOURTH_ROW + col - 1);
    break;
    default:      // case 1:
      LCD_Cmd(LCD_FIRST_ROW  + col - 1);
  }

}
void LCD_PutC(char LCD_Char)
{
  RS = 1;
  LCD_Write_Nibble(LCD_Char >> 4);
  LCD_Write_Nibble(LCD_Char );
}
void LCD_Print(char* LCD_Str)
{
  unsigned char i = 0;
  RS = 1;
  while(LCD_Str[i] != '\0')
  {
    LCD_Write_Nibble(LCD_Str[i] >> 4);
    LCD_Write_Nibble(LCD_Str[i++] );
  }
}
void LCD_Begin()
{
  RS = 0;

  LCD_RS     = 0;
  LCD_EN     = 0;
  LCD_D4     = 0;
  LCD_D5     = 0;
  LCD_D6     = 0;
  LCD_D7     = 0;
  LCD_RS_DIR = 0;
  LCD_EN_DIR = 0;
  LCD_D4_DIR = 0;
  LCD_D5_DIR = 0;
  LCD_D6_DIR = 0;
  LCD_D7_DIR = 0;

  __delay_ms(40);
  LCD_Cmd(3);
  __delay_ms(5);
  LCD_Cmd(3);
  __delay_ms(5);
  LCD_Cmd(3);
  __delay_ms(5);
  LCD_Cmd(LCD_RETURN_HOME);
  __delay_ms(5);
  LCD_Cmd(0x20 | (LCD_TYPE << 2));
  __delay_ms(50);
  LCD_Cmd(LCD_TURN_ON);
  __delay_ms(50);
  LCD_Cmd(LCD_CLEAR);
  __delay_ms(50);
  LCD_Cmd(LCD_ENTRY_MODE_SET | LCD_RETURN_HOME);
  __delay_ms(50);
}
void LCD_number(unsigned int number)
{
    unsigned char txt[5];
    txt[4] = number%10 + '0';
    number /= 10;
    txt[3] = number%10 + '0';
    number /= 10;
    txt[2] = number%10 + '0';
    number /= 10;
    txt[1] = number%10 + '0';
    number /= 10;
    txt[0] = number + '0';
    number = 0;
    
    LCD_Print(txt);
}
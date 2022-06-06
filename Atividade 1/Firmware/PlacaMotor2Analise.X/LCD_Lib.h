
#define LCD_FIRST_ROW          0x80
#define LCD_SECOND_ROW         0xC0
#define LCD_THIRD_ROW          0x94
#define LCD_FOURTH_ROW         0xD4
#define LCD_CLEAR              0x01
#define LCD_RETURN_HOME        0x02
#define LCD_ENTRY_MODE_SET     0x04
#define LCD_CURSOR_OFF         0x0C
#define LCD_UNDERLINE_ON       0x0E
#define LCD_BLINK_CURSOR_ON    0x0F
#define LCD_MOVE_CURSOR_LEFT   0x10
#define LCD_MOVE_CURSOR_RIGHT  0x14
#define LCD_TURN_ON            0x0C
#define LCD_TURN_OFF           0x08
#define LCD_SHIFT_LEFT         0x18
#define LCD_SHIFT_RIGHT        0x1E

#define LCD_RS       PORTDbits.RD0
#define LCD_EN       PORTDbits.RD1
#define LCD_D4       PORTDbits.RD4
#define LCD_D5       PORTDbits.RD5
#define LCD_D6       PORTDbits.RD6
#define LCD_D7       PORTDbits.RD7
#define LCD_RS_DIR   TRISDbits.TRISD0
#define LCD_EN_DIR   TRISDbits.TRISD1
#define LCD_D4_DIR   TRISDbits.TRISD4
#define LCD_D5_DIR   TRISDbits.TRISD5
#define LCD_D6_DIR   TRISDbits.TRISD6
#define LCD_D7_DIR   TRISDbits.TRISD7

#ifndef LCD_TYPE
   #define LCD_TYPE 2           // 0=5x7, 1=5x10, 2=2 lines
#endif

char RS;

void LCD_Write_Nibble(unsigned char n);
void LCD_Cmd(unsigned char Command);
void LCD_Goto(unsigned char col, unsigned char row);
void LCD_PutC(char LCD_Char);
void LCD_Print(char* LCD_Str);
void LCD_Begin();
void LCD_number(unsigned int number);

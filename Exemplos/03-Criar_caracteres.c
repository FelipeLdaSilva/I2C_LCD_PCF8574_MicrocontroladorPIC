/*
 * Exemplo: Create Char
 * Biblioteca: Interface entre o Microcontrolador PIC e o LCD 16x2 com expansor de portas I2C PCF8574
 * Microcontrolador: PIC16F877A
 */

#include <xc.h>
#include "config.h"
#include "I2C_LCD.h"
    
unsigned char Heart[] =   {0b00000,0b01010,0b11111,0b11111,0b01110,0b00100,0b00000,0b00000};
unsigned char Bell[] =    {0b00100,0b01110,0b01110,0b01110,0b11111,0b00000,0b00100,0b00000};
unsigned char Alien[] =   {0b11111,0b10101,0b11111,0b11111,0b01110,0b01010,0b11011,0b00000};
unsigned char Check[] =   {0b00000,0b00001,0b00011,0b10110,0b11100,0b01000,0b00000,0b00000};
unsigned char Speaker[] = {0b00001,0b00011,0b01111,0b01111,0b01111,0b00011,0b00001,0b00000};
unsigned char Sound[] =   {0b00001,0b00011,0b00101,0b01001,0b01001,0b01011,0b11011,0b11000};
unsigned char Skull[] =   {0b00000,0b01110,0b10101,0b11011,0b01110,0b01110,0b00000,0b00000};
unsigned char Lock[] =    {0b01110,0b10001,0b10001,0b11111,0b11011,0b11011,0b11111,0b00000};

void main(void) {
    
    I2C_Master_Init();
    LCD_Init(0x4E);
    
    LCD_Create_Char(0, Heart);
    LCD_Create_Char(1, Bell);
    LCD_Create_Char(2, Alien);
    LCD_Create_Char(3, Check);
    LCD_Create_Char(4, Speaker);
    LCD_Create_Char(5, Sound);
    LCD_Create_Char(6, Skull);
    LCD_Create_Char(7, Lock);
    
    LCD_Set_Cursor(1, 1);
    LCD_Write_String("LCD Create Char ");
    LCD_Set_Cursor(2 ,1);
    LCD_Write_Char(0);
    LCD_Write_Char(1);
    LCD_Write_Char(2);
    LCD_Write_Char(3);
    LCD_Write_Char(4);
    LCD_Write_Char(5);
    LCD_Write_Char(6);
    LCD_Write_Char(7);
    
    while(1){
        __delay_ms(10000);
    }
    
    return;
}

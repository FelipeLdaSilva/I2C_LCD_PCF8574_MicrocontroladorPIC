# Microcontrolador PIC com display I2C LCD (módulo PCF8574)
Com esta biblioteca, torna-se viável estabelecer uma conexão entre o microcontrolador PIC e displays LCD por meio do módulo I2C PCF8574, possibilitando a utilização de até 8 displays LCD.

Embora tenha sido desenvolvida para o microcontrolador PIC16F877A / PIC18F2550, essa biblioteca pode ser adaptada para outros microcontroladores PIC, como o PIC18F4550, o PIC18F4620, entre outros, mediante a modificação dos registradores. Ademais, a lógica pode ser aproveitada em microcontroladores AVR, STM, dentre outros.

## Funções de controle do display 

``` C
void LCD_Init(unsigned char I2C_Add);
void LCD_Set_Address(unsigned char I2C_Add);
void IO_Expander_Write(unsigned char Data);
void LCD_Write_4Bit(unsigned char Nibble);
void LCD_CMD(unsigned char CMD);
void LCD_Set_Cursor(unsigned char ROW, unsigned char COL);
void LCD_Write_Char(char);
void LCD_Write_String(char*);
void LCD_Write_Number(unsigned short length, unsigned int number);
void LCD_Create_Char(unsigned short CGRAM_Position, unsigned char Custom_Char[]);
void Backlight();
void noBacklight();
void LCD_SR();
void LCD_SL();
void LCD_Clear();
```

## Exemplo básico de uso da biblioteca

``` C
#include <xc.h>
#include "config.h"
#include "I2C_LCD.h"

void main(void) {
    
    I2C_Master_Init();
    LCD_Init(0x4E);
    
    LCD_Set_Cursor(1, 1);
    LCD_Write_String("   PIC16F877A   ");
    LCD_Set_Cursor(2 ,1);
    LCD_Write_String("    I2C LCD     ");
    
    while(1){
        __delay_ms(500);
        LCD_SR();
        __delay_ms(500);
        LCD_SL();
        __delay_ms(500);
        LCD_SL();
        __delay_ms(500);
        LCD_SR();
    }
    
    return;
}
```

## Exemplo de uso da biblioteca com números inteiros

```C
#include <xc.h>
#include "config.h"
#include "I2C_LCD.h"
    
unsigned int num = 0;

void main(void) {
    
    I2C_Master_Init();
    LCD_Init(0x4E);
    
    LCD_Set_Cursor(1, 1);
    LCD_Write_String("I2C LCD 16x2    ");
    LCD_Set_Cursor(2 ,1);
    LCD_Write_String("LCD Write Number");
    __delay_ms(2000);
    
    LCD_Set_Cursor(2 ,1);
    LCD_Write_String("Count:          ");
    
    while(1){
        LCD_Set_Cursor(2, 8);
        LCD_Write_Number(2, num);
        __delay_ms(1000);
        
        if(num < 100) {
            num++;
        } else {
            num = 0;
        }
    }
    
    return;
}
```

## Criando caracteres personalizados
```C
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
```

## Utilizando a biblioteca com dois displays
``` C
#include <xc.h>
#include "config.h"
#include "I2C_LCD.h"

#define LCD1_Address 0x4E
#define LCD2_Address 0x46

unsigned int num1 = 980;
unsigned int num2 = 80;

void main(void) {
    
    I2C_Master_Init();
    LCD_Init(LCD1_Address);
    LCD_Init(LCD2_Address);
    
    LCD_Set_Address(LCD1_Address);
    LCD_Set_Cursor(1, 1);
    LCD_Write_String(" Display 1      ");
    LCD_Set_Cursor(2 ,1);
    LCD_Write_String(" Count:         ");
    
    LCD_Set_Address(LCD2_Address);
    LCD_Set_Cursor(1, 1);
    LCD_Write_String(" Display 2      ");
    LCD_Set_Cursor(2 ,1);
    LCD_Write_String(" Count:         ");
    
    while(1){
        
        LCD_Set_Address(LCD1_Address);
        LCD_Set_Cursor(2, 9);
        LCD_Write_Number(3, num1);
        
        LCD_Set_Address(LCD2_Address);
        LCD_Set_Cursor(2, 9);
        LCD_Write_Number(3, num2);
        
        __delay_ms(1000);
        
        if(num1 < 1000)  num1++;
        else             num1 = 0;
        
        if(num2 < 1000)  num2++;
        else             num2 = 0;
    }
    
    return;
}
```

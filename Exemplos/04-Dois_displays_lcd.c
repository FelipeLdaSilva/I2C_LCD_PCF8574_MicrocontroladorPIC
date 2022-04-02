/*
 * Exemplo: Dois display's LCD com módulo I2C
 * Biblioteca: Interface entre o Microcontrolador PIC e o LCD 16x2 com expansor de portas I2C PCF8574
 * Microcontrolador: PIC16F877A
 */

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

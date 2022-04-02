/*
 * Exemplo: Number
 * Biblioteca: Interface entre o Microcontrolador PIC e o LCD 16x2 com expansor de portas I2C PCF8574
 * Microcontrolador: PIC16F877A
 */

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

/*
 * Exemplo: Básico
 * Biblioteca: Interface entre o Microcontrolador PIC e o LCD 16x2 com expansor de portas I2C PCF8574
 * Microcontrolador: PIC16F877A
 */

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

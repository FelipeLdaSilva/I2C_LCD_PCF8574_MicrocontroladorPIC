# Microcontrolador PIC com display I2C LCD (módulo PCF8574)
Com essa biblioteca é possível fazer a interface entre o microcontrolador PIC e displays LCD usando o módulo I2C PCF8574. Isso permitirá usar até 8 displays LCD.<br>
Essa biblioteca foi feita para o microcontrolador PIC16F877A / PIC18F2550, mas alterando os registradores, ela pode ser reutilizada em outros microcontroladores PIC, como o PIC18F4550, o PIC18F4620, etc. A lógica também pode ser reutilizada em microcontroladores AVR, STM, entre outros.

## Funções de controle do display 

void LCD_Init(unsigned char I2C_Add);<br>
void LCD_Set_Address(unsigned char I2C_Add);<br>
void IO_Expander_Write(unsigned char Data);<br>
void LCD_Write_4Bit(unsigned char Nibble);<br>
void LCD_CMD(unsigned char CMD);<br>
void LCD_Set_Cursor(unsigned char ROW, unsigned char COL);<br>
void LCD_Write_Char(char);<br>
void LCD_Write_String(char*);<br>
void LCD_Write_Number(unsigned short length, unsigned int number);<br>
void LCD_Create_Char(unsigned short CGRAM_Position, unsigned char Custom_Char[]);<br>
void Backlight();<br>
void noBacklight();<br>
void LCD_SR();<br>
void LCD_SL();<br>
void LCD_Clear();<br>

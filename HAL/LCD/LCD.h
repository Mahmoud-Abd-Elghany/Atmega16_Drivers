/*
 * LCD.h
 *
 * Created: 6/1/2021 9:19:03 PM
 *  Author: Mahmoud Abdelghany
 */ 
#include <avr/io.h>
#include <util/delay.h>

#ifndef LCD_H_
#define LCD_H_

#define LCD_PORT_DIR DDRC
#define LCD_PORT_OUT PORTC
#define LCD_PORT_UPPER_LOWER UPPER
#define RS_PIN 2
#define R_W_PIN 1
#define ENABLE_PIN 0

#define LCD_4BIT_MODE 0x02
#define LCD_4BIT_2LINES_MODE 0x28
#define LCD_DISPLAY_ON_CURSOR_ON  0x0E
#define LCD_DISPLAY_ON_CURSOR_OFF  0x0c
#define LCD_CLEAR_SCREEN 0x01

void LCD_init(void);
void LCD_Send_Command(unsigned char cmd);
void LCD_Send_Character(unsigned char Character);






#endif /* LCD_H_ */
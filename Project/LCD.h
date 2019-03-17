#ifndef LCD_H
#define LCD_H

#include "typedefs.h"
#include "tm4c123gh6pm.h"
#include "DIO.h"
#include "timer.h"

void LCD_sendCommand(uint8 command);
void LCD_sendInt(uint8 number);
void LCD_init(void);
void LCD_clearScreen(void);
#endif
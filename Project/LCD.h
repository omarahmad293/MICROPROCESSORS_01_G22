#ifndef LCD_H
#define LCD_H

#include "typedefs.h"
#include "tm4c123gh6pm.h"
#include "DIO.h"
#include "timer.h"


//Ports
#define PORT_A 0
#define PORT_B 1
#define PORT_C 2
#define PORT_D 3
#define PORT_E 4
#define PORT_F 5


#define RS 0
#define RW 1
#define E 2

#define CONTROL GPIO_PORTB_DATA_BITS_R
#define DATA GPIO_PORTD_DATA_R


/* List Of Command Codes */
#define Clear_display 0x01
#define Return_Home	  0x02
#define Display_off   0x08
#define Display_on   (0x0C | (CURSOR<<1) | (Blink))
#define CURSOR_Shift_Right	 0x14
#define CURSOR_Shift_left	 0x10
#define Display_shift_left    0x18
#define Display_shift_Right	  0x1C
#define Data_Set (0x20 |(_5x10_Dot<<2)|(Two_lines<<3)| (1<<4))
#define DDRAM_CONST 0x80



void LCD_sendCommand(uint8 command);
void LCD_sendInt(uint8 number);
void LCD_init(void);
void LCD_clearScreen(void);
#endif

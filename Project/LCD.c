#include "LCD.h"
#include "includes.h"

		/* init Settings */
#define CURSOR  1		/* 1 to Enable , 0 to Disable */
#define Blink	0		/* 1 to Enable , 0 to Disable */
#define _5x10_Dot	 0	/* 1 to Enable , 0 for 5 x 8 Dot */
#define Two_lines	 1	/* 1 to Enable , 0 for 1 Line */
#define LCD_CRTL_MASK     0x07  // 00 0111

		#if ( _5x10_Dot && Two_lines )
			#if Two_lines
				#pragma GCC error "You cannot Have Two Lines LCD with 5 * 10"
			#endif
		#endif

//LCD initialization
void LCD_init(void)
{
		Port_SetPinDirection(PORT_E, LCD_CRTL_MASK, PORT_PIN_OUT);
		Port_SetPinDirection(PORT_D, 0xFF, PORT_PIN_OUT);
		LCD_sendCommand(Data_Set);
		LCD_sendCommand(Display_on);
		LCD_sendCommand(Clear_display);
}


// function to convert number to char array
char* itoa(int value, char* result, int base) {
		// check that the base if valid
	
		if (base < 2 || base > 36) { *result = '\0'; return result; }

		char* ptr = result, *ptr1 = result, tmp_char;
		int tmp_value;

		do {
			tmp_value = value;
			value /= base;
			*ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
		} while ( value );

		// Apply negative sign
		if (tmp_value < 0) *ptr++ = '-';
		*ptr-- = '\0';
		while(ptr1 < ptr) {
			tmp_char = *ptr;
			*ptr--= *ptr1;
			*ptr1++ = tmp_char;
		}
		return result;
	}


void LCD_sendInt(uint8 number){
	uint8 n;
	uint8 i=0;
	char c[3];
	if(number/100 >0) n=3;
	else if(number/10 >0) n=2;
	else n=1;
	
	itoa(number,c,10);
	
	for( i=0; i<n; i++){
		GPIO_PORTD_DATA_R=c[i]; //send numbers character by character
		GPIO_PORTE_DATA_R |= 1; // set RS
		GPIO_PORTE_DATA_R |= 4; // set ENABLE
		GPIO_PORTE_DATA_R &=~ 2; //clr rw aka write mode
		delay_ms(10);
		GPIO_PORTE_DATA_R &=~ 4; // clr ENABLE
	}
}

//Sends a command to the LCD
//uint8 command: Command to be sent
void LCD_sendCommand(uint8 command)
{
	//void DIO_WritePort(uint8 port_index, uint8 pins_mask, Dio_LevelType pins_level);
	//DIO_WritePort(PORT_E, MASK_0, STD_LOW);
	DIO_WritePort(PORT_E,0,STD_LOW);
	DIO_WritePort(PORT_E,2,STD_LOW);
	delay_ms(1);
	DIO_WritePort(PORT_E,4, STD_HIGH);
	delay_ms(1);
	DATA = command;
	delay_ms(1);
	DIO_WritePort(PORT_E,4, STD_LOW);
	delay_ms(1); 
}

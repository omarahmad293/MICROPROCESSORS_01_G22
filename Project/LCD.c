#include "LCD.h"


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
	DIO_WritePort(PORT_E,1,STD_LOW);
	delay_ms(1);
	DIO_WritePort(PORT_E,2, STD_HIGH);
	delay_ms(1);
	DATA = command;
	delay_ms(1);
	DIO_WritePort(PORT_E,2, STD_LOW);
	delay_ms(1); 
}

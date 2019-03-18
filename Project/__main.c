#include "includes.h"

#define LCD_DATA          PORT_B
#define LCD_CRTL_MASK     0x07  // 00 0111
#define PUSH_BUTTONS_MASK 0x18  // 11000

#define INCREMENT_BUTTON  3
#define DECREMENT_BUTTON  5
#define RESET_BUTTON      4

void __main()
{
	uint16 count = 500;
	
	Port_Init(LCD_DATA);
	Port_Init(PORT_F);
	
	Port_SetPinDirection(LCD_DATA, PORT_PINS, PORT_PIN_OUT);
	Port_SetPinDirection(PORT_F, LCD_CRTL_MASK, PORT_PIN_OUT);
	Port_SetPinDirection(PORT_F, PUSH_BUTTONS_MASK, PORT_PIN_IN);
	
	Port_SetPinPullUp(PORT_F, PUSH_BUTTONS_MASK, 1);
	
	Timer_init();
	LCD_init();
	
	//LCD_clearScreen();
	
	LCD_sendInt(count);
		
	for(;;)
	{
		if (PushButton_readState(PORT_F, INCREMENT_BUTTON) == PRESSED)
		{
			//Wait for 0.2 second
			delay_ms(200);
			
			//Check if button is still pressed
			if (PushButton_readState(PORT_F, INCREMENT_BUTTON) == PRESSED)
			{
				//Increment counter
				count++;
				
				//Clear the screen
				LCD_clearScreen();
				
				//Send the new counter
				LCD_sendInt(count);
			}
		}
		
		else if (!PushButton_readState(PORT_F, DECREMENT_BUTTON) == PRESSED)
		{
			//Decrement counter
			count--;
			
			//Clear the screen
			LCD_clearScreen();
			
			//Send the new counter
			LCD_sendInt(count);
			
			//Wait until button is released to prevent continuous pressing
			while(!PushButton_readState(PORT_F, DECREMENT_BUTTON) == PRESSED);
		}
		
		else if (!PushButton_readState(PORT_F, RESET_BUTTON) == PRESSED)
		{
			//Wait until button is released
			while(!PushButton_readState(PORT_F, RESET_BUTTON) == PRESSED);

			//Reset counter
			count = 0;
			
			//Clear the screen
			LCD_clearScreen();
			
			//Send the new counter
			LCD_sendInt(count);
		}
	}
}

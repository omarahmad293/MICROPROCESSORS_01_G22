#include "includes.h"

#define LCD_DATA          PORT_D
#define LCD_CRTL_MASK     0x07  // 00 0111
#define PUSH_BUTTONS_MASK 0x38  // 11 1000

#define INCREMENT_BUTTON  3
#define DECREMENT_BUTTON  4
#define RESET_BUTTON      5

void __main()
{
	uint8 count = 0;
	
	Port_Init(LCD_DATA);
	Port_Init(PORT_E);
	
	Port_SetPinDirection(LCD_DATA, PORT_PINS, PORT_PIN_OUT);
	Port_SetPinDirection(PORT_E, LCD_CRTL_MASK, PORT_PIN_OUT);
	Port_SetPinDirection(PORT_E, PUSH_BUTTONS_MASK, PORT_PIN_IN);
	
	Port_SetPinPullUp(PORT_E, PUSH_BUTTONS_MASK, 1);
	
	Timer_init();
	LCD_init();
	
	LCD_sendInt(count);
		
	for(;;)
	{
		if (!PushButton_readState(PORT_E, INCREMENT_BUTTON) == PRESSED)
		{
			//Wait for 0.2 second
			delay_ms(200);
			
			//Check if button is still pressed
			if (!PushButton_readState(PORT_E, INCREMENT_BUTTON) == PRESSED)
			{
				//Increment counter
				count++;
				
				//Clear the screen
				LCD_clearScreen();
				
				//Send the new counter
				LCD_sendInt(count);
			}
		}
		
		else if (!PushButton_readState(PORT_E, DECREMENT_BUTTON) == PRESSED)
		{
			//Decrement counter
			count--;
			
			//Clear the screen
			LCD_clearScreen();
			
			//Send the new counter
			LCD_sendInt(count);
			
			//Wait until button is released to prevent continuous pressing
			while(!PushButton_readState(PORT_E, DECREMENT_BUTTON) == PRESSED);
		}
		
		else if (!PushButton_readState(PORT_E, RESET_BUTTON) == PRESSED)
		{
			//Wait until button is released
			while(!PushButton_readState(PORT_E, RESET_BUTTON) == PRESSED);

			//Reset counter
			count = 0;
			
			//Clear the screen
			LCD_clearScreen();
			
			//Send the new counter
			LCD_sendInt(count);
		}
	}
}

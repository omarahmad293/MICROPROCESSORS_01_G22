#include "includes.h"

#define LCD_DATA          PORT_B
#define LCD_CRTL_MASK     0x07    // 00 0111
#define PUSH_BUTTONS_MASK 0x18    // 01 1000

#define INCREMENT_BUTTON  3
#define DECREMENT_BUTTON  4
#define RESET_BUTTON      5

void __main()
{
	uint16 count = 500;
	
	//Initialize PORT_B for LCD data
	Port_Init(LCD_DATA);
	
	//Initialize PORT_F for LCD control and 2 push buttons
	Port_Init(PORT_F);
	
	//Initialize pin 5 of PORT_A (PA5) for the third push button
	Pin_Init(PORT_A, 32);
	
	//Set the direction of the LCD pins to be output
	Port_SetPinDirection(LCD_DATA, PORT_PINS, PORT_PIN_OUT);
	Port_SetPinDirection(PORT_F, LCD_CRTL_MASK, PORT_PIN_OUT);
	
	//Set the direction of the push button pins to be input
	Port_SetPinDirection(PORT_F, PUSH_BUTTONS_MASK, PORT_PIN_IN);
  Port_SetPinDirection(PORT_A, 32, PORT_PIN_IN);
	
	//Enable the pullup resistors for the push buttons
	Port_SetPinPullUp(PORT_F, PUSH_BUTTONS_MASK, 1);
	Port_SetPinPullUp(PORT_A, 32, 1);

	//Initialize the timer
	Timer_init();
	
	//Initialize the LCD
	LCD_init();
	
	//Send the initial value to the LCD
	LCD_sendInt(count);
		
	//The main program
	for(;;)
	{
		//If the increment button is pressed
		if (!PushButton_readState(PORT_F, INCREMENT_BUTTON) == PRESSED)
		{
			//Wait for 0.2 second
			delay_ms(200);
			
			//Check if button is still pressed
			if (!PushButton_readState(PORT_F, INCREMENT_BUTTON) == PRESSED)
			{
				//Increment counter
				count++;
				
				//Clear the screen
				LCD_clearScreen();
				
				//Send the new counter
				LCD_sendInt(count);
			}
		}
		
		//If the decrement button is pressed
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
		
		//If the reset button is pressed
		else if (!PushButton_readState(PORT_A, RESET_BUTTON) == PRESSED)
		{
			//Wait until button is released
			while(!PushButton_readState(PORT_A, RESET_BUTTON) == PRESSED);

			//Reset the counter
			count = 0;
			
			//Clear the screen
			LCD_clearScreen();
			
			//Send the new counter
			LCD_sendInt(count);
		}
	}
}

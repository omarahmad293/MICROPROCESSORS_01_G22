#include "MCAL.h"
#include "tm4c123gh6pm.h"

void Port_SetPinDirection(uint8 port_index, uint8 pins_mask, Port_PinDirectionType pins_direction)
{
	volatile unsigned long* port;
	
	switch (port_index)
	{
		case 0: port = &GPIO_PORTA_DIR_R; break;
		case 1: port = &GPIO_PORTB_DIR_R; break;
		case 2: port = &GPIO_PORTC_DIR_R; break;
		case 3: port = &GPIO_PORTD_DIR_R; break;
		case 4: port = &GPIO_PORTE_DIR_R; break;
		case 5: port = &GPIO_PORTF_DIR_R; break;
	}
	
	switch(pins_direction)
	{
		case PORT_PIN_IN:
			(*port) &= ~(pins_mask);
			break;
		
		case PORT_PIN_OUT:
			(*port) |= pins_mask;
			break;
	}
	
}

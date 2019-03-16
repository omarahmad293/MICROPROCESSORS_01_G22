#include "PushButton.h"
#include "DIO.h"
#include "tm4c123gh6pm.h"

PushButton_State PushButton_readState(uint8 port_index, uint8 pin_index)
{
	uint16 i = 0;
		
	if(DIO_ReadPort(port_index, (1 << pin_index)))
	{
		for (i = 0; i < 10000; i++); //Delay
		if(DIO_ReadPort(port_index, (1 << pin_index))) //Debouncing check
		{
			return PRESSED;
		}
		return NOT_PRESSED;
	}
	return NOT_PRESSED;
}

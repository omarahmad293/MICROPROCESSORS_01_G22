#include "DIO.h"
#include "typedefs.h"
#include "tm4c123gh6pm.h"

//reads a pin and returns 1 or 0
uint8 DIO_ReadPort(uint8 port_index, uint8 pins_mask)
{
	switch(port_index)
	{
		case 0:
				if((GPIO_PORTA_DATA_R&pins_mask) == 0)
					return 0;
				else return 1;
				break;
		case 1:
				if((GPIO_PORTB_DATA_R&pins_mask) == 0)
					return 0;
				else return 1;
				break;
		case 2:
				if((GPIO_PORTC_DATA_R&pins_mask) == 0)
					return 0;
				else return 1;
				break;
		case 3:
				if((GPIO_PORTD_DATA_R&pins_mask) == 0)
					return 0;
				else return 1;
				break;
		case 4:
				if((GPIO_PORTE_DATA_R&pins_mask) == 0)
					return 0;
				else return 1;
				break;
		case 5:
				if((GPIO_PORTF_DATA_R&pins_mask) == 0)
					return 0;
				else return 1;
				break;
		default:
			return 0;
	}
}

//extra function that reads a pin and returns level type
Dio_LevelType DIO_ReadPort_level(uint8 port_index, uint8 pins_mask)
{
	switch(port_index)
	{
		case 0:
				if((GPIO_PORTA_DATA_R&pins_mask) == 0)
					return STD_LOW;
				else return STD_HIGH;
				break;
		case 1:
				if((GPIO_PORTB_DATA_R&pins_mask) == 0)
					return STD_LOW;
				else return STD_HIGH;
				break;
		case 2:
				if((GPIO_PORTC_DATA_R&pins_mask) == 0)
					return STD_LOW;
				else return STD_HIGH;
				break;
		case 3:
				if((GPIO_PORTD_DATA_R&pins_mask) == 0)
					return STD_LOW;
				else return STD_HIGH;
				break;
		case 4:
				if((GPIO_PORTE_DATA_R&pins_mask) == 0)
					return STD_LOW;
				else return STD_HIGH;
				break;
		case 5:
				if((GPIO_PORTF_DATA_R&pins_mask) == 0)
					return STD_LOW;
				else return STD_HIGH;
				break;
		default:
			return 0;
	}
}

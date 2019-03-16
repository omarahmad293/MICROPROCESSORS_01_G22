#include "DIO.h"


uint8 DIO_ReadPort(uint8 port_index, uint8 pins_mask)
{
	switch(port_index)
	{
		case 0:
				return GPIO_PORTA_DATA_R&pins_mask;
		case 1:
				return GPIO_PORTB_DATA_R&pins_mask;
		case 2:
				return GPIO_PORTC_DATA_R&pins_mask;
		case 3:
				return GPIO_PORTD_DATA_R&pins_mask;
		case 4:
				return GPIO_PORTE_DATA_R&pins_mask;
		case 5:
				return GPIO_PORTF_DATA_R&pins_mask;
		default:
			return 0;
	}
}


/*
uint8 DIO_ReadPort(uint8 port_index, uint8 pins_mask)
{
	switch(port_index)
	{
		case 0:
				if((GPIO_PORTA_DATA_R&pins_mask) == 0)
					return 0;
				else return 1;
		case 1:
				if((GPIO_PORTB_DATA_R&pins_mask) == 0)
					return 0;
				else return 1;
		case 2:
				if((GPIO_PORTC_DATA_R&pins_mask) == 0)
					return 0;
				else return 1;
		case 3:
				if((GPIO_PORTD_DATA_R&pins_mask) == 0)
					return 0;
				else return 1;
		case 4:
				if((GPIO_PORTE_DATA_R&pins_mask) == 0)
					return 0;
				else return 1;
		case 5:
				if((GPIO_PORTF_DATA_R&pins_mask) == 0)
					return 0;
				else return 1;
		default:
			return 0;
	}
}
*/
 
//extra function that reads a pin and returns level type
Dio_LevelType DIO_ReadPort_level(uint8 port_index, uint8 pins_mask)
{
	switch(port_index)
	{
		case 0:
				if((GPIO_PORTA_DATA_R&pins_mask) == 0)
					return STD_LOW;
				else return STD_HIGH;
		case 1:
				if((GPIO_PORTB_DATA_R&pins_mask) == 0)
					return STD_LOW;
				else return STD_HIGH;
		case 2:
				if((GPIO_PORTC_DATA_R&pins_mask) == 0)
					return STD_LOW;
				else return STD_HIGH;
		case 3:
				if((GPIO_PORTD_DATA_R&pins_mask) == 0)
					return STD_LOW;
				else return STD_HIGH;
		case 4:
				if((GPIO_PORTE_DATA_R&pins_mask) == 0)
					return STD_LOW;
				else return STD_HIGH;
		case 5:
				if((GPIO_PORTF_DATA_R&pins_mask) == 0)
					return STD_LOW;
				else return STD_HIGH;
		default:
			return 0;
	}
}

//write 0 or 1 on specific pin in PORT_X 
void DIO_WritePort(uint8 port_index, uint8 pins_mask, Dio_LevelType pins_level)
	{
			switch(port_index)
		{
			case 0:
				if(pins_level == STD_HIGH)
						GPIO_PORTA_DATA_R |= pins_mask;
				else 
						GPIO_PORTA_DATA_R &= ~pins_mask;
				break;
			case 1:
				if(pins_level == STD_HIGH)
						GPIO_PORTB_DATA_R |= pins_mask;
				else 
						GPIO_PORTB_DATA_R &= ~pins_mask;
				break;
			case 2:
				if(pins_level == STD_HIGH)
						GPIO_PORTC_DATA_R |= pins_mask;
				else 
						GPIO_PORTC_DATA_R &= ~pins_mask;
				break;
			case 3:
				if(pins_level == STD_HIGH)
						GPIO_PORTD_DATA_R |= pins_mask;
				else 
						GPIO_PORTD_DATA_R &= ~pins_mask;
				break;
			case 4:
				if(pins_level == STD_HIGH)
						GPIO_PORTE_DATA_R |= pins_mask;
				else 
						GPIO_PORTE_DATA_R &= ~pins_mask;
				break;
			case 5:
				if(pins_level == STD_HIGH)
						GPIO_PORTF_DATA_R |= pins_mask;
				else 
						GPIO_PORTF_DATA_R &= ~pins_mask;
				break;	
		}
	}
	//toggles pins for port_x
void DIO_FlipPort(uint8 port_index, uint8 pins_mask){
	switch (port_index){
		case 0:
			GPIO_PORTA_DATA_R  ^= pins_mask;
		case 1:
			GPIO_PORTB_DATA_R  ^= pins_mask;
		case 2:
			GPIO_PORTC_DATA_R  ^= pins_mask;
		case 3:
			GPIO_PORTD_DATA_R  ^= pins_mask;
		case 4:
			GPIO_PORTE_DATA_R  ^= pins_mask;
		case 5:
			GPIO_PORTF_DATA_R  ^= pins_mask;
	
	}

}
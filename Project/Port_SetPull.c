#include "typedefs.h"

//Ports
#define PORT_A 0
#define PORT_B 1
#define PORT_C 2
#define PORT_D 3
#define PORT_E 4
#define PORT_F 5

//GPIO PULL DOWN Register
#define GPIOPDR_PORT_A (*((volatile unsigned long *)0x40004514))
#define GPIOPDR_PORT_B (*((volatile unsigned long *)0x40005514))
#define GPIOPDR_PORT_C (*((volatile unsigned long *)0x40006514))
#define GPIOPDR_PORT_D (*((volatile unsigned long *)0x40007514))
#define GPIOPDR_PORT_E (*((volatile unsigned long *)0x40024514))
#define GPIOPDR_PORT_F (*((volatile unsigned long *)0x40025514))
//GPIO PULL UP Register
#define GPIOPUR_PORT_A (*((volatile unsigned long *)0x40004510))
#define GPIOPUR_PORT_B (*((volatile unsigned long *)0x40005510))
#define GPIOPUR_PORT_C (*((volatile unsigned long *)0x40006510))
#define GPIOPUR_PORT_D (*((volatile unsigned long *)0x40007510))
#define GPIOPUR_PORT_E (*((volatile unsigned long *)0x40024510))
#define GPIOPUR_PORT_F (*((volatile unsigned long *)0x40025510))

//Must have called Port_Init first for that specific port
void Port_SetPinPullUp(uint8 port_index, uint8 pins_mask, uint8 enable)
{
	volatile unsigned long* port;
	
	switch(port_index)
	{
		case PORT_A:
			port = &GPIOPUR_PORT_A;
			break;
		case PORT_B:
			port = &GPIOPUR_PORT_B;
			break;
		case PORT_C:
			port = &GPIOPUR_PORT_C;
		  break;
		case PORT_D:
			port = &GPIOPUR_PORT_D;
			break;
		case PORT_E:
			port = &GPIOPUR_PORT_E;
			break;
		case PORT_F:
			port = &GPIOPUR_PORT_F;
			break;
	}
	switch(enable)
	{
		case 0:
			(*port) &= ~(pins_mask);
			break;
		case 1:
			(*port) |= pins_mask;
			break;
	}
}
//Must have called Port_Init first for that specific port
void Port_SetPinPulldown(uint8 port_index, uint8 pins_mask, uint8 enable)
{
		volatile unsigned long* port;
		switch(port_index)
		{
			case PORT_A:
			port = &GPIOPDR_PORT_A;
			break;
		case PORT_B:
			port = &GPIOPDR_PORT_B;
			break;
		case PORT_C:
			port = &GPIOPDR_PORT_C;
		  break;
		case PORT_D:
			port = &GPIOPDR_PORT_D;
			break;
		case PORT_E:
			port = &GPIOPDR_PORT_E;
			break;
		case PORT_F:
			port = &GPIOPDR_PORT_F;
			break;
		}
		switch(enable)
		{
			case 0:
				(*port) &= ~(pins_mask);
				break;
			case 1:
				(*port) |= pins_mask;
				break;
		}
}
#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include "typedefs.h"
#include "tm4c123gh6pm.h"

typedef enum {
	NOT_PRESSED,
	PRESSED
} PushButton_State; 

PushButton_State PushButton_readState(uint8 port_index, uint8 pin_index);

#endif
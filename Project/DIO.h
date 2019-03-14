#ifndef DIO_H
#define DIO_H

#include "typedefs.h"

//define pin masks 
#define MASK_0	0b00000001
#define MASK_1	0b00000010
#define MASK_2	0b00000100
#define MASK_3	0b00001000
#define MASK_4	0b00010000
#define MASK_5	0b00100000
#define MASK_6	0b01000000
#define MASK_7	010000000

typedef enum {STD_LOW = 0, STD_HIGH = 1} Dio_LevelType; 

uint8 DIO_ReadPort(uint8 port_index, uint8 pins_mask);
Dio_LevelType DIO_ReadPort_level(uint8 port_index, uint8 pins_mask);
void DIO_WritePort(uint8 port_index, uint8 pins_mask, Dio_LevelType pins_level);
void DIO_FlipPort(uint8 port_index, uint8 pins_mask);


#endif

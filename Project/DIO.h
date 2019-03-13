#ifndef DIO_H
#define DIO_H

#include "typedefs.h"

typedef enum {STD_LOW = 0, STD_HIGH = 1} Dio_LevelType; 


uint8 DIO_ReadPort(uint8 port_index, uint8 pins_mask);
void DIO_WritePort(uint8 port_index, uint8 pins_mask, Dio_LevelType pins_level);
void DIO_FlipPort(uint8 port_index, uint8 pins_mask);


#endif

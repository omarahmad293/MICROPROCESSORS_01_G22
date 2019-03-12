#include "typedefs.h"

/*MCAL Drivers*/
void Port_Init(uint8 port_index);
void Port_SetPinDirection(uint8 port_index, uint8 pins_mask, Port_PinDirectionType pins_direction);
void Port_SetPinPullUp(uint8 port_index, uint8 pins_mask, uint8 enable);
void Port_SetPinPulldown(uint8 port_index, uint8 pins_mask, uint8 enable);

/*DIO Drivers*/
uint8 DIO_ReadPort(uint8 port_index, uint8 pins_mask);
void DIO_WritePort(uint8 port_index, uint8 pins_mask, Dio_LevelType pins_level);
void DIO_FlipPort(uint8 port_index, uint8 pins_mask);

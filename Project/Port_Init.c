#include "typedefs.h"
#include "GPIO.h"

/*
Initialize port based on selected port_index (0 to 5) by enabling
the clock, unlocking the port, and making the selected mode
digital
*/

//Control Register Initilization was added as it is not defined in other functions

//Look Page 656, 258, 340, 684, 685, 687, 671, 682, 688 in Datasheet



void Port_Init(uint8 port_index)
{
    //Initialize the Port by enabling the clock
    RCGCGPIO |= 1 << port_index;

    switch (port_index)
    {
    case PORT_A:
        GPIOLOCK_PORT_A = GPIOLOCK_KEY; //Unlocking the Port
        GPIOCR_PORT_A |= PORT_PINS;     //Allow Changes in the Port for later use as Pull-up/down Resistors
        GPIOAMSEL_PORT_A &= ~PORT_PINS; //Enable Digital Mode - (Disable Analog Mode)
        GPIOPCTL_PORT_A &= ~PORT_PINS;  //Enable I/O, Disable Functions
        GPIOAFSEL_PORT_A &= ~PORT_PINS;
        GPIODEN_PORT_A |= PORT_PINS; //Enable Digital Mode
        break;
    case PORT_B:
        GPIOLOCK_PORT_B = GPIOLOCK_KEY;
        GPIOCR_PORT_B |= PORT_PINS;
        GPIOAMSEL_PORT_B &= ~PORT_PINS;
        GPIOPCTL_PORT_B &= ~PORT_PINS;
        GPIOAFSEL_PORT_B &= ~PORT_PINS;
        GPIODEN_PORT_B |= PORT_PINS;
        break;
    case PORT_C:
        GPIOLOCK_PORT_C = GPIOLOCK_KEY;
        GPIOCR_PORT_C |= PORT_PINS;
        GPIOAMSEL_PORT_C &= ~PORT_PINS;
        GPIOPCTL_PORT_C &= ~PORT_PINS;
        GPIOAFSEL_PORT_C &= ~PORT_PINS;
        GPIODEN_PORT_C |= PORT_PINS;
        break;
    case PORT_D:
        GPIOLOCK_PORT_D = GPIOLOCK_KEY;
        GPIOCR_PORT_D |= PORT_PINS;
        GPIOAMSEL_PORT_D &= ~PORT_PINS;
        GPIOPCTL_PORT_D &= ~PORT_PINS;
        GPIOAFSEL_PORT_D &= ~PORT_PINS;
        GPIODEN_PORT_D |= PORT_PINS;
        break;
    case PORT_E:
        GPIOLOCK_PORT_E = GPIOLOCK_KEY;
        GPIOCR_PORT_E |= PORT_PINS;
        GPIOAMSEL_PORT_E &= ~PORT_PINS;
        GPIOPCTL_PORT_E &= ~PORT_PINS;
        GPIOAFSEL_PORT_E &= ~PORT_PINS;
        GPIODEN_PORT_E |= PORT_PINS;
        break;
    case PORT_F:
        GPIOLOCK_PORT_F = GPIOLOCK_KEY;
        GPIOCR_PORT_F |= PORT_PINS;
        GPIOAMSEL_PORT_F &= ~PORT_PINS;
        GPIOPCTL_PORT_F &= ~PORT_PINS;
        GPIOAFSEL_PORT_F &= ~PORT_PINS;
        GPIODEN_PORT_F |= PORT_PINS;
        break;
    }
}

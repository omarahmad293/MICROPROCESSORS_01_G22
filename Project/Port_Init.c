/*
Initialize port based on selected port_index (0 to 5) by enabling
the clock, unlocking the port, and making the selected mode
digital
*/

//Control Register Initilization was added as it is not defined in other functions

//Look Page 656, 258, 340, 684, 685, 687 in Datasheet

#define RCGCGPIO (*((volatile unsigned long *)0x400FE608))

#define PORT_A 0
#define PORT_B 1
#define PORT_C 2
#define PORT_D 3
#define PORT_E 4
#define PORT_F 5

//GPIO Lock APB Mode
#define GPIOLOCK_PORT_A (*((volatile unsigned long *)0x40004520))
#define GPIOLOCK_PORT_B (*((volatile unsigned long *)0x40005520))
#define GPIOLOCK_PORT_C (*((volatile unsigned long *)0x40006520))
#define GPIOLOCK_PORT_D (*((volatile unsigned long *)0x40007520))
#define GPIOLOCK_PORT_E (*((volatile unsigned long *)0x40024520))
#define GPIOLOCK_PORT_F (*((volatile unsigned long *)0x40025520))

#define GPIOLOCK_KEY 0x4C4F434B

//GPIO Control Register - APB Mode
#define GPIOCR_PORT_A (*((volatile unsigned long *)0x40004524))
#define GPIOCR_PORT_B (*((volatile unsigned long *)0x40005524))
#define GPIOCR_PORT_C (*((volatile unsigned long *)0x40006524))
#define GPIOCR_PORT_D (*((volatile unsigned long *)0x40007524))
#define GPIOCR_PORT_E (*((volatile unsigned long *)0x40024524))
#define GPIOCR_PORT_F (*((volatile unsigned long *)0x40025524))

//GPIO Analog Mode Select - APB Mode
#define GPIOAMSEL_PORT_A (*((volatile unsigned long *)0x40004528))
#define GPIOAMSEL_PORT_B (*((volatile unsigned long *)0x40005528))
#define GPIOAMSEL_PORT_C (*((volatile unsigned long *)0x40006528))
#define GPIOAMSEL_PORT_D (*((volatile unsigned long *)0x40007528))
#define GPIOAMSEL_PORT_E (*((volatile unsigned long *)0x40024528))
#define GPIOAMSEL_PORT_F (*((volatile unsigned long *)0x40025528))

#define PORT_PINS 0xFF

void Port_Init(uint8 port_index)
{
    //Initialize the Port by enabling the clock
    RCGCGPIO |= 1 << port_index;

    //Unlocking the Port
    switch (port_index)
    {
    case PORT_A:
        GPIOLOCK_PORT_A = GPIOLOCK_KEY;
        break;
    case PORT_B:
        GPIOLOCK_PORT_B = GPIOLOCK_KEY;
        break;
    case PORT_C:
        GPIOLOCK_PORT_C = GPIOLOCK_KEY;
        break;
    case PORT_D:
        GPIOLOCK_PORT_D = GPIOLOCK_KEY;
        break;
    case PORT_E:
        GPIOLOCK_PORT_E = GPIOLOCK_KEY;
        break;
    case PORT_F:
        GPIOLOCK_PORT_F = GPIOLOCK_KEY;
        break;
    }

    //Allow Changes in the Port for later use as Pull-up/down Resistors
    switch (port_index)
    {
    case PORT_A:
        GPIOCR_PORT_A |= PORT_PINS;
        break;
    case PORT_B:
        GPIOCR_PORT_B |= PORT_PINS;
        break;
    case PORT_C:
        GPIOCR_PORT_C |= PORT_PINS;
        break;
    case PORT_D:
        GPIOCR_PORT_D |= PORT_PINS;
        break;
    case PORT_E:
        GPIOCR_PORT_E |= PORT_PINS;
        break;
    case PORT_F:
        GPIOCR_PORT_F |= PORT_PINS;
        break;
    }

    //Select Digital Mode - (Disable Analog Mode)
    switch (port_index)
    {
    case PORT_A:
        GPIOAMSEL_PORT_A &= ~PORT_PINS;
        break;
    case PORT_B:
        GPIOAMSEL_PORT_B &= ~PORT_PINS;
        break;
    case PORT_C:
        GPIOAMSEL_PORT_C &= ~PORT_PINS;
        break;
    case PORT_D:
        GPIOAMSEL_PORT_D &= ~PORT_PINS;
        break;
    case PORT_E:
        GPIOAMSEL_PORT_E &= ~PORT_PINS;
        break;
    case PORT_F:
        GPIOAMSEL_PORT_F &= ~PORT_PINS;
        break;
    }
}

#ifndef GPIO_H
#define GPIO_H

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

//I/O Enable, Function Disable - APB Mode
#define GPIOPCTL_PORT_A (*((volatile unsigned long *)0x4000452C))
#define GPIOPCTL_PORT_B (*((volatile unsigned long *)0x4000552C))
#define GPIOPCTL_PORT_C (*((volatile unsigned long *)0x4000652C))
#define GPIOPCTL_PORT_D (*((volatile unsigned long *)0x4000752C))
#define GPIOPCTL_PORT_E (*((volatile unsigned long *)0x4002452C))
#define GPIOPCTL_PORT_F (*((volatile unsigned long *)0x4002552C))

#define GPIOAFSEL_PORT_A (*((volatile unsigned long *)0x40004420))
#define GPIOAFSEL_PORT_B (*((volatile unsigned long *)0x40005420))
#define GPIOAFSEL_PORT_C (*((volatile unsigned long *)0x40006420))
#define GPIOAFSEL_PORT_D (*((volatile unsigned long *)0x40007420))
#define GPIOAFSEL_PORT_E (*((volatile unsigned long *)0x40024420))
#define GPIOAFSEL_PORT_F (*((volatile unsigned long *)0x40025420))

//GPIO Digital Enable - APB Mode
#define GPIODEN_PORT_A (*((volatile unsigned long *)0x4000451C))
#define GPIODEN_PORT_B (*((volatile unsigned long *)0x4000551C))
#define GPIODEN_PORT_C (*((volatile unsigned long *)0x4000651C))
#define GPIODEN_PORT_D (*((volatile unsigned long *)0x4000751C))
#define GPIODEN_PORT_E (*((volatile unsigned long *)0x4002451C))
#define GPIODEN_PORT_F (*((volatile unsigned long *)0x4002551C))

#define PORT_PINS 0xFF

#endif

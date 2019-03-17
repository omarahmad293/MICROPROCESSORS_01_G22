#ifndef TIMER_H
#define TIMER_H

#include "typedefs.h"
#include "tm4c123gh6pm.h"

//Defines for Timer0 Delay
#define GPTMTAILR_0 (*((volatile unsigned long *)0x40030028)) //Load Register
#define GPTMCTL_0 (*((volatile unsigned long *)0x4003000C))   //Timer Control
#define GPTMRIS_0 (*((volatile unsigned long *)0x4003001C))   //Raw Interrupt Status
#define GPTMICR_0 (*((volatile unsigned long *)0x40030024))   //Clear Interrupt Status

#define TAEN 0     //Enable bit in Control Register
#define TATORIS 0  //Timer A Interrupt Bit
#define TATOCINT 0 //Clear Timer A Interrupt Status Bit
#define TIMER_FREQ 16000000

void Timer_init(void);
void delay_ms(uint32 value);
void delay_us(uint32 value);

#endif

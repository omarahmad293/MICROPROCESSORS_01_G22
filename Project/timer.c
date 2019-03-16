#include "timer.h"

// Initialize and configure 16/32-bit TIMERA0 to work on One-Shot mode
void OneShotTimer_init()
{
		RCGCTIMER |= (1<<0); // enable timer 0
		GPTMCTL &= ~(1<<TAEN); // disable the timer before making any changes (for safety)
		GPTMCFG = 0x0000.0000;
		GPTMTAMR |= (0x1<<0); // set timer mode to be One-Shot mode 
		GPTMTAMR &= ~ (1<<4); // set timer to be count down timer 
}

/*
void delay(uint8 value);
{
		GPTMTAILR = // load the value which will count from
		GPTMCTL |= (1<<TAEN); // start the timer

	//Poll the GPTMRIS register or wait for the interrupt to be generated (if enabled). In both cases,
	//the status flags are cleared by writing a 1 to the appropriate bit of the GPTM Interrupt Clear
	//Register (GPTMICR).

}
*/
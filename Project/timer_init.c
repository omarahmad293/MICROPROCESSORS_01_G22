#include "timer.h"

//This Code will be Initialize and configure 16/32-bit TIMERA0 to work on One-Shot mode
//Look on the Datasheet on section 11.4 

void Timer_init(void)
{
	//To use a GPTM, the appropriate TIMERA (R0) bit must be set in the RCGCTIMER	
	SYSCTL_RCGCTIMER_R |= (1<<0); 
		
	//Ensure the timer is disabled (the TAEN bit in the GPTMCTL register is cleared) before making
	//any changes
	TIMER0_CTL_R &= ~(1<<TAEN); 
	
	//Write the GPTM Configuration Register (GPTMCFG) with a value of 0x0000.0000
	TIMER0_CFG_R = 0x00000000;
		
	//Configure the TAMR field in the GPTM Timer n Mode Register (GPTMTAMR)
	//Write a value of 0x1 for One-Shot mode
	TIMER0_TAMR_R |= (0x1<<0);  
		
	//Set timer to be count down timer 
	//TIMER0_TAMR_R &= ~ (1<<4); 
	TIMER0_TAMR_R |=  (1<<4);
}

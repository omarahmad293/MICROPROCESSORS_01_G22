#include "timer.h"

//This Code will be implementing the delay fuction using the timer's One Shot Mode
//We will be working on Timer0 A-Full Register
//Look th Datasheet pages 123, 137, 704, 709, 722

void delay_ms(uint16 value)
{
    //Load the start value into theGPTM Timer n Interval Load Register (GPTMTnILR). Look Page 756
    GPTMTAILR_0 = (value * TIMER_FREQ) / 1000;

    //Set theTnENbit in theGPTMCTLregister to enable the timer and start counting. Look Page 737
    GPTMCTL_0 |= (1 << TAEN);

    //Poll theGPTMRISregister, the status flags are cleared by writing a 1 to the appropriate bit of theGPTM Interrupt ClearRegister (GPTMICR). Look Page 748
    while (!(GPTMRIS_0 & (1 << TATORIS)))
        ;

    //Clear the Status flag by setting it to 1 in the interrupt clear register, for later uses Look Page 754
    GPTMICR_0 |= (1 << TATOCINT);
}

void delay_us(uint16 value)
{
    //Load the start value into theGPTM Timer n Interval Load Register (GPTMTnILR). Look Page 756
    GPTMTAILR_0 = (value * TIMER_FREQ) / (1000 * 1000);

    //Set theTnENbit in theGPTMCTLregister to enable the timer and start counting. Look Page 737
    GPTMCTL_0 |= (1 << TAEN);

    //Poll theGPTMRISregister, the status flags are cleared by writing a 1 to the appropriate bit of theGPTM Interrupt ClearRegister (GPTMICR). Look Page 748
    while (!(GPTMRIS_0 & (1 << TATORIS)))
        ;

    //Clear the Status flag by setting it to 1 in the interrupt clear register, for later uses Look Page 754
    GPTMICR_0 |= (1 << TATOCINT);
}

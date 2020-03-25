#ifndef switches_included
#define switches_included

#define SW1 BIT0
#define SW2 BIT1
#define SW3 BIT2
#define SW4 BIT3
#define SWITCHES (SW1|SW2|SW3|SW4)  /*intializing all 4 swithches     */

void switch_init();
void switch_interrupt_handler();

extern char switch_state_down, switch_state_changed, state1, state2, state3, state4; // 4 states

#endif 

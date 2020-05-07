#include <msp430.h>
#include "switches.h"
#include "stateMachines.h"
#include "buzzer.h"
#include "led.h"

char state1, state2, state3,state4,switch_state_changed;

static char switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES); /* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES); /* if down, sense up */
  return p2val;
}


/*setting up the switch */ 
void switch_init()

{
  P2REN |= SWITCHES; /* enables resistors for switches */
  P2IE = SWITCHES; /* enable interrupts from switches */
  P2OUT |= SWITCHES; /*pull-ups for switches */
  P2DIR &= ~SWITCHES; /* set switches bits for input */
  switch_update_interrupt_sense();
  
  led_update();
}

void switch_interrupt_handler()
{

  /* switches on the toy */
  char p2val = switch_update_interrupt_sense();
  

  /* 4 states or switches, checking if running or not */ 
  state1 = (p2val & SW1) ? 0 : SW1;
  state2 = (p2val & SW2) ? 0 : SW2;
  state3 = (p2val & SW3) ? 0 : SW3;
  state4 = (p2val & SW4) ? 0 : SW4;
  
  /* play one song */
  if(state1){
    sound();
  }
  /* have green light flicker while red stays on */
  if(state2){
   
    enableWDTInterrupts(); // turns on leds
    
  }
  /*same as state 2 but buzzer sound */
  if(state3){
    enableWDTInterrupts();
    buzzer_set_period(1000);
    
  }
  
  if(state4){
    greenOn();
    buzzer_set_period(800);
  }
    
}

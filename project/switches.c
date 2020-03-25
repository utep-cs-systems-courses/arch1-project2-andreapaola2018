#include <msp430.h>
#include "switches.h"
#include "stateMachines.h"
#include "buzzer.h"
#include "led.h"

char switch_state_down, switch_state_changed;

statich char switch_update_interrupt_sense()
{
  char p2val = P2IN;
  P2IES |= (p2val & SWITCHES);
  P2IES &= (p2val | ~SWITCHES);
  return p2val;
}

void switch_init()

{
  P2REN |= switches;
  P2IE = SWITCHES;
  P2OUT |= SWITCHES;
  P2DIR &= ~SWITCHES;
  switch_update_interrupt_sense();
  state_zero();
}

void switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();
  switch_state_changed = 1; // state has changed

  /* 4 states, checking if running or not */ 
  state1 = (p2val & SW1) ? 0 : 1;
  state2 = (p2val & SW2) ? 0 : 1;
  state3 = (p2val & SW3) ? 0 : 1;
  state4 = (p2val & SW4) ? 0 : 1;

  if(state1) {
    switch_state_down = state1;
    switch_state_changed = 1;
    /* call to song sound */

    
  }
  else if(state2) {
    switch_state_down = state2;
    switch_state_changed = 1;
    /*   */
  }
  else if(state3) {
    switch_state_down = state3;
    switch_state_changed = 1; 
  }

  else if(state4) {
    switch_state_down = state4;
    switch_state_changed = 1; 
  }

  else{
    switch_state_down = state4;
    switch_state_changed = 1; 
  }

  else{
    switch_state_down = 0;
    switch_state_changed = 1; 

  }
}

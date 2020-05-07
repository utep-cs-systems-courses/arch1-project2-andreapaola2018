
#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"

/* toggles red light */
char toggle_red()
{
  static char state = 0;

  switch (state) {
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 0;
    state = 0;
    break;
  }
  return 1;
}

char toggle_green()

{
  char changed = 0;
  if(red_on){
    green_on ^= 1;
    changed = 1;
  }
  return changed;
}

/* switch case for all states */
/* Creates different light patterns for the different states and different sounds */
void state_advance()
{

  char state = 0;

  switch(state) {

    // state 1
  case 1:
    red_on = 0;
    green_on = 1;
    state = 1;
    led_update();
    break;

  case 2:
    toggle_green();
    buzzer_set_period(790);
    state = 2;
    led_update();
    break;
    
  case 3:
    toggle_red();
    state = 3;
    led_update();
    break;
    
  case 4:
    green_on = 1;
    red_on = 1;
    state =4;
    led_update();
    break;
  }

  
  }


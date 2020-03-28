#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "stateMachines.h"

void buzzer_init()
{
  timerAUpmode();  /* used to drive speaker */ 
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;  /* enable output to speaker (P2.6) */
}

void buzzer_set_period(short cycles) /* buzzer clock = 2MHz (period of 1k results in 2kHz tone) */
{
  CCR0 = cycles;
  CCR1 = cycles >> 1; /* one ahlf cycle */
}

void sound(){

  int i = 0;
  int sounds[] ={150, 1000, 900, 700, 805}; // different pitches of sound for buzzer

  while(i < sizeof(sounds))
  {
    buzzer_set_period(sounds[i]);
    state_advance();
    i++;
  }
}

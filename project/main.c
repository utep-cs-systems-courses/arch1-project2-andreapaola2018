#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

/* sets clocks, and interrupts */ 
int main(void) {
  configureClocks(); // setting CPU and clocks 
  led_init();
  enableWDTInterrupts();
  switch_init();/* initiating switches */
  buzzer_init(); /* initiating buzzer  */  
  

  or_sr(0x18);
}

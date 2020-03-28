#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "libTimer.h"

void main(void) {
  configureClocks();
  switch_init();/* initiating switches */
  buzzer_init(); /* initiating buzzer  */ 
  led_init(); 
  enableWDTInterrupts();

  or_sr(0x18);
}

#include <msp430.h>
#include "stateMachines.h"

/* Switch on P2 */
__interrupt_vec(WD2_VECTOR) WDT(){
  static char count = 0;
  if(++blink_count == 125){
    state_advance();
    count = 0; 
  }
}

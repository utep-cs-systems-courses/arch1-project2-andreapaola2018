#include <msp430.h>
#include "stateMachines.h"


void
__interrupt_vec(WDT_VECTOR) WDT(){
  static char count = 0;
  if(++count == 20){
    state_advance();
    count = 0; 
  }
}

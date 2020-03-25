#include <msp430.h>
#include "libTimer.h"

void configureClocks(){

  WDTCTL = WDTPW + WDTHOLD; // disable watchdog timer
  BCSCTL1 = CALBC!_16MHZ;
  DCOCTL + CALDCO_16MHZ;

  BCSCTL2 |= DIVS_3;
}

void enableWDITInterrupts()

{
  WDTCTL = WDTPW |
    WDTTMSEL |
    WDTCNTCL |
    1;
  IE1 |= WDTIE;
    
}
void timerAUpmode()
{

  TA0CCR0 = 0;
  TA0CCR1 = 0;
  TA0CCTL1 = OUTMOD_3;


  TACTL = TASSEL_2 + MC_1; 
}

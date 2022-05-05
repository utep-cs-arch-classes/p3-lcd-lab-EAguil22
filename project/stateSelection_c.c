#include <msp430.h>
#include "states.h"
#include "buzzer.h"
#include "switches.h"


void stateSelection(void){
  switch(state){

  case 1:
    buzzer_set_period(250);
    break;

  case 2:
    switch_interrupt_handler();
    playgame();
    break;

  case 3:
    switch_interrupt_handler();
    win();
    break;

  case 4:
    switch_interrupt_handler();
    lose();

  default:
    playgame();
    
  }

}

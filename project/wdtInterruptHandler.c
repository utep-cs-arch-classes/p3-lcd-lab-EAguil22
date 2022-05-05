#include <msp430.h>
#include "libTimer.h"
#include "draw_shapes.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "states.h"
#include "buzzer.h"

// function that handles interrupts
// from the periodic timer
// The timer fires an event 250 times/sec

void
__interrupt_vec(WDT_VECTOR) WDT()
{
  const  u_int second_limit = 100;
  static u_int second_count = 0;

  second_count++;

  if (second_count >= second_limit) {
    if (count == 0){
      state = 1;
    }
    
    if (count >= 25){
      state = 3;
    }
    
    
    draw_moving_shapes();

    // stateSelection();
   
    second_count = 0;
  }

  stateSelection();
  
} 


#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "draw_shapes.h"

#include "buzzer.h"
#include "switches.h"

// WARNING: LCD DISPLAY USES P1.0.  Do not touch!!! 

void main()
{
  
  
  configureClocks();
  lcd_init();
  buzzer_init();
  switch_init();
  
  clearScreen(background_color);

  init_shapes();
  
  enableWDTInterrupts();      /**< enable periodic interrupt */
  // or_sr(0x8);              /**< GIE (enable interrupts) */

  or_sr(0x18);
  
  /*
  while(1){
    if(redrawScreen){
      redrawScreen = 0;
      draw_moving_shapes();
    }
    P1OUT &= ~LED;
    or_sr(0x10);
    P1OUT |= LED;
    }*/
  
}

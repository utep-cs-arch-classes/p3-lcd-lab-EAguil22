#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "draw_shapes.h"

#include "buzzer.h"

// WARNING: LCD DISPLAY USES P1.0.  Do not touch!!! 

void main()
{
  
  configureClocks();
  lcd_init();
  buzzer_init();
  clearScreen(background_color);

  init_shapes();
  
  enableWDTInterrupts();      /**< enable periodic interrupt */
  or_sr(0x8);	              /**< GIE (enable interrupts) */
  
 
  
}

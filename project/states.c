#include <msp430.h>
#include "switches.h"
#include "buzzer.h"
#include "lcdutils.h"
#include "states.h"
#include "draw_shapes.h"
#include "lcddraw.h"

void playgame(void){
  
  if(switch1_down){
    //write rebuilding
    buzzer_set_period(250);
    drawString5x7(5, 30, "Rebuilding Road", COLOR_WHITE, COLOR_BLACK);
    draw_road();
    //redrawScreen = 1;
    switch1_down = 0;
    
  }
  
  if(switch2_down){
    //write rebuilding
    buzzer_set_period(250);
    drawString5x7(5, 30, "Rebuilding Roof", COLOR_WHITE, COLOR_BLACK);
    draw_roof();
    //redrawScreen = 1;
    switch2_down = 0;
    
  }

  if(switch3_down){
    //write rebuilding
    buzzer_set_period(250);
    drawString5x7(5, 30, "Rebuilding House", COLOR_WHITE, COLOR_BLACK);
    draw_house();
    //redrawScreen = 1;
    switch3_down = 0;
    
  }
  if(switch4_down){
    //give up option
    drawString5x7(5, 20, "You Cower before the Sun", COLOR_WHITE, COLOR_BLACK); 
    state = 4;
    //redrawScreen = 1;
    switch4_down = 0;
  }
  
}

void lose(void){
  buzzer_set_period(1000);
  switch4_down = 0;
  drawString5x7(5, 5, "The Sun Burned All", COLOR_RED, COLOR_BLACK);

  drawString5x7(5, 90, "Try Again?", COLOR_WHITE, COLOR_BLACK);
  
  if (switch1_down || switch2_down || switch3_down || switch4_down){
    
    // init_shapes();
    count = 0;
    state = 2;
    
    }
  
}

void win(void){

  drawString5x7(5, 5, "YOU SURVIVED", COLOR_WHITE, COLOR_BLACK);

  drawString5x7(5, 90, "Try Again?", COLOR_WHITE, COLOR_BLACK);

  if (switch1_down || switch2_down || switch3_down || switch4_down){
    // init_shapes();
    count = 0;
    state = 2;
  }

}

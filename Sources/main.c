#include  "..\Project_Headers\api.h"    		// private library - API layer
#include  "..\Project_Headers\app.h"    		// private library - APP layer

enum FSMstate state;
enum SYSmode lpm_mode;

void main(void){
  
  state = state0;  // start in idle state on RESET
  lpm_mode = mode0;     // start in idle state on RESET
  sysConfig();
  char id[] = {2,0,5,8,8,7,4,2,5};
  char powerOf2[] = {1,2,4,8,16,32,64,128};
  
  while(1){
	switch(state){
	  case state0:
		//printSWs2LEDs();
        enterLPM(lpm_mode);
		break;
		 
	  case state1:
		//disable_interrupts();
		
		printArr2SWs(id, 9, 1024000, 0);
		
		//enable_interrupts();
		state = state0;
		break;
		 
	  case state2:
		//disable_interrupts();
		
		printArr2SWs(powerOf2, 8, 1024000, 1);
		
		//enable_interrupts();
		state = state0;
		break;
		
	  case state3:
	  		//disable_interrupts();
		  
		    pwm(422, 0.75); //
	  		
	  		//enable_interrupts();
	  		//state = state0;
	  		break;
		
	}
  }
}
  
  
  
  
  
  

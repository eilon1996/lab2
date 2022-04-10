#include  "..\Project_Headers\api.h"    		// private library - API layer
#include  "..\Project_Headers\app.h"    		// private library - APP layer

enum FSMstate state;
enum SYSmode lpm_mode;

void main(void){
  static int[] idNum = {2, 0, 8, 7, 2, 5, 2, 1, 8};
  state = state0;       // start in idle state on RESET
  lpm_mode = mode0;     // start in idle state on RESET
  sysConfig();
  
  while(1){
	switch(state){
	case state0:		
		enterLPM(lpm_mode);
		break;
		 
	case state1:
	{
		disable_interrupts();
		showArrayOnLEDS(idNUM, 9);
		enable_interrupts();
		break;
	}
	case state2:
	{
		disable_interrupts();

        static int val = 1;         // Static variable is used to resume the bit-skipping from the last bit it skipped
		int counter = 0;			// Allows counting 7 seconds of led bit-skipping

        while (counter < 14){
			setLEDs((char)val);
			//timerDelay(0.5);		// 0.5 [s] delay
			val = (val==128) ? 1 : val*2;		// 128 is the maximum single bit value on a 8-bit 											register; allows a cyclic skip
		}

        enable_interrupts();
		break;
	}
	
	case state3:
	{	
		while(1){
			setOP(7);	  		  // setting PTD.7 pin to logic 1
			timerDelay(0.001875); // generating 75% duty cycle
			toggleOP(7);		  // toggling PTD.7 pin to 0;
			timerDelay(0.000625); // 15% low value
		}
		break;
	}	
	
  	}
}
  
  
  
  
  
  

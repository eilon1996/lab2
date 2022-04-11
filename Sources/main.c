#include  "..\Project_Headers\api.h"    		// private library - API layer
#include  "..\Project_Headers\app.h"    		// private library - APP layer

enum FSMstate state;
enum SYSmode lpm_mode;

char id[9] = {2,0,6,9,0,3,4,4,5};

void main(void){

  state = state0;  // start in idle state on RESET
  lpm_mode = mode0;     // start in idle state on RESET
  sysConfig();

  while(1){
	switch(state){
	  case state0:
		printSWs2LEDs();
        enterLPM(lpm_mode);
		break;


	  case state1:
		disable_interrupts();
		printArr2SWs(id, 9, HALF_SEC_DELAY);
		enable_interrupts();
		break;

	  case state2:
		disable_interrupts();
		printLedsOneByOne(14, HALF_SEC_DELAY);
		enable_interrupts();
		break;

	  case state3:
		while(1){
			print2LEDs(0x01);
			delay(LEDs_SHOW_RATE);		// delay of 62.5 [ms]
			print2LEDs(0x00);
			delay(LEDs_SHOW_RATE/3);
		}
		break;

	}
  }
}







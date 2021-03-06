#include  "..\Project_Headers\api.h"    		// private library - API layer
#include  "..\Project_Headers\app.h"    		// private library - APP layer

#define ID_LEN 9
#define PWM_PIN 7
#define PWM_RATE 4 // *KILO
#define DUTY_CYCLE 0.75
#define STATE2_REPEATS 14

enum FSMstate state;
enum SYSmode lpm_mode;



char id[ID_LEN] = {2,0,6,9,0,3,4,4,5};

void main(void){

  state = state0;  // start in idle state on RESET
  lpm_mode = mode0;     // start in idle state on RESET
  sysConfig();

  while(1){
	switch(state){
	  case state0:
		print2LEDs(0x00);
        enterLPM(lpm_mode);
		break;


	  case state1:
		disable_interrupts();
		printArr2SWs(id, ID_LEN, 0.5);
		enable_interrupts();
		break;

	  case state2:
		disable_interrupts();
		printLedsOneByOne(STATE2_REPEATS, 0.5);
		enable_interrupts();
		break;

	  case state3: // interrupt is enabled
	  	doPWMPortD(PWM_PIN, PWM_RATE, DUTY_CYCLE);
		break;

	}
  }
}







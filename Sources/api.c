#include  "..\Project_Headers\api.h"    		// private library - API layer
#include  "..\Project_Headers\halGPIO.h"     // private library - HAL layer

//-------------------------------------------------------------
//            Print SWs value onto LEDs
//-------------------------------------------------------------
void printSWs2LEDs(void){
	unsigned char ch;

	ch = readSWs();
	print2LEDs(ch);

}
//--------------------------------------------------------------------
//            Print array to LEDs array with rate of LEDs_SHOW_RATE
//--------------------------------------------------------------------
void printArr2SWs(char Arr[], int size, float seconds){
	unsigned int i;

	for(i=0; i<size; i++){
		print2LEDs(Arr[i]);
		delaySec(seconds);
	}
}

void printLedsOneByOne(int repeatTimes, float seconds){
	static unsigned int bit;
	int counter;

	for(counter=0; counter<repeatTimes; bit = (bit+1)%8, counter++){
		print2LEDs(1 << bit);
		delaySec(seconds);
	}
}

void doPWMPortB(unsigned int bitNum, float rate, float dutyCycle){
	int timeOn  = (int)(dutyCycle*FREQ_TO_TIME(rate));
	int timeOff = (int)((1-dutyCycle)*FREQ_TO_TIME(rate));
	while(1){
		print2PortB(BIT(bitNum));
		delaySec(timeOn);
		print2PortB(BIT(bitNum));
		delaySec(timeOff);
	}
}




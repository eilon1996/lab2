#include  "..\Project_Headers\api.h"    		// private library - API layer
#include  "..\Project_Headers\halGPIO.h"     // private library - HAL layer

int count = 0;
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
/*
void printArr2SWs(char Arr[], int size, unsigned int rate, int flag){
	unsigned int i;

	if(flag) {
		for(i = 0; i < 14; i++){
				print2LEDs(Arr[count%8]);
				delay(rate);
				count++;
			}
*/
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

void doPWMPortD(unsigned int bitNum, float rate, float dutyCycle){
	float timeOn  = dutyCycle*FREQ_TO_TIME(rate);   // give run time error for some reason
	float timeOff = (1-dutyCycle)*FREQ_TO_TIME(rate);
	//float timeOn = 2;
	//float timeOff = 1;
	while(1){
		setPortxOutputData(PORT_D, BIT(bitNum));	// doesnt work
		delaySec(timeOn);
		setPortxOutputData(PORT_D, 0);
		delaySec(timeOff);
	}

}




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
void printArr2SWs(char Arr[], int size, unsigned int rate){
	unsigned int i;

	for(i=0; i<size; i++){
		print2LEDs(Arr[i]);
		delay(rate);
	}
}

void printLedsOneByOne(int repeatTimes, unsigned int rate){
	static unsigned int bit;
	int counter;

	for(counter=0; counter<14; bit = (bit+1)%8){
		print2LEDs(1 << bit);
		delay(rate);
	}
}






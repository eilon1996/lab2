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
void printArr2SWs(char Arr[], int size, unsigned int rate, int flag){
	unsigned int i;
	
	if(flag) {
		for(i = 0; i < 14; i++){
				print2LEDs(Arr[count%8]);
				delay(rate);
				count++;
			}
	}
	else {
		for(i = 0; i < size; i++){
				print2LEDs(Arr[i]);
				delay(rate);
			}
	}
	
}


 
  


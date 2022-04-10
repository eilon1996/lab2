#include  "..\Project_Headers\api.h"    		// private library - API layer
#include  "..\Project_Headers\halGPIO.h"     // private library - HAL layer

//--------------------------------------------------------------------
//            Print array to LEDs array with rate of LEDs_SHOW_RATE
//--------------------------------------------------------------------            
void showArrayOnLEDS(int Arr[], int size){
    for (int i = 0; i < size; i++){
        setLEDs((char)Arr[i]);
        //delay(LEDs_SHOW_RATE); // delay of 62.5 [ms]
        //timerDelay(0.5);		 // 0.5 [s] delay
    }
}


 
  


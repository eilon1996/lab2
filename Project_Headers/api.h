#ifndef _api_H_
#define _api_H_

#include  "..\Project_Headers\halGPIO.h"     // private library - HAL layer


extern void printSWs2LEDs(void);
extern void printArr2SWs(char Arr[], int size, float seconds);
extern void printLedsOneByOne(int repeatTimes, float seconds);
extern void doPWMPortB(unsigned int bitNum, float rate, float dutyCycle);


#endif








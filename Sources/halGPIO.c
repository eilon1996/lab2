#include  "..\Project_Headers\halGPIO.h"     // private library - HAL layer
#include  "..\Project_Headers\bsp.h"     // private library - HAL layer

//--------------------------------------------------------------------
//             System Configuration
//--------------------------------------------------------------------
void sysConfig(void){
	GPIOconfig();
	TIMERconfig();
	ADCconfig();
}

//--------------------------------------------------------------------
// 				Print Byte to port B array
//--------------------------------------------------------------------
void print2PortB(unsigned char ch){
	GPIOB_PDOR = ch & 0xFF;
	// LEDsArrPortWrite(ch);
}
//--------------------------------------------------------------------
// 				Print Byte to 8-bit LEDs array
//--------------------------------------------------------------------
void print2LEDs(unsigned char ch){
	GPIOB_PDOR = (ch & 0xF) + (ch*16 & 0xF00);
	// LEDsArrPortWrite(ch);
}

void pwm(unsigned int t, float dutycycle){  // t[msec]
	GPIOD_PSOR = 0x80;
	delay(dutycycle*t);
	GPIOD_PCOR = 0x80;
	delay((1-dutycycle)*t);
}
//--------------------------------------------------------------------
//				Clear 8-bit LEDs array
//--------------------------------------------------------------------
void clrLEDs(void){
	LEDsArrPortClear(0x00);
}
//--------------------------------------------------------------------
//				Toggle 8-bit LEDs array
//--------------------------------------------------------------------
void toggleLEDs(char ch){
	LEDsArrPortToggle(ch);
}
//--------------------------------------------------------------------
//				Set 8-bit LEDs array
//--------------------------------------------------------------------
void setLEDs(char ch){
	LEDsArrPortSet(ch);
}
//--------------------------------------------------------------------
//				Read value of 4-bit SWs array
//--------------------------------------------------------------------
unsigned char readSWs(void){
	unsigned char ch=0;

	ch = (GPIOD_PDIR>>4) & 0xF;
	// ch = SWsArrVal;  // mask the SWs 4-bit location

	return ch;
}
//---------------------------------------------------------------------
//             Increment / decrement LEDs shown value
//---------------------------------------------------------------------
void incLEDs(char val){

	GPIOC_PDOR = (GPIOC_PDOR + val) & 0xFF;
	// LEDsArrPort = (LEDsArrPort + val) & LEDsArr_LOC;

}
//---------------------------------------------------------------------
//            Polling based Delay function
//---------------------------------------------------------------------
void delay(unsigned int t){  // 0.488*t[usec]
	volatile unsigned int i;
	for(i=t; i>0; i--);
}

void delaySec(float sec){  // t[msec]
	volatile unsigned int iters = (int)(ITERS_PER_SEC * sec);
	for(; iters>0; iters--);
}
//---------------------------------------------------------------------
//            Enter from LPM0 mode
//---------------------------------------------------------------------
void enterLPM(unsigned char LPM_level){
	if (LPM_level == 0x00)
		stop();    /* Enter Low Power Mode 0 */
    else if(LPM_level == 0x01)
    	wait();      /* Enter Low Power Mode 1 */
}
//---------------------------------------------------------------------
//            Enable interrupts
//---------------------------------------------------------------------
void enable_interrupts(){
	GIE();        // Enable Interrupts
}
//---------------------------------------------------------------------
//            Disable interrupts
//---------------------------------------------------------------------
void disable_interrupts(){
	GID();        // Disable Interrupts
}
//*********************************************************************
//            PORTD Interrupt Service Routine - uses for PBs array
//*********************************************************************
void PORTD_IRQHandler(void){

	delaySec(debounceVal);
//---------------------------------------------------------------------
//            selector of transition between states
//---------------------------------------------------------------------
	if(PBsArrIntPend & BIT0){
		 state = state1;
		 PBsArrIntPendClear(BIT0);
	}
    else if (PBsArrIntPend & BIT1){
		 state = state2;
		 PBsArrIntPendClear(BIT1);
    }
    else if (PBsArrIntPend & BIT2){
		 state = state3;
		 PBsArrIntPendClear(BIT2);
    }
    else if (PBsArrIntPend & BIT3){
		 state = state4;
		 PBsArrIntPendClear(BIT3);
    }
    
//---------------------------------------------------------------------
//            Exit from a given LPM
//---------------------------------------------------------------------
    /* switch(lpm_mode){
     	 case mode0:
     	   exitSleep(); // must be called from ISR only
     	   break;

		default:
		  exitSleep(); // must be called from ISR only
		  break;
	}
     */
}


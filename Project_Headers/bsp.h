#ifndef _bsp_H_
#define _bsp_H_

#include "derivative.h"  // contains the inclusion of <MKL25Z4.h>

#define   debounceVal      0.25
#define   SEC_TO_MILLI(x)  (x*1000)
#define   MILLI_TO_SEC(x)  (x/1000.0f)
#define   ITERS_PER_SEC    0x240000
#define   BIT(x)           (1<<x)
#define   KILO             1000
#define   FREQ_TO_TIME(x)  (1/(float)x)
#define   PORT_LOC(x)        ((uint32_t)(1<<x))
//------------------------------------------------------------------
//  					LEDs abstraction
//------------------------------------------------------------------

#define LEDsArrPortSel     		PORT_PCR_MUX(1) | PORT_PCR_DSE_MASK | PORT_PCR_SRE_MASK // figure out what it is (the mux part)
//-----------------------------------------------------------------------
//                    Switches abstraction
//-----------------------------------------------------------------------

typedef enum {
   PORT_A = 0,
   PORT_B,
   PORT_C,
   PORT_D,
   PORT_E

}PortId;

#define BIT(x) 1 << x
#define BIT0 BIT(0)
#define BIT1 BIT(1)
#define BIT2 BIT(2)
#define BIT3 BIT(3)
#define BIT4 BIT(4)
#define BIT5 BIT(5)
#define BIT6 BIT(6)
#define BIT7 BIT(7)

#define SW0_VALUE           (GPIOD_PDIR & BIT0)
#define SW1_VALUE			(GPIOD_PDIR & BIT1)
#define SW2_VALUE			(GPIOD_PDIR & BIT2)
#define SW3_VALUE           (GPIOD_PDIR & BIT3)

#define BUTTON0_VALUE       (GPIOD_PDIR & BIT4)
#define BUTTON1_VALUE       (GPIOD_PDIR & BIT5)
#define BUTTON2_VALUE       (GPIOD_PDIR & BIT6)
#define BUTTON3_VALUE       (GPIOD_PDIR & BIT7)

#define ALL_SW_BUTTON_VALUES {SW0_VALUE, SW1_VALUE, SW2_VALUE, SW3_VALUE, BUTTON0_VALUE, BUTTON1_VALUE, BUTTON2_VALUE, BUTTON3_VALUE}

#define SWsArrPort         GPIOD_PDIR
#define SWsArrPortDir      GPIOD_PDDR
#define SWsArrPortSel      PORT_PCR_MUX(1)+ PORT_PCR_IRQC(0x00)

//-----------------------------------------------------------------------
//                    OutputSignals abstraction
//-----------------------------------------------------------------------
#define OutputSignalPort            GPIOD_PDIR
#define OSignalPortDir              GPIOD_PDDR
#define OSignalPortSel              PORT_PCR_MUX(1)+ PORT_PCR_IRQC(0x00)

#define OP7_LOC                     PORT_LOC(7)

//------------------------------------------------------------------------
//					 PushButtons abstraction
//-------------------------------------------------------------------------
#define PB0_LOC		PORT_LOC(0)
#define PB1_LOC		PORT_LOC(1)
#define PB2_LOC		PORT_LOC(2)
#define PB3_LOC		PORT_LOC(3)
#define PBsArr_LOC  PB0_LOC|PB1_LOC|PB2_LOC|PB3_LOC


#define PBsArrPort	       		GPIOD_PDOR
#define PBsArrIntPend	    	PORTD_ISFR
#define PBsArrIntPendClear(x)	PORTD_ISFR |= x  // using clear with PBi_LOC
// #define PBsArrIntEn
#define PBsArrIntEdgeSel(x) 	PORT_PCR_IRQC(x)
#define PULL_UP            		0x0a
#define PULL_DOWN           	0x09
#define PBsArrPortSel      		PORT_PCR_MUX(1)| PORT_PCR_PFE_MASK
#define PBsArrPortDir      		GPIOD_PDDR
//---------------------------------------------------------------------------

extern void GPIOconfig(void);
extern void TIMERconfig(void);
extern void ADCconfig(void);

#endif /* TFC_bspGPIO_H_ */

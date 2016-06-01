#include "sam.h"

int main( void ){
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   
   // make the GPIO pins an output
   PIOB->PIO_OER = 0x01 << 25;
   PIOC->PIO_OER = 0x01 << 28;
   PIOC->PIO_OER = 0x01 << 25;
   PIOC->PIO_OER = 0x01 << 24;

	for (;;) {
		
		//Turn B25 and C28 on
		PIOB->PIO_SODR = 0x01 << 25;
		PIOC->PIO_SODR = 0x01 << 28;
		for (volatile int i = 0; i < 100'000; i++){}
		
		//Turn B25 off and C25 on
		PIOB->PIO_CODR = 0x01 << 25;
		PIOC->PIO_SODR = 0x01 << 25;
		for (volatile int i = 0; i < 100'000; i++){}
		
		//TURN C28 off and C24 on
		PIOC->PIO_CODR = 0x01 << 28;
		PIOC->PIO_SODR = 0x01 << 24;
		for (volatile int i = 0; i < 100'000; i++){}
		
		//REVERSE ORDER
		PIOC->PIO_CODR = 0x01 << 24;
		PIOC->PIO_SODR = 0x01 << 28;
		for (volatile int i = 0; i < 100'000; i++){}
		
		PIOC->PIO_CODR = 0x01 << 25;
		PIOB->PIO_SODR = 0x01 << 25;
		for (volatile int i = 0; i < 100'000; i++){}
	}
}

#include "sam.h"

int main( void ){
	
	int counter = 0;
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   
   // enable clock for all gpio
   PMC->PMC_PCER0 = (0x3F << 11);
   
   // make the GPIO pins an output
   PIOB->PIO_OER = 0x01 << 25;
   PIOC->PIO_OER = 0x01 << 28;
   PIOC->PIO_OER = 0x01 << 25;
   PIOC->PIO_OER = 0x01 << 24;

	for (;;) {
		if (( PIOC->PIO_PDSR & (0x01 << 21)) == 0 && counter < 4)
		{
			counter++;
			for (volatile int i = 0; i < 100'000; i++){}
		}
		else if (( PIOD->PIO_PDSR & (0x01 << 7)) == 0 && counter > 0)
		{
			counter--;
			for (volatile int i = 0; i < 100'000; i++){}
		}
		switch(counter) {
			case 0:
			PIOB->PIO_CODR = 0x01 << 25;
			PIOC->PIO_CODR = 0x01 << 28;
			PIOC->PIO_CODR = 0x01 << 25;
			PIOC->PIO_CODR = 0x01 << 24;
			break;
			case 1:
			PIOB->PIO_SODR = 0x01 << 25;
			PIOC->PIO_CODR = 0x01 << 28;
			PIOC->PIO_CODR = 0x01 << 25;
			PIOC->PIO_CODR = 0x01 << 24;
			break;
			case 2:
			PIOB->PIO_SODR = 0x01 << 25;
			PIOC->PIO_SODR = 0x01 << 28;
			PIOC->PIO_CODR = 0x01 << 25;
			PIOC->PIO_CODR = 0x01 << 24;
			break;
			case 3:
			PIOB->PIO_SODR = 0x01 << 25;
			PIOC->PIO_SODR = 0x01 << 28;
			PIOC->PIO_SODR = 0x01 << 25;
			PIOC->PIO_CODR = 0x01 << 24;
			break;
			case 4:
			PIOB->PIO_SODR = 0x01 << 25;
			PIOC->PIO_SODR = 0x01 << 28;
			PIOC->PIO_SODR = 0x01 << 25;
			PIOC->PIO_SODR = 0x01 << 24;
			break;
		}
	}
}

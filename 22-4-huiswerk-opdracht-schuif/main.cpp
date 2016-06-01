#include "sam.h"
#include "hwlib.hpp"

int main( void ){
	
	namespace target = hwlib::target;
	auto ds   = target::pin_out( target::pins::d10 );
	auto shcp = target::pin_out( target::pins::d7 );
	auto stcp = target::pin_out( target::pins::d8 );
	auto spi  = hwlib::spi_bus_bit_banged_sclk_mosi_miso( 
	stcp, 
	ds, 
	hwlib::pin_in_dummy 
	);
	
	auto hc595 = hwlib::hc595(spi, shcp);
	
	
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
		if (( PIOC->PIO_PDSR & (0x01 << 21)) == 0 && counter < 8)
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
			hc595.p0.set(0);
			hc595.p1.set(0);
			hc595.p2.set(0);
			hc595.p3.set(0);
			break;
			case 1:
			PIOB->PIO_SODR = 0x01 << 25;
			PIOC->PIO_CODR = 0x01 << 28;
			PIOC->PIO_CODR = 0x01 << 25;
			PIOC->PIO_CODR = 0x01 << 24;
			hc595.p0.set(0);
			hc595.p1.set(0);
			hc595.p2.set(0);
			hc595.p3.set(0);
			break;
			case 2:
			PIOB->PIO_SODR = 0x01 << 25;
			PIOC->PIO_SODR = 0x01 << 28;
			PIOC->PIO_CODR = 0x01 << 25;
			PIOC->PIO_CODR = 0x01 << 24;
			hc595.p0.set(0);
			hc595.p1.set(0);
			hc595.p2.set(0);
			hc595.p3.set(0);
			break;
			case 3:
			PIOB->PIO_SODR = 0x01 << 25;
			PIOC->PIO_SODR = 0x01 << 28;
			PIOC->PIO_SODR = 0x01 << 25;
			PIOC->PIO_CODR = 0x01 << 24;
			hc595.p0.set(0);
			hc595.p1.set(0);
			hc595.p2.set(0);
			hc595.p3.set(0);
			break;
			case 4:
			PIOB->PIO_SODR = 0x01 << 25;
			PIOC->PIO_SODR = 0x01 << 28;
			PIOC->PIO_SODR = 0x01 << 25;
			PIOC->PIO_SODR = 0x01 << 24;
			hc595.p0.set(0);
			hc595.p1.set(0);
			hc595.p2.set(0);
			hc595.p3.set(0);
			break;
			case 5:
			PIOB->PIO_SODR = 0x01 << 25;
			PIOC->PIO_SODR = 0x01 << 28;
			PIOC->PIO_SODR = 0x01 << 25;
			PIOC->PIO_SODR = 0x01 << 24;
			hc595.p0.set(1);
			hc595.p1.set(0);
			hc595.p2.set(0);
			hc595.p3.set(0);
			break;
			case 6:
			PIOB->PIO_SODR = 0x01 << 25;
			PIOC->PIO_SODR = 0x01 << 28;
			PIOC->PIO_SODR = 0x01 << 25;
			PIOC->PIO_SODR = 0x01 << 24;
			hc595.p0.set(1);
			hc595.p1.set(1);
			hc595.p2.set(0);
			hc595.p3.set(0);
			break;
			case 7:
			PIOB->PIO_SODR = 0x01 << 25;
			PIOC->PIO_SODR = 0x01 << 28;
			PIOC->PIO_SODR = 0x01 << 25;
			PIOC->PIO_SODR = 0x01 << 24;
			hc595.p0.set(1);
			hc595.p1.set(1);
			hc595.p2.set(1);
			hc595.p3.set(0);
			break;
			case 8:
			PIOB->PIO_SODR = 0x01 << 25;
			PIOC->PIO_SODR = 0x01 << 28;
			PIOC->PIO_SODR = 0x01 << 25;
			PIOC->PIO_SODR = 0x01 << 24;
			hc595.p0.set(1);
			hc595.p1.set(1);
			hc595.p2.set(1);
			hc595.p3.set(1);
			break;
		}
	}
}

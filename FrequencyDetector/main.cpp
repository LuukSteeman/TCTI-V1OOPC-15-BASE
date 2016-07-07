
//          Copyright Luuk Steeman 2004 - 2006.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include "sam.h"
#include "hwlib.hpp"
#include "signal_pin.hpp"
#define ARRAY_SIZE 300

int main( void ){
    
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   
	namespace target = hwlib::target; 
  
   // set GPIO pins as output
	PIOC->PIO_OER = 0x01 << 28;
	PIOC->PIO_OER = 0x01 << 25;
	PIOC->PIO_OER = 0x01 << 24;
	PIOC->PIO_OER = 0x01 << 23;
	PIOC->PIO_OER = 0x01 << 22;
	PIOC->PIO_OER = 0x01 << 21;

   auto adc0 = target::pin_adc( target::ad_pins::a0 );
   int a[ARRAY_SIZE];
	
	hwlib::wait_ms(300);
	
   for(int i = 0; i < ARRAY_SIZE; i++){ 
		a[i] = adc0.get();
		hwlib::wait_us( 200 );
   }
   
   signal sig((&a)[0]);
   
   
	
	hwlib::cout
	<< "intensiteit"
	<< hwlib::setw( 8 ) << sig.find_intensity()
	<< "\n";
	
	hwlib::cout
	<< "gemiddelde "
	<< hwlib::setw( 8 ) << sig.find_average()
	<< "\n";
	
	hwlib::cout
	<< "frequentie "
	<< hwlib::setw( 8 ) << sig.find_frequency()
	<< "\n";
	
	if (sig.find_intensity() > 1600) {
		PIOC->PIO_SODR = 0x01 << 21;
	}
	
	else if (sig.find_intensity() > 800) {
		PIOC->PIO_SODR = 0x01 << 22;
	}
	
	else if (sig.find_intensity() > 400) {
		PIOC->PIO_SODR = 0x01 << 23;
	}
	
	else if (sig.find_intensity() > 200) {
		PIOC->PIO_SODR = 0x01 << 24;
	}
	
	else if (sig.find_intensity() > 100) {
		PIOC->PIO_SODR = 0x01 << 25;
	}
	
	else if (sig.find_intensity() > 50) {
		PIOC->PIO_SODR = 0x01 << 28;
	}
}
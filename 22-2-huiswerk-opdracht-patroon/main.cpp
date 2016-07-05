#include "sam.h"
#include "hwlib.hpp"

int main( void ){
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   
   // make the GPIO pins an output
   auto led0 = hwlib::target::pin_out( hwlib::target::pins::d7 );
   auto led1 = hwlib::target::pin_out( hwlib::target::pins::d6 );
   auto led2 = hwlib::target::pin_out( hwlib::target::pins::d5 );
   auto led3 = hwlib::target::pin_out( hwlib::target::pins::d4 );

	for (;;) {
		
		
		led0.set(1);
		led1.set(1);
		for (volatile int i = 0; i < 100'000; i++){}
		
		//Turn B25 off and C25 on
		led0.set(0);
		led2.set(1);
		for (volatile int i = 0; i < 100'000; i++){}
		
		//TURN C28 off and C24 on
		led1.set(0);
		led3.set(1);
		for (volatile int i = 0; i < 100'000; i++){}
		
		//REVERSE ORDER
		led1.set(1);
		led3.set(0);
		for (volatile int i = 0; i < 100'000; i++){}
		
		led0.set(1);
		led2.set(0);
		for (volatile int i = 0; i < 100'000; i++){}
	}
}

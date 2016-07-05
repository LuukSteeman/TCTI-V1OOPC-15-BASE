#include "sam.h"
#include "hwlib.hpp"

int main( void ){
	
	int counter = 0;
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   
   // enable clock for all gpio
   PMC->PMC_PCER0 = (0x3F << 11);
   
   // make the GPIO pins an output
   auto led0 = hwlib::target::pin_out( hwlib::target::pins::d7 );
   auto led1 = hwlib::target::pin_out( hwlib::target::pins::d6 );
   auto led2 = hwlib::target::pin_out( hwlib::target::pins::d5 );
   auto led3 = hwlib::target::pin_out( hwlib::target::pins::d4 );
   auto button1 = hwlib::target::pin_in( hwlib::target::pins::d9);
   auto button2 = hwlib::target::pin_in( hwlib::target::pins::d10);

	for (;;) {
		if ( button1.get() == 1 && counter < 4)
		{
			counter++;
			for (volatile int i = 0; i < 100'000; i++){}
		}
		else if ( button2.get() == 1 && counter > 0)
		{
			counter--;
			for (volatile int i = 0; i < 100'000; i++){}
		}
		switch(counter) {
			case 0:
			led0.set(0);
			led1.set(0);
			led2.set(0);
			led3.set(0);
			break;
			case 1:
			led0.set(1);
			led1.set(0);
			led2.set(0);
			led3.set(0);
			break;
			case 2:
			led0.set(1);
			led1.set(1);
			led2.set(0);
			led3.set(0);
			break;
			case 3:
			led0.set(1);
			led1.set(1);
			led2.set(1);
			led3.set(0);
			break;
			case 4:
			led0.set(1);
			led1.set(1);
			led2.set(1);
			led3.set(1);
			break;
		}
	}
}

#include "hwlib.hpp"
#include "mirror.hpp"

int main( void ){	
    
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   
   namespace target = hwlib::target;   
   auto adc0 = target::pin_adc( target::ad_pins::a0 );

   for(int i = 0; i < 50; i++){      
      hwlib::cout 
         << "adc = " 
         << hwlib::setw( 8 ) << adc0.get()
         << "\n";
      hwlib::wait_us( 500 );
   }
     
}

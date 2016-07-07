#include "sam.h"
#include "hwlib.hpp"

class pin_out_all : public hwlib::pin_out {
public:
   hwlib::pin_out * list[ 4 ];     
   


   pin_out_all( 
      hwlib::pin_out & p0, 
      hwlib::pin_out & p1 = hwlib::pin_out_dummy,  
      hwlib::pin_out & p2 = hwlib::pin_out_dummy, 
      hwlib::pin_out & p3 = hwlib::pin_out_dummy 
   ):
      list{ &p0, &p1, &p2, &p3 }
   {}
   
   void set( bool v ){
      for( auto p : list ){
          p->set( v );
      }
   }
};

class pin_out_invert: public pin_out_all {
private:
    pin_out_all & listt;
public:
  pin_out_invert(pin_out_all & listt):
        pin_out_all(listt),
        listt(listt)
  {}
    
   void set( bool v ) override{
      for( auto p  : list ){
          p->set( !v );
      }
   }
};

int main( void ) {
	
	auto led0 = hwlib::target::pin_out(hwlib::target::pins::d2);
	auto led1 = hwlib::target::pin_out(hwlib::target::pins::d3);
	auto led2 = hwlib::target::pin_out(hwlib::target::pins::d4);
	auto led3 = hwlib::target::pin_out(hwlib::target::pins::d5);
	auto led4 = hwlib::target::pin_out(hwlib::target::pins::d6);
	auto led5 = hwlib::target::pin_out(hwlib::target::pins::d7);
	auto led6 = hwlib::target::pin_out(hwlib::target::pins::d8);
	auto led7 = hwlib::target::pin_out(hwlib::target::pins::d9);
	
	led0.set(1);
	led1.set(1);
	led2.set(1);
	led3.set(1);
	led4.set(0);
	led5.set(0);
	led6.set(0);
	led7.set(0);
	
	auto leds1 = pin_out_all(led0, led1, led2, led3);
	auto leds2 = pin_out_all(led4, led5, led6, led7);
	
	auto leds3 = pin_out_invert(leds1);
	auto leds4 = pin_out_invert(leds2);
	auto port = hwlib::port_out_from_pins(leds3, leds4);
	
	while (1){
	hwlib::kitt( port);
	}
}
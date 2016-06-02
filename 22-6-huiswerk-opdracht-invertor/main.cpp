#include "sam.h"
#include "hwlib.hpp"

class pin_out_all : public hwlib::pin_out {
private:
	hwlib::pin_out * list[ 4 ];     
public:
	pin_out_all( 
	hwlib::pin_out & p0, 
	hwlib::pin_out & p1 = hwlib::pin_out_dummy,  
	hwlib::pin_out & p2 = hwlib::pin_out_dummy, 
	hwlib::pin_out & p3 = hwlib::pin_out_dummy 
	):
	list{ &p0, &p1, &p2, &p3 }
	{}
	void set( bool v ){
	for( const auto p& : list ){
		p->set( v );
	}
}
};

class pin_out_invert : public hwlib::target::pin_out {
private:
	hwlib::target::pin_out & slave;
	
public:
	pin_out_invert( hwlib::target::pin_out & sl):
	slave (sl) {}
	
	void set( bool x) override {
		slave.set( ! x );
	}
};


int main( void ) {
	
	auto led0inv = hwlib::target::pin_out(hwlib::target::pins::d2);
	auto led1inv = hwlib::target::pin_out(hwlib::target::pins::d3);
	auto led2inv = hwlib::target::pin_out(hwlib::target::pins::d4);
	auto led3inv = hwlib::target::pin_out(hwlib::target::pins::d5);
	auto led4 = hwlib::target::pin_out(hwlib::target::pins::d6);
	auto led5 = hwlib::target::pin_out(hwlib::target::pins::d7);
	auto led6 = hwlib::target::pin_out(hwlib::target::pins::d8);
	auto led7 = hwlib::target::pin_out(hwlib::target::pins::d9);
	
	pin_out_invert led0(led0inv);
	pin_out_invert led1(led1inv);
	pin_out_invert led2(led2inv);
	pin_out_invert led3(led3inv);
	
	auto leds1 = pin_out_all(led0, led1, led2, led3);
	auto leds2 = pin_out_all(led4, led5, led6, led7);
	
	hwlib::kitt( leds1, leds2);
}
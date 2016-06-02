#include "hwlib.hpp"
#include "sam.h"

class and_pin_in : public hwlib::pin_in {
private:
	hwlib::target::pin_in_out sw1;
	hwlib::target::pin_in_out sw2;
	
public:
	and_pin_in (hwlib::target::pin_in_out sw1, hwlib::target::pin_in_out sw2) :
	sw1(sw1),
	sw2(sw2)
	{}
	
	bool get() override {
		if ((sw1.get() && sw2.get()) == 1) {
			return 1;
		}
		else {
			return 0;
		}
	}
};

int main(void) {
	WDT->WDT_MR = WDT_MR_WDDIS;
	
	auto sw1 = hwlib::target::pin_in_out( hwlib::target::pins::d7);
	auto sw2 = hwlib::target::pin_in_out( hwlib::target::pins::d8);
	and_pin_in and1(sw1, sw2);
	and1.get();
	
}
// example:
// definition of the functions of a filled rectangle object

#include "constructed_object.hpp"

constructed_object::constructed_object( window & w, int mod):
   win(w),
   cir1(w, 25, 45, 10),
   cir2(w, 80, 45, 10),
   cir3(w, 50, 45, 10),
   lin1(w, 15, 5, 15, 10),
   lin2(w, 10, 4, 20, 6),
   rec(w, 10, 10, 100, 35),
   modular(mod)
{}

void constructed_object::print() {
	cir1.print();
	if (modular == 2)
	{
		cir2.print();
	}
	lin1.print();
	lin2.print();
	rec.print();
}
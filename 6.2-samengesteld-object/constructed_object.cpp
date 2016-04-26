// example:
// definition of the functions of a filled rectangle object

#include "constructed_object.hpp"

constructed_object::constructed_object( window & w, circle & c, line & l, filled_rectangle & f):
   win(w),
   cir(c),
   lin(l),
   rec(f)
{}

void constructed_object::print() {
	cir.print();
	lin.print();
	rec.print();
}
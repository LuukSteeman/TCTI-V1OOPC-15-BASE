// example:
// definition of the functions of a rectangle object

#include "filled_rectangle.hpp"

filled_rectangle::filled_rectangle( window & w, int start_x, int start_y, int end_x, int end_y ):
   start_x(start_x),
   end_x(end_x),
   start_y(start_y),
   end_y(end_y),
   win(w)
{}

void filled_rectangle::print(){
   for (int i = start_x; i < end_x; i++) {
	   for (int j = start_y; j < end_y; j++) {
		   win.draw(i, j);
	   }
   }
}


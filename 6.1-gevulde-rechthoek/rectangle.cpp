// example:
// definition of the functions of a rectangle object

#include "filled_rectangle.hpp"

rectangle::rectangle( window & w, int start_x, int start_y, int end_x, int end_y ):
   startx(start_x),
   endx(end_x),
   starty(start_y),
   endy(end_y)
{}

void rectangle::print(){
   left.print();
   right.print();
   top.print();
   bottom.print();
}


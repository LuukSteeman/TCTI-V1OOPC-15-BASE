// example:
// declaration of a filled rectangle object

#ifndef FILLED_RECTANGLE_HPP
#define FILLED_RECTANGLE_HPP

#include "window.hpp"

class filled_rectangle {
private:
   int start_x, end_x, start_y, end_y;
   window &win;
   
public:
   filled_rectangle( window & w, int start_x, int start_y, int end_x, int end_y );
   void print();
};


#endif // RECTANGLE_HPP

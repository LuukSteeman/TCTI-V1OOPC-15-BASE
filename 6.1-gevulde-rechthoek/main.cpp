// template

#include <iostream>

#include "window.hpp"
#include "filled_rectangle.hpp"

int main(int argc, char **argv){
   window w( 128, 64, 2 );
   
   filled_rectangle box( w, 10, 10, 100, 50 );
   box.print();
   
   return 0;
}

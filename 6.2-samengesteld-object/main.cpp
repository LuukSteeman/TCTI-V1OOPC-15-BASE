// template

#include <iostream>

#include "constructed_object.hpp"

int main(int argc, char **argv){
   window w( 128, 64, 2 );
   
   line diagonal_line( w, 5, 5, 30, 40 );
   
   filled_rectangle box( w, 20, 10, 30, 20 );
   
   circle ball( w, 70, 30, 20 );

	constructed_object con(w, ball, diagonal_line, box);
   
   return 0;
}

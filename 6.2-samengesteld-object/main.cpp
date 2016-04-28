// template

#include <iostream>

#include "constructed_object.hpp"

int main(int argc, char **argv){
   window w( 128, 64, 2 );

	constructed_object con(w, 2);
	con.print();
   
   return 0;
}
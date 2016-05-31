#include "victim.hpp"
#include <iostream>

victim::victim( window & w, const vector & start, const vector & end):
   rectangle(w, start, end),
   start_help(start)
{}

void victim::interact( drawable & other ){
   if( this != & other){
      if( overlaps( other )){
		 if (((end.x - start_help.x) > 0) && ((end.y - start_help.y) > 0))
		 {
			 start_help -= vector(1,1);
			 end -= vector(1,1);
		 }
      }
   }
}
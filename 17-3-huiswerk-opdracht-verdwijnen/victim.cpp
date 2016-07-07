#include "victim.hpp"
#include <iostream>

victim::victim( window & w, const vector & start, const vector & end):
   rectangle(w, start, end)
{}

void victim::draw() {
	fill();
}

void victim::interact( drawable & other ){
   if( this != & other){
      if( overlaps( other )){
		  printf("ja\n");
		 if (((end.x - start.x) > 0) && ((end.y - start.y) > 0))
		 {
			 start.x += 1;
			 start.y += 1;
			 end.x -= 1;
			 end.y -= 1;
		 }
		 printf("%d, %d, %d, %d", start.x, start.y, end.x, end.y);
      }
   }
}
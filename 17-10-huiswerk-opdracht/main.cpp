#include "window.hpp"
#include "line.hpp"
#include "ball.hpp"
#include "muur.hpp"

int main(){
   window w( vector( 128, 64 ), 2 );
   muur top( w, vector(   0,  0 ), vector( 127,  4 ) );
   muur right( w, vector( 123,  0 ), vector( 127, 63 ) );
   muur bottom( w, vector(   0, 59 ), vector( 127, 63 ) );
   muur left( w, vector(   0,  0 ), vector(   4, 63 )  );
   ball b( w, vector( 50, 20 ), 9, vector( 5, 2 ) );
   
   drawable * objects[] = { &b, &top, &left, &right, &bottom };

   for(;;){
      w.clear();
      for( auto & p : objects ){
         p->draw();
      }
      wait_ms( 200 );
      for( auto & p : objects ){
          p->update();
      }
      for( auto & p : objects ){
         for( auto & other : objects ){
            p->interact( *other );
         } 
      }
   }
}
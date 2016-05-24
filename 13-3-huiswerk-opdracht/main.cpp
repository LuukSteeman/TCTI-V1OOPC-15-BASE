#include "ostream"
#include "catch_with_main.hpp"
#include "vector.hpp"

TEST_CASE( "Adding two vectors" ){
   vector v( 1, 2 );
   vector w( 3, 5 );
   vector x = v + w;
   REQUIRE( x == vector(4, 7)) ; 
}

TEST_CASE( "Adding vector to vector" ){
   vector v(1,2);
   vector w(3,5);
   w += v;
   REQUIRE( w == vector(4,7)); 
}

TEST_CASE( "subtracting two vectors" ){
   vector v(1,2);
   vector w(3,5);
   vector x = w - v;
   REQUIRE( x == vector(2,3) ); 
}

TEST_CASE( "Subtracting vector from vector" ){
   vector v(1,2);
   vector w(3,5);
   w -= v;
   REQUIRE( w == vector(2,3) );   
}

TEST_CASE( "multiply by integer" ){
   vector v( 3, 4 );
   vector x = v * 7;
   REQUIRE( v == vector( 3, 4 ) );   
   REQUIRE( x == vector( 21, 28 ) );   
}

TEST_CASE( "change by multiplying by integer" ){
   vector v( 3, 10 );
   v *= 5;
   REQUIRE( v == vector( 15, 50 ) );   
}

TEST_CASE( "divide by integer" ){
   vector v( 6, 8 );
   vector x = v / 2;
   REQUIRE( v == vector( 6, 8 ) );   
   REQUIRE( x == vector( 3, 4 ) );   
}

TEST_CASE( "change by dividing by integer" ){
   vector v( 6, 8 );
	v /= 2;
   REQUIRE( v == vector( 3, 4 ) );   
}

TEST_CASE( "operator <<"){
	std::stringstream s;
	vector v(3,10);
	s << v;
	REQUIRE(s.str() == "(3,10)");
}
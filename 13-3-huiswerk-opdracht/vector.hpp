#ifndef VECTOR_HPP
#define VECTOR_HPP
/// @file

/// 2D integer vector ADT
//
/// This is 2D vector ADT that stores its two components as (signed) integers.
/// The x and y components are public attributes. 
/// The appropriate constructors and operators are provided.
class vector {
public:   
	int x, y;
	
   /// default constructor
   //
   /// Constrcutor to initialize x and y coordinates
   vector( int x, int y):
   x(x),
   y(y)
   {}

   /// Add two vectors
   //
   /// This operator gives the sum of two vectors.
   /// The resulting vector points in the combined direction of the two original vectors.
   /// In other words, the x and y attributes of the result are
   /// the x and y are the sum of the x and y of the two original vectors.
   vector operator+( vector & rhs ) const
   {
		return vector( x + rhs.x, y + rhs.y);
	};
   
   /// Add vector to original
   //
   /// This operator adds the x and y values of a vector to an existing one.
   /// This doesn't create a new vector, but changes the original.
   /// The x and y coordinates of the original vector
   /// become the sum of the two vectors.
   
   vector & operator+=( vector & rhs)
	{
		x = x + rhs.x;
		y = y + rhs.y;
		return *this;
	};
   
   /// Subtract two vectors
   //
   /// This operator gives the result of the subtraction of two vectors
   /// The result is a vector where the x and y are the subtraction of 
   /// the original x and y.
   
   vector & operator-( vector & rhs) const 
   {
		return vector( x - rhs.x, y - rhs.y);
	};
   
   /// Subtract vector from original returning original
   //
   /// This operator returns the original vector after another vector
   /// has been subtracted from it.
   /// The x and y are the original x and y minus the subtracters x and y.
   
   vector & operator-=( vector & rhs)
	{
		x = x - rhs.x;
		y = y - rhs.y;
		return *this;
	};
   
   /// Multiply vector with integer
   //
   /// This operator multiplies a vector with an integer.
   /// The resulting vector points in the same direction as
   /// the original, but with a different length.
   /// The x and y are the original x and y multiplied by the integer.
   
   vector & operator*( int rhs) const 
   {
		return vector(x * rhs, y * rhs);
	};
   
   /// Change original vector by multiplying with integer
   //
   /// This operator multiplies and changes the original vector with an integer.
   /// The vector keeps the same direction but its lenght changes.
   /// The new x and y are the old multiplied by the integer.
   
   vector & operator*=( int rhs) 
   {
		x = x * rhs;
		y = y * rhs;
		return *this.
	};
   
   /// Divide vector by integer
   //
   /// This operator divides a vector by an integer.
   /// The resulting vector points in the same direction
   /// but has a different length.
   /// The x and y are the original x and y divided by the integer.
   
   vector & operator/( int rhs) const 
   {
		return vector( x / rhs, y / rhs);
	};
   
   /// Divide and change vector by integer
   //
   /// This operator changes a vector by dividing it with an integer.
   /// The vector doesn't change direction but its length will change.
   /// The new x and y are the old divided by the integer.
   
   vector & operator/=( int rhs) 
   {
		x = x / rhs;
		y = y / rhs;
		return *this;
	};
   
   /// Write to std::ostream
   //
   /// This operator writes the given vector to std::oustream.
   
   friend std::ostream & operator<<(std::ostream & lhs, const vector & rhs ) 
   {
		lhs << "(" << rhs.x << "," << rhs.y << ")";
		return lhs;
	}
};

#endif
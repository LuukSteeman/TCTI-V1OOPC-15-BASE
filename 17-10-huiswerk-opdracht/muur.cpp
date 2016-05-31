#include "muur.hpp"
#include <iostream>

void muur::update(){
   if (filled == 1)
	{
		filled = 0;
	}
	else 
	{
		filled = 1;
	}
}

muur::muur( window & w, const vector & start, const vector & end, bool filled, int update_interval, int update_count ):
	rectangle( w, start, end),
	filled (filled),
	update_interval(update_interval),
	update_count(update_count)
{}

void muur::draw(){
	if ( (update_count % 2) == 0)
	{
		for (int i = start.x; i < end.x; i++)
		{
			for (int j = start.y; j < end.y; j++) 
			{
				w.draw( vector(i, j));
			}
		}
	update();
	update_count++;
	}
	else {
		draw();
	}
}
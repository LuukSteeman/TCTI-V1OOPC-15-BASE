#include "muur.hpp"
#include <iostream>

muur::muur( window & w, const vector & start, const vector & end, bool filled, int update_interval):
	rectangle( w, start, end),
	filled (filled),
	update_interval(update_interval),
	update_count( 0 )
{}

void muur::update(){
	update_count++;
	if (update_count == update_interval){
	   if (filled == 1)
		{
			filled = 0;
			update_count = 0;
		}
		else 
		{
			filled = 1;
			update_count = 0;
		}
	}
}

void muur::draw(){
	if (filled == 1)
	{
		fill();
	}
	else 
	{
		left.draw();
		right.draw();
		top.draw();
		bottom.draw();
	}
}
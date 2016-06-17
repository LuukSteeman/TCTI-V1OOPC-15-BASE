
//          Copyright Luuk Steeman 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include "signal_pin.hpp"
#include "hwlib.hpp"

signal::signal(int (&arr)[ARRAY_SIZE], int total, int deviation, int crossover, int frequency, int average) :
	a( arr ),
	total(total),
	deviation(deviation),
	crossover(crossover),
	frequency(frequency),
	average(average)
{}

int signal::find_average() {
	total = 0;
	for (int i = 0; i < ARRAY_SIZE; i++) {
		total = total + a[i];
	}
	
	average = total / ARRAY_SIZE;
	return average;
}

int signal::find_frequency() {
	crossover = 0;
	average = find_average();
	for (int i = 0; i < ARRAY_SIZE-1; i++) {
		if ((a[i] > average) && (a[i+1] < average)) {
			crossover++;
		}
		
		else if ((a[i] < average) && (a[i+1] > average)) {
			crossover++;
		}
	}
	
	frequency = crossover * 5.5;
	return frequency;
}

int signal::find_intensity() {
	
	average = find_average();
	
	for (int i = 0; i < ARRAY_SIZE; i++) {
		if ((a[i] - average) > 0 ){
			deviation += a[i] - average;
		}
		else if ((a[i] - average) < 0) {
			deviation += average - a[i];
		}
	}
	
	deviation = deviation / ARRAY_SIZE;
	return deviation;
}

//          Copyright Luuk Steeman 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef SIGNAL_PIN_HPP
#define SIGNAL_PIN_HPP
#include "hwlib.hpp"
#define ARRAY_SIZE 300
/// @file


/// Signal class for calculating frequency, intensity and average.
//
/// This is the class used to store the signal data received from the Aruino Due ADC
/// and calculate the various elements of a wave.
/// This class was made with soundwaves in mind and might therfore not work with other types of waves.
/// All characteristics of this class are private
/// and are only made visible by the class's functions.
/// All function definitions can be found in the signal_pin.cpp file.

class signal {
private:
	int (&a)[ARRAY_SIZE];
	int total;
	int deviation;
	int crossover;
	int frequency;
	int average;
public:
	/// Constructor
	//
	/// This constructor initializes the class using an existing array.
	/// All characteristics are set to default value 0 as to prevent bugs.
	signal( int (&arr)[ARRAY_SIZE], int total = 0, int deviation = 0, int crossover = 0, int frequency = 0, int average = 0);
	
	/// Calculate the average value
	//
	/// This function calculates the average value in the array of the class.
	/// It then returns the average so it can be used for other functions or to print it.
	int find_average();
	
	/// Calculate the wave frequency
	//
	/// This function calculates the frequency of the wave in Hz and returns it.
	/// It does so by first calling the fin_average() function,
	/// and checking how often it passed the value found by the function.
	/// The resulting "crossover" value is then multiplied by a calibration factor.
	/// If you find the frequency to be off, use a known frequency and change the factor
	/// until the function returns the desired frequency.
	int find_frequency();
	
	/// Calculate the wave intensity
	//
	/// This function calculates the wave's intensity.
	/// It does so by calculating the average deviation from the wave's average,
	/// by comparing all the values to the return value of find_average().
	/// The returned value is abstract and does not directly corrolate to DB.
	/// Higher returned values does however corrolate to a higher sound level.
	int find_intensity();

};

#endif // SIGNAL_PIN_HPP

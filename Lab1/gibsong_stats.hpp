/*
 * Author: Grace Gibson
 * Date Created: 2/1/2022
 * This header file contains statistical functions for 
 * calculating min/max, mean, and standard deviation of arrays. 
 * Also, there is a function that can estimate a histogram from input arguments. 
 */
#ifndef STATS_LIB
#define STATS_LIB

#include <stdio.h>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <math.h>

namespace arrStats {

	class basicStats {
		public:
			//constructor for creating an object for this class, test is a throw away variable just to test out passing numbers to a constructor
			basicStats(int test);
			//mini() calculates and returns the minimum value of an input array
			float mini(std::vector<float>* in_arr); //or use std::vector<float>
			//max() calculates and returns the maximum value of an input array
			float  max(std::vector<float>* in_arr);
			//mean() calculates and returns the mean value of an input array
			float mean(std::vector<float>* in_arr);
			//stdev() calculates and returns the standard deviation of an input array
			float stdev(std::vector<float>* in_arr);
			//hist() takes in an array and outputs an array corresponding to quantity of data within each bin
			//hist() helps construct a histogram by calculating the width of each bin and centering the histogram at the mean
			std::vector<int> hist(std::vector<float>* in_arr);

			//std::vector allows you not to pre-allocate the size
		//private:


	};
}
#endif

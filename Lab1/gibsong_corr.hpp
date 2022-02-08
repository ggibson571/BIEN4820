/*
 * Author: Grace Gibson
 * Date Created: 2/3/2022
 * This header file contains a correlation coefficient calculation function.
 */
#ifndef CORR_LIB
#define CORR_LIB

#include <stdio.h>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <math.h>

namespace arrStats {

	class corrs {
		public:
			corrs();
            //estimates the correlation coefficient between 2 data sets
			float corr_coef(std::vector<float>* data1, std::vector<float>* data2);


	};
}
#endif
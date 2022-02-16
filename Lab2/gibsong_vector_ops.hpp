/*
 * Author: Grace Gibson
 * Date Created: 2/15/2022
 * This header file contains functions for operating on vectors
 * including summing all their elements, subtracting 2 vectors, and dividing all values by a constant
 */
#ifndef VECTORS
#define VECTORS

#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <math.h>

namespace home_of_vecs{
    class vector_ops {
        public:
            vector_ops();
            //sums all the elements of a vector input array 
            float sum(std::vector<float> *in_arr);
            //subtracts one input array from another input array, element by element
            //subtracts in_arr2 from in_arr1 (in_arr1 - in_arr2)
            void subtract(std::vector<float> *in_arr1, std::vector<float> *in_arr2, std::vector<float> *result);
            //dvidies all values of an input vector array by a specified constant 
            void divide(std::vector<float> *in_arr, float constant, std::vector<float> *result);

       
            
    };
}

#endif
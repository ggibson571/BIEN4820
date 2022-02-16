/*
 * Author: Grace Gibson
 * Date Created: 2/15/2022
 * This header file contains functions for operating on vectors
 * including summing all their elements, subtracting 2 vectors, and dividing all values by a constant
 */
#ifndef PREPE
#define PREPE

#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <math.h>


namespace home_of_vecs{
    class pre_processing {
        public:
            //constructor to create pre_processing object to use functions below
            pre_processing();
            //normalize the in_arr by dividing the data (element by element) by the mean intensity value
            void normalize(std::vector<float> *in_arr, std::vector<float> *out_arr);
            //takes normalized data of both sporulating (sp_arr) and non-sorulating (non_sp_arr) samples and calculates the log ratio for each gene
            void log_ratio(std::vector<float> *sp_arr, std::vector<float> *non_sp_arr, std::vector<float> *out_arr);
    };
}
#endif
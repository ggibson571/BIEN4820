/*
 * Author: Grace Gibson
 * Date Created: 2/15/2022
 * This header file contains functions for processing the yeast cell data 
 * including normalization by the mean and calculating the log ratio between 2 data points. 
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
            //normalize function normalizes by the in_arr by dividing the data (element by element) by the mean intensity value
            std::vector<float> normalize(std::vector<float> *in_arr);
            //log_ratio takes normalized data of both sporulating (sp_arr) and non-sorulating (non_sp_arr) samples and calculates the log ratio for each gene
            std::vector<float> log_ratio(std::vector<float> *sp_arr, std::vector<float> *non_sp_arr);
    };
}
#endif
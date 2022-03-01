/*
 * Author: Grace Gibson
 * Date Created: 2/22/2022
 * This header file contains functions for operating on vectors
 * including summing all their elements, subtracting 2 vectors, and dividing all values by a constant
 */
#ifndef K_MEANS
#define K_MEANS

#include "gibsong_pre_processing.hpp"
#include "/home/gibsong/BIEN4820/Lab1/gibsong_stats.hpp"
#include "gibsong_vector_ops.hpp"
#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <math.h>

namespace gene_clustering {
    class Cluster {
        public:
            //constructor to make cluster object with sets the data vector, name of cluster, and mean of data
            Cluster(std::string name, float mean);
            //getMean returns the mean of the cluster data
            float getMean();
            //getName returns the name of the cluster
            std::string getName();
            //calcMean calculates and sets mean of cluster based on a new cluster data vector
            void calcMean(std::vector<float>* new_cluster);
            //setMean sets the mean of the cluster
            void setMean(float mean);
            //setName sets the name of the cluster
            void setName(std::string name);
            //distance takes in a data point and returns the distance from the data pt to the cluster object (its mean)
            float distance(float data_pt);
            //getData returns the address to the vector containing cluster data
            std::vector<float>* getData();
            //setData sets the data vector for the cluster
            void setData(std::vector<float>* new_cluster);
        private:
            float cluster_mean; 
            std::string cluster_name; 
            std::vector<float>* cluster_data;

    };
}


#endif
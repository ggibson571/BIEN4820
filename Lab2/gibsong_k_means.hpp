/*
 * Author: Grace Gibson
 * Date Created: 2/22/2022
 * This header file contains functions and variables for clustering with the k means algorithm. 
 * Thus, this header file has functions that allow the user to set, retrieve, and calculate the name, mean, data vector, 
 * and distance from mean for a cluster object. 
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
            //constructor to make cluster object which sets the initial name of cluster to name and mean of data to mean
            Cluster(std::string name, float mean);
            //getMean returns the mean of the cluster data
            float getMean();
            //getName returns the name of the cluster
            std::string getName();
            //calcMean calculates and sets mean of cluster based on a new cluster data vector new_vector
            void calcMean(std::vector<float>* new_cluster);
            //setMean sets the mean of the cluster
            void setMean(float mean);
            //setName sets the name of the cluster to name
            void setName(std::string name);
            //distance takes in a data point and returns the distance from the data pt to the cluster object (its mean)
            float distance(float data_pt);
            //getData returns the address to the vector containing cluster data
            std::vector<float>* getData();
            //setData sets the data vector for the cluster to new_cluster
            void setData(std::vector<float>* new_cluster);
        private:
            float cluster_mean; //holds the cluster mean
            std::string cluster_name;  //holds the name of the cluster
            std::vector<float>* cluster_data; //holds the address of the vector with all the cluster members data 

    };
}


#endif
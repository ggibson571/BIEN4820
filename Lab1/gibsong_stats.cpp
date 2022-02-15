#include "gibsong_stats.hpp"
using namespace arrStats;

//determine minimum value of an array
//https://www.cplusplus.com/reference/vector/vector/operator[]/

arrStats::basicStats::basicStats(int test) {
    //printf("object created\n");
}
float arrStats::basicStats::mini(std::vector<float>* in_arr) {
    float min = in_arr->at(0);
    //std::vector<float>::size_type = ; //size returns number of elements in an array
    for(int i = 0; i < in_arr->size(); i++) {
        if(in_arr->at(i) < min) { //change min value if current element's value is less
            min = in_arr->at(i);
        }
    }
    return min;

}
//determine maximum value of an array
float arrStats::basicStats::max(std::vector<float>* in_arr) {
    float max = in_arr->at(0);
    //std::vector<float>::size_type = in_arr.size(); //size returns number of elements in an array
    for(int i = 0; i < in_arr->size(); i++) {
        if(in_arr->at(i) > max) { //change max value if current element's value is more
            max = in_arr->at(i);
        }
    }
    return max;
}
//determine mean/average of an array
float arrStats::basicStats::mean(std::vector<float>* in_arr) {
    //std::vector<float>::size_type = in_arr.size(); //size returns number of elements in an array
    float sum = 0; //will hold the sum of all the elements in the input array 
    for(int i = 0; i < in_arr->size(); i++) {
        sum = in_arr->at(i) + sum;
    }
    return sum/in_arr->size(); //mean = sum/number of elements summed  
}
//determines standard deviation of an array
float arrStats::basicStats::stdev(std::vector<float>* in_arr) {
    //std::vector<float>::size_type = in_arr.size(); //size returns number of elements in an array
    //first calculate sum of the squared difference between each element value and mean
    float mean = this->mean(in_arr);
    float sum = 0;
    for(int i = 0; i < in_arr->size(); i++) {
        sum = sum + pow(in_arr->at(i)-mean, 2);
    }
    //standard deviation is the square root of the sum/number of elements
    return sqrt(sum/in_arr->size());
}
//construct a histogram
std::vector<int> arrStats::basicStats::hist(std::vector<float>* in_arr) {
    float mean = this->mean(in_arr); //sample mean
    float std = this->stdev(in_arr); //sample standard deviation
    float width = 0.4*std; //width of each bin 
    float bin_begin = mean - 3*std;
    float bin_end = mean + 3*std;
    int num_bins = (bin_end - bin_begin)/width;
    //printf("number of bins = %i\n", num_bins);
    std::vector<int> bin_sizes (num_bins);
    int j = 0; //calculate range & count through bin sizes
    int sum = 0; //count number of values in a bin
    //printf("made it here \n");
    /*
    for(int i = 0; i < in_arr->size(); i++) {
        if(in_arr->at(i) >= (bin_begin+(j+1)*width)) {
            sum = 0; //restart sum
            printf("number of values in bin %i= %i\n", j, bin_sizes[j]);
            j++; //move to next bin range 
        }
        if((bin_begin+(j+1)*width) > bin_end ) {
            break; 
        }
        if((in_arr->at(i)>=(bin_begin + j*width)) && (in_arr->at(i) < (bin_begin +(j+1)*width))) {
            printf("added to %ith loop \n", i);
            bin_sizes[j] = sum++;
            
        }
        printf("made it through %ith loop \n", i);
    }
    */
   //fill all bins with zero at first
   for(int i = 0; i < num_bins; i++) {
       bin_sizes[i] = 0;
   }
   //go through all bins
   for(int i = 0; i < num_bins; i++) {
       for(int z = 0; z < in_arr->size(); z++) { //go through all values for a bin
           if((bin_begin+(j+1)*width) > bin_end ) {
                break; 
            }
           if((in_arr->at(z)>=(bin_begin + i*width)) && (in_arr->at(z) < (bin_begin +(i+1)*width))) {
                //.printf("added to %ith bin\n", i);
                sum = sum + 1;
                bin_sizes[i] = sum;
           }
       }
       //printf("sum of %ith bin = %i \n", i, bin_sizes[i]);
       sum = 0; //reset sum
       //printf("made it through %ith bin \n", i);
       
       
   }
    return bin_sizes;

}
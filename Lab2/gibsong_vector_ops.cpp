#include "gibsong_vector_ops.hpp"
//sums all the elements of a vector input array 
            home_of_vecs::vector_ops::vector_ops() {
                std::cout << "object created bb\n";
            }
            float home_of_vecs::vector_ops::sum(std::vector<float> *in_arr) {
                float sum = 0;
                for(int i =  0; i < in_arr->size(); i++) {
                    sum = sum + in_arr->at(i);
                }
                return sum;
            }
            //subtracts one input array from another input array, element by element
            void home_of_vecs::vector_ops::subtract(std::vector<float> *in_arr1, std::vector<float> *in_arr2, std::vector<float> *result){
                if(in_arr1->size() != in_arr2->size()) {
                    std::cout << "Arrays are not the same size. Cannot perform element by element subtraction\n";
                    //return in_arr1;
                    //break;

                }
                else {
                    //std::vector<float> result(in_arr1->size());
                    for(int i =  0; i < in_arr1->size(); i++) {
                        result->at(i) = in_arr1->at(i) - in_arr2->at(i);

                    }
                }
                //return &result;
            }
            
            //dvidies all values of an input vector array by a specified constant 
            void home_of_vecs::vector_ops::divide(std::vector<float> *in_arr, float constant, std::vector<float> *result) {
                for(int i =  0; i < in_arr->size(); i++) {
                    result->at(i) = in_arr->at(i)/constant;
                }
                //return in_arr;
            }


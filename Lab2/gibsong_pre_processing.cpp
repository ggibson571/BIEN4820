#include "gibsong_pre_processing.hpp"
#include "/home/gibsong/BIEN4820/Lab1/gibsong_stats.hpp"
#include "gibsong_vector_ops.hpp"
//constructor to create pre_processing object to use functions below
home_of_vecs::pre_processing::pre_processing(){

}
//normalize the in_arr by dividing the data (element by element) by the mean intensity value
void home_of_vecs::pre_processing::normalize(std::vector<float> *in_arr, std::vector<float> *out_arr){
    arrStats::basicStats for_mean(1);
    for(int i = 0; i < in_arr->size(); i++) {
        out_arr->at(i) = in_arr->at(i)/for_mean.mean(in_arr);
    }
}
//takes normalized data of both sporulating (sp_arr) and non-sorulating (non_sp_arr) samples and calculates the log ratio for each gene
void home_of_vecs::pre_processing::log_ratio(std::vector<float> *sp_arr, std::vector<float> *non_sp_arr, std::vector<float> *out_arr){
    for(int i = 0; i < sp_arr->size(); i++) {
        out_arr->at(i) = log10(sp_arr->at(i)/non_sp_arr->at(i));
    }
}

int main(std::string file_path_red, std::string file_path_bkg_red, std::string file_path_green, std::string file_path_bkg_green, std::string cali_data, int num_genes) {
    //take in 6 command line arguments (written out above)
    //check if the data file exists before trying to read data for all data files
    std::ifstream fileStream_red;
    fileStream_red.open(file_path_red); //open file
    std::string dataEntry;
    int i = 0; //counter for reading all data in files
    std::vector<float> red;
    if(!fileStream_red.is_open()) { //fopen returns a null pointer if FILE object is not opened successfully/not found
        std::cout << "Data file is not found\n";
        fileStream_red.close();
        return -1;
    }
    else {
        while( std::getline(fileStream_red, dataEntry) ){
            red.push_back(std::stof(dataEntry));
			i++;
        }
        if(num_genes > i) {
            std::cout<<"number of genes exceeds number of data points in " << file_path_red << "\n";
            return -2;
        }
    }
    std::ifstream fileStream_bkg_red;
    fileStream_bkg_red.open(file_path_bkg_red); //open file
    i = 0; //reset counter
    std::vector<float> bkg_red;
    
    if(!fileStream_bkg_red.is_open()) { //fopen returns a null pointer if FILE object is not opened successfully/not found
        std::cout << "Data file is not found\n";
        fileStream_bkg_red.close();
        return -1;
    }
    else {
        while( std::getline(fileStream_bkg_red, dataEntry) ){
            bkg_red.push_back(std::stof(dataEntry));
			i++;
        }
        if(num_genes > i) {
            std::cout<<"number of genes exceeds number of data points in " << file_path_bkg_red << "\n";
            return -2;
        }
    }
    
    std::ifstream fileStream_green;
    fileStream_green.open(file_path_green); //open file
    i = 0; //reset counter
    std::vector<float> green;
    if(!fileStream_green.is_open()) { //fopen returns a null pointer if FILE object is not opened successfully/not found
        std::cout << "Data file is not found\n";
        fileStream_green.close();
        return -1;
    }
    else {
        while( std::getline(fileStream_green, dataEntry) ){
            green.push_back(std::stof(dataEntry));
			i++;
        }
        if(num_genes > i) {
            std::cout<<"number of genes exceeds number of data points in " << file_path_green << "\n";
            return -2;
        }
    }
    std::ifstream fileStream_bkg_green;
    fileStream_bkg_green.open(file_path_bkg_green); //open file
    i = 0; //reset counter
    std::vector<float> bkg_green;
    if(!fileStream_bkg_green.is_open()) { //fopen returns a null pointer if FILE object is not opened successfully/not found
        std::cout << "Data file is not found\n";
        fileStream_bkg_green.close();
        return -1;
    }
    else {
        while( std::getline(fileStream_bkg_green, dataEntry) ){
            bkg_green.push_back(std::stof(dataEntry));
			i++;
        }
        if(num_genes > i) {
            std::cout<<"number of genes exceeds number of data points in " << file_path_bkg_green << "\n";
            return -2;
        }
    }
    //checked that the number of genes do not exceed the number of data points in a file
    
    //subtract the corresponding background intensities from the red and green data sets
    std::vector<float> green_cal;
    std::vector<float> red_cal;
    home_of_vecs::vector_ops vect;
    vect.subtract(&red, &bkg_red, &red_cal);
    vect.subtract(&green, &bkg_green, &green_cal);
    //create object to use mean function for the corrected datasets
    arrStats::basicStats stats(1);
    float mean_red = stats.mean(&red_cal);
    float mean_green = stats.mean(&green_cal);
    //normalize the corrected green and red datasets 
    home_of_vecs::pre_processing prepe;
    prepe.normalize(&red_cal, &red_cal);
    prepe.normalize(&green_cal, &green_cal);
    //calculate the log intensity ratio of the normalized data
    std::vector<float> output;
    prepe.log_ratio(&red_cal, &green_cal, &output);
    
    std::ofstream out_file;
    out_file.open(cali_data);
    if(out_file.is_open()) {
        for(int j = 0; j < output.size(); j++) {
            out_file << output[i] <<"\n";
            std::cout << j;
        }
    }

    out_file.close();

    //close rest of files
    fileStream_bkg_green.close();
    fileStream_bkg_red.close();
    fileStream_green.close();
    fileStream_red.close();

    return 0;
}
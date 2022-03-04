#include "gibsong_pre_processing.hpp"
#include "gibsong_stats.hpp"
#include "gibsong_vector_ops.hpp"
//constructor to create pre_processing object to use functions below
home_of_vecs::pre_processing::pre_processing(){
    
}
//normalize the in_arr by dividing the data (element by element) by the mean intensity value
std::vector<float> home_of_vecs::pre_processing::normalize(std::vector<float> *in_arr){
    arrStats::basicStats for_mean(1);
    std::vector<float> out_arr(in_arr->size());
    //std::cout<<"started to normalize\n";
    float mean_arr = for_mean.mean(in_arr);
    //std::cout<<"mean="<<mean_arr<<"\n";
    for(int i = 0; i < in_arr->size(); i++) {
        //std::cout<<in_arr->at(i)/mean_arr<<"\n";
        out_arr[i] = (in_arr->at(i))/mean_arr;
        
    }
    //std::cout<<in_arr->at(in_arr->size()-1)/mean_arr<<"\n";
    return out_arr;
}
//takes normalized data of both sporulating (sp_arr) and non-sorulating (non_sp_arr) samples and calculates the log ratio for each gene
std::vector<float> home_of_vecs::pre_processing::log_ratio(std::vector<float> *sp_arr, std::vector<float> *non_sp_arr){
    std::vector<float> out_arr(sp_arr->size());
    for(int i = 0; i < sp_arr->size(); i++) {
        out_arr[i] = log10(sp_arr->at(i)/non_sp_arr->at(i));
    }
    return out_arr;
}

int main(int argc, char *argv[]) {
    
    //check that the correct amount of command line arguments were inputted by user
    if(argc <7) {
        std::cout<<"not enough arguments\n";
        return -1;
    }
    //take in 6 command line arguments 
    char* file_path_red = argv[1]; //red experimental data
    char* file_path_bkg_red = argv[2]; //red background data for calibration
    char* file_path_green = argv[3]; //green experimental data
    char* file_path_bkg_green = argv[4]; //green background data for calibration
    char* cali_data = argv[5]; //name of output file
    int num_genes = atoi(argv[6]); //number of genes to analyze
    //open and read all files- store results in respective vector
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
            //std::cout << red[i] <<"\n";
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
            //std::cout << bkg_red[i] <<"\n";
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
    home_of_vecs::vector_ops vect;
    std::vector<float> red_cal = vect.subtract(&red, &bkg_red);
    std::vector<float> green_cal = vect.subtract(&green, &bkg_green);
    
    //create object to use mean function for the corrected datasets
    arrStats::basicStats stats(1);
    float mean_red = stats.mean(&red_cal);
    float mean_green = stats.mean(&green_cal);
    
    //normalize the corrected green and red datasets 
    home_of_vecs::pre_processing prepe;
    std::vector<float> red_nor = prepe.normalize(&red_cal);
    std::vector<float> green_nor = prepe.normalize(&green_cal);
    
    //calculate the log intensity ratio of the normalized data
    std::vector<float> output=prepe.log_ratio(&red_nor, &green_nor);
    
    
    std::ofstream out_file; //will store the log ratio output 
    out_file.open(cali_data);
    //only write the output of the number of genes specified to be analyzed 
    if(out_file.is_open()) {
        for(int j = 0; j < num_genes; j++) {
            out_file << output[j] <<"\n";
        }
    }
    //close output file 
    out_file.close();

    //close rest of files
    fileStream_bkg_green.close();
    fileStream_bkg_red.close();
    fileStream_green.close();
    fileStream_red.close();

    return 0;
}
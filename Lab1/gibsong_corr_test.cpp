#include "gibsong_corr.hpp"
#include "gibsong_corr.cpp"
using namespace arrStats;

int main() {
    //expects 2 input arguments corresponding to the paths of 2 data files 
    std::string file_path1;
    std::cout << "What is the file path to your first data file?\n";
    std::cin >> file_path1;
    std::string file_path2;
    std::cout << "What is the file path to your second data file?\n";
    std::cin >> file_path2;
    std::ifstream fileStream1;
    fileStream1.open(file_path1);
    std::ifstream fileStream2;
    fileStream2.open(file_path2);

	//if data file cannot be found, return error to screen & terminate program
    if(!fileStream1.is_open() || !fileStream2.is_open()) { //fopen returns a null pointer if FILE object is not opened successfully/not found
        std::cout << "Data file is not found\n";
        fileStream1.close();
        fileStream2.close();
        return -1;
    }
    //ensure all data pts from both data files are correctly read
    std::vector<float> in_arr1;
    std::vector<float> in_arr2;
    int i = 0; //count number of data points
    std::string dataEntry;
    //ensure all data pts are correctly read
    if(fileStream1.is_open()) {
        while( std::getline(fileStream1, dataEntry) ){
            in_arr1.push_back(std::stof(dataEntry));
			i++;
        }
    }
    fileStream1.close();
    i=0;
    std::string dataEntry2;
    if(fileStream2.is_open()) {
        while( std::getline(fileStream2, dataEntry2) ){
            in_arr2.push_back(std::stof(dataEntry2));
			i++;
        }
    }
    fileStream2.close();
    arrStats:corrs corr_obj;
    printf("%f\n", corr_obj.corr_coef(&in_arr1, &in_arr2));
    return 0;
}
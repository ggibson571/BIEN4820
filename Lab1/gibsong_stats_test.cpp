#include "gibsong_stats.hpp"
//#include "gibsong_stats.cpp"
using namespace arrStats;
int main() {
    std::string file_path;
    std::cout << "What is the file path to your data file?\n"; //prompt user for file
    std::cin >> file_path; //take file name in
    //std:: cout << "About to open file \n";
    /*if(file_path == NULL) {
        std::cout << "Data file is not entered to function\n";
        return -1;
    }*/
    std::ifstream fileStream;
    fileStream.open(file_path); //open file

	//FILE *ptr = fopen("test_file.txt", "r");
    if(!fileStream.is_open()) { //fopen returns a null pointer if FILE object is not opened successfully/not found
        std::cout << "Data file is not found\n";
        fileStream.close();
        return -1;
    }
    std::vector<float> in_arr; //will store all data in file
    int i = 0; //count number of data points
    std::string dataEntry;
    //ensure all data pts are correctly read
    if(fileStream.is_open()) {
        while( std::getline(fileStream, dataEntry) ){
            in_arr.push_back(std::stof(dataEntry));
			i++;
        }
    }
    fileStream.close();
    
    //create object to use stats on data from file
    arrStats::basicStats stat_obj(1);


    //create histogram 
    std::vector<int> vec_ptr = stat_obj.hist(&in_arr);
    //printf("returned from histogram \n"); //determine if issue is returning from histogram 
    
    int max_num = vec_ptr[0];
    //determine maximum number of values in a bin
    for(int j = 0; j < vec_ptr.size(); j++) {
        if(vec_ptr[j] > max_num) {
            max_num = vec_ptr[j];
            
        }
    }
    
    //go from largest value to smallest to construct histogram
    for(int z = max_num; z > 0; z--) {
        for(int y = 0; y < vec_ptr.size(); y++) { //go through each bin
            if( vec_ptr[y] >= z) {
                printf("* ");
            }
            else { //if z is greater than print a space
                printf("  ");
            }
        }
        //once go through all bins for one value
        printf("\n");
        
    }
    //print horizontal lines
    for(int j = 0; j < vec_ptr.size(); j++) {
        printf("==");
    }
    printf("\n");
    //print quantities of bins 
    for(int j = 0; j < vec_ptr.size(); j++) {
        printf("%i ", vec_ptr[j]);
    }
    printf("\n");
    
    //print rest of the statistical analysis result
    printf("number of points: %d\n", i); //number of pts analyzed= size of array
    printf("Mean value of data: %f\n", stat_obj.mean(&in_arr));
    printf("Standard deviation of data: %f\n", stat_obj.stdev(&in_arr));
    printf("Minimum of data: %f\n", stat_obj.mini(&in_arr));
    printf("Maximum of data: %f\n", stat_obj.max(&in_arr));
    
    return 0;
}

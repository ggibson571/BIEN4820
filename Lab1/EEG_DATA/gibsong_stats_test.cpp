#include "gibsong_stats.hpp"
//#include "gibsong_stats.cpp"
using namespace arrStats;
int main() {
    std::string file_path;
    //std::cout << "What is the file path to your data file?\n";
    std::cin >> file_path;
    //std:: cout << "About to open file \n";
    /*if(file_path == NULL) {
        std::cout << "Data file is not entered to function\n";
        return -1;
    }*/
    std::ifstream fileStream;
    fileStream.open(file_path);

	//FILE *ptr = fopen("test_file.txt", "r");
    if(!fileStream.is_open()) { //fopen returns a null pointer if FILE object is not opened successfully/not found
        std::cout << "Data file is not found\n";
        fileStream.close();
        return -1;
    }
    std::vector<float> in_arr;
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
    /*while(fscanf(ptr, "%f", &in_arr[i]) != NULL) {
        i++;
    }
    fclose(ptr);
    */
    //create object to use stats on data from file
    arrStats::basicStats stat_obj(1);

    //printf("number of points: %d\n", i); //number of pts analyzed= size of array
    //printf("Mean value of data: %f\n", stat_obj.mean(&in_arr));
    //printf("Standard deviation of data: %f\n", stat_obj.stdev(&in_arr));
    //printf("Minimum of data: %f\n", stat_obj.mini(&in_arr));
    //printf("Maximum of data: %f\n", stat_obj.max(&in_arr));
    //create histogram 
    std::vector<int> vec_ptr = stat_obj.hist(&in_arr);
    //printf("returned from histogram \n");
    //std::vector<int &vr = *vec_ptr;
    //printf("number of values in bin 1 = %i\n", vec_ptr[0]);
    int max_num = vec_ptr[0];
    //determine maximum number of values in a bin
    for(int j = 0; j < vec_ptr.size(); j++) {
        if(vec_ptr[j] > max_num) {
            max_num = vec_ptr[j];
            
        }
    }
    //printf("max number of values in a bin = %i\n", max_num);
    //go from largest value to smallest to construct histogram
    ///*
    int counter = 1;
    for(int z = max_num; z > 0; z--) {
        for(int y = 0; y < vec_ptr.size(); y++) { //go through each bin
            if( vec_ptr[y] >= z) {
                printf("* ");
            }
            else { //if z is greater than print a space
                printf("  ");
            }
        }
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
    //*/
   /*
    int counter = 1;
    for(int z = 0; z < max_num; z++) {
        for(int y = 0; y < vec_ptr.size(); y++) { //go through each bin
           
            printf("%d *", vec_ptr[y]);
            for(int x = 0; x <vec_ptr[y]; x++) {
                if(counter == 10) {
                    printf("=");
                    counter = 1;
                }
                counter++;
            }
            printf("\n");
        }
        
        
    }
    */
    


    
    return 0;
}

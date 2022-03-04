#include "gibsong_k_means.hpp"
#include "gibsong_stats.hpp"

//constructor to make cluster object which sets the =name of cluster and mean of data
gene_clustering::Cluster::Cluster(std::string name, float mean) {
    this->cluster_name = name;
    this->cluster_mean = mean;
    
}
//getMean returns the mean of the cluster data
float gene_clustering::Cluster::getMean(){
    return this->cluster_mean;
}
//getName returns the name of the cluster
std::string gene_clustering::Cluster::getName() {
    return this->cluster_name;
}
//calcMean calculates and sets mean of cluster based on a new cluster data vector
void gene_clustering::Cluster::calcMean(std::vector<float>* new_cluster) {
    arrStats::basicStats mean_calc(1);
    this->cluster_data = new_cluster;
    this->cluster_mean = mean_calc.mean(this->cluster_data);

}
//sets the mean of the cluster
void gene_clustering::Cluster::setMean(float mean) {
    this->cluster_mean = mean;

}
//setName sets the name of the cluster
void gene_clustering::Cluster::setName(std::string name) {
    this->cluster_name = name;
}
//distance takes in a data point and returns the distance from the data pt to the cluster object (its mean)
float gene_clustering::Cluster::distance(float data_pt) {
    return fabs(data_pt - this->cluster_mean);

}
//getVector returns the address to the vector containing cluster data
std::vector<float>* gene_clustering::Cluster::getData() {
    return this->cluster_data;
}
void gene_clustering::Cluster::setData(std::vector<float>* new_cluster) {
    this->cluster_data = new_cluster;
}

int main(void) {
    //read in a data file named log_ratio_input.dat
    std::string file_path;
    //used for testing 
    //std::cout << "What is the file path to your data file?\n"; //prompt user for file
    //std::cin >> file_path; //take file name in
    
    std::ifstream fileStream;
    fileStream.open("log_ratio_input.dat"); //open file

	//check if the data file exists before trying to read it 
    if(!fileStream.is_open()) { //fopen returns a null pointer if FILE object is not opened successfully/not found
        std::cout << "Data file is not found\n";
        fileStream.close();
        return -1;
    }
    //read in the data of file
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
    int size_file = i; //holds number of data points in file
    //std::cout<<size_file<<"\n";
    //open file with gene names
    std::ifstream fileStream2;
    fileStream2.open("gene_list.txt"); //open file

	//check if the data file exists before trying to read it 
    if(!fileStream2.is_open()) { //fopen returns a null pointer if FILE object is not opened successfully/not found
        std::cout << "Data file is not found\n";
        fileStream2.close();
        return -1;
    }
    //ensure all data pts are correctly read
    i=0;
    std::vector<std::string> in_arr2;
    if(fileStream2.is_open()) {
        while( std::getline(fileStream2, dataEntry) ){
            in_arr2.push_back(dataEntry);
            //std::cout<<in_arr[i]<<" ";
			i++;
        }
    }
    fileStream2.close();
    
    //initialize three cluster classes, their names, and means 
    gene_clustering::Cluster cluster1("suppressed", -0.5);
    gene_clustering::Cluster cluster2("stationary", 0);
    gene_clustering::Cluster cluster3("expressed", 0.5);
    std::vector<float> cluster_data1, cluster_data2, cluster_data3; //hold new vector cluster data
    //calculate distance of log ratio data point to each of the three cluster means 
    float distance1, distance2, distance3; //hold distance from each cluster mean respectively
    float mean1, mean2, mean3; //will store the old cluster means 
    float sum_diff; //hold the sum of the fabs difference of old and new means
    int flag = 1; //flag if should continue the while loop
    std::vector<std::string> names1, names2, names3; //will hold names of genes in each cluster
    while(flag) {
        for(i=0; i<size_file;i++) {
            //calculate distance of cluster mean from each data point
            distance1 = cluster1.distance(in_arr[i]);
            distance2 = cluster2.distance(in_arr[i]);
            distance3 = cluster3.distance(in_arr[i]);
            

            //reassign the data point to the closest cluster
            //assume if any distance is equal to distance 1, cluster 1 gets the data point 
            if((distance1<=distance2) && (distance1<=distance3)) {
                cluster_data1.push_back(in_arr[i]); //add new element to end of vector
                names1.push_back(in_arr2[i]);
            } 
            //assume if distance2 is equal to distance3, cluster 2 gets data point
            else if((distance2<distance1) && (distance2<=distance3)) {
                cluster_data2.push_back(in_arr[i]);
                names2.push_back(in_arr2[i]);
            }
            else { //distance3 is the closest/smallest
                cluster_data3.push_back(in_arr[i]); //add to closest cluster
                names3.push_back(in_arr2[i]);
            }

        }
        
        //finished entire data file
        //store old means of clusters
        mean1 = cluster1.getMean();
        mean2 = cluster2.getMean();
        mean3 = cluster3.getMean();
        
        //recalculate the cluster mean
        cluster1.calcMean(&cluster_data1);
        cluster2.calcMean(&cluster_data2);
        cluster3.calcMean(&cluster_data3);
        
        //calculate the sum of the fabs difference of previous and current mean 
        sum_diff = cluster1.distance(mean1)+cluster2.distance(mean2)+cluster3.distance(mean3);
        
        
        if(sum_diff <= 0.0001) { //criteria for stopping k means algorithm 
            flag = 0; //break out while loop
            //std::cout<<"about to break the loop\n";
            break; //leave the for loop
        }

        //clear members of each cluster if did not meet criteria... will reassign clusters again 
        cluster_data1.clear();
        cluster_data2.clear();
        cluster_data3.clear();
        names1.clear();
        names2.clear();
        names3.clear();
    }
    //output the final cluster means to standard output
    std::cout<<cluster1.getMean()<<"\n";
    std::cout<<cluster2.getMean()<<"\n";
    std::cout<<cluster3.getMean()<<"\n";
    //write three output files with the list of genes by name

    std::ofstream out_file1, out_file2, out_file3;
    
    out_file1.open("suppressed_gene.txt");
    if(out_file1.is_open()) {
        for(int j = 0; j < names1.size(); j++) {
            out_file1 << names1[j] <<"\n";

            //std::cout << j;
        }
    }
    out_file2.open("stationary_gene.txt");
    if(out_file2.is_open()) {
        for(int j = 0; j < names2.size(); j++) {
            out_file2 << names2[j] <<"\n";
            //std::cout << j;
        }
    }
    out_file3.open("expressed_gene.txt");
    if(out_file3.is_open()) {
        for(int j = 0; j < names3.size(); j++) {
            out_file3 << names3[j] <<"\n";
            //std::cout << j;
        }
    }
    //close all files once done writing to them
    out_file1.close();
    out_file2.close();
    out_file3.close();
    /* //test code to determine the log values in each cluster and names in each cluster based upon the mean of the clusters 
    if(cluster1.getMean()>cluster2.getMean()>cluster3.getMean()) {
        out_file1.open("expressed_gene.txt");
        if(out_file1.is_open()) {
            for(int j = 0; j < names1.size(); j++) {
                out_file1 << names1[j] <<"\n";
                //std::cout << j;
            }
        }
        out_file2.open("stationary_gene.txt");
        if(out_file2.is_open()) {
            for(int j = 0; j < names2.size(); j++) {
                out_file2 << names2[j] <<"\n";
                //std::cout << j;
            }
        }
        out_file3.open("suppressed_gene.txt");
        if(out_file3.is_open()) {
            for(int j = 0; j < names3.size(); j++) {
                out_file3 << names3[j] <<"\n";
                //std::cout << j;
            }
        }
    }
    else if(cluster1.getMean()>cluster3.getMean()>cluster2.getMean()) {
        out_file1.open("expressed_gene.txt");
        if(out_file1.is_open()) {
            for(int j = 0; j < names1.size(); j++) {
                out_file1 << names1[j] <<"\n";
                //std::cout << j;
            }
        }
        out_file2.open("suppressed_gene.txt");
        if(out_file2.is_open()) {
            for(int j = 0; j < names2.size(); j++) {
                out_file2 << names2[j] <<"\n";
                //std::cout << j;
            }
        }
        out_file3.open("stationary_gene.txt");
        if(out_file3.is_open()) {
            for(int j = 0; j < names3.size(); j++) {
                out_file3 << names3[j] <<"\n";
                //std::cout << j;
            }
        }
    }
    else if(cluster2.getMean()>cluster1.getMean()>cluster3.getMean()) {
        out_file1.open("stationary_gene.txt");
        if(out_file1.is_open()) {
            for(int j = 0; j < names1.size(); j++) {
                out_file1 << names1[j] <<"\n";
                //std::cout << j;
            }
        }
        out_file2.open("expressed_gene.txt");
        if(out_file2.is_open()) {
            for(int j = 0; j < names2.size(); j++) {
                out_file2 << names2[j] <<"\n";
                //std::cout << j;
            }
        }
        out_file3.open("suppressed_gene.txt");
        if(out_file3.is_open()) {
            for(int j = 0; j < names3.size(); j++) {
                out_file3 << names3[j] <<"\n";
                //std::cout << j;
            }
        }
    }
    else if(cluster2.getMean()>cluster3.getMean()>cluster1.getMean()) {
        out_file1.open("suppressed_gene.txt");
        if(out_file1.is_open()) {
            for(int j = 0; j < names1.size(); j++) {
                out_file1 << names1[j] <<"\n";
                //std::cout << j;
            }
        }
        out_file2.open("expressed_gene.txt");
        if(out_file2.is_open()) {
            for(int j = 0; j < names2.size(); j++) {
                out_file2 << names2[j] <<"\n";
                //std::cout << j;
            }
        }
        out_file3.open("stationary_gene.txt");
        if(out_file3.is_open()) {
            for(int j = 0; j < names3.size(); j++) {
                out_file3 << names3[j] <<"\n";
                //std::cout << j;
            }
        }
    }
    else if(cluster3.getMean()>cluster1.getMean()>cluster2.getMean()) {
        out_file1.open("stationary_gene.txt");
        if(out_file1.is_open()) {
            for(int j = 0; j < names1.size(); j++) {
                out_file1 << names1[j] <<"\n";
                //std::cout << j;
            }
        }
        out_file2.open("suppressed_gene.txt");
        if(out_file2.is_open()) {
            for(int j = 0; j < names2.size(); j++) {
                out_file2 << names2[j] <<"\n";
                //std::cout << j;
            }
        }
        out_file3.open("expressed_gene.txt");
        if(out_file3.is_open()) {
            for(int j = 0; j < names3.size(); j++) {
                out_file3 << names3[j] <<"\n";
                //std::cout << j;
            }
        }
    }
    else {//c3_mean>c2_mean>c1_mean
        out_file1.open("suppressed_gene.txt");
        if(out_file1.is_open()) {
            for(int j = 0; j < names1.size(); j++) {
                out_file1 << names1[j] <<"\n";
                //std::cout << j;
            }
        }
        out_file2.open("stationary_gene.txt");
        if(out_file2.is_open()) {
            for(int j = 0; j < names2.size(); j++) {
                out_file2 << names2[j] <<"\n";
                //std::cout << j;
            }
        }
        out_file3.open("expressed_gene.txt");
        if(out_file3.is_open()) {
            for(int j = 0; j < names3.size(); j++) {
                out_file3 << names3[j] <<"\n";
                //std::cout << j;
            }
        }
    }
    */
    
     

    return 0; //if successful execution (ie went thru entire main program )
}
#!/bin/bash
#Author:  Grace Gibson
#Date Created: 3/1/2022
#Calibrates all the data from the seven time points and creates a summary file of cluster means and total number
#of expressed, suppressed, and stationary genes
#prompt user for input
echo "Enter the number of microarray points to be read in"
read num_microarray #read user input

#calibrate the data from each of the 7 time pts
green_start="./microarray/green_"
red_start="./microarray/red_"
counter=0 #count through all files
while [ $counter -le 6 ]  #loop used to loop through all data files to make log ratio files for each data set with prep executable
do
    rm -f "clusters_${counter}.txt"
    
    ./prep "${red_start}${counter}.dat" "${red_start}background_${counter}.dat" "${green_start}${counter}.dat" "${green_start}background_${counter}.dat" "log_ratio_${counter}.dat" $num_microarray
    cp "log_ratio_${counter}.dat" log_ratio_input.dat #copy log ratio output data to new file
    #run clustering program on the new file and put results/stdout in a respective file
    ./k_means >> "clusters_${counter}.txt"
    #copy the cluster output files to files who denote the corresponding time point 
    cp expressed_gene.txt "expressed_${counter}.txt"
    #write the cluster means and number of members in each cluster to a separate file for each time point
    wc -l "expressed_${counter}.txt" >> "clusters_${counter}.txt"
    cp suppressed_gene.txt "suppressed_${counter}.txt"
    wc -l "suppressed_${counter}.txt" >> "clusters_${counter}.txt"
    cp stationary_gene.txt "stationary_${counter}.txt"
    wc -l "stationary_${counter}.txt" >> "clusters_${counter}.txt"
    (( counter++ ))
    
done

#create a summary file that lists the final cluster means and total number of each category of genes for each time point
cat clusters_* > sum.txt

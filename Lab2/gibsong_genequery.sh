#!/bin/bash
#Author:  Grace Gibson
#Date Created: 3/1/2022
#The program takes in the gene name and returns its status: expressed, suppressed, or stationary
#for each time point

#prompt user to enter gene name
echo "Enter the gene to be queried: "
read gene_name

#find where the gene name is found in each time point and echo to screen the state of the gene for each time point
counter=0 #count through all files
while [ $counter -le 6 ]  #loop through all time pts
do
    if [[ $(grep -o $gene_name "expressed_${counter}.txt" | wc -l) = 1 ]] #will return 1 if count 1
    then 
        echo "at time point ${counter}: expressed"
    elif [[ $(grep -o $gene_name "stationary_${counter}.txt" | wc -l) = 1 ]]
    then
        echo "at time point ${counter}: stationary"
    else
        echo "at time point ${counter}: suppressed"
    fi
    (( counter++ ))
done

#!/bin/bash
#Author:  Grace Gibson
#Date Created: 2/8/2022
#Concatenates all 60 data files from the user-specified concentration level into one data file

#prompt user for input
echo "Enter the concentration level to analyze (00 or 05)"
read conc_level #read user input
#echo $conc_level
touch catted_input.dat
if test $conc_level = "00"
then
#echo "entered"
#touch catted_data_test.dat #create file to concatenate all 60 data files to
cat ./ERP/ERP00/* > catted_data${conc_level}.dat #concatenate all files in a directory and output to new file
fi
if test $conc_level = "05"
then
#touch catted_data_test2.dat #create file to concatenate all 60 data files to
cat ./ERP/ERP05/* > catted_data.dat #concatenate all files in a directory and output to new file
fi
#execute the histogram program for this new data set
#cp /home/gibsong/BIEN4820/Lab1/gibsong_stats.hpp gibsong_stats.hpp

make clean
make hist #compile and link all executable files

touch hist$conc_level.txt
echo "catted_data.dat" | ./hist  > hist$conc_level.txt #echo output of executable to output file
#print to screen where output is stored 
echo "output stored in hist$conc_level.txt"
#!/bin/bash
#Author:  Grace Gibson
#Date Created: 2/8/2022
#Concatenates all 60 data files from the user-specified concentration level into one data file

#prompt user for input
echo "Enter the concentration level to analyze (00 or 05)"
read conc_level #read user input

touch conc_corr_$conc_level.csv

make clean
make all #compile and link all executable files 

counter=1 #count through all files
while [ $counter -le 5 ]  #loop used to learn and test while loop and counter++ command
do
    #echo "hi"
    (( counter++ ))
done
counter=1 #reset counter
while [ $counter -le 59 ]
do 
    #echo -e "hi\n"
    counter_plus=$((counter + 1))
    if [ $conc_level = "00" ]
    then
        #echo the path names for verificaiton that they are the ones we're expecting
        echo -e "./ERP/ERP${conc_level}/ERP${conc_level}${counter}.txt\n./ERP/ERP${conc_level}/ERP${conc_level}${counter_plus}.txt\n" 
        echo -e "./ERP/ERP${conc_level}/ERP${conc_level}${counter}.txt\n./ERP/ERP${conc_level}/ERP${conc_level}${counter_plus}.txt\n" | ./corr >> conc_corr_$conc_level.csv
    else 
        echo -e "./ERP/ERP${conc_level}/ERP${conc_level}.${counter}.txt\n./ERP/ERP${conc_level}/ERP${conc_level}.${counter_plus}.txt\n"
        echo -e "./ERP/ERP${conc_level}/ERP${conc_level}.${counter}.txt\n./ERP/ERP${conc_level}/ERP${conc_level}.${counter_plus}.txt\n" | ./corr >> conc_corr_$conc_level.csv
    fi
    (( counter++ )) #move to next file
done

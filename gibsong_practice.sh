#!/bin/bash
#Author:  Grace Gibson
#Date Created: 3/2/22
#

#download one of your cpp files from Lab 1 using bash from Github
rm "gibsong_corr.cpp*"
#wget https://raw.githubusercontent.com/ggibson571/BIEN4820/master/Lab1/gibsong_corr.cpp

#extract function headers
grep ".*::.*::" gibsong_corr.cpp | sed 's/.*::.*:://g' > practice.txt
#extract namespace and class name
grep -m1 ".*::.*::" gibsong_corr.cpp

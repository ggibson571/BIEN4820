#!/bin/bash
#Author:  Grace Gibson
#Date Created: 2/16/2022
#Bash script about bash conditionals

line_1="Oh-oh-oh-oh-oh, oh-oh-oh-"
line_2="oh, oh-oh-oh"
line_3="Caught in a bad romance"
line_4="Ra-ra-ah-ah-ah"
line_5="Roma Roma-ma"
line_6="Gaga, \"Ooh la-la\""
line_7="Want your bad romance"

for (( i=1;i<15;i++ ))
do
    if [[ ($i -eq 1) || ($i -eq 4) ]]
    then
        echo $line_1
        
    elif [[ ($i -eq 2) || ($i -eq 5) ]]
    then
        echo $line_2
       
    elif [[ ($i -eq 3) || ($i -eq 6) ]]
    then    
        echo $line_3
        
    elif [[ ($i -eq 7) || ($i -eq 11) ]]
    then    
        echo $line_4
        
    elif [[ ($i -eq 8) || ($i -eq 12) ]]
    then    
        echo $line_5
        
    elif [[ ($i -eq 9) || ($i -eq 13) ]]
    then    
        echo $line_6
        
    else 
        echo $line_7
        
    fi
done

while IFS= read line
do 
    if [[ ($line = "Spirited Away") ]]
    then
        echo $line
    fi
done < good_movies.txt

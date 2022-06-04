#! /usr/bin/bash

car=("BWM" "TOYOTA" "BENZ" "AUDI") # "" is the same as ''
# car=('BWM' 'TOYOTA' 'BENZ' 'AUDI') # strict definations


unset car[2] # delete the third member

car[2]=Mecedes # add the member
echo "${car[@]}"
echo "${car[0]}"
echo "${!car[@]}" # index
echo "${#car[@]}" # number of the value

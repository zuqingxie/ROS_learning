#! /usr/bin/bash

echo "press any key to continue"

while [ true ] # this frequency is very high
do
    read -t 0.2 -n 1  # keep reading the input every 0.2 second . and will only read one leter
if [ $? = 0 ] # if read anything
then 
    echo "you have terminates the script"
    exit;
else  # nothing happens
    echo "waiting for you to press any key!!! "
fi


done
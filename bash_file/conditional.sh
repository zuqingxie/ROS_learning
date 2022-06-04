#! /usr/bin/bash

# compare in the conditional
counter=10  # here is not allow to have a space
# if [ $counter >= 11 ]  # here must have the space   -gt -ne -lt -le
# < > >= <=  is not allow to use here. we can use :
# if (($counter < 11 ))
# if [ $counter -gt 5 ] && [ $counter -lt 15 ] # and
# if [ $counter -gt 5 ] || [ $counter -lt 15 ] # or
# if [ $counter -gt 5 -o $counter -gt 15 ] # or
then
    echo "condition is true"
# elif xxxxxx
else 
    echo "condition is false"
fi





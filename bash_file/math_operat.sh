#! /usr/bin/bash

#数学运算的表达 
n1=3
n2=10

echo $(( n1 + n2 ))
# echo $(( n1 - n2 ))
# echo $(( n1 * n2 ))
# echo $(( n1 / n2 )) # integer 0
# echo $(( n1 % n2 )) 

echo $(expr $n1 + $n2 ) # another method
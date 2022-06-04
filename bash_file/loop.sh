#! /usr/bin/bash

# loop

number=1
while [ $number -lt 10 ]
# until [ $number -gt 10 ] # actually they are the same

do
    echo "$number is smaller as 10"
    number=$(( number+1 ))
done



# for loop
# for i in {0..10..2} # {start..ending..increament}
for (( i=0 ; i<10 ; i++ )) # {start..ending..increament}
do
    if [ $i -gt 5 ] && [ $i -lt 15 ]
    then
        continue # do the next loop
    else
        echo $i
    fi
done
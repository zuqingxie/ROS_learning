#! /usr/bin/bash

# learn about awk
# simple and effective languages

# print a file with awk

echo "Enter filename to print from awk"

read fileName

if [[ -f $fileName ]]
then
    awk '{print}' $fileName # print all the content                                                                                                             
    awk '/windows/ {print $3,$4 }' $fileName # search for windows all the content                                                                                                             
else
    echo "$fileName does not exist"
fi
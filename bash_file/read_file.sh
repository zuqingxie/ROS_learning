#! /usr/bin/bash

while read line
do 
    echo $line
done < "${1:-/dev/stdin}"

# try this : $ bash read_file.sh file_add.txt 
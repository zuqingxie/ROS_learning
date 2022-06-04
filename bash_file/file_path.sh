#! /usr/bin/bash

# check the file or directory are existed or not 
# what we usually do is check whether we have the file or directory. if not create one
# or if this is the file and then we write or read on that
echo "Enter the directory path :"
read path
# if [ -d "$path" ]  
if [ -f "$path" ] 
then
    echo "it is a directory or file "
else
    echo " it is not a directory or file"
fi 
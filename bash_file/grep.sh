#! /usr/bin/bash

# learn about grep

echo "Enter filename to search text "
read fileName

if [[ -f $fileName ]]
then
    echo "File exist"
    echo "what do you want to search"

    read text
    grep -i -n -c $text $fileName # -i remove the case sensitivity; -n show the lines; -c how many times it occurs, -v delete the searching words
else
    echo "File does not exist"
fi

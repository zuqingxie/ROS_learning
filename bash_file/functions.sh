#! /usr/bin/bash


# function will overwrite the 
# define and use the function!!!!!
function functionname()
{
     echo "this is a function"
}
functionname

# add the parameter

function functionPrint(){
    MESSAGE="ME" # variable in the function is treated as actually global value 

    echo "the value is $1 , and $2" # beginn with 1 . it is different as array
}
functionPrint World Hello

echo "$MESSAGE"
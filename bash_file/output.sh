#! /usr/bin/bash

# ls .... this is stdout 
# ls +al .... this is stderr

# ls -al 1>stdout.txt 2>stderr.txt # this is the idea to seperate the both error and output to two file
# ls +al >stdout_and_stderr.txt 2>&1 # this is combine the error and output together
ls +al >& stdout_and_stderr.txt # the same as last line
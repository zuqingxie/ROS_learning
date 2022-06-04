#! /usr/bin/bash
echo "Ethenet IP is:" > file.txt #delete the precious stuff

ifconfig | grep 192 | awk '{print $2}' >> file_add.txt # continue write
cat >> file_add.txt # write in the terminal and record id into file, ctrl+d to stop it

#! /usr/bin/bash -x

# learn about sed

set -x # debugging beginns

echo "Enter filename to substitute using sed"
read fileName
if [[ -f $fileName ]]

set +x # end of the debug

then
    # cat $fileName | sed 's/i/I/' # substitute i to I once a line temporary
    # cat $fileName | sed 's/i/I/g' # substitute i to I globally temporary  
    sed 's/i/III/g' $fileName # substitute i to III globally
    sed -i 's/i/III/g' $fileName # modify the file forever 
    sed 's/i/III/g' $fileName > file_sed_new.txt # recommand to backup and save into a new file
else
    echo "$fileName does not exist"
fi 
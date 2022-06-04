#! /usr/bin/bash

url="https://www.dundeecity.gov.uk/sites/default/files/publications/civic_renewal_forms.zip"
# curl ${url} -O # download original
curl ${url} -o DownloadFile.zip # rename it 
curl ${url} > file.txt # downliad into a file
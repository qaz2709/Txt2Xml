#! /bin/bash

echo "script input:  $1  $2"
echo "-----------------"
txtPath="./data/Up.txt"
xmlPath="./data/Up.xml"

./Qtbuild-txt2xml-Debug/out $1 $2 

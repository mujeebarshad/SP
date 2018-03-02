#!/bin/bash

UNIX=( "Debian" "Red hat" "Ubuntu" "Suse" "Fedora" )  
echo "Content of AWrray: "
echo ${UNIX[*]}

echo "Length of array: "
echo ${#UNIX}
echo "Length of element 2: "
echo ${#UNIX[1]}
echo "Extract elements from 3 to 5"
echo ${#UNIX[3]}
echo ${#UNIX[4]}
echo ${UNIX[*]:3:2}
echo "Search and Replace"
echo ${UNIX[*]/Ubuntu/SCO}
echo "Content of Array: "
echo ${UNIX[*]}
echo "Add Element"
UNIX=(${UNIX[*]} "AIX" "HP-UX")
echo "Remove Element "
unset UNIX[3]
LINUX=(${UNIX[*]})
echo "Content of Array: "
echo ${LINUX[*]}

LU=(${UNIX[*]} ${LINUX[*]})

echo "Content of Array: "
echo ${UNIX[*]}

unset LINUX[*]
unset UNIX[*]

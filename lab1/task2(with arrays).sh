#!/bin/bash

arr=(`ls -l doc1`)

echo "Owner: " ${arr[2]}
echo "Group: " ${arr[3]}
echo "Permissions: " ${arr[0]}
echo "Filename: " ${arr[8]}
if(test ${arr[3]}=${arr[2]})
	then
	echo "Cheating: " 0
else
	echo "Cheating: " 1
fi

diff -c doc1 doc2

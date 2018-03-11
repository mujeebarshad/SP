#!/bin/bash

if [ -z "$1" ]
then
	echo "No arguments"
else
	IFS=$'\n' arr=(`sort $1 | uniq`)
	bool=0
	for i in ${arr[*]}
	do
		if [ $bool -eq 0 ]
		then
			echo $i 1>$1
			bool=`expr $bool + 1`
		else
			echo $i 1>>$1
		fi
	done
fi

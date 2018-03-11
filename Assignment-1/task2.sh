#!/bin/bash

if [ -z "$1" ]
then
	echo "No arguments"
else
	IFS=$'\n' lines=(`cat $1`)
	if [ ${#lines[*]} -gt 0 ]
	then
		touch oddfile
		touch evenfile
		count=1
		for i in ${lines[*]}
		do
			res=`expr $count % 2`
			if [ $res -eq 0 ]
			then
				echo $i 1>>evenfile
			else
				echo $i 1>>oddfile
			fi 
			count=`expr $count + 1`
		done
	fi
fi


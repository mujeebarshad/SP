#!/bin/bash

showMeOwner()
{
	user=$1
		for i in `ls`
			do
				
				set `ls -li $i`
				shift
				if [ -f $i ]
				then
				if [ $user = $3 ]
				then
				echo "FileOwner: " $3
				shift
				echo "FileName: " $8
				fi
				fi
			done
	
}
bool=0
if [ $# -eq 0 ]
	then
	echo "NO arguments"
	bool=1
fi

if [ $# -gt 1 ]
	then
	echo "Invalid arguments"
	bool=1
fi

if [ $bool -eq 0 ]
	then
		cd ~/
		showMeOwner $1
fi


#!/bin/bash

allFiles=( `ls` )
for i in ${allFiles[@]}
do
	echo $i
	IFS=$'.' exten=( $i )
	if [ -d ${exten[1]} ]
	then
		IFS=$" "
		mv $i ${exten[1]}
	else
		IFS=$" "
		mkdir ${exten[1]}
		mv $i ${exten[1]}
	fi 
	
done

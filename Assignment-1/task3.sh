#!/bin/bash

is_Lower()
{
	echo ${@,,}
}

is_Root()
{
	root_id=(`cut -d ":" -f 3 /etc/passwd`)
	current_id=`id -u`
	if [ $root_id -eq $current_id ]
	then
		echo "User is Root"
		return 0
	else
		echo "User is Not Root"
	fi
}

is_User_exists()
{
	allusers=(`cut -d ":" -f 1 /etc/passwd`)
	user=$1
	for i in ${allusers[*]}
	do
		if [ $i = $user ]
		then
			echo "User exists"
			return 0
		fi
	done
	echo "User not exists!"
}
is_User_exists $1
is_Root
is_Lower $@

#!/bin/bash

RunningProcess()
{
	file=$1
	set `ps -all -A | grep $file`
	if [ $? -eq 0 ]
	then
	echo "PID: " $4
	echo "PPID: " $5
	shift
	shift
	shift
	shift
	shift
	echo "Name: " $9
	echo "State: Running"
	fi
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
	count=`ps -all -A | grep $1 | wc -l`
	if [ $count -gt 0 ]
	then
		RunningProcess $1
	fi
fi

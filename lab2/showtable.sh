#!/bin/bash

showTable()
{
	check=0
	if [ $# -eq 1 ]
	then
	x=$2
	var=${x:abc}
	if [ $var!=abc ]
	then
		for i in `seq 1 10`
		do
			echo "$1 * $i = " `expr $i \* $1`
		done
	check=1
	fi
	fi
	
	if ( [ $check -eq 0 ] && [ $# -eq 3 ] )
	then
		
		var2=$2
		if [ $var2 = "-s" ]
		then
			for i in `seq $3 10`
			do
				echo "$1 * $i = " `expr $i \* $1`
			done
		elif [ $var2 = "-e" ]
		then
			for i in `seq 1 $3`
			do
				echo "$1 * $i = " `expr $i \* $1`
			done
		fi
		check=1
	fi
	
	if ( [ $check -eq 0 ] && [ $# -eq 5 ] )
	then
		if ( [ $2 = "-s" ] && [ $4 = "-e" ] )
		then
			for i in `seq $3 $5`
			do
				echo "$1 * $i = " `expr $i \* $1`
			done
		fi
		check=1
	fi
	
	if ( [ $check -eq 0 ] && [ $# -eq 6 ] )
	then
		if ( [ $2 = "-s" ] && [ $4 = "-e" ] && [ $6 = "-r" ] )
		then
			for i in `seq $3 $5`
			do
				echo "$1 * $i = " `expr $i \* $1`
			done
			echo "Reverse : "
			j=$5
			while [ $j -ge $3 ]
			do
				echo "$1 * $j = " `expr $j \* $1`
				j=`expr $j - 1`
			done
		fi
		check=1
	fi
	
}
bool=0
if [ $# -eq 0 ]
	then
		echo "No Arguments Provided!"
		bool=1
fi
if [ $# -gt 6 ]
	then 
		echo "Invalid aruguments"
		bool=1
fi
if [ $# -eq 2 ]
	then 
		echo "Invalid aruguments"
		bool=1
fi
if [ $# -eq 4 ]
	then 
		echo "Invalid aruguments"
		bool=1
fi

if [ $bool -eq 0 ]
	then
		showTable $@
fi

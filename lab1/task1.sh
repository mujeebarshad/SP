#!/bin/bash

read -p "Enter number: " n1 
read -p "Enter number: " n2

expr $n1 + 0
if ( test $? -eq  0 )
	then
		 expr $n2 + 0
		 if ( test $? -eq 0 )
			then
				echo "Addition: "
				echo `expr $n1 + $n2`
				echo "Subtraction: "
				echo `expr $n1 - $n2`
				echo "Division: "
				echo `expr $n1 / $n2`
				echo "Multiplication: "
				echo `expr $n1 \* $n2`
				echo "Mod: "
				echo `expr $n1 % $n2`
			else
				echo "Number not valid"
		 fi
	else
		echo "Number not valid"

fi

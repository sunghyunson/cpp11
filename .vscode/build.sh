#!/bin/bash

makeFileName="Makefile"
PWD=$1
cd "$PWD"
# depth=0
root="/"
found="true"

while [[ ! -f "$makeFileName" ]]
do
	# echo "PWD : $PWD"
	cd ..
	# depth=$depth+1
	# if (( $depth > 10 ))
	# then
	# 	found="false"
	# 	break
	# fi
	if [[ "$PWD" = "$root" ]]
	then
		found="false"
		break
	fi
done

if [[ "$found" = "false" ]]
then
	echo "ERROR --> no make file"
	exit 1
else
	make $2
fi

#echo "Compiled Dir is : $PWD"
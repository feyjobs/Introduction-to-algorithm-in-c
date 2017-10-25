#!/bin/bash
i=1
RANDOM=$(date +%s)
while [[ i -le 7 ]]
do
	echo $RANDOM 
	let "i+=1"
done

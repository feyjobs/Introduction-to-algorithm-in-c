#!/bin/bash
i=1
RANDOM=$(date +%s)
while [[ i -le 10000 ]]
do
	echo 100
	let "i+=1"
done

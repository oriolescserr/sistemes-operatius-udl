#!/bin/bash

total=0;
avg(){
	total=$((total + $1))
}

val(){
	if [ $1 -lt -10000 ] || [ $1 -gt 10000 ]; then
		exit -1
	fi
}

read nr
if [ $nr -lt 1 ] || [ $nr -gt 500 ]; then
	exit -1
fi

for i in $(seq 1 $nr); do
	read x
	val $x
	avg $x
done

echo "scale=3; $total/$nr" | bc 

#avg=$((sum/nr))

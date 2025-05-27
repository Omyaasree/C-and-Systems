#!/usr/bin/bash

gcc -o asserts asserts.c -lm

Inputs=( "not a number" \
	"bad 100.0" \
	"-15" \
	"" \
	"-0" \
	"+0" \
	"0" \
	"16.0" \
	"17.5" )
	

LEN=${#Inputs[@]}

index=0
while [ $index -lt $LEN ]
do
	echo " "
	echo ${Inputs[$index]}
	echo ${Inputs[$index]} | asserts
	index=$(($index + 1))
done


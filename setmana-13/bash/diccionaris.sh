#!/bin/bash

declare -A FRUITES

FRUITES=(
["Poma"]="Oriol"
["Pera"]="Bernat"
)

for FRUITA in ${!FRUITES[@]}; do
	echo "$FRUITA - ${FRUITES[$FRUITA]}"
done



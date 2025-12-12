#!/bin/bash

FRUITES=(
"Poma"
"Pera"
"Mango"
"Kiwi"
)

USUARIS=(
"Oriol"
"Eric"
"Albert"
"Marc"
)

for i in ${!FRUITES[@]}; do
	echo "${FRUITES[i]} - ${USUARIS[i]}"
done

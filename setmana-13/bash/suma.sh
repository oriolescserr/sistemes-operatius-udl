#!/bin/bash
NUM1=5
NUM2=10
#RESULTAT=$((NUM1 + NUM2)) 
#RESULTAT=$(expr $NUM1 + $NUM2)
let RESULTAT=NUM1+NUM2
echo "La suma de $NUM1 i $NUM2 es: $RESULTAT"

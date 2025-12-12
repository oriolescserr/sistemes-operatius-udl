#!/bin/bash

declare -A DICT

DICT=(
["jordi"]="profe"
["marc"]="alumne"
["eric"]="alumne"
)

echo "${!DICT[@]}"
echo "Tria una persona:"
read P

[ -z "${DICT[$P]}" ] && echo "Persona no valida" && exit 1

echo "Quin és el rol de la persona?"
echo "${DICT[@]}"
read S
[ "$S" == "${DICT[$P]}" ] && echo "correcte" || echo "incorrecte!"


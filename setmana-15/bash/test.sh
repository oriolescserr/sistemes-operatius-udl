!#/bin/bash
declare -a inputs=("input1" "input2" "input3" "input4" "input5")
declare -a expecteds=("5.000" "5175.240" "4696.947" "" "")

for i in ${!inputs[@]}; do
    output=$(bash ch1.sh < ${inputs[$i]})
    if [ "$output" == "${expecteds[$i]}" ]; then
        echo "Test $i passed"
    else
        echo "Test $i failed"
        echo "Expected: ${expecteds[$i]}"
        echo "Got: $output"
    fi
done

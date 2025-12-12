cat > ch01.data << 'EOT'
102
#El zero vol dir que és hexadecimal, (echo "071" | bc) --> 71
071 
210
153
EOT

clear
cat ch01.data
declare -i SUM=0

while read X; do
    temp=`echo $X | bc`
    SUM+=$X
done < ch01.data

echo "Suma: $SUM != 536"
rm -f ch01.data

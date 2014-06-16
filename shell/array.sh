#!/usr/bin/env sh
declare -A phone
phone=([jim]=135 [tom]=136 [lucy]=158)
echo $phone

for key in ${!phone[*]}
do
    echo "$key -> ${phone[$key]}"
done


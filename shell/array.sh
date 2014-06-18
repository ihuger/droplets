#!/bin/bash

#array
arr=(1 2 3 4 5)
arr[5]=10
echo ${arr[0]} #1  (index by 0)
echo ${arr[*]} #1 2 3 4 5 (all elements)
echo ${arr[@]} #1 2 3 4 5 (all elements)
echo ${#arr[*]} #5 (length)

for num in ${arr[@]} 
do
    printf '%d\t' $num
done

echo

#map
declare -A phone
phone=([jim]=135 [tom]=136 [lucy]=158)
phone[new]=111
echo '$phone no value : '$phone
echo  '${phone[*]} is : '${phone[*]}
echo  '${!phone[*]} is : '${!phone[*]}
echo  '${#phone[*]} is : '${#phone[*]}

for key in ${!phone[*]}
do
    echo "$key -> ${phone[$key]}"
done


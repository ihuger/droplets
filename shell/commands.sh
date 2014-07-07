#!/usr/bin/env sh

###cat
cd /tmp
file="test.tmp"
touch $file
echo "\n\n\nabc\tcde\tde\t" > $file
echo "cat -------------------"
cat $file
echo "cat -s-------------------"
cat -s $file
echo "cat -T-------------------"
cat -T $file
echo "cat -n-------------------"
cat -n $file
echo "cat -b-------------------"
cat -b $file
echo "cat -sb-------------------"
cat -sb $file


###find


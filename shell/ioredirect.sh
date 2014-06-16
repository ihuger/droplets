#!/usr/bin/env sh
: > file1
cat file1
echo '123223423' > file1
cat file1
exec 3<> file1
cat file1
read -n 4 <&3
cat file1
echo "d" >&3
exec 3>&-
cat file1

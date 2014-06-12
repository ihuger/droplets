#!/usr/bin/env sh

function callback {
    echo "nothing"
    sleep 3
}

tmpfile="/tmp/mt.tmp"
mkfifo $tmpfile
exec 6<>$tmpfile
rm $tmpfile

thread=2
for((i=0;i<$thread;++i)); do
    echo
done >& 6

num=23
for((i=0;i<$num;++i)); do
    read -u6
    {
        callback && {
            echo "finished $i"
        } || {
            echo "wrong $i"
        }
        echo >&6
    }&
done

wait
exec 6>&-

exit 0

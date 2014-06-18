#!/usr/bin/env sh

usage(){
    echo "shell functions:"
    echo "rule 1: must be declared before function can be used ,
        a bit like in c language"
    echo "usage: $0 filename"
    exit 1
}
[ $# -eq 0 ]  && usage

is_file_exists(){
    echo "loacl variable"
    local f="$1"
    echo "return stat"
    globalV=100
    [ -f "$f" ] && return 0 || return 1
}

is_file_exists "$1" && echo $globalV
if [ $?!=0 ]
then 
    echo "$1 not found"
else
    echo "$1 found"
fi

#readonly -f is_file_exists





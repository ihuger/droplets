#!/usr/bin/env sh

#date
printf "current date :\t %s\n" "`date`"
#date +%s
printf "current date second:\t %d\n" `date +%s`
date --date "Jan 20 2010"

date "+%d %B %Y"


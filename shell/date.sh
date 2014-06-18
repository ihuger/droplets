#!/usr/bin/env sh

#1.时区的区别
#http://en.wikipedia.org/wiki/Time_zone : Most Unix-like systems, including Linux and Mac OS X, keep system time as UTC (Coordinated Universal Time). Rather than having a single time zone set for the whole computer, timezone offsets can vary for different processes. Standard library routines are used to calculate the local time based on the current timezone, normally supplied to processes through the TZ environment variable. This allows users in multiple timezones to use the same computer, with their respective local times displayed correctly to each user. Time zone information most commonly comes from the IANA time zone database. In fact, many systems, including anything using the GNU C Library, can make use of this database.
#1.1 UTC: 世界标准时间，现在统一使用此标准
#1.2 GTC: 格林威治时间(与UTC差别很小）
#1.3 CST：中国东八区+0800时间，在中国linux下默认使用此时间
date -d 'TZ="UTC"'

#date
printf "current date :\t %s\n" "`date`"
#date +%s
printf "current date second:\t %d\n" `date +%s`
date --date "Jan 20 2010"

date "+%d %B %Y"
date +%s #UTC seconds

date +%Y-%m-%d\ %H:%M:%S

#-d
date -d '2014-06-07'
#n days
date -d '+n days' #after
date -d '-n days' #before
#n months 
date -d '+n months' #after
date -d '-n months' #before
#n years
date -d '+n years' #after
date -d '-n years' #before

#Convert seconds since the epoch (1970-01-01 UTC) to a date
date -d '@seconds'


#-s
#set system time
#date -s '2014-06-17'






#!/usr/bin/env sh
#using $

#1. var
a=10
echo $a

#2. parameter substitution
#${}
#2.1 ${parameter}
#same as $parameter
id=${a}

#2.2 ${parameter-default},${parameter:-default}
#If parameter not set, use default.
var1=100
var2=200
echo ${var1-$var2} #100
#           ^          Note the $ prefix.
echo ${var3-$var2} #200  #var3 unset
default_var=300
echo ${1:-$default_var}

#Both forms nearly equivalent. The : makes a difference only when parameter has been declared and is null, as above.

#2.3 ${parameter=default}, ${parameter:=default}
    #If parameter not set, set it to default.
echo ${var3=abc} #abc
echo ${var3=xyz} #abc

#2.4 ${parameter+alt_value}, ${parameter:+alt_value}
    #If parameter set, use alt_value, else use null string
param0=
a24=${param0+900}
echo "a24=$a24"

#2.5 ${parameter?err_msg}, ${parameter:?err_msg}
    #If parameter set, use it, else print err_msg and abort the script with an exit status of 1.
p25=
echo "${p25?p25 null}"
#: ${1?"need import at least one argument"}



echo current file name `basename ${0}`
##3 Variable length / Substring removal
#3.1 ${#var}
v31=kdfjaksdflakjsdlkfajld3293
echo $v31 length is ${#v31}

###removal
#3.2 ${var#Pattern}, ${var##Pattern} from begining
echo ${v31} rm k*j  using \${v31#k*j} is ${v31#k*j}
echo ${v31} rm k*j  using \${v31##k*j} is ${v31##k*j}
#3.3 ${var%Pattern}, ${var%%Pattern} from end
echo ${v31} rm d*3  using \${v31%d*3} is ${v31%d*3}
echo ${v31} rm d*3  using \${v31%%d*3} is ${v31%%d*3}
# #,% shortest
# ##,%% longest
# Remember, # and ## work from the left end (beginning) of string,
#           % and %% work from the right end.



##4
#Variable expansion / Substring replacement
#4.1 ${var:pos}
    #Variable var expanded, starting from offset pos.
v41=saldjflajsdji000
echo 'v41' is $v41
echo '${v41:2}' is ${v41:2}
#4.2 ${var:pos:len}
    #Expansion to a max of len characters of variable var, from offset pos. See Example A-13 for an example of the creative use of this operator.
echo '${v41:2:4}' is ${v41:2:4}
#4.3 ${var/Pattern/Replacement}
    #First match of Pattern, within var replaced with Replacement.
    #If Replacement is omitted, then the first match of Pattern is replaced by nothing, that is, deleted.
echo '${v41/s*j/xxx}' is ${v41/s*j/xxx}

#4.4 ${var//Pattern/Replacement}
    #Global replacement. All matches of Pattern, within var replaced with Replacement.
    #As above, if Replacement is omitted, then all occurrences of Pattern are replaced by nothing, that is, deleted.
echo '${v41//dj/}' is ${v41//dj/}

#4.5 ${var/#Pattern/Replacement}
    #If prefix of var matches Pattern, then substitute Replacement for Pattern.
echo '${v41/#sa/#}' is ${v41/#sa/#}

#4.6 ${var/%Pattern/Replacement}
    #If suffix of var matches Pattern, then substitute Replacement for Pattern
echo '${v41/%j*0/%}' is ${v41/%j*0/%}


#${!varprefix*}
#Matches names of all previously declared variables beginning with varprefix.

echo '${!v*}' is ${!v*}

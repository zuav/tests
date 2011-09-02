#!/bin/sh
echo "number of args is: " $#

if [ "$#" -ne "1" ] ; then
    echo "Number of arguments is not equal to 1"
fi

echo $0

#!/bin/sh

list="1 2 3"

for i in $list
do
    echo $i
done

gcc_vers="4.7 4.6 4.4.3"

for j in $gcc_vers
do
    echo GCC-$j
done

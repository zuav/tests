#!/bin/bash

#gcc_versions="gcc4_6 gcc4_8 gcc4_9"
gcc_versions="4.6 4.8 4.9"
gcc_versions_2="4.8 4.9"
abis="armeabi armeabi-v7a x86 mips armeabi-v7a-hard arm64-v8a x86_64 mips64"

declare -a built_libs

#for ver in $gcc_versions; do
#    v=gcc${ver/\./_}
#    built_libs["$v"]="armeabi"
#done
#
#for i in $gcc_versions; do
#    v=gcc${i/\./_}
#    echo ${built_libs["$v"]}
#done 
#
#for i in $gcc_versions; do
#    v=gcc${ver/\./_}
#    built_libs["$v"]=
#done 

for ver in $gcc_versions_2; do
    v=gcc${ver/\./_}
    for abi in $abis; do
        built_libs[$v]="${built_libs[$v]} $abi"
    done
done

built_libs[0]="armeabi"
built_libs[1]="armeabi mips"
built_libs[0]="armeabi mips x86"


for i in $gcc_versions; do
    v=gcc${i/\./_}
    echo $v: ${built_libs["$v"]}
done 

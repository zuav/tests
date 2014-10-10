#!/bin/bash

#gcc_versions="gcc4_6 gcc4_8 gcc4_9"
gcc_versions="4.6 4.8 4.9"
abis="armeabi armeabi-v7a x86 mips armeabi-v7a-hard arm64-v8a x86_64 mips64"

declare -a built_libs

for ver in $gcc_versions; do
    built_libs["$ver"]="armeabi"
done

for i in $gcc_versions; do
    echo ${built_libs["$i"]}
done 

for ver in $gcc_versions; do
    for abi in $abis; do
        built_libs[$ver]="${built_libs[$ver]} $abi"
    done
done

for i in $gcc_versions; do
    echo ${built_libs["$i"]}
done 


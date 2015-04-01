#!/bin/bash

#. vars.sh
#./catvars.sh

abis="armeabi armeabi-v7a x86 mips armeabi-v7a-hard arm64-v8a x86_64 mips64"
ver="4.8"

#echo ${abi/64/""}

for abi in $abis ; do
    if [ "${abi/64/}" != "$abi" -a "$ver" = "4.8" ]; then
        echo "$abi = $abi"
    fi
done
   

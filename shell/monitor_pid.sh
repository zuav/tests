#!/bin/bash

VM_NAME="cryptovm"
DELAY=3

while [ : ]
do
    PID=`ps | grep xl | grep $VM_NAME | awk '{ print $1;}'`
    if [ "xyz$PID" != "xyz" ]
    then
        logger -s -p debug -t start_crypto_vm "$VM_NAME works"
    else
        logger -s -p info -t start_crypto_vm "$VM_NAME was terminated!"
        break
    fi
    sleep $DELAY
done

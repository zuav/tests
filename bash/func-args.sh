#!/bin/bash

foo()
{
    echo "arg0: " $0
    echo "arg1: " $1
    echo "arg2: " $2

    echo "all arg before shift: " $*
    shift
    echo "all arg after  shift: " $*
}


foo arg1 arg2 arg3

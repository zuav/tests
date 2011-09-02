#!/bin/sh

if [ "$#" -gt "0" ] ;
then
    cmd=$1
    shift 1
    echo 'cmd=' $cmd
    echo '$*=' $* ;
else
    echo No args were given
    echo 'cmd=' $cmd
    echo '$*=' $* ;
fi

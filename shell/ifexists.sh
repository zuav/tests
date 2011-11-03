#!/bin/sh

hostname="fornost"
#hostname=`hostname -s`

if [ ! -d ~/src/configs/$hostname ]
then
    echo "No config dir for host: $hostname"
else
    echo "There is config dir for host: $hostname"
    ls -la ~/src/configs/$hostname
fi


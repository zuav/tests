#!/bin/bash

if (( $1 != 6 )) && (( $1 != 7 )); then
    echo "Bad number: $1"
else
    echo "Good number: $1"
fi

#!/bin/bash

sys=bsd
list="lin win mac"

echo "sys = $sys"
echo "list = $list"
echo "${list/$sys}"

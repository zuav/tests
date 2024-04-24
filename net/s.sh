#!/bin/bash

sleep 2
./scatter-gather-unix-socket /tmp/sock1 AA 500 &
./scatter-gather-unix-socket /tmp/sock1 BB 500 &

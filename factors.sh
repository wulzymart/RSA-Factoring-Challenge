#!/usr/bin/bash
./factors.py $1
gcc factors.c -o fact
./fact $1
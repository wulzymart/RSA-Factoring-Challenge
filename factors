#!/bin/python3
from sys import argv
nums = []
try:
    if len(argv) > 1:
        with open(argv[1], "r") as file:
            try:
                nums = [int(l) for l in file.readlines()]
            except:
                pass
except:
    pass
for num in nums:
    inc = num % 2 + 1
    a = b = 1
    while a == 1 and b < num:
        b += inc
        if num % b == 0:
            a = num // b
    print(f"{num}={a}*{b}")
#!/usr/bin/python3
import sys
from math import isqrt

def factorize(number):
    if number % 2 == 0:
        print(f"{number}={number // 2}*{2}")
        return True
    if number % 3 == 0:
        print(f"{number}={number // 3}*{3}")
        return
    if number % 5 == 0:
        print(f"{number}={number // 5}*{5}")
        return
    if number % 7 == 0:
        print(f"{number}={number // 7}*{7}")
        return
    for div in range(11, int(number ** 0.5), 2):
        if number % div == 0:
            print(f"{number}={number // div}*{div}")
            return
    
    # If no factorization is found, number is prime
    print(f"{number}={number}*1")
    return

if len(sys.argv) != 2:
    print("Usage: python factors.py <file>")
    exit(1)

filename = sys.argv[1]

try:
    with open(filename, 'r') as file:
        for line in file:
            number = int(line)
            factorize(number)
except FileNotFoundError:
    print("Error opening file")
    exit(1)

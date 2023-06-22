#!/usr/bin/python3
import sys
from math import isqrt

def factorize(number):
    div = 2
    if number % div == 0:
        print(f"{number}={number // div}*{div}")
        return True
    div = 3
    while div <= div * div:
        if number % div == 0:
            print(f"{number}={number // div}*{div}")
            return True
        div += 2
    
    # If no factorization is found, number is prime
    print(f"{number}={number}*1")
    return False

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

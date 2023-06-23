#!/usr/bin/python3
import ctypes
from sys import argv


def factorise(number):
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


factor = ctypes.CDLL("./libprime.so")
factor.factorise.argtypes = [ctypes.c_longlong]
if len(argv) != 2:
    print("Usage: python factors.py <file>")
    exit(1)

filename = argv[1]
try:
    with open(filename, 'r') as file:
        for line in file:
            number = int(line)
            if number < 100000000000000000:
                factor.factorise(number)
            else:
                factorise(number)
                
except FileNotFoundError:
    print("Error opening file")
    exit(1)

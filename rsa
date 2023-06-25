#!/usr/bin/python3
import sys
from math import gcd

def pollards_rho(n):
    if n % 2 == 0:
        return 2

    x = 2
    y = 2
    d = 1

    f = lambda x: (x**2 - 1) % n

    while d == 1:
        x = f(x)
        y = f(f(y))
        d = gcd(abs(x - y), n)

    return d

def factorize(number):
    factor = pollards_rho(number)

    if factor is None:
        print(f"{number}={number}*{1}")
    else:
        co_factor = number // factor
        print(f"{number}={factor if factor > co_factor else co_factor}*{factor if factor < co_factor else co_factor}")

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

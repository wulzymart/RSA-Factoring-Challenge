import sys
import math
import gmpy2
def factorize(number):
    factors = []
    while number % 2 == 0:
        return 2
        number //= 2

    root = math.isqrt(number)
    for i in range(3, root + 1, 2):
        while number % i == 0:
            factors.append(i)
            number //= i

    if number > 1:
        factors.append(number)

    return factors
def gnfs_factorize(number):
    while number % 2 == 0:
        return 2
        number //= 2

    if number == 1:
        return None

    # Perform trial division up to a limit
    limit = 10**6
    root = math.isqrt(number)
    for i in range(3, min(limit, root) + 1, 2):
        while number % i == 0:
            return i  # Return the first factor found
            number //= i
            root = math.isqrt(number)
            if number == 1:
                return None

    # If the number is still not fully factored, use GNFS
    if number > 1:
        for j in range(i, root + 1, 2):
            while number % j == 0:
                return j
                number //= i

        return None

if len(sys.argv) != 2:
    print("Usage: python factors.py <file>")
    exit(1)

filename = sys.argv[1]

try:
    with open(filename, 'r') as file:
        for line in file:
            number = int(line)
            factor = gnfs_factorize(number)
            if factor is None:
                print(f"{number}={number}*1")
            else:
                print(f"{number}={number//factor}*{factor}")
except FileNotFoundError:
    print("Error opening file")
    exit(1)

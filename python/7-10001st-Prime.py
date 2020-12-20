"""
**************************************************************
    Problem 7 - Project Euler

    10001st prime

    Date:   [07 JAN 2019]
    Author: [CastleBomber]
**************************************************************
"""

# What is the 1001st prime number?

from sieveOfEratosthenes import SieveOfEratosthenes

def main():

    primes = dict()
    max_value = 106000
    spot = 10001
    loop_count = 0

    primes = SieveOfEratosthenes(max_value)
    print(primes[spot])

main()

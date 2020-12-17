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

    primes = set()
    x = 6

    primes = SieveOfEratosthenes(x)

    for i in primes:
        print(i)
    

main()

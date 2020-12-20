## Python program to print all primes smaller than or
#  equal to n using Sieve of Eratosthenes

#  going to change:
#  return array

def SieveOfEratosthenes(max_value):

    dictOfPrimes = dict()

    # boolean array prime[...] all entries true
    prime = [True for i in range(max_value+1)]
    p = 2
    key = 1

    while (p * p <= max_value):
        if (prime[p] == True):
            for i in range(p * 2, max_value+1, p):
                prime[i] = False
        p += 1

    for value in range(2, max_value):
        if prime[value]:
            dictOfPrimes[key] = value
            key = key + 1

    return dictOfPrimes

## Python program to print all primes smaller than or
#  equal to n using Sieve of Eratosthenes

def SieveOfEratosthenes(max_value):

    global max
    global primes
    max = max_value
    primes = dict()

    primeChecked = getPrimes(max_value)
    setPrimes(primeChecked)

    return primes

# returns primeCheck -
#         boolean array with 1's corresponding to primes
def getPrimes(max_value):
    # if max_value = 4, prime[11111] ~= [{0}{1}{2}{3}{4}]
    primeCheck = [True for i in range(max_value+1)]
    p = 2 # skip 0,1 not added to primes

    while (p * p <= max_value):
        if (primeCheck[p] == True):
            for i in range(p * 2, max_value+1, p):
                primeCheck[i] = False
        p += 1

    return primeCheck

# goes through boolean array
# neglects 0's (non prime)
# adds 1's (primes)
def setPrimes(primeChecked):
    key = 1

    for value in range(2, max):
        if primeChecked[value]:
            primes[key] = value
            key = key + 1
"""
**************************************************************
    Problem 5 - Project Euler

    Smallest Multiple
    
    Date:   [20 DEC 2018]
    Author: [CastleBomber]
**************************************************************
"""

# 2520 is the smallest number that
# can be divided by each of the numbers
# from 1 to 10 without any remainder.

# What is the smallest positive number
# that is evenly divisible by all of the
# numbers from 1 to 20? Answer: 232792560
from sieveOfEratosthenes import SieveOfEratosthenes

def driver():

    smallestNumber = 0
    x = 20 # arbitrary
    primes = set()
    finalSetToCheck = set()
    
    primes = SieveOfEratosthenes(x)
    finalSetToCheck = generateSet1ThroughX(x)

    while True:
        smallestNumber = find(primes, smallestNumber)
        if check(finalSetToCheck, smallestNumber):
            break

    print("*:", smallestNumber)

## Part 1:
# Find a suitable "perhaps" option
# *May not be correct because we are only checking
#  divisibility by primes, much faster than alwasys checking 1-x
#
#  May be called multiple times
#
#  @param
#       primes - set to help us speed search for our hunted #
#       smallestNumber - initially 0, but will be increasing as we hunt
#  @return # that may be what we are hunting for,
#           will need to check in part 2
#  
def find(primes, smallestNumber):
    truths = 0 # check for how many primes our # is div by
    
    while len(primes) > truths:
        smallestNumber += 1
        truths = 0
        for i in primes:
            if smallestNumber%i: # No, not divisible
                break
            else: # yes, divisible
                truths += 1
    return smallestNumber

##  Part 2:
#  Check part 1's, which was indeed divisible by primes
#  @param
#       finalCheck - set of #'s 1 through x
#       smallestNumber - number to check, given from part 1
#  @return truth value, whether indeed the # we are hunting for
#
def check(finalCheck, smallestNumber):
    finalTruths = 0
    while len(finalCheck) > finalTruths:
        for z in finalCheck:
            if smallestNumber%z: # No, not divisible
                return False
            else: # yes, divisible
                finalTruths+=1
    return True

 
## Used in Part 2, set of all #'s to divide into smallestNumber
#  @param
#       x - arbitrary value, the highest # to check
#  @return set of #'s 1 through x
#
def generateSet1ThroughX(x):
    mySet = set()
    
    for y in range(1, x+1):
        mySet.add(y)

    return mySet

    
    
driver()

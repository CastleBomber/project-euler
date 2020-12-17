"""
**************************************************************
    Problem 3 - Project Euler

    Largest Prime Factor
    
    Date:   [13 OCT 2018]
    Author: [CastleBomber]
**************************************************************
"""
# Largest prime factor
# -Problem 3- 
# The prime factors of 13195 are 5, 7, 13 and 29.
#
# What is the largest prime factor of the number 600851475143 ?
from math import *

# find the largest prime factor
# ex: 13195 -> 5, 7, 13, [29]
def main():
    
    try:
        number = int(600851475143)
#        number = 13195
        highestCheck = 0
        largeArray = []
        
        
        highestCheck = int(sqrt(number))
        #print(highestCheck)
        largeArray = generateNumbers(highestCheck)

        removeZeroAndOne(largeArray)
        
        smallArray = cutArray(largeArray, number)
        smallArray = finalCut(smallArray)

        print(smallArray)

    except ValueError:
        print("ERROR")

## -START-
# Need to create table of Sieve of Erastosthenes
#
# @param
#       sqrt(# we are checking), going to need to eliminate #'s
#
# @return array with too many #'s
# 
def generateNumbers(highestCheck):
    myLargeArray = []
    for i in range(highestCheck+1):
        myLargeArray.append(i)

    return myLargeArray

# from gNums(),
# we need to eliminate 0, 1
# @param
#       full array, will be taking off 0 && 1
#
# @return D.N.E. so cool!
# 
def removeZeroAndOne(largeArray):
        if 0 in largeArray :
            n = largeArray.index(0)
            largeArray.pop(n)

        if 1 in largeArray :
            n = largeArray.index(1)
            largeArray.pop(n)

# from gNums() - > rZAO(),
# we need to put in work! time to cut this baby down!!
# @param
#       array w/o #'s: 0 && 1
#
# @return array w/ early prime factors
# 
def cutArray(largeArray, number):
    fakePrimes = []

    for cur in largeArray:
        if number%cur == 0:
            fakePrimes.append(cur)

    return fakePrimes

# from gNums() - > rZAO() -> cA(),
#
# Deciding to make a copy of smallArray && check
# prime values amongst them
#
# don't forget! copying a list needs .copy()
#
# @param
#       array of potential primes
#
# @return full array w/ all prime factors
#                                 
def finalCut(smallArray):
    newArray = []
    copy = smallArray.copy() # important!

    for outer in smallArray:
        for inner in smallArray:
            if outer%inner == 0 and outer!=inner and outer in copy:
                copy.remove(outer)

                 
    return copy
        
                                  
                                

main()

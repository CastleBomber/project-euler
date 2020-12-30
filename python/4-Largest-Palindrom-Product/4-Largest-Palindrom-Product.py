"""
**************************************************************
    Problem 4 - Project Euler

    Largest Palindrome Product
    
    Date:   [19 DEC 2018]
    Author: [CastleBomber]
**************************************************************
"""
## A palindromic number reads the same both ways.
## The largest palindrome made from
## the product of two 2-digit numbers
## is 9009 = 91 × 99.
##
## Find the largest palindrome made from
## the product of two 3-digit numbers.
## Ex: RssTssR = xyz * abc

def main():
    try:
        maxi = 999
        largestPalindrome = 0
        productsSet = set()
        palindromeSet = set()

        productsSet = generate(maxi, productsSet)
        palindromeSet = findPalindromes(productsSet)
        largestPalindrome = max(palindromeSet) # cool set operation!!

        print(largestPalindrome)
        
    except ValueError:
        print("ERROR")

# Need to create all multiples
#
# @param
#       maxi - highest value
#       numSet - empty set
#
# @return set of all our multiples
# 
def generate(maxi, numSet):
    a = 1
    b = 1

    while a <= maxi:
        while b <= maxi:
            numSet.add(a*b)
            b+=1
        b=1
        a+=1

    return numSet

# Need to find palindromes
#
# @param
#       numSet - set of all our products
#
# @return set all palindromes
# 
def findPalindromes(productsSet):
    palindromes = set()

    for item in productsSet:
        string = str(item)
        revString = string[::-1]
        if string == revString:
            palindromes.add(item)

    return palindromes        

main()

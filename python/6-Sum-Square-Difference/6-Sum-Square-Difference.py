"""
**************************************************************
    Problem 6 - Project Euler

    Square Sum Difference
    
    Date:   [7 JAN 2019]
    Author: [CastleBomber]
**************************************************************
"""

# Sum of squares
#   First 10 natural #'s:
#       (1^2) + (2^2) + ... + (10^2) = 385
#
# Square of sum
#   First 10 natural #'s:
#       (1 + 2 + ... + 10)^2 = (55^2) = 3025
#
# Difference (3025 - 385) = 2640
#
# Find the diff b/n:
#   (sum of squares of first 100 natural #'s) - (square of sum)

def main():
    sumSquares = 0 # small
    squareSUM = 0 # big
    firstTen = 100 # arbitrary 10 vs 100
    naturalNums = []

    naturalNums = generate(firstTen)

    sumSquares = findSumSquares(naturalNums) # small
    squareSUM = findSquareSum(naturalNums) # big
    print(squareSUM - sumSquares)

## sum of (squares)
#
#  @param
#       natNums - arbitrary list
#  return the sum after squaring ALL #'s in list
#
def findSumSquares(natNums):
    sumSquares = 0

    for i in natNums:
        sumSquares += (i**2)

    return sumSquares

## square of (sums)
#
#  @param
#       natNums - arbitrary list
#  return the square after adding up ALL #'s is list
def findSquareSum(natNums):
    mySum = 0
    squareSum = 0

    for i in natNums:
        mySum += i
        
    squareSum = mySum**2
    
    return squareSum

## We need a list of #'s 1 through x
#
#  @param
#       highest - max value of list
#  return list w/ #'s 1 through highest
def generate(highest):
    listOfNaturalNums = []

    for i in range(1, highest+1):
        listOfNaturalNums.append(i)

    return listOfNaturalNums

main()

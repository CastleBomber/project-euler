#!/usr/bin/env python
from functions import *
"""
**************************************************************
    Problem 8 - Project Euler

    Date:   [1 JAN 2021]
    Author: [CastleBomber]
**************************************************************
"""

def main():
    thousandDigits = getThousandDigits()
    thirteenAdjacentDigitsList = setThirteenAdjacentDigits(thousandDigits)
    adjacentDigitsWithoutZeros = getAdjacentDigitsWithoutZeros(thirteenAdjacentDigitsList)
    products = multiplyEachDigit(adjacentDigitsWithoutZeros)
    greatestProduct = getGreatestProduct(products)
    print(greatestProduct) #Answer: 23514624000

main()

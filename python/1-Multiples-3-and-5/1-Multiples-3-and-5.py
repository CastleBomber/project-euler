"""
**************************************************************
    Problem 1 - Project Euler
    
    Date:   [13 OCT 2018]
    Author: [CastleBomber]
**************************************************************
"""

def main() :
    try:
        thousand = int(1000)
        ten = int(10)
        sum = 0

        for x in range(1, thousand) :
            if x%3 == 0 or x%5 == 0:
                sum = sum + x

        print(sum)

    except ValueError:
            print("ERROR")

main()

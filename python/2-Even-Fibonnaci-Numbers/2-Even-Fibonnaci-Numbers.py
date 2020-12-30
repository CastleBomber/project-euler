"""
**************************************************************
    Problem 2 - Project Euler
    
    Date:   [13 OCT 2018]
    Author: [CastleBomber]
**************************************************************
"""

def main() :
    try:
        terms = int(4000000)
        sum = 1
        evenSum = 0 # our return
        fibarray = [] # 1, 2, 3...
        fibarray.append(sum) 
        pos = 1
        
        # 1, 2, 3, 5*, 8, 13, 21, 34, 55, 89
        for x in range(1, terms) :
            sum = sum + pos
            
            fibarray.append(sum)
            pos = fibarray[-2]
            fibarray.pop(0)
            if sum %2 == 0:
                evenSum += sum
            if sum >= 4000000:
                break
            
        #print("sum: ", sum)
        print("evenSum: ", evenSum) # 4613732

    except ValueError:
            print("ERROR")

main()

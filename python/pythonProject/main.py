def solution(A):
    pairs = 0

    for i in A:
        if (i < len(A) - 1):
            if ((A[i] + A[i + 1]) % 2 == 0):
                pairs = pairs + 1
                i = i + 2
        elif (i >= (len(A) - 1)):
            if ((A[i] + A[0]) % 2 == 0):
                pairs = pairs + 1
        if (i > len(A)):
            break
    print (pairs)
    return pairs

A = [0,1]
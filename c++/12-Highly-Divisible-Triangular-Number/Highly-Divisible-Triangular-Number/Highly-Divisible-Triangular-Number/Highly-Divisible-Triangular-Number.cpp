/*
    Author: CBOMBS
    Date: June 20th, 2022

    Project Euler: #12 - Highly Divisible Triangular Number

    The sequence of triangle numbers is generated by adding the natural numbers.
    So the 7th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28.
    The first ten terms would be:

    1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

    S(1) = 1
    S(2) = 3 = 1 + 2
    S(3) = 6 = 1 + 2 + 3
    S(4) = 10 = ...

    Let us list the factors of the first seven triangle numbers:

     1: 1
     3: 1,3
     6: 1,2,3,6
    10: 1,2,5,10
    15: 1,3,5,15
    21: 1,3,7,21
    28: 1,2,4,7,14,28

    We can see that 28 is the first triangle number to have over five divisors (aka 6)

    What is the first triangle number to have over five hundred divisors? (aka 501+)
*/

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>

using namespace std;


/*
    Triangle numbers:

    1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

    S(1) = 1
    S(2) = 3 = 1 + 2
    S(3) = 6 = 1 + 2 + 3
    S(4) = 10 = 1 + 2 + 3 + 4
    S(5) = 15 = 1 + 2 + 3 + 4 + 5
    ...
*/
void getTriangleNumbers(vector<int>& triangleNumbers, int largestPossible) {

    int base = 1;
    int sum = 1;

    while(sum < largestPossible) {

        triangleNumbers.push_back(sum);
        base++;
        sum += base;
    }
}

/*

*/
void getNumberWithOverXFactors(vector<int>& triangleNumbers, int minDivisors) {
}

void checkHowManyFactors(vector<int>& triangleNumbers) {

}

/*
    triangleNums :      1, 3, 6, 10, 15, 21, 28 ...
    factors      :  28: 1, 2, 4, 7, 14, 28
    mysteryNumber:   ?: 1, x2, ..., x499, x500, ..., ?
*/
int main()
{
    vector<int> triangleNums;
    int minimumDivisors = 500;
    int largestPossibleTriangleNumber = 100000000;

    getTriangleNumbers(triangleNums, largestPossibleTriangleNumber);
    checkHowManyFactors(triangleNumbers.end());
    //getNumberWithOverXFactors(triangleNums, minimumDivisors);
}

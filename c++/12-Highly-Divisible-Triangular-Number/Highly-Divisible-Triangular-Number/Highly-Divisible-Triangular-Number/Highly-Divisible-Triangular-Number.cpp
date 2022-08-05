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
    This class stores information for each triangle number
*/
class Triangle{

    protected:
        int number;
        vector<int> factors;

    public:
        Triangle(int triangleNumber, vector<int>& _factors) {
            
            number = triangleNumber;
            factors = _factors;
        }
};


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
vector<int> getTriangleNumbers(int largestPossible) {

    int base = 1;
    int sum = 1;
    vector<int> triangleNums;

    while(sum < largestPossible) {

        triangleNums.push_back(sum);
        base++;
        sum += base;
    }

    return triangleNums;
}

/*



*/
vector<int> getFactors(int number) {

    vector<int> factors;

    for (int i = 0; i < number; i++) {

        if ((number % i) == 0) {

        }

    }

    return factors;
}

/*
    triangleNums :      1, 3, 6, 10, 15, 21, 28 ...
    factors      :  28: 1, 2, 4, 7, 14, 28
    mysteryNumber:   ?: 1, xf2, ..., xf499, xf500, ..., ?
*/
int main()
{
    int minimumDivisorsRequested = 500;
    int largestPossible = 100000000;
    int triangleNum = 1;
    vector<int> factors;
    vector<int> triangleNumbers;
    vector<Triangle> triangleObjects;

    triangleNumbers = getTriangleNumbers(largestPossible);

    for(int i = 0; i < triangleNumbers.size(); i++) {

        triangleNum = triangleNumbers[i];
        factors = getFactors(triangleNumbers[i]);

        if (factors.size() >= minimumDivisorsRequested) {

            Triangle t(triangleNum, factors);
            triangleObjects.push_back(t);
        }
    }

    for (auto &t : triangleObjects) {

        //cout <<  << endl;
    }
}

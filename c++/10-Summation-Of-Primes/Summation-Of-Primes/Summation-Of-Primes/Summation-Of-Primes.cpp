/*
    Author: CBOMBS
    Date: May 25th, 2022

    Project Euler: #10 Summation Of Primes

    The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

    Find the sum of all the primes below two million.

    Solution: 142913828922

*/
#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;
void SieveOfEratoshenes(int max);
long double sum = 0;

int main()
{
    const unsigned int max = 2000000;
    SieveOfEratoshenes(max);
    printf("%Lf", sum);
}

/*
* Initially creates all true boolean array
* Ex: If max is 4, primes[11111] ~= [{0} {1} {2} {3} {4}]
* 
* After the algorightm, 1's corresponding to primes
*/
void SieveOfEratoshenes(int max) 
{
    bool* primes = new bool[max + 1];
    memset(primes, true, max+1);

    for (unsigned int i = 2; i * i <= max; i++) {
        if (primes[i] == true) {
            for (unsigned int j = i * 2; j <= max; j += i) {
                primes[j] = false;
            }
        }
    }

    for (unsigned int p = 2; p <= max; p++) {
        if (primes[p] == true) {
            sum = sum + p;
        }
    }

    delete[] primes;
}
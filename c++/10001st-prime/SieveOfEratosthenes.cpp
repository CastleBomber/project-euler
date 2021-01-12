#include <iostream>
#include <unordered_map>
#include <vector>
#include "HeaderFunctions.h"
using namespace std;

vector<int> getPrimes(int maxValue); // must declare function prototypes
vector<int> setPrimes(vector<int> primeChecked);

/* 
int maxValue -
    wisely chosen cap, must know primes are within
  
 returns primes -
    the 0th && 1st value to be added is 2
    all the rest are true primes 
*/
vector<int> SieveOfEratosthenes(int maxValue)
{
    vector<int> primeChecked;
    primeChecked = getPrimes(maxValue);

    vector<int> primes;
    primes = setPrimes(primeChecked);

    return primes;

}

/* 
intially,
if maxValue = 4, primeCheck[11111] ~= [{0}{1}{2}{3}{4}]

returns primeCheck -
    vector with 1's corresponding to primes
    0's corresponding to non-primes 
*/
vector<int> getPrimes(int maxValue) {
    int indexZeroToMaxValue = maxValue + 1;
    vector<int> primeCheck(indexZeroToMaxValue, 1);
    int p = 2; // skip 0, 1 not added to primes

    while (p * p <= maxValue) {
        if (primeCheck[p] == 1) {
            for (int n = p * 2; n < maxValue + 1; n = n + p) {
                primeCheck[n] = 0;
            }
        }
        p += 1;
    }

    return primeCheck;
}

/* 
goes through primeChecked
    neglects 0's (non prime) 
    adds 1's (primes)

returns primes -
    the 0th && 1st value to be added is 2
    all the rest are true primes 
*/
vector<int> setPrimes(vector<int> primeChecked) {
    int maximum = primeChecked.size() - 1;
    vector<int> primes;
    primes.push_back(2); // filling up primes[0]

    for (int i = 2; i < maximum; i++) {
        if (primeChecked[i] == 1) {
            primes.push_back(i);
        }
    }
      
    return primes;
}
#include <iostream>
#include <unordered_map>
#include <vector>
#include "HeaderFunctions.h"
using namespace std;

int main()
{
    vector<int> primes;
    int maxValue = 106000; // wisely chosen, primes must be within
    int spot = 10001;

    primes = SieveOfEratosthenes(maxValue);
    cout << primes[spot] << endl;
    cin.get();
}

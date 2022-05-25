/*
    Author: Richie CastleBomber
    Date: May 20th, 2022
    

    Project Euler: #9 Special Pythagorean Triplet
    
    A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
    a^2 + b^2 = c^2
    For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
    There exists exactly one Pythagorean triplet for which a + b + c = 1000.
    Find the product abc.

    Solution: a = 200, b = 375, c = 425, abc = 31875000
*/
#include <iostream>
using namespace std;

int main()
{
    int a = 0;
    int b = 0;
    int c = 0;
    unsigned int m;
    unsigned int n;
    const unsigned int z = 1000; // a + b + c

    for (m = 1; m < z; m++) {
        for (n = 1; n < z; n++) {

            // Special method for finding SPT
            a = ((pow(m, 2)) - (pow(n, 2)));
            b = 2 * (m * n);
            c = (pow(m, 2)) + (pow(n, 2));

            if (a < 0) {
                break;
            }

            if ((a + b + c) == 1000) {
                cout << a << endl;
                cout << b << endl;
                cout << c << endl;
                cout << (a * b * c) << endl << endl;
            }
        }
    }

}


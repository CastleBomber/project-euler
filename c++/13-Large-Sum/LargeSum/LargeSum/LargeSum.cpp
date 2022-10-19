/*
    Author: CBOMBS
    Date: September3 7th, 2022

    Project Euler: #13 - Large Sum

    Acknowledgement: Tutorial's Point Sum of Two Large Numbers in C++

    Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.
*/

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

/*
    Adds two very large numbers given as strings

    Source: Tutorial's Point's function
*/
string addBigNumbers(string number1, string number2) {

    if (number1.length() >  number2.length()) {

        swap(number1, number2);
    }

    string sum = "";
    int len1 = number1.length();
    int len2 = number2.length();
    int digitDiff = len2 - len1;
    int carry = 0;
    int intSum;

    for (int i = len1 - 1; i >= 0; i--) {

        intSum = ((number1[i] - '0') + (number2[i+digitDiff] - '0') + carry);
        sum.push_back(intSum%10 + '0');
        carry = intSum/10;
    }

    for (int i = digitDiff-1; i >= 0; i--) {

        intSum = ((number2[i] - '0') + carry);
        sum.push_back(intSum%10 + '0');
        carry = intSum/10;
    }

    if (carry) {

        sum.push_back(carry + '0');
    }

    reverse(sum.begin(), sum.end());

    return sum;
}

/*

*/
int main()
{
    ifstream infile("Number.txt"); // read input from file
    string line;
    vector<string> numbers; // stores the file's numbers as strings
    string sum = "0";

    // go through file and load up numbers
    while (!infile.eof()) {

        getline(infile, line);
        numbers.push_back(line);
    }

    // add up all the numbers from numbers
    for (int x = 0; x < numbers.size(); x++) {

        sum = addBigNumbers(sum, numbers[x]);
    }

    cout << sum << endl;

    return 0;
}

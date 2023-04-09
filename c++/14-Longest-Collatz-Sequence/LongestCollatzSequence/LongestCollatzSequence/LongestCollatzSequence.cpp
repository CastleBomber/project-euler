/**
 * Author: CBOMBS
 * Date: December 26th, 2022
 * Project Euler: #14 Longest Collatz Sequence
 *
 * The following iterative sequence is defined for the set of positive integers:
 *
 * n → n/2 (n is even)
 * n → 3n + 1 (n is odd)
 *
 * Using the rule above and starting with 13, we generate the following sequence:
 *
 * 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
 *
 * It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms.
 * Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
 *
 * Which starting number, under one million, produces the longest chain?
 *
 * Examples:
 * 1 - returns 1 becuase its the number of terms in the sequence
 * 2 - return 2
 *
 * References:
 * https://www.enjoyalgorithms.com/blog/top-down-memoization-vs-bottom-up-tabulation
 *
 * Shortcuts:
 *  VS Code:
 * 	    c++ VS Code clang-formatter: shift+alt+f
 *
 *  Visual Studio:
 *      code folding: select region, ctrl+m+m
 *      full screen: shift+alt+enter
 *
 */

#include <iostream>
#include <map>
#include <string>
#include <string_view>

using namespace std;

int collatzSequence(map<int, int> t, int startingNumber);
int tabulization(map<int, int> t, int number);
int isOdd(int number);

/**
 *  Increases odd numbers and decreases even numbers
 *  with the goal of finishing at 1
 *
 *  returns
 *      count - number of terms to reach 1, includes starting number
 */
int collatzSequence(map<int, int> t, int startingNumber)
{
    int finalNumber = startingNumber; // decrements through sequence until reaches 1
    int count = 1;                    // number of numTerms to reach 1
    int sequenceLength = 0;

    // Error Check
    if (startingNumber < 1)
    {
        printf("Error: value should not be less than 1\n");

        return 0;
    }

    // Loops and updates the starting number until 1 is reached
    while ((finalNumber != 1))
    {
        sequenceLength = tabulization(finalNumber);

        if (isOdd(finalNumber))
        {
            // Odd number -> increased and becomes even
            finalNumber = (3 * finalNumber) + 1;
        }
        else
        {
            // Even number -> decreases and becomes odd || even
            finalNumber = finalNumber / 2;
        }

        count++;
    }

    return count;
}

/**
 * Checks if number is in the table
 *
 * tabulization - top-down dynamic approach,
 * uses extra memory to store solutions to sub problems
 * avoids recomputation
 *
 * Ex: if the number is in the table:
 * input number = 5, return = 6  (includes itself)
 * 5 → 16 → 8 → 4 → 2 → 1
 *
 * table.emplace() - make them a pair and add to map
 *
 */
int tabulization(map<int, int> &t, int number)
{
    map<int, int> table = t;
    int sequenceLength = 0;

    for (auto& item : table)
    {
        // Performance boost, exits if assumes no entry for number
        if (it.begin() < it.end())
        {
            cout << key << value << endl;
        }

        if (i < 0)
        {
            table.emplace(key, val);
            sequenceLength = 1;
        }
    }

    return sequenceLength;
}

int isOdd(int number)
{
    int status = 0;

    if ((number % 2) > 0)
    {
        status = 1;
    }

    return status;
}

int main()
{
    int starting = 1;          // checks for which number gives the largest sequence
    int maximum = 1000000;     // largest number to check
    int numTerms = 0;          // number of terms to cascade down to 1
    int producer = 0;          // produces the longest chain in the sequence
    int greatestTermCount = 0; // stores the highest value of numTerms from producer
    map<int, int> table;       // stores LCS values of numbers

    while (starting != maximum)
    {
        numTerms = collatzSequence(table, starting);

        if (greatestTermCount < numTerms)
        {
            greatestTermCount = numTerms;
            producer = starting;
        }

        starting++;
    }

    std::cout << "The number: " << producer
              << " produces the longest chain with: " << greatestTermCount << " terms\n";
}

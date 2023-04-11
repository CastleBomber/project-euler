﻿/**
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

int collatzSequence(map<int, int> table, int startingNumber);
int checkTabulization(map<int, int> table, int number);
int setTabulization(map<int, int> table, int key, int value);
int isOdd(int number);

/**
 *  Increases odd numbers and decreases even numbers
 *  with the goal of finishing at 1
 *
 * Mimimum acceptable value is 1. All lower numbers will be returned as an error.
 * For this reason, we set: sequenceCount = 1
 *
 *  returns
 *      sequenceCount - number of terms to reach 1, includes starting number
 */
int collatzSequence(map<int, int> &table, int startingNumber)
{
    map<int, int> collatzTable = table;
    int finalNumber = startingNumber; // decrements through sequence until reaches 1
    int sequenceCount = 1;            // number of terms for given number to reach 1

    // Error Check
    if (startingNumber < 1)
    {
        printf("Error: value should not be less than 1\n");

        return 0;
    }

    // Loops and updates given number until its value is 1
    while ((finalNumber != 1))
    {
        // Check if number already in the table
        if (sequenceCount = checkTabulization(collatzTable, finalNumber))
        {
            return sequenceCount;
        }

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

        sequenceCount++;
    }

    collatzTable.emplace(startingNumber, sequenceCount); // Add to table

    return sequenceCount;
}

/**
 * Checks if number is in the table
 *
 * If the given number is not in the table, return 0
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
int checkTabulization(map<int, int> &table, int number)
{
    map<int, int> tableCheck = table;
    int sequenceLength = 0;

    for (auto &item : tableCheck)
    {
        if (number == item.key)
        {
            return item.value;
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
    int currentTerm = 1;          // checks for which number gives the largest sequence
    int maxTerm = 1000000;        // largest number to check
    int numTerms = 0;             // number of terms to cascade down to 1
    int longestChainProducer = 0; // produces the longest chain in the sequence
    int longestChainCount = 0;    // stores the highest value of numTerms from longestChainProducer
    map<int, int> table;          // stores LCS values of numbers

    while (currentTerm != maxTerm)
    {
        numTerms = collatzSequence(table, currentTerm);

        if (longestChainCount < numTerms)
        {
            longestChainCount = numTerms;
            longestChainProducer = currentTerm;
        }

        currentTerm++;
    }

    cout << "The number: " << longestChainProducer
         << " produces the longest chain with: " << longestChainCount << " terms\n";
}

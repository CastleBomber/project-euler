/*
    Author: CBOMBS
    Date: December 26th, 2022

    Project Euler: #14 Longest Collatz Sequence

    The following iterative sequence is defined for the set of positive integers:

    n → n/2 (n is even)
    n → 3n + 1 (n is odd)

    Using the rule above and starting with 13, we generate the following sequence:

    13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1

    It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms.
    Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

    Which starting number, under one million, produces the longest chain?
*/

#include <iostream>

int collatzSequence(int number){

  int count = 0;

  while ((startingNumber != 1) || (startingNumber != 2)) {
      if(isOdd){
          n1 = (3*startingNumber) + 1;
      } else {
          n2 = startingNumber/2;
      }
      count++;
  }

  return count;
}

int main()
{
    int startingNumber = 13;
    int steps = 0; // steps to turn startingNumber to 1

    steps = collatzSequence(startingNumber);

    std::cout << "Number of steps: " << steps << "\n";
}

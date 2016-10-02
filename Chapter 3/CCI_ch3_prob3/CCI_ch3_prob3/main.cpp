/* Cracking the Coding Interview, McDowell 5th Ed, 2011
   Chapter 3: Problem 3. 

   Implement a data structure that utilizes a series of stacks,
   where when one stack reaches capacity (assuming there is such a capacity),
   another stack is begun. Push() and Pop() should behave the same
   as with a regular stack.

   Solutions by vnpjeremy.
*/

#include "SpillStack.h"

/* So this seems to me to be just "implement a stack that has a vector
   of stacks acting as one, where elements progress after a designated 
   cutoff. */
int main()
{
    SpillStack<int> testStack1;
    for(size_t ii = 0; ii < 12; ++ii)
        testStack1.push(static_cast<int>(ii));

    std::vector<int> out1 = testStack1.printCurrentStack();

    int dummy = 0;
}
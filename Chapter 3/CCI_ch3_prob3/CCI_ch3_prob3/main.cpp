/* Cracking the Coding Interview, McDowell 5th Ed, 2011
   Chapter 3: Problem 3. 

   Implement a data structure that utilizes a series of stacks,
   where when one stack reaches capacity (assuming there is such a capacity),
   another stack is begun. Push() and Pop() should behave the same
   as with a regular stack.

   Follow-up: Implement (or talk through the implementation of) a function
   popAt(int index) which performs a pop operation on a sub-stack.

   Solutions by vnpjeremy.
*/

#include "SpillStack.h"

/* So this seems to me to be just "implement a stack that has a vector
   of stacks acting as one, where elements progress after a designated 
   cutoff. */
int main()
{
    SpillStack<int> testStack1;
    for(size_t ii = 0; ii < 6; ++ii)
        testStack1.push(static_cast<int>(ii));
    testStack1.pop();
    for(size_t ii = 5; ii < 12; ++ii)
        testStack1.push(static_cast<int>(ii));

    //try populating 6, popping to 5, and pushing again

    //std::vector<int> out1 = testStack1.printCurrentStack();

    std::vector<int> fullPrint;
    for(size_t ii = 0; ii < 12; ++ii)
    {
        fullPrint.push_back(testStack1.top());
        testStack1.pop();
    }

    /* Test re-populating, and then some. Empty stacks should exist. */
    for(size_t ii = 0; ii < 21; ++ii)
        testStack1.push(static_cast<int>(ii));


    std::vector<int> fullPrint2;
    for(size_t ii = 0; ii < 21; ++ii)
    {
        fullPrint2.push_back(testStack1.top());
        testStack1.pop();
    }


    int dummy = 0;
}
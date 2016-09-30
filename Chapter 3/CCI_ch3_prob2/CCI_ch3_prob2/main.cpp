/* Cracking the Coding Interview, McDowell 5th Ed, 2011
   Chapter 2: Problem 2.
   
   Design a stack which has a function min() operating in O(1) time.
   Push and Pop should also be O(1) time.
   
   Solutions by: vnpjeremy*/
#include "StackWithMin.h"


/* Because we need constant time push, pop, and min, we can't use
   a vector or an array. Use a list. 
   
   Obviously, here, something has to give. Push and Min could easily
   be O(1), but for Pop to be O(1), we have to break the boundaries and
   use space as a tradeoff. Otherwise we would always have to search the
   length of the stack for the new Min value.
   
   This really really pushes at a *sorted* stack, but we won't ever get
   O(1) time with that. Basically it pushes towards a tree.
   
   Approach 1: 2*N space solution: each node will need a T data member 
   to store the snapshot of the min at that time.
 */
int main()
{
    /* Approach 1:  */
    SLList<int> listWithDiffNodes;
    /* Stack:
    5   min: 1
    1   min: 1
    4   min: 2
    6   min: 2
    2   min: 2
    */

    listWithDiffNodes.push_front(2); //Push for a stack is push_front
    listWithDiffNodes.push_front(6);
    listWithDiffNodes.push_front(4);
    listWithDiffNodes.push_front(1);
    listWithDiffNodes.push_front(5);
    
    std::vector<int> out1    = listWithDiffNodes.flatten();
    std::vector<int> outMins = listWithDiffNodes.flattenMins();

    for(size_t ii = 0; ii < 5; ++ii)
    {
        int const tmp1 = listWithDiffNodes.front();
        int const min1 = listWithDiffNodes.min();
        listWithDiffNodes.pop();
    }

    /* Approach 2: */
    int dummy = 0;

    //test
}

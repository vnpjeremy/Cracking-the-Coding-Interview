/* Cracking the Coding Interview, McDowell 5th Ed, 2011
   Chapter 2: Problem 5.
   
   Implement a queue using two stacks.
   
   Solutions by: vnpjeremy*/

#include "QueueWithStacks.h"
#include <vector>

/* Something to qualitatively consider is that stacks empty
   their contents reversed, so that N^(mod2==0) is forward and 
   any N^(mod2!=0) is reversed. Two stacks take advantage of this
   and end up with the second stack always in the *proper* order,
   so that it is the inversion of the first stack.
   
   It works out because we are only ever pull off the last element. */
int main()
{
    QueueWithStacks<int> queue1;

    for(size_t ii = 0; ii < 6; ++ii)
        queue1.push(ii);

    int const test1 = queue1.front();
    /* Contents:
       {5 4 3 2 1 0} */
    assert(test1 == 0);

    queue1.pop();
    queue1.pop();
    queue1.pop();

    int const test2 = queue1.front();
    /* Contents:
       {5 4 3} */
    assert(test2 == 3);

    for(size_t ii = 12; ii < 18; ++ii)
        queue1.push(ii);
    /* Contents:
       {5 4 3 17 16 15 14 13 12} */

    int const test3 = queue1.front();
    assert(test3 == 12);

    std::vector<int> out1;
    while(!queue1.empty())
    {
        out1.push_back(queue1.front());
        queue1.pop();
    }

    assert(out1.front() == 12); //first to be dequeued is 12 from last modification
    assert(out1.back() == 5);   //last to be dequeued is 5 from last modification

    QueueWithStacks<int> stack2;
    stack2.push(6);
    int const test4 = stack2.front();
    assert(test4 == 6);
    stack2.pop();

    assert(stack2.empty());

    int dummy = 0;
}
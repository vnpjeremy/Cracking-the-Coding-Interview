/* Cracking the Coding Interview, McDowell 5th Ed, 2011
   Chapter 2: Problem 2.
   
   Design a stack which has a function min() operating in O(1) time.
   Push and Pop should also be O(1) time.
   
   Solutions by: vnpjeremy*/
#include "StackWithMin.h"

int main()
{
    StackWithMin<int> st1;
    for(size_t ii = 0; ii < 8; ++ii)
        st1.push(ii);
    st1.push(-4);
    st1.push(41);


    //test
}
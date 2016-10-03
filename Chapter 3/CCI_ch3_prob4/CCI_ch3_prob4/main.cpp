/* Cracking the Coding Interview, McDowell 5th Ed, 2011
   Chapter 2: Problem 4.
   
   Solve the Towers of Hanoi problem using stacks. 3
   towers, N discs.
   
   Solutions by: vnpjeremy*/


/* It is well-known that this problem can be solved in 
   2*N-1 operations. */

#include "hanoiStacks.h"

/* There are 3 generalized steps here:
   (1) Move N-1 from A to B, using C, freeing up the biggest disc, N.
   (2) Move disc N to C
   (3) Move the other N-1 discs from B to C, using A
*/
int main()
{
    hanoiStacks stack1(6);
    stack1.solve();

    int debug = 0;
}
/* Cracking the Coding Interview, McDowell 5th Ed, 2011
   Chapter 2: Problem 5
   
   You have 2 numbers represented by a LL. Each node is a digit.
   They are in reverse order. Write an addition function that retuns
   the result as a LL. */

#include "SLList.h"

//As noted previously, DO NOT put templates in global scope in implementation
//files. Put in headers.

//could be made a binary operator()
template <class T>
SLList<T> add( SLList<T> const& lhs, SLList<T> const& rhs )
{
    /* Will add the trailing nodes first, then proceed
       to leading ones. Leading nodes may not align. */
}

int main()
{
    SLList<int> num1, num2;
    num1.push_back(1);
    num1.push_back(0);
    num1.push_back(0);

    num2.push_back(5);
    num2.push_back(7);



}
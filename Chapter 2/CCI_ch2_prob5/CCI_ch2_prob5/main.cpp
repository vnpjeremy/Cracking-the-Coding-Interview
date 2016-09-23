/* Cracking the Coding Interview, McDowell 5th Ed, 2011
   Chapter 2: Problem 5
   
   You have 2 numbers represented by a LL. Each node is a digit.
   They are in reverse order. Write an addition function that retuns
   the result as a LL. */

#include "SLList.h"
#include <vector>

//As noted previously, DO NOT put templates in global scope in implementation
//files. Put in headers.

//could be made a binary operator()
template <class T>
SLList<T> add( SLList<T> const& lhs, SLList<T> const& rhs )
{
    /* Will add the trailing nodes first, then proceed
       to leading ones. Leading nodes may not align. */

    /* This is an advantageous way of storing integers
       as the inverse would require one to reverse-traverse
       the LL, an extremely inefficent process unless double-linkage
       exists. */

    /* Padding will be faster if .size() is O(1) instead of O(n). */
    size_t const size1 = lhs.size(), size2 = rhs.size();
    if(size1 < size2)
    {
        size_t const diff = size2 - size1;
    }
    else if(size2 < size1)
    {

    }

    SLList<T>::Node<T> const *curLHS = lhs.m_head, *curRHS = rhs.m_head;
    SLList<T>      output;
    while(curLHS || curRHS)
    {
        //T num1(), num2();
        if(curLHS && curRHS)
        {
            output.push_front(curLHS->m_data + curRHS->m_data);
            curLHS = curLHS->m_next;
            curRHS = curRHS->m_next;
        }
        else if(curLHS)
        {
            output.push_front(curLHS->m_data);
            curLHS = curLHS->m_next;
        }
        else
        {
            output.push_front(curRHS->m_data);
            curRHS = curRHS->m_next;
        }
    }

    return output;
}

int main()
{
    int arg1();
    int arg2 = 0;
   // int arg3 = arg1 + arg2;

    SLList<int> num1, num2; 
    num1.push_front(1);
    num1.push_front(0);
    num1.push_front(6);

    num2.push_front(5);
    num2.push_front(6);
    std::vector<int> flat0  = num1.flatten();
    std::vector<int> flat00 = num2.flatten();

    SLList<int>      output = add(num1, num2);
    std::vector<int> flat1 = output.flatten();

    int dummy = 0;
}
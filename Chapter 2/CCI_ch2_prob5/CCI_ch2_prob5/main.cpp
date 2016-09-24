/* Cracking the Coding Interview, McDowell 5th Ed, 2011
   Chapter 2: Problem 5
   
   You have 2 numbers represented by a LL. Each node is a digit.
   They are in reverse order. Write an addition function that retuns
   the result as a LL. 
   
   Part 2: the digits are in forward order. Repeat.*/

#include "SLList.h"
#include <vector>

//As noted previously, DO NOT put templates in global scope in implementation
//files. Put in headers.

/* Will add the trailing nodes first, then proceed
   to leading ones. Leading nodes may not align. */

/* This is an advantageous way of storing integers
   as the inverse would require one to reverse-traverse
   the LL, an extremely inefficent process unless double-linkage
   exists. */

/* This algorithm is O(n + m) time and O(1) space. (O(n) space if
   you consider the output) */
template <class T, typename = std::enable_if_t<std::is_integral<T>::value>>
SLList<T> add( SLList<T> const& lhs, SLList<T> const& rhs )
{
    SLList<T>::Node<T> const *curLHS = lhs.m_head, *curRHS = rhs.m_head;
    SLList<T>      output;
    T carry = {};
    while(curLHS || curRHS)
    {
        T const lhsVal = curLHS ? curLHS->m_data : 0;
        T const rhsVal = curRHS ? curRHS->m_data : 0;
        T const sum = lhsVal + rhsVal + carry;
        T const answer = sum % 10;
        carry = sum > 10 ? 1 : 0;
        output.push_back(answer);

        curLHS = curLHS ? curLHS->m_next : curLHS;
        curRHS = curRHS ? curRHS->m_next : curRHS;
    }

    return output;
}

template <class T, typename = std::enable_if_t<std::is_integral<T>::value>>
void addRecursive(SLList<T> const& lhs, SLList<T> const& rhs, SLList<T> & output)
{
    //The book solves this recursively, but that doesn't make sense to me.
    //It feels like shoehorning the solution in when a perfectly logical
    //loop approach would work fine. Will try if there is time.
}


template <class T>
SLList<T> addForwardFormat(SLList<T> & lhs, SLList<T> & rhs)
{
#if 0
    /* For non-reverse storage in LL containers: */
    /* Padding will be faster if .size() is O(1) instead of O(n). */
    size_t const size1 = lhs.size(), size2 = rhs.size();
    if(size1 < size2)
    {
        size_t const diff = size2 - size1;
        T const      val = {};
        for(size_t ii = 0; ii < diff; ++ii)
            lhs.push_front(val);
    }
    else if(size2 < size1)
    {
        size_t const diff = size1 - size2;
        T const      val = {};
        for(size_t ii = 0; ii < diff; ++ii)
            rhs.push_front(val);
    }
#endif

    return SLList<T>();
}


int main()
{
    SLList<int> num1, num2; 
    num1.push_front(1);
    num1.push_front(0);
    num1.push_front(6);

    num2.push_front(6);
    std::vector<int> verify1  = num1.flatten();
    std::vector<int> verify2 = num2.flatten();

    SLList<int>      output = add(num1, num2);
    std::vector<int> verify3 = output.flatten();

    SLList<double> disabledListType1, disabledListType2;
    disabledListType1.push_back(2.01);
    disabledListType2.push_back(1.05);
    //SLList<double> shouldntWork = add(disabledListType1, disabledListType2);

    SLList<int> num3, num4;
    num3.push_back(1);
    num3.push_back(0);
    num3.push_back(6);

    num4.push_front(6);
    std::vector<int> verify5 = num3.flatten();
    std::vector<int> verify6 = num4.flatten();

    SLList<int>      output2 = addForwardFormat(num1, num2);
    std::vector<int> verify7 = output.flatten();

    int dummy = 0;
}
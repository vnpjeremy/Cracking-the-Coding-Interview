/* Cracking the Coding Interview, McDowell 5th Ed, 2011
   Chapter 2: Problem 5
   
   You have 2 numbers represented by a LL. Each node is a digit.
   They are in reverse order. Write an addition function that retuns
   the result as a LL. 
   
   Part 2: the digits are in forward order. Repeat.*/

#include "SLList.h"


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

template <class T>
inline void SLList<T>::recursivePopulateReverse( Node<T> const*   cur,
                                                 std::stack<T> &  output)
{
    if(!cur)
        return;
    output.push(cur->m_data);
    recursivePopulateReverse(cur->m_next, output);
}

template <class T>
inline SLList<T> addForwardFormat(SLList<T> & lhs, SLList<T> & rhs)
{
    /* For non-reverse storage in LL containers: */
    /* Padding will be faster if .size() is O(1) instead of O(n). */
    SLList<T> output;
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

    std::stack<T>       stack1, stack2;
    lhs.recursivePopulateReverse(lhs.m_head, stack1);
    rhs.recursivePopulateReverse(rhs.m_head, stack2);

    T carry = {};
    while(!stack1.empty())
    {
        T const sum = stack1.top() + stack2.top() + carry;
        T const answer = sum % 10;
        carry = sum > 10 ? 1 : 0;
        stack1.pop();
        stack2.pop();
        output.push_front(answer);
    }

    return output;
}


int main()
{
    SLList<int> num1, num2; 
    num1.push_front(1);
    num1.push_front(0);
    num1.push_front(6);

    num2.push_front(6);
    std::vector<int> numerand1  = num1.flatten();
    std::vector<int> numberand2 = num2.flatten();

    SLList<int>      output = add(num1, num2);
    std::vector<int> verifyAddition = output.flatten();

    SLList<double> disabledListType1, disabledListType2;
    disabledListType1.push_back(2.01);
    disabledListType2.push_back(1.05);
    //SLList<double> shouldntWork = add(disabledListType1, disabledListType2);

    SLList<int> num3, num4;
    num3.push_back(1);
    num3.push_back(0);
    num3.push_back(6);

    num4.push_front(6);
    std::vector<int> numerand3 = num3.flatten();
    std::vector<int> numerand4 = num4.flatten();

    SLList<int>      output2 = addForwardFormat(num3, num4);
    std::vector<int> output2Verify = output2.flatten();

    int dummy = 0;
}
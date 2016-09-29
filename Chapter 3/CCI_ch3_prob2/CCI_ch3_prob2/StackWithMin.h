#pragma once
#include <vector>
#include <stack>
#include "SLList.h"

/* Because we need constant time push, pop, and min, we can't use
   a vector or an array. Use a list. 
   
   Obviously, here, something has to give. Push and Min could easily
   be O(1), but for Pop to be O(1), we have to break the boundaries and
   use space as a tradeoff. Otherwise we would always have to search the
   length of the stack for the new Min value.
   
   This really really pushes at a *sorted* stack. That would be a tree,
   and although we could do fairly well in terms of complexity, I don't
   think we'd get O(1) no matter how clever our sorting algorithm. */

template <class T>
class StackWithMin
{
public:
    StackWithMin() :
        m_data()
    {

    }

    /* Must be O(1) */
    void push(T const& data)
    {
        /* Should check to see if we are adding a min */
    }


    /* Must beo O(1) */
    void pop()
    {
        /* Should check to see if we are losing a min */

        //if we pop the min, and the access to min is O(1), how
        //do we keep finding the new min from being O(n)??
    }

    T & top()
    {

    }

    /* Must be O(1) */
    T & min()
    {

    }


private:
    SLList<T>     m_data;
    std::stack<T> m_minRecord;
};
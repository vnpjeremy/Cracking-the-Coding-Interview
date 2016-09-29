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
   
   This really really pushes at a *sorted* stack, but we won't ever get
   O(1) time with that. 
   
   Add a stack that records not only the min value, but previous min values,
   to account for the requirement that pop() remain O(1) time while keeping
   m_min up-to-date. */

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
        if(m_data.empty() || data < m_minRecord.top())
            m_minRecord.push(data);

        m_data.push_back(data);
    }


    /* Must beo O(1) */
    void pop()
    {
        /* Should check to see if we are losing a min */
        if(m_data.front() == m_minRecord.top())
            m_minRecord.pop();

        m_data.pop();
    }

    T & top()
    {
        return m_data.front();
    }

    std::vector<T> flatten() const
    {
        return m_data.flatten();
    }

    /* Must be O(1) */
    T & min()
    {
        return m_minRecord.top();
    }


private:
    SLList<T>     m_data;
    std::stack<T> m_minRecord;
};
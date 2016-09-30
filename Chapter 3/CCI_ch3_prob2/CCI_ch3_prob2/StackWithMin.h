#pragma once
#include <vector>
#include <stack>
#include "SLList.h"

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
        m_data.push_front(data);
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

    /* Caution: can't get at std::stack. This empties the thing. DEBUG ONLY!! */
    std::vector<T> flattenMins()
    {
        std::vector<T> output;
        while(!m_minRecord.empty())
        {
            output.push_back(m_minRecord.top());
            m_minRecord.pop();
        }
        return output;
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


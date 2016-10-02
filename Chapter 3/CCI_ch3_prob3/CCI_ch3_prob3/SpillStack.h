#pragma once
#include <cassert>
#include <stack>
#include <vector>

/* If we don't have an m_size data member on our Stack class,
   it may be advantageous to add it so that .size() is O(1) and 
   not O(n) in this type of use scenario. */
template <class T>
class SpillStack
{
    /* Make some default stack spill-over criteria; artifically
       small for the purposes of this question and solution. */
    static const size_t defaultMaxSize = 5;

public:
    SpillStack() :
        m_maxStackSize(defaultMaxSize),
        m_stackIndex(),
        m_stacks()
    {
    }

    SpillStack(size_t const maxSize) :
        m_maxStackSize(maxSize),
        m_stackIndex(),
        m_stacks()
    {
    }

    void push(T const& data)
    {
        if(m_stacks[m_stackIndex].size() < m_maxStackSize)
            m_stacks[m_stackIndex].push(data);
        else
        {
            m_stacks.push_back(std::stack<T>());
            m_stacks[++m_stackIndex].push(data);
        }
    }

    void pop()
    {
        assert(!m_stacks[m_stackIndex].empty());
    }

    /* CAUTION: This is debug-only, and for stacks!
       It will empty the stack off with pop()s! */
    std::vector<T> printCurrentStack()
    {
        std::vector<T> output;
        while(!m_stacks[m_stackIndex].empty())
        {
            output.push_back(m_stacks[m_stackIndex].top());
            m_stacks[m_stackIndex].pop();
        }
        return output;
    }

private:
    size_t                     m_maxStackSize;
    size_t                     m_stackIndex;
    std::vector<std::stack<T>> m_stacks;
};
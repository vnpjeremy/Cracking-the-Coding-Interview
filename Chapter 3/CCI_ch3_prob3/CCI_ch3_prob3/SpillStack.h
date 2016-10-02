#pragma once
#include <cassert>
#include <stack>
#include <vector>

/* If we don't have an m_size data member on our Stack class,
   it may be advantageous to add it so that .size() is O(1) and 
   not O(n) in this type of use scenario. */

/* Point of consideration:
   This design does not 'shrink', that is, when a large stack
   is populated, popping the thing down to zero won't delete
   the elements of the vector. Deleting elements from a vector
   can be less than optimal, so add that in if desired. */
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
        m_stacks(1) //Populate the first stack in the empty vector
    {
    }

    SpillStack(size_t const maxSize) :
        m_maxStackSize(maxSize),
        m_stackIndex(),
        m_stacks(1)
    {
    }

    void push(T const& data)
    {
        assert(!m_stacks.empty());
        if(m_stacks[m_stackIndex].size() < m_maxStackSize)
            m_stacks[m_stackIndex].push(data);
        else
        {
            /* stack may exist and be empty from previous operations */
            if(m_stacks.size() < m_stackIndex + 2)
                m_stacks.push_back(std::stack<T>());
            m_stacks[++m_stackIndex].push(data);
        }
    }
    
    T & top()
    {
        assert(!m_stacks[m_stackIndex].empty());
        return m_stacks[m_stackIndex].top();
    }

    T const& top() const
    {
        assert(!m_stacks[m_stackIndex].empty());
        return m_stacks[m_stackIndex].top();
    }

    void pop()
    {
        assert(!m_stacks[0].empty());
        if(m_stacks[m_stackIndex].empty())
            --m_stackIndex;

        assert(!m_stacks[m_stackIndex].empty());
        m_stacks[m_stackIndex].pop();
        if(m_stacks[m_stackIndex].empty() && m_stackIndex > 0) //we just popped the last one
            --m_stackIndex;
    }

    /* Careful! Doesn't move the m_stackIndex. */
    void popAt(size_t const stackIndex)
    {
        assert(stackIndex < m_stacks.size());
        assert(!m_stacks[stackIndex].empty());
        m_stacks[stackIndex].pop();
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
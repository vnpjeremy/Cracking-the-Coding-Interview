#pragma once
#include <stack>
#include <vector>

/* If we don't have an m_size data member on our Stack class,
   it may be advantageous to add it so that .size() is O(1) and 
   not O(n) in this type of use scenario. */
template <class T>
class SpillStack
{
public:
    SpillStack() :
        m_stacks()
    {
    }

private:
    std::vector<std::stack<T>> m_stacks;
};
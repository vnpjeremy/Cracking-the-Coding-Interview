#pragma once
#include <stack>

//enable_if integral type
//even IF integral type, what if short, and N > std::numeric_limits<short>::Max()? problem!
//probably can't/shouldn't templatize.

//template <class T>
class hanoiStacks
{
public:
    hanoiStacks() :
        m_numberOfDiscs(3),
        m_stack1(),
        m_stack2(),
        m_stack3()
    {
        populateFirstStack();
    }

    hanoiStacks(size_t const discCount) :
        m_numberOfDiscs(discCount),
        m_stack1(),
        m_stack2(),
        m_stack3()
    {
        populateFirstStack();
    }

    void populateFirstStack()
    {
        for(size_t ii = 0; ii < m_numberOfDiscs; ++ii)
            m_stack1.push(ii);
    }


private:
    /* Could be an array of stack[3] as well. */
    size_t        m_numberOfDiscs;
    std::stack<int> m_stack1;
    std::stack<int> m_stack2;
    std::stack<int> m_stack3;
};
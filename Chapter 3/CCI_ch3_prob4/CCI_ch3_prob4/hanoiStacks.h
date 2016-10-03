#pragma once
#include <stack>
#include <cassert>
//enable_if integral type
//even IF integral type, what if short, and N > std::numeric_limits<short>::Max()? problem!
//probably can't/shouldn't templatize.

//template <class T>
class hanoiStacks
{
public:
    hanoiStacks() noexcept :
        m_numberOfDiscs(3),
        m_stack1(),
        m_stack2(),
        m_stack3()
    {
        populateFirstStack();
    }

    hanoiStacks(size_t const discCount) noexcept :
        m_numberOfDiscs(discCount),
        m_stack1(),
        m_stack2(),
        m_stack3()
    {
        populateFirstStack();
    }

    void populateFirstStack() noexcept
    {
        for(size_t ii = 0; ii < m_numberOfDiscs; ++ii)
            m_stack1.push(ii);
    }

    void moveAtoB()
    {
        assert(!m_stack1.empty());
        m_stack2.push(m_stack1.top());
        m_stack1.pop();
    }
    
    void moveBtoC()
    {
        assert(!m_stack2.empty());
        m_stack3.push(m_stack2.top());
        m_stack2.pop();
    }

    void moveAtoC()
    {
        assert(!m_stack1.empty());
        m_stack3.push(m_stack1.top());
        m_stack1.pop();
    }

private:
    /* Could be an array of stack[3] as well. */
    size_t        m_numberOfDiscs;
    std::stack<int> m_stack1;
    std::stack<int> m_stack2;
    std::stack<int> m_stack3;
};
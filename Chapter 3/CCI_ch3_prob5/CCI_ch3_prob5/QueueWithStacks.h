#pragma once
#include <cassert>
#include <stack>

template <class T>
class QueueWithStacks
{
public:
    QueueWithStacks() noexcept :
        m_stack1(),
        m_stack2()
    {

    }

    /* STL does not offer & output */
    T const& front() const
    {
        assert(!m_stack2.empty());
    }

    /* Although not named so, this is push_back(). */
    void push(T const& data)
    {

    }

    void pop()
    {

    }

    

private:
    std::stack<T> m_stack1;
    std::stack<T> m_stack2;
};
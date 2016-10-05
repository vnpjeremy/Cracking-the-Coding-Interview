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

    void unload()
    {
        while(!m_stack1.empty())
        {
            m_stack2.push(m_stack1.top());
            m_stack1.pop();
        }
    }

    /* STL does not offer & output */
    T const& front()
    {
        unload();
        assert(!m_stack2.empty());
        return m_stack2.top();
    }

    /* Although not named so, this is push_back(). */
    void push(T const& data)
    {
        m_stack1.push(data);
    }

    void pop()
    {
        unload();
        assert(!m_stack2.empty());
        m_stack2.pop();
    }

    bool empty() const
    {
        return m_stack1.empty() && m_stack2.empty();
    }

    size_t size() const
    {
        return m_stack1.size() + m_stack2.size();
    }

private:
    std::stack<T> m_stack1;
    std::stack<T> m_stack2;
};
#pragma once
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

private:
    std::stack<T> m_stack1;
    std::stack<T> m_stack2;
};
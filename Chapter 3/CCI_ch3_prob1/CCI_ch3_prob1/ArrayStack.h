#pragma once
#include <stdexcept>

template <class T>
class arrayStackTriplet
{
public:

    enum stackID { Stack_1, Stack_2, Stack_3 };

    arrayStackTriplet() :
        m_data(),
        m_stackSize(),
        m_indices()
    {

    }

    arrayStackTriplet(size_t size) :
        m_data(),
        m_stackSize(size * 3),
        m_indices()
    {
        m_data = new T[m_stackSize];
        m_indices[1] = size;
        m_indices[2] = 2 * size;
    }

    /* Indexed {0,1,2} */
    void push( T const& input, 
               stackID   stackNumber )
    {
        if(badIncrement(stackNumber))
            throw std::length_error("stack overlap");
        m_data[m_indices[stackNumber]++] = input;
    }

    T & top( stackID  stackNumber )
    {
        return  m_data[m_indices[stackNumber]];
    }

    void pop( stackID  stackNumber )
    {
        m_data[m_indices[stackNumber]--] = 0;
    }

    ~arrayStackTriplet()
    {
        delete [] m_data;
    }

private:

    /* Detect attempts to overlap into next logical container */
    bool badIncrement(stackID stackNumber) const
    {
        bool bad = false;
        if(stackNumber < 2)
        {
            if(m_indices[stackNumber] == m_indices[stackNumber + 1])
                bad = true;
        }
        if(m_indices[stackNumber] == m_stackSize)
            bad = true;
        return bad;
    }

    T      *m_data;
    size_t m_stackSize;
    size_t m_indices[3];
};
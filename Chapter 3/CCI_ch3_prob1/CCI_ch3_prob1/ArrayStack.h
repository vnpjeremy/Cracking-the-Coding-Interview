#pragma once
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
        m_indices[1] = size - 1;
        m_indices[2] = 2 * size - 1;
    }

    /* Indexed {0,1,2} */
    void push( T const& input, 
               size_t   stackNumber )
    {
        if(stackNumber > 2)
            throw std::length_error("stack does not exist");
        m_data[stackNumber++] = input;
    }

    T & top()
    {

    }

    void pop()
    {

    }    

    ~arrayStackTriplet()
    {
        delete [] m_data;
    }

private:

    /* Detect attempts to overlap into next logical container */
    bool badIncrement(size_t const stackNumber) const
    {
        size_t next = stackNumber + 1 > 2 ? 0 : stackNumber + 1;
        if(m_data[stackNumber] == m_data[next])
            return true;
        return false;
    }

    int m_data[];
    int m_stackSize;
    int m_indices[3];
};
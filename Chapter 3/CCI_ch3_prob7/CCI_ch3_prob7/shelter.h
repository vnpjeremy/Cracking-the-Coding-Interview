#pragma once
#include <queue>

template <class T>
class Shelter
{
public:

    enum class AnimalType
    {
        Dog,
        Cat,
        LongestResident
    };

    Shelter() : noexcept
        m_dogs(),
        m_cats()
    {
    }

    /* A pop operation with query arguments */
    adopt()
    {

    }

private:
    std::queue<T> m_dogs;
    std::queue<T> m_cats;
};
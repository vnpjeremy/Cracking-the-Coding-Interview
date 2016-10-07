#pragma once
#include <cassert>
#include <queue>

template <class T>
class Shelter
{
public:

    enum class Animal
    {
        Dog,
        Cat,
        LongestResident
    };

    Shelter() noexcept :
        m_takeANumber(),
        m_dogs(),
        m_cats()
    {
    }

    void push( Animal const preference,
               T const&     goingIn )
    {
        if(preference == Animal::Dog)
        {
            m_dogs.push(goingIn);
        }
        else
        {
            m_cats.push(goingIn);
        }
    }

    /* A pop operation with query arguments */
    void adopt( Animal const preference,
                T &          animalOutput )
    {
        if(preference == Animal::Dog)
        {
            assert(!m_dogs.empty());
            animalOutput = m_dogs.front();
            m_dogs.pop();

        }
        else if(preference == Animal::Cat)
        {
            assert(!m_cats.empty());
            animalOutput = m_cats.front();
            m_cats.pop();
        }
        else
        {
            assert(!m_dogs.empty() || !m_cats.empty());
        }

        --m_takeANumber;
    }

private:
    size_t        m_takeANumber;
    std::queue<T> m_dogs;
    std::queue<T> m_cats;
};
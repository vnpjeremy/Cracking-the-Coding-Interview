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
        Cat
    };

    Shelter() noexcept :
        m_curTimeStamp(),
        m_dogs(),
        m_cats()
    {
    }

    void push( Animal const preference,
               T const&     goingIn )
    {
        if(preference == Animal::Dog)
            m_dogs.push(AnimalNode(m_curTimeStamp++, goingIn));
        else
            m_cats.push(AnimalNode(m_curTimeStamp++, goingIn));
    }

    void popDog( T & animalOutput )
    {
        assert(!m_dogs.empty());
        animalOutput = m_dogs.front().m_data;
        m_dogs.pop();
    }

    void popCat( T & animalOutput )
    {
        assert(!m_cats.empty());
        animalOutput = m_cats.front().m_data;
        m_cats.pop();
    }

    /* A pop operation with query arguments */
    void adoptAnimal( Animal const preference,
                      T &          animalOutput )
    {
        if(preference == Animal::Dog)
            popDog(animalOutput);
        else
            popCat(animalOutput);
    }

    void adoptLongestResident( T & animalOutput )
    {        
        assert(!m_dogs.empty() || !m_cats.empty());        
        if(!m_dogs.empty() && !m_cats.empty())
        {
            /* Case 1: both are populated and timestamp decides */
            if(m_dogs.front().m_timestamp < m_cats.front().m_timestamp)
                popDog(animalOutput);
            else
                popCat(animalOutput);
        }
        else if(!m_dogs.empty())
        {
            /* Case 2: Only dogs left */
            popDog(animalOutput);
        }
        else
        {
            /* Case 3: Only cats left */
            popCat(animalOutput);
        }
    }

private:
    /* We can't even store 2 numbers, as they are indicative of totals, but not chronology. E.g., 
       insert 1 cat , then 100 dogs. The cat should be chosen. How can that be discerned? With a timestamp.
       This will increase space by O(n). We can use a larger size if we know the input will be enormous
       (unsigned long long) 
   */
    size_t                 m_curTimeStamp;

    /* Convenience struct for uniform storage/access in queues */
    struct AnimalNode
    {
        AnimalNode() noexcept :
            m_timestamp(),
            m_data()
        {
        }

        AnimalNode( size_t const time,
                    T const&     input ) noexcept :
            m_timestamp(time),
            m_data(input)
        {
        }

        size_t m_timestamp;
        T      m_data;
    };

    std::queue<AnimalNode> m_dogs;
    std::queue<AnimalNode> m_cats;
};
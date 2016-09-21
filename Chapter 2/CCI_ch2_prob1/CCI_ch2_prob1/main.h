#pragma once
#include <algorithm>
#include <list>
#include <iterator>
#include <unordered_set>

/* Naive: O(n^2). For practice, let's see what this would look like. Space complexity = constant. 
   This algorithm should be stable. Original ordering is preserved. */
template <class T>
void removeDuplicatesNaive(std::list<T> & input)
{
    for(auto itr = input.begin(); itr != input.end(); ++itr)
    {
        auto itr2 = std::next(itr);
        while(itr2 != input.end())
        {
            if(*itr == *itr2)
            {
                itr2 = input.erase(itr2);
                continue;
            }
            ++itr2; //don't double-increment when erasure occurs.
        }
    }
}

/* If we can afford a buffer, we can create an unordered(hash) map.
   Insertion is linear and querying is average constant. So this will be
   an O(n) solution, rather than O(n^2). 
   This algorithm should be stable. Original ordering is preserved. */
template <class T>
void removeDuplicates(std::list<T> & input)
{
    std::unordered_set<T> inputMap;
    for(auto itr = input.begin(); itr != input.end(); )
    {
        auto found = inputMap.find(*itr);
        if(found != inputMap.end())
        {
            itr = input.erase(itr);
            continue;
        }
        inputMap.insert(*itr);
        ++itr;
    }
}

/* If we are constrained on space but want better than O(n^2), we can sort
   the thing. Sorting is n log(n), then unique is O(n) linear. We get
   away with nlog(n) and no buffer requirement for in-place.
   While std::sort is not stable, list::sort is. This algorithm should be stable,
   but the original ordering will NOT be preserved. */

template <class T>
void removeDuplicatesSort(std::list<T> & input)
{
    input.sort();
    input.erase(std::unique(input.begin(), input.end()), input.end());
}
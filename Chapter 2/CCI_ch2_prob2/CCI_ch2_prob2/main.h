#pragma once
#include <list>
#include <iterator>

/* The naive solution is to iterate over the list once,
   count the steps, and then iterate again. Remember .size()
   will be linear if the list implementation does not store
   the size in the data structure. If it did, we could iterate
   once and use size - k to find this element.
   
   The more 'clever' solution, in my opinion, isn't much better,
   as it still requires between N and 2N iterator increments. In
   both cases, the complexity is linear. Below is the dual-iterator
   trick to solve the problem.

   This method is const and does not alter the container. */
template <typename Iterator>
Iterator findKthToLastElement(Iterator const begin,
                              Iterator const end,
                              size_t const   k )
{
    /* Using std::advance for the iterator difference is an easy coding style,
       but safety requires checking k by the size of the list, and list.size()
       is linear. For efficiency, approach a different way. */

    if(begin == end)
        return end;

    /* Handle k > container.size effieciently. Initialize itr2 to
       k spaces from itr1. */
    Iterator itr1 = begin, itr2 = begin;
    for(size_t counter = 0; counter <= k; ++counter)
    {
        if(itr2 == end)
            return end;
        ++itr2;        
    }

    /* Iterate itr2 to the container.end(). Then itr1 is the element
       that is k from the end. */
    while(itr2 != end)
    {
        ++itr2;
        ++itr1;
    }

    return itr1;
}
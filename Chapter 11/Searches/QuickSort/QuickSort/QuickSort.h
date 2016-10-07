#pragma once
#include<cassert>

/* Note:
   Watch the 'famous bug' described in Programming Pearls by Bentley:
   int mid = (low + high) / 2;
   
   It causes overflow for large values. Becomes negative, then indexing
   nukes itself.

   Do:


   */

template <class T>
inline void QuickSort( T            *arr, 
                       size_t const size )
{
    assert(arr);
    assert(size > 0);

    /* 1. Pick a pivot */

    /* 2. Partition so that all values less than pivot come before the pivot */

    /* 3. Recursively apply above steps to sub-array of elements with smaller than pivot,
          as well as same for greater. */


}
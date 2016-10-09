#pragma once
#include <algorithm>
#include<cassert>


/* Note:
   Watch the 'famous bug' described in Programming Pearls by Bentley:
   int mid = (low + high) / 2;
   
   It causes overflow for large values. Becomes negative, then indexing
   nukes itself.

   Do:
   [(low + high) + low - low ] / 2
   [2*low + high - low] / 2
   -->  low + (high-low) / 2
*/

//fun thing to get size
template <class T, size_t N>
size_t inline size1(T (&arr)[N])
{
    return N;
}

/* This implementation assumes an array. Pointer arithmetic
   will have to be replaced with node traveral operations to
   support tree-like structures .
   
   QuickSort will be recursive, so pass the array as well as
   its boundaries. Subsequent calls will be sub-arrays.   
*/
template <class T>
inline void QuickSort( T  *arr, 
                       T  *arrBeg,
                       size_t const  len )
{
    assert(arr);

    /* 1. Pick a pivot */
    T   *midPivot = arr + (arr + len - arr) / 2;
    T   mid = *midPivot;

    /* Can do this a number of different ways, including moving the
       pivot to one side or another for ease of partitioning operations.

       Now instead of juggling two sides around the pivot, you're really
       just moving the pivot and swapping around to achieve partitioning. */
    std::swap(*arr, *midPivot);

    /* 2. Partition so that all values less than pivot come before the pivot */
    partition(arr, midPivot, arr,  arr + len);    

    /* 3. Recursively apply above steps to sub-array of elements with smaller than pivot,
          as well as same for greater. */

    int dummy = 0;
}

//error handling for the input arguments here could be a lot. Consider.
template <class T>
inline void partition( T    *arr,
                       T    *pivot,
                       T    *left,
                       T    *right )
{

    T        *itrSlow = left;      //can re-use, but this is more readable.
    T const  pivotVal = *pivot;    //when we swap the pivot and move to the front, it can be irritating to track.
   
    for(T* itrFast = left; itrFast < right; ++itrFast) //is...this valid, comparint iterators?
    {
        if(*itrFast < pivotVal)
        {
            std::swap(*itrFast, *itrSlow);
            ++itrSlow;
        }
    }

    /* Move pivot to just after the last swap */
    std::swap(*itrSlow, *(right - 1));

    int dummy0 = 0;
}

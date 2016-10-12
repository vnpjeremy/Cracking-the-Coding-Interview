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

/* This is a convention. Array 5 isze, pass arr[0] and 5. Index
   of 5 is one beyond, but could design the interface in the alternative
   way if that is preferable. */
template <class T>
/*inline*/ void QuickSort( T*           arr,
                           size_t const begElement,
                           size_t const oneElementPast ) //this design might be bad for the VERY Max() of the size.
{
    assert(arr);
    assert(oneElementPast > begElement);
    /* Pick a pivot. Should be random, but for now choose the middle.
       rand() is a possibility, but seed is important. Clock dependency
       can be less than 'random' in some cases. */

    /* Partition stuff around the pivot element. */
    if(oneElementPast - begElement > 1)
    {
        size_t const  lastElement = oneElementPast - 1;
        size_t const  mid = begElement + (/*lastElement*/oneElementPast - begElement) / 2;
        T const       pivot = arr[mid];

        size_t leftItr = begElement, rightItr = lastElement;
        while(leftItr < rightItr)
        {
            /* If an element on either side of the pivot is already in
               the right place, skip it. Swap only incorrect elements. */
            while(arr[leftItr] < pivot && leftItr < rightItr)
                ++leftItr;

            while(pivot < arr[rightItr] && leftItr < rightItr)
                --rightItr;

            if(leftItr < rightItr)
            {
                /* Move one past where the element was just swapped */
                std::swap(arr[leftItr], arr[rightItr]);
                ++leftItr;
            }
        }

        /* Partitioned for left and right. Repeate for those two sub-arrays, until
           we end up with size == 1. Watch recursion depth for super-big arrays? */
        QuickSort(arr, begElement, leftItr);
        QuickSort(arr, rightItr, oneElementPast);
    }
    
    int dummy = 9;
}



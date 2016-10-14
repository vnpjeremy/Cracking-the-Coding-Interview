#pragma once
#include <algorithm>
#include <cassert>
#include <iostream>


template <class T, size_t N>
size_t inline sizeOfArr(T (&input)[N])
{
    return N;
}

/* Divide the list into n sublists, each containing 1 element
   Repeatedly merge sublists to produce new sorted sublists 
   until everything is done. */
template <class T>
inline void Merge( T*           arr, 
                       size_t const beg,
                       size_t const mid,
                       size_t const end )
{
    /* Is called with {0,5} and {6,10} for elements [0-9] 
       So R1 should be (low = 0, high < 5 or <= 4) 
       and R2 should be (low = 5, high < 10 or <= 9)*/

    /* O(n) space for helper array */
    size_t const len1 = mid - beg, len2 = end - mid;
    T* helper1 = new T[len1], *helper2 = new T[len2];
    std::copy(arr + beg, arr + mid, helper1);
    std::copy(arr + mid, arr + end, helper2);

    /* Debug help */
    std::cout << " beg " << beg << " mid " << mid << " end " << end << "\n";
    
    /* Merge operation. beg->mid-1 on the first, mid->end on second. */
    size_t     arrIndex = beg, ii = 0, jj = 0;
    while(ii < len1  && jj < len2)
    {
        /* drop in  LHS or RHS depending on comparison */
        if(helper1[ii] <= helper2[jj])
            arr[arrIndex++] = helper1[ii++];
        else
            arr[arrIndex++] = helper2[jj++];
    }

    /* Dump remaining elements if sub-arrays are unequal */
    while(ii < len1)
        arr[arrIndex++] = helper1[ii++];

    /* This is really an 'else' operation, but the conditionals handle it well enough. */
    while(jj < len2)
        arr[arrIndex++] = helper2[jj++];

    delete[] helper1;
    delete[] helper2;
}

template <class T>
inline void MergeSort( T*           arr, 
                       size_t const beg, 
                       size_t const end )
{
    assert(arr);

    /* Nothing to do if there is only one element. */
    if(end - beg > 1)
    {
        /* Find midpoint */
        size_t const mid = beg + (end - beg) / 2;
        /* Recurse for LHS and RHS 
           For a {0,..10} integer set where mid == 5,
           Recurse 1 has {0,4}
           Recurse 2 has {5,9}*/
        MergeSort(arr, beg, mid);
        MergeSort(arr, mid, end);
        Merge(arr, beg, mid, end);
    }
}
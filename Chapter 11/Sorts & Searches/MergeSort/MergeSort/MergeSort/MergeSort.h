#pragma once
#include <algorithm>
#include <cassert>


template <class T, size_t N>
size_t inline sizeOfArr(T (&input)[N])
{
    return N;
}

/* Divide the list into n sublists, each containing 1 element
   Repeatedly merge sublists to produce new sorted sublists 
   until everything is done. */
template <class T>
/*inline*/ void Merge( T*           arr, 
                   size_t const beg, // beg = 3
                   size_t const mid, // mid = 4
                   size_t const end )// end = 5
{
    /* O(n) space for helper array */
    size_t const len1 = mid - beg, len2 = end - mid;       //len = 2
    T* helper1 = new T[len1], *helper2 = new T[len2];
    std::copy(arr + beg, arr + mid, helper1);
    std::copy(arr + mid, arr + end, helper2);
    
    /* Merge operation. beg->mid-1 on the first, mid->end on second. */
    size_t     arrIndex = beg, ii = 0, jj = 0; //arrIndex = 3, ii = 3, jj = 5
    while(ii < len1  && jj < len2)
    {
        /* drop in  LHS or RHS depending on comparison */
        if(helper1[ii] < helper2[jj])
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

    if(end > beg)
    {
        /* Find midpoint */
        size_t const mid = beg + (end - beg) / 2;
        /* Recurse for LHS and RHS */
        MergeSort(arr, beg, mid);
        MergeSort(arr, mid + 1, end);
        Merge(arr, beg, mid, end);
    }
}
#pragma once
#include <algorithm>
#include <cassert>
#include <iterator>

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
    /* O(n) space for helper array */
    T* helper = new T[end - beg];
    std::copy(arr, arr + end, helper);
    //std::copy(std::begin(arr), std::end(arr), std::begin(helper));

    //eh could probably do memset or std::copy


    delete[] helper;
}

template <class T>
inline void MergeSort( T*           arr, 
                       size_t const beg, 
                       size_t const end )
{
    assert(arr && end > beg);

    /* Find midpoint */
    size_t const mid = beg + (end - beg) / 2;
    /* Recurse for LHS and RHS */
    MergeSort(arr, beg, mid);
    MergeSort(arr, mid + 1, end);
    Merge(arr, beg, mid, end);
}
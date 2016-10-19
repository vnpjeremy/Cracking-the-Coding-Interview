#pragma once

template <class T>
inline size_t myBinarySearch( T const*const  arrayInput,
                              size_t const   LH,
                              size_t const   RH,
                              T const        searchValue )
{
    /* Assume ascending order */
    //assert(LH < RH); logical, but this condition is met when the searched for value is the [0] element in the array. Can't include.
    size_t const  midIndex = LH + (RH - LH) / 2;
    T const       mid = arrayInput[midIndex];

    if(mid == searchValue)//oops, missed a case.
        return midIndex;

    if(mid < searchValue)
        return myBinarySearch(arrayInput, midIndex + 1, RH, searchValue);
    if(searchValue < mid)
        return myBinarySearch(arrayInput, LH, midIndex - 1, searchValue);
    return midIndex;
}
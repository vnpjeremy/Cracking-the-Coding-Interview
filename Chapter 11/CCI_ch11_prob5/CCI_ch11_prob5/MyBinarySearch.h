#pragma once
#include <array>
#include <string>
//this is no longer valid for template generiticiy. Strings only.
size_t findMid( std::string const*const  arrayInput,
                size_t const              LH,
                size_t const              RH,
                size_t const              midSeed )
{
    //assume no asserts needed for out-of-bounds calling
    if(!arrayInput[midSeed].empty())
        return midSeed;

    //assume smallest-to-greatest, again, for BS
    size_t candLHS = midSeed - 1, candRHS = midSeed + 1, counterLHS = 1, counterRHS = 1;
    while(1)
    {
        if(candLHS <= RH &&  !arrayInput[candLHS].empty())
            return candLHS;
        if(candRHS <= RH && !arrayInput[candRHS].empty())
            return candRHS;
        candLHS = midSeed - counterLHS++;
        candRHS = midSeed + counterRHS++;

        if(candLHS > RH && candRHS > RH)
            break; //wasn't found. Exit infinite loop.
    }

    return RH;
}

//could pass this as std::aray<std::string, N>. It depends on API preference.
size_t myBinarySearch( std::string const*const  arrayInput,
                       size_t const             LH,
                       size_t const             RH,
                       std::string const        searchValue )
{
    /* Assume ascending order */
    //assert(LH < RH); logical, but this condition is met when the searched for value is the [0] element in the array. Can't include.
    size_t      midIndex = LH + (RH - LH) / 2;
    midIndex = findMid(arrayInput, LH, RH, midIndex);

    std::string const       mid = arrayInput[midIndex];

    if(mid == searchValue)//oops, missed a case.
        return midIndex;

    if(mid < searchValue)
        return myBinarySearch(arrayInput, midIndex + 1, RH, searchValue);
    if(searchValue < mid)
        return myBinarySearch(arrayInput, LH, midIndex - 1, searchValue);
    return midIndex;
}
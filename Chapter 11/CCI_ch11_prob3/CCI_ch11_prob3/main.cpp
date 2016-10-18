/* Cracking the Coding Interview, McDowell 5th Ed, 2011
   Chapter 11: Problem .
   
   Find an element in a previously sorted array that has been
   rotated some N number of times.
   
   Solutions by: vnpjeremy*/
#include <algorithm>
#include <cassert>
/* There has GOT to be a better way of finding the rotation point
   than O(n). Maybe do a modified binary search for that too, so
   once it's found, you basically do 2*logN, which is still LogN? */

/* Binary search overview:
   1. Set LH to first and RH to last element
   2. if L > R, exit. Assumes ordering. Could probably specify the reverse 
      ordering, though.
   3. Set some middle element M = (LH+RH)/2
   4. If Am < T, set LH to M+1 and go to Step 2.
   5. If Am > T, set RH to M-1 and go to Step 2.
   6. Now Am = T, return M
 
   So we can kind of do this. Ish. For the pivot discovery:
   */


template <class T>
inline size_t findPivot( T const*const  arrayInput,
                         size_t const   LH, 
                         size_t const   RH )
{
    /* If 0 is passed, and this is true, we know there isn't a pivot. Assume ordered. */
    //assert(LH != RH); //also assume no repeated elements? Is that fair?

    if(arrayInput[LH] < arrayInput[RH])
        return LH;
    
    size_t const midIndex = LH + (RH - LH) / 2;
    T const      mid = arrayInput[midIndex];

    if(mid < arrayInput[LH] && mid < arrayInput[RH])
        return midIndex;

    if(mid < arrayInput[RH])
        return findPivot(arrayInput, LH, RH - 1);
    if(mid > arrayInput[LH])
        return findPivot(arrayInput, LH + 1, RH);

    return 0; //shouldn't happen...
}


template <class T>
inline size_t findElement( T const*const  arrayInput, 
                           size_t const   len, 
                           T const&       elem )
{
    size_t const pivot = findPivot(arrayInput, 0, len - 1);

    auto itrLHS = std::lower_bound(arrayInput, arrayInput + pivot, elem);
    if(itrLHS != arrayInput + len && elem == *itrLHS)
    {
        /* Note: if InputIterator meets the requirements of RandomAccessIterator, which it does
           in this case, std::distance is constant, not linear. */
        return std::distance(arrayInput, itrLHS);

    }
    
    auto itrRHS = std::lower_bound(arrayInput + pivot, arrayInput + len, elem);
    if(itrRHS != arrayInput + len)
        return std::distance(arrayInput, itrRHS);
    else
        return 0; //error; not found
}

/* Fun Note:
   std::partition(begin, end, unary_predicate) can be used to split up a vector
   (not sure about c-arrays), but surely std::arrays. This could be used to 'fix'
   the array here, also probably useful in the sorting implementations - e.g., quicksort
   with a lambda function for the < operator.
   */

int main()
{
    //                     V
    int    arr[6] = {7, 8, 9, 10, 4, 5};
    size_t find = findElement(arr, 6,  4);
    assert(find == 4);
    size_t find1 = findElement(arr, 6, 7);
    assert(find1 == 0);
    size_t find2 = findElement(arr, 6, 5);
    assert(find2 == 5);
    size_t find3 = findElement(arr, 6, 10);
    assert(find3 == 3);

    int arr2[7] = {199, 2, 16, 22, 41, 55, 60};
    size_t find10 = findElement(arr2, 7, 199);
    assert(find10 == 0);
    size_t find11 = findElement(arr2, 7, 60);
    assert(find11 == 6);
    size_t find12 = findElement(arr2, 7, 22);
    assert(find12 == 3);

    //assuming increasing order, if element 2 < element 1, you're 'around' the pivot.

    int dummy2 = 0;
}
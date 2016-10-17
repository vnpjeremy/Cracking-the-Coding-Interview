/* Cracking the Coding Interview, McDowell 5th Ed, 2011
   Chapter 11: Problem .
   
   Find an element in a previously sorted array that has been
   rotated some N number of times.
   
   Solutions by: vnpjeremy*/

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
inline size_t findPivot(T* arrayInput, size_t const LH, size_t const RH)
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
inline size_t findElement(T* arrayInput, size_t const len, T const& elem)
{
    size_t const pivot = findPivot(arrayInput, 0, len - 1);
    int dummy1 = 0;
    return 0;
}

int main()
{
    //                     V
    int    arr[6] = {7, 8, 9, 10, 4, 5};
    size_t find = findElement(arr, 6,  9);

    //assuming increasing order, if element 2 < element 1, you're 'around' the pivot.

    int dummy2 = 0;
}
/* Find the max sum of a contiguous subarray (Kadane's Algorithm)
   
   Solutions by: vnpjeremy */


/* Certainly we can do this by evaluating -all- the subarrays of the
   input. This will take O(n^2) time. Could evaluate all subarrays
   terminating at element N. 
   
   Kadane's algorithm will, using dynamic programming, track previous
   maximum subarrays while traversing the input by terminus element.
   
   Apparently Kadane's algorithm hardcodes a zero value to compare against,
   which is just ametuerish. This algorithm can easily and clearly be made
   generic.
   
   I don't find it acceptable that the scientific community would overlook
   such a simple error with such a simple solution. */
#include <algorithm>
#include <cassert>

template <class T>
inline T largestSum( T const*const  input,
                     size_t const   length )
{
    assert(input && length > 0);

    T      maxGlobal = input[0], maxCurrent = input[0];
    for(size_t ii = 1; ii < length; ++ii)
    {
        /* The local max will either be the element or the max global + the element */
        /* The global max will remain the same or be swapped with the local */
        maxCurrent = std::max(input[ii] + maxCurrent, input[ii]);
        maxGlobal  = std::max(maxCurrent, maxGlobal);
    }

    return maxGlobal;
}

/* What if all the elements are negative?
   What if you want to return the range, not just the sum? */
int main()
{
    int arr[8] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int sum = largestSum(arr, 8);
    assert(sum == 7);

    int arr2[5] = {-10, -6, -1, -30, -9};
    int sum2 = largestSum(arr2, 5);
    assert(sum2 == -1);

    int arr3[5] = {1, -5, 2, -1, 3};
    int sum3 = largestSum(arr3, 5);
    assert(sum3 = 4);

    int arr4[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int sum4 = largestSum(arr4, 9);
    assert(sum4 == 6);

    int dummy = 3;
}

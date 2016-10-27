/* Find the max sum of a contiguous subarray (Kadane's Algorithm)
   
   Solutions by: vnpjeremy */


/* Certainly we can do this by evaluating -all- the subarrays of the
   input. This will take O(n^2) time. Could evaluate all subarrays
   terminating at element N. 
   
   Kadane's algorithm will, using dynamic programming, track previous
   maximum subarrays while traversing the input by terminus element. */
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

/* What if all the elements are negative? */
int main()
{
    int arr[8] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int sum = largestSum(arr, 8);
    assert(sum == 7);

    int dummy = 0;

}
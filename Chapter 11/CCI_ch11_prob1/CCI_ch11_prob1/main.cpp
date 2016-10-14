/* Cracking the Coding Interview, McDowell 5th Ed, 2011
   Chapter 11: Problem 1.
   
   Given two sorted arrays, and assuming arr1 has a buffer
   to hold both size-wise, write a method to merge B to A.
   
   Solutions by: vnpjeremy*/

#include "merge.h"
#include <random>

/* This is the integral component of Mergesort. Since we already
   have this buffer, we don't want to add O(n) space to it, like
   ususal. We can do it in O(1) space and O(1) time.
   
   We will have to use the second half of the first array AS the
   buffer, which could mean one of a couple/few approaches. My
   knee-jerk reaction to having a fixed-width array to populate
   is to start at the -back-. In normal strings, there is a trick
   to populate from the back and move the start pointer to the
   new first element, releasing the need to do unecessary shifting.
   We'll order this left->right by moving the largest of the last two
   elements to the end of the string1 buffer.
   
   If the buffer is -larger-, we will have to do this string trick. 
   Assumption is that it is not necessarily the same size.
   
   If the size is excessive, we could use the knowledge of size of 
   array 1 + size of array 2 to move to the 'appropriate' end element
   of array 1, some M elements from the last one, where size1+ size2 + M = N, 
   length of array 1 storage capacity. Let us implement this more generic
   solution.
   */
int main()
{
    int                             arr[25];
    std::random_device              rDev;
    std::mt19937                    gen(rDev());
    std::uniform_int_distribution<> dist(-100, 100);

    size_t const len1_alloc = 12, len2 = 5, len1_pop = 5;
    int buf1[len1_alloc] = {44, -44, 150, 99, -3, 0, 0, 0, 0, 0, 0, 0};
    int buf2[len2] = {-1, 15, 25, -66, 100};

    merge(buf1, buf2, len1_alloc, len2);

    int dummy = 0;
}
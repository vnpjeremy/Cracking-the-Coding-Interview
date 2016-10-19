/* Cracking the Coding Interview, McDowell 5th Ed, 2011
   Chapter 11: Problem 6.
   
   In a matrix of rows AND columns sorted in ascending order,
   search to find an element.
   
   Solutions by: vnpjeremy*/

#include <array>
#include <utility>
/* This is a very intriguing problem. 
   Consider:
   We have a matrix of rows that are sorted. We can perform a binary
   search on each, but must do so linearly over the group. Therefore
   an O(N) compounded with an O(N log N) approach must necessarily be
   *worse* than what we can do here, as we have more information than
   this particular scenario.
   

   */

typedef std::pair<size_t, size_t> indices;
//typedef size_t indices[2];

indices searchMtx()
{

}

int main()
{
    std::array<std::array<int, 4>, 4> matx = { {{13, 80,  190, 250},
                                                {50, 99,  200, 260},
                                                {61, 121, 210, 277},
                                                {77, 135, 301, 325}} };

    /* Straight off, it looks like we can use the diagonals to exclude entire
       sub-matrices. */
}
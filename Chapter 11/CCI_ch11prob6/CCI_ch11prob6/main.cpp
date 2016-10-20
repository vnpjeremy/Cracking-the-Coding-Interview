/* Cracking the Coding Interview, McDowell 5th Ed, 2011
   Chapter 11: Problem 6.
   
   In a matrix of rows AND columns sorted in ascending order,
   search to find an element.
   
   Solutions by: vnpjeremy*/

#include <algorithm>
#include <array>
#include <cassert>
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

/* I could templatize this with the array form T**, but this? */
template <class T, size_t N>
indices searchMtx( std::array<std::array<T, N>, N> mtx,
                   T const&                        searchVal)
{
    /* In theory we should be able to write this for arbitrary types
       as well as arbitrary lengths. In theory. 
       
       It is advantageous in linear algebra to consider column space.
       So we'll do that first. If the element is less than element [0]
       of the column, it isn't in that column at all. Move left.
       
       Secondly, if a value is greater than the last element in a row,
       it isn't in that row. Move down.
       
       Alternatively, if an element is greater than the last element
       in a column one must move move right, and smaller than the first
       element in a row, move up.
       
       Using two of these rules can help 'bound' the matrix into a sub-matrix
       that can be binary searched. This approach hints at a Divide-and-Conquer
       algorithm, which we can return to when we strike Algorithms. */

    /* In a similar vein we can take advantage of the diagonals! Right?
       although that approach may not be as efficient as using col vs rows.
       Let's try using col->right and row->down, arbitrarily.
    */

    /* Down-Left Search O(n), fastest? Other than a clever D&Q?*/

    /* Move from RHS col */
    for(size_t ii = N - 1; ii < N; --ii)
    {
        if(searchVal < mtx[0][ii])
            continue;

        for(size_t jj = 0; jj < N; ++jj)
        {
            if(mtx[jj][ii] < searchVal)
                continue;
            if(mtx[jj][ii] == searchVal)
                return std::make_pair(jj, ii);
        }
    }

    return std::make_pair(N, N);
}

int main()
{
    std::array<std::array<int, 4>, 4> matx = { {{13, 80,  190, 250},
                                                {50, 99,  200, 260},
                                                {61, 121, 210, 277},
                                                {77, 135, 301, 325}} };

    indices const result1 = searchMtx(matx, 13);
    assert(result1.first == 0 && result1.second == 0);

    indices const result2 = searchMtx(matx, 325);
    assert(result2.first == 3 && result2.second == 3);

    indices const result3 = searchMtx(matx, 200);
    assert(result3.first == 1 && result3.second == 2);

    indices const result4 = searchMtx(matx, 61);
    assert(result4.first == 2 && result4.second == 0);

    int dummy = 0;
    /* Straight off, it looks like we can use the diagonals to exclude entire
       sub-matrices. */
}
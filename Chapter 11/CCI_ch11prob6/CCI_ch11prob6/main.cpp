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
bool searchMtx( std::array<std::array<T, N>, N> mtx,
                T const&                        searchVal,
                indices &                       location )
{
    if(searchVal < mtx[0][0] || searchVal > mtx[N - 1][N - 1])
        return false;

    size_t row = 0, col = N - 1;
    while(row < N && col < N)
    {
        if(searchVal < mtx[row][col])
            --col;
        else if(mtx[row][col] < searchVal)
            ++row;
        else
        {
            location = std::make_pair(row, col);
            return true;
        }
    }
    return false;

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
#if 0
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
#endif

    
}

int main()
{
    std::array<std::array<int, 4>, 4> matx = { {{13, 80,  190, 250},
                                                {50, 99,  200, 260},
                                                {61, 121, 210, 277},
                                                {77, 135, 301, 325}} };

    indices result1;
    bool ret1 = searchMtx(matx, 13, result1);
    assert(result1.first == 0 && result1.second == 0);

    indices result2;
    bool ret2 = searchMtx(matx, 325, result2);
    assert(result2.first == 3 && result2.second == 3);

    indices result3;
    bool ret3 = searchMtx(matx, 200, result3);
    assert(result3.first == 1 && result3.second == 2);

    indices result4;
    bool ret4 = searchMtx(matx, 61, result4);
    assert(result4.first == 2 && result4.second == 0);

    std::array<std::array<int, 5>, 5> matx2 = { {{1,  4,  7,  11, 15},
                                                {2,  5,  8,  12, 19},
                                                {3,  6,  9,  16, 22},
                                                {10, 13, 14, 17, 24},
                                                {18, 21, 23, 26, 30}} };

    indices result5;
    bool ret5 = searchMtx(matx2, 13, result5);
    assert(result5.first == 3 && result5.second == 1);

    int dummy = 0;
    /* Straight off, it looks like we can use the diagonals to exclude entire
       sub-matrices. */
}
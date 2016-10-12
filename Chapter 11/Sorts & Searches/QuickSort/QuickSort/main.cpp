
/* Test the quicksort impl */
#include <random>
#include "QuickSort.h"

int main()
{
    std::random_device              rDev;
    std::mt19937                    gen(rDev());
    std::uniform_int_distribution<> dogsAndCats(-200, 200);
    size_t const bigSize = 25;
    int arr0[bigSize] = {34	,
        -170	,
        -154	,
        178	,
        69	,
        53	,
        -72	,
        -124	,
        -33	,
        -95	,
        50	,
        -144	,
        21	,
        12	,
        52	,
        200	,
        -14	,
        -58	,
        -174	,
        110	,
        105	,
        -178	,
        110	,
        -66	,
        -178	
    };
    

    QuickSort(arr0, 0, bigSize);
    int tmp = std::numeric_limits<int>::min();
    for(size_t ii = 0; ii < bigSize; ++ii)
    {        
        assert(arr0[ii] >= tmp); //shoot it isn't right.
        tmp = arr0[ii];
    }
    int     arr[] = {4, -15, 25, 61, -88, 91, 2, 121};
    size_t  len = size1(arr);

   // QuickSort(arr, 0, len);

    int dummy = 0;
}

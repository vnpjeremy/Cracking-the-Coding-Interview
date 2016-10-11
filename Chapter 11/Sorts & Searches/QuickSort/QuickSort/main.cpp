
/* Test the quicksort impl */
#include <random>
#include "QuickSort.h"

int main()
{
    std::random_device              rDev;
    std::mt19937                    gen(rDev());
    std::uniform_int_distribution<> dogsAndCats(-200, 200);
    size_t const bigSize = 25;
    int arr0[bigSize];
    for(size_t ii = 0; ii < bigSize; ++ii)
        arr0[ii] = dogsAndCats(gen);

    QuickSort(arr0, 0, bigSize);

    int     arr[] = {4, -15, 25, 61, -88, 91, 2, 121};
    size_t  len = size1(arr);

    QuickSort(arr, 0, len);

    int dummy = 0;
}

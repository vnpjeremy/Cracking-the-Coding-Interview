#include "MergeSort.h"
#include <random>

int main()
{
    int                             arr[25];
    std::random_device              rDev;
    std::mt19937                    gen(rDev());
    std::uniform_int_distribution<> dist(-100, 100);

    for(int ii = 0; ii < 25; ++ii)
        arr[ii] = dist(gen);

    MergeSort(arr, 0, 25);
    int tmp = std::numeric_limits<int>::min();
    for(int ii = 0; ii < 25; ++ii)
    {
        assert(tmp <= arr[ii]);
        tmp = arr[ii];
    }


    
    int dummy = 0;
}
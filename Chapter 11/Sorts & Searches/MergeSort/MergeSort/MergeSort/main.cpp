#include "MergeSort.h"
#include <random>

int main()
{
    int arr0[5] = {3, -1, 5, 2, -20};
    size_t len = sizeOfArr(arr0);
    MergeSort(arr0, 0, len);


    std::random_device              rDev;
    std::mt19937                    gen(rDev());
    std::uniform_int_distribution<> dist(-100, 100);

    int dummy = 0;
}
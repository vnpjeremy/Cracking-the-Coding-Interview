
/* Test the quicksort impl */
#include "QuickSort.h"

int main()
{
    //std::array<int, 7> = {//stuff};
    int     arr[] = {4, -15, 25, 61, -88, 91, 2, 121};
    size_t  len = size1(arr);

    QuickSort(arr, 0, len);

    int dummy = 0;
}

#pragma once

template <class T>
void merge( T             *arr1, 
            T const*const arr2,
            size_t const  len_arr1_populated, //len_arr1_allocated != len_arr1_populated
            size_t const  len_arr2 )
{
    /* say there are 4 populated and 3 in the second, total of 7, elements [0-6] */
    size_t last_index = len_arr1_populated + len_arr2 - 1;
    size_t itrArr1 = len_arr1_populated - 1, itrArr2 = len_arr2 - 1;

    while( itrArr1 < len_arr1_populated && itrArr2 < len_arr2 )
    {
        if(arr1[itrArr1] < arr2[itrArr2])
            arr1[last_index--] = arr2[itrArr2--];
        else
            arr1[last_index--] = arr1[itrArr1--];
    }
    
    //then take care of non-identical lengths
}
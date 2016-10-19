/* Cracking the Coding Interview, McDowell 5th Ed, 2011
   Chapter 11: Problem 5.
   
   If you have a sorted array of strings with empty strings
   in the set, write a method to find a string.
   
   Solutions by: vnpjeremy*/
#include "MyBinarySearch.h"


/* Key: sorted. So, we're thinking OK so binary search must have
   a limitation with empty strings. Modify it so that it doesn't,
   more or less.

   Note normally we'd use something akin to std::lower_bound for this.
   What happens if we just call it? <time passes> OK so it doesn't work.
   */
int main()
{
    std::array<std::string, 9> arr1= {"", "bangelore", "charles", "", "", "finland", "", "krunk", ""};

    auto itr = std::lower_bound(arr1.begin(), arr1.end(), "bangelore");

    std::string comp1 = "bangelore";
    size_t const find = myBinarySearch(arr1.data(), 0, arr1.size(), comp1);
    assert(arr1[find] == comp1);

    std::string comp2 = "muffin";
    size_t const find2 = myBinarySearch(arr1.data(), 0, arr1.size(), comp2);
    assert(find2 == 9);

    std::string comp3 = "charles";
    size_t const find3 = myBinarySearch(arr1.data(), 0, arr1.size(), comp3);
    assert(find3 == 2);

    std::string comp4 = "finland";
    size_t const find4 = myBinarySearch(arr1.data(), 0, arr1.size(), comp4);
    assert(find4 == 5);

    std::string comp5 = "krunk";
    size_t const find5 = myBinarySearch(arr1.data(), 0, arr1.size(), comp5);
    assert(find5 == 7);

    std::array<std::string, 9> arr2 = {"aloof", "", "charles", "", "", "finland", "", "krunk", "mrr"};

    std::string comp6 = "aloof";
    size_t const find6 = myBinarySearch(arr2.data(), 0, arr2.size(), comp6);
    assert(find6 == 0);

    std::string comp7 = "mrr";
    size_t const find7 = myBinarySearch(arr2.data(), 0, arr2.size(), comp7);
    assert(find7 == 8);

    int dummy = 0;
}
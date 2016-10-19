/* Cracking the Coding Interview, McDowell 5th Ed, 2011
   Chapter 11: Problem 5.
   
   If you have a sorted array of strings with empty strings
   in the set, write a method to find a string.
   
   Solutions by: vnpjeremy*/
#include <array>

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

    int dummy = 0;
}
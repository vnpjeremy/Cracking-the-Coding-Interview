/* Cracking the Coding Interview, McDowell 5th Ed, 2011
   Chapter 11: Problem 2.
   
   Sort an array of strings such that anagrams are adjacent.
   
   Solutions by: vnpjeremy*/

/* First up we have to generate this nonsense. 
   Also: Aha! It never actually says to sort the damn things.
*/
#include <algorithm>
#include <string>
#include <vector>



struct AnagramCompare
{
    bool operator()(std::string const& lhs, std::string const& rhs)
    {
        std::string lhs1(lhs), rhs1(rhs);
        std::sort(lhs1.begin(), lhs1.end());
        std::sort(rhs1.begin(), rhs1.end());
        return lhs1 < rhs1;
    }
};

void stringSort(std::vector<std::string> & unsortedArr)
{
    std::sort(unsortedArr.begin(), unsortedArr.end(), AnagramCompare());
}

int main()
{
    std::vector<std::string> stringArr;
    stringArr.push_back(std::string("bat")); //non-explicit constructor?
    stringArr.push_back("flash");
    stringArr.push_back("grab");
    stringArr.push_back("lighthouse");
    stringArr.push_back("zephyr");
    stringArr.push_back("brag");
    stringArr.push_back("tab");

    stringSort(stringArr);

    int dummy = 0;
}
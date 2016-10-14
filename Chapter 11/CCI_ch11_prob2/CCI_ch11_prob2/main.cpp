/* Cracking the Coding Interview, McDowell 5th Ed, 2011
   Chapter 11: Problem 2.
   
   Sort an array of strings such that anagrams are adjacent.
   
   Solutions by: vnpjeremy*/

/* First up we have to generate this nonsense. */
#include <string>
#include <vector>

void stringSort(std::vector<std::string> & unsortedArr)
{

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
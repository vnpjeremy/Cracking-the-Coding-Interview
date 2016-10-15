/* Cracking the Coding Interview, McDowell 5th Ed, 2011
   Chapter 11: Problem 2.
   
   Sort an array of strings such that anagrams are adjacent.
   
   Solutions by: vnpjeremy*/

/* First up we have to generate this nonsense. 
   Also: Aha! It never actually says to sort the damn things.
*/
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>


void sortWithHashing(std::vector<std::string> & unsortedArr)
{
    std::vector<std::string>                     tmp;
    tmp.reserve(unsortedArr.size());
    std::unordered_map<std::string, std::string> stringMap;

    for(size_t ii = 0; ii < unsortedArr.size(); ++ii)
    {
        std::string  sorted(unsortedArr[ii]);
        std::sort(sorted.begin(), sorted.end());
        auto itr = stringMap.find(sorted);
        if(itr != stringMap.end())
        {
            tmp.push_back(unsortedArr[ii]);
            tmp.push_back((*itr).second);
            itr = stringMap.erase(itr);
        }
        else
            stringMap.insert(std::make_pair(sorted, unsortedArr[ii]));
    }

    for(auto elm : stringMap)
        tmp.push_back(elm.second);
    unsortedArr = tmp;
}

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

/* There are a couple ways to attack this. First of all, an anagram is defined
   by means of identical char counts. So, sort it. I've done this in AnagramCompare.
   
   Technically, the instructions don't call for a sort. This might be more work
   than is necessary. 

   Solution 1: Sort the strings, then sort the arrays. N log N for both operations.
   Solution 2: Use a hash table to skirt the second sort. Store the sorted and the 
   unsorted string, then populate the array with anagrams next to one another. This
   ought to be faster as insert, erase, and find are average constant in umaps.
*/
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

    //stringSort(stringArr);
    sortWithHashing(stringArr);

    int dummy = 0;
}
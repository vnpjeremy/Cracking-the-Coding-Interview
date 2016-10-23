/* Cracking the Coding Interview, McDowell 5th Ed, 2011
   Chapter 11: Problem 7.
   
   Say you have a 20GB file with one string per line. How
   would you sort it.
   
   Solutions by: vnpjeremy*/
#include <algorithm>
#include <vector>
#include <utility>

typedef std::pair<int, int> person;

//struct ComparePersons
//{
//    bool operator()(person const& lhs, person const& rhs)
//    {
//        return lhs.first < rhs.first && lhs.second < rhs.second;
//    }
//};

int main()
{
    /* Lexicographical compare fixes this in O(log N) time. */
    std::vector<person> personGroup = { std::make_pair(65, 100), std::make_pair(70, 150), std::make_pair(56, 90),
                                        std::make_pair(75, 190), std::make_pair(60, 95), std::make_pair(68, 110) };

    std::vector<int> arr2 = {65, 100, 70, 150, 56, 90, 75, 190, 60, 95, 68, 110};
    std::vector<person> buffer;
    buffer.reserve(arr2.size() / 2);

    for(size_t ii = 0; ii < arr2.size(); ii += 2)
        buffer.push_back(std::make_pair(arr2[ii], arr2[ii + 1]));
    std::sort(buffer.begin(), buffer.end());

    size_t itr = 0;
    for(auto elm : buffer)
    {
        arr2[itr++] = elm.first;
        arr2[itr++] = elm.second;
    }

    std::sort(personGroup.begin(), personGroup.end()/*, ComparePersons()*/);

    int dummy = 8;
}
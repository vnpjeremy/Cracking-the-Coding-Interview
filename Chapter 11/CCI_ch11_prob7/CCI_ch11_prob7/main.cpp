/* Cracking the Coding Interview, McDowell 5th Ed, 2011
   Chapter 11: Problem 7.
   
   Find the max number of persons in a tower requiring lexicographical ordering.
   Kadane's Algorithm! (Using it. Ish.)
   
   Solutions by: vnpjeremy*/
#include <algorithm>
#include <vector>
#include <utility>

typedef std::pair<int, int> person;

/* This guy is REALLY asking if you can find the Longest Increasing Subsequence. (or decreasing)
   But worded the problem in an extremely poor way. So, if you have
   [10, 9,--11-- 2, 5, 3, 7, 101, 18]
   
   How would you go about finding that    
   [2, 3, 7, 101]
   is the longest increasing subsequence? That's the kicker. */

struct CompareHeight
{
    bool operator()(person const& lhs, person const& rhs)
    {
        return lhs.first < rhs.first;
    }
};

struct CompareWeight
{
    bool operator()(person const& lhs, person const& rhs)
    {
        return lhs.second < rhs.second;
    }
};

/* A dynamic programming approach will enumerate all the possible subsequences in the whole array,
   then the longest can be chosen and returned as output. This is almost certainly not the most
   efficient approach since it calculates all the unecessary sequences. Note the spacial complexity
   is worse than linear, approaching O(n^2) as well. */

 void longestIncSubseq( std::vector<person> const& input,
                        std::vector<person> &      longestSeq )
{
    size_t                            longestSeqLength = 0, longestSeqIndex = 0;
    std::vector<std::vector<person>>  sequences(input.size());
    sequences[0].push_back(input[0]); //the first element is always a subsequence of length == 1

    for(size_t ii = 1; ii < input.size(); ++ii)
    {
        size_t seqLen = 0;
        for(size_t jj = 0; jj < ii; ++jj)
        {
            /* Each previous entry in the array 'input' will have its own sequence.
               if that element, which is the greatest in its sequence, is less than 
               the element ii (where the iterator currently is in the input), then
               that entire sequence will be the first part of this sequence, followed
               by the current element as its terminal element. Make this sequence that
               vector, then update the vector with the appended element. */
            if(CompareWeight()(input[jj], input[ii]) && sequences[ii].size() < sequences[jj].size() + 1)
            {
                sequences[ii] = sequences[jj];
                ++seqLen;
            }
        }

        if(seqLen > longestSeqLength)
        {
            longestSeqLength = seqLen;
            longestSeqIndex = ii;
        }
        sequences[ii].push_back(input[ii]);
    }

    longestSeq = sequences[longestSeqIndex];
}

int main()
{
    /* Lexicographical compare fixes this in O(log N) time where N = length */
    std::vector<person> personGroup = { std::make_pair(65, 100),
                                        std::make_pair(70, 150), 
                                        std::make_pair(56, 90),
                                        std::make_pair(75, 190), 
                                        std::make_pair(60, 95),
                                        std::make_pair(68, 110) };

    std::sort(personGroup.begin(), personGroup.end(), CompareHeight());

    std::vector<person> result;
    longestIncSubseq(personGroup, result);

    int seq[8] = {10, 9, 2, 5, 3, 7, 101, 18};
    // out len==4; [2,3,7,101]
    //longestIncSubseq(seq0, len, out);

    int dummy = 8;
}
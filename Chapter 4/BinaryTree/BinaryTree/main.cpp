#include "bTree.h"
#include <vector>

int main()
{
    bTree<int> t1;

    std::vector<int> input = {11, 6, 14, 18, 5, 8, 10};
        /*  10
          /   \
         6    14 
        / \   / \ 
       5   8 11  18 */
    for(auto elm : input)
        t1.insert(elm);

    int dummy = 0;
}
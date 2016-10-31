#include "bTree.h"
#include <cassert>
#include <vector>

int main()
{
    {
        bTree<int> t1;

        std::vector<int> input = {10, 14, 6, 11, 8, 18, 5};
        /*  10
          /   \
         6    14
        / \   / \
       5   8 11  18 */
        for(auto elm : input)
            t1.insert(elm);

        //t1.depthFirst_PreOrderTraverseSearch();
        t1.depthFirst_InOrderTraverseSearch();
        //t1.depthFirst_PostOrderTraverseSearch();

        bool const search1 = t1.search(6);
        assert(search1 == true);
        bool const search2 = t1.search(19);
        assert(search2 == false);

        int dummy1 = 1;
    }

    int dummy = 0;
}
#include "bTree.h"
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
        bool const search3 = t1.search(10);
        assert(search3 == true);

        int const max = t1.max();
        assert(max == 18);
        int const min = t1.min();
        assert(min == 5);

        size_t const height1 = t1.height();
        assert(height1 == 2);

        bTree<int> t2;
        //an empty tree has a height of -1. height is defined as the path from the root to the farthest node.
        int const height2 = t2.height();
        assert(height2 == -1);

        int dummy1 = 1;
    }

    int dummy = 0;
}
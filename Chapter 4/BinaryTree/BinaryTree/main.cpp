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
    }

    int dummy = 0;
}
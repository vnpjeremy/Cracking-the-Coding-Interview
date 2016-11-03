/* Cracking the Coding Interview, McDowell 5th Ed, 2011
   Chapter 4: Problem 5.
   
   Create a check to query if a BT is a BST.
   
   Solutions by: vnpjeremy*/

#include "bst.h"
#include <vector>

/* My first attempt at solving this was actually slightly incorrect. Consider a small, 
   balanced BST: */
        /*  10
          /   \
         6    14
        / \   / \
       5   8 11  18 */

/* The naive solution would be to check every subtree to see if it is a BST, but though
   this will weed out many incorrect solutions, such as 
       8
     /   \
    7     6
           \
            9
   
   For example. The one condition we should track here is a 'nearly' BST. Something that
   contains a subtree that is not a BST, not due to the subtree, but the supertree: */

        /*  10
          /   \
         6    14
        / \   / \
       5  12 11  18 */

/* This last example is NOT a BST, because 12 > 10, and should be in the right subtree.
   Thus what we need to track is the maximum / minimum values in each subtree. Here, we
   should be saying ok, at 12 min == 5, max == 10. Since it is in the left subtree, it
   must be <= 10. In the right subtree, it must be >= 10. */

template <class T>
bool bTree<T>::isBST( bTreeNode<T> const*const node,
                      T const&                 min,
                      T const&                 max ) const
    {
        if(node)
        {
            return min <= node->m_val
                && isBST(node->m_lhs, min, node->m_val)
                && node->m_val <= max
                && isBST(node->m_rhs, node->m_val, max);
        }
        else
            return true;//what IS an empty tree, is it BST?
    }

template <class T>
bool bTree<T>::isBST() const
{
    return isBST(m_root, std::numeric_limits<T>::min(), std::numeric_limits<T>::max());
}

int main()
{
    bTree<int> tree1 , tree2, tree3, tree4;
    std::vector<int> input1 = {10, 14, 6, 11, 8, 18, 5};
    for(auto elm : input1)
        tree1.insert(elm);
        /*  10
          /   \
         6    14
        / \   / \
       5   8 11  18 */

    /* Test a perfect BST */
    tree1.depthFirst_InOrderTraverseSearch();
    bool const bsttest1 = tree1.isBST();
    assert(bsttest1);

    /* Flat out isn't a BST. */
    std::vector<int> input2 = {21, 31, 4, -5};
    for(auto elm : input2)
        tree2.insertWrong(elm);

    /*        21
             /
           31
           /
          4
         /
       -5

    */
    bool const bsttest2 = tree2.isBST();
    assert(!bsttest2);
             
    /* Is a BST, but not a perfect one. */
    std::cout << "\n\n\n";
    std::vector<int> input3 = {10, 14, 6, 8, 6};
    for(auto elm : input3)
        tree3.insert(elm);
       /*  10
          /   \
         6    14
        / \   
       6   8       */
    tree3.depthFirst_InOrderTraverseSearch();
    bool const bsttest3 = tree3.isBST();
    assert(bsttest3);

    /* The real test, a very nearly BST: */
    std::vector<int> input4 = {10, 14, 6, 11, 18, 5};
    for(auto elm : input4)
        tree4.insert(elm);
    tree4.insertAt(12, 6);

       /*  10
          /   \
         6    14
        / \   / \
       5  12 11  18 */

    bool const bsttest4 = tree4.isBST();
    assert(!bsttest4);

    int dummy = 0;
}
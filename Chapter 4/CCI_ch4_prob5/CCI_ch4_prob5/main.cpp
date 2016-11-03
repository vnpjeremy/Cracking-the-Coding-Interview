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
            return min < node->m_val
                && isBST(node->m_lhs, min, node->m_val)
                && node->m_val < max
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
    bTree<int> tree1;
    std::vector<int> input = {10, 14, 6, 11, 8, 18, 5};
    for(auto elm : input)
        tree1.insert(elm);

    int dummy = 0;
}
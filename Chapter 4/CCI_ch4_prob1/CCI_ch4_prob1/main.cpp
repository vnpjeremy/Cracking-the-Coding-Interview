/* Cracking the Coding Interview, McDowell 5th Ed, 2011
   Chapter 4: Problem 1.
   
   Make a check to verify if a BT is balanced.
   
   Solutions by: vnpjeremy*/
#include "bst.h"
#include <utility>

/* Essentially they are asking for you to perform a depth-first traversal
   and keep track of the depth at each leaf node. Compare the min/max and
   return a result. */

template <class T>
int bTree<T>::height(bTreeNode<T> const*const node) const
{
    if(!node)
        return -1; //leaf nodes will get an std::max(0,0) + 1, so 
                   //this -1 will balance that out to the proper '0' answer

    int const height_lhs = height(node->m_lhs);
    int const height_rhs = height(node->m_rhs);
    return std::max(height_lhs, height_rhs) + 1; //increment count by one edge for this node
}

template <class T>
bool bTree<T>::balanced() const
{
    Int2 const out = heightDiff(m_root);
    return !(std::abs(out.second - out.first) > 1);
}
 /* A 'height' function is really just a max height calculator. We want max AND min, 
    so logically the simplest modification is just to add a parameter on the output for it.
    It will still be linear. */
template <class T>
Int2  bTree<T>::heightDiff(bTreeNode<T> const*const node) const
{
    if(!node)
        return std::make_pair(-1, -1);

    Int2 const height_lhs = heightDiff(node->m_lhs);
    Int2 const height_rhs = heightDiff(node->m_rhs);
    return std::make_pair(std::min(height_lhs.first, height_rhs.first) + 1,
                          std::max(height_lhs.second, height_rhs.second)+ 1);
}

        /*  10
          /   \
         6    14
        / \   / \
       5   8 11  18 */

int main()
{
    /* We want our traversal to look like this:
    {10 6 5} {10 6 8} {10 14 11} {10 14 8}
    
    There are several approaches. We could do breadth-first and ensure
    there is only 1 non-full level, or we could do depth-first and track
    min/max depth. */
    bTree<int>       tree1, tree2;
    std::vector<int> input1 = {10, 14, 6, 11, 8, 18, 5};
    for(auto elm : input1)
        tree1.insert(elm);

    bool const balanced = tree1.balanced();
    assert(balanced);

       /*  10
          /   \
         6    14
        / \   
       5   8       
      /
     3                  
     
     Should come out to h_min == 1, h_max == 3*/

    std::vector<int> input2 = {10, 14, 6, 8, 5, 3};
    for(auto elm : input2)
        tree2.insert(elm);

    bool const balanced2 = tree2.balanced();
    assert(!balanced2);

    int dummy = 0;
}
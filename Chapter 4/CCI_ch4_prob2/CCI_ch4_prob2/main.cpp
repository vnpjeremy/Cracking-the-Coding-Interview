/* Cracking the Coding Interview, McDowell 5th Ed, 2011
   Chapter 4: Problem 2.
   
   Find a route between two nodes, if possible, in a directed graph.
   
   Solutions by: vnpjeremy*/

#include "bst.h"

/* A graph G is an ordered pair of a set of V vertices and E edges 
   G = (V,E) 
   
   A directed graph is one which consists of edges that have directionality,
   e.g., v->u. 
   
   A tree is a directed graph as we will have a path from the root to a leaf
   node, but not vice-versa. 
   
   A walk is a route. A 'path' is a simple walk; a walk in which no edges or 
   vertices are repated. Assume this. 
   
   A 'trail' is a walk except repeated vertices are allowed, but not edges.
   
   A graph with no cycle is acyclic. A tree is a directed acyclic graph. (DAG) */

template <class T>
bool bTree<T>::BFS( bTreeNode<T> const* node,
                    T const&            val ) const
{
    if(node)
    {
        std::queue<bTreeNode<T>const*> q;
        q.push(node);
        while(!q.empty())
        {
            bTreeNode<T> const*const cur = q.front();
            q.pop();
            if(cur->m_val == val)
                return true;
            if(cur->m_lhs)
                q.push(cur->m_lhs);
            if(cur->m_rhs)
                q.push(cur->m_rhs);
        }
    }
    return false;
}

template <class T>
void bTree<T>::rotateRight( bTreeNode<T>* grandParent,
                            bTreeNode<T>* parent,
                            bTreeNode<T>* child )
{
    //check null for GP
    grandParent->m_rhs = child;    //Grandparent of child becomes the child's parent
    parent->m_lhs = child->m_rhs;  //Right subtree of child becomes left subtree of parent
    child->m_rhs = parent;         //Now that the RHS of child is used, replace that with its unused parent

}

/* The DSW Algorithm:
   balances a tree by transforming the existing tree into
   a linked list, i.e., a tree with only RHS or LHS nodes. This is achieved
   through rotations. Then a balanced tree is created from the 'backbone' that
   has been created. */
template <class T>
void bTree<T>::DSW_balance()
{
    DSW_treeToVine();
    //vine-to-tree
}

template <class T>
void bTree<T>::DSW_treeToVine()
{

}

int main()
{
    /* Note that a graph will be programmatically implemented differently than
       a simple thing like a BST or BT. The member data will be an iterable,
       not a non-connected series of N (2, in BST) 
       
       Note also that a BT is not strongly connected. */

    bTree<int>       tree1;
    std::vector<int> input = {99, 50, 130, 36, 25, 115, 149, 28, 9, 39, 33, 101, 120, 160, 140 };
        /*        99
           /              \
          50              130
        /    \         /       \
       25     36      115       149 
      /  \   /  \    /   \     /   \ 
     9   28 33  39  101  120 140   160
      */
    for(auto elm : input)
        tree1.insert(elm);

    /* Either search approach will be linear for the portion of the directed graph after 
    the origin node being queried. Now we would have to implement DFS or BFS generically
    for a generic graph in order to PROPERLY solve this problem, but that will not be done
    here. As noted above, the difference will simply be to traverse the N conneceted nodes,
    where in a BT, N==2 in all cases.
    
    BFS implements a queue but to me, is more likely to return a result more efficiently than
    DFS, but scientifically is is probably a toss up. Both are linear.*/
#if 0
    bTree<int>::bTreeNode<int>* src1 = tree1.find(tree1.m_root, 50);
    bool const                  found1 = tree1.BFS(src1, 39);
    assert(found1);

    bool const                  found2 = tree1.BFS(src1, 90);
    assert(!found2);

    bTree<int>::bTreeNode<int>* src2 = tree1.find(tree1.m_root, 149);
    bool const                  found3 = tree1.BFS(src1, 160);
    assert(found3);
    bool const                  found4 = tree1.BFS(src1, 120);
    assert(!found4);

    bool const                  found5 = tree1.BFS(tree1.m_root, 39);
    assert(found5);
#endif

    /* For the below unbalanced tree, the grandparent is 10, parent is 20, 
       and the child is 15.

            10
              \
              20
             /  \
            15   30
           /  \
          14  19
                    
    */

    std::vector<int> rotateData = {10, 20, 15, 14, 19, 30};
    bTree<int>       rotateTree;
    for(auto i : rotateData)
        rotateTree.insert(i);

    /*
        After rotating, the tree should look like this:

            10
              \
              15
             /  \
            14   20
                /  \
               19  30
    */

    bTree<int>::bTreeNode<int>* GP = rotateTree.find(rotateTree.m_root, 10);
    bTree<int>::bTreeNode<int>* Par = rotateTree.find(rotateTree.m_root, 20);
    bTree<int>::bTreeNode<int>* Ch = rotateTree.find(rotateTree.m_root, 15);

    rotateTree.rotateRight(GP, Par, Ch);


    int dummy = 0;
}
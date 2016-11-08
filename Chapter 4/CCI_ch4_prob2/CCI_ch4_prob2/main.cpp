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

int main()
{
    /* Note that a graph will be programmatically implemented differently than
       a simple thing like a BST or BT. The member data will be an iterable,
       not a non-connected series of N (2, in BST) 
       
       Note also that a BT is not strongly connected. */

    bTree<int>       tree1;
    std::vector<int> input = {99, 50, 36, 25, 9, 28, 39, 33, 130, 149, 115, 101, 120, 160, 140};
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

    int dummy = 0;
}
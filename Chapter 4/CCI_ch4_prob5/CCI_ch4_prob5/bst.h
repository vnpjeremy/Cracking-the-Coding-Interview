#pragma once
#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <queue>

template <class T>
class bTree
{
public:
    bTree() :
        m_root()
    {

    }

public:
    template <class T>
    struct bTreeNode
    {
        bTreeNode() :
            m_val(),
            m_lhs(),
            m_rhs()
        {
        }

        bTreeNode(T const& value) :
            m_val(value),
            m_lhs(),
            m_rhs()
        {
        }

        T              m_val;
        bTreeNode<T>   *m_lhs;
        bTreeNode<T>   *m_rhs;
    };

    void preOrder(bTreeNode<T> const*const node) const
    {
        if(!node)
            return;
        std::cout << node->m_val << "\n";
        preOrder(node->m_lhs);
        preOrder(node->m_rhs);
    }

    void inOrder(bTreeNode<T> const*const node) const
    {
        if(node)
        {
            inOrder(node->m_lhs);
            std::cout << node->m_val << "\n";
            inOrder(node->m_rhs);
        }
    }

    void postOrder(bTreeNode<T> const*const node) const
    {
        if(node)
        {
            postOrder(node->m_lhs);
            postOrder(node->m_rhs);
            std::cout << node->m_val << "\n";
        }
    }

    /* For breadth-first traversal, we can take advantage of a queue, as links
    are not directly available to traverse levels with only the container
    instrumentation. */
    void levelOrder(bTreeNode<T> const*const node) const
    {
        if(node)
        {
            std::queue<bTreeNode<T>*> nodeq;
        }
    }

    bTreeNode<T>* insertWrong(bTreeNode<T>      *node,
        T const&          value)
    {
        if(node)
        {
            node->m_lhs = insertWrong(node->m_lhs, value);
        }
        else
            node = new bTreeNode<T>(value);

        return node;
    }

    /* Recursive insert. Don't expose the node struct to the API */
    bTreeNode<T>* insert(bTreeNode<T>    *node,
        T const&        value)
    {
        if(node)
        {
            if(value < node->m_val)
                node->m_lhs = insert(node->m_lhs, value);
            else
                node->m_rhs = insert(node->m_rhs, value);
        }
        else
        {
            node = new bTreeNode<T>(value);
        }
        return node;
    }

    bTreeNode<T>* find(bTreeNode<T>    *node,
        T const&       searchVal)
    {
        if(node)
        {
            if(searchVal < node->m_val)
                return node->m_lhs = find(node->m_lhs, searchVal);
            else if(node->m_val < searchVal)
                return node->m_rhs = find(node->m_rhs, searchVal);
            else
                return node;
        }

        //assert?
        return node;
    }

    bool search(bTreeNode<T> const*const node,
        T const&                 value) const
    {
        if(!node)
            return false;
        else if(value == node->m_val)
            return true;
        else if(value < node->m_val)
            return search(node->m_lhs, value);
        else
            return search(node->m_rhs, value);
    }

    T max(bTreeNode<T> const*const node) const
    {
        assert(node);
        if(node->m_rhs)
            return max(node->m_rhs);
        return node->m_val;
    }

    T min(bTreeNode<T> const*const node) const
    {
        assert(node);
        if(node->m_lhs)
            return min(node->m_lhs);
        return node->m_val;
    }

    int height(bTreeNode<T> const*const node) const
    {
        if(!node)
            return -1; //leaf nodes will get an std::max(0,0) + 1, so 
                       //this -1 will balance that out to the proper '0' answer

        int const height_lhs = height(node->m_lhs);
        int const height_rhs = height(node->m_rhs);
        return std::max(height_lhs, height_rhs) + 1; //increment count by one edge for this node
    }

    /* This simple recursive check for BST actually only looks at subtrees. It is subtlely incorrect.
    To fix, we need to track the state of the larger tree, i.e., the values at nodes along the height
    from the leaf nodes of the subtree to the root of the entire tree. */
    bool isBST(bTreeNode<T> const*const node,
        T const&                 min,
        T const&                 max) const
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

    bTreeNode<T>   *m_root;

public:
    /* Recursive insert wrapper */
    void insert(T const&  value)
    {
        m_root = insert(m_root, value);
    }

    void insertAt(T const& insertVal,
        T const& nodeToMakeParent)
    {
        bTreeNode<T> *parent = find(m_root, nodeToMakeParent);
        if(!parent)
            return;
        if(!parent->m_lhs)
            parent->m_lhs = new bTreeNode<T>(insertVal);
        else if(!parent->m_rhs)
            parent->m_rhs = new bTreeNode<T>(insertVal);
    }

    void insertWrong(T const& value)
    {
        m_root = insertWrong(m_root, value);
    }

    /* Max will be RHS, RHS, RHS, etc */
    T max() const
    {
        return max(m_root);
    }

    /* Min will be LHS, LHS, LHS, etc */
    T min() const
    {
        return min(m_root);
    }

    /* We search the thing anyway on insert. */
    bool search(T const&  value) const
    {
        return search(m_root, value);
    }

    void destroyTree(bTreeNode<T>  *node)
    {
        if(node)
        {
            destroyTree(node->m_lhs);
            destroyTree(node->m_rhs);
            delete node;
        }
    }

    /* -----------------------------Traversal of Binary Trees----------------------------------- */

    /* Depth first traversal */
    /* Linear O(n) time complexity */
    /* Space complexity average, O(log n), from the stack depth for recursion. */

    /* Pre-order traversal involves moving in Left-To-Right manner:
    <root> <left subtree> <right subtree> */
    void depthFirst_PreOrderTraverseSearch() const
    {
        preOrder(m_root);
    }

    /* In-order traversal doesn't do the root first, still Left-To-Right:
    <lseft subtree> <root> <right subtree>

    Fun fact: In-Order traversal of a Binary Search Tree (BST) will
    yield results in SORTED order! */
    void depthFirst_InOrderTraverseSearch() const
    {
        inOrder(m_root);
    }

    /* Post-order traversal waits till the end to do the root. Still Left-to-Right:
    <left subtree> <right subtree> <root> */
    void depthFirst_PostOrderTraverseSearch() const
    {
        postOrder(m_root);
    }

    /* Breadth first traversal */
    void breadthFirst_LevelOrderSearch() const
    {
        if(m_root)
        {
            std::queue<bTreeNode<T>*> nodeq;
            nodeq.push(m_root);
            while(!nodeq.empty())
            {
                bTreeNode<T> const*const cur = nodeq.front();
                std::cout << cur->m_val << "\n";
                nodeq.pop();
                if(cur->m_lhs)
                    nodeq.push(cur->m_lhs);
                if(cur->m_rhs)
                    nodeq.push(cur->m_rhs);
            }
        }
    }
    /* -----------------------------Traversal of Binary Trees----------------------------------- */

    int height() const
    {
        return height(m_root);
    }

    /* This container is, of course, a BST, but if it were simply a BT, this check would indicate
    whether it is ordered appropriately. */
    bool isBST() const
    {
        return isBST(m_root, std::numeric_limits<T>::min(), std::numeric_limits<T>::max());
    }

    ~bTree()
    {
        destroyTree(m_root);
    }
};
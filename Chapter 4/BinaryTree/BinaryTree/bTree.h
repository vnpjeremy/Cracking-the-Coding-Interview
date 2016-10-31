#pragma once
#include <cassert>
#include <iostream>

template <class T>
class bTree
{
public:
    bTree() :
        m_root()
    {

    }

private:
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
        if(!node)
            return;

        inOrder(node->m_lhs);
        std::cout << node->m_val << "\n";
        inOrder(node->m_rhs);
    }

    void postOrder(bTreeNode<T> const*const node) const
    {
        if(!node)
            return;

        postOrder(node->m_lhs);
        postOrder(node->m_rhs);
        std::cout << node->m_val << "\n";
    }

    /* Recursive insert. Don't expose the node struct to the API */
    bTreeNode<T>* insert( bTreeNode<T>    *node,
                          T const&        value )
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

    bool search( bTreeNode<T> const*const node,
                 T const&                 value ) const
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

    bTreeNode<T>   *m_root;

public:
    /* Recursive insert wrapper */
    void insert( T const&  value )
    {
        m_root = insert(m_root, value);
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
#if 0
    /* Non-recursive implementation of insert */
    void insert(T const&              value)
    {       
        if(!m_root)
            m_root = new bTreeNode<T>(value);
        else
        {  
            bTreeNode<T>  *cur = m_root;
            while(cur)
            {
                if(value < cur->m_val)
                {
                    if(!cur->m_lhs)
                    {
                        cur->m_lhs = new bTreeNode<T>(value);
                        break;
                    }
                    else
                        cur = cur->m_lhs;
                }
                else
                {
                    if(!cur->m_rhs)
                    {
                        cur->m_rhs = new bTreeNode<T>(value);
                        break;
                    }
                    else
                        cur = cur->m_rhs;
                }
            }
        }
    }
#endif

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
    void breadthFirst_LevelOrderSearch()
    {
        
    }

    /* -----------------------------Traversal of Binary Trees----------------------------------- */

    ~bTree()
    {
        destroyTree(m_root);
    }
};
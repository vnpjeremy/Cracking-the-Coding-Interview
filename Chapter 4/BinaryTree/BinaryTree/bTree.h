#pragma once
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

    bTreeNode<T>   *m_root;

public:
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
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

    /* Pre-order traversal involves moving in Left-To-Right manner:
      <root> <left subtree> <right subtree> */
    void depthFirst_PreOrderTraverseSearch()
    {
        
    }

    /* In-order traversal doesn't do the root first, still Left-To-Right:
       <lseft subtree> <root> <right subtree> */
    void depthFirst_InOrderTraverseSearch()
    {
        
    }

    /* Post-order traversal waits till the end to do the root. Still Left-to-Right:
       <left subtree> <right subtree> <root> */
    void depthFirst_PostOrderTraverseSearch()
    {
        
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
#pragma once

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

    ~bTree()
    {
        destroyTree(m_root);
    }
};
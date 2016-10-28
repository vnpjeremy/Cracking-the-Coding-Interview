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
            //    //T             parentVal = m_root->m_val;
            //    
            bTreeNode<T>  *cur = m_root;
            while(cur)
            {
                if(value < cur->m_val)
                    cur = cur->m_lhs;
                else
                    cur = cur->m_rhs;
            }
            cur = new bTreeNode<T>(value);
            /* leaf node */
            //if(value < parentVal)
        }
    }

    ~bTree()
    {
        bTreeNode<T>* cur = m_root;
    }
};
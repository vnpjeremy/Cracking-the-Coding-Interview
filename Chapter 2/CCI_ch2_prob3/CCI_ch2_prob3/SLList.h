#pragma once
#include <vector>

/* For latest version: see GitHub repo "Containers".
   This is an unsecured copy for convenience. */

template <class T>
class SLList
{
public:
    template <class T>
    class Node
    {
    public:
        Node(T data) :
            m_next(),
            m_data(data)
        {
        }

        Node() :
            m_next(),
            m_data()
        {
        }

        Node(Node<T> const& rhs)
        {
            m_next = rhs.m_next;
            m_data = rhs.m_data;
        }

        Node<T>& operator=(Node<T> const& rhs)
        {
            if(this != rhs)
            {
                m_next = rhs.m_next;
                m_data = rhs.m_data;
            }
            return *this;
        }

        Node<T>* m_next;
        T        m_data;
    };

public:
    SLList() :
        m_head()
    {
    }

    void removeNode(T const& data);

    Node<T>* find(T data) //const&?
    {
        Node<T>* cur = m_head;
        while(cur)
        {
            if(cur->m_data == data)
                return cur;
            cur = cur->m_next;
        }
        return cur;
    }

    //Rule of 3/5: Need a CC
    /* SLList(SLList<T> const& rhs)
    {
    if(m_head)
    {

    }
    }*/

    //Rule of 3/5: Need a CA

    //MA

    //MC

    void push_back(T data)
    {
        Node<T>* newNode = new Node<T>(data);
        if(!m_head)
            m_head = newNode;
        else
        {
            Node<T>* cur = m_head;
            while(cur->m_next)
                cur = cur->m_next;
            cur->m_next = newNode;
        }
    }

    std::vector<T> flatten()
    {
        std::vector<T> output;
        Node<T>* tmp = m_head;
        while(tmp)
        {
            output.push_back(tmp->m_data);
            tmp = tmp->m_next;
        }

        return output;
    }

    void clear()
    {
        while(m_head)
        {
            Node<T>* tmp = m_head->m_next;
            delete m_head;
            m_head = tmp;
        }
    }

    ~SLList()
    {
        clear();
    }

    Node<T>* m_head;
};
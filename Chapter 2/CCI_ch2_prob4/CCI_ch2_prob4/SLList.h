#pragma once
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
        m_head(),
        m_tail()
    {
    }

    void removeNode(T const& data);
    void removeNode(Node<T>* node);

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

    void push_back(T const& data)
    {
        Node<T>* newNode = new Node<T>(data);
        if(!m_head)
        {
            m_head = newNode;
            m_tail = m_head;
        }
        else
        {
            m_tail->m_next = newNode;
            m_tail = newNode;
        }
    }

    void push_front(T const& data)
    {
        Node<T>* newNode = new Node<T>(data);
        if(!m_head)
            m_head = newNode;
        else
        {
            newNode->m_next = m_head;
            m_head = newNode;
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

    void partition(T const& data);

    ~SLList()
    {
        clear();
    }

    Node<T>* m_head;
    Node<T>* m_tail;
};

template <class T>
void SLList<T>::removeNode(T const& data)
{
    Node<T>* removeCandidate = find(data);
    if(!removeCandidate)
        return;

    if(!removeCandidate->m_next)
        return;//special case; Won't be O(1) time for this guy. Probably.
               //Can easily do O(n), naively.

    Node<T>* tmp = removeCandidate->m_next;
    removeCandidate->m_data = removeCandidate->m_next->m_data;
    removeCandidate->m_next = removeCandidate->m_next->m_next;
    delete tmp;
}

template <class T>
void SLList<T>::removeNode(Node<T>* removeCandidate)
{
    if(!removeCandidate->m_next)
        return;//special case; Won't be O(1) time for this guy. Probably.
               //Can easily do O(n), naively.

    Node<T>* tmp = removeCandidate->m_next;
    removeCandidate->m_data = removeCandidate->m_next->m_data;
    removeCandidate->m_next = removeCandidate->m_next->m_next;
    delete tmp;
}
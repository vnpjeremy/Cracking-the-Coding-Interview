
#pragma once
#include <vector>

template <class T>
class SLList
{
private:
    template <class T>
    class Node
    {
    public:
        Node(T data) :
            m_next(),
            m_data(data),
            m_min()
        {

        }

        Node() :
            m_next(),
            m_data(),
            m_min()
        {

        }

        Node(Node<T> const& rhs)
        {
            m_next = rhs.m_next;
            m_data = rhs.m_data;
            m_min = rhs.m_min;
        }

        Node<T>& operator=(Node<T> const& rhs)
        {
            if(this != rhs)
            {
                m_next = rhs.m_next;
                m_data = rhs.m_data;
                m_min = rhs.m_min;
            }
            return *this;
        }

        Node<T>* m_next;
        T        m_data;
        T        m_min;
    };

public:
    SLList() :
        m_head(),
        m_tail(),
        m_min()
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
    SLList(SLList<T> const& rhs)
    {
        Node<T>* cur = rhs.m_head;
        while(cur)
        {
            push_back(cur->m_data);
            cur = cur->m_next;
        }
    }

    //Rule of 3/5: Need a CA
    SLList<T>& operator=(SLList<T> const& rhs)
    {
        if(this != rhs)
        {
            Node<T>* cur = rhs.m_head;
            while(cur)
            {
                push_back(cur->m_data);
                cur = cur->m_next;
            }
        }
        return *this;
    }
    //MA

    //MC

    T & front()
    {
        if(empty())
            throw std::length_error("empty list");
        return m_head->m_data;
    }

    bool empty() const
    {
        return m_head ? false : true;
    }

    void pop()
    {
        if(empty())
            throw std::length_error("empty list");

        T minTmp = m_head->m_min;

        Node<T>* tmp = m_head->m_next;
        delete m_head;
        m_head = tmp;

        if(minTmp == m_min)
            m_min = m_head->m_min;
    }

    T min() const
    {
        return m_min;
    }

    void push_back(T const& data)
    {
        Node<T>* newNode = new Node<T>(data);
        if(!m_head)
        {
            m_head = newNode;       //make first node this new one
            m_tail = m_head;        //since we have a tail, it's also the head for a one-element container
            m_tail->m_min = data;   //the min for this node will be this, the only value present
            this->m_min = data;     //same for the list minimum value
        }
        else
        {
            m_tail->m_next = newNode;   //append node to tail
            m_tail = newNode;           //move the m_tail to this new node that has been created
            if(data < m_min)
            {
                m_tail->m_min = data;   //set this node's min to the data value
                this->m_min = data;     //set the list's min to the data value
            }
            else
            {
                m_tail->m_min = this->m_min; //set this node's min to the list's current value, since it's lower
            }
        }
    }
    
    
    void push_front(T const& data)
    {
        Node<T>* newNode = new Node<T>(data);
        if(!m_head)
        {
            m_head = newNode;
            m_head->m_min = data;   //the min for this node will be this, the only value present
            this->m_min = data;     //same for the list minimum value
        }
        else
        {
            newNode->m_next = m_head;
            m_head = newNode;
            if(data < m_min)
            {
                m_head->m_min = data;   //set this node's min to the data value
                this->m_min = data;     //set the list's min to the data value
            }
            else
            {
                m_head->m_min = this->m_min; //set this node's min to the list's current value, since it's lower
            }
        }
    }

    std::vector<T> flatten() const
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

    std::vector<T> flattenMins() const
    {
        std::vector<T> output;
        Node<T>* tmp = m_head;
        while(tmp)
        {
            output.push_back(tmp->m_min);
            tmp = tmp->m_next;
        }

        return output;
    }

    void reverse()
    {
        SLList<T>::Node<T> *cur = m_head, *prev = nullptr, *tmp = m_head;
        m_head = m_tail;
        m_tail = tmp;
        while(cur)
        {
            SLList<T>::Node<T> *tmp = cur->m_next;
            cur->m_next = prev; //reverse the linkage
            prev = cur;         //update prev iterator
            cur = tmp;          //update cur iterator
        }
    }

    SLList<T> outputReverse() const
    {
        SLList<T> output;
        SLList<T>::Node<T> const* cur = m_head;
        while(cur)
        {
            output.push_front(cur->m_data);
            cur = cur->m_next;
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
    Node<T>* m_tail;
    T        m_min;
};

template <class T>
void SLList<T>::removeNode(T const& data)
{
    Node<T>* removeCandidate = find(data);
    if(!removeCandidate)
        return;

    if(!removeCandidate->m_next)
    {
        Node<T>* tmp = m_head;
        while(tmp)
        {
            if(tmp->m_next->m_data == removeCandidate->m_data)
                break;
            tmp = tmp->m_next;
        }

        delete removeCandidate;
        tmp->m_next = nullptr;
        m_tail = tmp;
        return;
    }
    //special case; Won't be O(1) time for this guy. Probably.
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
    {
        Node<T>* tmp = m_head;
        while(tmp)
        {
            if(tmp->m_next->m_data == removeCandidate->m_data)
                break;
            tmp = tmp->m_next;
        }

        delete removeCandidate;
        tmp->m_next = nullptr;
        m_tail = tmp;
        return;
    }//Won't be O(1) time for this guy. Probably.
     //Can easily do O(n), naively.

    Node<T>* tmp = removeCandidate->m_next;
    removeCandidate->m_data = removeCandidate->m_next->m_data;
    removeCandidate->m_next = removeCandidate->m_next->m_next;
    delete tmp;
}
/* Cracking the Coding Interview, McDowell 5th Ed, 2011
   Chapter 2: Problem 4.
   Write code to partition a linked list around a value
   x, such that all nodes less than x come before all nodes
   greater than or equal to x.
   
   Solutions by: vnpjeremy*/

#include "SLList.h"

//NOTE: Put templates in headers, but for clarity in this exercise, putting 
//it in the implementation file in global scope. (Don't do this.)

//will be linear, but won't be sorted.
//Actually, will be linear only if push_back and push_front are constant. They are.

/* O(n) time and O(1) space, but NOT stable. Version 1.*/
template <class T>
void SLList<T>::partition(T const& data)
{
    if(!m_head)
        return;

    SLList<T>::Node<T>* node = find(data);
    if(!node)
        return;

    /* If less, push front. If greater, push back.
       Stop when your iterator is the original last
       element. */
    T const              partitionData = node->m_data;
    T const              tailData = m_tail->m_data;
    SLList<T>::Node<T>*  cur = m_head;
    while(cur)
    {
        bool const lastOne = cur->m_data == tailData ? true : false;
        if(cur->m_data < partitionData)
        {
            push_front(cur->m_data);
            removeNode(cur);
        }
        else if(cur->m_data == partitionData)
        {
            cur = cur->m_next;
        }
        else
        {
            push_back(cur->m_data);
            removeNode(cur);
        }

        if(lastOne)
            break;
    }
}

/* O(n) time O(n) space stable algorithm. Version 2. */
template <class T>
SLList<T> partition( SLList<T> const& input,
                     T const&         partitionVal )
{
    /* Anything less */
    SLList<T> newList1, newList2, newList3;
    SLList<T>::Node<T>*  cur = input.m_head;
    while(cur)
    {
        if(cur->m_data < partitionVal)
            newList1.push_back(cur->m_data);
        else if(cur->m_data == partitionVal)
            newList2.push_back(cur->m_data);
        else
            newList3.push_back(cur->m_data);
        cur = cur->m_next;
    }

    newList1.m_tail->m_next = newList2.m_head;
    newList1.m_tail = newList2.m_tail;
    newList1.m_tail->m_next = newList3.m_head;

    newList1.m_tail = newList3.m_tail;
    newList2.m_head = nullptr;
    newList3.m_head = nullptr;

    return newList1;
}

int main()
{
    {
        SLList<int> list2;
        list2.push_back(31);
        list2.push_back(1);
    }

    SLList<int> list1;
    list1.push_back(31);
    list1.push_back(1);
    list1.push_back(9);
    list1.push_back(81);
    list1.push_back(19);
    list1.push_back(9);
    list1.push_back(4);

    SLList<int>      part1 = partition(list1, 19);
    std::vector<int> out0 = part1.flatten();

    std::vector<int> out = list1.flatten();
    list1.partition(9);
    std::vector<int> out2 = list1.flatten();

    int dummy0 = 0;
}
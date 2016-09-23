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
//Actually, will be linear only if push_back and push_front are constant. Right
//now, push_back is linear, but storing m_tail in the data structure will make it
//constant.

template <class T>
void SLList<T>::partition(T const& data)
{
    if(!m_head)
        return;

    SLList<T>::Node<T>* node = find(data);
    if(!node)
        return;

    SLList<T>::Node<T>* cur = m_head;
    while(cur)
    {
        //less, then head. Else, tail.
        SLList<T>::Node<T>* tmp = cur->m_next;
        if(cur->m_data < node->m_data)
        {
            push_front(cur->m_data);
            removeNode(cur);
            int dummy = 3;
        }
        else
        {
            push_back(cur->m_data);
            removeNode(cur);
            int dummy = 3;
        }
        cur = tmp;
    }
}

int main()
{
    //Develop insertion before & after that is constant\
    //push_back: straightforward
    //push_front: rename the head

    SLList<int> list1;
    list1.push_back(31);
    list1.push_back(1);
    list1.push_back(9);
    list1.push_back(81);
    list1.push_back(19);
    list1.push_back(4);

    std::vector<int> out = list1.flatten();

    list1.partition(9);

    //list1.push_front(31);
    //list1.push_front(1);
    //list1.push_front(9);
    //list1.push_front(81);
    //list1.push_front(19);
    //list1.push_front(4);

    //std::vector<int> out = list1.flatten();

    int dummy0 = 0;

}
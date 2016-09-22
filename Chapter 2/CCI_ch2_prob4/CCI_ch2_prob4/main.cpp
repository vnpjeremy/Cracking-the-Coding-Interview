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
        if(cur->m_data < node->m_data)
        {
            SLList<T>::Node<T>* newNode = new SLList<T>::Node<T>;
        }
        else
        {

        }
    }
}

int main()
{
    //Develop insertion before & after that is constant\
    //push_back: straightforward
    //push_front: rename the head


}
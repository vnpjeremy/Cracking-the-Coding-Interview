#include "main.h"
#include "SLList.h"
/* Cracking the Coding Interview, McDowell 5th Ed, 2011
   Chapter 2: Problem 3.
   Implement an algorithm to delete a node in the middle of a singly-
   linked list, given only access to that node.
   Ex:
   Input  - the node c from LL a->b->c->d->e
   Result - a->b->d->e
   
   Solutions by: vnpjeremy*/

template <class T>
void SLList<T>::removeNode(T const& data)
{
    Node<T>* toRemove = find(data);
    if(!toRemove)
        return;

    if(!toRemove->m_next)
        return;//special case; Won't be O(1) time for this guy. Probably.
               //Can easily do O(n), naively.

    /*Node<T>* tmp = toRemove->m_next;
    toRemove = toRemove->m_next;
    delete tmp;*/

    int dummy0 = 0;

    //if(!node->m_next)
    //    return; 
    //node = node->m_next;

    /*Node<T>* nxt = node->m_next;
    node = node->m_next;
    node->m_next = nxt->m_next;
    delete nxt;*/
}

int main()
{
    SLList<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);
    list1.push_back(4);
    list1.push_back(5);

    list1.removeNode(3);

    std::vector<int> removed = list1.flatten();

    int dummy0 = 0;
}
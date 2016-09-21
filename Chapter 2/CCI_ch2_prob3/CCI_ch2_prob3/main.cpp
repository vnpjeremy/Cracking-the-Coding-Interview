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
    Node<T>* removeCandidate = find(data);
    if(!removeCandidate)
        return;

    if(!removeCandidate->m_next)
        return;//special case; Won't be O(1) time for this guy. Probably.
               //Can easily do O(n), naively.

    Node<T>* tmp   = removeCandidate->m_next;
    removeCandidate->m_data = removeCandidate->m_next->m_data;
    removeCandidate->m_next = removeCandidate->m_next->m_next;
    delete tmp;
}

/* So we are working with a singly-linked list, which means each
node will have a pointer to the next node, but not the previous.
This is problematic as the previous node's 'm_next" pointer will
need updating.

The naive solution will be linear O(n), as one must traverse the list
to gain access to the previous node. Ideally, considering this,
the problem would give access to node N and require deletion of
node N + 1.

Using this knowledge we can employ a trick to make the list behave
in this way. We will copy node N + 1 to node N, then, having access
to N + 1->m_next and putting it in node N, we can safely delete node
N + 1. This solution is constant O(1).

NOTE: This solution means the last node's deletion will be a special
case. It may have to be linear. */

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
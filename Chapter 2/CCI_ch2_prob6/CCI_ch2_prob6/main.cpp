/* Cracking the Coding Interview, McDowell 5th Ed, 2011
   Chapter 2: Problem 6.

   Given a circular linked list, implement an algorithm that
   returns the node at the beginning of the loop (corruption).
   Ex:
   A->B->C->D->E->C
   Output C
   
   Solutions by: vnpjeremy*/

#include "SLList.h"

/* The obvious solution, to me anyway, is a hash-based approach.
   Counting/storing the nodes could be a huge hassle. Storing and
   querying is O(1) for the most part with a hash table, such as an
   unsorted set.
   
   O(lam + mu)<--
   However this requires O(n) space. A well-known algorithm to this
   type of problem is the Tortise and the Hare algorithm. Basically,
   two iterators are used to traverse the list. One moves a single 
   node at once, the other double that. 
   
   Several CS applications have interest in this category of problems,
   and more algorithms exist aside from Floyd's cyle chasing, the term
   attributed from Knuth for this approach. */

template <class T>
bool SLList<T>::hasCircularLinkage(Node<T> & repeated) const
{
    if(!m_head)
        return false; //empty list

    SLList<T>::Node<T> *tortise = m_head, *hare = m_head;
    do
    {
        tortise = tortise->m_next;
        hare = hare->m_next;
        if(!hare)
            return false; //has an end
        hare = hare->m_next;

        if(!tortise || !hare)
            return false;//has an end
    } while(tortise != hare);

    /* Full cycle special case. This result must be on the cycle. */
    if(tortise == m_head)
    {
        repeated = *tortise;
        return true; 
    }

    /* Due to an algebra detail, the distance the two iterators have to travel
       to the cyle beginning is now precisely equal.*/
    size_t mu = 0, lam = 0;
    tortise = m_head;
    while(tortise != hare)
    {
        tortise = tortise->m_next;
        hare = hare->m_next;
        ++mu;
    }
    repeated = *tortise;
   
#if 0
    /* Find the length of the cyle, not needed in this example */
    while(tortise != hare || lam == 0)
    {
        hare = hare->m_next;
        ++lam;
    }
#endif

    return true;
}

int main()
{
    SLList<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);
    list1.push_back(4);
    list1.push_back(5);
    list1.push_back(6);
    list1.push_back(7);

    /* Note: the simple destructor written for this won't handle corruption. */
    SLList<int>::Node<int>* end = list1.m_tail;
    SLList<int>::Node<int>* cyclBeg = list1.find(3);
    end->m_next = cyclBeg;

    SLList<int>::Node<int> culprit;
    bool const hasRepeat = list1.hasCircularLinkage(culprit);
    int  debug = 0;
}
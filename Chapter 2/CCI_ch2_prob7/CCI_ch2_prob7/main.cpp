/* Cracking the Coding Interview, McDowell 5th Ed, 2011
   Chapter 2: Problem 7.

   Check to see if a LL is a palindrome.
   
   Solutions by: vnpjeremy*/

#include "SLList.h"

/* O(n) time O(1) space reversal method */
template <class T>
inline void SLList<T>::reverse()
{
    SLList<T>::Node<T> *cur = m_head, *prev = nullptr, *tmp = m_head;
    m_head = m_tail;
    m_tail = tmp;
    while(cur)
    {
        SLList<T>::Node<T>* tmp = cur->m_next;
        cur->m_next = prev; //reverse the linkage
        prev = cur;         //update prev iterator
        cur = tmp;          //update cur iterator
    }
}

int main()
{
    SLList<int> list1;
    for(int ii = 0; ii < 7; ++ii)
        list1.push_back(ii);

    std::vector<int> test1 = list1.flatten();
    list1.reverse();
    std::vector<int> test2 = list1.flatten();

    int dummy = 0;
}
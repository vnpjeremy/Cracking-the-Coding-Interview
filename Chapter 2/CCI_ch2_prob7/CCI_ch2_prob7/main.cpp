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

/* O(n) time and O(n) space reversal (new list creation) */
template <class T>
inline SLList<T> SLList<T>::outputReverse() const
{
    SLList<T> output;
    SLList<T>::Node<T> *cur = m_head;
    while(cur)
    {
        output.push_front(cur->m_data);
        cur = cur->m_next;
    }

    return output;
}

int main()
{
    SLList<int> list1;
    for(int ii = 0; ii < 7; ++ii)
        list1.push_back(ii);

    std::vector<int>  test1 = list1.flatten();
    SLList<int>       reversedList = list1.outputReverse();
    std::vector<int>  test2 = reversedList.flatten();

    list1.reverse();
    std::vector<int>  test3 = list1.flatten();

    int dummy = 0;
}
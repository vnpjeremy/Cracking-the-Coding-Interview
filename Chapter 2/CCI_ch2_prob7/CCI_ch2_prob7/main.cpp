/* Cracking the Coding Interview, McDowell 5th Ed, 2011
   Chapter 2: Problem 7.

   Check to see if a LL is a palindrome.
   
   Solutions by: vnpjeremy*/

#include "SLList.h"

/* O(n) time and O(n) space reverse-and-check algorithm */
template <class T>
inline bool SLList<T>::isPalindrome() const
{
    if(!m_head)
        return false;

    /* Only need to check half the list to verify, but don't have .size() as O(1).
       Could get away with only populating the first half of the list. outputReverse populates all of it. */
    SLList<T> const           reversedList = outputReverse();
    SLList<T>::Node<T> const  *cur = m_head, *curReversed = reversedList.m_head, *fast = m_head;
    while(fast)
    {
        /* Elements must be equal */
        if(cur->m_data != curReversed->m_data)
            return false;

        cur = cur->m_next;
        fast = fast->m_next;
        if(!fast)
            continue;

        fast = fast->m_next;
        curReversed = curReversed->m_next;
    }
    return true;
}

/* O(n) time O(1) space reversal method */
template <class T>
inline void SLList<T>::reverse()
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

/* O(n) time and O(n) space reversal (new list creation) */
template <class T>
inline SLList<T> SLList<T>::outputReverse() const
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

template <class T>
inline void SLList<T>::traverseReverse() const
{
    std::vector<T> stack = flatten();
    size_t const   size = stack.size();
    for(size_t ii = size - 1; ii < size; --ii)
    {
        //iterate reversely
    }
}

template <class T>
inline void SLList<T>::traverseRecursive(Node<T>* cur, std::vector<T> & output) const
{
    if(!cur)
        return;

    output.push_back(cur->m_data);
    traverseRecursive(cur->m_next, output);
}

int main()
{
    SLList<int> list1;
    for(size_t ii = 0; ii < 7; ++ii)
        list1.push_back(ii);
    for(size_t ii = 6 - 1; ii < 6; --ii)
        list1.push_back(ii);

    std::vector<int>  test1 = list1.flatten();
    bool const isPali = list1.isPalindrome();

    //SLList<int>       reversedList = list1.outputReverse();
    //std::vector<int>  test2 = reversedList.flatten();    

    //list1.reverse();
    //std::vector<int>  test3 = list1.flatten();

    int dummy = 0;
}
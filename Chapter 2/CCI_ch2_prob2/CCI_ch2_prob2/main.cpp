#include "main.h"

/* Cracking the Coding Interview, McDowell 5th Ed, 2011
   Chapter 2: Problem 2.
   Implement an algorithm to find the kth to last element of a 
   singly-linked list.
   
   Solutions by: vnpjeremy*/
int main()
{
    std::list<int> list1 = {4, 15, 20, 9, 7, 33};
    std::list<int> emptyList;
    std::list<int> list2 = {4};

    auto itr = findKthToLastElement(list1.begin(), list1.end(), 2);
    auto itr2 = findKthToLastElement(emptyList.begin(), emptyList.end(), 2);
    auto itr3 = findKthToLastElement(list2.begin(), list2.end(), 0);

    int  dummy = 0;
}
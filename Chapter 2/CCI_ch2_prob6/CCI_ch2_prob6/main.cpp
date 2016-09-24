/* Cracking the Coding Interview, McDowell 5th Ed, 2011
   Chapter 2: Problem 6.

   Given a circular linked list, implement an algorithm that
   returns the node at the beginning of the loop (corruption).
   Ex:
   A->B->C->D->E->C
   Output C
   
   Solutions by: vnpjeremy*/

#include "SLList.h"
int main()
{
    SLList<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);
    list1.push_back(4);
    list1.push_back(5);
    SLList<int>::Node<int>* cur = list1.find(3);

    int debug = 0;
}
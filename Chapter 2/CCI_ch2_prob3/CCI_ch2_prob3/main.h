#pragma once
#include <list>

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


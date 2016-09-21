#include "main.h"
/* Cracking the Coding Interview, McDowell 5th Ed, 2011
   Chapter 2: Problem 1.
   Remove duplicates from an unsorted list.
   Follow-up: What if a temporary buffer is not allowed? 
   
   Solutions by: vnpjeremy*/

int main()
{
    std::list<int> unsorted1 = {1, 5, 7, 7, 1, 2}, unsorted2 = unsorted1, unsorted3 = unsorted1;
    std::list<int> repeats = {1, 1, 1, 1,}, repeats2 = repeats, repeats3 = repeats;
    std::list<int> emptyset, emptyset2 = emptyset, emptyset3 = emptyset;
    std::list<int> norepeats = {1, 5, 2, 7, 11, 6}, norepeats2 = norepeats, norepeats3 = norepeats;

    /* Naive implementation test: */
    removeDuplicatesNaive(unsorted1);
    removeDuplicatesNaive(repeats);
    removeDuplicatesNaive(emptyset);
    removeDuplicatesNaive(norepeats);

    /* Hash implementation test: */
    removeDuplicates(unsorted2);
    removeDuplicates(repeats2);
    removeDuplicates(emptyset2);
    removeDuplicates(norepeats2);

    /* Sort/unique test: */
    removeDuplicatesSort(unsorted3);
    removeDuplicatesSort(repeats3);
    removeDuplicatesSort(emptyset3);
    removeDuplicatesSort(norepeats3);

    int dummy = 0;
}
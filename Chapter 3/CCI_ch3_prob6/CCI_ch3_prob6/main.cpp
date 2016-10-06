/* Cracking the Coding Interview, McDowell 5th Ed, 2011
   Chapter 2: Problem 6.
   
   Sort a stack in ascending order - biggest item on top.
   Make it no worse than O(n) space for another stack,
   but use no non-identical containers (stacks only).
   Push, Pop, Top, Empty (like STL).
   
   Solutions by: vnpjeremy*/


/* The O(n^2) solution is obvious: iterate over the stack
   each time for the smallest, then populate the next stack
   with that element. You'll get the second stack sorted
   in the way described.
   
   Obviously wanting to do better than that. Can we, with these
   limitations?
   
       <Same average time complexity as Merge, but that only really deals
        with comparisons. Things like cache locality are not included, and
        the majority of the time, Quick sort is faster.>
   Quick Sort: 
       Average: O(n log n) time
       Worst:   O(n^2) time
       Stable:  No 
       Space:   O(log n), for recursion
       
       <Merge sort is superior on disk due to sequential read/writes.
        For RAM this benefit is not present.>
    Merge Sort:
       Average: O(n log n) time
       Worst:   O(n log n) time
       Stable:  Yes
       Space:   O(n)

       <If you don't need stable and care about worst case >
    Heap Sort:
       Average: O(n log n)
       Worst:   O(n log n)
       Stable:  No
       Space:   O(1)

    Introsort:
       Quick sort that switches to a heap sort after a certain depth
    Insertion Sort:
       Stable and helpful when N is very small

    Odd-ones-out like Bucket and Radix.
    Bubble Sort:
        Rarely useful, much so in tape drives. 

    Summary:
        Ignoring access options, Quick and Merge seem like 
        possibilities here. Heap requires a non-stack container.
       */
//#include <chrono>
#include <random>
#include <stack>

template <class T>
inline void sort(std::stack<T> & input)
{
    std::stack<T> buffer;
}

int main()
{
    std::stack<int>                 stack1;
    std::random_device              rDev;
    std::mt19937                    gen(rDev());
    std::uniform_int_distribution<> dis(-100, 100);

    for(size_t ii = 0; ii < 7; ++ii)
        stack1.push(dis(gen));

    sort(stack1);

    int dummy = 0;
}
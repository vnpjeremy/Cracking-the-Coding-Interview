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


/* So here is the 'naive' solution, O(n^2), not a 'real' sorting algorithm
   in that sense. The top element will be a tmp variable for comparison.
   Everything gets pushed to stack2, and then all but this minimum or
   anything less than it gets pushed back.
   
   Because each sequential minimum will be greater than the previous minimum,
   previous minimums are not popped back from stack2, and eventually everything
   ends up there properly ordered. 
 
   I think we can do better than this, frankly. There are several sets of operations
   that can end up as undone (e.g., when a local minimum is found, then is obsoleted)
   But the restrictions make things tricky.
 */
template <class T>
inline void sort(std::stack<T> & input)
{
    if(input.empty())
        return;

    size_t countDebug = 0;

    /* Note: While this is O(n^2), if there are 5 elements, this algorithm
       will likely end up with more than just the 25 inner-loop operations 
       expected in an ordinary O(n^2) for loop. Any subsequent new minimum
       will start all over and perform O(n^2) operations. 
       
       Thus, if the absolute minimum is at the bottom of the stack, this
       method will perform 2*O(n^2) operations at minimum, or 50 in the 
       case of 5 elements. */
    std::stack<T>  buffer;
    while(!input.empty())
    {
        /* Pop off the top element of the data stack for comparison. */
        T tmp = input.top();
        input.pop();

        /* If there is stuff in the buffer, put it all back in the data
           stack when the element in question is NOT less than the tmp */
        while(!buffer.empty() && tmp < buffer.top())
        {
            input.push(buffer.top());
            buffer.pop();
        }

        /* Now that we've verified that the tmp is the lowest candidate 
           element other than the ones currently in buffer, push that into
           buffer as well. This will be the next one in the sorted list. */
        buffer.push(tmp);
    }

    /* Load everything back */
    while(!buffer.empty())
    {
        input.push(buffer.top());
        buffer.pop();
    }

    int dummy = 0;
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
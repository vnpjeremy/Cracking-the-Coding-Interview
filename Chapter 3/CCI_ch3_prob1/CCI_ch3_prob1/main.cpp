/* Cracking the Coding Interview, McDowell 5th Ed, 2011
   Chapter 3: Problem 1. 

   How could you use a single array to implement three stacks?

   Solutions by vnpjeremy.
*/
#include "ArrayStack.h"
#include <vector>
int main()
{
    arrayStackTriplet<int> newstack1(5);
    for(size_t ii = 0; ii < 5; ++ii)
        newstack1.push(ii, arrayStackTriplet<int>::stackID::Stack_1);
    for(size_t ii = 5; ii < 10; ++ii)
        newstack1.push(ii, arrayStackTriplet<int>::stackID::Stack_2);
    for(size_t ii = 10; ii < 15; ++ii)
        newstack1.push(ii, arrayStackTriplet<int>::stackID::Stack_3);

    std::vector<int> out1, out2, out3;
    for(size_t ii = 0; ii < 5; ++ii)
    {
        out1.push_back(newstack1.top(arrayStackTriplet<int>::stackID::Stack_1));
        newstack1.pop(arrayStackTriplet<int>::stackID::Stack_1);

        out2.push_back(newstack1.top(arrayStackTriplet<int>::stackID::Stack_2));
        newstack1.pop(arrayStackTriplet<int>::stackID::Stack_2);

        out3.push_back(newstack1.top(arrayStackTriplet<int>::stackID::Stack_3));
        newstack1.pop(arrayStackTriplet<int>::stackID::Stack_3);
    }


    int dummy = 0;
}
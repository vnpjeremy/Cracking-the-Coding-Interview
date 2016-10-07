/* Cracking the Coding Interview, McDowell 5th Ed, 2011
   Chapter 3: Problem 7.
   
   An animal shelter holds dogs and cats, with FIFO.
   People must adopt either the 'oldest' animal at
   the shelter, or pick a dog or cat. Only those 
   three options are available.
   
   Solutions by: vnpjeremy*/


/* FIFO means std::queue<> 

   This seems really straightforward. Two stacks.
   But how to handle the 'either' query scenario, most
   efficeintly with respect to space? 

*/
#include "shelter.h"
#include <random>

int main()
{
    Shelter<int> shelter1;

    std::random_device              rDev;
    std::mt19937                    gen(rDev());
    std::uniform_int_distribution<> dogsAndCats(-100, 100);
    std::uniform_int_distribution<> numberOfConsecutive(1, 6);

    int dummy = 0;
}
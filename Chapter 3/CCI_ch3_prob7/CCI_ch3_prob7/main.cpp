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

    /* Test: adopt cats when dogs are empty */
    shelter1.push(Shelter<int>::Animal::Cat, 2);
    shelter1.push(Shelter<int>::Animal::Cat, 3);
    shelter1.push(Shelter<int>::Animal::Cat, 4);

    /* */
    int cat1 = -1;
    shelter1.adoptAnimal(Shelter<int>::Animal::Cat, cat1);
    assert(cat1 == 2);

    int cat2 = -1;
    shelter1.adoptLongestResident(cat2);
    assert(cat2 == 3);

    shelter1.push(Shelter<int>::Animal::Dog, 22);
    shelter1.push(Shelter<int>::Animal::Dog, 20);
    shelter1.push(Shelter<int>::Animal::Dog, 35);

    int dog1 = -1;
    shelter1.adoptAnimal(Shelter<int>::Animal::Dog, dog1);
    assert(dog1 == 22);



    int dummy = 0;
}
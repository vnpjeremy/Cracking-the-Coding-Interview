#pragma once
#include <stack>
#include <cassert>
//enable_if integral type
//even IF integral type, what if short, and N > std::numeric_limits<short>::Max()? problem!
//probably can't/shouldn't templatize.

//template <class T>
class hanoiStacks
{
public:
    hanoiStacks() noexcept :
        m_numberOfDiscs(3),
        m_stacks()
    {
        populateFirstStack();
    }

    hanoiStacks(size_t const discCount) noexcept :
        m_numberOfDiscs(discCount),
        m_stacks()
    {
        populateFirstStack();
    }

    void solve()
    {
        SolveTOH(m_numberOfDiscs, 0, 1, 2);
    }

private:

    /* Using these three generalized steps:
       (1) Move N-1 from A to B, using C, freeing up the biggest disc, N.
       (2) Move disc N to C
       (3) Move the other N-1 discs from B to C, using A

      We can outline a recursive call. For example, w/ 3 discs:
      2^3- 1 = 7 moves
      Recursive (1):
      1. Disc 3: A->C (1->3)
      2. Disc 2: 1->2
      3. Disc 3: 3->2

      (2)
      4. Disc 1: 1->3

      Recursive (3)
      5. Disc 3: 2->1
      6. Disc 2: 2->3
      7. Disc 3: 1->3
    */
    void SolveTOH( size_t const numberOfDiscs,
                   size_t const indexOfTowerOrigin,
                   size_t const indexOfTowerBuffer,
                   size_t const indexOfTowerTarget )
    {
        if(numberOfDiscs > 0)
        {
            /* Origin to buffer */
            SolveTOH(numberOfDiscs - 1, indexOfTowerOrigin, indexOfTowerTarget, indexOfTowerBuffer);
            printf("Move a disc from %d to %d \n", indexOfTowerOrigin, indexOfTowerTarget);
            moveDisc(indexOfTowerOrigin, indexOfTowerTarget);
            /* Buffer to target */
            SolveTOH(numberOfDiscs - 1, indexOfTowerBuffer, indexOfTowerOrigin, indexOfTowerTarget);
        }
    }

    void populateFirstStack() noexcept
    {
        for(size_t ii = 0; ii < m_numberOfDiscs; ++ii)
            m_stacks[0].push(ii);
    }

    void moveDisc( size_t const sourceTower,
                   size_t const targetTower )
    {
        //assert(sourceTower < 3 && targetTower < 3); //Probably extranneous.
        assert(!m_stacks[sourceTower].empty());
        m_stacks[targetTower].push(m_stacks[sourceTower].top());
        m_stacks[sourceTower].pop();
    }

    size_t          m_numberOfDiscs;
    std::stack<int> m_stacks[3];
};
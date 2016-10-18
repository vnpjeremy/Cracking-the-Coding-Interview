/* Cracking the Coding Interview, McDowell 5th Ed, 2011
   Chapter 11: Problem 4.
   
   Say you have a 20GB file with one string per line. How
   would you sort it.
   
   Solutions by: vnpjeremy*/

/* Well, first off we don't have 20GB of RAM. At least not as of 2016.
   This means we should assume we're dealing with spin-disk page-file type
   behavior, very slow random read/write. */
int main()
{
    /* So we have 20GB of file. Let us assume we can handle some amount, say 200MB
       at a time, in memory. Load 100MB of data with a 100MB buffer for the sort
       algorithm. That leaves 200 chunks to process in total. 
       
       for ii = 0; ii < 200; ++ii
            perform sorting operation on the strings

       Doing a merge sort on these sorted sub-arrays will require smaller
       chunks, for example, maybe 20MB chunks. 

       The first 500K (100MB / 200 pieces) of each sorted 100MB chunk of each of the
       20GB file will be sorted, then dumped to the final sorted output. Repeat until
       the entirety of the 100MB sorted chunks are sorted between themselves and written
       to the output.

       A single-pass merge may not be efficient. With this size, a two-pass merge approach
       will aid in efficiency, as more, smaller buffers are used as size increases. This 
       efficiency overflow stems from the fact that the disk seeks required to fill the input
       buffers with data from each chucnk will take up most of the sort time.

       Recall mergesort space is linear.

       An efficient external sort will be O(N log N) time. Exponential increases in
       data size require linear increases in the number of passes.

       From Wiki:
       With reasonable assumptions, one could sort 500GB of data on a disk using 1GB of memory
       before a third pass becomes advantageous. Probably a two-pass sort on this.
       */
}
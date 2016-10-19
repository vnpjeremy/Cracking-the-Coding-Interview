/* Cracking the Coding Interview, McDowell 5th Ed, 2011
   Chapter 11: Problem 6.
   
   In a matrix of rows AND columns sorted in ascending order,
   search to find an element.
   
   Solutions by: vnpjeremy*/


/* This is a very intriguing problem. 
   Consider:
   We have a matrix of rows that are sorted. We can perform a binary
   search on each, but must do so linearly over the group. Therefore
   an O(N) compounded with an O(N log N) approach must necessarily be
   *worse* than what we can do here, as we have more information than
   this particular scenario.
   

   */
int main()
{

}
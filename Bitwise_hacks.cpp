//x&~(x-1) isolates the lowest set bit
//example
//if x is 100100 the expression would return 000100


//x&(x-1) changes the lowest set bit to zero
//example
//if x is 100100 the expression would return 100000


//The two's complement of the given no has all bits are reverted except the first '1' from right to left
-------------------------------------------------------------------------

//to isolate the Most significant set bit the most stable way would be to create a vector containing powers of 2 from 0 to 64.
// then binary search in it.

-------------------------------------------------------------------------

//Tricks With Bits:- https://www.interviewbit.com/tutorial/tricks-with-bits/
x & (x-1) will clear the lowest set bit of x
x & ~(x-1) extracts the lowest set bit of x (all others are clear). Pretty patterns when applied to a linear sequence.
x & (x + (1 << n)) = x, with the run of set bits (possibly length 0) starting at bit n cleared.
x & ~(x + (1 << n)) = the run of set bits (possibly length 0) in x, starting at bit n.
x | (x + 1) = x with the lowest cleared bit set.
x | ~(x + 1) = extracts the lowest cleared bit of x (all others are set).
x | (x - (1 << n)) = x, with the run of cleared bits (possibly length 0) starting at bit n set.
x | ~(x - (1 << n)) = the lowest run of cleared bits (possibly length 0) in x, starting at bit n are the only clear bits.
  
-------------------------------------------------------------------------

//These properties are useful in interactive problems

//https://codeforces.com/contest/1325/problem/D
a+b=(a xor b)+2*(a and b)
// we can observe that the difference between sum and xor of two numbers is always even...
  
//https://codeforces.com/contest/1556/problem/D
a+b=(a or b)+(a and b)
  
//https://codeforces.com/blog/entry/94384?#comment-834316
(a xor b) = (a and b) ^ (a or b)

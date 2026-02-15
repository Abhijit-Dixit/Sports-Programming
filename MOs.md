SQRT decomposition and MO's algorithm

SQRT decomposition
Given an array and 'q' queries find the number of unique elements in range L to R
It would be inefficient to solve this problem using segment trees, sqrt decomposition would be better.



<img width="610" height="259" alt="image" src="https://github.com/user-attachments/assets/ab294255-29e3-4230-9ba1-64af36d7a07d" />

In classical sqrt decomposition you divide the array into blocks of size. In Mo’s Algorithm instead of dividing the array, you divide the queries into blocks based on L.

Both sqrt decomposition and mo's algorithm come with nxroot(n) time complexity or qxroot(n).

Here's the intuition behind mo's algorithm's time complexity...
So after sorting the queries, answering them depends upon movement of L and R indices of query range. Assuming the cost of movement is O(1).
1. Movement of L - There are q queries, based on their L values these queries can be divided into root(n) blocks(of size root(n). Each query may adjust L by at most root(n) i.e. size of a block. so L movement would be qxroot(n)
2. Movement of R - Worst case: R sweeps from 0 → n once per block. So R movement per block = O(n). Given total as nxroot(n).

Hence mo's time complexity is nxroot(n) + qxroot(n)

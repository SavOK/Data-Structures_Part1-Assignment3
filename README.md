#Implementation of divide-and-conquer algorithm

---
<p align="right">
Specialization:Data Structures and Algorithms</br>
Course:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Algorithmic Toolbox</br>
Project:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
Assignment&nbsp;3</br></p>

---
Implemented solutions by using divide-and-conquer algorithm for the following computational problems:

- binary search
- majority element
- sorting: 3-way partition
- number of inversions
- points and segments

## Problem 1: [Binary Search]
Implement the binary search algorithm that allows searching sorted list.  
Input:&nbsp;&nbsp;&nbsp;The first line of the input contains an integer N and a sequence a<sub>0</sub> &lt; a<sub>1</sub> &lt; ... &lt; a<sub>n-1</sub> of
n pairwise distinct positive integers in increasing order. The next line contains an integer K and k positive integers b<sub>0</sub>, b<sub>1</sub>, ... ,b<sub>k-1</sub>  
Constraints: 1 &le; n, k &le; 10<sup>5</sup>; 1 &le; a<sub>i</sub> &le; 10<sup>9</sup>
for all 0 &le; i &le; N; 1 &le; b<sub>j</sub> &le; 10<sup>9</sup> for all 0 &le; j &le; K;</br>

Output: For all i from 0 to k-1, output an index 0 &le; j &le; n-1 such that a<sub>j</sub> = b<sub>i</sub> or -1 if there is no such index.</br>
*Example*:  
Input:      

    5 1 5 8 12 13
    5 8 1 23 1 11
Output:
  
    2 0 -1 0 -1

**Note**  </br>
- Current implementation is O(K&sdot;ln(N)).

## Problem 2: [Majority Element]
Check whether the input sequence contains a majority element.  
Input:&nbsp;&nbsp;&nbsp; List of integers of size N, 1 &le; N &le; 10<sup>5</sup>; 0 &le; a<sub>i</sub> &le; 10<sup>9</sup> for all 0 &le; i &lt; N.</br>
Output: 1 if majority element present 0 otherwise</br>

**Note** Implemented 2 solutions</br> 
- Majority element must be a median O(N&sdot;log(N)) </br>
- Majority element have the biggest frequency O(N) </br>

## Problem 3: [Quicksort 3-Way Partition] </br> 
Implement Quicksort 3-way partition. </br> 
Input:&nbsp;&nbsp;&nbsp; List of integers of size N, 1 &le; N &le; 10<sup>5</sup>; 1 &le; a<sub>i</sub> &le; 10<sup>9</sup> for all 0 &le; i &le; N.</br> 
Output: Sorted sequence </br>

**Note**</br>
- Complexity O(N&sdot;log(N)) </br>


## Problem 4: [Number of Inversions] </br>
Given unsorted list of integers count the number of invertion needed to sort list.</br>
An inversion of a sequence a<sub>0</sub>, a<sub>1</sub>, ..., a<sub>n-1</sub> is a pair of indices 0 &le; i &lt; j &lt; n such that a<sub>i</sub> &gt; a<sub>j</sub>.</br>
Input:&nbsp;&nbsp;&nbsp;Unsorted list {a<sub>0</sub>, a<sub>1</sub>, ..., a<sub>n-1</sub>}; 1 &le; n &le; 10<sup>5</sup>, 1 &le; a<sub>i</sub> &le; 10<sup>9</sup>
for all 0 &le; i &lt; n </br>
Output: Number of inversions in the sequence.</br>

**Note**   
- Implemented merge sort, option to output sorted sequence.</br>
- Complexity O(N&sdot;log(N))</br>

## Problem 5: [Points and Segments]</br>
Given a set of segments on a line and a set of points on a line, count, for each point, the number of segments which contain it</br>
Input:&nbsp;&nbsp;&nbsp; Set of segments { [a<sub>1</sub>, b<sub>1</sub>], [a<sub>2</sub>, b<sub>2</sub>], ..., [a<sub>s-1</sub>, b<sub>s-1</sub>], [a<sub>s</sub>, b<sub>s</sub>]} and
list of points { x<sub>1</sub>, x<sub>2</sub>, ..., x<sub>p-1</sub>, x<sub>p</sub> };</br>
1 &le; s, p &le; 50000; -10<sup>8</sup> &le; a<sub>i</sub> &le; b<sub>i</sub> &le; 10<sup>8</sup> for all 0 &le; i &lt; s; 
-10<sup>8</sup> &le; x<sub>j</sub> &le; 10<sup>8</sup> for all 0 &le; j &lt; p. </br>

Output: p non-negative integers k<sub>0</sub>, k<sub>1</sub>, . . . , k<sub>p-1</sub> where k<sub>i</sub>
is the number of segments which contain x<sub>i</sub>. </br>
k<sub>i</sub> = { j : a<sub>j</sub> &le; x<sub>i</sub> &le; b<sub>j</sub> } </br>
*Example*:  
Input:      

    3 2     3 segements (S), 2 points (P)
    0 5     Segment 1
    -3 2    Segment 2
    7 10    Segment 3
    1 6     Points 

Output:
  
    2 0

**Note**  </br>
- Solution is based on the discussion from Coursera forums. </br>
    1. Convert the points and segments in the list of points of deferent type.</br>
For example: Segments { [0, 5], [-3, 2], [7, 10] } and point {1, 6} becomes</br>{ (0, 'b'), (5, 't'), (-3, 'b'), (2, 't'), (7, 'b'), (10, 't), (1, 'p'), (6, 'p') }. </br>
    2. Sort the points.  
    3. Count how many points between 'b' and 't'   
- Complexity O((2s+p)&sdot;log(2s+p))

[Binary Search]:./src/binary_search.c
[Majority Element]:./src/majority_element.c
[Quicksort 3-Way Partition]:./src/sorting.c
[Number of Inversions]:./src/inversions.c
[Points and Segments]:./src/points_and_segments.c

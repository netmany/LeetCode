/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/


class Solution {
    int num(int start, int end){
        if (start >= end) return 1;
        int sum = 0;
        for(int i = start; i <= end; i++)
            sum += num(start, i-1) * num(i+1, end);
        return sum;
    }
public:
    int numTrees(int n) {
        return num(1, n);
    }
};

/*
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/


class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        set<int> s;
        for(int i = 0; i< n; i++){
            if(A[i] > 0 && s.count(A[i]) == 0) s.insert(A[i]);
        }
        for(int i = 1; i<= n; i++){
            if(s.count(i) == 0) return i;
        }
        return n + 1;
    }
};

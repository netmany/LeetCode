/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/


class Solution {
public:
    bool canJump(int A[], int n) {
        int begin = 0, end = begin;
        while(end < n - 1){
            int next = end;
            for(int i = begin; i <= end; i++){
                next = max(next, i + A[i]);
            }
            if(next == end) return false;
            begin = end + 1; end = next;
        }
        return true;
    }
};

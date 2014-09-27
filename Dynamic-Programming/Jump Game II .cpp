/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
*/


class Solution {
public:
    int jump(int A[], int n) {
        int k = 0;
        int begin = 0, end = begin;
        while(end < n - 1){
            int next = end;
            for(int i = begin; i <= end; i++){
                next = max(next, i + A[i]);
            }
            k++;
            if(next == end) return -1;
            begin = end + 1; end = next;
        }
        return k;
    }
};

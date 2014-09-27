/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/


class Solution {
public:
    int trap(int A[], int n) {
        int max = 0;
        for (int i = 0; i < n; i++){
            if (A[i] > A[max]) max = i;
        }
        int water = 0;
        for (int i = 0, leftMaxHeight = 0; i < max; i++){
            if (A[i] > leftMaxHeight) leftMaxHeight = A[i];
            else water += leftMaxHeight - A[i];
        }
        for (int i = n - 1, rightMaxHeight = 0; i > max; i--){
            if (A[i] > rightMaxHeight) rightMaxHeight = A[i];
            else water += rightMaxHeight - A[i];
        }
        return water;
    }
};

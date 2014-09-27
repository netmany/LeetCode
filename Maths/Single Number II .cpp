/*
Given an array of integers, every element appears three times except for one. Find that single one.
*/

class Solution {
public:
    int singleNumber(int A[], int n) {
        int tmp, b0 = 0, b1 = 0;
        for(int i = 0; i < n; i++){
            tmp = b0;
            b0 ^= A[i];
            b1 ^= tmp & A[i];
            tmp = ~ (b0 & b1);
            b0 &= tmp; b1 &= tmp;
        }
        return b0;
    }
};

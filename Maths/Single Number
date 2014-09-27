/*
Given an array of integers, every element appears twice except for one. Find that single one.
*/

class Solution {
public:
    int singleNumber(int A[], int n) {
        while(n >= 2){
            A[n-2] ^= A[n-1];
            n--;
        }
        return A[0];
    }
};

/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/


class Solution {
public:
    int search(int A[], int n, int target) {
        if(target == A[0]){
            return 0;
        }else if(target > A[0]){
            int i = 0;
            while(A[i] != target && i+1 < n && A[i] <= A[i+1]) i++;
            return A[i] == target ? i : -1;
        } else {
            int i = n - 1;
            while(A[i] != target && i-1 >= 0 && A[i] >= A[i-1]) i--;
            return A[i] == target ? i : -1;
        }
    }
};

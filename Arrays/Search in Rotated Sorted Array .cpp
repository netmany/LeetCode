/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/


class Solution {
public:
    int search(int A[], int n, int target) {
        int left = 0, right = n - 1, mid;
        while(left <= right){
            mid = (left + right) / 2;
            if(A[mid] == target) return mid;
            if(A[mid] < target){
                if(A[left] <= A[mid]) left = mid + 1;
                else {
                    if(A[left] <= target) right = mid - 1;
                    else left = mid + 1;
                }
            } else {
                if(A[right] >= A[mid]) right = mid - 1;
                else {
                    if(A[left] <= target) right = mid - 1;
                    else left = mid + 1;
                }
            }
        }
        return -1;
    }
};

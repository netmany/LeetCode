/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/


class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> range(2, -1);
        int left = 0, right = n -1, mid;
        while(left <= right){
            mid = (left + right) / 2;
            if(A[mid] == target){
                int i;
                i = mid; while(i >= 0 && A[i] == A[mid]) i--; 
                range[0] = i >= 0 ? i + 1 : 0;
                i = mid; while(i < n && A[i] == A[mid]) i++; 
                range[1] = i < n ? i - 1 : n - 1;
                break;
            } else if(A[mid] < target){
                left = mid + 1;
            } else {
                right = mid -1;
            }
        }
        return range;
    }
};

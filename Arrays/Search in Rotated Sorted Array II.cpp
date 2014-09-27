/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/


class Solution {
public:
    bool search(int A[], int n, int target) {
        int p = 0;
        while(p < n && A[p] != target) p++;
        return p < n;
    }
};

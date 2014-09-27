/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].
*/


class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int i = -1, p = 0, q = 0;
        while(p < n){
            while(p < n && A[p] == A[q]) p++;
            A[++i] = A[q];
            if(p > q + 1) {
                A[++i] = A[q];
            }
            if(p < n){
                q = p;
            }
        }
        return i + 1;
    }
};

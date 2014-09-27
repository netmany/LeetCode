/*
Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B.
The number of elements initialized in A and B are m and n respectively.
*/


class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        if(n == 0) return;
        if(m == 0) {
            for(int i = 0; i < n; i++)
                A[i] = B[i];
        } else {
            if (A[0] > B[0]) {
                int tmp = A[0]; A[0] = B[0]; B[0] = tmp;
                int i = 0;
                while (i+1 < n && B[i] > B[i+1]){
                    int b = B[i]; B[i] = B[i+1]; B[i+1] = b;
                    i++;
                }
            }
            merge(A + 1, m -1, B, n);
        }
    }
};

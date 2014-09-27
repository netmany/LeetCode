/*
There are two sorted arrays A and B of size m and n respectively. 
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*/


class Solution {
    int findKmin(int k, int A[], int m, int B[], int n){
        if(m == 0) return B[k -1];
        if(n == 0) return A[k -1];
        if(k == 1) return min(A[0], B[0]);
        if(m > n)  return findKmin(k, B, n, A, m);
        int p = min(m, k/2), q = k - p;
        if(A[p - 1] <= B[q - 1]) {
            return findKmin(k - p, A + p, m - p, B, n);
        } else {
            return findKmin(k - q, A, m, B + q, n - q);
        }
    }
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int k = m + n;
        if(k & 1) {
            return findKmin(k/2 + 1, A, m, B, n);
        } else {
            return (findKmin(k/2 , A, m, B, n) + findKmin(k/2 + 1, A, m, B, n))/2.0;
        }
    }
};

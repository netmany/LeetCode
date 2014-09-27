/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.
*/

class Solution {
public:
    int maxSubArray(int A[], int n) {
        int rs, s;
        if (n == 0) return 0;
        else if (n == 1) return A[0];
        else{
            int i = 1;
            rs = s = A[0];
            while(i < n){
                rs = max(A[i], rs + A[i]);
                s = max(s, rs);
                i++;
            }  
        }
        return s;
    }
};

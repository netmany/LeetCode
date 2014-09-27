/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/

// ---------------------------------------------------------------------------------
class Solution {
public:
    int maxProduct(int A[], int n) {
        int plusmax = 0, minusmax = 0, mp = INT_MIN;
        for(int i = 0; i < n; i++){
            if(A[i] == 0){
                plusmax = 0; 
                minusmax = 0;
            } else if(A[i] > 0) {
                plusmax = plusmax == 0 ? A[i] : plusmax * A[i];
                minusmax = minusmax == 0 ? 0 : minusmax * A[i];  
            } else {
                int tmp = plusmax;
                plusmax = minusmax == 0 ? 0 : minusmax * A[i];
                minusmax = tmp == 0 ? A[i] : tmp * A[i];
            }
            mp = max(mp, plusmax == 0 ? A[i] : plusmax);
        }
        return mp;
    }
};

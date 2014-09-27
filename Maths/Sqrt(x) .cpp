/*
Implement int sqrt(int x).

Compute and return the square root of x.
*/

class Solution {
public:
    int sqrt(int x) {
        long long left = 0, right = x, mid, t;
        while(left <= right){
            mid = (left + right)/2;
            t = mid * mid;
            if(t == x) return mid;
            else if(t < x) left = mid + 1;
            else right = mid -1;
        }
        return mid*mid <= x ? mid : mid - 1;
    }
};

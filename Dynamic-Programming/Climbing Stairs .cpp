/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/


class Solution {
public:
    int climbStairs(int n) {
        int t, i = 1, c1 = 1, c2 = 1;
        while(i++ < n){
            t = c1;
            c1 += c2;
            c2 = t;
        }
        return c1;
    }
};

/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/


class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int cur = INT_MAX, dis = cur;
        if(num.size() < 3) return cur;
        sort(num.begin(), num.end());
        for(int i = 0; i < num.size() - 2; i++){
            if(i > 0 && num[i] == num[i - 1]) continue;
            int j = i + 1, k = num.size() - 1;
            while(j < k){
                int t = num[i] + num[j] + num[k];
                if(t == target) return target;
                else if(t < target) j++;
                else k--;
                if(abs(t - target) < dis){
                        dis = abs(t - target);
                        cur = t;
                }
            }
        }
        return cur;
    }
};

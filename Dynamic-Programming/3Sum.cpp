/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/


class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > res;
        if(num.size() < 3) return res;
        sort(num.begin(), num.end());
        for(int i = 0; i < num.size() - 2; i++){
            if(i > 0 && num[i] == num[i - 1]) continue;
            int j = i + 1, k = num.size() - 1;
            while(j < k){
                int t = num[i] + num[j] + num[k];
                if(t == 0) {
                    res.push_back(vector<int>{num[i], num[j], num[k]});
                    int p;
                    p = j; while(p < k && num[p] == num[j]) p++; j = p;
                    p = k; while(p > j && num[p] == num[k]) p--; k = p;
                } else if(t < 0) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return res;
    }
};

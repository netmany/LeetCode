/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 
*/

class Solution {
    void combSum(vector<vector<int> > &res, vector<int> prefix, vector<int> &candidates, int begin, int target){
        if(target == 0) {
            res.push_back(prefix); return;
        }
        if(target < candidates[begin]) return;
        for(int i = begin; i < candidates.size(); i++){
            if(i > begin && candidates[i] == candidates[i - 1]) continue;
            vector<int> t = prefix;
            t.push_back(candidates[i]);
            combSum(res, t, candidates, i + 1, target - candidates[i]);
        }
    }
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        vector<vector<int> > res;
        vector<int> prefix;
        combSum(res, prefix, num, 0, target);
        return res;
    }
};

/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 
*/

class Solution {
    void combSum(vector<vector<int> > &res, vector<int> prefix, vector<int> &candidates, int begin, int target){
        if(target == 0) {
            res.push_back(prefix); return;
        }
        if(target < candidates[begin]) return;
        for(int i = begin; i < candidates.size(); i++){
            vector<int> t = prefix;
            t.push_back(candidates[i]);
            combSum(res, t, candidates, i, target - candidates[i]);
        }
    }
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > res;
        vector<int> prefix;
        combSum(res, prefix, candidates, 0, target);
        return res;
    }
};

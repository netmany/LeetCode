/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/


class Solution {
    void F(vector<vector<int> > &res, vector<int> v, int n, int k){
        if(n < k || k < 1) return;
        if(1 == k) {
            vector<int> t = v;
            t.insert(t.begin(), n);
            res.push_back(t);
        }
        F(res, v, n-1, k);
        v.insert(v.begin(), n);
        F(res, v, n-1, k-1);
    }
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res;
        vector<int> v;
        F(res, v, n, k);
        return res;
    }
};

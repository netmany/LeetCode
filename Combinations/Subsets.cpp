/*
Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/


class Solution {
    void qsort(vector<int> &S, int begin, int end){
        if(begin + 1 >= end) return;
        int p = begin + 1, q = p;
        while(p < end){
            if(S[p] < S[begin]){
                int t = S[q]; S[q] = S[p]; S[p] = t;
                q++; 
            }
            p++;
        }
        int t = S[q-1]; S[q-1] = S[begin]; S[begin] = t;
        qsort(S, begin, q-1);
        qsort(S, q, end);
    }
    void helper(vector<vector<int> > &res, vector<int> v, 
        vector<int> &S, int begin, int end){
        if(begin == end) {
            res.push_back(v);
            return;
        }
        int p = begin;
        helper(res, v, S, p + 1, end);
        v.push_back(S[begin]);
        helper(res, v, S, p + 1, end);
    }
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > res;
        vector<int> v;
        qsort(S, 0, S.size());
        helper(res, v, S, 0, S.size());
        return res;
    }
};

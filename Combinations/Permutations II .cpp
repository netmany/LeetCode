/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
*/


class Solution {
    void permute(vector<vector<int> > &res, vector<int> num, int begin){
        if(begin == num.size()) {
            res.push_back(num);
            return;
        }
        sort(num.begin() + begin, num.end());
        vector<int> t = num;
        for(int i = begin; i < t.size();){
            permute(res, t, begin + 1);
            t = num;
            int p = i; while(p < t.size() && t[p] == t[i]) p++;
            if(p < t.size()){
                int s = t[begin]; t[begin] = t[p]; t[p] = s;
            }
            i = p;
        }
    }
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > res;
        permute(res, num, 0);
        return res;
    }
};

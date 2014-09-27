/*
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/


class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > res, prev;
        if(num.size() == 0) return res;
        vector<int> t; t.push_back(num[0]);
        prev.push_back(t);
        for (int i = 1; i < num.size(); i++){
            for(int j = 0; j < prev.size(); j++){
                for(int k = 0; k <= prev[j].size(); k++){
                    vector<int> tmp  = prev[j];
                    tmp.insert(tmp.begin() + k, num[i]);
                    res.push_back(tmp);
                }
            }
            prev = res;
            res.clear();
        }
        return prev;
    }
};

/*
Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.
*/


class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> res;
        map<string, int> m;
        for(int i = 0; i < strs.size(); i++){
            string s = strs[i];
            sort(s.begin(), s.end());
            if(m.count(s) == 0) m[s] = 1;
            else m[s] = m[s] + 1;
        }
        for(int i = 0; i < strs.size(); i++){
            string s = strs[i];
            sort(s.begin(), s.end());
            if(m.count(s) > 0 && m[s] > 1) res.push_back(strs[i]);    
        }
        return res;
    }
};

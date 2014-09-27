/*
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/


class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        vector<bool> t(s.length() + 1, false);
        t[0] = true;
        for(int i = 1; i <= s.length(); i++){
            for(int j = 0; j <= i; j++){
                if(dict.find(s.substr(j, i - j)) != dict.end() && t[j]){
                    t[i] = true; break;
                }
            }
        }
        return t[s.length()];
    }
};

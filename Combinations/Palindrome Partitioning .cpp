/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
*/


class Solution {
    bool isPal(string s){
        for(int i = 0; i < s.length() / 2; i++){
            if(s[i] != s[s.length() - 1 -i]) return false;
        }
        return true;
    }
    void part(vector<vector<string>>& res, vector<string> cand,
            string& s, int p){
        if(p == s.length()) res.push_back(cand);
        for(int q = p + 1; q <= s.length(); q++){
            if(isPal(s.substr(p, q - p))) {
                vector<string> temp = cand;
                temp.push_back(s.substr(p, q - p));
                part(res, temp, s, q);
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> cand;
        part(res, cand, s, 0);
        return res;
    }
};

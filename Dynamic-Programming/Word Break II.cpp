/*
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].
*/



class Solution {
    bool isBreakable(string s, unordered_set<string> &dict){
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
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> res;
        if(!isBreakable(s, dict)) return res; 
        vector<int> cand; cand.push_back(0);
        int p = 0, i = 1;
        while(p + i <= s.length()){
            while(p + i <= s.length() && dict.find(s.substr(p, i)) == dict.end()) i++;
            if (p + i < s.length()){
                p = p + i; cand.push_back(p); i = 1;
            }else {
                if(p + i == s.length()){
                    int pre = 0; string part;
                    for(int j = 1; j < cand.size(); j++){
                        part += s.substr(pre, cand[j] - pre) + " ";
                        pre = cand[j];
                    }
                    part += s.substr(p, i);
                    res.push_back(part);
                }
                cand.pop_back();
                if(cand.size() == 0) break;
                i = p + 1 - cand.back();
                p = cand.back();
            }
        }
        return res;
    }
};

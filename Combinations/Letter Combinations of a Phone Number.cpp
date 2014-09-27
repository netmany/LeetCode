/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/


class Solution {
    void comb(vector<string> &res, string prefix, string &s, int begin, int end){
        if(begin == end){
            res.push_back(prefix);
        } else {
            string v;
            switch(s[begin]){
                case '2': v = "abc"; break;
                case '3': v = "def"; break;
                case '4': v = "ghi"; break;
                case '5': v = "jkl"; break;
                case '6': v = "mno"; break;
                case '7': v = "pqrs"; break;
                case '8': v = "tuv"; break;
                case '9': v = "wxyz"; break;
                    
            }
            for (int i = 0; i < v.length(); i++){
                comb(res, prefix + string(1, v[i]), s, begin + 1, end);
            }
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        comb(res, "", digits, 0, digits.length());
        return res;
    }
};

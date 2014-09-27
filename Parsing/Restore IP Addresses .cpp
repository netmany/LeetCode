/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/


class Solution {
    void restore(vector<string> &res, string prefix, string s, int begin, int k){
        if(k == 0) {
            if(begin == s.length()) res.push_back(prefix);
            return;
        }
        if(begin == s.length()) return;
        if(k != 4) prefix += ".";
        string v1 = prefix + s.substr(begin, 1);
        restore(res, v1, s, begin + 1, k - 1);
        if(begin + 1 < s.length() && s[begin] != '0') {
            string v2 = prefix + s.substr(begin, 2);
            restore(res, v2, s, begin + 2, k - 1);
        }
        if(begin + 2 < s.length() && s[begin] != '0') {
            int p = (s[begin] - '0') * 100 + (s[begin + 1] - '0') * 10 + (s[begin + 2] - '0');
            if(p < 256) {
                string v3 = prefix + s.substr(begin, 3);
                restore(res, v3, s, begin + 3, k - 1);
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        restore(res, "", s, 0, 4);
        return res;
    }
};

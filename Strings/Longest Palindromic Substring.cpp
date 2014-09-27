/*
Given a string S, find the longest palindromic substring in S. 
You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/


class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) return s;
        int left = 0, right = 0, maxlen = INT_MIN;
        for(int c = 0; c < s.length(); c++){
            int p = 1, rad = min(c, (int)(s.length() - 1 - c));
            if((rad << 1) + 1 > maxlen){
                while(p <= rad && s[c + p] == s[c - p]) p++;
                p--;
                int t = (p << 1) + 1;
                if(t > maxlen){maxlen = t; left = c - p; right = c + p;}
            }
            if(s[c] == s[c + 1]){
                int p = 1, rad = min(c, (int)(s.length() - 2 - c));
                if((rad << 1) + 2 > maxlen){
                    while(p <= rad && s[c + 1 + p] == s[c - p]) p++;
                    p--;
                    int t = (p << 1) + 2;
                    if(t > maxlen){maxlen = t; left = c - p; right = c + 1 + p;}
                }
            }
        }
        return s.substr(left, right - left + 1);
    }
};

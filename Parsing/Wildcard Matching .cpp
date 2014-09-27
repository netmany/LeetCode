/*
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
*/


class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int sl = strlen(s);
        int j = 0, cnt = 0;
        while(p[j] != '\0') {
            if(p[j] !='*') cnt++;
            j++;
        }
        if(cnt > sl) return false;
        int pl = j;
        vector<vector<bool> > t(sl + 1, vector<bool>(pl + 1, false));
        t[sl][pl] = true;
        for(int i = sl; i >= 0; i--){
            for(int j = pl - 1; j >= 0; j--){
                if(i == sl) t[i][j] = p[j] == '*' && t[i][j + 1];
                else {
                    if(p[j] == '?') t[i][j] = t[i + 1][j + 1];
                    else if (p[j] != '*') t[i][j] = s[i] == p[j] && t[i + 1][j + 1];
                    else if (p[j + 1] != '*') t[i][j] = t[i + 1][j] || t[i][j + 1];
                    else t[i][j] = t[i][j + 1];
                }
            }
        }
        return t[0][0];
     }
};

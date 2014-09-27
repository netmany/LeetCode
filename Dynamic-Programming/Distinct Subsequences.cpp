/*
Given a string S and a string T, count the number of distinct subsequences of S which equals to T.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
*/


class Solution {
public:
    int numDistinct(string S, string T) {
        int len1 = S.length(), len2 = T.length();
        if(len1 == 0) return len2 == 0 ? 1 : 0;
        if(len2 == 0) return 0;
        vector<vector<int> > c(len1, vector<int>(len2, 0));
        for(int i = len1 - 1; i >= 0; i--){
            for(int j = len2 - 1; j >= 0; j--){
                if(i == len1 - 1) {
                    if(j == len2 - 1) c[i][j] = S[i] == T[j] ? 1 : 0;
                    else c[i][j] = 0;
                } else {
                    if(j == len2 - 1) {
                        if(S[i] == T[j]) c[i][j] = 1 + c[i + 1][j];
                        else c[i][j] = c[i + 1][j];
                    } else {
                        if(S[i] == T[j]) c[i][j] = c[i + 1][j + 1] + c[i + 1][j];
                        else c[i][j] = c[i + 1][j];
                    }
                }
            }
        }
        return c[0][0];
    }
};

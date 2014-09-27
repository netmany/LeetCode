/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
*/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
        if(len1 + len2 != len3) return false;
        vector<vector<vector<bool> > > res(len1+1, vector<vector<bool> >(len2+1, vector<bool>(len3+1, false)));
        res[len1][len2][len3] = true;
        for(int j = len2-1; j >= 0; j--){
            for(int k = len3-1; k >= 0; k--){
                if(len2 - j == len3 - k){
                    res[len1][j][k] = s2[j] == s3[k] && res[len1][j+1][k+1];
                }
            }
        }
        for(int i = len1-1; i >= 0; i--){
            for(int k = len3-1; k >= 0; k--){
                if(len1 - i == len3 - k){
                    res[i][len2][k] = s1[i] == s3[k] && res[i+1][len2][k+1];
                }
            }
        }
        for(int i = len1-1; i >= 0; i--){
            for(int j = len2-1; j >= 0; j--){
                for(int k = len3-1; k >= 0; k--){
                    if(len1 - i + len2 - j == len3 - k){
                        if(s1[i] == s2[j]){
                            if(s1[i] == s3[k]) res[i][j][k] = res[i+1][j][k+1] || res[i][j+1][k+1];
                            else res[i][j][k] = false;
                        } else {
                            if(s1[i] == s3[k]) res[i][j][k] = res[i+1][j][k+1];
                            else if(s2[j] == s3[k]) res[i][j][k] = res[i][j+1][k+1];
                            else res[i][j][k] = false;
                        }
                    }
                }
            }
        }
        return res[0][0][0];
    }
};

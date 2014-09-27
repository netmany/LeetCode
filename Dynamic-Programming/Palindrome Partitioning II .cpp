/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/

class Solution {
    bool isPal(string s){
        for(int i = 0; i < s.length() / 2; i++){
            if(s[i] != s[s.length() - 1 -i]) return false;
        }
        return true;
    }
public:
    int minCut(string s) {
        if(s.length() == 0) return 0;
        vector<int> c(s.length()+1, s.length()); c[0] = -1;
        vector<vector<bool> > isPal(s.length(), vector<bool>(s.length(), false));
        for(int i = 1; i <= s.length(); i++){
            for(int j = 0; j < i; j++){
                if(s[j] == s[i-1] && (j+1 >= i-1 || isPal[j+1][i-1])){
                    isPal[j][i] = true;
                    c[i] = min(c[i], c[j]+1);
                }
            }
        }
        return c[s.length()];
    }
};
